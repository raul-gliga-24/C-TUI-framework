#include <iostream>
#include "core/Widget.hpp"
#include "core/Label.hpp"
#include "renderer/Cell.hpp"
#include "renderer/Buffer.hpp"
#include "renderer/Renderer.hpp"
#include "hal/Terminal.hpp"

int main() {
      {
          Terminal term;
          std::cout << "\033[5;10HTerminal hijacked!" << std::flush;
          Sleep(2000);
      } 
  }