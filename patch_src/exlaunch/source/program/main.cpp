#include "lib.hpp"
#include "lib/patch/patcher_impl.hpp"
#include "nn/fs/fs_files.hpp"

#include <cstddef>

#define BFCOOP_EXLMOD_ENABLED 0
#define BFCOOP_SETTINGS_CORE_ENABLED BFCOOP_EXLMOD_ENABLED
#define BFCOOP_SETTINGS_MENU_OVERLAY_ENABLED 0
#define RELEASE_DIAGNOSTIC_SETTINGS_START_VISIBLE 0
#define RELEASE_DIAGNOSTIC_NVN_SUBMITTER_ENABLED 0

#if BFCOOP_EXLMOD_ENABLED
#include "exlmod/arena_allocator.hpp"
#include "exlmod/imgui_nvn_backend.hpp"
#include "exlmod/nvn_bootstrap.hpp"
#include "exlmod/render.hpp"
#include "exlmod/settings.hpp"
#include "exlmod/settings_imgui.hpp"
#endif

#define PATCH_0016_ENABLED 1          






#define DIAG_DEATHCAM_HOLD 0

                                                                            
                                                                               
                                                                              
                                                                       
                                                                           
                                                                          
                                                                          
                                                                           
                                                                        
                                                                      
                                                                      
                                                                        
                                                                           
                                                          
#define PATCH_0019_DEAD_FRAMES 20

#define PATCH_0013_OVERRIDE_ENABLED 1  
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       

#define RELEASE_DIAGNOSTIC_ENABLED 0            
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       

  
                                                                         
                                                                              
                                                                               
                                                                      
                               
  
                                                       
                                                                       
                                                                       
                                                                        
                                                       
  
                                                             
                                                                          
                                                               
                                                                           
                                                        
                                                                     
                                
  
                                                                     
                                                                           
                                                            
                                                                                    
                                                                              
                                                               
                                                                              
                                       
                                                                             
                                                                          
                                                                                 
                                                                               
                                                                                   
  
                                               
                                                                 
                                                   
  
                                                    
                                                                
                                                                   
  
                                                                   
                                                                    
                                                                 
                                                               
                                                                    
                                                                     
                                                             
                                                                  
                                                                
                                                                  
                                                                    
                                                                     
   

namespace PatchOffsets {
    
    constexpr ptrdiff_t SceneInitPlayerCount = 0x3EE76C;
    constexpr ptrdiff_t SceneLoopMapperCheck = 0x3E82BC;
    constexpr ptrdiff_t SceneLoopActorCount  = 0x3E82CC;

    
    constexpr ptrdiff_t ArrayGetOrNull       = 0x1D9F40;

    
    constexpr ptrdiff_t JoinedCtorCallA      = 0x32D4E8;  
    constexpr ptrdiff_t JoinedCtorCallB      = 0x33C57C;  
    constexpr ptrdiff_t JoinedCtorCallC      = 0x33D198;  
    constexpr ptrdiff_t ActorControlDispatch = 0x366150;  
    constexpr ptrdiff_t DefaultStptrVtable   = 0x1379A28; 

    
    
    
    
    constexpr ptrdiff_t TreeSelSiteA = 0x2DA01C;  
    constexpr ptrdiff_t TreeSelSiteB = 0x2DA044;  
    constexpr ptrdiff_t TreeSelSiteC = 0x2DA080;  
    constexpr ptrdiff_t GrabSelSite  = 0x24AF74;  

    
    
    constexpr ptrdiff_t DirectSelSiteA = 0x2190EC;  
    constexpr ptrdiff_t DirectSelSiteB = 0x21C34C;  

    
    
    
    constexpr ptrdiff_t GetClippingRadius    = 0x00835010;
    constexpr ptrdiff_t GetClippingCenterPos = 0x00835190;
}

                                                                       
namespace CameraMidpointOffsets {
    constexpr ptrdiff_t MakeLookAtCamera = 0x00923170; 
    constexpr ptrdiff_t FinalPoseCommitArgs = 0x00923048; 
    
    constexpr ptrdiff_t AltAfterMidpoint = 0x0006D830;   
    constexpr ptrdiff_t AltAfterCommonPost = 0x0006D83C; 
    constexpr ptrdiff_t AltAfterTransition = 0x0006D9CC; 
    constexpr ptrdiff_t AltAfterUp = 0x0006D9D8;         
    constexpr ptrdiff_t AltFinalCommitArgs = 0x0006D9E4; 

    constexpr ptrdiff_t ScenePlayerCount = 0x000001D8;
    constexpr ptrdiff_t ScenePlayerArray = 0x000001E0;

    constexpr ptrdiff_t PlayerPosX = 0x0000047C;
    constexpr ptrdiff_t PlayerPosZ = 0x0000049C;
    constexpr ptrdiff_t PlayerPosY = 0x00000584;

    constexpr ptrdiff_t OutPosX    = 0x00000038;
    constexpr ptrdiff_t OutPosY    = 0x0000003C;
    constexpr ptrdiff_t OutPosZ    = 0x00000040;
    constexpr ptrdiff_t OutLookX   = 0x00000044;
    constexpr ptrdiff_t OutLookY   = 0x00000048;
    constexpr ptrdiff_t OutLookZ   = 0x0000004C;
    constexpr ptrdiff_t OutUpX     = 0x00000050;
    constexpr ptrdiff_t OutUpY     = 0x00000054;
    constexpr ptrdiff_t OutUpZ     = 0x00000058;
}


                                                                       
namespace CrashFixOffsets {
    constexpr ptrdiff_t FightInitFix      = 0x0039F580; 
    constexpr ptrdiff_t DarkBowserDemo    = 0x00015EC0; 
    constexpr ptrdiff_t Phase3InitA       = 0x0003EA64; 
    constexpr ptrdiff_t Phase3InitB       = 0x0003EA90; 
    constexpr ptrdiff_t Phase2Defeat      = 0x00872C68; 
    constexpr ptrdiff_t PlayerAliveGroup  = 0x00371FE8; 
    constexpr ptrdiff_t ActorKitCapacity  = 0x003E752C; 
    constexpr ptrdiff_t SceneObjHolderSz  = 0x003E624C; 
    constexpr ptrdiff_t FadeToWhiteA      = 0x0041D3F0; 
    constexpr ptrdiff_t FirstAppearA      = 0x0020D9C0; 
    constexpr ptrdiff_t BossResHeap       = 0x003D6044; 
    constexpr ptrdiff_t GhostReturn       = 0x00319A00; 
    constexpr ptrdiff_t SceneResHeapSize  = 0x00720554; 
}

                                                                       
namespace KoopaJrOffsets {
    constexpr ptrdiff_t SceneInit          = 0x003E7090; 
    constexpr ptrdiff_t SetNerve           = 0x00880950; 
    constexpr ptrdiff_t LiveActorKill      = 0x0085B9B0; 
    constexpr ptrdiff_t LiveActorHide      = 0x0085BBA0; 
    constexpr ptrdiff_t PassiveNerveData   = 0x0137F630; 
    constexpr ptrdiff_t ScenePlayerCount   = 0x000001D8; 
    constexpr ptrdiff_t ScenePlayerArray   = 0x000001E0; 
    constexpr ptrdiff_t PlayerKoopaJr      = 0x000005D8; 
    constexpr ptrdiff_t KoopaJrSceneObj    = 0x00000148; 
}

static uintptr_t sCurrentScene = 0;

                                                                       
namespace FigureFixOffsets {
    constexpr ptrdiff_t PhaseBossFigInit   = 0x003E8344; 
    constexpr ptrdiff_t GigaModelName      = 0x00376EE0; 
    constexpr ptrdiff_t GigaBellCollect    = 0x0042EDD0; 
}





namespace Patch0025 {
    static int AssistMode();

    
    
    
    
    
    static bool sCoopLatch = false;   
    static bool sSceneCoop = false;   
    static bool sReArmed   = false;   
    static bool sConfigCoopLoaded = false;
    static bool sConfigCoopEnabled = false;

    
    
    
    constexpr long Set2PAssistModeOff        = 0x427720; 
    constexpr long SetAppletCancel2PAssistOff = 0x427760; 
}

namespace Patch0023 {
    static bool LoadContentConfig();
}

                                                                      

                                                                   
  
                                                             
                                       
                                                                        
                                                                            
                                                                          
                                                                         
                                                                           
                                                                    
                                                                            
                                                                            
                                                                        
   
HOOK_DEFINE_INLINE(ForcePlayerCount) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        Patch0023::LoadContentConfig();
        uint32_t vanilla = ctx->W[21];
        int mode = Patch0025::AssistMode();
        
        
        
        bool coop = (mode == 2) || Patch0025::sCoopLatch;
        Patch0025::sSceneCoop = coop;
        Patch0025::sReArmed = false;
        if (coop) ctx->W[21] = 2;
        Logging.Log("[BFCoop] PATCH-0004 scene-init: assist-mode=%d latch=%d players %u -> %u",
                    mode, Patch0025::sCoopLatch ? 1 : 0, vanilla,
                    static_cast<uint32_t>(ctx->W[21]));
    }
};

                                                                  
  
                                                                
                                                            
  
                                                             
                                                                   
                                                                 
                                                                     
   
HOOK_DEFINE_INLINE(FixSceneLoopMapper) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        
        
        
        
        
        
        if (!Patch0025::sSceneCoop) return;
        if (ctx->X[20] < 2) {
            ctx->W[0] = ctx->W[20];
        }
    }
};

                                              
  
                                                                
                                                                
                                                                  
                                            
  
                                                                
                                                                
   
HOOK_DEFINE_INLINE(FixActorCount) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        
        
        if (!Patch0025::sSceneCoop) return;
        ctx->X[8] = 2;
    }
};

                                                                      

                                         
  
                                  
                                                 
                                                
                                    
                                                  
                                                     
         
         
                      
  
                                                           
                            
                            
                            
                                                
  
                                                                
                                                                 
                                                                    
                             
   
HOOK_DEFINE_REPLACE(ArrayGetOrNull) {
    static void* Callback(void* container, int selector) {
        uintptr_t base = reinterpret_cast<uintptr_t>(container);

        int count = *reinterpret_cast<int*>(base + 0x08);
        void** array = *reinterpret_cast<void***>(base + 0x10);

        if (selector < count) {
            return array[selector];
        }

        
        *reinterpret_cast<int*>(base + 0x08) = selector + 1;
        array[selector] = array[0];
        return array[selector];
    }
};


                                                                       
  
                                                                           
                                                                            
                                                          
   

                                                                       
  
                                    
                                                                               
                                                                              
                                      
                                                                             
                                                             
   

using TryGetSceneObjFn = void* (*)(void* holder, int index);
using SetNerveFn = void (*)(void* nerveUser, void* nerve);
using LiveActorFn = void (*)(void* actor);

static inline bool IsSaneGamePtr(uintptr_t p) {
    return p > 0x10000 && p < 0x8000000000UL && (p & 7) == 0;
}

static void* TryGetKoopaJrFromSpawnedPlayers(void* scenePtr) {
    uintptr_t scene = reinterpret_cast<uintptr_t>(scenePtr);
    int count = *reinterpret_cast<int*>(scene + KoopaJrOffsets::ScenePlayerCount);
    if (count <= 0 || count > 4) {
        return nullptr;
    }

    uintptr_t players = *reinterpret_cast<uintptr_t*>(scene + KoopaJrOffsets::ScenePlayerArray);
    if (!IsSaneGamePtr(players)) {
        return nullptr;
    }

    for (int i = 0; i < count; i++) {
        uintptr_t player = *reinterpret_cast<uintptr_t*>(players + static_cast<uintptr_t>(i) * 8);
        if (!IsSaneGamePtr(player)) {
            continue;
        }

        uintptr_t koopaJr =
            *reinterpret_cast<uintptr_t*>(player + KoopaJrOffsets::PlayerKoopaJr);
        if (IsSaneGamePtr(koopaJr)) {
            return reinterpret_cast<void*>(koopaJr);
        }
    }

    return nullptr;
}

HOOK_DEFINE_TRAMPOLINE(KoopaJrNeutralize) {
    static void Callback(void* scenePtr, void* initInfo) {
        sCurrentScene = reinterpret_cast<uintptr_t>(scenePtr);
        Orig(scenePtr, initInfo);

        
        
        
        
        
        if (!Patch0025::sSceneCoop) {
            Logging.Log("[BFCoop] KoopaJr left vanilla (scene-init coop off)");
            return;
        }

        static TryGetSceneObjFn tryGetSceneObj = nullptr;
        if (!tryGetSceneObj) {
            tryGetSceneObj = reinterpret_cast<TryGetSceneObjFn>(
                exl::util::modules::GetTargetOffset(0x008A4A90)
            );
        }
        static SetNerveFn setNerve = nullptr;
        if (!setNerve) {
            setNerve = reinterpret_cast<SetNerveFn>(
                exl::util::modules::GetTargetOffset(KoopaJrOffsets::SetNerve)
            );
        }
        static LiveActorFn hideActor = nullptr;
        if (!hideActor) {
            hideActor = reinterpret_cast<LiveActorFn>(
                exl::util::modules::GetTargetOffset(KoopaJrOffsets::LiveActorHide)
            );
        }
        static LiveActorFn killActor = nullptr;
        if (!killActor) {
            killActor = reinterpret_cast<LiveActorFn>(
                exl::util::modules::GetTargetOffset(KoopaJrOffsets::LiveActorKill)
            );
        }

        
        
        
        void* kj = TryGetKoopaJrFromSpawnedPlayers(scenePtr);

        
        
        if (!kj && tryGetSceneObj) {
            void* holder =
                reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(scenePtr) + 0x28);
            void* sceneObj = tryGetSceneObj(holder, 56);
            if (sceneObj) {
                kj = reinterpret_cast<void*>(
                    reinterpret_cast<uintptr_t>(sceneObj) - KoopaJrOffsets::KoopaJrSceneObj
                );
            }
        }
        if (!kj || !IsSaneGamePtr(reinterpret_cast<uintptr_t>(kj))) return;

        uintptr_t passiveNerve =
            exl::util::modules::GetTargetOffset(KoopaJrOffsets::PassiveNerveData);
        setNerve(kj, reinterpret_cast<void*>(passiveNerve));
        hideActor(kj);
        killActor(kj);

        Logging.Log("[BFCoop] KoopaJr neutralized+hidden+killed, kj=%p nerve=%p",
            kj, (void*)passiveNerve);
    }
};

                                                                       
  
                                                        
  
                                            
                            
                                                                          
                                                            
                                                                         
                                                  
                                                                                    
                                                                             
                                                                              
  
                                        
                                     
                                                                       
                                                                 
                                                                            
                                                        
                                                                            
                                                                          
                                                                   
  
                                  
                            
                                                            
                                                                                  
                                                              
                                               
                                                                                         
                                                                
                                                             
   

                                                                               
HOOK_DEFINE_INLINE(FixPhaseBossFigure) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        
        
        
        
        ctx->W[24] = 9;
    }
};

                                                                             
HOOK_DEFINE_TRAMPOLINE(FixGigaModelName) {
    static int Callback(void* outStr, void* path, void* playerName, int figure) {
        
        
        
        
        
        if (figure == 9) {
            return Orig(outStr, path, playerName, 3);
        }
        return Orig(outStr, path, playerName, figure);
    }
};

                                                                          
HOOK_DEFINE_INLINE(FixGigaBellCollect) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        
        
        
        
        
        ctx->W[21] &= ~1;
    }
};

                                                                      
  
                                                                    
  
                                                                              
                                                                            
                                                                              
                                                                          
                                                                              
                                                                               
                                                                         
                                                                              
                                                                                  
  
                                                                               
                                                                                
                                                                                 
                                                                            
                                                                                 
                                                                                 
                                                             
   
static int  sLastValidPuppetIdx = -1;
static bool sLoggedPuppetRemap  = false;

                                                                          
                                                                              
                                                                               
                                                              
static inline void RemapLuigiSelectorReg(exl::hook::InlineCtx* ctx, int reg) {
    uint32_t idx = ctx->W[reg];
    if (idx == 0xFFFFFFFFu) {
        int li = (sLastValidPuppetIdx >= 0) ? sLastValidPuppetIdx + 1 : 1;
        if (li > 3) li = 3;
        ctx->W[reg] = static_cast<uint32_t>(li);
        if (!sLoggedPuppetRemap) {
            sLoggedPuppetRemap = true;
            Logging.Log("[BFCoop] selector remap: -1 -> %d (Mario idx=%d)",
                li, sLastValidPuppetIdx);
        }
    } else if (idx <= 3u) {
        sLastValidPuppetIdx = static_cast<int>(idx);
    }
}

                                                                
HOOK_DEFINE_INLINE(TreeSelA) { static void Callback(exl::hook::InlineCtx* ctx) { RemapLuigiSelectorReg(ctx, 1); } };
HOOK_DEFINE_INLINE(TreeSelB) { static void Callback(exl::hook::InlineCtx* ctx) { RemapLuigiSelectorReg(ctx, 1); } };
HOOK_DEFINE_INLINE(TreeSelC) { static void Callback(exl::hook::InlineCtx* ctx) { RemapLuigiSelectorReg(ctx, 1); } };
HOOK_DEFINE_INLINE(GrabSel)  { static void Callback(exl::hook::InlineCtx* ctx) { RemapLuigiSelectorReg(ctx, 1); } };


                                                                      
                                                                              
                                                                                
                                                                           
                                                                              
                                                                         
                                                                               
                                             
                                         
                                    
                                                      
                                                                                            
                                                                                       
   
