#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
#include "Game/Player/PlayerModel.h"
#include <sead/container/seadPtrArray.h>

class PlayerModelHolder {
private:
    u8 inherit[0x20];
    PlayerModel** mModels;           // +0x20
    int mCurModelIndex;              // +0x28
    u8 unk[0x28];
    int mBufferSize;                 // +0x58
    u8 unk1;

public:
    PlayerModelHolder(int allocBuffer);

    virtual void change(int index);
    virtual void show();
    virtual void hide();
    virtual bool isHidden() const;
    virtual void showSilhouette();
    virtual void hideSilhouette();
    virtual bool isSilhouetteHidden() const;
    virtual void showShadow();
    virtual void hideShadow();
    virtual bool isShadowHidden() const;
    virtual void validateMash();
    virtual void invalidateMash();
    virtual bool isMash() const;

    void validateTailDynamics();
    void registerModel(int index, PlayerModel* model);
    void initCurrentModel(int index);

    PlayerModel* getCurrentModel() const { return mModels[mCurModelIndex]; }
};
