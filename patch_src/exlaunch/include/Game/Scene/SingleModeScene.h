#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
// Key: SingleModeScene is the Bowser's Fury scene class.
//   isBossScene() virtual at some vtable slot — used by figure fix to
//   determine if we're in a giga boss fight and need ClimbGiga figure.

class IslandKeeper;
class RaidonSurf;
class SingleModeSceneLayout;

class SingleModeScene {
public:
    void movement();

    u8 unk[0xdf];
    IslandKeeper* mIslandKeeper;               // +0x0E0
    u8 _1C8[0xa8];
    RaidonSurf* mRaidonSurf;                   // +0x190
    u8 _278[0x50];
    SingleModeSceneLayout* mLayout;            // +0x1E8

    virtual bool isScenarioComplete(int, int);
    virtual bool isChangePhase() const;
    virtual bool allowRestartPoint() const;
    virtual bool isIslandScene() const;
    virtual bool isBossScene() const;          // returns true in giga boss fights
    virtual bool isGameEnd() const;
    virtual bool isPhaseEnd() const;
};