static int P16PlayerSelector(uintptr_t actor) {
    if (!IsSaneGamePtr(actor)) return -99;
    uintptr_t selp = *reinterpret_cast<uintptr_t*>(actor + 0x1D0);
    if (!IsSaneGamePtr(selp)) return -99;
    return *reinterpret_cast<int*>(selp + 8);
}


                                                                       
                                                                        
                                                                       
                                                                           
                                                                               
                                                                              
                                                                       
                                                                             
                                                                                       
   
namespace Patch0016 {
    constexpr ptrdiff_t StateCtrl    = 0x1C8;  
    constexpr ptrdiff_t CurStatePtr  = 0x88;   
    
    
    
    
    
    constexpr int       DownFrames   = DIAG_DEATHCAM_HOLD ? 99999999 : 600;
    
    constexpr long      AppearSingleModeOff = 0x366150; 
    constexpr long      MakeAppearedOff = 0x3663B0; 
    constexpr long      RestartOnGroundOff = 0x36B280; 
    
    
    
    
    
    
    
    
    
    
    
    
    constexpr ptrdiff_t PlayerModelHolderField = 0x240; 
    constexpr ptrdiff_t PMHIndexOff   = 0x30;  
    constexpr ptrdiff_t PMHCountOff   = 0x5c;  
    constexpr long      PMHAppearOff  = 0x3ac840; 
    constexpr long      ValidateClippingOff= 0x8354F0; 
    constexpr long      OnDrawClippingOff  = 0x835530; 
    constexpr long      ShowModelOff    = 0x83A350; 
    constexpr long      SetDisableDrawOff = 0x83A7E0; 
    constexpr long      SetScaleAllOff  = 0x83FD60; 
    constexpr long      SetTransOff     = 0x83FA00; 
}

static bool P16ReadState(uintptr_t player, int* idOut, uintptr_t* stOut) {
    if (!IsSaneGamePtr(player)) return false;
    uintptr_t ctrl = *reinterpret_cast<uintptr_t*>(player + Patch0016::StateCtrl);
    if (!IsSaneGamePtr(ctrl)) return false;
    uintptr_t st = *reinterpret_cast<uintptr_t*>(ctrl + Patch0016::CurStatePtr);
    if (!IsSaneGamePtr(st)) return false;
    *stOut = st;
    *idOut = *reinterpret_cast<int*>(st);
    return true;
}














static inline bool P16IsActorAlive(uintptr_t actor) {
    if (!IsSaneGamePtr(actor)) return false;
    uintptr_t flagPtr = *reinterpret_cast<uintptr_t*>(actor + 0x108);
    if (!IsSaneGamePtr(flagPtr)) return false;
    return *reinterpret_cast<unsigned char*>(flagPtr) == 0;
}




static uintptr_t P16FindAlivePartner(uintptr_t player) {
    uintptr_t scene = sCurrentScene;
    if (!IsSaneGamePtr(scene)) return 0;
    int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
    if (count < 2 || count > 8) return 0;
    uintptr_t array = *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
    if (!IsSaneGamePtr(array)) return 0;
    for (int i = 0; i < count; i++) {
        uintptr_t p = *reinterpret_cast<uintptr_t*>(array + i * 8);
        if (!IsSaneGamePtr(p) || p == player) continue;
        if (P16IsActorAlive(p)) return p;
    }
    return 0;
}





namespace Patch0016Safe {
    constexpr int SafeRing        = 12;  
    constexpr int SafeSampleEvery = 12;  
}
struct P16Slot {
    uintptr_t actor; int lastId; int deadFrames; bool revived;
    float ringX[Patch0016Safe::SafeRing];
    float ringY[Patch0016Safe::SafeRing];
    float ringZ[Patch0016Safe::SafeRing];
    int   ringHead;   
    int   ringCount;  
    int   sampleCtr;  
    unsigned lastFrame;      
    int      sameFrameCalls; 
    int   traceLeft;  
    int   traceCtr;   
    float tgtX, tgtY, tgtZ; 
    int   reapplyLeft;      
    int   reapplyCount;     
    int   dbgLastId;        
    int   dbgLastAlive;     
};
static P16Slot sP16[8] = {};
static int sP16N = 0;









static unsigned sP16GlobalFrame = 0;

                                                                     
                                                                              
                                                                      
                                                                           
                                                                            
                                                                          
                                                                           
                                                                       
                                                                   
namespace Patch0021 {
    constexpr unsigned kDyingWindowFrames = 900;  
    constexpr int      kFigMini = 1;              
}
static uintptr_t sEarlyFatalActor = 0;
static unsigned  sEarlyFatalFrame = 0;
static bool P21IsDying(uintptr_t actor) {
    if (sEarlyFatalActor == 0 || actor != sEarlyFatalActor) return false;
    return (sP16GlobalFrame - sEarlyFatalFrame) < Patch0021::kDyingWindowFrames;
}

                                                                      
                                                                          
                                                                          
                                                                            
                                            
static uintptr_t sBubbleActor = 0;
static unsigned  sBubbleUntilFrame = 0;


static uintptr_t sBubbleRearmPending = 0;






constexpr unsigned kBubbleWindowFrames = 300;

static bool P21IsInBubble(uintptr_t actor) {
    if (sBubbleActor == 0 || actor != sBubbleActor) return false;
    if (sP16GlobalFrame >= sBubbleUntilFrame) { sBubbleActor = 0; return false; }
    return true;
}

                                                                           
                                                                          
                                                                      
                                                                           
                                                                           
                                                                           
                                                     
                                                                          
                                                                     
                                                                    
                                                                            
                                                                          
                                                                            
                                                                            
                                                                        
                                                                      
                                                                      
                                                                           
                                                                         
                                                                        
#define PATCH_0021_GATES_ENABLED 0
static bool P21IsOut(uintptr_t actor, int deadFrames) {
    if (deadFrames >= PATCH_0019_DEAD_FRAMES && deadFrames != -1) return true;
    if (PATCH_0021_GATES_ENABLED && P21IsDying(actor)) return true;
    if (P21IsInBubble(actor)) return true;
    return false;
}

                                                                       
                                                                   
                                                                             
                                                                              
                                                                           
                                                                            
                                                                             
                                                                             
                                                                          
                                                                            
                                                                         
                                                                          
                                                                       
#define PATCH_0022_ENABLED 1
#if PATCH_0022_ENABLED
HOOK_DEFINE_TRAMPOLINE(SkipFreezeDistance) {
    static void Callback(void* dir) {
        uintptr_t dying = sEarlyFatalActor;
        bool skip = (dying != 0) && IsSaneGamePtr(dying) &&
                    (P16FindAlivePartner(dying) != 0);
        static int sN = 0;
        if (sN < 20) {
            sN++;
            Logging.Log("[BFCoop] PATCH-0022 freeze-distance %s (dying=%p frame=%u)",
                skip ? "SKIPPED" : "pass-through",
                reinterpret_cast<void*>(dying), sP16GlobalFrame);
        }
        if (!skip) Orig(dir);
    }
};
#endif




static void Patch0025Tick(uintptr_t player);

HOOK_DEFINE_INLINE(InterceptDeath) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        uintptr_t player = ctx->X[0];
        Patch0025Tick(player);
        int id; uintptr_t st;
        if (!P16ReadState(player, &id, &st)) return;
        int slot = -1;
        for (int i = 0; i < sP16N; i++) if (sP16[i].actor == player) { slot = i; break; }
        if (slot < 0 && sP16N < 8) {
            slot = sP16N++;
            sP16[slot].actor = player; sP16[slot].lastId = 0;
            sP16[slot].deadFrames = 0; sP16[slot].revived = false;
            sP16[slot].ringHead = 0; sP16[slot].ringCount = 0; sP16[slot].sampleCtr = 0;
            sP16[slot].lastFrame = 0; sP16[slot].sameFrameCalls = 0;
            sP16[slot].traceLeft = 0; sP16[slot].traceCtr = 0;
            sP16[slot].tgtX = 0; sP16[slot].tgtY = 0; sP16[slot].tgtZ = 0;
            sP16[slot].reapplyLeft = 0; sP16[slot].reapplyCount = 0;
            sP16[slot].dbgLastId = -99; sP16[slot].dbgLastAlive = -1;
        }
        if (slot < 0) return;
        P16Slot& s = sP16[slot];

        
        
        {
            int aliveNow = P16IsActorAlive(player) ? 1 : 0;
            if (id != s.dbgLastId || aliveNow != s.dbgLastAlive) {
                
                if (aliveNow == 1 && s.dbgLastAlive == 0 && player == sEarlyFatalActor)
                    sEarlyFatalActor = 0;
                s.dbgLastId = id; s.dbgLastAlive = aliveNow;
            }
        }

        
        
        
        
        
        
        
        
        
#define P16_REPLACE_ENABLED 0
        if (P16_REPLACE_ENABLED && s.reapplyLeft > 0) {
            s.reapplyLeft--;
            if (s.reapplyLeft <= 117) {
                float cx = *reinterpret_cast<float*>(player + CameraMidpointOffsets::PlayerPosX);
                float cy = *reinterpret_cast<float*>(player + CameraMidpointOffsets::PlayerPosY);
                float cz = *reinterpret_cast<float*>(player + CameraMidpointOffsets::PlayerPosZ);
                float dx = cx - s.tgtX, dy = cy - s.tgtY, dz = cz - s.tgtZ;
                if (dx*dx + dy*dy + dz*dz > 1000.0f * 1000.0f) {
                    uintptr_t setTrans = exl::util::modules::GetTargetOffset(Patch0016::SetTransOff);
                    if (IsSaneGamePtr(setTrans)) {
                        reinterpret_cast<void(*)(void*, float, float, float)>(setTrans)(
                            reinterpret_cast<void*>(player), s.tgtX, s.tgtY, s.tgtZ);
                        if (++s.reapplyCount <= 5)
                            Logging.Log("[BFCoop] PATCH-0016 re-place #%d: player=%p was=(%.1f,%.1f,%.1f) -> tgt=(%.1f,%.1f,%.1f)",
                                s.reapplyCount, reinterpret_cast<void*>(player),
                                cx, cy, cz, s.tgtX, s.tgtY, s.tgtZ);
                    }
                } else {
                    s.reapplyLeft = 0;  
                }
            }
        }

        
        

        
        
        
        
        
        bool actorAlive = P16IsActorAlive(player);
        if (actorAlive) {
            s.deadFrames = 0; s.revived = false; s.lastId = id;
            
            
            
            
            
            
#if PATCH_0022_ENABLED
            
            
            
            
            
            
            
            if (sBubbleRearmPending == player &&
                (sBubbleActor != player || sP16GlobalFrame >= sBubbleUntilFrame)) {
                sBubbleRearmPending = 0;
                uintptr_t fn = exl::util::modules::GetTargetOffset(0x914d50);
                if (IsSaneGamePtr(fn)) {
                    reinterpret_cast<void (*)(void*, bool)>(fn)(
                        reinterpret_cast<void*>(player), true);
                    Logging.Log("[BFCoop] PATCH-0022 re-arm: player=%p sel=%d frame=%u",
                        reinterpret_cast<void*>(player), P16PlayerSelector(player),
                        sP16GlobalFrame);
                }
            }
#endif
            
            
            if (id == 0) {
                if (++s.sampleCtr >= Patch0016Safe::SafeSampleEvery) {
                    s.sampleCtr = 0;
                    float x = *reinterpret_cast<float*>(player + CameraMidpointOffsets::PlayerPosX);
                    float y = *reinterpret_cast<float*>(player + CameraMidpointOffsets::PlayerPosY);
                    float z = *reinterpret_cast<float*>(player + CameraMidpointOffsets::PlayerPosZ);
                    s.ringX[s.ringHead] = x; s.ringY[s.ringHead] = y; s.ringZ[s.ringHead] = z;
                    s.ringHead = (s.ringHead + 1) % Patch0016Safe::SafeRing;
                    if (s.ringCount < Patch0016Safe::SafeRing) s.ringCount++;
                }
            }
            return;
        }

        
        
        uintptr_t partner = P16FindAlivePartner(player);
        if (partner == 0) { s.lastId = id; return; }

        
        unsigned nowFrame = sP16GlobalFrame;
        if (s.lastFrame == nowFrame && ++s.sameFrameCalls < 8) {
            s.lastId = id;
            return;
        }
        s.lastFrame = nowFrame;
        s.sameFrameCalls = 0;
        s.deadFrames++;

        
        
        
        
        
        
        if (s.deadFrames >= Patch0016::DownFrames) {
            if (!s.revived) {
                
                
                float px, py, pz; const char* warpSrc;
                if (s.ringCount > 0) {
                    int oldest = (s.ringCount == Patch0016Safe::SafeRing) ? s.ringHead : 0;
                    px = s.ringX[oldest]; py = s.ringY[oldest]; pz = s.ringZ[oldest];
                    warpSrc = "safeground";
                } else {
                    px = *reinterpret_cast<float*>(partner + CameraMidpointOffsets::PlayerPosX);
                    py = *reinterpret_cast<float*>(partner + CameraMidpointOffsets::PlayerPosY);
                    pz = *reinterpret_cast<float*>(partner + CameraMidpointOffsets::PlayerPosZ);
                    warpSrc = "partner";
                }
                
                
                
                
                
                
                
                
                
                {
                    float qx = *reinterpret_cast<float*>(partner + CameraMidpointOffsets::PlayerPosX);
                    float qy = *reinterpret_cast<float*>(partner + CameraMidpointOffsets::PlayerPosY);
                    float qz = *reinterpret_cast<float*>(partner + CameraMidpointOffsets::PlayerPosZ);
                    float ddx = px - qx, ddy = py - qy, ddz = pz - qz;
                    constexpr float kMaxGap = 2500.0f;  
                    if (ddx*ddx + ddy*ddy + ddz*ddz > kMaxGap*kMaxGap) {
                        px = qx; py = qy; pz = qz; warpSrc = "partner-far";
                        for (int i = 0; i < sP16N; i++) {
                            if (sP16[i].actor == partner && sP16[i].ringCount > 0) {
                                int po = (sP16[i].ringCount == Patch0016Safe::SafeRing)
                                             ? sP16[i].ringHead : 0;
                                px = sP16[i].ringX[po]; py = sP16[i].ringY[po]; pz = sP16[i].ringZ[po];
                                warpSrc = "partner-safeground";
                                break;
                            }
                        }
                    }
                }
                uintptr_t setTrans = exl::util::modules::GetTargetOffset(Patch0016::SetTransOff);
                
                if (IsSaneGamePtr(setTrans)) {
                    reinterpret_cast<void(*)(void*, float, float, float)>(setTrans)(
                        reinterpret_cast<void*>(player), px, py, pz);
                }
                
                uintptr_t appear = exl::util::modules::GetTargetOffset(Patch0016::AppearSingleModeOff);
                if (IsSaneGamePtr(appear)) {
                    reinterpret_cast<void(*)(void*, unsigned int)>(appear)(reinterpret_cast<void*>(player), 0u);
                }
                
                
                
                
                
                
                uintptr_t restart = exl::util::modules::GetTargetOffset(Patch0016::RestartOnGroundOff);
                if (IsSaneGamePtr(restart)) {
                    reinterpret_cast<void(*)(void*)>(restart)(reinterpret_cast<void*>(player));
                }
                
                if (IsSaneGamePtr(setTrans)) {
                    reinterpret_cast<void(*)(void*, float, float, float)>(setTrans)(
                        reinterpret_cast<void*>(player), px, py, pz);
                }
                
                
                
                
                
                
                
                

                
                uintptr_t appeared = exl::util::modules::GetTargetOffset(Patch0016::MakeAppearedOff);
                if (IsSaneGamePtr(appeared))
                    reinterpret_cast<void(*)(void*)>(appeared)(reinterpret_cast<void*>(player));

                
                uintptr_t valClip = exl::util::modules::GetTargetOffset(Patch0016::ValidateClippingOff);
                if (IsSaneGamePtr(valClip))
                    reinterpret_cast<void(*)(void*)>(valClip)(reinterpret_cast<void*>(player));
                uintptr_t onDrawClip = exl::util::modules::GetTargetOffset(Patch0016::OnDrawClippingOff);
                if (IsSaneGamePtr(onDrawClip))
                    reinterpret_cast<void(*)(void*)>(onDrawClip)(reinterpret_cast<void*>(player));

                
                uintptr_t showModel = exl::util::modules::GetTargetOffset(Patch0016::ShowModelOff);
                if (IsSaneGamePtr(showModel))
                    reinterpret_cast<void(*)(void*)>(showModel)(reinterpret_cast<void*>(player));

                
                uintptr_t setDraw = exl::util::modules::GetTargetOffset(Patch0016::SetDisableDrawOff);
                if (IsSaneGamePtr(setDraw))
                    reinterpret_cast<void(*)(void*, unsigned int)>(setDraw)(reinterpret_cast<void*>(player), 0u);
                uintptr_t setScale = exl::util::modules::GetTargetOffset(Patch0016::SetScaleAllOff);
                if (IsSaneGamePtr(setScale))
                    reinterpret_cast<void(*)(void*, float)>(setScale)(reinterpret_cast<void*>(player), 1.0f);

                
                
                uintptr_t holder = IsSaneGamePtr(player + Patch0016::PlayerModelHolderField)
                    ? *reinterpret_cast<uintptr_t*>(player + Patch0016::PlayerModelHolderField) : 0;
                int hIdx = -1; unsigned hCnt = 0;
                if (IsSaneGamePtr(holder)) {
                    hIdx = *reinterpret_cast<int*>(holder + Patch0016::PMHIndexOff);
                    hCnt = *reinterpret_cast<unsigned int*>(holder + Patch0016::PMHCountOff);
                }
                bool idxOk = IsSaneGamePtr(holder) && hCnt > 0 && hCnt < 16 && hIdx >= 0 && (unsigned)hIdx < hCnt;
                if (idxOk) {
                    uintptr_t pmhAppear = exl::util::modules::GetTargetOffset(Patch0016::PMHAppearOff);
                    if (IsSaneGamePtr(pmhAppear))
                        reinterpret_cast<void(*)(void*)>(pmhAppear)(reinterpret_cast<void*>(holder));
                }

                s.revived = true;
                
                
                
                sBubbleActor = player;
                sBubbleUntilFrame = sP16GlobalFrame + kBubbleWindowFrames;
                sBubbleRearmPending = player;  
                s.tgtX = px; s.tgtY = py; s.tgtZ = pz;  
                s.reapplyLeft = 120; s.reapplyCount = 0;
                Logging.Log("[BFCoop] PATCH-0016 respawn: player=%p sel=%d after=%d source=%s pos=(%.1f,%.1f,%.1f)",
                    reinterpret_cast<void*>(player), P16PlayerSelector(player), s.deadFrames,
                    warpSrc, px, py, pz);
            }
            
        }
        s.lastId = id;
    }
};

                                                                       
                                                               
                                                                   
                                                                       
                                                                     
                                                                          
                                                                      
                                                              
                                                       
HOOK_DEFINE_TRAMPOLINE(DiagFigureLose) {
    static void Callback(void* dirRaw) {
        uintptr_t dir = reinterpret_cast<uintptr_t>(dirRaw);
        int fig = -1;
        if (IsSaneGamePtr(dir)) {
            fig = *reinterpret_cast<int*>(dir + 4);
        }
        
        
        
        
        
        
        
        
        
        
        constexpr int kAggregateOff = 0x1C8;  
        constexpr int kFigDirOff    = 0x88;   
        uintptr_t ownerActor = 0; int ownerSel = -1;
        uintptr_t scene = sCurrentScene;
        if (IsSaneGamePtr(scene) && IsSaneGamePtr(dir)) {
            int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
            uintptr_t array = *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
            if (count >= 1 && count <= 8 && IsSaneGamePtr(array)) {
                for (int i = 0; i < count; i++) {
                    uintptr_t p = *reinterpret_cast<uintptr_t*>(array + i * 8);
                    if (!IsSaneGamePtr(p)) continue;
                    uintptr_t agg = *reinterpret_cast<uintptr_t*>(p + kAggregateOff);
                    if (!IsSaneGamePtr(agg)) continue;
                    if (*reinterpret_cast<uintptr_t*>(agg + kFigDirOff) == dir) {
                        ownerActor = p; ownerSel = P16PlayerSelector(p); break;
                    }
                }
            }
        }
        
        
        
        if (fig == Patch0021::kFigMini && ownerActor != 0) {
            sEarlyFatalActor = ownerActor;
            sEarlyFatalFrame = sP16GlobalFrame;
            Logging.Log("[BFCoop] PATCH-0021 early-fatal: actor=%p sel=%d frame=%u",
                reinterpret_cast<void*>(ownerActor), ownerSel, sP16GlobalFrame);
        }
        Orig(dirRaw);
    }
};

                                                                       
                                                                       
                                                                  
                                                                 
                                                              
                                                                         
                                                                            
                                                                        
                                                                           
                                                                             
                                                    
                                                                            
                                                                       
                                               
                                                                            
                                                                            
