module debugger(
    input wire clk, reset,
    input wire [7:0] w,
    output wire trigger,
    output wire [7:0] data
);

    reg [7:0] data_reg, data_next;

    always @(posedge clk, posedge reset)
        if (reset)
            data_reg <= 8'h0;
        else
            data_reg <= data_next;

    always @*
        data_next = w;

    assign data = w;
    assign trigger = data_reg !== w;

endmodule
