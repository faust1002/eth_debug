module debounce(
    input wire clk, reset,
    input wire sw,
    output reg db
);

    localparam [2:0] zero    = 3'b000,
                     wait1_1 = 3'b001,
                     wait1_2 = 3'b010,
                     wait1_3 = 3'b011,
                     one     = 3'b100,
                     wait0_1 = 3'b101,
                     wait0_2 = 3'b110,
                     wait0_3 = 3'b111;

    localparam N = 19;

    reg [N-1:0] q_reg;
    wire [N-1:0] q_next;
    wire m_tick;
    reg [2:0] state_reg, state_next;

    always @(posedge clk)
        q_reg <= q_next;
    assign q_next = q_reg + 1'b1;
    assign m_tick = (0 == q_reg) ? 1'b1 : 1'b0;

    always @(posedge clk, posedge reset)
        if (reset)
            state_reg <= zero;
        else
            state_reg <= state_next;

    always @* begin
        state_next = state_reg;
        db = 1'b0;
        case (state_reg)
            zero: begin
                if (sw)
                    state_next = wait1_1;
            end
            wait1_1: begin
                if (~sw)
                    state_next = zero;
                else if (m_tick)
                    state_next = wait1_2;
            end
            wait1_2: begin
                if (~sw)
                    state_next = zero;
                else if (m_tick)
                    state_next = wait1_3;
            end
            wait1_3: begin
                if (~sw)
                    state_next = zero;
                else if (m_tick)
                    state_next = one;
            end
            one: begin
                db = 1'b1;
                if (~sw)
                    state_next = wait0_1;
            end
            wait0_1: begin
                db = 1'b1;
                if (sw)
                    state_next = one;
                else if (m_tick)
                    state_next = wait0_2;
            end
            wait0_2: begin
                db = 1'b1;
                if (sw)
                    state_next = one;
                else if (m_tick)
                    state_next = wait0_3;
            end
            wait0_3: begin
                db = 1'b1;
                if (sw)
                    state_next = one;
                else if (m_tick)
                    state_next = zero;
            end
            default: state_next = zero;
        endcase
    end

endmodule