#define RELEASE_DIAGNOSTIC_ENABLED 0
#if RELEASE_DIAGNOSTIC_ENABLED
HOOK_DEFINE_TRAMPOLINE(Diag0029SetUpdateFreeze) {
    static void Callback(void* actor, unsigned flag) {
        static uintptr_t sLastActor = 1;   
        static unsigned  sLastFlag  = ~0u;
        static int sRepeat = 0;
        static int sLines  = 0;
        uintptr_t a = reinterpret_cast<uintptr_t>(actor);
        bool edge = (a != sLastActor) || ((flag & 1) != sLastFlag);
        if (edge) { sRepeat = 0; sLastActor = a; sLastFlag = flag & 1; }
        else sRepeat++;
        if (sLines < 120 && (edge || (sRepeat % 60) == 0)) {
            sLines++;
            Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC setUpdateFreeze: actor=%p flag=%u rep=%d frame=%u",
                actor, flag & 1, sRepeat, sP16GlobalFrame);
        }
        Orig(actor, flag);
    }
};
#endif

                                                                        
                                                                           
                                                                            
                                                                             
                                                                              
                                                                        
                                                                       
                                                                        
                                                                            
                                                                             
                                                                            
                                                                             
                                                                             
                                                                      
                               
                                                                           
                                                                              
                                                                             
                                                                          
#define RELEASE_DIAGNOSTIC_ENABLED 0
#if RELEASE_DIAGNOSTIC_ENABLED
HOOK_DEFINE_TRAMPOLINE(Diag0031CamCalcTarget) {
    static void Callback(void* actorRaw, bool flag) {
        uintptr_t actor = reinterpret_cast<uintptr_t>(actorRaw);
        static uintptr_t sActors[4] = {};
        static int sLastFlag[4] = {-1, -1, -1, -1};
        static int sRepeat[4] = {};
        static int sLines = 0;
        int slot = -1;
        for (int i = 0; i < 4; i++) { if (sActors[i] == actor) { slot = i; break; } }
        if (slot < 0) {
            for (int i = 0; i < 4; i++) {
                if (sActors[i] == 0) { sActors[i] = actor; slot = i; break; }
            }
        }
        int f = flag ? 1 : 0;
        bool edge = (slot < 0) || (sLastFlag[slot] != f);
        if (slot >= 0) {
            if (edge) { sLastFlag[slot] = f; sRepeat[slot] = 0; }
            else sRepeat[slot]++;
        }
        if (sLines < 120 && (edge || (slot >= 0 && (sRepeat[slot] % 300) == 0))) {
            sLines++;
            int sel = IsSaneGamePtr(actor) ? P16PlayerSelector(actor) : -1;
            Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC camCalcTarget: actor=%p flag=%d sel=%d rep=%d frame=%u",
                actorRaw, f, sel, slot >= 0 ? sRepeat[slot] : -1, sP16GlobalFrame);
        }
        Orig(actorRaw, flag);
    }
};
#endif

                                                                       
  
                                                                      
                                                                    
                                                                             
                                                                              
                                                                             
                                      
  
                                                  
                                                                            
                                                                              
                                                                                 
                                                                                
                                                                              
                                                                            
                                                                       
                                                                       
   

                                                                          
                                                                            
                                            
#ifndef PATCH_0017_PERSISTENT_DEAD_FRAMES
#define PATCH_0017_PERSISTENT_DEAD_FRAMES 500
#endif







#define PATCH_0017C_DIAG_EXTREME 0

static inline bool CameraSanePtr(uintptr_t p) {
    return p > 0x10000 && p < 0x8000000000UL && (p & 7) == 0;
}

static inline bool CameraSaneFloatPtr(uintptr_t p) {
    return p > 0x10000 && p < 0x8000000000UL && (p & 3) == 0;
}

static inline bool CameraSaneFloat(float v) {
    return (v == v) && v > -10000000.0f && v < 10000000.0f;
}

static inline float ReadF(uintptr_t base, ptrdiff_t off) {
    return *reinterpret_cast<float*>(base + off);
}

static inline void WriteF(uintptr_t base, ptrdiff_t off, float value) {
    *reinterpret_cast<float*>(base + off) = value;
}

HOOK_DEFINE_TRAMPOLINE(CameraMidpointLookAt) {
    static void Callback(void* poser, void* output) {
        Orig(poser, output);

        uintptr_t scene = sCurrentScene;
        uintptr_t out = reinterpret_cast<uintptr_t>(output);
        if (!CameraSanePtr(scene) || !CameraSanePtr(out)) return;

        int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
        if (count < 2 || count > 8) return;

        uintptr_t array = *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
        if (!CameraSanePtr(array)) return;

        uintptr_t mario = *reinterpret_cast<uintptr_t*>(array + 0x00);
        uintptr_t luigi = *reinterpret_cast<uintptr_t*>(array + 0x08);
        if (!CameraSanePtr(mario) || !CameraSanePtr(luigi) || mario == luigi) return;

        
        
        
        
        
        
        if (Patch0025::AssistMode() != 2) return;

        float mx = ReadF(mario, CameraMidpointOffsets::PlayerPosX);
        float my = ReadF(mario, CameraMidpointOffsets::PlayerPosY);
        float mz = ReadF(mario, CameraMidpointOffsets::PlayerPosZ);
        float lx = ReadF(luigi, CameraMidpointOffsets::PlayerPosX);
        float ly = ReadF(luigi, CameraMidpointOffsets::PlayerPosY);
        float lz = ReadF(luigi, CameraMidpointOffsets::PlayerPosZ);

        if (!CameraSaneFloat(mx) || !CameraSaneFloat(my) || !CameraSaneFloat(mz) ||
            !CameraSaneFloat(lx) || !CameraSaneFloat(ly) || !CameraSaneFloat(lz)) {
            return;
        }

        float midX = (mx + lx) * 0.5f;
        float midY = (my + ly) * 0.5f;
        float midZ = (mz + lz) * 0.5f;

        
        
        
        
        
        
        
        
        
        
        
        
        {
            constexpr float kVoidY   = -400.0f;
            constexpr float kVoidGap = 600.0f;
            bool luigiVoid = (ly < kVoidY) && (my - ly > kVoidGap);
            bool marioVoid = (my < kVoidY) && (ly - my > kVoidGap);
            static bool sVoidBias = false;
            if (luigiVoid != marioVoid) {
                if (luigiVoid) { midX = mx; midY = my; midZ = mz; }
                else           { midX = lx; midY = ly; midZ = lz; }
                if (!sVoidBias) {
                    sVoidBias = true;
                    Logging.Log("[BFCoop] PATCH-0020 void-bias ON: follow=%s (My=%.0f Ly=%.0f)",
                        luigiVoid ? "MARIO" : "LUIGI", my, ly);
                }
            } else if (sVoidBias) {
                sVoidBias = false;
                Logging.Log("[BFCoop] PATCH-0020 void-bias OFF (My=%.0f Ly=%.0f)", my, ly);
            }
        }

        
        
        
        
        
        
        int luigiDf = -1, marioDf = -1;
        for (int i = 0; i < sP16N; i++) {
            if (sP16[i].actor == luigi)  luigiDf = sP16[i].deadFrames;
            else if (sP16[i].actor == mario) marioDf = sP16[i].deadFrames;
        }
        
        
        
        
        
        
        bool luigiPersistDead = P21IsOut(luigi, luigiDf);
        bool marioPersistDead = P21IsOut(mario, marioDf);
        bool collapsing = (luigiPersistDead != marioPersistDead);  
#if DIAG_DEATHCAM_HOLD
        
        
        if (collapsing) {
            static int sAnchorSkip = 0, sAnchorLogged = 0;
            if (sAnchorLogged < 8 && ++sAnchorSkip >= 30) {
                sAnchorSkip = 0; sAnchorLogged++;
                Logging.Log("[BFCoop] DIAG-CAM anchor: poser=%p out=%p scene=%p mario=%p luigi=%p",
                    poser, output, reinterpret_cast<void*>(scene),
                    reinterpret_cast<void*>(mario), reinterpret_cast<void*>(luigi));
            }
        }
#endif
        static bool sLoggedCollapse = false;
        if (collapsing) {
            if (luigiPersistDead) { midX = mx; midY = my; midZ = mz; }
            else                 { midX = lx; midY = ly; midZ = lz; }
            if (!sLoggedCollapse) {
                sLoggedCollapse = true;
                Logging.Log(
                  "[BFCoop] PATCH-0017 survivor-collapse: target=%s "
                  "(M df=%d L df=%d)",
                  luigiPersistDead ? "MARIO" : "LUIGI",
                  marioDf, luigiDf);
            }
        } else {
            sLoggedCollapse = false;
        }

        float oldLookX = ReadF(out, CameraMidpointOffsets::OutLookX);
        float oldLookY = ReadF(out, CameraMidpointOffsets::OutLookY);
        float oldLookZ = ReadF(out, CameraMidpointOffsets::OutLookZ);
        if (!CameraSaneFloat(oldLookX) || !CameraSaneFloat(oldLookY) || !CameraSaneFloat(oldLookZ)) {
            return;
        }

#if PATCH_0013_OVERRIDE_ENABLED
        
        
        
        
        
        
        
        
        float dx = midX - oldLookX;
        float dy = midY - oldLookY;
        float dz = midZ - oldLookZ;

        WriteF(out, CameraMidpointOffsets::OutPosX, ReadF(out, CameraMidpointOffsets::OutPosX) + dx);
        WriteF(out, CameraMidpointOffsets::OutPosY, ReadF(out, CameraMidpointOffsets::OutPosY) + dy);
        WriteF(out, CameraMidpointOffsets::OutPosZ, ReadF(out, CameraMidpointOffsets::OutPosZ) + dz);
        WriteF(out, CameraMidpointOffsets::OutLookX, midX);
        WriteF(out, CameraMidpointOffsets::OutLookY, midY);
        WriteF(out, CameraMidpointOffsets::OutLookZ, midZ);
#else
        
        
        
        
        
        (void)midX; (void)midY; (void)midZ;
#endif
    }
};

                                                                                 
                                                                                
                                                                             
                                                                               
                                                                  
                                                                              
                                                                         
                                                                          
                                                                             
                                                                               
                                                                                 
                                                                               
                    
  
             
                                                                          
                                                                              
                                         
                                                                              
                                                                                
                                                                                 
                                                     
  
                                                                                 
   
namespace Patch0017c {
    constexpr int kLogMax    = 60;
    constexpr int kLogEveryN = 15;
    static int s_logged = 0;
    static int s_skip   = 0;
    static float sOffX = 0.f, sOffY = 0.f, sOffZ = 0.f;
    static bool  sHaveOff = false;
}

