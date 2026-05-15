#include <iostream>
#include "core/Widget.hpp"
#include "core/Label.hpp"
#include "renderer/Cell.hpp"

int main(){
    Cell a;
    Cell b;

    std::cout << (a == b ? "equal" : "not equal") << "\n";

    b.ch = 'X';
    std::cout << (a == b ? "equal" : "not equal") << "\n";
}