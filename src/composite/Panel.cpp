#include "Panel.hpp"
#include <vector>
#include <memory>

void Panel::addChildren(std::unique_ptr<Widget> child){
    children_.push_back(std::move(child));
}

void Panel::draw(Buffer& buf){
    for (const auto& c : children_){
        c->draw(buf);
    }
}

bool Panel::handleInput(char c){
    return false;
}