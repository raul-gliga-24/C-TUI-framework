#include "Label.hpp"
#include "Widget.hpp"
#include <iostream>
#include "../renderer/Buffer.hpp"

Label::Label(std::string text) : text_(std::move(text)){}

void Label::setText(std::string text){
    text_ = std::move(text);
}

void Label::draw(Buffer& buf) {
      for (int i = 0; i < (int)text_.size(); i++) {
          buf.at(x_ + i, y_).ch = text_[i];
      }
  }
