#include <iostream>
#include <windows.h>
 class Terminal {
  public:
      Terminal();
      ~Terminal();

      static int width();
      static int height();

      Terminal(const Terminal&) = delete;
      Terminal& operator=(const Terminal&) = delete;

  private:
      HANDLE hIn_;
      DWORD  oldInMode_;
  };