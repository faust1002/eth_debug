module debugger(
    input wire clk, reset,
    input wire [3:0] w,
    output wire trigger,
    output wire [3:0] data
);

    reg [3:0] data_reg, data_next;

    always @(posedge clk, posedge reset)
        if (reset)
            data_reg <= 4'h0;
        else
            data_reg <= data_next;

    always @*
        data_next = w;

    assign data = w;
    assign trigger = data_reg !== w;

endmodule
