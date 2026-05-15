#include "Buffer.hpp"

Buffer::Buffer(int width,int height) : width_ (width) , height_ (height),cells_(width*height){}

Cell& Buffer::at(int col,int row){

    return cells_[row * width_ + col];
}

const Cell& Buffer::at(int col, int row) const {
      return cells_[row * width_ + col];
  }

 void Buffer::clear(){
    std::fill(cells_.begin(),cells_.end(),Cell{});
 }

 int Buffer::width()const {return width_;}
    
 int Buffer::height()const {return height_;}