#pragma once
#include "Widget.hpp"
#include <string>
#include "../renderer/Buffer.hpp"

class Label : public Widget{
public:
    explicit Label(std::string text);

    void draw(Buffer& buf) override;
    bool handleInput(char c) override {return false;}
    bool isFocusable() const override {return false;}

    void setText(std::string text);
    const std::string& text() const;

private:
    std::string text_;

};