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

        //Check if pos is not out of boundaries

        int saved_w = c->getW();
        int saved_h = c->getH();

        int maxW = (x_ + w_)-(x_ + saved_x);
        int clampedW = std::min(saved_w,maxW);
        c->setSize(clampedW,saved_h);

        c->draw(buf);
        c->setPosition(saved_x,saved_y);
        c->setSize(saved_w,saved_h);
    }
}

bool Panel::handleInput(char c){
    return false;
}