HOOK_DEFINE_TRAMPOLINE(Diag0021Camera9207c0) {
    static void Callback(void* sub_poser, void* output) {
        Orig(sub_poser, output);

        uintptr_t out = reinterpret_cast<uintptr_t>(output);
        if (!IsSaneGamePtr(out)) return;

        uintptr_t scene = sCurrentScene;
        if (!IsSaneGamePtr(scene)) return;
        int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
        if (count < 2 || count > 8) return;
        uintptr_t array = *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
        if (!IsSaneGamePtr(array)) return;
        uintptr_t mario = *reinterpret_cast<uintptr_t*>(array + 0x00);
        uintptr_t luigi = *reinterpret_cast<uintptr_t*>(array + 0x08);
        if (!IsSaneGamePtr(mario) || !IsSaneGamePtr(luigi) || mario == luigi) return;

        
        float ex  = ReadF(out, CameraMidpointOffsets::OutPosX);
        float ey  = ReadF(out, CameraMidpointOffsets::OutPosY);
        float ez  = ReadF(out, CameraMidpointOffsets::OutPosZ);
        float lkx = ReadF(out, CameraMidpointOffsets::OutLookX);
        float lky = ReadF(out, CameraMidpointOffsets::OutLookY);
        float lkz = ReadF(out, CameraMidpointOffsets::OutLookZ);
        if (!CameraSaneFloat(ex)  || !CameraSaneFloat(ey)  || !CameraSaneFloat(ez) ||
            !CameraSaneFloat(lkx) || !CameraSaneFloat(lky) || !CameraSaneFloat(lkz)) return;

        
        int luigiDf = -1, marioDf = -1;
        for (int i = 0; i < sP16N; i++) {
            if (sP16[i].actor == luigi)      luigiDf = sP16[i].deadFrames;
            else if (sP16[i].actor == mario) marioDf = sP16[i].deadFrames;
        }
        
        bool luigiDead = P21IsOut(luigi, luigiDf);
        bool marioDead = P21IsOut(mario, marioDf);
        bool collapsing = (luigiDead != marioDead);  

        if (!collapsing) {
            
            
            Patch0017c::sOffX = ex - lkx;
            Patch0017c::sOffY = ey - lky;
            Patch0017c::sOffZ = ez - lkz;
            Patch0017c::sHaveOff = true;
            Patch0017c::s_logged = 0;  
            return;
        }
        if (!Patch0017c::sHaveOff) return;  

        
        uintptr_t surv = luigiDead ? mario : luigi;
        float sx = ReadF(surv, CameraMidpointOffsets::PlayerPosX);
        float sy = ReadF(surv, CameraMidpointOffsets::PlayerPosY);
        float sz = ReadF(surv, CameraMidpointOffsets::PlayerPosZ);
        if (!CameraSaneFloat(sx) || !CameraSaneFloat(sy) || !CameraSaneFloat(sz)) return;

        
        
        float offX = Patch0017c::sOffX;
        float offY = Patch0017c::sOffY;
        float offZ = Patch0017c::sOffZ;
#if PATCH_0017C_DIAG_EXTREME
        
        
        
        
        
        
        offX = 0.f; offY = 3000.f; offZ = 2000.f;
#endif
        WriteF(out, CameraMidpointOffsets::OutLookX, sx);
        WriteF(out, CameraMidpointOffsets::OutLookY, sy);
        WriteF(out, CameraMidpointOffsets::OutLookZ, sz);
        WriteF(out, CameraMidpointOffsets::OutPosX, sx + offX);
        WriteF(out, CameraMidpointOffsets::OutPosY, sy + offY);
        WriteF(out, CameraMidpointOffsets::OutPosZ, sz + offZ);

        if (Patch0017c::s_logged < Patch0017c::kLogMax &&
            ++Patch0017c::s_skip >= Patch0017c::kLogEveryN) {
            Patch0017c::s_skip = 0;
            Patch0017c::s_logged++;
            Logging.Log(
              "[BFCoop] PATCH-0017c eye-fix: surv=%s eye=(%.1f,%.1f,%.1f) "
              "look=(%.1f,%.1f,%.1f) off=(%.1f,%.1f,%.1f) Mdf=%d Ldf=%d",
              luigiDead ? "MARIO" : "LUIGI",
              sx + offX, sy + offY, sz + offZ,
              sx, sy, sz,
              offX, offY, offZ,
              marioDf, luigiDf);
        }
    }
};

                                                                              
                                                                         
                                                                   
                                                                           
                                                                  
                                                                              
                                                                         
                                                                            
                                                                      
                                                                              
                                                                        
                                                                           
                                      

#define PATCH_0026_ENABLED 0
namespace Patch0026 {
    static void Apply(uintptr_t poser, uintptr_t eyePtr,
                      uintptr_t atPtr, uintptr_t upPtr);
}

#define PATCH_0027_ENABLED 1
namespace Patch0027 {
    static void Apply(uintptr_t poser, uintptr_t eyePtr, uintptr_t atPtr);
}

#define PATCH_0028_ENABLED 1
#define RELEASE_DIAGNOSTIC_PATCH0028_MODEL_BOUNDS_ENABLED 0
namespace Patch0028 {
    static void Apply(uintptr_t poser, uintptr_t eyePtr,
                      uintptr_t atPtr, uintptr_t upPtr);
}






HOOK_DEFINE_TRAMPOLINE(Patch0028FinalLookAtCamera) {
    static void Callback(void* self, void* camera) {
        Orig(self, camera);
        const uintptr_t poser = reinterpret_cast<uintptr_t>(self);
        const uintptr_t out = reinterpret_cast<uintptr_t>(camera);
        if (!CameraSanePtr(poser) || !CameraSanePtr(out))
            return;
#if PATCH_0028_ENABLED
        Patch0028::Apply(poser, out + 0x38, out + 0x44, out + 0x50);
#endif
    }
};

                                                                             
                                                                           
  
                                                                           
                                                                           
                                                                              
                                                                        
                                                                              
                                                                            
                                                                                
  
                                                                         
                                                                          
                                                                           
                                                                              
                                                                       
  
                                                                              
                                                                        
                                                                         
                                                                
   
#define PATCH_0019_ENABLED 1

namespace Patch0019 {
    
    constexpr ptrdiff_t PoserOwner = 0xa0;   
    constexpr ptrdiff_t OwnerMgr   = 0x28;   
    constexpr ptrdiff_t MgrArr2    = 0x20;   
    static uintptr_t sOrig    = 0;           
    static uintptr_t sSlot    = 0;           
    static bool      sSwapped = false;
    static bool      sLastDeadIsLuigi = false; 

    
    static uintptr_t SubjectSlot(uintptr_t poser) {
        if (!CameraSanePtr(poser)) return 0;
        uintptr_t owner = *reinterpret_cast<uintptr_t*>(poser + PoserOwner);
        if (!CameraSanePtr(owner)) return 0;
        uintptr_t mgr = *reinterpret_cast<uintptr_t*>(owner + OwnerMgr);
        if (!CameraSanePtr(mgr)) return 0;
        uintptr_t arr2 = *reinterpret_cast<uintptr_t*>(mgr + MgrArr2);
        if (!CameraSanePtr(arr2)) return 0;
        return arr2;  
    }
}




static bool AltCamCollapseState(uintptr_t* marioOut, uintptr_t* luigiOut,
                                bool* luigiDeadOut, int* marioDfOut, int* luigiDfOut) {
    uintptr_t scene = sCurrentScene;
    if (!CameraSanePtr(scene)) return false;
    int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
    if (count < 2 || count > 8) return false;
    uintptr_t array = *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
    if (!CameraSanePtr(array)) return false;
    uintptr_t mario = *reinterpret_cast<uintptr_t*>(array + 0x00);
    uintptr_t luigi = *reinterpret_cast<uintptr_t*>(array + 0x08);
    if (!CameraSanePtr(mario) || !CameraSanePtr(luigi) || mario == luigi) return false;

    int luigiDf = -1, marioDf = -1;
    for (int i = 0; i < sP16N; i++) {
        if (sP16[i].actor == luigi)      luigiDf = sP16[i].deadFrames;
        else if (sP16[i].actor == mario) marioDf = sP16[i].deadFrames;
    }
    
    
    
    
    
    
    bool luigiDead = P21IsOut(luigi, luigiDf);
    bool marioDead = P21IsOut(mario, marioDf);

    *marioOut = mario; *luigiOut = luigi;
    *luigiDeadOut = luigiDead; *marioDfOut = marioDf; *luigiDfOut = luigiDf;
    return (luigiDead != marioDead);  
}

                                                                       
                                                                          
                                                                     
                                                                             
                                                                          
                                                                            
                                                                             
                                                                              
                                                                      
                                                                              
                                                                              
                                                                               
#define RELEASE_DIAGNOSTIC_ENABLED 0

HOOK_DEFINE_INLINE(AltCamCommitOverride) {
    static void Callback(exl::hook::InlineCtx* ctx) {
        
        
        sP16GlobalFrame++;

#if RELEASE_DIAGNOSTIC_ENABLED
        {
            static int sLastFz = -2, sLastEx = -2;   
            static int sLines = 0;
            int fz = -1, ex = -1;                    
            uintptr_t scn = sCurrentScene;
            if (CameraSanePtr(scn)) {
                uintptr_t obj8 = *reinterpret_cast<uintptr_t*>(scn + 0x158);
                if (CameraSanePtr(obj8)) {
                    fz = *reinterpret_cast<unsigned char*>(obj8 + 0x61);
                    ex = *reinterpret_cast<unsigned char*>(obj8 + 0x62);
                }
            }
            if ((fz != sLastFz || ex != sLastEx) && sLines < 120) {
                sLines++;
                Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC freeze-byte: fz=%d ex=%d frame=%u",
                            fz, ex, sP16GlobalFrame);
                sLastFz = fz; sLastEx = ex;
            }
        }
#endif

        uintptr_t mario, luigi; bool luigiDead; int marioDf, luigiDf;
        bool collapsing = AltCamCollapseState(&mario, &luigi, &luigiDead, &marioDf, &luigiDf);

#if PATCH_0019_ENABLED
        
        
        
        
        {
            uintptr_t slot = Patch0019::SubjectSlot(ctx->X[19]);
            if (collapsing && slot) {
                uintptr_t alt = *reinterpret_cast<uintptr_t*>(slot + (luigiDead ? 0x8 : 0x10));
                if (!Patch0019::sSwapped) {
                    
                    uintptr_t orig = *reinterpret_cast<uintptr_t*>(slot);
                    if (CameraSanePtr(alt) && CameraSanePtr(orig) && alt != orig) {
                        Patch0019::sOrig = orig;
                        Patch0019::sSlot = slot;
                        *reinterpret_cast<uintptr_t*>(slot) = alt;
                        Patch0019::sSwapped = true;
                        Patch0019::sLastDeadIsLuigi = luigiDead;
                        Logging.Log("[BFCoop] PATCH-0019 retarget ON: dead=%s slot=%p orig=%p alt=%p Mdf=%d Ldf=%d",
                                    luigiDead ? "LUIGI" : "MARIO",
                                    reinterpret_cast<void*>(slot), reinterpret_cast<void*>(orig),
                                    reinterpret_cast<void*>(alt), marioDf, luigiDf);
                    }
                } else if (slot == Patch0019::sSlot &&
                           Patch0019::sLastDeadIsLuigi != luigiDead &&
                           CameraSanePtr(alt)) {
                    
                    
                    
                    
                    *reinterpret_cast<uintptr_t*>(slot) = alt;
                    Patch0019::sLastDeadIsLuigi = luigiDead;
                    Logging.Log("[BFCoop] PATCH-0019 retarget FLIP: dead=%s->%s alt=%p Mdf=%d Ldf=%d",
                                luigiDead ? "MARIO" : "LUIGI",
                                luigiDead ? "LUIGI" : "MARIO",
                                reinterpret_cast<void*>(alt), marioDf, luigiDf);
                }
            } else if (!collapsing && Patch0019::sSwapped) {
                
                
                if (slot && slot == Patch0019::sSlot && CameraSanePtr(Patch0019::sOrig)) {
                    *reinterpret_cast<uintptr_t*>(slot) = Patch0019::sOrig;
                    Logging.Log("[BFCoop] PATCH-0019 retarget OFF: restored orig=%p",
                                reinterpret_cast<void*>(Patch0019::sOrig));
                } else {
                    Logging.Log("[BFCoop] PATCH-0019 retarget OFF: slot changed (%p -> %p), state dropped",
                                reinterpret_cast<void*>(Patch0019::sSlot), reinterpret_cast<void*>(slot));
                }
                Patch0019::sSwapped = false;
                Patch0019::sOrig = 0;
                Patch0019::sSlot = 0;
            }
        }
#endif

    }
};

                                                                            
                                                                          
                                                                  
  
                                                                          
                                                                           
                                                                      
                                        
                                                                          
                                                           
                                                             
                                         
                                                                         
                                                                     
                                      
                                                                           
                                                                       
                                                        
  
                                                                         
                                                                         
                                                              
                                                           
  
                                                                           
                                                                           
                                                                            
                                                            
                                                                             
                                                                                 
                                                                                
                                                              
#define PATCH_0023_ENABLED 1
#define PATCH_0023_INSTALL_ENABLED 0
                                                                                 
                                                            
#define RELEASE_DIAGNOSTIC_PATCH0023_BOUNDARY_ENABLED 0
                                                                             
                                                                               
                                                                             
                                                                                 
#define PATCH_0023_DYNAMIC 0
                                                                          
                                                                              
                                                                   
#define PATCH_0023_PAD_CONTROL 0
                                                                      
                                                                       
                                                                              
                                                                
#define RELEASE_DIAGNOSTIC_ENABLED 0

                                                                           
                                                                             
                                                                               
                                                                           
                                                           
#define RELEASE_DIAGNOSTIC_RENDER_HOOK_ENABLED 0
                                                                            
                                                                            
                                                                                
#define RELEASE_DIAGNOSTIC_NVN_BOOTSTRAP_ENABLED 0
                                                                           
                                                                              
                                                                  
#define RELEASE_DIAGNOSTIC_SETTINGS_IMGUI_ENABLED 0







namespace Patch0025 { static int AssistMode(); }

namespace Patch0023 {
    
    constexpr ptrdiff_t CalcDistanceRaw = 0x0006BC00;
    
    
    
    
    constexpr ptrdiff_t ControllerMgrSlot = 0x01A28E30;
    constexpr int kPadUpBit   = 16;      
    constexpr int kPadDownBit = 17;      
    constexpr int kPadLeftBit = 18;      
    constexpr int kPadRightBit = 19;     

    constexpr const char* kBaseZoomSettingId = "camera.zoom.base";
    constexpr float kBaseZoom = 1.12f;   
    constexpr float kZoomStep = 0.15f;   
    constexpr float kZoomMin  = 1.00f;   
    constexpr float kZoomMax  = 2.50f;
                                                                         
                                                                            
                                             
                                                                             
                                                                              
                                                                         
                                                                              
                                                                          
                                                            
                                                                     
                                                             
                                              
    constexpr float kMaxZoom  = 2.80f;   
    constexpr float kSepStart = 500.0f;  
    constexpr float kSepFull  = 1600.0f; 
    constexpr float kLerp     = 0.05f;   

    static float    sZoom      = 1.0f;   
    static unsigned sLastFrame = 0;      
    static float    sBaseZoomValue = kBaseZoom; 

    [[maybe_unused]] static float ClampBaseZoom(float value) {
        if (value < kZoomMin) return kZoomMin;
        if (value > kZoomMax) return kZoomMax;
        return value;
    }

#if BFCOOP_EXLMOD_ENABLED
    static exlmod::settings::FloatSetting* sBaseZoomSetting = nullptr;

    static void OnBaseZoomChanged(exlmod::settings::FloatSetting*, float value, void*) {
        sBaseZoomValue = ClampBaseZoom(value);
    }

    static exlmod::settings::FloatSetting* BaseZoomSetting() {
        if (!sBaseZoomSetting) {
            sBaseZoomSetting = exlmod::settings::RegisterFloat({
                kBaseZoomSettingId,
                "Camera zoom distance",
                "Camera",
                sBaseZoomValue,
                kZoomMin,
                kZoomMax,
                kZoomStep,
                "%.2f",
                OnBaseZoomChanged,
                nullptr,
            });
        }
        return sBaseZoomSetting;
    }
#endif

    static float BaseZoom() {
        return sBaseZoomValue;
    }

    [[maybe_unused]] static void RegisterSettings() {
#if BFCOOP_EXLMOD_ENABLED
        (void)BaseZoomSetting();
#endif
    }

    constexpr const char* kConfigPath = "content:/BowsersFuryCoopMod/settings.ini";
    constexpr size_t kConfigMaxBytes = 1024;

    struct ParsedConfig {
        bool hasBaseZoom = false;
        float baseZoom = kBaseZoom;
        bool hasCoopEnabled = false;
        bool coopEnabled = false;
    };

    static const char* SkipConfigSpaces(const char* p, const char* end) {
        while (p < end && (*p == ' ' || *p == '\t' || *p == '\r')) {
            p++;
        }
        return p;
    }

    static const char* TrimConfigSpacesEnd(const char* begin, const char* end) {
        while (end > begin && (end[-1] == ' ' || end[-1] == '\t' || end[-1] == '\r')) {
            end--;
        }
        return end;
    }

    static bool ConfigKeyEquals(const char* begin, const char* end, const char* key) {
        for (; begin < end && *key; begin++, key++) {
            if (*begin != *key) {
                return false;
            }
        }
        return begin == end && *key == '\0';
    }

    static bool ConfigIsDigit(char c) {
        return c >= '0' && c <= '9';
    }

