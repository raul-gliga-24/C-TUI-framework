#include "../core/Widget.hpp"
#include <string>
#include <functional>
#include "Button.hpp"

Button::Button(std::string label, std::function<void()> onClick)
    : label_(std::move(label)), onClick_(onClick) {
    w_ = (int)label_.size();
    h_ = 1;
}

 void Button::draw(Buffer& buf) {
      Cell& lb = buf.at(x_, y_);
      lb.ch = '[';
      if (hasFocus_) { lb.fg = 0; lb.bg = 7; }

      for (int i = 0; i < (int)label_.size(); i++) {
          Cell& cell = buf.at(x_ + 1 + i, y_);
          cell.ch = label_[i];
          if (hasFocus_) { cell.fg = 0; cell.bg = 7; }
      }

      Cell& rb = buf.at(x_ + 1 + (int)label_.size(), y_);
      rb.ch = ']';
      if (hasFocus_) { rb.fg = 0; rb.bg = 7; }
  }

bool Button::handleInput(char c) {
    if (c == '\n' || c == '\r' || c == ' ') {
        if (onClick_) onClick_();
        return true;
    }
    return false;
}

bool Button::isFocusable() const {
    return true;
}

void Button::focus() {
    hasFocus_ = true;
}

void Button::blur() {
    hasFocus_ = false;
}
