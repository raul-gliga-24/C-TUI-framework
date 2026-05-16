#pragma once
#include "../renderer/Buffer.hpp"
class Widget{
public:
    virtual ~Widget() = default;

    virtual void draw(Buffer& buf) = 0;
    virtual bool handleInput(char c) = 0;
    virtual bool isFocusable() const = 0;

    void setPosition(int x,int y){
        this->x_ = x;
        this->y_ = y;
    }
    void setSize(int w,int h){
        this->w_ = w;
        this->h_ = h;
    }

protected:
    int x_ = 0, y_ = 0 , w_ = 0 , h_ =0;

};