module eth_debug(
    input wire clk, reset,
    input wire [3:0] sw,
    output wire uart_tx,
    output wire uart_empty, uart_full);

    wire [3:0] trigger_data;
    wire [7:0] ascii_data;
    wire trigger, full, w_uart;

    bin2ascii bin_utils (.bin(trigger_data), .ascii(ascii_data));

    debugger debugger_unit (.clk(clk), .reset(reset),
                          .w(sw), .trigger(trigger),
                          .data(trigger_data));

    uart uart_unit (.clk(clk), .reset(reset), .tx(uart_tx), .wr_uart(~reset & trigger & ~full),
                    .w_data(ascii_data), .tx_empty(uart_empty), .tx_full(full));

    assign uart_full = full;

endmodule
