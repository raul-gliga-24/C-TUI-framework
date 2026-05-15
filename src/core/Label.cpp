#include "Label.hpp"
#include "Widget.hpp"
#include <iostream>

Label::Label(std::string text) : text_(std::move(text)){}

void Label::setText(std::string text){
    text_ = std::move(text);
}

void Label::draw(){
    std::cout << "\033[" << y_ + 1 << ";" << x_ + 1 << "H" << text_;


}
