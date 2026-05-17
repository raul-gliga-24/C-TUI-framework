#pragma once
#include <vector>
#include <memory>
#include "core/Widget.hpp"

class Panel : public Widget{

public:
    void addChildren(std::unique_ptr<Widget> child);
    void draw(Buffer& buf) override;
    bool handleInput(char c) override;
    bool isFocusable() const override { return false;} // a layout container in not interactive
private:
    std::vector<std::unique_ptr<Widget>> children_;
};