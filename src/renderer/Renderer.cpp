#include "Renderer.hpp"
#pragma once
#include <iostream>

Renderer::Renderer(int width,int height): back_(width,height),front_(width,height) {}

    
Buffer& Renderer::backBuffer(){
    return back_;
}

void Renderer::moveCursor(int col,int row){

    std::cout<<"\033["<<row+1<<";"<<col+1<<"H";
}

void Renderer::present(){

    for (int row = 0 ; row < back_.height();row++){
        for (int col = 0 ; col < back_.width();col++){
            if (back_.at(col,row) == front_.at(col,row)){
                continue;
            } 
            else{
                moveCursor(col,row);
                applyStyle(back_.at(col,row));
                std::cout << back_.at(col, row).ch;
                front_.at(col, row) = back_.at(col, row);
            }
        }
    }
    std::cout.flush();
}

void Renderer::applyStyle(const Cell& c){

        if (c.fg != last_.fg)
            {
                std::cout<<"\033[38;5;"<<(int)c.fg<<"m";
                last_.fg = c.fg;
            }
        if (c.bg != last_.bg){
            std::cout<<"\033[48;5;"<<(int)c.bg<<"m";
            last_.bg = c.bg;
        }
        if (c.bold != last_.bold){
            if (c.bold){
            std::cout<<"\033[1m";
            }
            else{
                std::cout<<"\033[0m";
                last_.fg = 255;
                last_.bg = 255;
            }
            last_.bold = c.bold;
        }
        
    

}
