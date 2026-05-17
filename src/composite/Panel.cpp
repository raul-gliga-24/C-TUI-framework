#include "Panel.hpp"
#include <vector>
#include <memory>

void Panel::addChildren(std::unique_ptr<Widget> child){
    children_.push_back(std::move(child));
}

void Panel::draw(Buffer& buf){
    for (const auto& c : children_){
        int saved_x = c->getX();
        int saved_y = c->getY();

        c->setPosition(x_ + saved_x, y_ + saved_y); // Position relative to parent
        c->draw(buf);
        c->setPosition(saved_x,saved_y);

    }
}

bool Panel::handleInput(char c){
    return false;
}