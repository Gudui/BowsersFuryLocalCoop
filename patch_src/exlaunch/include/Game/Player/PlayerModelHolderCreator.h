#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
// This factory creates the full model set for a specific character, loading
// all figure variants (Normal, Fire, Climb, Giga, etc.) from game archives.
//
// Key usage (from bf-multiplayer PlayerPuppet.cpp):
//   mModelHolder = PlayerModelHolderCreator::createModelHolderAll(
//       info, util::getPlayerName(mPlayerType),
//       retargettingSelector, hioNode, true,
//       PlayerModelHolderCreator::CreationFlag(), "SM", 0);
//
// Character archive name table (from bf-multiplayer PlayerModelNameUtil.h):
//   Mario    → "Mario"
//   Luigi    → "Luigi"
//   Peach    → "Peach"
//   Kinopio  → "Kinopio"   (Toad)
//   Rosetta  → "Rosetta"   (Rosalina)
//
// Each has these full model variants loaded:
//   ObjectData/{name}
//   ObjectData/{name}Climb
//   ObjectData/{name}Fire
//   ObjectData/{name}Boomerang
//   ObjectData/{name}Raccoon
//   ObjectData/{name}Mini
//   ObjectData/{name}Manekineko  (Lucky Cat)
//   ObjectData/{name}Ice         (if applicable)

#include "Game/Player/PlayerActor.h"
#include "Game/Player/PlayerModelHolder.h"
#include "al/Debug/HioNode.h"

class PlayerModelHolderCreator {
public:
    struct CreationFlag {
        bool createIK : 1;
        bool createHairCtrl : 1;
        bool createSkirtDynamics : 1;
        bool createTailJointController : 1;
        bool createHairJointController : 1;

        operator u32() { return *reinterpret_cast<u8*>(this); }
    };

    static PlayerModelHolder* createModelHolderAll(
        const al::ActorInitInfo& info,
        const char* playerName,          // "Mario", "Luigi", "Peach", etc.
        class IUsePlayerRetargettingInfoCreator*,
        al::IUseHioNode*,
        bool createFur,
        u32 creationFlag,
        const char* archiveSuffix,       // "SM" for SingleMode (Bowser's Fury)
        int);
};
