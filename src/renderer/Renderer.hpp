#pragma once
#include "Buffer.hpp"

class Renderer{

public:
    Renderer(int width,int height);

    Buffer& backBuffer();
    void present();

private:
    void moveCursor(int col,int row);
    void applyStyle(const Cell& c);

    Buffer back_;
    Buffer front_;
    Cell last_;  // last emmited style 
};