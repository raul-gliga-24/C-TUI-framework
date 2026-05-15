#include <iostream>
#include "core/Widget.hpp"
#include "core/Label.hpp"

int main(){
    Label lbl("Hello , TUI");
    lbl.setPosition(5,3);
    lbl.draw();
    std::cout<<"\n";
    return 0;    
}