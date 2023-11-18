// AstroTinker Bot : Task 2A : UART Transmitter
/*
Instructions
-------------------
Students are not allowed to make any changes in the Module declaration.

This file is used to generate UART Tx data packet to transmit the messages based on the input data.

Recommended Quartus Version : 20.1
The submitted project file must be 20.1 compatible as the evaluation will be done on Quartus Prime Lite 20.1.

Warning: The error due to compatibility will not be entertained.
-------------------
*/

/*
Module UART Transmitter

Input:  clk_50M - 50 MHz clock
        data    - 8-bit data line to transmit
Output: tx      - UART Transmission Line
*/

// module declaration
module uart_tx(
    input  clk_50M,
    input  [7:0] data,
    output reg tx
);

//////////////////DO NOT MAKE ANY CHANGES ABOVE THIS LINE//////////////////

initial begin
	 tx <= 0;
end

////////// Add your code here ///////////////////


// Parameters
    parameter BAUD_RATE = 115200;
    parameter CLK_FREQ = 50000000;
    parameter BIT_CYCLES = CLK_FREQ / BAUD_RATE;
  
    // Internal signals
    reg [23:0] counter;        // Counter to keep track of bit transmission
    reg [3:0] state;           // State machine state
    reg [8:0] current_bit;     // Track the current transmitting bit
  
    // State machine states
    localparam START_BIT = 4'b0000;
    localparam DATA_BITS = 4'b0001;
    localparam STOP_BIT = 4'b0010;
	 
    initial begin
        state <= 4'b0000;
        counter <= 23'b1; 
        current_bit <= 9'b0;
    end 

    always @(posedge clk_50M) begin
        // State machine
		  case (state)
        START_BIT: begin
			//tx <= (data == 0) ? 1 : 0;
            counter <= counter + 1;
            if (counter == BIT_CYCLES  & data != 0) begin
                counter <= 23'b0;
                state <= DATA_BITS;
                tx <= data[current_bit];
            end
            else if(counter==1)  begin
                tx <=  1 ; // Start bit (low)
            end
				else tx <= (data == 0) ? 1 : 0; // Start bit (low)
        end
            
            DATA_BITS: 
					begin
							counter <= counter + 1;
							if (counter == BIT_CYCLES - 1) 
								begin
									counter <= 23'b0;
									//tx <= data[current_bit+1];
									if (current_bit == 7) 
										begin
											state <= STOP_BIT;
											if (data!=0) tx <= 1; // Transmit stop bit (high)
											else tx<=0;
											current_bit <= 9'b0;
										end
									else 
										begin
											current_bit = current_bit + 1;
											tx = data[current_bit];
										 end
								 end
							 else 
								begin
									tx <= data[current_bit]; // Transmit current bit
								end
					end

								STOP_BIT: begin
                if (counter == BIT_CYCLES-2 ) begin
                    counter <= 23'b0;
                    state <= START_BIT;
						  
                end
                else begin
                    counter <= counter + 1;
						  tx <=1;
                end
            end
        endcase
    end



//////////////////DO NOT MAKE ANY CHANGES BELOW THIS LINE//////////////////

endmodule