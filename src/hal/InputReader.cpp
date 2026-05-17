#pragma once
#include <windows.h>
#include <optional>
#include "InputReader.hpp"

InputReader::InputReader(){
    hIn_ = GetStdHandle(STD_INPUT_HANDLE);
}

std::optional<char> InputReader::poll(){

    DWORD count = 0;
    GetNumberOfConsoleInputEvents(hIn_,&count);

    if ( count == 0){
        return std::nullopt;
    }

    INPUT_RECORD rec;
    DWORD read;
    ReadConsoleInput(hIn_, &rec, 1, &read);

    if (rec.EventType != KEY_EVENT || !rec.Event.KeyEvent.bKeyDown)
        return std::nullopt;

    return rec.Event.KeyEvent.uChar.AsciiChar;

}