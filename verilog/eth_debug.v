module eth_debug(
    input wire clk, reset,
    input wire [7:0] sw,
    output wire uart_tx,
    output wire uart_empty, uart_full);

    wire [7:0] trigger_data;
    wire [7:0] ascii_data, ascii_data0, ascii_data1;
    wire trigger, full, w_uart, empty;

    bin2ascii bin2ascii_unit0 (.bin(trigger_data[3:0]), .ascii(ascii_data0));
    bin2ascii bin2ascii_unit1 (.bin(trigger_data[7:4]), .ascii(ascii_data1));

    debugger debugger_unit (.clk(clk), .reset(reset),
                          .w(sw), .trigger(trigger),
                          .data(trigger_data));

    shift shift_unit (.clk(clk), .reset(reset), .in({ascii_data1, ascii_data0}),
                      .wr(trigger), .out(ascii_data), .empty(empty));

    uart uart_unit (.clk(clk), .reset(reset), .tx(uart_tx), .wr_uart(~reset & ~empty & ~full),
                    .w_data(ascii_data), .tx_empty(uart_empty), .tx_full(full));

    assign uart_full = full;

endmodule