    static char ConfigLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return static_cast<char>(c + ('a' - 'A'));
        }
        return c;
    }

    static const char* ConfigValueTokenEnd(const char* begin, const char* end) {
        const char* p = begin;
        while (p < end && *p != ' ' && *p != '\t' && *p != '\r' && *p != '#' && *p != ';') {
            p++;
        }
        return p;
    }

    static bool ConfigTokenEqualsNoCase(const char* begin, const char* end, const char* value) {
        for (; begin < end && *value; begin++, value++) {
            if (ConfigLower(*begin) != ConfigLower(*value)) {
                return false;
            }
        }
        return begin == end && *value == '\0';
    }

    static bool ParseConfigFloat(const char* begin, const char* end, float* outValue) {
        const char* p = SkipConfigSpaces(begin, end);
        bool neg = false;
        if (p < end && (*p == '-' || *p == '+')) {
            neg = (*p == '-');
            p++;
        }

        bool seenDigit = false;
        float value = 0.0f;
        while (p < end && ConfigIsDigit(*p)) {
            seenDigit = true;
            value = value * 10.0f + static_cast<float>(*p - '0');
            p++;
        }

        if (p < end && *p == '.') {
            p++;
            float scale = 0.1f;
            while (p < end && ConfigIsDigit(*p)) {
                seenDigit = true;
                value += static_cast<float>(*p - '0') * scale;
                scale *= 0.1f;
                p++;
            }
        }

        if (!seenDigit) {
            return false;
        }

        *outValue = neg ? -value : value;
        return true;
    }

    static bool ParseConfigBool(const char* begin, const char* end, bool* outValue) {
        const char* valueBegin = SkipConfigSpaces(begin, end);
        const char* valueEnd = ConfigValueTokenEnd(valueBegin, end);
        if (ConfigTokenEqualsNoCase(valueBegin, valueEnd, "true") ||
            ConfigTokenEqualsNoCase(valueBegin, valueEnd, "1") ||
            ConfigTokenEqualsNoCase(valueBegin, valueEnd, "yes") ||
            ConfigTokenEqualsNoCase(valueBegin, valueEnd, "on")) {
            *outValue = true;
            return true;
        }
        if (ConfigTokenEqualsNoCase(valueBegin, valueEnd, "false") ||
            ConfigTokenEqualsNoCase(valueBegin, valueEnd, "0") ||
            ConfigTokenEqualsNoCase(valueBegin, valueEnd, "no") ||
            ConfigTokenEqualsNoCase(valueBegin, valueEnd, "off")) {
            *outValue = false;
            return true;
        }
        return false;
    }

    static bool ParseConfigText(const char* text, size_t len, ParsedConfig* outConfig) {
        bool found = false;
        const char* p = text;
        const char* end = text + len;
        while (p < end) {
            const char* lineBegin = p;
            while (p < end && *p != '\n') {
                p++;
            }
            const char* lineEnd = p;
            if (p < end && *p == '\n') {
                p++;
            }

            const char* cur = SkipConfigSpaces(lineBegin, lineEnd);
            if (cur >= lineEnd || *cur == '#' || *cur == ';') {
                continue;
            }

            const char* eq = cur;
            while (eq < lineEnd && *eq != '=') {
                eq++;
            }
            if (eq >= lineEnd) {
                continue;
            }

            const char* keyEnd = TrimConfigSpacesEnd(cur, eq);
            const bool isZoomKey =
                ConfigKeyEquals(cur, keyEnd, kBaseZoomSettingId) ||
                ConfigKeyEquals(cur, keyEnd, "zoom");
            const bool isCoopEnabledKey =
                ConfigKeyEquals(cur, keyEnd, "coop.enabled") ||
                ConfigKeyEquals(cur, keyEnd, "coop.persist_enabled");
            if (!isZoomKey && !isCoopEnabledKey) {
                continue;
            }

            if (isZoomKey) {
                float parsed = 0.0f;
                if (ParseConfigFloat(eq + 1, lineEnd, &parsed)) {
                    outConfig->baseZoom = parsed;
                    outConfig->hasBaseZoom = true;
                    found = true;
                }
            } else if (isCoopEnabledKey) {
                bool parsed = false;
                if (ParseConfigBool(eq + 1, lineEnd, &parsed)) {
                    outConfig->coopEnabled = parsed;
                    outConfig->hasCoopEnabled = true;
                    found = true;
                }
            }
        }
        return found;
    }

    static void ApplyBaseZoom(float value) {
        sBaseZoomValue = ClampBaseZoom(value);
#if BFCOOP_EXLMOD_ENABLED
        exlmod::settings::SetFloat(BaseZoomSetting(), sBaseZoomValue);
#endif
    }

    static void ApplyCoopEnabled(bool enabled) {
        Patch0025::sConfigCoopLoaded = true;
        Patch0025::sConfigCoopEnabled = enabled;
        Patch0025::sCoopLatch = enabled;
    }

    [[maybe_unused]] static bool LoadContentConfig() {
        static bool sConfigResolved = false;
        if (sConfigResolved) {
            return true;
        }

        nn::fs::FileHandle handle {};
        Logging.Log("[BFCoop] CONFIG-0002 opening content settings at scene init path=%s", kConfigPath);
        Result result = nn::fs::OpenFile(&handle, kConfigPath, nn::fs::OpenMode_Read);
        if (result != 0) {
            sConfigResolved = true;
            Logging.Log("[BFCoop] CONFIG-0002 content settings open failed result=0x%08x; using defaults path=%s",
                        result, kConfigPath);
            return true;
        }

        long fileSize = 0;
        result = nn::fs::GetFileSize(&fileSize, handle);
        if (result != 0 || fileSize <= 0) {
            nn::fs::CloseFile(handle);
            sConfigResolved = true;
            Logging.Log("[BFCoop] CONFIG-0002 content settings unreadable result=0x%08x size=%ld; camera zoom default=%.2f coop.enabled=%d",
                        result, fileSize, sBaseZoomValue, Patch0025::sCoopLatch ? 1 : 0);
            return true;
        }

        char buffer[kConfigMaxBytes + 1] {};
        size_t readSize = static_cast<size_t>(fileSize);
        if (readSize > kConfigMaxBytes) {
            readSize = kConfigMaxBytes;
        }

        result = nn::fs::ReadFile(handle, 0, buffer, static_cast<ulong>(readSize));
        nn::fs::CloseFile(handle);
        if (result != 0) {
            sConfigResolved = true;
            Logging.Log("[BFCoop] CONFIG-0002 content settings read failed result=0x%08x; camera zoom default=%.2f coop.enabled=%d",
                        result, sBaseZoomValue, Patch0025::sCoopLatch ? 1 : 0);
            return true;
        }
        buffer[readSize] = '\0';

        ParsedConfig config {};
        if (ParseConfigText(buffer, readSize, &config)) {
            if (config.hasBaseZoom) {
                ApplyBaseZoom(config.baseZoom);
            }
            if (config.hasCoopEnabled) {
                ApplyCoopEnabled(config.coopEnabled);
            }
        }
        sConfigResolved = true;
        Logging.Log("[BFCoop] CONFIG-0002 content settings loaded camera.zoom.base=%.2f%s coop.enabled=%d%s path=%s",
                    sBaseZoomValue, config.hasBaseZoom ? "" : " default",
                    Patch0025::sCoopLatch ? 1 : 0,
                    config.hasCoopEnabled ? "" : " default",
                    kConfigPath);
        return true;
    }

    
    
    static uintptr_t PadPtr(int i) {
        uintptr_t slot = exl::util::modules::GetTargetOffset(ControllerMgrSlot);
        uintptr_t mgr = *reinterpret_cast<uintptr_t*>(slot);
        if (!CameraSanePtr(mgr)) return 0;
        uint32_t count = *reinterpret_cast<uint32_t*>(mgr + 0x188);
        if (count == 0 || count > 16 || static_cast<uint32_t>(i) >= count) return 0;
        uintptr_t arr = *reinterpret_cast<uintptr_t*>(mgr + 0x190);
        if (!CameraSanePtr(arr)) return 0;
        uintptr_t pad = *reinterpret_cast<uintptr_t*>(arr + i * 8);
        if (!CameraSanePtr(pad)) return 0;
        return pad;
    }

    
    
    
    
    static void UpdateZoomControl() {
        static uint32_t sPrevHold[4] = {};
        bool up = false, down = false;
        for (int i = 0; i < 4; i++) {
            uintptr_t pad = PadPtr(i);
            if (!pad) continue;
            uint32_t hold = *reinterpret_cast<uint32_t*>(pad + 0x114);
            uint32_t pressed = hold & ~sPrevHold[i];
            sPrevHold[i] = hold;
            if ((pressed >> kPadUpBit) & 1)   up = true;
            if ((pressed >> kPadDownBit) & 1) down = true;
#if RELEASE_DIAGNOSTIC_ENABLED
            
            
            
            
            static uint32_t sLastLogged[4] = {};
            static int sLines = 0;
            if (hold != sLastLogged[i] && sLines < 150) {
                sLines++;
                Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC pad[%d] hold=%08x trig=%08x",
                            i, hold, *reinterpret_cast<uint32_t*>(pad + 0x8));
                sLastLogged[i] = hold;
            }
#endif
        }
#if RELEASE_DIAGNOSTIC_ENABLED
        {
            static bool sOnce = false;
            if (!sOnce) {
                sOnce = true;
                uintptr_t slot = exl::util::modules::GetTargetOffset(ControllerMgrSlot);
                uintptr_t mgr = *reinterpret_cast<uintptr_t*>(slot);
                uint32_t count = CameraSanePtr(mgr) ? *reinterpret_cast<uint32_t*>(mgr + 0x188) : 0;
                Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC mgr=%p count=%u pad0=%p pad1=%p",
                            reinterpret_cast<void*>(mgr), count,
                            reinterpret_cast<void*>(PadPtr(0)),
                            reinterpret_cast<void*>(PadPtr(1)));
            }
        }
#endif
#if PATCH_0023_PAD_CONTROL
        if (up == down) return;
        float baseZoom = BaseZoom();
        float nz = ClampBaseZoom(baseZoom + (up ? kZoomStep : -kZoomStep));
        if (nz != baseZoom) {
            sBaseZoomValue = nz;
#if BFCOOP_EXLMOD_ENABLED
            exlmod::settings::SetFloat(BaseZoomSetting(), nz);
#endif
            Logging.Log("[BFCoop] PATCH-0023 zoom base=%.2f (dpad-%s)", nz, up ? "up" : "down");
        }
#else
        (void)up; (void)down;
#endif
    }

    
    
    
    static float TargetFactor() {
        uintptr_t scene = sCurrentScene;
        if (!CameraSanePtr(scene)) return 1.0f;
        int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
        if (count < 2 || count > 8) return 1.0f;
        uintptr_t array = *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
        if (!CameraSanePtr(array)) return 1.0f;
        uintptr_t mario = *reinterpret_cast<uintptr_t*>(array + 0x00);
        uintptr_t luigi = *reinterpret_cast<uintptr_t*>(array + 0x08);
        if (!CameraSanePtr(mario) || !CameraSanePtr(luigi) || mario == luigi) return 1.0f;

        int luigiDf = -1, marioDf = -1;
        for (int i = 0; i < sP16N; i++) {
            if (sP16[i].actor == luigi)      luigiDf = sP16[i].deadFrames;
            else if (sP16[i].actor == mario) marioDf = sP16[i].deadFrames;
        }
        if (P21IsOut(mario, marioDf) || P21IsOut(luigi, luigiDf)) return 1.0f;

        
        
        
        
        if (Patch0025::AssistMode() != 2) return 1.0f;

        float baseZoom = BaseZoom();
        float target = baseZoom;
#if PATCH_0023_DYNAMIC
        float dx = ReadF(mario, CameraMidpointOffsets::PlayerPosX) - ReadF(luigi, CameraMidpointOffsets::PlayerPosX);
        float dy = ReadF(mario, CameraMidpointOffsets::PlayerPosY) - ReadF(luigi, CameraMidpointOffsets::PlayerPosY);
        float dz = ReadF(mario, CameraMidpointOffsets::PlayerPosZ) - ReadF(luigi, CameraMidpointOffsets::PlayerPosZ);
        if (CameraSaneFloat(dx) && CameraSaneFloat(dy) && CameraSaneFloat(dz)) {
            float sepSq = dx * dx + dy * dy + dz * dz;
            float t = (sepSq - kSepStart * kSepStart) /
                      (kSepFull * kSepFull - kSepStart * kSepStart);
            if (t < 0.0f) t = 0.0f; else if (t > 1.0f) t = 1.0f;
            float hi = (kMaxZoom > baseZoom) ? kMaxZoom : baseZoom;
            target = baseZoom + t * (hi - baseZoom);
        }
#endif
        return target;
    }

    [[maybe_unused]] static float Factor() {
        if (sLastFrame != sP16GlobalFrame) {  
            sLastFrame = sP16GlobalFrame;
            UpdateZoomControl();
            sZoom += (TargetFactor() - sZoom) * kLerp;
        }
        return sZoom;
    }
}

HOOK_DEFINE_TRAMPOLINE(CamZoomDistanceRaw) {
    static float Callback(void* poser) {
        float d = Orig(poser);
#if PATCH_0023_ENABLED
        if (!CameraSaneFloat(d) || d <= 0.0f) return d;
        float f = Patch0023::Factor();
        static bool sLogged = false;
        if (!sLogged && f > 1.05f) {
            sLogged = true;
            Logging.Log("[BFCoop] PATCH-0023 zoom live: calcDistanceRaw d=%.0f -> %.0f (f=%.2f)",
                        d, d * f, f);
        }
        d *= f;
#endif
        return d;
    }
};

                                                                         
  
                                                                           
                                                                              
                                                                               
                                                                             
                                                                                
                                                                           
  
                                                                               
                                                                           
                                                                              
                                                                              
                                                                              
            
  
                                                           
                                                                         
                                                                    
                                                                            
                                                                            
                                          
  
                                                                            
                                                                         
                                                                              
                                                                             
                                                                           
                                  
   
namespace Patch0026 {
    constexpr ptrdiff_t GetFovyDegree = 0x009226B0;
    constexpr float kPlayerCenterY = 90.0f;
    constexpr float kPlayerRadius = 110.0f;
    constexpr float kHalfDegToRad = 3.14159265358979323846f / 360.0f;
    constexpr float kAspect = 1280.0f / 720.0f;

