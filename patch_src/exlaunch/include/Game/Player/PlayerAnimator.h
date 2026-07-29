#pragma once

// From bf-multiplayer (fruityloops1) — reference header for SM3DW+BF v1.1.0.
#include "Game/Player/PlayerModelHolder.h"
#include "al/LiveActor/LiveActor.h"
#include <sead/prim/seadSafeString.h>

class IUsePlayerRetargettingSelector;

class PlayerAnimator {
public:
    al::LiveActor* mParent;                          // +0x00
    PlayerModelHolder* mModelHolder;                  // +0x08
    IUsePlayerRetargettingSelector* mRetargettingSelector; // +0x10
    class PlayerAnimFrameCtrl* mAnimFrameCtrl;        // +0x18
    bool mIsSubAnim;                                  // +0x20
    u8 unk[0x7];
    float mBlendWeights[6];                           // +0x28 (6 floats)
    u8 unk2[0x10];
    sead::FixedSafeString<64> mCurAnimName;           // +0x50
    sead::FixedSafeString<64> mCurSubAnimName;        // +0x90
    u8 unk4[0x60];

    PlayerAnimator(al::LiveActor* parent, PlayerModelHolder* modelHolder,
                   IUsePlayerRetargettingSelector* retargettingSelector);

    void init();
    void update();
    virtual ~PlayerAnimator();

    virtual void enableAlphaCtrl(bool);
    virtual void startAnim(const sead::SafeString& anim);
    virtual void setAnimRate(float rate);
    virtual void setAnimRateCommon(float rate);
    virtual void setAnimFrame(float frame);
    virtual bool isAnimEnd() const;
    virtual bool isAnim(const sead::SafeString& anim) const;
    virtual bool isAnimReverse() const;
    virtual float getAnimFrame() const;
    virtual float getAnimFrameMax() const;
    virtual void clearInterpolation();
    virtual const char* getAnimName() const;
    virtual void startSubAnim(const sead::SafeString& subAnim);
    virtual void endSubAnim();
    virtual bool isSubAnimBinding() const;
    virtual bool isSubAnimEnd() const;
    virtual bool isSubAnim(const sead::SafeString& subAnim) const;
    virtual bool isSubAnimReverse() const;
    virtual float getSubAnimFrame() const;
    virtual float getAnimFrameMax(const sead::SafeString& anim) const;
    virtual void startMaterialAnim(const sead::SafeString& mclAnim);
    virtual bool isMaterialAnimEnd() const;
    virtual void setWeightSixfold(float, float, float, float, float, float);
    virtual float getWeight(int index) const;
    bool isUpperBodyAnimAttached() const;
    void resetWeight();
};
