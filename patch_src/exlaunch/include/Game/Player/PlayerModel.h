#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
#include "al/LiveActor/LiveActor.h"

class PlayerModel : public al::LiveActor {
    void* unk1;

public:
    const char* mPlayerName;           // +0x150
    const char* mFigureName;           // +0x158
    void* _160;
    void* _168;
    void* _170;
    void* _178;
    void* _180;
    void* _188;
    class PlayerModelIK* mModelIK;     // +0x190
    class PlayerModelHair* mModelHair; // +0x198
    int _1a0;
    int _1a4;
    void* _1a8;
    u8 unk2[0x2a];

    PlayerModel(const char* name, const char* archiveName,
                const al::ActorInitInfo& info, const char* subArchiveName);
};
