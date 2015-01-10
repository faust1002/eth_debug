module eth_debug(
    input wire clk, reset,
    output wire uart_tx,
    output wire uart_empty, uart_full);

    uart uart_unit (.clk(clk), .reset(reset), .tx(uart_tx), .wr_uart(1'b1),
                    .w_data(8'h30), .tx_empty(uart_empty), .tx_full(uart_full));

endmodule
