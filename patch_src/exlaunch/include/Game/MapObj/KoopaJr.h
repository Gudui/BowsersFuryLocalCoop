#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
// KoopaJr is Bowser Jr. as the co-op partner in Bowser's Fury.
// In stock BF, he follows Mario around. With PATCH-0004, Luigi replaces
// the 2nd player slot. KoopaJr becomes a cosmetic artifact that mirrors
// Luigi's position.
//
// bf-multiplayer approach: set KoopaJr's nerve to a passive/hidden state
// (NSO data offset 0x0137F630) after scene init, then teleport to P1 pos.
// This fully disables him rather than having him mirror Luigi's movements.

#include "al/LiveActor/LiveActor.h"
#include "al/Scene/ISceneObj.h"

class KoopaJr : public al::LiveActor, public al::ISceneObj {
public:
    KoopaJr();
};
