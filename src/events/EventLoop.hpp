 #pragma once
  #include "hal/Terminal.hpp"
  #include "hal/InputReader.hpp"
  #include "renderer/Renderer.hpp"
  #include "composite/Panel.hpp"
  #include <memory>

class EventLoop{

    public:
        EventLoop();
        void setRoot(std::unique_ptr<Panel>root);
        void run();
        void quit();

    private:
        Terminal terminal_;
        InputReader input_;
        Renderer renderer_;
        std::unique_ptr<Panel> root_;
        bool quit_ = false;
};