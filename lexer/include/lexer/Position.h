#pragma once

struct Position {
    unsigned int symbol;
    unsigned int line;

    Position() : symbol(0), line(0) {}
    explicit Position(unsigned int symbol, unsigned int line) : symbol(symbol), line(line) {}

    void nextSymbol();
    void newLine();
    void drop();

    ~Position() = default;
};