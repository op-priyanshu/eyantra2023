// AstroTinker Bot : Task 2A : UART Receiver
/*
Instructions
-------------------
Students are not allowed to make any changes in the Module declaration.

This file is used to receive UART Rx data packet from receiver line and then update the rx_msg and rx_complete data lines.

Recommended Quartus Version : 20.1
The submitted project file must be 20.1 compatible as the evaluation will be done on Quartus Prime Lite 20.1.

Warning: The error due to compatibility will not be entertained.
-------------------
*/

/*
Module UART Receiver

Input:  clk_50M - 50 MHz clock
        rx      - UART Receiver

Output: rx_msg      - read incoming message
        rx_complete - message received flag
*/

// module declaration
module uart_rx (
  input clk_50M, rx,
  output reg [7:0] rx_msg,
  output reg rx_complete
);

//////////////////DO NOT MAKE ANY CHANGES ABOVE THIS LINE//////////////////

////////////////////////// Add your code here


initial begin

rx_msg = 0; rx_complete = 0;

end



  // Parameters
  parameter BAUD_RATE = 115200;
  parameter CLK_FREQ = 50000000;
  parameter BIT_CYCLES = CLK_FREQ / BAUD_RATE;

  // Internal signals
  reg [23:0] bit_counter;         // Counter to keep track of bit reception
  reg [2:0] state;               // State machine state
  reg [7:0] received_data;       // Temporarily store received bits
  reg [5:0] current_bit_counter; // Counter to track the current bit position

  // State machine states
  localparam START_BIT = 3'b000;
  localparam DATA_BITS = 3'b001;
  localparam STOP_BIT = 3'b010;

  // Initialize signals
  initial begin
    state <= START_BIT;
    bit_counter <= 23'b0;
    rx_msg <= 8'b0;
    rx_complete <= 0;
    received_data <= 8'b0;
    current_bit_counter <= 3'b0;
  end

  always @(posedge clk_50M) begin
    // State machine
    case (state)
      START_BIT: begin
		if(bit_counter == 23'b0) begin rx_complete <= 0; end
        bit_counter <= bit_counter + 1;
        if (bit_counter == BIT_CYCLES - 1) begin
          bit_counter <= 23'b0;
          state <= DATA_BITS;
        end
      end
      DATA_BITS: begin
        bit_counter <= bit_counter + 1;
		  if(bit_counter == 23'b0) begin received_data[7-current_bit_counter] <= rx; end
        if (bit_counter == BIT_CYCLES - 1) begin
			bit_counter <= 23'b0;
          // Add the received bit to the data at the LSB position
          

          // Increment the current bit counter
          current_bit_counter <= current_bit_counter + 1;

          // Check if all bits are received
          if (current_bit_counter == 7) begin
            state <= STOP_BIT;
				bit_counter <= 23'b0;
				current_bit_counter <= 0;
          end
        end
      end
      STOP_BIT: begin
        bit_counter <= bit_counter + 1;
        if (bit_counter == BIT_CYCLES - 1) begin
          // Store the received byte
          rx_msg <= received_data;
				received_data <= 8'b0;
          // Set receive complete flag
          rx_complete <= 1;

          // Reset state to START_BIT
          state <= START_BIT;
			 bit_counter <= 23'b0;
        end
      end
    endcase
  end







//////////////////DO NOT MAKE ANY CHANGES BELOW THIS LINE//////////////////

endmodule