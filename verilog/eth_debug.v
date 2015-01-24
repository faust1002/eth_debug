module eth_debug(
    input wire clk, reset,
    input wire [7:0] sw,
    input wire btn_start, btn_stop,
    output wire uart_tx,
    output wire uart_empty, uart_full
);

    wire [7:0] trigger_data;
    wire [7:0] ascii_data, ascii_data0, ascii_data1;
    wire trigger, full, empty, wr, wr_uart;
    wire start, working, stop;
    reg [15:0] data;
    reg delay;

    always @* begin
        if (start)
            data = 16'h5354; //ST
        else if (working)
            data = {ascii_data1, ascii_data0};
        else if (stop)
            data = 16'h5350; //SP
        else
            data = 16'h0;
    end
    assign wr = trigger | start | stop;
    assign wr_uart = ~reset & ~empty & ~full;

    statem statem_unit (.clk(clk), .reset(reset), .btn_start(btn_start), .btn_stop(btn_stop), .start(start),
                        .working(working), .stop(stop));

    bin2ascii bin2ascii_unit0 (.bin(trigger_data[3:0]), .ascii(ascii_data0));
    bin2ascii bin2ascii_unit1 (.bin(trigger_data[7:4]), .ascii(ascii_data1));

    debugger debugger_unit (.clk(clk), .reset(reset | stop), .enabled(working & empty), .w(sw),
                            .trigger(trigger), .data(trigger_data));

    shift shift_unit (.clk(clk), .reset(reset), .in(data), .wr(wr),
                      .out(ascii_data), .empty(empty));

    uart uart_unit (.clk(clk), .reset(reset), .tx(uart_tx), .wr_uart(wr_uart),
                    .w_data(ascii_data), .tx_empty(uart_empty), .tx_full(full));

    assign uart_full = full;

endmodule
