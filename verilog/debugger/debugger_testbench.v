module testbench;

    reg clk, reset;
    reg [7:0] w;
    wire trigger;
    wire [7:0] trigger_data;
    debugger uut (.clk(clk), .reset(reset), .w(w),
                  .trigger(trigger), .data(trigger_data));

    initial begin
        $dumpfile("testbench.vcd");
        $dumpvars(0, uut);
    end

    initial begin
        clk <= 1'b0;
        reset <= 1'b1;
        w <= 8'h0;
        #5;
        reset <= 1'b0;
        #5;
        w <= 8'h20;
        #100;
        $finish;
    end

    always #5 clk = ~clk;

endmodule
