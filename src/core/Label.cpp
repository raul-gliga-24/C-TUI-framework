#include "Label.hpp"
#include "Widget.hpp"
#include <iostream>
#include "../renderer/Buffer.hpp"

Label::Label(std::string text) : text_(std::move(text)){
    w_ = (int)text_.size();
    h_ = 1;
}

void Label::setText(std::string text){
    text_ = std::move(text);
}

void Label::draw(Buffer& buf) {
    int limit = std::min((int)text_.size(),w_);
      for (int i = 0; i < limit; i++) {
          buf.at(x_ + i, y_).ch = text_[i];
      }
  }
