module InputBuffer(clk,u1,u2,u3,d2,d3,d4,done,out,qEmpty);

	input clk,u1,u2,u3,d2,d3,d4,done;
	output [2:0] out;
	output qEmpty;
	
	reg [2:0] out;
	
	reg [5:0] buffer;
	
	initial begin
		out<=3'b0;
		buffer<=6'b0;
	end
	
	always @ (posedge clk) begin
		//last output has been processed
		case (out)
			3'b1:		buffer[0]=0;
			3'b10:	buffer[1]=0;
			3'b11:	buffer[2]=0;
			3'b100:	buffer[3]=0;
			3'b101:	buffer[4]=0;
			3'b110:	buffer[5]=0;		
		endcase
				
		//record inputs in buffers
		if(u1) buffer[0]=1; 
		if(u2) buffer[1]=1; 
		if(u3) buffer[2]=1; 
		if(d2) buffer[3]=1; 
		if(d3) buffer[4]=1; 
		if(d4) buffer[5]=1; 

		
		if(done) begin		
			if(buffer[0]) out=3'b1;
			else if(buffer[1]) out=3'b10;
			else if(buffer[2]) out=3'b11;
			else if(buffer[3]) out=3'b100;
			else if(buffer[4]) out=3'b101;
			else if(buffer[5]) out=3'b110;
		end				
	end

	assign qEmpty=	(!buffer[0])&&(!buffer[1])&&(!buffer[2])&&
						(!buffer[3])&&(!buffer[4])&&(!buffer[5]);	
endmodule