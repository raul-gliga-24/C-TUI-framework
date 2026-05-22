#pragma once
#include "../core/Widget.hpp"
#include <string>
#include <functional>

class Button : public Widget{

public:
    Button(std::string label,std::function<void()> onClick);

    void draw(Buffer& buf) override;
    bool handleInput(char c) override;
    bool isFocusable() const override;
    void focus() override;
    void blur() override;

private:
    std::string label_;
    std::function<void()> onClick_;
    bool hasFocus_ = false;

};