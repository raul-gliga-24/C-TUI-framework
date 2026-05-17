#pragma once
#include <windows.h>
#include <optional>

class InputReader{

public:
    InputReader();
    std::optional<char> poll();

private:
    HANDLE hIn_;

};