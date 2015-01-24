module statem(
    input wire clk, reset,
    input wire btn_start, btn_stop,
    output wire start, working, stop
);

    localparam [1:0] un  = 2'b00,
                     st  = 2'b01,
                     wk  = 2'b10,
                     sp  = 2'b11;

    reg [1:0] state_reg, state_next;
    reg [1:0] cnt_reg, cnt_next;
    wire start_db, stop_db;

    debounce #(.N(16)) debounce_unit0 (.clk(clk), .reset(reset), .sw(btn_start), .db(start_db));
    debounce #(.N(16)) debounce_unit1 (.clk(clk), .reset(reset), .sw(btn_stop), .db(stop_db));

    always @(posedge reset, posedge clk)
        if (reset) begin
            state_reg <=  un;
            cnt_reg <= 2'b10;
        end
        else begin
            state_reg <= state_next;
            cnt_reg <= cnt_next;
        end

    always @* begin
        state_next = state_reg;
        cnt_next = cnt_reg;
        case (state_reg)
            un: begin
                if (start_db)
                    state_next = st;
            end
            st: begin
                state_next = wk;
            end
            wk: begin
                if (stop_db)
                    state_next = sp;
            end
            sp: begin
                state_next = un;
            end
        endcase
    end

    assign start = (state_reg == st);
    assign working = (state_reg == wk);
    assign stop = (state_reg == sp);

endmodule
