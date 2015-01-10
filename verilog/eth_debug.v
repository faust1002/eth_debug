module eth_debug(
    input wire clk, reset,
    input wire [7:0] sw,
    output wire uart_tx,
    output wire uart_empty, uart_full);

    wire [7:0] trigger_data;
    wire trigger;

    debugger debugger_unit (.clk(clk), .reset(reset),
                          .w(sw), .trigger(trigger),
                          .data(trigger_data));

    uart uart_unit (.clk(clk), .reset(reset), .tx(uart_tx), .wr_uart(trigger),
                    .w_data(trigger_data), .tx_empty(uart_empty), .tx_full(uart_full));

endmodule
