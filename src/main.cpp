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
#include "events/EventLoop.hpp"

int main() {
    EventLoop loop;
      auto root = std::make_unique<Panel>();
      root->setPosition(0, 0);
      root->setSize(Terminal::width(), Terminal::height());

      auto l1 = std::make_unique<Label>("Hello from the loop!");
      l1->setPosition(2, 2);
      root->addChildren(std::move(l1));

      loop.setRoot(std::move(root));
      loop.run();
}