    [[maybe_unused]] static void Apply(uintptr_t poser, uintptr_t eyePtr,
                                       uintptr_t atPtr, uintptr_t upPtr) {
        uintptr_t scene = sCurrentScene;
        if (!CameraSanePtr(poser) || !CameraSaneFloatPtr(eyePtr) ||
            !CameraSaneFloatPtr(atPtr) || !CameraSaneFloatPtr(upPtr) ||
            !CameraSanePtr(scene)) {
            return;
        }
        static bool sLiveLogged = false;
        if (!sLiveLogged) {
            sLiveLogged = true;
            Logging.Log("[BFCoop] PATCH-0026 live at FollowLimit final commit");
        }
        if (Patch0025::AssistMode() != 2) return;

        int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
        if (count < 2 || count > 8) return;
        uintptr_t array = *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
        if (!CameraSanePtr(array)) return;
        uintptr_t mario = *reinterpret_cast<uintptr_t*>(array + 0x00);
        uintptr_t luigi = *reinterpret_cast<uintptr_t*>(array + 0x08);
        if (!CameraSanePtr(mario) || !CameraSanePtr(luigi) || mario == luigi) return;

        int marioDf = -1;
        int luigiDf = -1;
        for (int i = 0; i < sP16N; ++i) {
            if (sP16[i].actor == mario) marioDf = sP16[i].deadFrames;
            else if (sP16[i].actor == luigi) luigiDf = sP16[i].deadFrames;
        }
        if (P21IsOut(mario, marioDf) || P21IsOut(luigi, luigiDf)) return;

        float centers[2][3] = {
            {
                ReadF(mario, CameraMidpointOffsets::PlayerPosX),
                ReadF(mario, CameraMidpointOffsets::PlayerPosY) + Patch0026::kPlayerCenterY,
                ReadF(mario, CameraMidpointOffsets::PlayerPosZ)
            },
            {
                ReadF(luigi, CameraMidpointOffsets::PlayerPosX),
                ReadF(luigi, CameraMidpointOffsets::PlayerPosY) + Patch0026::kPlayerCenterY,
                ReadF(luigi, CameraMidpointOffsets::PlayerPosZ)
            }
        };
        for (int i = 0; i < 2; ++i) {
            if (!CameraSaneFloat(centers[i][0]) ||
                !CameraSaneFloat(centers[i][1]) ||
                !CameraSaneFloat(centers[i][2])) {
                return;
            }
        }

        
        
        constexpr float kVoidY = -400.0f;
        constexpr float kVoidGap = 600.0f;
        const float marioY = centers[0][1] - Patch0026::kPlayerCenterY;
        const float luigiY = centers[1][1] - Patch0026::kPlayerCenterY;
        const bool marioVoid = marioY < kVoidY && luigiY - marioY > kVoidGap;
        const bool luigiVoid = luigiY < kVoidY && marioY - luigiY > kVoidGap;
        if (marioVoid != luigiVoid) return;

        float* eye = reinterpret_cast<float*>(eyePtr);
        const float* at = reinterpret_cast<const float*>(atPtr);
        const float* up = reinterpret_cast<const float*>(upPtr);
        for (int i = 0; i < 3; ++i) {
            if (!CameraSaneFloat(eye[i]) || !CameraSaneFloat(at[i]) ||
                !CameraSaneFloat(up[i])) {
                return;
            }
        }

        float forward[3] = {
            at[0] - eye[0],
            at[1] - eye[1],
            at[2] - eye[2]
        };
        const float nativeDistance = __builtin_sqrtf(
            forward[0] * forward[0] +
            forward[1] * forward[1] +
            forward[2] * forward[2]);
        const float upLength = __builtin_sqrtf(
            up[0] * up[0] + up[1] * up[1] + up[2] * up[2]);
        if (!(nativeDistance > 1.0f && nativeDistance < 1000000.0f &&
              upLength > 0.1f && upLength < 10.0f)) {
            return;
        }
        forward[0] /= nativeDistance;
        forward[1] /= nativeDistance;
        forward[2] /= nativeDistance;

        float right[3] = {
            forward[1] * up[2] - forward[2] * up[1],
            forward[2] * up[0] - forward[0] * up[2],
            forward[0] * up[1] - forward[1] * up[0]
        };
        const float rightLength = __builtin_sqrtf(
            right[0] * right[0] +
            right[1] * right[1] +
            right[2] * right[2]);
        if (!(rightLength > 0.1f && rightLength < 10.0f)) return;
        right[0] /= rightLength;
        right[1] /= rightLength;
        right[2] /= rightLength;

        const float cameraUp[3] = {
            right[1] * forward[2] - right[2] * forward[1],
            right[2] * forward[0] - right[0] * forward[2],
            right[0] * forward[1] - right[1] * forward[0]
        };

        const uintptr_t fovyAddr =
            exl::util::modules::GetTargetOffset(Patch0026::GetFovyDegree);
        const float fovyDegree =
            reinterpret_cast<float (*)(const void*)>(fovyAddr)(
                reinterpret_cast<const void*>(poser));
        if (!(CameraSaneFloat(fovyDegree) &&
              fovyDegree > 1.0f && fovyDegree < 170.0f)) {
            return;
        }
        const float tanY =
            __builtin_tanf(fovyDegree * Patch0026::kHalfDegToRad);
        const float tanX = tanY * Patch0026::kAspect;
        if (!(tanY > 0.01f && tanX > 0.01f)) return;

        float requiredDistance = nativeDistance;
        for (int i = 0; i < 2; ++i) {
            const float relAt[3] = {
                centers[i][0] - at[0],
                centers[i][1] - at[1],
                centers[i][2] - at[2]
            };
            const float x =
                relAt[0] * right[0] +
                relAt[1] * right[1] +
                relAt[2] * right[2];
            const float y =
                relAt[0] * cameraUp[0] +
                relAt[1] * cameraUp[1] +
                relAt[2] * cameraUp[2];
            const float forwardAt =
                relAt[0] * forward[0] +
                relAt[1] * forward[1] +
                relAt[2] * forward[2];
            const float absX = x < 0.0f ? -x : x;
            const float absY = y < 0.0f ? -y : y;
            const float needX =
                (absX + Patch0026::kPlayerRadius) / tanX - forwardAt;
            const float needY =
                (absY + Patch0026::kPlayerRadius) / tanY - forwardAt;
            const float needNear =
                Patch0026::kPlayerRadius + 1.0f - forwardAt;
            if (needX > requiredDistance) requiredDistance = needX;
            if (needY > requiredDistance) requiredDistance = needY;
            if (needNear > requiredDistance) requiredDistance = needNear;
        }

        static bool sActive = false;
        const bool active = requiredDistance > nativeDistance + 1.0f;
        if (active) {
            eye[0] = at[0] - forward[0] * requiredDistance;
            eye[1] = at[1] - forward[1] * requiredDistance;
            eye[2] = at[2] - forward[2] * requiredDistance;
        }
        if (active != sActive) {
            sActive = active;
            Logging.Log("[BFCoop] PATCH-0026 exact-fit %s native=%.0f required=%.0f fovy=%.1f",
                        active ? "ON" : "OFF",
                        nativeDistance, requiredDistance, fovyDegree);
        }
    }
}

                                                                         
  
                                                                       
                                                                             
                                                                    
                                                                      
  
                                                                             
                                                                               
                                                                             
                                                                              
                                      
   
namespace Patch0027 {
    constexpr float kBaseZoom = 1.12f;
    constexpr float kMaxZoom = 1.65f;
    constexpr float kSeparationStart = 500.0f;
    constexpr float kSeparationFull = 2500.0f;
    constexpr float kLerp = 0.05f;
    constexpr unsigned kFreshPoseCalls = 180;

    static float sTargetFactor = 1.0f;
    static float sAppliedFactor = 1.0f;
    static float sSeparation = -1.0f;
    static unsigned sFreshPoseCalls = 0;

    static bool ObservePlayers() {
        uintptr_t scene = sCurrentScene;
        if (!CameraSanePtr(scene) || Patch0025::AssistMode() != 2) return false;
        int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
        if (count < 2 || count > 8) return false;
        uintptr_t array =
            *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
        if (!CameraSanePtr(array)) return false;
        uintptr_t mario = *reinterpret_cast<uintptr_t*>(array + 0x00);
        uintptr_t luigi = *reinterpret_cast<uintptr_t*>(array + 0x08);
        if (!CameraSanePtr(mario) || !CameraSanePtr(luigi) || mario == luigi) return false;

        int marioDf = -1;
        int luigiDf = -1;
        for (int i = 0; i < sP16N; ++i) {
            if (sP16[i].actor == mario) marioDf = sP16[i].deadFrames;
            else if (sP16[i].actor == luigi) luigiDf = sP16[i].deadFrames;
        }
        if (P21IsOut(mario, marioDf) || P21IsOut(luigi, luigiDf)) return false;

        const float mx = ReadF(mario, CameraMidpointOffsets::PlayerPosX);
        const float mz = ReadF(mario, CameraMidpointOffsets::PlayerPosZ);
        const float lx = ReadF(luigi, CameraMidpointOffsets::PlayerPosX);
        const float lz = ReadF(luigi, CameraMidpointOffsets::PlayerPosZ);
        if (!CameraSaneFloat(mx) || !CameraSaneFloat(mz) ||
            !CameraSaneFloat(lx) || !CameraSaneFloat(lz)) {
            return false;
        }

        const float dx = mx - lx;
        const float dz = mz - lz;
        const float separation = __builtin_sqrtf(dx * dx + dz * dz);
        if (!(separation >= 0.0f) || separation > 100000.0f) return false;

        float t = (separation - kSeparationStart) /
                  (kSeparationFull - kSeparationStart);
        if (t < 0.0f) t = 0.0f;
        else if (t > 1.0f) t = 1.0f;

        sSeparation = separation;
        sTargetFactor = kBaseZoom + t * (kMaxZoom - kBaseZoom);
        sFreshPoseCalls = kFreshPoseCalls;
        return true;
    }

    static void Apply(uintptr_t poser, uintptr_t eyePtr, uintptr_t atPtr) {
        if (!CameraSanePtr(poser) || !CameraSaneFloatPtr(eyePtr) ||
            !CameraSaneFloatPtr(atPtr)) {
            return;
        }

        const bool observed = ObservePlayers();
        if (!observed) {
            if (sFreshPoseCalls > 0) {
                --sFreshPoseCalls;
            } else {
                sTargetFactor = 1.0f;
                sSeparation = -1.0f;
            }
        }

        sAppliedFactor += (sTargetFactor - sAppliedFactor) * kLerp;
        if (sAppliedFactor < 1.0f) sAppliedFactor = 1.0f;
        else if (sAppliedFactor > kMaxZoom) sAppliedFactor = kMaxZoom;

        float* eye = reinterpret_cast<float*>(eyePtr);
        const float* at = reinterpret_cast<const float*>(atPtr);
        const float dx = eye[0] - at[0];
        const float dy = eye[1] - at[1];
        const float dz = eye[2] - at[2];
        const float before = __builtin_sqrtf(dx * dx + dy * dy + dz * dz);
        if (!(before > 0.0f) || before > 1000000.0f) return;

        eye[0] = at[0] + dx * sAppliedFactor;
        eye[1] = at[1] + dy * sAppliedFactor;
        eye[2] = at[2] + dz * sAppliedFactor;

        static unsigned sCalls = 0;
        static unsigned sLogged = 0;
        if ((sCalls++ % 120) == 0 && sLogged < 80) {
            ++sLogged;
            Logging.Log("[BFCoop] PATCH-0027 zoom final poser=%p sep=%.0f target=%.2f applied=%.2f d=%.0f->%.0f fresh=%u",
                        reinterpret_cast<void*>(poser), sSeparation,
                        sTargetFactor, sAppliedFactor,
                        before, before * sAppliedFactor, sFreshPoseCalls);
        }
    }
}

                                                                        
  
                                                                       
                                                                       
                                                                              
                                                                               
                                                            
  
                                 
                                                                        
                                                                         
                                                                    
                                                                         
                                                                      
                                                                            
                                                     
                                                                    
  
                                                                              
                                                                             
                                                                        
                                                                               
   
namespace Patch0028 {
    constexpr ptrdiff_t GetFovyDegree = 0x009226B0;
    constexpr ptrdiff_t CalcModelBoundingBox = 0x0083B8E0;
    constexpr ptrdiff_t MultVecPose = 0x0083FF10;
    constexpr float kHalfDegToRad = 3.14159265358979323846f / 360.0f;
    constexpr float kAspect = 1280.0f / 720.0f;
    constexpr unsigned kFreshPoseCalls = 2;
    
    
    
    
    constexpr float kBubbleHandoffDistance = 3000.0f;
    constexpr float kBubbleHandoffResetDistance = 2700.0f;

    static bool sValid = false;
    static float sCenter[2][3] = {};
    static float sRadius[2] = {};
    static unsigned sFreshPoseCalls = 0;
    static bool sBubbleHandoff = false;

    static void Invalidate() {
        sValid = false;
        sFreshPoseCalls = 0;
    }

    
    
    
    
    static bool ObservePlayers() {
        uintptr_t scene = sCurrentScene;
        if (!CameraSanePtr(scene) || Patch0025::AssistMode() != 2)
            return false;
        int count =
            *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
        if (count < 2 || count > 8)
            return false;
        uintptr_t array =
            *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
        if (!CameraSanePtr(array)) {
            Invalidate();
            return false;
        }
        uintptr_t players[2] = {
            *reinterpret_cast<uintptr_t*>(array + 0x00),
            *reinterpret_cast<uintptr_t*>(array + 0x08)
        };
        if (!CameraSanePtr(players[0]) || !CameraSanePtr(players[1]) ||
            players[0] == players[1]) {
            Invalidate();
            return false;
        }

        int deadFrames[2] = {-1, -1};
        for (int i = 0; i < sP16N; ++i) {
            if (sP16[i].actor == players[0]) deadFrames[0] = sP16[i].deadFrames;
            else if (sP16[i].actor == players[1]) deadFrames[1] = sP16[i].deadFrames;
        }
        if (P21IsOut(players[0], deadFrames[0]) ||
            P21IsOut(players[1], deadFrames[1])) {
            return false;
        }

        auto calcModelBoundingBox =
            reinterpret_cast<void (*)(float*, const void*)>(
                exl::util::modules::GetTargetOffset(CalcModelBoundingBox));
        auto multVecPose =
            reinterpret_cast<void (*)(float*, const void*, const float*)>(
                exl::util::modules::GetTargetOffset(MultVecPose));

        for (int i = 0; i < 2; ++i) {
            float box[6] = {};
            calcModelBoundingBox(box, reinterpret_cast<const void*>(players[i]));
            bool boxValid = true;
            for (int axis = 0; axis < 3; ++axis) {
                if (!CameraSaneFloat(box[axis]) ||
                    !CameraSaneFloat(box[axis + 3]) ||
                    box[axis] > box[axis + 3] ||
                    box[axis + 3] - box[axis] > 100000.0f) {
                    boxValid = false;
                    break;
                }
            }
            if (!boxValid) {
#if RELEASE_DIAGNOSTIC_PATCH0028_MODEL_BOUNDS_ENABLED
                static unsigned rejectLines = 0;
                if (rejectLines < 12) {
                    ++rejectLines;
                    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC model-box reject idx=%d actor=%p box=(%.2f,%.2f,%.2f)-(%.2f,%.2f,%.2f)",
                                i, reinterpret_cast<void*>(players[i]),
                                box[0], box[1], box[2],
                                box[3], box[4], box[5]);
                }
#endif
                Invalidate();
                return false;
            }

            const float localCenter[3] = {
                (box[0] + box[3]) * 0.5f,
                (box[1] + box[4]) * 0.5f,
                (box[2] + box[5]) * 0.5f
            };
            const float half[3] = {
                (box[3] - box[0]) * 0.5f,
                (box[4] - box[1]) * 0.5f,
                (box[5] - box[2]) * 0.5f
            };
            float worldCenter[3] = {};
            float worldAxis[3][3] = {};
            multVecPose(worldCenter, reinterpret_cast<const void*>(players[i]),
                        localCenter);
            for (int axis = 0; axis < 3; ++axis) {
                float endpoint[3] = {
                    localCenter[0], localCenter[1], localCenter[2]
                };
                endpoint[axis] += half[axis];
                float worldEndpoint[3] = {};
                multVecPose(worldEndpoint,
                            reinterpret_cast<const void*>(players[i]), endpoint);
                for (int component = 0; component < 3; ++component) {
                    worldAxis[axis][component] =
                        worldEndpoint[component] - worldCenter[component];
                }
            }

            float radiusSquared = 0.0f;
            for (int corner = 0; corner < 8; ++corner) {
                float delta[3] = {};
                for (int axis = 0; axis < 3; ++axis) {
                    const float sign = (corner & (1 << axis)) ? 1.0f : -1.0f;
                    for (int component = 0; component < 3; ++component)
                        delta[component] += sign * worldAxis[axis][component];
                }
                const float cornerRadiusSquared =
                    delta[0] * delta[0] +
                    delta[1] * delta[1] +
                    delta[2] * delta[2];
                if (cornerRadiusSquared > radiusSquared)
                    radiusSquared = cornerRadiusSquared;
            }
            const float radius = __builtin_sqrtf(radiusSquared);
            if (!CameraSaneFloat(worldCenter[0]) ||
                !CameraSaneFloat(worldCenter[1]) ||
                !CameraSaneFloat(worldCenter[2]) ||
                !CameraSaneFloat(radius) ||
                !(radius > 0.01f && radius < 100000.0f)) {
#if RELEASE_DIAGNOSTIC_PATCH0028_MODEL_BOUNDS_ENABLED
                static unsigned transformRejectLines = 0;
                if (transformRejectLines < 12) {
                    ++transformRejectLines;
                    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC model-transform reject idx=%d actor=%p center=(%.2f,%.2f,%.2f) radius=%.2f",
                                i, reinterpret_cast<void*>(players[i]),
                                worldCenter[0], worldCenter[1], worldCenter[2],
                                radius);
                }
#endif
                Invalidate();
                return false;
            }
            for (int axis = 0; axis < 3; ++axis)
                sCenter[i][axis] = worldCenter[axis];
            sRadius[i] = radius;
        }

        const float separationX = sCenter[1][0] - sCenter[0][0];
        const float separationY = sCenter[1][1] - sCenter[0][1];
        const float separationZ = sCenter[1][2] - sCenter[0][2];
        const float separation = __builtin_sqrtf(
            separationX * separationX +
            separationY * separationY +
            separationZ * separationZ);
        if (!CameraSaneFloat(separation)) {
            Invalidate();
            return false;
        }
        if (!sBubbleHandoff && separation >= kBubbleHandoffDistance) {
            sBubbleHandoff = true;
            Logging.Log("[BFCoop] PATCH-0028 bubble handoff ON separation=%.1f threshold=%.1f",
                        separation, kBubbleHandoffDistance);
        } else if (sBubbleHandoff &&
                   separation <= kBubbleHandoffResetDistance) {
            sBubbleHandoff = false;
            Logging.Log("[BFCoop] PATCH-0028 bubble handoff OFF separation=%.1f reset=%.1f",
                        separation, kBubbleHandoffResetDistance);
        }
        if (sBubbleHandoff) {
            Invalidate();
            return false;
        }

#if RELEASE_DIAGNOSTIC_PATCH0028_MODEL_BOUNDS_ENABLED
        static bool acceptedLogged = false;
        if (!acceptedLogged) {
            acceptedLogged = true;
            Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC model bounds accepted c0=(%.1f,%.1f,%.1f) r0=%.1f c1=(%.1f,%.1f,%.1f) r1=%.1f",
                        sCenter[0][0], sCenter[0][1], sCenter[0][2], sRadius[0],
                        sCenter[1][0], sCenter[1][1], sCenter[1][2], sRadius[1]);
        }
