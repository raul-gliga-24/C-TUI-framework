#pragma once
#include "Cell.hpp"
#include <vector>

class Buffer{

public:
    Buffer(int width,int height);

    Cell& at(int col,int row);
    const Cell& at(int col,int row)const;

    void clear();
    int width()const;
    int height()const;

private:
    int width_,height_;
    std::vector<Cell> cells_;
};