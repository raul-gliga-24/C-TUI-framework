  # TUI Framework

    A bespoke, retained-mode Terminal User Interface (TUI) framework built from scratch in C++20. No external UI
    libraries — just raw ANSI escape sequences, Win32 console APIs, and modern C++.

    ## What It Does

    A complete terminal UI engine that lets you build interactive text-based applications with:
    - Positioned, colored widgets rendered into a virtual grid
    - Smooth 60fps redraws with only changed characters updated
    - Keyboard navigation between interactive controls
    - Composable layouts via a DOM-like widget tree

    ## Architecture

    The framework is built in six layers, each depending on the one below:
     [ Button / TextBox / Label ]   ← interactive widgets
    [ Panel / Composite tree    ]  ← layout and containment
    [ EventLoop / Focus FSM     ]  ← input routing and Tab traversal
    [ InputReader               ]  ← non-blocking Win32 keyboard polling
    [ Terminal HAL              ]  ← console mode setup/teardown
    [ Renderer / Buffer         ]  ← differential ANSI rendering engine
    [ Widget base class         ]  ← abstract interface for everything above

    ## Project Structure

    src/
    ├── core/
    │   ├── Widget.hpp            # Abstract base: draw(), handleInput(), isFocusable()
    │   └── Label.hpp             # Static text leaf widget
    ├── renderer/
    │   ├── Cell.hpp              # One terminal slot: char + fg + bg + bold + underline
    │   ├── Buffer.hpp/cpp        # Flat 1D grid with 2D (col, row) indexing
    │   └── Renderer.hpp/cpp      # Diff engine + ANSI escape emitter
    ├── hal/
    │   ├── Terminal.hpp/cpp      # Win32 raw mode, alternate screen buffer, RAII restore
    │   └── InputReader.hpp/cpp   # Non-blocking Win32 keystroke polling
    ├── composite/
    │   └── Panel.hpp/cpp         # Container widget, coordinate translation, scissor clip
    ├── events/
    │   └── EventLoop.hpp/cpp     # 60fps game loop, focus FSM, Tab/Shift-Tab traversal
    └── widgets/
        ├── Button.hpp/cpp        # Focusable button with std::function callback
        └── TextBox.hpp/cpp       # Text input, cursor emulation, horizontal scroll


     Tech Stack

    ┌──────────────┬─────────────────────────────────────────────────────────┐
    │   Concern    │                         Choice                          │
    ├──────────────┼─────────────────────────────────────────────────────────┤
    │ Language     │ C++20                                                   │
    ├──────────────┼─────────────────────────────────────────────────────────┤
    │ Compiler     │ MSVC (cl.exe)                                           │
    ├──────────────┼─────────────────────────────────────────────────────────┤
    │ Build system │ CMake 3.20+                                             │
    ├──────────────┼─────────────────────────────────────────────────────────┤
    │ Input        │ Win32 Console API (<windows.h>)                         │
    ├──────────────┼─────────────────────────────────────────────────────────┤
    │ Rendering    │ ANSI/VT escape sequences via std::cout                  │
    ├──────────────┼─────────────────────────────────────────────────────────┤
    │ Memory       │ RAII throughout — std::unique_ptr, no manual new/delete │
    ├──────────────┼─────────────────────────────────────────────────────────┤
    │ UI libraries │ None                                                    │
    └──────────────┴─────────────────────────────────────────────────────────┘

    