#endif
        sValid = true;
        sFreshPoseCalls = kFreshPoseCalls;
        return true;
    }

    static void FitFinalPose(uintptr_t poser, float* eye, const float* at,
                             const float* up, const float* nativeEye) {
        if (!sValid || sFreshPoseCalls == 0)
            return;
        --sFreshPoseCalls;

        float forward[3] = {
            at[0] - eye[0],
            at[1] - eye[1],
            at[2] - eye[2]
        };
        const float distance = __builtin_sqrtf(
            forward[0] * forward[0] +
            forward[1] * forward[1] +
            forward[2] * forward[2]);
        const float upLength = __builtin_sqrtf(
            up[0] * up[0] + up[1] * up[1] + up[2] * up[2]);
        if (!(distance > 1.0f && distance < 1000000.0f &&
              upLength > 0.1f && upLength < 10.0f))
            return;

        forward[0] /= distance;
        forward[1] /= distance;
        forward[2] /= distance;
        float right[3] = {
            forward[1] * up[2] - forward[2] * up[1],
            forward[2] * up[0] - forward[0] * up[2],
            forward[0] * up[1] - forward[1] * up[0]
        };
        const float rightLength = __builtin_sqrtf(
            right[0] * right[0] +
            right[1] * right[1] +
            right[2] * right[2]);
        if (!(rightLength > 0.1f))
            return;
        right[0] /= rightLength;
        right[1] /= rightLength;
        right[2] /= rightLength;
        const float cameraUp[3] = {
            right[1] * forward[2] - right[2] * forward[1],
            right[2] * forward[0] - right[0] * forward[2],
            right[0] * forward[1] - right[1] * forward[0]
        };

        const uintptr_t fovyFnAddr =
            exl::util::modules::GetTargetOffset(GetFovyDegree);
        const float fovyDegree =
            reinterpret_cast<float (*)(const void*)>(fovyFnAddr)(
                reinterpret_cast<const void*>(poser));
        const float tanY = __builtin_tanf(fovyDegree * kHalfDegToRad);
        const float tanX = tanY * kAspect;
        if (!(CameraSaneFloat(fovyDegree) &&
              fovyDegree > 1.0f && fovyDegree < 170.0f &&
              tanY > 0.01f && tanX > 0.01f))
            return;

        float signedDepth[2] = {};
        float requiredDistance = 0.0f;
        for (int i = 0; i < 2; ++i) {
            const float relEye[3] = {
                sCenter[i][0] - eye[0],
                sCenter[i][1] - eye[1],
                sCenter[i][2] - eye[2]
            };
            const float relAt[3] = {
                sCenter[i][0] - at[0],
                sCenter[i][1] - at[1],
                sCenter[i][2] - at[2]
            };
            signedDepth[i] =
                relEye[0] * forward[0] +
                relEye[1] * forward[1] +
                relEye[2] * forward[2];
            const float x =
                relEye[0] * right[0] +
                relEye[1] * right[1] +
                relEye[2] * right[2];
            const float y =
                relEye[0] * cameraUp[0] +
                relEye[1] * cameraUp[1] +
                relEye[2] * cameraUp[2];
            const float absX = x < 0.0f ? -x : x;
            const float absY = y < 0.0f ? -y : y;
            const float forwardAt =
                relAt[0] * forward[0] +
                relAt[1] * forward[1] +
                relAt[2] * forward[2];
            const float needX = (absX + sRadius[i]) / tanX - forwardAt;
            const float needY = (absY + sRadius[i]) / tanY - forwardAt;
            const float needNear = sRadius[i] + 1.0f - forwardAt;
            if (needX > requiredDistance) requiredDistance = needX;
            if (needY > requiredDistance) requiredDistance = needY;
            if (needNear > requiredDistance) requiredDistance = needNear;
        }

        const float nativeDx = nativeEye[0] - at[0];
        const float nativeDy = nativeEye[1] - at[1];
        const float nativeDz = nativeEye[2] - at[2];
        const float nativeDistance = __builtin_sqrtf(
            nativeDx * nativeDx + nativeDy * nativeDy + nativeDz * nativeDz);
        if (!(nativeDistance > 1.0f && nativeDistance < 1000000.0f &&
              requiredDistance >= 0.0f && requiredDistance < 100000.0f))
            return;

        const float baseDistance = nativeDistance * Patch0023::BaseZoom();
        const float fitDistance =
            requiredDistance > baseDistance ? requiredDistance : baseDistance;
        eye[0] = at[0] - forward[0] * fitDistance;
        eye[1] = at[1] - forward[1] * fitDistance;
        eye[2] = at[2] - forward[2] * fitDistance;

        static unsigned calls = 0;
        static unsigned logged = 0;
        if ((calls++ % 60) == 0 && logged < 60) {
            ++logged;
            Logging.Log("[BFCoop] PATCH-0028 exact fit native=%.1f required=%.1f final=%.1f depth=%.1f/%.1f radius=%.1f/%.1f",
                        nativeDistance, requiredDistance, fitDistance,
                        signedDepth[0], signedDepth[1],
                        sRadius[0], sRadius[1]);
        }
    }

    static void Apply(uintptr_t poser, uintptr_t eyePtr,
                      uintptr_t atPtr, uintptr_t upPtr) {
        if (!CameraSanePtr(poser) || !CameraSaneFloatPtr(eyePtr) ||
            !CameraSaneFloatPtr(atPtr) || !CameraSaneFloatPtr(upPtr))
            return;
        float* eye = reinterpret_cast<float*>(eyePtr);
        const float* at = reinterpret_cast<const float*>(atPtr);
        const float* up = reinterpret_cast<const float*>(upPtr);
        for (int i = 0; i < 3; ++i) {
            if (!CameraSaneFloat(eye[i]) || !CameraSaneFloat(at[i]) ||
                !CameraSaneFloat(up[i]))
                return;
        }

        const float nativeEye[3] = {eye[0], eye[1], eye[2]};
        (void)ObservePlayers();
#if PATCH_0027_ENABLED
        Patch0027::Apply(poser, eyePtr, atPtr);
#endif
        FitFinalPose(poser, eye, at, up, nativeEye);
    }
}

#if BFCOOP_EXLMOD_ENABLED && RELEASE_DIAGNOSTIC_RENDER_HOOK_ENABLED
namespace Diag0033 {
    constexpr ptrdiff_t DisplayListEnd = 0x0075D330;
    constexpr ptrdiff_t CmdBufOffset = 0x250;

    static int sLogLines = 0;
}

#if RELEASE_DIAGNOSTIC_SETTINGS_IMGUI_ENABLED
namespace Diag0035 {
    constexpr size_t kImGuiArenaSize = 512 * 1024;
    alignas(16) static unsigned char sImGuiArenaMemory[kImGuiArenaSize] = {};
    static exlmod::arena_allocator::FixedArena sImGuiArena;
    static int sAllocatorLogLines = 0;
    static bool sArenaLogged = false;

    static void InitImGuiArena() {
        if (!sImGuiArena.Init(sImGuiArenaMemory, sizeof(sImGuiArenaMemory))) {
            if (!sArenaLogged) {
                sArenaLogged = true;
                Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC imgui arena init failed size=%llu",
                            static_cast<unsigned long long>(sizeof(sImGuiArenaMemory)));
            }
            return;
        }

        if (!sArenaLogged) {
            sArenaLogged = true;
            const exlmod::arena_allocator::Stats stats = sImGuiArena.GetStats();
            Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC imgui arena ready capacity=%llu",
                        static_cast<unsigned long long>(stats.capacity));
        }
    }

    static void* ImGuiAlloc(size_t size, void* userData) {
        auto* arena = static_cast<exlmod::arena_allocator::FixedArena*>(userData);
        if (!arena || !arena->IsReady()) return nullptr;
        void* ptr = arena->Alloc(size);
        if (!ptr && sAllocatorLogLines < 4) {
            ++sAllocatorLogLines;
            const exlmod::arena_allocator::Stats stats = arena->GetStats();
            Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC alloc failed size=%llu used=%llu peak=%llu largestFree=%llu fails=%u",
                        static_cast<unsigned long long>(size),
                        static_cast<unsigned long long>(stats.used),
                        static_cast<unsigned long long>(stats.peakUsed),
                        static_cast<unsigned long long>(stats.largestFree),
                        stats.failCount);
        }
        return ptr;
    }

    static void ImGuiFree(void* ptr, void* userData) {
        auto* arena = static_cast<exlmod::arena_allocator::FixedArena*>(userData);
        if (arena) {
            arena->Free(ptr);
        }
    }

    static void FillBackendState(exlmod::settings_imgui::BackendState* out) {
        if (!out) return;

        const exlmod::nvn::BootstrapState& state = exlmod::nvn::GetState();
        out->cropWidth = state.cropWidth;
        out->cropHeight = state.cropHeight;
        out->displayWidth = state.cropWidth > 0 ? static_cast<float>(state.cropWidth) : 1920.0f;
        out->displayHeight = state.cropHeight > 0 ? static_cast<float>(state.cropHeight) : 1080.0f;
        out->rendererReady = exlmod::nvn::IsReady();
        out->rendererDevice = state.device;
        out->rendererGetProcAddress = state.deviceGetProcAddress;
        out->texturePool = state.lastTexturePool;
        out->samplerPool = state.lastSamplerPool;
    }

    static void FillInputState(exlmod::settings_imgui::InputState* out) {
        if (!out) return;

        static uint32_t sPrevHold[4] = {};
        for (int i = 0; i < 4; ++i) {
            uintptr_t pad = Patch0023::PadPtr(i);
            if (!pad) continue;

            uint32_t hold = *reinterpret_cast<uint32_t*>(pad + 0x114);
            uint32_t pressed = hold & ~sPrevHold[i];
            sPrevHold[i] = hold;

            out->gamepadEnabled = true;
            out->toggleMenuPressed = out->toggleMenuPressed || ((pressed >> 3) & 1); 
            out->closeMenuPressed = out->closeMenuPressed || ((pressed >> 1) & 1);  
            out->gamepadActivateDown = out->gamepadActivateDown || ((hold >> 0) & 1);
            out->gamepadCancelDown = out->gamepadCancelDown || ((hold >> 1) & 1);
            out->gamepadMenuDown = out->gamepadMenuDown || ((hold >> 3) & 1);
            out->gamepadDpadUpDown = out->gamepadDpadUpDown ||
                                     ((hold >> Patch0023::kPadUpBit) & 1);
            out->gamepadDpadDownDown = out->gamepadDpadDownDown ||
                                       ((hold >> Patch0023::kPadDownBit) & 1);
            out->gamepadDpadLeftDown = out->gamepadDpadLeftDown ||
                                       ((hold >> Patch0023::kPadLeftBit) & 1);
            out->gamepadDpadRightDown = out->gamepadDpadRightDown ||
                                        ((hold >> Patch0023::kPadRightBit) & 1);
        }
    }
}
#endif  

HOOK_DEFINE_TRAMPOLINE(Diag0033DisplayListEnd) {
    static uint32_t Callback(void* displayList) {
        void* cmdBuf = nullptr;
        uintptr_t dl = reinterpret_cast<uintptr_t>(displayList);

        if (CameraSanePtr(dl)) {
            uintptr_t rawCmdBuf = *reinterpret_cast<uintptr_t*>(dl + Diag0033::CmdBufOffset);
            if (CameraSanePtr(rawCmdBuf)) {
                cmdBuf = reinterpret_cast<void*>(rawCmdBuf);
            }

            exlmod::render::RenderContext context{displayList, cmdBuf};
            exlmod::render::Dispatch(context);

            if (Diag0033::sLogLines < 16) {
                ++Diag0033::sLogLines;
                Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC displayList=%p cmdBuf=%p dispatch=%u callbacks=%d",
                            displayList, cmdBuf,
                            exlmod::render::GetDispatchCount(),
                            exlmod::render::GetDrawCallbackCount());
            }
        } else if (Diag0033::sLogLines < 16) {
            ++Diag0033::sLogLines;
            Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC invalid displayList=%p", displayList);
        }

        return Orig(displayList);
    }
};
#endif

                                                                            
                                                                
                                                                         
                                                
  
                                                                 
                                                                        
                                                                          
                                                                      
                                                                
                                                                          
                                                                        
                                                                           
                                                                
                                                                            
                                                                   
                                                                            
                                      
                                                                           
                                                                         
                                                                         
                                                                      
                                                              
  
                                                           
                                                                          
                                                                            
                                                                       
                                                                        
                                                                      
                                                                       
                                                                        
                                                                          
                                                                      
  
                                                                            
                                                                         
                                                                             
                                                       
#define PATCH_0024_ENABLED 1

namespace Patch0024 {
    constexpr ptrdiff_t GroupTargetCalc = 0x00071BB0; 
    constexpr ptrdiff_t TrackedActor    = 0x10;       
    constexpr ptrdiff_t YClampFlag      = 0x0B;       
}

HOOK_DEFINE_TRAMPOLINE(CoopCamTargetMidpoint) {
    static void Callback(void* subject, float* out) {
        Orig(subject, out);
#if PATCH_0024_ENABLED
        uintptr_t self = reinterpret_cast<uintptr_t>(subject);
        if (!CameraSanePtr(self)) return;
        if (*reinterpret_cast<unsigned char*>(self + Patch0024::YClampFlag)) return; 

        uintptr_t tracked = *reinterpret_cast<uintptr_t*>(self + Patch0024::TrackedActor);
        uintptr_t scene = sCurrentScene;
        if (!CameraSanePtr(scene) || !CameraSanePtr(tracked)) return;
        int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
        if (count < 2 || count > 8) return;
        uintptr_t array = *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
        if (!CameraSanePtr(array)) return;
        uintptr_t mario = *reinterpret_cast<uintptr_t*>(array + 0x00);
        uintptr_t luigi = *reinterpret_cast<uintptr_t*>(array + 0x08);
        if (!CameraSanePtr(mario) || !CameraSanePtr(luigi) || mario == luigi) return;
        if (tracked != mario && tracked != luigi) return;   

        
        
        {
            static uintptr_t sLastTracked = 0;
            static int sFlipLogs = 0;
            if (tracked != sLastTracked && sFlipLogs < 20) {
                sFlipLogs++;
                sLastTracked = tracked;
                Logging.Log("[BFCoop] PATCH-0024 tracked=%s frame=%u",
                            tracked == mario ? "MARIO" : "LUIGI", sP16GlobalFrame);
            }
        }

        
        
        
        if (Patch0025::AssistMode() != 2) return;

        
        int luigiDf = -1, marioDf = -1;
        for (int i = 0; i < sP16N; i++) {
            if (sP16[i].actor == luigi)      luigiDf = sP16[i].deadFrames;
            else if (sP16[i].actor == mario) marioDf = sP16[i].deadFrames;
        }
        if (P21IsOut(mario, marioDf) || P21IsOut(luigi, luigiDf)) return;

        float mx = ReadF(mario, CameraMidpointOffsets::PlayerPosX);
        float my = ReadF(mario, CameraMidpointOffsets::PlayerPosY);
        float mz = ReadF(mario, CameraMidpointOffsets::PlayerPosZ);
        float lx = ReadF(luigi, CameraMidpointOffsets::PlayerPosX);
        float ly = ReadF(luigi, CameraMidpointOffsets::PlayerPosY);
        float lz = ReadF(luigi, CameraMidpointOffsets::PlayerPosZ);
        if (!CameraSaneFloat(mx) || !CameraSaneFloat(my) || !CameraSaneFloat(mz) ||
            !CameraSaneFloat(lx) || !CameraSaneFloat(ly) || !CameraSaneFloat(lz)) {
            return;
        }

        float midX = (mx + lx) * 0.5f;
        float midY = (my + ly) * 0.5f;
        float midZ = (mz + lz) * 0.5f;

        
        
        
        {
            constexpr float kVoidY   = -400.0f;
            constexpr float kVoidGap = 600.0f;
            bool luigiVoid = (ly < kVoidY) && (my - ly > kVoidGap);
            bool marioVoid = (my < kVoidY) && (ly - my > kVoidGap);
            if (luigiVoid != marioVoid) {
                if (luigiVoid) { midX = mx; midY = my; midZ = mz; }
                else           { midX = lx; midY = ly; midZ = lz; }
            }
        }

        
        
        float tx = (tracked == mario) ? mx : lx;
        float ty = (tracked == mario) ? my : ly;
        float tz = (tracked == mario) ? mz : lz;
        out[0] += midX - tx;
        out[1] += midY - ty;
        out[2] += midZ - tz;
#endif
    }
};

                                                                            
                                                                          
                                                                          
                                               
  
                                                              
                                                                             
                                                                        
                                                                           
                                           
                                                                            
                                                                              
                                                                            
                                                                         
                                                                        
                                                                              
  
                                                                            
                                                                          
                                                                       
                                                                           
                                                                       
                                                                           
                                                                        
                                                                       
                                                                        
                                                                          
                      
  
                                                                       
                                                                          
                                                                        
                                                                          
                                                                            
                                                                            
                                                                          
                                                                          
                                                                           
                                                                          
                                                                        
                                                                          
                                                                        
                                                 
#define PATCH_0025_ENABLED 1

