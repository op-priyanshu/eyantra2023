// AstroTinker Bot : Task 1C : Pulse Generator and Detector
/*
Instructions
-------------------
Students are not allowed to make any changes in the Module declaration.

This file is used to design a module which will generate a 10us pulse and detect incoming pulse signal.

Recommended Quartus Version : 20.1
The submitted project file must be 20.1 compatible as the evaluation will be done on Quartus Prime Lite 20.1.

Warning: The error due to compatibility will not be entertained.
-------------------
*/

// t1c_pulse_gen_detect
//Inputs : clk_50M, reset, echo_rx
//Output : trigger, distance, pulses, state

// module declaration
module t1c_pulse_gen_detect (
    input clk_50M, reset, echo_rx,
    output reg trigger, out,
    output reg [21:0] pulses,
    output reg [1:0] state
);

initial begin
    trigger = 0; out = 0; pulses = 0; state = 0;
end


//////////////////DO NOT MAKE ANY CHANGES ABOVE THIS LINE//////////////////

reg [22:0] pulse_counter; // Counter for generating 10us pulse
reg [22:0] delay_counter; // Counter for generating delays
reg [22:0] pulse_width;   // Counter for measuring pulse width
reg [22:0] pulse_period;  // Counter for measuring pulse period
reg warmup_done=0;          // Warm-up signal done
reg exact=0;           // Delay done

always @(posedge clk_50M or posedge reset) 
	begin
		if (reset) 
			begin
				state<= 2'b00;
				delay_counter <= 23'b0;
				pulses <= 23'b0;
				trigger<=1'b0;
				out <=1'b0;
			end 
			
		else 
			begin
		
    case (state)
	 
      2'b00: 
			
			begin // Idle state
			     if (!warmup_done) 
		             begin
							delay_counter <= delay_counter + 1;
							if (delay_counter == 23'd50) 
								begin
									delay_counter <= 23'b0;
									state<= 2'b01;
									warmup_done<=1;
								end
						 end 
					else 
						begin
					state<= 2'b01;
					
					end
				
			end
			
      2'b01:
			begin // Generating 10us pulse
			trigger <= 1;
				delay_counter <= delay_counter + 1;
				if (delay_counter == 23'd500) 
					begin
						delay_counter <= 23'b0;
						state <= 2'b10;
						trigger <= 0;
					end
			end
			
      2'b10:
			begin // Measuring incoming pulses
			if (delay_counter == 23'd50000) 
				begin 
					delay_counter <= 0;
						if(pulses >23'd29410)
									begin
									delay_counter <= 0;
									pulses<=0;
										state <= 2'b11;
									end
						else state <= 2'b11;
				end
			else
				begin 
				delay_counter<=delay_counter+1;
					if(echo_rx)
						begin
							pulses<=pulses+1;
							
						end
					
				end
			end
      2'b11:
			begin // Generate output pulse
				
					
				out <= 1'b1;
				state<= 2'b00;
			end
			
      default: 
			begin
				state<= 2'b00;
			end
			
    endcase
	 end
end






//////////////////DO NOT MAKE ANY CHANGES BELOW THIS LINE//////////////////

endmodule
