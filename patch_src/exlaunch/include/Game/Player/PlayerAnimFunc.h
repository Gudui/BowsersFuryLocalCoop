#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
// Enum values confirmed by Ghidra static analysis and GDB runtime probes.
enum class EPlayerFigure : int {
    None           = 0,
    Mini           = 1,
    Fire           = 2,
    Climb          = 3,
    RaccoonDog     = 4,
    Boomerang      = 5,
    RaccoonDogWhite = 6,
    Manekineko     = 7,
    ClimbWhite     = 8,
    ClimbGiga      = 9
};

class PlayerAnimFunc {
public:
    static const char* getFigureString(EPlayerFigure);
};
