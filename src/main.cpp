#include <iostream>
#include "core/Widget.hpp"
#include "core/Label.hpp"
#include "renderer/Cell.hpp"
#include "renderer/Buffer.hpp"
#include "renderer/Renderer.hpp"
#include "hal/Terminal.hpp"
#include "hal/InputReader.hpp"
#include "composite/Panel.hpp"
#include <string>
#include <vector>

int main() {
    Panel p;
    p.setPosition(5,3);
    p.setSize(80,24);

     auto l1 = std::make_unique<Label>("Hello");
     l1->setPosition(1,1);
    auto l2 = std::make_unique<Label>("World");
    l2->setPosition(2,2);
    p.addChildren(std::move(l1));
    p.addChildren(std::move(l2));

    Terminal term;
    Renderer renderer(Terminal::width(), Terminal::height());

    p.draw(renderer.backBuffer());
    renderer.present(); 

  std::cin.get();




  }