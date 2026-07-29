#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
#include "Game/Player/Player/PlayerFigureDirector.h"
#include "Game/Player/PlayerActionGraph.h"
#include <sead/math/seadVector.h>

struct PlayerProperty {
    sead::Vector3f trans;     // +0x00
    u8 unk[0x18];
    sead::Vector3f velocity;  // +0x24
};

class Player {
public:
    PlayerProperty* mPlayerProperty;             // +0x00
    u8 unk[0x80];
    PlayerFigureDirector* mFigureDirector;       // +0x88
    void* _90;
    void* _98;
    PlayerActionGraph* mActionGraph;             // +0xA0
};
