  #include "events/EventLoop.hpp"
  #include "composite/Panel.hpp"
  #include "widgets/Button.hpp"
  #include <memory>

  int main() {
      EventLoop loop;
      auto root = std::make_unique<Panel>();
      root->setPosition(0, 0);
      root->setSize(80, 24);

      auto btn = std::make_unique<Button>("OK", [&]{ loop.quit(); });
      btn->setPosition(2, 2);

      Widget* btn_ptr = btn.get();
      root->addChildren(std::move(btn));
      loop.setRoot(std::move(root));
      loop.setFocus(btn_ptr);
      loop.run();
  }