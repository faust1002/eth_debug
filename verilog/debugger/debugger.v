module debugger(
    input wire clk, reset,
    input wire [3:0] w,
    output wire trigger,
    output wire [3:0] data
);

    reg [3:0] data_reg, data_next;
    reg trigger_reg, trigger_next;
    wire [3:0] w_db;

    debounce debounce_unit0 (.clk(clk), .reset(reset), .sw(w[0]), .db(w_db[0]));
    debounce debounce_unit1 (.clk(clk), .reset(reset), .sw(w[1]), .db(w_db[1]));
    debounce debounce_unit2 (.clk(clk), .reset(reset), .sw(w[2]), .db(w_db[2]));
    debounce debounce_unit3 (.clk(clk), .reset(reset), .sw(w[3]), .db(w_db[3]));

    always @(posedge clk, posedge reset)
        if (reset) begin
            data_reg <= 4'h0;
            trigger_reg <= 1'b0;
        end
        else begin
            data_reg <= data_next;
            trigger_reg <= trigger_next;
        end

    always @* begin
        data_next = w_db;
        trigger_next = data_reg !== w_db;
    end

    assign data = data_reg;
    assign trigger = trigger_reg;

endmodule