namespace Patch0025 {
    
    constexpr ptrdiff_t ModeGlobalSlot = 0x01A10F58;
    constexpr long SetTransOff = 0x83FA00;   

                                                                       
                                                                         
                                                                        
                                                                         
                                                                         
                                                                       
                                                                      
                                                              
                                                                   
                                                                           
                                                                          
                                                                   
                                                                        
    constexpr long HideModelIfShowOff = 0x83A480;  
    constexpr long ShowModelOff       = 0x83A350;  
    constexpr long HideSilhouetteOff  = 0x83A790;  
    constexpr long ShowSilhouetteOff  = 0x83A740;  

    
    [[maybe_unused]] static uintptr_t CurrentModel(uintptr_t player) {
        uintptr_t pmh = *reinterpret_cast<uintptr_t*>(player + 0x240);
        if (!CameraSanePtr(pmh)) return 0;
        uintptr_t arr = *reinterpret_cast<uintptr_t*>(pmh + 0x28);
        if (!CameraSanePtr(arr)) return 0;
        int idx = *reinterpret_cast<int*>(pmh + 0x30);
        if (idx < 0 || idx > 15) return 0;
        uintptr_t model = *reinterpret_cast<uintptr_t*>(arr + static_cast<long>(idx) * 8);
        if (!CameraSanePtr(model)) return 0;
        return model;
    }

    
    [[maybe_unused]] static bool IsModelHidden(uintptr_t model) {
        uintptr_t flags = *reinterpret_cast<uintptr_t*>(model + 0x108);
        if (!CameraSanePtr(flags)) return false;
        return *reinterpret_cast<unsigned char*>(flags + 6) != 0;
    }

    
    
    
    [[maybe_unused]] static int AssistMode() {
        uintptr_t slot = exl::util::modules::GetTargetOffset(ModeGlobalSlot);
        uintptr_t g = *reinterpret_cast<uintptr_t*>(slot);
        if (!CameraSanePtr(g)) return 0;
        uintptr_t a = *reinterpret_cast<uintptr_t*>(g + 0x28);
        if (!CameraSanePtr(a)) return 0;
        uintptr_t b = *reinterpret_cast<uintptr_t*>(a + 0x38);
        if (!CameraSanePtr(b)) return 0;
        uintptr_t holder = *reinterpret_cast<uintptr_t*>(b + 0x128);
        if (!CameraSanePtr(holder)) return 0;
        uintptr_t c = *reinterpret_cast<uintptr_t*>(holder + 0x200);
        if (!CameraSanePtr(c)) return 0;
        uintptr_t modeObj = *reinterpret_cast<uintptr_t*>(c + 0x20);
        if (!CameraSaneFloatPtr(modeObj)) return 0;
        int mode = *reinterpret_cast<int*>(modeObj);
        return (mode == 1 || mode == 2) ? mode : 0;
    }
}

static void Patch0025Tick(uintptr_t player) {
#if PATCH_0025_ENABLED
    
    
    
    
    
    uintptr_t scene = sCurrentScene;
    if (!CameraSanePtr(scene)) return;
    int count = *reinterpret_cast<int*>(scene + CameraMidpointOffsets::ScenePlayerCount);
    if (count < 1 || count > 8) return;
    uintptr_t array = *reinterpret_cast<uintptr_t*>(scene + CameraMidpointOffsets::ScenePlayerArray);
    if (!CameraSanePtr(array)) return;
    uintptr_t p0 = *reinterpret_cast<uintptr_t*>(array + 0x00);
    if (!CameraSanePtr(p0)) return;
    if (player != p0) return;      

    int mode = Patch0025::AssistMode();

    
    
    
    
    
    if (Patch0025::sSceneCoop && !Patch0025::sReArmed && mode == 1 && count >= 2) {
        Patch0025::sReArmed = true;
        uintptr_t setMode = exl::util::modules::GetTargetOffset(Patch0025::Set2PAssistModeOff);
        uintptr_t setAplt = exl::util::modules::GetTargetOffset(Patch0025::SetAppletCancel2PAssistOff);
        if (IsSaneGamePtr(setMode) && IsSaneGamePtr(setAplt)) {
            reinterpret_cast<void(*)(bool, bool)>(setMode)(true, true);
            reinterpret_cast<void(*)(bool)>(setAplt)(false);
            mode = Patch0025::AssistMode();
            Logging.Log("[BFCoop] PATCH-0025 co-op re-armed after scene load (mode now %d)", mode);
        }
    }

    static int sLastMode = -1;
    static int sModeLogs = 0;
    if (mode != sLastMode && sModeLogs < 30) {
        sModeLogs++;
        Logging.Log("[BFCoop] PATCH-0025 assist-mode %d -> %d (players=%d)",
                    sLastMode, mode, count);
        if (mode == 2) {
            Patch0025::sCoopLatch = true;
            if (count < 2) {
                Logging.Log("[BFCoop] PATCH-0025 co-op selected mid-scene: Luigi joins on the NEXT scene load (quit to title -> continue)");
            }
        } else if (mode == 1 && sLastMode == 2) {
            Patch0025::sCoopLatch = false;
            if (count >= 2) {
                Logging.Log("[BFCoop] PATCH-0025 co-op deselected: Luigi leaves on the next scene load");
            }
        }
        sLastMode = mode;
    }
#else
    (void)player;
#endif
}

                                                                      

extern "C" void exl_main(void* x0, void* x1) {
    exl::hook::Initialize();

    
    exl::patch::impl::InitPatcherImpl();

#if BFCOOP_EXLMOD_ENABLED && RELEASE_DIAGNOSTIC_NVN_BOOTSTRAP_ENABLED
    if (exlmod::nvn::InstallBootstrapHook()) {
        Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC installed direct (nvnBootstrapLoader)");
    } else {
        Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC direct install unavailable; arming deferred install");
    }
    if (exlmod::nvn::RegisterDeferredInstall()) {
        Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC armed (deferred NVN bootstrap install)");
    } else {
        Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC arm failed (deferred NVN bootstrap install)");
    }
#endif
#if BFCOOP_SETTINGS_CORE_ENABLED
    Patch0023::RegisterSettings();
#endif
#if BFCOOP_EXLMOD_ENABLED && RELEASE_DIAGNOSTIC_SETTINGS_IMGUI_ENABLED
    Diag0035::InitImGuiArena();
    exlmod::settings_imgui::SetAllocator({
        Diag0035::ImGuiAlloc,
        Diag0035::ImGuiFree,
        &Diag0035::sImGuiArena,
    });
    exlmod::settings_imgui::Configure({
        "BFCoop Settings",
        "BFCoop ExLaunch",
        "BFCoop NVN pending",
        "[BFCoop]",
        48.0f,
        72.0f,
        430.0f,
        230.0f,
    });
    exlmod::settings_imgui::SetBackendStateProvider(Diag0035::FillBackendState);
    exlmod::settings_imgui::SetInputStateProvider(Diag0035::FillInputState);
    if (exlmod::imgui_nvn::RegisterDrawDataConsumer()) {
        Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC installed (settings ImGui NVN renderer probe)");
    } else {
        Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC install failed (settings ImGui NVN renderer probe)");
    }
#if RELEASE_DIAGNOSTIC_NVN_SUBMITTER_ENABLED
    exlmod::imgui_nvn::SetSubmitterEnabled(true);
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC submitter enabled (settings ImGui NVN renderer)");
#else
    exlmod::imgui_nvn::SetSubmitterEnabled(false);
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC submitter disabled (probe-only)");
#endif
#if RELEASE_DIAGNOSTIC_SETTINGS_START_VISIBLE
    exlmod::settings_imgui::SetVisible(true);
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC start visible (settings window probe)");
#endif
    if (exlmod::settings_imgui::RegisterRenderCallback()) {
        Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC installed (settings ImGui draw callback)");
    } else {
        Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC install failed (settings ImGui draw callback)");
    }
#endif

    
    ForcePlayerCount::InstallAtOffset(PatchOffsets::SceneInitPlayerCount);
    FixSceneLoopMapper::InstallAtOffset(PatchOffsets::SceneLoopMapperCheck);
    FixActorCount::InstallAtOffset(PatchOffsets::SceneLoopActorCount);

    
    ArrayGetOrNull::InstallAtOffset(PatchOffsets::ArrayGetOrNull);

    
    
    
    


                                                                       
    {
        exl::patch::RandomAccessPatcher p;

        
        const uint32_t fourNops[] = {0xD503201F, 0xD503201F, 0xD503201F, 0xD503201F};
        for (int i = 0; i < 4; i++)
            p.Write<uint32_t>(CrashFixOffsets::FightInitFix + i * 4, fourNops[i]);

        
        p.Write<uint32_t>(CrashFixOffsets::DarkBowserDemo, 0x52800000);

        
        p.Write<uint32_t>(CrashFixOffsets::Phase3InitA, 0xD503201F);
        p.Write<uint32_t>(CrashFixOffsets::Phase3InitB, 0xD503201F);

        
        p.Write<uint32_t>(CrashFixOffsets::Phase2Defeat, 0xD503201F);

        
        p.Write<uint32_t>(CrashFixOffsets::PlayerAliveGroup, 0xD503201F);

        
        p.Write<uint32_t>(CrashFixOffsets::ActorKitCapacity, 0x528ABE03);

        
        p.Write<uint32_t>(CrashFixOffsets::SceneObjHolderSz, 0x528007C2);



        
        p.Write<uint32_t>(CrashFixOffsets::BossResHeap, 0xD2A32000);


        Logging.Log("[BFCoop] CrashFix: applied %lu NOP/tweak patches",
            (unsigned long)9);
    }

                                                                       
    
    KoopaJrNeutralize::InstallAtOffset(KoopaJrOffsets::SceneInit);

                                                                       
    
    FixPhaseBossFigure::InstallAtOffset(FigureFixOffsets::PhaseBossFigInit);
    
    FixGigaModelName::InstallAtOffset(FigureFixOffsets::GigaModelName);
    
    FixGigaBellCollect::InstallAtOffset(FigureFixOffsets::GigaBellCollect);

                                                                              
    
    
    TreeSelA::InstallAtOffset(PatchOffsets::TreeSelSiteA);
    TreeSelB::InstallAtOffset(PatchOffsets::TreeSelSiteB);
    TreeSelC::InstallAtOffset(PatchOffsets::TreeSelSiteC);
    GrabSel::InstallAtOffset(PatchOffsets::GrabSelSite);
    Logging.Log("[BFCoop] PATCH-0012 installed (tree/grab)");

                                                                       
    CameraMidpointLookAt::InstallAtOffset(CameraMidpointOffsets::MakeLookAtCamera);
    Logging.Log("[BFCoop] PATCH-0013 installed (camera midpoint output)");

#if RELEASE_DIAGNOSTIC_ENABLED
                                                                                         
    Diag0021Camera9207c0::InstallAtOffset(0x009207C0);
    Logging.Log("[BFCoop] PATCH-0017c installed @ 0x9207c0 (survivor eye-follow override)");
#endif

                                                                    
                                                                              
                                                                            
                                                                        
    AltCamCommitOverride::InstallAtOffset(CameraMidpointOffsets::AltFinalCommitArgs);
    Logging.Log("[BFCoop] PATCH-0019 installed @ 0x6D9E4 (alt-pipeline commit hook)");
#if PATCH_0019_ENABLED
    Logging.Log("[BFCoop] PATCH-0019 active (follow-subject retarget in alt-commit hook)");
#endif

#if PATCH_0016_ENABLED
                                                                      
                                                                             
                                                                    
    InterceptDeath::InstallAtOffset(0x42CB40);
    Logging.Log("[BFCoop] PATCH-0016 installed (intercept-before-death @ 0x42CB40)");
#endif

                                                                      
                                                                              
                                                                        
                                                                     
    DiagFigureLose::InstallAtOffset(0x392140);
    Logging.Log("[BFCoop] PATCH-0021 installed (killing-blow detector @ 0x392140; gate feed disabled)");

#if RELEASE_DIAGNOSTIC_ENABLED
                                                                             
                                                                            
                               
    Diag0029SetUpdateFreeze::InstallAtOffset(0xa9500);
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC installed (rc::setUpdateFreeze @ 0xa9500)");
#endif
#if RELEASE_DIAGNOSTIC_ENABLED
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC installed (freeze-byte watch in alt-commit hook)");
#endif
#if RELEASE_DIAGNOSTIC_ENABLED
                                                                                 
    Diag0031CamCalcTarget::InstallAtOffset(0x914d50);
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC installed (al::setCameraCalcTargetFlag @ 0x914d50)");
#endif

#if PATCH_0022_ENABLED
                                                                         
                                                                          
    SkipFreezeDistance::InstallAtOffset(0x91a8a0);
    Logging.Log("[BFCoop] PATCH-0022 installed (freeze-distance skip @ 0x91a8a0 + calc-target re-arm)");
#endif

#if PATCH_0023_ENABLED
#if PATCH_0023_INSTALL_ENABLED
                                                                     
                                                                                
#if RELEASE_DIAGNOSTIC_PATCH0023_BOUNDARY_ENABLED
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC patch0023 boundary: before install @ 0x6bc00");
#endif
    CamZoomDistanceRaw::InstallAtOffset(Patch0023::CalcDistanceRaw);
#if RELEASE_DIAGNOSTIC_PATCH0023_BOUNDARY_ENABLED
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC patch0023 boundary: after install, before base read");
#endif
    const float patch0023BaseZoom = Patch0023::BaseZoom();
#if RELEASE_DIAGNOSTIC_PATCH0023_BOUNDARY_ENABLED
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC patch0023 boundary: base read ok %.2f", patch0023BaseZoom);
#endif
    Logging.Log("[BFCoop] PATCH-0023 installed (camera zoom @ 0x6bc00, base=%.2f dynamic=%d)",
                patch0023BaseZoom, PATCH_0023_DYNAMIC);
#else
#if RELEASE_DIAGNOSTIC_PATCH0023_BOUNDARY_ENABLED
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC patch0023 boundary: install skipped, before base read");
#endif
    const float patch0023BaseZoom = Patch0023::BaseZoom();
#if RELEASE_DIAGNOSTIC_PATCH0023_BOUNDARY_ENABLED
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC patch0023 boundary: base read ok %.2f", patch0023BaseZoom);
#endif
    Logging.Log("[BFCoop] PATCH-0023 install skipped (launch A/B, base=%.2f dynamic=%d)",
                patch0023BaseZoom, PATCH_0023_DYNAMIC);
#endif
#else
    Logging.Log("[BFCoop] PATCH-0023 disabled (launch rescue A/B)");
#endif

#if BFCOOP_EXLMOD_ENABLED && RELEASE_DIAGNOSTIC_RENDER_HOOK_ENABLED
    Diag0033DisplayListEnd::InstallAtOffset(Diag0033::DisplayListEnd);
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC installed (DisplayList::endDisplayList @ 0x75d330)");
#endif

#if PATCH_0024_ENABLED
                                                                           
                                                                              
    CoopCamTargetMidpoint::InstallAtOffset(Patch0024::GroupTargetCalc);
    Logging.Log("[BFCoop] PATCH-0024 installed (camera target midpoint @ 0x71bb0)");
#endif

#if PATCH_0026_ENABLED
                                                                             
                                                                               
    Logging.Log("[BFCoop] PATCH-0026 v2 installed (projection-space fit in FollowLimit final commit @ 0x6d9e4)");
#endif

#if PATCH_0027_ENABLED
    Logging.Log("[BFCoop] PATCH-0027 installed (Odyssey PATCH-0008 final-pose widening in FollowLimit commit @ 0x6d9e4; base=1.12 max=1.65 start=500 full=2500 lerp=0.05)");
#endif

#if PATCH_0028_ENABLED
    Patch0028FinalLookAtCamera::InstallAtOffset(0x0006DFB0);
    Logging.Log("[BFCoop] PATCH-0028 installed (Odyssey PATCH-0053 exact final LookAtCamera fit @ 0x6dfb0; model bounds + native bubble handoff at 3000)");
#endif

#if RELEASE_DIAGNOSTIC_PATCH0028_MODEL_BOUNDS_ENABLED
    Logging.Log("[BFCoop] RELEASE-DIAGNOSTIC installed (PATCH-0028 native model-bounds acceptance discriminator)");
#endif

#if PATCH_0025_ENABLED
                                                                           
                                                                         
                                                                            
    Logging.Log("[BFCoop] PATCH-0025 v5 active (deferred Luigi creation + coop latch/re-arm)");
#endif
}

extern "C" NORETURN void exl_exception_entry() {
    EXL_ABORT("Default exception handler called!");
}
