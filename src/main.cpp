#include <iostream>
#include "core/Widget.hpp"
#include "core/Label.hpp"
#include "renderer/Cell.hpp"
#include "renderer/Buffer.hpp"
#include "renderer/Renderer.hpp"

int main(){

  /*
  Key codes:

  ┌──────────────────────┬────────────────┐
  │        Effect        │    Sequence    │
  ├──────────────────────┼────────────────┤
  │ Reset all attributes │ \033[0m        │
  ├──────────────────────┼────────────────┤
  │ Bold on              │ \033[1m        │
  ├──────────────────────┼────────────────┤
  │ Underline on         │ \033[4m        │
  ├──────────────────────┼────────────────┤
  │ Foreground 256-color │ \033[38;5;<n>m │
  ├──────────────────────┼────────────────┤
  │ Background 256-color │ \033[48;5;<n>m │
  └──────────────────────┴────────────────┘
  */
    Renderer r(80, 24);
    r.backBuffer().at(5, 3).ch = 'H';
    r.backBuffer().at(5, 3).fg = 11;
    r.backBuffer().at(6, 3).ch = 'i';

    std::cin.get();


    r.present();
    std::cin.get();

 }