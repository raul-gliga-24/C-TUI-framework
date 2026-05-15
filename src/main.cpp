#include <iostream>
#include "core/Widget.hpp"
#include "core/Label.hpp"
#include "renderer/Cell.hpp"
#include "renderer/Buffer.hpp"

int main(){
    Buffer buf(10,5);
    buf.at(3,2).ch = 'X';
     std::cout << buf.at(3, 2).ch << "\n";  // should print X
    std::cout << buf.at(0, 0).ch << "\n"; 
}