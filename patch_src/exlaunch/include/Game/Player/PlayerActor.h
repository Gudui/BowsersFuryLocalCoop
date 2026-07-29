#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
// sizeof(PlayerActor) == 0x648 (confirmed by static_assert in bf-multiplayer).
//
// Key field offsets for patch work:
//   +0x000 – +0x058  : al::LiveActor base
//   +0x058 – +0x080  : inherits[0x58]  (player-specific base fields)
//   +0x080            : mPlayer          (Player*)
//   +0x088            : unk2[0x10]
//   +0x098            : mPlayerAnimator  (PlayerAnimator*)
//   +0x0A0 – +0x0F8  : unk3[0x58]
//   +0x0F8            : mModelHolder     (PlayerModelHolder*)
//   +0x100 – +0x120  : unk4[0x4 pointer slots]
//   +0x120            : mBoomerangHolder (holds boomerang actor ref)
//   +0x128 – +0x1C0  : unk5[0x98]
//   +0x1C0            : mCollider        (al::Collider*)
//   +0x1C8            : input chain src  (stptr chain entry — see PATCH-0010)
//   +0x1D0            : selector object  (per-actor selector, idx at +8)
//   +0x310            : area [0x190]
//   +0x4A0            : mFootPrintHolder (al::FootPrintHolder*)
//   +0x4B0            : area [0x1A0]

#include "Game/Player/Player/Player.h"
#include "Game/Player/PlayerAnimator.h"
#include "Game/Player/PlayerModelHolder.h"
#include "al/Collision/Collider.h"
#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/SubActorKeeper.h"
#include "al/Npc/FootPrintHolder.h"

class IUsePlayerActionGraphBuilder;
class IUsePlayerRetargettingInfoCreator;

class PlayerActor : public al::LiveActor {
    u8 inherits[0x58];

public:
    u8 unk[0x28];
    Player* mPlayer;                       // +0x080
    u8 unk2[0x10];
    PlayerAnimator* mPlayerAnimator;       // +0x098
    u8 unk3[0x58];
    PlayerModelHolder* mModelHolder;       // +0x0F8
    void* unk4[0x4];
    struct {
        void* unk;
        al::LiveActor* boomerang;
    }* mBoomerangHolder;                   // +0x120
    u8 unk5[0x98];
    al::Collider* mCollider;               // +0x1C0
    u8 _310[0x190];
    al::FootPrintHolder* mFootPrintHolder; // +0x4A0
    u8 _4B0[0x1A0];

    void initSpecial(const al::ActorInitInfo&, int, const char*,
                     IUsePlayerRetargettingInfoCreator*,
                     IUsePlayerRetargettingSelector*,
                     IUsePlayerActionGraphBuilder*,
                     const char*, unsigned int, int, const char*);
};

static_assert(sizeof(PlayerActor) == 0x648);
