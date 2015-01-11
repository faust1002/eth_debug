module shift(
    input wire clk, reset,
    input wire [15:0] in,
    input wire wr,
    output wire [7:0] out,
    output wire empty
);

    localparam [1:0] ready  = 2'b00,
                     first  = 2'b01,
                     second = 2'b10;

    reg [1:0] state_reg, state_next;
    reg empty_reg, empty_next;
    reg [15:0] data_reg, data_next;

    always @(posedge clk, posedge reset)
        if (reset) begin
            state_reg <= ready;
            empty_reg <= 1'b1;
            data_reg <= 16'h0;
        end
        else begin
            state_reg <= state_next;
            empty_reg <= empty_next;
            data_reg <= data_next;
        end

    always @* begin
        state_next = state_reg;
        empty_next = empty_reg;
        data_next = data_reg;
        case (state_reg)
            ready: begin
                if (wr) begin
                    state_next = first;
                    data_next = in;
                    empty_next = 1'b0;
                end
            end
            first: begin
                state_next = second;
                empty_next = 1'b0;
                data_next = data_reg << 8;
            end
            second: begin
                state_next = ready;
                empty_next = 1'b1;
            end
        endcase
    end

    assign out = data_reg[15:8];
    assign empty = empty_reg;

endmodule
