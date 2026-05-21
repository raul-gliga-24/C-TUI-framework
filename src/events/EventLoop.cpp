#include "EventLoop.hpp"
#include "hal/Terminal.hpp"
#include "hal/InputReader.hpp"
#include "renderer/Renderer.hpp"
#include "composite/Panel.hpp"
#include <memory>
#include <chrono>
#include <thread>


using namespace std::chrono;

EventLoop::EventLoop():terminal_(),input_(),renderer_(Terminal::width(),Terminal::height()){}

void EventLoop::setRoot(std::unique_ptr<Panel>root){
    root_ = std::move(root);
}

void EventLoop::quit(){
    quit_ = true;
}

void EventLoop::run(){

    while(!quit_){
        auto frame_start = steady_clock::now();

        auto key = input_.poll();

        renderer_.backBuffer().clear();

        if(root_){

            root_->draw(renderer_.backBuffer());
        }
        renderer_.present();


        auto elapsed = steady_clock::now() - frame_start;
        auto remaining  = milliseconds(16)-duration_cast<milliseconds>(elapsed);

        if (remaining > milliseconds(0)){
            std::this_thread::sleep_for(remaining);
        }

        if ( key == '\x1b'){
            quit();
        }

    }


}