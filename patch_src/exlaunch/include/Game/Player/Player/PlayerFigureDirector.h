#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
#include "Game/Player/PlayerAnimFunc.h"
#include "al/LiveActor/LiveActor.h"

class PlayerFigureDirector {
public:
    int unk;                         // +0x00
    EPlayerFigure mCurFigure;        // +0x04 — current power-up figure

    void change(EPlayerFigure figure);
    void forceChange(EPlayerFigure figure);  // used for Giga Bell transform
    void set(EPlayerFigure figure);
    void lose();
    void update();
};

namespace rc {
    void initPlayerFigureType(al::LiveActor* actor, u32 figureType, bool something);
}
