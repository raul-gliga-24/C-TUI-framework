#include "Terminal.hpp"
#include <iostream>
#include <windows.h>

Terminal::Terminal(){
    hIn_ = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hIn_,&oldInMode_);

     SetConsoleMode(hIn_, oldInMode_
      & ~ENABLE_LINE_INPUT
      & ~ENABLE_ECHO_INPUT
      & ~ENABLE_PROCESSED_INPUT);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD outMode;
  GetConsoleMode(hOut, &outMode);
  SetConsoleMode(hOut, outMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

  std::cout << "\033[?1049h\033[?25l";
  std::cout.flush();
}

Terminal::~Terminal() {
      SetConsoleMode(hIn_, oldInMode_);
      std::cout << "\033[?1049l\033[?25h";
      std::cout.flush();
  }

int Terminal::width() {
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
      return csbi.srWindow.Right - csbi.srWindow.Left + 1;
  }

int Terminal::height() {
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
      return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  }