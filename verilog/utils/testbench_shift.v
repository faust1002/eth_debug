module testbench;

    reg clk, reset, wr;
    reg [15:0] in;
    wire empty;
    wire [7:0] out;
    shift uut (.clk(clk), .reset(reset), .in(in), .wr(wr), .out(out), .empty(empty));

    initial begin
        $dumpfile("testbench.vcd");
        $dumpvars(0, uut);
    end

    initial begin
        clk <= 1'b0;
        reset <= 1'b1;
        in <= 16'hABCD;
        wr <= 1'b1;
        #5;
        reset <= 1'b0;
        #10;
        wr <= 1'b0;
        #100;
        $finish;
    end

    always #5 clk = ~clk;

endmodule
