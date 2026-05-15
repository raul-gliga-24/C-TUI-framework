#pragma once
#include "Widget.hpp"
#include <string>

class Label : public Widget{
public:
    explicit Label(std::string text);

    void draw() override;
    bool handleInput(char c) override {return false;}
    bool isFocusable() const override {return false;}

    void setText(std::string text);
    const std::string& text() const;

private:
    std::string text_;

};