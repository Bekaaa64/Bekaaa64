#include "Includes.h"
#include "Tools.h"
#include "fake_dlfcn.h"
#include "Vector3.hpp"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "StrEnc.h"
#include "plthook.h"


#include "Items.h"
#include "fontch.h"  
#include "obfuscate.h"
#include "KittyMemory/MemoryPatch.h"

#include "json.hpp"
#include "Rect.h"
#include "Iconcpp.h"
#include "ImguiPP.cpp"
#include "Menu.h"
#include "Font.h"
#include "Font.h"
#include "Icon.h"
using json = nlohmann::json;
#define SLEEP_TIME 1000LL / 60LL
#include "SDK.hpp"
using namespace SDK;
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "base64/base64.h"




float size_child = 0;
static float SliderFloat = 0;
char extras[32];

#define COLOR_GREEN Color(0.f, 0.5f, 0.f, 1.f)
#define COLOR_BLACK Color(0, 0, 0, 1.f)
#define COLOR_WHITE Color(1.f, 1.f, 1.f, 1.f)
#define COLOR_RED   Color(1.f, 0, 0, 1.f)
#define COLOR_LIME  Color(0, 1.f, 0, 1.f)
#define COLOR_BLUE  Color(0, 0, 1.f, 1.f)
#define COLOR_ORANGE Color(1.f, 0.6f, 0.f, 1.f)
#define IM_PI 3.14159265358979323846f
#define RAD2DEG(x) ((float)(x) * (float)(180.f / IM_PI))
#define DEG2RAD(x) ((float)(x) * (float)(IM_PI / 180.f))

static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;

uintptr_t AimBullet_Offset;
uintptr_t GWorld_Offset, GUObjectArray_Offset, SilentAim_Offset;

#define GNames_Offset 0x483167c
 #define GEngine_Offset 0x9e1cc1c //UEngine
 #define GEngine_Offset 0x9e01220 //UlocalPlayer
 #define GUObject_Offset 0x9bcac18
 #define GetActorArray_Offset 0x673c4e8
 #define ProccesEvent_Offset 0x62a4b5c //Child
 #define GNativeAndroidApp_Offset 0x9a02f38
 #define Actors_Offset 0x70



static int a = 0;
time_t rng = 0;
static std::string EXP = " ";
static std::string SLOT = " ";
static std::string modname = " ";
static std::string mod_status = " ";
static std::string credit = " ";
static std::string days = " ";
static std::string key = " ";
static std::string keys = " ";

std::string KeySlot = "";
std::string FlotingText = "";
std::string expiredDate = "";

//std::string expiredDate = "";
ImFont* Arabic;
json items_data;
std::string g_Token, g_Auth;
bool bValid = false;
bool show_another_window2 = false;
static bool HideWindow = true;
bool unlock;
bool shit = false;
bool LobbyBy = false;
bool ActiveESP = false;
bool ItemsMenu = true;

float RGB = 5;
float sliderint;
float FOVSize = 5;
float FOVSizea = 120;
uintptr_t anort;
uintptr_t UE4;
uintptr_t ANOGS;
uintptr_t Anogs;
uintptr_t g_UE4;
uintptr_t cloud;
uintptr_t anogs;
uintptr_t g_gcloud;
uintptr_t PandoraVideo;
uintptr_t GKPxStudio;
uintptr_t tgpa;
uintptr_t cubehawk;
uintptr_t shared;
uintptr_t INTLFoundation;
uintptr_t INTLCompliance;
uintptr_t CrashSight;
uintptr_t antiban;
uintptr_t GCloudVoice;
uintptr_t ijkffmpeg;
uintptr_t gcloudcore;
uintptr_t gnustl_shared;
uintptr_t igshare;
uintptr_t ITOP;
uintptr_t marsxlog;
uintptr_t swappy;
uintptr_t GvoiceNN;
uintptr_t TDataMaster;
uintptr_t TPRT;
uintptr_t TDMASTER;

android_app *g_App = 0;
//;time_t rng = 0;
ImFont* logo;
//ImFont* main_close;
ASTExtraPlayerCharacter *g_LocalPlayer = 0;
ASTExtraPlayerController *g_LocalController = 0;
///float FOVSizea = 100;
///float FOVSize = 5;
bool HIDEESP = true;
bool initImGui = false;
int screenWidth = -1, glWidth, screenHeight = -1, glHeight;
float density = -1;

std::map<int, bool> Items;
std::map<int, float *> ItemColors;

bool WriteAddr(void *addr, void *buffer, size_t length) {
    unsigned long page_size = sysconf(_SC_PAGESIZE);
    unsigned long size = page_size * sizeof(uintptr_t);
    return mprotect((void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy(addr, buffer, length) != 0;
}
template<typename T>
void Write(uintptr_t addr, T value) {
    WriteAddr((void *) addr, &value, sizeof(T));
}

static UEngine *GEngine = 0;
UWorld *GetWorld() {
    while (!GEngine) {
        GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1"); // Auto 
        sleep(1);
    }
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;

        if (ViewPort) {
   //return {};
            return ViewPort->World;
        }
    }
    return 0;
}
TNameEntryArray *GetGNames() {
    return ((TNameEntryArray *(*)()) (UE4 + GNames_Offset))();
}

std::vector<AActor *> getActors() {
    auto World = GetWorld();
    if (!World)
        return std::vector<AActor *>();

    auto PersistentLevel = World->PersistentLevel;
    if (!PersistentLevel)
        return std::vector<AActor *>();

    auto Actors = *(TArray<AActor *> *)((uintptr_t) PersistentLevel + Actors_Offset);

    std::vector<AActor *> actors;
    for (int i = 0; i < Actors.Num(); i++) {
        auto Actor = Actors[i];
        if (Actor) {
            actors.push_back(Actor);
        }
    }
    return actors;
}


enum EAimBy {
    Distance = 0,
	FOV = 1
};

enum EAimB {
    Bt90 = 0,
	Bt360 = 1
};

enum EAimTarget {
    Head = 0,
    Chest = 1
};

enum EAimTrigger {
    None = 0,
    Shooting = 1,
    Scoping = 2,
    Both = 3,
    Any = 4
};
    struct sOTHER {
        bool FPS;
        bool EXPIRYTIME;
    };

//std::map<int, bool> Items;

struct sConfig {
	bool Nation;
	float Cross;
	float Meter;
	bool FPS;
	float Skill;
	float Skill1;
	float Skill3;
	float Skill4;
	float FOVSizea;
	float FOVSize;
	float Skill2;
	float Line;
	float Recc;
	float Distance;
	float Box;
	float Skeleton;
	float Production;
    struct sPlayerESP {
		bool RGB;
		bool LineBelow;
		bool KERO;
		bool Island;
        bool LineMid;
        bool Recc;
        bool LootBoxItems;
        bool Box3D;
        bool Box4Line;
        bool Namee;
        bool keroz;
        bool LineTop;
        bool VehicleFuel;
        bool VehicleHP;
        bool WeaponId;
        bool BoxItems;
		bool ActiveEsp;
		bool MagicBullet;
		bool VehicleDist;
		bool Alert;
	//	bool VehicleFuel;
		bool Nation;
		//bool Box3D;
        bool Line;
		bool Radar;
		bool RadarDraw2;
		bool Radar1;
		bool Radar2;
		bool Radar3;
		bool Radar4;
		bool Warning;
        bool Box;
        bool Skeleton;
        bool Health;
        bool Grenade;
        bool ShowKnockedHealth;
        bool KEROO3;
        bool Name;
        bool Distance;
        bool TeamID;
        bool NoBot;
        bool LootBox;
        bool Vehicle;
    };
    sPlayerESP PlayerESP{0};

    struct sAimMenu {
        bool Enable;
        bool Less;
		bool Enable2;
        bool AimBot;
        bool SilentAim;
		float Cross;
        float RecZ;
		float RecX;
		float RecY;
		EAimBy AimBy;
	    EAimB  AimB;
        EAimTarget Target;
        EAimTrigger Trigger;
        bool Pred;
        bool ReCo;
        bool IgnoreKnocked;
        bool VisCheck;
		bool IgnoreBots;
		bool IgnoreBot;
		bool Recc;
		bool Predection;
    };
	sAimMenu SilentAim{0};
	sAimMenu AimBot{0};

	struct sMEM
	{
    bool Warning;
    bool Warning1;
	};
	sMEM MEM{0};
	struct sHighRisk
	{
		bool Shake;
		bool Recoil;
		bool Recoil1;
		bool RGB;
		bool Instant;
		bool HitEffect;
		bool Wall;
		bool FlashSdk;
		bool Wal;
		bool WideView;
        bool FPSUnlock = true;
        bool TSSBypass = true;
        bool TSSBypass2 = true;
        bool blockspect = true;
	};
	sHighRisk HighRisk{0};


struct sGOODVIEW {
    	bool ENABLE;
		bool UP;
		bool ON;
		bool DOWN;
		bool FRONT;
		bool BEHIND;
		bool RIGHT;
		bool LEFT;
		
		
	};
	sGOODVIEW GOODVIEW;


struct sESPMenu {
		bool Line;
		bool Box;
		bool fk;
		bool Skeleton;
		bool AUTOGOODZ;
		bool AUTOGOODY;
		bool AUTOGOODX;
		bool AUTOGOODXX;
		bool AUTOGOODYY;
		bool Skeletonn;
		bool Health;
		bool Name;
		bool Distance;
		bool TeamID;
		bool AutoFire;
	};
	sESPMenu ESPMenu;

struct sColorsESP
	{
		float *PVisibile;
        float *PNonVis;
        float *PVLine;
        float *PVILine;
        float *BVLine;
        float *BVILine;
        float *PVBox;
        float *PVIBox;
        float *BVBox;
        float *BVIBox;
        float *PVSkeleton;
        float *PVISkeleton;
        float *BVSkeleton;
        float *BVISkeleton;
		float *Fov;
		float *Text;
		float *Box3D;
		float *RGB;
		float *Count;
        float *TeamID;
        float *Name;
        float *WeaponId;
        float *Distance;
        float *Vehicle;
        float *Items;
    }; 
	sColorsESP ColorsESP{0};
	struct sOTHER {
        bool FPS;
        bool HIDEESP;
        bool EXPIRYTIME;
    };
    sOTHER OTHER{0};
};
sConfig Config{0};
static bool Feu;
#define CREATE_COLOR(r, g, b, a) new float[4] {(float)r, (float)g, (float)b, (float)a};

static float LineSize = 0.6f;
static float BoxSize = 1.7f;
static float SkeletonSize = 1.0f;
static float NameSize = 34.0f;
static float DistanceSize = 35.0f;
static float VehicleSize = 30.0f;

float RadarXW=320,RadarYW=255;


struct sRegion {
    uintptr_t start, end;
};

std::vector<sRegion> trapRegions;

bool isObjectInvalid(UObject *obj) {
    if (!Tools::IsPtrValid(obj)) {
        return true;
    }

    if (!Tools::IsPtrValid(obj->ClassPrivate)) {
        return true;
    }

    if (obj->InternalIndex <= 0) {
        return true;
    }

    if (obj->NamePrivate.ComparisonIndex <= 0) {
        return true;
    }

    if ((uintptr_t)(obj) % sizeof(uintptr_t) != 0x0 && (uintptr_t)(obj) % sizeof(uintptr_t) != 0x4) {
        return true;
    }

    if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj) >= region.start && ((uintptr_t) obj) <= region.end; }) ||
        std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj->ClassPrivate) >= region.start && ((uintptr_t) obj->ClassPrivate) <= region.end; })) {
        return true;
    }

    return false;
}

std::string getObjectPath(UObject *Object) {
    std::string s;
    for (auto super = Object->ClassPrivate; super; super = (UClass *) super->SuperStruct) {
        if (!s.empty())
            s += ".";
        s += super->NamePrivate.GetName();
    }
    return s;
}

// ======================================================================== //

int32_t ToColor(float *col) {
    return ImGui::ColorConvertFloat4ToU32(*(ImVec4 *) (col));
}

FRotator ToRotator(FVector local, FVector target) {
    FVector rotation = UKismetMathLibrary::Subtract_VectorVector(local, target);

    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);

    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;

    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;

    return newViewAngle;
}


#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(localController, w, true, s)


bool isInsideFOVs(int x, int y) {
    if (!Config.AimBot.Cross)
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = Config.AimBot.Cross*0.5f;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

auto GetTargetForAimBot() {
   ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();
    auto Actors = getActors();
    auto localPlayer = g_LocalPlayer;
    auto localController = g_LocalController;
    if (localPlayer)
    {
        for (int i = 0; i < Actors.size(); i++) {
                    auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;
            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
            {
                auto Player = (ASTExtraPlayerCharacter *)Actor;
                auto Target = (ASTExtraPlayerCharacter *) Actor;

                float dist = localPlayer->GetDistanceTo(Target) / 150.0f;    
                if (dist > 150.0f)
                    continue;
                        
                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;
                if (Player->TeamID == localPlayer->TeamID)
                    continue;
                if (Player->bDead)
                    continue;
                    
                    
                if (Config.AimBot.IgnoreKnocked) {
                    if (Player->Health == 0.0f)
                        continue;
                }

                if (Config.AimBot.VisCheck) {
                    if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                        continue;
                }
                if (Config.AimBot.IgnoreBot) {
                    if (Player->bIsAI)
                        continue;
                }

                        auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});
                FVector2D RootSc, HeadSc;
                if (W2S(Root, &RootSc) && W2S(Head, &HeadSc))
                {
                    float height = abs(HeadSc.Y - RootSc.Y);
                    float width = height * 0.65f;

                    FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight))
                    {
                        FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
                        

                        
                        
                                if(isInsideFOVs((int)middlePoint.X, (int)middlePoint.Y)) {
									
                                float dist = FVector2D::Distance(v2Middle, v2Loc);

                                if (dist < max) {
                                    max = dist;
                                    result = Player;
                                }
                              
                            }
                        }
                  }  
                
            }
        }
    }

    return result;
}



auto GetTargetByCrossDist() {
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();

    auto Actors = getActors();

    auto localPlayer = g_LocalPlayer;
    auto localController = g_LocalController;
                        FVector ViewPosY{0, 0, 0};
                        if (localPlayer) {                   
                        ViewPosY = localPlayer->GetBonePos("Head", {});
                        ViewPosY.Z += 10.f;
                         }  
    if (localPlayer) {
        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                auto Player = (ASTExtraPlayerCharacter *) Actor;

                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;

                if (Player->TeamID == localPlayer->TeamID)
                    continue;

                if (Player->bDead)
                    continue;
//silentAim
                if (Config.SilentAim.IgnoreKnocked) {
                    if (Player->Health == 0.0f)
                        continue;
                }

                if (Config.SilentAim.VisCheck) {
                    if (!localController->LineOfSightTo(Player, ViewPosY, true))
                        continue;
                }
                if (Config.SilentAim.IgnoreBot) {
                    if (Player->bIsAI)
                        continue;
                }

                auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});

                FVector2D RootSc, HeadSc;
                if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
                    float height = abs(HeadSc.Y - RootSc.Y);
                    float width = height * 0.65f;

                    FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
                        FVector2D v2Middle = FVector2D((float) (glWidth / 2), (float) (glHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
if(isInsideFOVs((int)middlePoint.X, (int)middlePoint.Y)) {
                        float dist = FVector2D::Distance(v2Middle, v2Loc);

                        if (dist < max) {
                            max = dist;
                            result = Player;
                        }
                    }
                   }
                }
            }
        }
    }

    return result;
}

// ======================================================================== //
const char *GetVehicleName(ASTExtraVehicleBase *Vehicle) {
    switch (Vehicle->VehicleShapeType) {
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart:
            return "Motorbike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia:
            return "Dacia";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus:
            return "Mini Bus";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyPickup:
            return "Pick Up";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy:
            return "Buggy";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ:
            return "UAZ";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117:
            return "PG117";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Aquarail:
            return "Aquarail";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado01:
            return "Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Rony:
            return "Rony";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Scooter:
            return "Scooter";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowMobile:
            return "Snow Mobile";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_TukTukTuk:
            return "Tuk Tuk";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowBike:
            return "Snow Bike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Surfboard:
            return "Surf Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Snowboard:
            return "Snow Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Amphibious:
            return "Amphibious";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_LadaNiva:
            return "Lada Niva";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAV:
            return "UAV";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MegaDrop:
            return "Mega Drop";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01:
            return "Lamborghini";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_GoldMirado:
            return "Gold Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_BigFoot:
            return "Big Foot";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUH60:
            return "UH60";
            break;
        default:
            return "Vehicle";
            break;
    }
    return "Vehicle";
}

void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = 0;

void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1) {
    if (Config.SilentAim.Enable) {
        ASTExtraPlayerCharacter *Target = GetTargetByCrossDist();
        if (Target) {
            bool triggerOk = false;
            if (Config.SilentAim.Trigger != EAimTrigger::None) {
                if (Config.SilentAim.Trigger == EAimTrigger::Shooting) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Scoping) {
                    triggerOk = g_LocalPlayer->bIsGunADS;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Both) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring && g_LocalPlayer->bIsGunADS;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Any) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
                }
            } else triggerOk = true;
            if (triggerOk) {
                FVector targetAimPos = Target->GetBonePos("Head", {});
                if (Config.SilentAim.Target == EAimTarget::Chest) {
                    targetAimPos.Z -= 25.0f;
                }
                UShootWeaponEntity *ShootWeaponEntityComponent = thiz->ShootWeaponEntityComponent;
                if (ShootWeaponEntityComponent) {
                    ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                    if (CurrentVehicle) {
                        FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                    } else {
                        FVector Velocity = Target->GetVelocity();

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                    }
                    FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, g_LocalController->PlayerCameraManager->CameraCache.POV.Location);
                    rot = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                }
            }
        }
    }
    return orig_shoot_event(thiz, start, rot, weapon, unk1);
}
// ================================================================================================================================ //


class FPSCounter {
protected:
    unsigned int m_fps;
    unsigned int m_fpscount;
    long m_fpsinterval;

public:
    FPSCounter() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
    }

    void update() {
        m_fpscount++;

        if (m_fpsinterval < time(0)) {
            m_fps = m_fpscount;

            m_fpscount = 0;
            m_fpsinterval = time(0) + 1;
        }
    }

    unsigned int get() const {
        return m_fps;
    }
};

FPSCounter fps;


void DrawBoxEnemy(ImDrawList *draw, ImVec2 X, ImVec2 Y, float thicc, float rounding, int color) {
    draw->AddLine({X.x, X.y}, {Y.x, Y.y}, color, thicc);
}

void VectorAnglesRadar(Vector3 & forward, FVector & angles) {
 if (forward.X == 0.f && forward.Y == 0.f) {
  angles.X = forward.Z > 0.f ? -90.f : 90.f;
  angles.Y = 0.f;
 } else {
  angles.X = RAD2DEG(atan2(-forward.Z, forward.Magnitude(forward)));
  angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
 }
 angles.Z = 0.f;
}

void RotateTriangle(std::array<Vector3, 3> & points, float rotation) {
 const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
 for (auto & point : points) {
  point = point - points_center;
  const auto temp_x = point.X;
  const auto temp_y = point.Y;
  const auto theta = DEG2RAD(rotation);
  const auto c = cosf(theta);
  const auto s = sinf(theta);
  point.X = temp_x * c - temp_y * s;
  point.Y = temp_x * s + temp_y * c;
  point = point + points_center;
 }
}

FVector2D pushToScreenBorder(FVector2D Pos, FVector2D screen, int borders, int offset) {
	int x = (int)Pos.X;
	int y = (int)Pos.Y;
	if ((borders & 1) == 1) {
		y = 0 - offset;
	}
	if ((borders & 2) == 2) {
		x = (int)screen.X + offset;
	}
	if ((borders & 4) == 4) {
		y = (int)screen.Y + offset;
	}
	if ((borders & 8) == 8) {
		x = 0 - offset;
	}
	return FVector2D(x, y);
}

int isOutsideSafezone(FVector2D pos, FVector2D screen) {
	FVector2D mSafezoneTopLeft(screen.X * 0.04f, screen.Y * 0.04f);
	FVector2D mSafezoneBottomRight(screen.X * 0.96f, screen.Y * 0.96f);
	int result = 0;
	if (pos.Y < mSafezoneTopLeft.Y) {
		result |= 1;
	}
	if (pos.X > mSafezoneBottomRight.X) {
		result |= 2;
	}
	if (pos.Y > mSafezoneBottomRight.Y) {
		result |= 4;
	}
	if (pos.X < mSafezoneTopLeft.X) {
		result |= 8;
	}
	return result;
}

void Box4Line(ImDrawList *draw, float thicc, int x, int y, int w, int h, int color) {
    int iw = w / 4;
    int ih = h / 4;
    // top
    draw->AddRect(ImVec2(x, y),ImVec2(x + iw, y), color, thicc);
    draw->AddRect(ImVec2(x + w - iw, y),ImVec2(x + w, y), color, thicc);
    draw->AddRect(ImVec2(x, y),ImVec2(x, y + ih), color, thicc);
    draw->AddRect(ImVec2(x + w - 1, y),ImVec2(x + w - 1, y + ih), color, thicc);;
    // bottom
    draw->AddRect(ImVec2(x, y + h),ImVec2(x + iw, y + h), color, thicc);
    draw->AddRect(ImVec2(x + w - iw, y + h),ImVec2(x + w, y + h), color, thicc);
    draw->AddRect(ImVec2(x, y + h - ih), ImVec2(x, y + h), color, thicc);
    draw->AddRect(ImVec2(x + w - 1, y + h - ih), ImVec2(x + w - 1, y + h), color, thicc);
}

void DrawBoxEnemy(ImDrawList *draw, ImVec2 X, ImVec2 Y, float thicc, int color) {
    draw->AddLine({X.x, X.y}, {Y.x, Y.y}, color, thicc);
}

void DrawFilledRectangle(int x, int y, int w, int h, ImU32 col, float rounding) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), col, rounding);
}

void DrawRectangle(int x, int y, int w, int h, ImU32 col, float rounding) {
    ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), col, rounding);
}
bool W2S2(FVector worldPos, FVector2D *screenPos) {
    return g_LocalController->ProjectWorldLocationToScreen(worldPos, true, screenPos);
}

void Line(ImDrawList *draw,FVector2D origin, FVector2D dest, ImColor color)
{
   draw->AddLine({origin.X, origin.Y},{dest.X, dest.Y},color, 2.0f);
}


void Box3D1(ImDrawList *draw, FVector origin, FVector extends, ImColor col) {
    origin.X -= extends.X / 2.f;
    origin.Y -= extends.Y / 2.f;
    origin.Z -= extends.Z / 2.f;
    
    
 FVector one = origin;
 FVector two = origin; two.X += extends.X;
 FVector tree = origin; tree.X += extends.X; tree.Y += extends.Y;
 FVector four = origin; four.Y += extends.Y;

 FVector five = one; five.Z += extends.Z;
 FVector six = two; six.Z += extends.Z;
 FVector seven = tree; seven.Z += extends.Z;
 FVector eight = four; eight.Z += extends.Z;

    FVector2D s1, s2, s3, s4, s5, s6, s7, s8;
    if (W2S2(one, &s1) && W2S2(two, &s2) && W2S2(tree, &s3) && W2S2(four, &s4) &&
    W2S2(five, &s5) && W2S2(six, &s6) && W2S2(seven, &s7) && W2S2(eight, &s8))
    {
        
    Line(draw,s1, s2, col);
    Line(draw,s2, s3, col);
    Line(draw,s3, s4, col);
    Line(draw,s4, s1, col);
 
    Line(draw,s5, s6, col);
    Line(draw,s6, s7, col);
    Line(draw,s7, s8, col);
    Line(draw,s8, s5, col);
 
    Line(draw,s1, s5, col);
    Line(draw,s2, s6, col);
    Line(draw,s3, s7, col);
    Line(draw,s4, s8, col);

}
}

FVector WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY, Vector3 Size, bool &outbuff) {
 bool flag = false;
 double num = (double)Yaw;
 double num2 = num * 0.017453292519943295;
 float num3 = (float)std::cos(num2);
 float num4 = (float)std::sin(num2);
 float num5 = Origin.X - LocalOrigin.X;
 float num6 = Origin.Y - LocalOrigin.Y;
 struct FVector Xector;
 Xector.X = (num6 * num3 - num5 * num4) / 150.f;
 Xector.Y = (num5 * num3 + num6 * num4) / 150.f;
 struct FVector Xector2;
 Xector2.X = Xector.X + PosX + Size.X / 2.f;
 Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f;
 bool flag2 = Xector2.X > PosX + Size.X;
 if (flag2) {
  Xector2.X = PosX + Size.X;
 }else{
  bool flag3 = Xector2.X < PosX;
  if (flag3) {
   Xector2.X = PosX;
  }
 }
 bool flag4 = Xector2.Y > PosY + Size.Y;
 if (flag4) {
  Xector2.Y = PosY + Size.Y;
 }else{
  bool flag5 = Xector2.Y < PosY;
  if (flag5){
   Xector2.Y = PosY;
  }
 }
 bool flag6 = Xector2.Y == PosY || Xector2.X == PosX;
 if (flag6){
  flag = true;
 }
 outbuff = flag;
 return Xector2;
}




void DrawESP(ImDrawList *draw) {
if (g_LocalController == 0){
   } else {
    }

	 if (LobbyBy) {
MemoryPatch::createWithHex("libanogs.so",0x4CE40, "00 20 70 47").Modify();
            	}   
		
    if (Config.OTHER.HIDEESP) {
        HIDEESP = false;
    } else {
        HIDEESP = true;
    }
    if (HIDEESP) {

            auto Actors = getActors();

    int totalEnemies = 0, totalBots = 0;

    ASTExtraPlayerCharacter *localPlayer = 0;
    ASTExtraPlayerController *localController = 0;
    
if (Config.AimBot.Enable) {
            draw->AddText({((float) density / 10.0f), 70}, IM_COL32(0, 255, 0, 255),
                          "AimSimukation 2.0 ~ Enable");
            }else{
            draw->AddText({((float) density / 10.0f), 70}, IM_COL32(255, 0, 0, 255),
                          "AimSimukation 2.0 ~ Disable");
        }

draw->AddText(NULL, ((float) density / 15.0f),{(float) glWidth / 150 + glWidth / 20,610},IM_COL32(0, 0, 255, 255),
                          "TELEGRAM - @TRSHACK");
/*draw->AddText(NULL, ((float) density / 15.0f),{(float) glWidth / 150 + glWidth / 20,640},IM_COL32(0,255,255, 255),
                          "For FEEDBACK Hack Contact to @Owner_Admnn");*/
	
	
		
/* draw->AddText(NULL, ((float) density / 15.0f),{(float) glWidth / 2 + glWidth / 30,15},IM_COL32(0, 255, 0, 250),
                            " EXPIRY KEY :-  ");
    
draw->AddText(NULL, ((float) density / 15.0f),{(float) glWidth / 2 + glWidth / 6,15},IM_COL32(255, 0, 0, 250),EXP.c_str());*/
 

      

//draw->AddText(NULL, ((float) density / 20.0f),{(float) glWidth / 180 + glWidth / 40,200}, IM_COL32(255,255,0, 255),floating.c_str());
        /*if (Config.Bypass) {
            draw->AddText({((float) density / 10.0f), 40}, IM_COL32(0, 255, 0, 255),
                          "BYPASS ON");
			}else{
		draw->AddText({((float) density / 10.0f), 40}, IM_COL32(255, 0, 0, 255),
                          "BYPASS OFF");
        }*/     

    for (int i = 0; i < Actors.size(); i++) {
        auto Actor = Actors[i];
        if (isObjectInvalid(Actor))
            continue;

        if (Actor->IsA(ASTExtraPlayerController::StaticClass())) {
            localController = (ASTExtraPlayerController *) Actor;
            break;
        }
    }

    if (localController) {
        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                if (((ASTExtraPlayerCharacter *) Actor)->PlayerKey == localController->PlayerKey) {
                    localPlayer = (ASTExtraPlayerCharacter *) Actor;
                    break;
                }
            }
        }


        if (localPlayer) {
            if (localPlayer->PartHitComponent) {
                auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
                for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
                    ConfigCollisionDistSqAngles[j].Angle = 90.0f;
                }
                localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
            }
                ///===================== Memory Function ====================//
                        if (Config.SilentAim.Enable) {
                         draw->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), Config.SilentAim.Cross*0.5f, ToColor(Config.ColorsESP.Fov), 100, 1.0f);
                    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                    if (WeaponManagerComponent) {
                        auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                        if ((int) propSlot.GetValue() >= 1 && (int) propSlot.GetValue() <= 3) {
                            auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                            if (CurrentWeaponReplicated) {
                                auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                if (ShootWeaponComponent) {
                                    int shoot_event_idx = 162;
                                    auto VTable = (void **) ShootWeaponComponent->VTable;
                                    if (VTable && (VTable[shoot_event_idx] != shoot_event)) {
                                        orig_shoot_event = decltype(orig_shoot_event)(
                                                VTable[shoot_event_idx]);
                                        VTable[shoot_event_idx] = (void *) shoot_event;
                                    }
                                }
                            }
                        }
                    }
                }

                //Aimbot//
                
                //ايم بوت
							 if (Config.AimBot.Less) {
                    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                    if (WeaponManagerComponent) {
                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                        if (CurrentWeaponReplicated) {
                            auto ShootWeaponEntityComp = CurrentWeaponReplicated->ShootWeaponEntityComp;
                            auto ShootWeaponEffectComp = CurrentWeaponReplicated->ShootWeaponEffectComp;
                            if (ShootWeaponEntityComp && ShootWeaponEffectComp) {
                                if (Config.AimBot.Less) {
                                    ShootWeaponEntityComp->AccessoriesVRecoilFactor = 0.190f;
                                    ShootWeaponEntityComp->AccessoriesHRecoilFactor = 0.190f;
                                    ShootWeaponEntityComp->AccessoriesRecoveryFactor = 0.190f;

                                }
                            }
                        }
                    }
                }		
                
                
                if (Config.SilentAim.Enable) { //Config True
   auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
         if (WeaponManagerComponent) {
  auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
  if ((int) propSlot.GetValue() >= 1 && (int) propSlot.GetValue() <= 3) {
   auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
              if (CurrentWeaponReplicated) {
   auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
               if (ShootWeaponComponent) {
              int shoot_event_idx = 165;
        auto f_mprotect = [](uintptr_t addr, size_t len, int32_t prot) -> int32_t {
             static_assert(PAGE_SIZE == 4096);
     constexpr size_t page_size = static_cast<size_t>(PAGE_SIZE);
           void* start = // Reference Address of Start 
reinterpret_cast<void*>(addr & -page_size);
        uintptr_t end = (addr + len + page_size - 1) & -page_size;
        return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
                                    };
              auto VTable = (void **) ShootWeaponComponent->VTable;
               if (VTable && (VTable[shoot_event_idx] != shoot_event)) {
               orig_shoot_event = decltype(orig_shoot_event)(
                         VTable[shoot_event_idx]);
          f_mprotect((uintptr_t)(&VTable[shoot_event_idx]), sizeof(uintptr_t), PROT_READ | PROT_WRITE);
             VTable[shoot_event_idx] = (void *) shoot_event;
                                    }
                     }   
         }  
      } 
   }   
}
                
                
				
				if (Config.AimBot.Enable)
    {
    
    
     ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
     if (Target)
     {
      bool triggerOk = false;
      if (Config.AimBot.Trigger != EAimTrigger::None)
      {
       if (Config.AimBot.Trigger == EAimTrigger::Shooting)
       {
        triggerOk = g_LocalPlayer->bIsWeaponFiring;
       }
       else if (Config.AimBot.Trigger == EAimTrigger::Scoping)
       {
        triggerOk = g_LocalPlayer->bIsGunADS;
       }
       else if (Config.AimBot.Trigger == EAimTrigger::Both)
       {
        triggerOk = g_LocalPlayer->bIsWeaponFiring && g_LocalPlayer->bIsGunADS;
       }
       else if (Config.AimBot.Trigger == EAimTrigger::Any)
       {
        triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
       }
      }
      else
       triggerOk = true;
      if (triggerOk)
      {
      FVector targetAimPos = Target->GetBonePos("Head", {});
                        targetAimPos.Z += 9.f;
                       if (Config.SilentAim.Target == EAimTarget::Chest) {
                       
                       targetAimPos.Z -= 10.0f;
                    
                    }
                    
                       
          
         auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
       if (WeaponManagerComponent)
       {
        auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
        if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3)
        {
         auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
         if (CurrentWeaponReplicated)
         {
          auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
          if (ShootWeaponComponent)
          {
           UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
           if (ShootWeaponEntityComponent)
           {
           
          
            ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
            if (CurrentVehicle)
            {
             FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
             float dist = localPlayer->GetDistanceTo(Target) ;
    //         auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed ;
           //  targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
             
             
            }
            else
            {
             FVector Velocity = Target->GetVelocity();
             float dist = localPlayer->GetDistanceTo(Target) ;
      //       auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;
         //    targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
             
             
            }
            
            if (Config.Recc) {
                            if (g_LocalPlayer->bIsGunADS) {
                               if (g_LocalPlayer->bIsWeaponFiring) {
                                float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                targetAimPos.Z -= dist * Config.Recc;        
                                
                                                   }
                                                   
                                                       }       
                                }  
                                
                              
            
            
            localController->SetControlRotation(ToRotator(localController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos),"");
           }
          }
         }
        }
       }
      }
     }
    }
				
				
                  								
                  												
                  																				
                    for (int i = 0; i < Actors.size(); i++) {
                auto Actor = Actors[i];
                if (isObjectInvalid(Actor))
                    continue;

                         if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                            auto Player = (ASTExtraPlayerCharacter *) Actor;

                            float Distance = localPlayer->GetDistanceTo(Player) /100.0f;
                            if (Distance > 500.0f)
                                continue;

                            if (Player->PlayerKey == localController->PlayerKey)
                                continue;

                            if (Player->TeamID == localController->TeamID)
                                continue;

                            if (Player->bDead)
                                continue;

                            //if (!Player->Mesh)
                               // continue;
                                
                            bool IsVisible = localController->LineOfSightTo(Player, {0, 0, 0}, true);

                            int SCOLOR;
                            int SCOLOR2;
                            int SCOLO;

                            if (IsVisible)
                            {
                            SCOLOR = IM_COL32(0, 255, 0, 255);
                            SCOLOR2 = IM_COL32(0, 255, 0, 25);
                            SCOLO = IM_COL32(255, 100, 0, 100);
                            }else{
                            SCOLOR = IM_COL32(255, 0, 0, 255);
                            SCOLOR2 = IM_COL32(255, 0, 0, 25);
                            SCOLO = IM_COL32(0, 0, 0, 100);
                            }
                            
                            
                           int Colorhealth;
						int healthOutline;
                        if (Player->bIsAI)
						   {
                            totalBots++;
							Colorhealth = IM_COL32(0, 255, 0, 90);
							healthOutline = IM_COL32(0, 255, 174, 255);
						    }
                        else 
						    {
							totalEnemies++;
							Colorhealth = IM_COL32(255, 100, 0, 100);
							healthOutline = IM_COL32(255, 0, 0, 255);
							
							}
							///int SCOLOR3;

                                              if (Player->bIsAI)
                                              {
                                              SCOLO = IM_COL32(0, 255, 0, 90);
                                              }

		            if (Config.PlayerESP.Alert){
bool shit = false;
                            FVector MyPosition, EnemyPosition;
                            ASTExtraVehicleBase * CurrentVehiclea = Player->CurrentVehicle;
                            if (CurrentVehiclea) {
                                MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                            } else {
                                MyPosition = Player->RootComponent->RelativeLocation;
                            }
                            ASTExtraVehicleBase * CurrentVehicle = localPlayer->CurrentVehicle;
                            if (CurrentVehicle) {
                                EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                            } else {
                                EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                            }
                            FVector EntityPos = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, NULL, NULL, Vector3(glWidth, glHeight, 0), shit);
                            FVector angle = FVector();
                            Vector3 forward = Vector3((float)(glWidth / 2) - EntityPos.X, (float)(glHeight / 2) - EntityPos.Y, 0.0f);
                            VectorAnglesRadar(forward, angle);
                            const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
                            const auto new_point_x = (glWidth / 2) + (55/*alert dist from me*/) / 2 * 8 * cosf(angle_yaw_rad);
                            const auto new_point_y = (glHeight / 2) + (55/*alert dist from me*/) / 2 * 8 * sinf(angle_yaw_rad);
                            std::array<Vector3, 3> points { Vector3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((55) / 4 + 3.5f) / 2, 0.f), Vector3(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f), Vector3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((55) / 4 + 3.5f) / 2, 0.f)};
                            RotateTriangle(points, angle.Y + 180.f);
                                                    draw->AddTriangle(ImVec2(points.at(0).X, points.at(0).Y), ImVec2(points.at(1).X, points.at(1).Y), ImVec2(points.at(2).X, points.at(2).Y), SCOLOR, 1.5f);
       draw->AddTriangleFilled(ImVec2(points.at(0).X, points.at(0).Y), ImVec2(points.at(1).X, points.at(1).Y), ImVec2(points.at(2).X, points.at(2).Y), SCOLOR);
       }
       
       
       
       if (Config.PlayerESP.WeaponId) {
        auto WeaponManagerComponent = Player->WeaponManagerComponent;
        if (WeaponManagerComponent) {
            {
          auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
          if (CurrentWeaponReplicated) {
           auto WeaponId = (int)CurrentWeaponReplicated->GetWeaponID();
           if (WeaponId) {
            std::string s;
            s += CurrentWeaponReplicated->GetWeaponName().ToString();
            auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, ((float) density / 30.0f));
            //draw->AddText(NULL, ((float) density / 30.0f), {RootPosSC.x - (textSize.x / 2), RootPosSC.y}, IM_COL32(255, 255, 255, 255), s.c_str());
           }
          }
         }
        }
       }

	 	// if (Bypass) {Write<float>(UE4 + 0x6B29A38, 0);}
	   
			if (Config.PlayerESP.Radar) {          
bool out = false;                              
                     struct Vector3 Pos;
                     Pos.X = screenWidth / 4.395;
                     Pos.Y = screenHeight / 200;
                     struct Vector3 Size;
                     Size.X = 200; //Width of Radar Box.
                     Size.Y = 210; //Height of Radar Box.
                     float RadarCenterX = Pos.X + (Size.X / 2);
                     float RadarCenterY = Pos.Y + (Size.Y / 2);
                     ImColor CircleColor = ImColor(0, 0, 0, 20);
                     ImColor PointColor = ImColor(255, 255, 255, 150);
                     draw->AddLine(ImVec2(RadarCenterX, RadarCenterY), ImVec2(RadarCenterX, Pos.Y), IM_COL32(255, 000, 000, 0), 0.f);
                     draw->AddLine(ImVec2(RadarCenterX, RadarCenterY), ImVec2(Pos.X , RadarCenterY), IM_COL32(255, 000, 000, 0), 0.f);
                     draw->AddLine(ImVec2(Pos.X, RadarCenterY), ImVec2(Pos.X + Size.X, RadarCenterY), IM_COL32(255, 000, 000, 0), 0.f);
                     draw->AddLine(ImVec2(RadarCenterX, RadarCenterY), ImVec2(RadarCenterX, Pos.Y + Size.Y), IM_COL32(255, 000, 000, 0), 0.f);
                            
                     draw->AddCircleFilled(ImVec2(RadarCenterX, RadarCenterY), 100.f, CircleColor, 1000); //Background
                     draw->AddCircle(ImVec2(RadarCenterX, RadarCenterY), 100.f, PointColor, 1000);
                     draw->AddCircle(ImVec2(RadarCenterX, RadarCenterY), 80.f, PointColor, 1000);
                     draw->AddCircle(ImVec2(RadarCenterX, RadarCenterY), 60.f, PointColor, 1000);
                     draw->AddCircle(ImVec2(RadarCenterX, RadarCenterY), 25.f, PointColor, 1000);
                     draw->AddCircleFilled(ImVec2(RadarCenterX + 0.5f, RadarCenterY + 0.5f), 3.f, PointColor, 1000);
                 }
                 
                 
                 if (Config.PlayerESP.Radar) 
					 {
                      FVector MyPosition;
                      ASTExtraVehicleBase *CurrentVehiclea = Player->CurrentVehicle;
                 if (CurrentVehiclea) {
                      MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                       } else {
                      MyPosition = Player->RootComponent->RelativeLocation;
                       }                                     
                      FVector EnemyPosition;
                      ASTExtraVehicleBase *CurrentVehicle = localPlayer->CurrentVehicle;
                 if (CurrentVehicle) {
                      EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                       }  else {
                      EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                }
               bool out = false;                              
               struct Vector3 Pos;
               Pos.X = screenWidth / 4.395;
               Pos.Y = screenHeight / 200;
               struct Vector3 Size;
               Size.X = 200; //Width of Radar Box.
               Size.Y = 210; //Height of Radar Box.
               float RadarCenterX = Pos.X + (Size.X / 2);
               float RadarCenterY = Pos.Y + (Size.Y / 2);                                    
                                                   
               bool IsVisible = true;
               FVector RadarSketch = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, Pos.X, Pos.Y, Vector3(Size.X, Size.Y, 0), out);
                                if (Distance >= 0.f) {
                                
                                draw->AddCircleFilled(ImVec2(RadarSketch.X, RadarSketch.Y), 5, SCOLOR, 0.0f);
                 
             }
}
                    if (Config.PlayerESP.NoBot)
                        if (Player->bIsAI)
                            continue;

                    auto HeadPos = Player->GetBonePos("Head", {});
                            HeadPos.Z = HeadPos.Z + 12.5f; //head se line ooper
                            ImVec2 headPosSC;

                            auto RootPos = Player->GetBonePos("Root", {});
                            ImVec2 RootPosSC;
                            if (W2S(HeadPos, (FVector2D *) &headPosSC) && W2S(RootPos, (FVector2D *) &RootPosSC)) {
							
				    float magic_number = (Distance);
                    float mx = (glWidth / 4) / magic_number;

                    float healthLength = glWidth / 17;
                    if (healthLength < mx)
                        healthLength = mx;
						
						if (Config.PlayerESP.LineTop) {
						draw->AddLine({(float) glWidth / 2, 90}, headPosSC,
                                                  SCOLOR, 0.2f);
                    } 
										
							if (Config.PlayerESP.Skeleton) {
                                // ESP Head
                                static std::vector<std::string> right_arm{"neck_01",
                                                                              "clavicle_r",
                                                                              "upperarm_r",
                                                                              "lowerarm_r",
                                                                              "hand_r", "item_r"};
                                    static std::vector<std::string> left_arm{"neck_01",
                                                                             "clavicle_l",
                                                                             "upperarm_l",
                                                                             "lowerarm_l",
                                                                             "hand_l", "item_l"};
                                    static std::vector<std::string> spine{"Head", "neck_01",
                                                                          "spine_03",
                                                                          "spine_02", "spine_01",
                                                                          "pelvis"};
                                    static std::vector<std::string> lower_right{"pelvis", "thigh_r",
                                                                                "calf_r", "foot_r"};
                                    static std::vector<std::string> lower_left{"pelvis", "thigh_l",
                                                                               "calf_l", "foot_l"};
                                    static std::vector<std::vector<std::string>> skeleton{right_arm,
                                                                                          left_arm,
                                                                                          spine,
                                                                                          lower_right,
                                                                                          lower_left};

                                    for (auto &boneStructure: skeleton) {
                                        std::string lastBone;
                                        for (std::string &currentBone: boneStructure) {
                                            if (!lastBone.empty()) {
                                                ImVec2 boneFrom, boneTo;
                                                if (W2S(Player->GetBonePos(lastBone.c_str(), {}),
                                                        (FVector2D *) &boneFrom) &&
                                                    W2S(Player->GetBonePos(currentBone.c_str(), {}),
                                                        (FVector2D *) &boneTo)) {
                                                    draw->AddLine(boneFrom, boneTo,
                                                                SCOLOR, Config.Skeleton);
                                                }
                                            }
                                            lastBone = currentBone;
                                        }
                                    }              	 
								}
				    	
				                	if (Config.PlayerESP.Box3D) {
                            float boxHeight = abs(headPosSC.y - RootPosSC.y);
                                    float boxWidth = boxHeight * 0.65f;
                                    ImVec2 vStart = {headPosSC.x - (boxWidth / 2), headPosSC.y};
                                    ImVec2 vEnd = {vStart.x + boxWidth, vStart.y + boxHeight};

                                    draw->AddRect(vStart, vEnd, SCOLOR, 1.5f, 240, 1.7f);
                                    draw->AddRectFilled(vStart, vEnd, SCOLOR2, 1.5f, 240);
                                }
                                     
				                	if (Config.PlayerESP.Name || Config.PlayerESP.Distance) {
                                    DrawBoxEnemy(draw, ImVec2(headPosSC.x , headPosSC.y - 25), ImVec2(headPosSC.x , headPosSC.y - 25), 22, IM_COL32(0, 0, 0, 255));
                               }
						       /*if (Config.ESPMenu.Name) {
                                    std::string s;
                                    int NameColor;
                                    float a = 5;

                                    if (Player->bIsAI) {
                                        NameColor = IM_COL32(0, 255, 0, 255);
										s += std::to_string((int) Player->TeamID);
                                        s += "  [BOT] ";								    
                                    } else {
                                        NameColor = IM_COL32(255, 255, 100, 255);
                                        s += "[";
                                        s += std::to_string((int) Player->TeamID);
                                        s += "] ";
                                        s += Player->PlayerName.ToString();
                                    }
                                    draw->AddText(NULL, 15.f, ImVec2(headPosSC.x  + a, headPosSC.y - 35.0f), NameColor, s.c_str());
                                }*/
                                if (Config.PlayerESP.Health) {
                                                int CurHP = (int) std::max(0, std::min(
                                                        (int) Player->Health,
                                                        (int) Player->HealthMax));
                                                int MaxHP = (int) Player->HealthMax;

                                            
														
												  long HPColor;
                                                    if (Player->Health < 25)
                                                       HPColor = IM_COL32(0, 203, 255, 110);
                                                 else if (Player->Health < 50)
                                                       HPColor = IM_COL32(255, 0, 233, 120);
                                                 else if ( Player->Health < 75)
                                                       HPColor = IM_COL32(255, 0, 233, 120);
                                                  else
                                                       HPColor = SCOLO;

                                                //if (Config.PlayerESP.ShowKnockedHealth) {
                                                if (Player->Health == 0.0f && !Player->bDead) {
                                                   SCOLOR = IM_COL32(250, 0, 0, 80);
                                                   
                                                    HPColor = IM_COL32(255, 0, 0, 110);

                                                    CurHP = Player->NearDeathBreath;
                                                    if (Player->NearDeatchComponent) {
                                                        MaxHP = Player->NearDeatchComponent->BreathMax;
                                                    }
                                                }
                                                //}

                                                float boxWidth = density / 1.6f;
                                                boxWidth -= std::min(
                                                        ((boxWidth / 2) / 0.001f) * Distance,
                                                        boxWidth / 2);
                                                float boxHeight = boxWidth * 0.15f;


                                                ImVec2 vStart = {headPosSC.x - (boxWidth / 2),
                                                                 headPosSC.y -
                                                                 (boxHeight * 2.001f)};

                                                ImVec2 vEndFilled = {
                                                        vStart.x + (CurHP * boxWidth / MaxHP),
                                                        vStart.y + boxHeight};
                                                ImVec2 vEndRect = {vStart.x + boxWidth,
                                                                   vStart.y + boxHeight};

                                                draw->AddRectFilled(vStart, vEndFilled, HPColor,
                                                                    10.0f);
                                                draw->AddRect(vStart, vEndRect,
                                                              SCOLO, 10.0f);
                                            }
                              if (Config.PlayerESP.Name || Config.PlayerESP.Name || Config.PlayerESP.Distance) {
                                    float boxWidth = density / 1.6f; // width
                                boxWidth -= std::min(((boxWidth / 2) / 00.0f) * Distance,
                                                     boxWidth / 2);
                                float boxHeight = boxWidth * 0.15f;
                                    std::string s;
                                    
                                    

                                    if (Config.PlayerESP.TeamID) {
                                       
                                        s += std::to_string(Player->TeamID);
                                        s += " ";
                                   
                                    }

                                    if (Config.PlayerESP.Name) {
                                        if (Player->bIsAI) {                                       
                                        s += "  BOT ";
                                        
                                    } else {
                                    
                                  
                                       s += Player->PlayerName.ToString();
                                        }
                                    }

                                    if (Config.PlayerESP.Distance) {
                                        if (!s.empty()) {
                                            s += " ";
                                        }
                                        s += std::to_string((int)Distance);
                                        s += "m";
                                    }
                         
												  
							auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, ((float) density / 30.0f));
                            draw->AddText(NULL, ((float) density / 30.0f), {headPosSC.x - (textSize.x / 2), headPosSC.y - (boxHeight * 1.83f)}, IM_COL32(255, 255, 255, 255), s.c_str());

                        }
                    }
                }
                

					//اوت

                if (Actors[i]->IsA(APickUpWrapperActor::StaticClass())) {
                            auto PickUp = (APickUpWrapperActor *) Actors[i];
                            if (Items[PickUp->DefineID.TypeSpecificID]) {
														
                                auto RootComponent = PickUp->RootComponent;
                                if (!RootComponent)
                                    continue;

                                float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;

                                FVector2D itemPos;
                                if (W2S(PickUp->K2_GetActorLocation(), &itemPos)) {
                                    std::string s;
                                    uint32_t tc = 0xFF000000;
									
                                    for (auto &category : items_data) {
                                         for (auto &item : category["Items"]) {
                                             if (item["itemId"] ==
                                                 PickUp->DefineID.TypeSpecificID) {
                                                 s = item["itemName"].get<std::string>();
                                                 tc = strtoul(
                                                 item["itemTextColor"].get<std::string>().c_str(),
                                                 0,
                                                 16);
                                                 break;
                                              }
                                         }
                                    }
                                    s += " - ";
                                    s += std::to_string((int) Distance);
                                    s += "m";
                                                        
									draw->AddText(NULL, ((float) density / 25.0f),
                                                              {itemPos.X, itemPos.Y},
                                                              tc, s.c_str());
                           }
                      }
                }
					                
						
				if (Config.PlayerESP.LootBox) 
     {
                            if (Actor->IsA(APickUpListWrapperActor::StaticClass())) {
                                auto LootBox = (APickUpListWrapperActor *) Actor;
                                auto RootComponent = Actor->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = LootBox->GetDistanceTo(localPlayer) / 100.f;

                                FVector2D lootboxPos;
        if (Config.PlayerESP.LootBox) {
                                    FVector Hunt;
                            Hunt.X = 70.0f; 
                            Hunt.Y = 70.0f; // Front
                            Hunt.Z = 35.0f; // Height
                                Box3D1(draw, LootBox->K2_GetActorLocation(), Hunt, IM_COL32(0, 255, 0, 250));       
                                } 
                                if (W2S(LootBox->K2_GetActorLocation(), &lootboxPos)) {
                                    std::string s = ICON_FA_ARCHIVE"";
                                    s += " [";
                                    s += std::to_string((int) Distance);
                                    s += "M]";

                                    draw->AddText(NULL, ((float) density / 15.0f),
                                                  {lootboxPos.X, lootboxPos.Y},
                                                  IM_COL32(255, 0, 0, 255), s.c_str());
                                }
                            }
                        }
                        
                               	if (Config.PlayerESP.Grenade) {
						if (Actors[i]->IsA(ASTExtraGrenadeBase::StaticClass())) {
							auto Grenade = (ASTExtraGrenadeBase *) Actors[i];
							auto RootComponent = Grenade->RootComponent;
							if (!RootComponent)
								continue;
							float Distance = Grenade->GetDistanceTo(localPlayer) / 70.f;
							FVector2D grenadePos;
							if (W2S(Grenade->K2_GetActorLocation(), & grenadePos)) {
								std::string s = std::to_string((int) Distance);
								s += " m";
								std::string t;
								t += "!!!...MOVE  MOVE  MOVE...!!!";
								auto textSize = ImGui::CalcTextSize2(t.c_str(), 0, ((float) density / 17.0f));
								draw->AddText(NULL, ((float) density / 17.0f), ImVec2(glWidth / 2 - (textSize.x / 2), 110), IM_COL32(255, 0, 0, 220), t.c_str());
								draw->AddText(NULL, ((float) density / 25.0f), {grenadePos.X - 10, grenadePos.Y - 10}, IM_COL32(0, 0, 255, 255), s.c_str());
								draw->AddCircleFilled(ImVec2(grenadePos.X, grenadePos.Y), glHeight / (float) 1080 * 20, IM_COL32(255, 0, 0, 255), 0);
							}
						}
					}
					
					
                            if (Config.PlayerESP.Vehicle || Config.PlayerESP.VehicleFuel || Config.PlayerESP.VehicleHP)
					{
					if (Actors[i]->IsA(ASTExtraVehicleBase::StaticClass()))
                        {
                            auto Vehicle = (ASTExtraVehicleBase *)Actors[i];
                            if (!Vehicle->Mesh)
                                continue;
                            int CurHP = (int) std::max(0, std::min((int) Vehicle->VehicleCommon->HP, (int) Vehicle->VehicleCommon->HPMax));
                            int MaxHP = (int) Vehicle->VehicleCommon->HPMax;
                            long curHP_Color = IM_COL32(std::min(((510 * (MaxHP - CurHP)) / MaxHP), 255), std::min(((510 * CurHP) / MaxHP), 255), 0, 155);
                            float Distance = Vehicle->GetDistanceTo(localPlayer) / 100.f;
                            FVector2D vehiclePos;
                            if (W2S(Vehicle->K2_GetActorLocation(), &vehiclePos))
                            {
                                auto mWidthScale = std::min(0.10f * Distance, 50.f);
                                auto mWidth = 70.f - mWidthScale;
                                auto mHeight = mWidth * 0.15f;
                                if (Config.PlayerESP.Vehicle)
                                {
                                    std::string s = GetVehicleName(Vehicle);
                                    s += ICON_FA_CAR" [";
                                    s += std::to_string((int)Distance);
                                    s += "]";
                                    draw->AddText(NULL, ((float)density / 30.0f), {vehiclePos.X - (mWidth / 2), vehiclePos.Y}, ToColor(Config.ColorsESP.Vehicle), s.c_str());
                                }
                                if (Config.PlayerESP.Vehicle) {
                                    std::string sf;
                                    sf += "[Fuel:";
                                    sf += std::to_string((int)(100 * Vehicle->VehicleCommon->Fuel / Vehicle->VehicleCommon->FuelMax));
                                    sf += "]";
                                    draw->AddText(NULL, ((float)density / 30.0f), {vehiclePos.X - (mWidth / 2), vehiclePos.Y + 15.f}, IM_COL32(255, 255, 0, 255), sf.c_str());
                                }
                                if (Config.PlayerESP.Vehicle)
                                {
                                    ImVec2 vStart = {vehiclePos.X - (mWidth / 2), vehiclePos.Y - (mHeight * 1.5f)};
                                    ImVec2 vEndFilled = {vStart.x + (CurHP * mWidth / MaxHP), vStart.y + mHeight};
                                    ImVec2 vEndRect = {vStart.x + mWidth, vStart.y + mHeight};
                                    draw->AddRectFilled(vStart, vEndFilled, curHP_Color, 3.2f, 240);
                                    draw->AddRect(vStart, vEndRect, IM_COL32(000, 000, 000, 255), 3.2f, 240);
                                }
                             }
                             }
                             }
                            }}} 

         g_LocalController = localController;
    g_LocalPlayer = localPlayer;

    g_LocalController = localController;
    g_LocalPlayer = localPlayer;

       ImGui::GetForegroundDrawList()->AddRectFilled({glWidth /2-50,40},{glWidth /2,80},ImColor(255, 0, 0,110));
       ImGui::GetForegroundDrawList()->AddRectFilled({glWidth /2+50,40},{glWidth /2,80},ImColor(3, 255, 40,110)); 
       sprintf(extras, "%d", totalEnemies);
       ImGui::GetForegroundDrawList()->AddText({glWidth /2-35,45}, ImColor(255,255,255), extras);
       sprintf(extras, "%d", totalBots);
       ImGui::GetForegroundDrawList()->AddText({glWidth /2+15,45}, ImColor(255,255,255), extras);
                    

	               if (Config.AimBot.Enable) {
draw->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), Config.AimBot.Cross*0.5f, ToColor(Config.ColorsESP.Fov), 100, 1.0f);
}
        fps.update();
    }
}

// ======================================================================== //// ======================================================================== //

    std::string getClipboardText() {
    if (!g_App)
        return "";

    auto activity = g_App->activity;
    if (!activity)
        return "";

    auto vm = activity->vm;
    if (!vm)
        return "";

    auto object = activity->clazz;
    if (!object)
        return "";

    std::string result;

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    {
        auto ContextClass = env->FindClass("android/content/Context");
        auto getSystemServiceMethod = env->GetMethodID(ContextClass, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");

        auto str = env->NewStringUTF("clipboard");
        auto clipboardManager = env->CallObjectMethod(object, getSystemServiceMethod, str);
        env->DeleteLocalRef(str);

        auto ClipboardManagerClass = env->FindClass("android/content/ClipboardManager");
        auto getText = env->GetMethodID(ClipboardManagerClass, "getText", "()Ljava/lang/CharSequence;");

        auto CharSequenceClass = env->FindClass("java/lang/CharSequence");
        auto toStringMethod = env->GetMethodID(CharSequenceClass, "toString", "()Ljava/lang/String;");

        auto text = env->CallObjectMethod(clipboardManager, getText);
        if (text) {
            str = (jstring) env->CallObjectMethod(text, toStringMethod);
            result = env->GetStringUTFChars(str, 0);
            env->DeleteLocalRef(str);
            env->DeleteLocalRef(text);
        }

        env->DeleteLocalRef(CharSequenceClass);
        env->DeleteLocalRef(ClipboardManagerClass);
        env->DeleteLocalRef(clipboardManager);
        env->DeleteLocalRef(ContextClass);
    }
    vm->DetachCurrentThread();

    return result;
}

const char *GetAndroidID(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
    jmethodID getContentResolverMethod = env->GetMethodID(contextClass, /*getContentResolver*/ StrEnc("E8X\\7r7ys_Q%JS+L+~", "\x22\x5D\x2C\x1F\x58\x1C\x43\x1C\x1D\x2B\x03\x40\x39\x3C\x47\x3A\x4E\x0C", 18).c_str(), /*()Landroid/content/ContentResolver;*/ StrEnc("8^QKmj< }5D:9q7f.BXkef]A*GYLNg}B!/L", "\x10\x77\x1D\x2A\x03\x0E\x4E\x4F\x14\x51\x6B\x59\x56\x1F\x43\x03\x40\x36\x77\x28\x0A\x08\x29\x24\x44\x33\x0B\x29\x3D\x08\x11\x34\x44\x5D\x77", 35).c_str());
    jclass settingSecureClass = env->FindClass(/*android/provider/Settings$Secure*/ StrEnc("T1yw^BCF^af&dB_@Raf}\\FS,zT~L(3Z\"", "\x35\x5F\x1D\x05\x31\x2B\x27\x69\x2E\x13\x09\x50\x0D\x26\x3A\x32\x7D\x32\x03\x09\x28\x2F\x3D\x4B\x09\x70\x2D\x29\x4B\x46\x28\x47", 32).c_str());
    jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, /*getString*/ StrEnc("e<F*J5c0Y", "\x02\x59\x32\x79\x3E\x47\x0A\x5E\x3E", 9).c_str(), /*(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;*/ StrEnc("$6*%R*!XO\"m18o,0S!*`uI$IW)l_/_knSdlRiO1T`2sH|Ouy__^}%Y)JsQ:-\"(2_^-$i{?H", "\x0C\x7A\x4B\x4B\x36\x58\x4E\x31\x2B\x0D\x0E\x5E\x56\x1B\x49\x5E\x27\x0E\x69\x0F\x1B\x3D\x41\x27\x23\x7B\x09\x2C\x40\x33\x1D\x0B\x21\x5F\x20\x38\x08\x39\x50\x7B\x0C\x53\x1D\x2F\x53\x1C\x01\x0B\x36\x31\x39\x46\x0C\x15\x43\x2B\x05\x30\x15\x41\x43\x46\x55\x70\x0D\x59\x56\x00\x15\x58\x73", 71).c_str());

    auto obj = env->CallObjectMethod(context, getContentResolverMethod);
    auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj, env->NewStringUTF(/*android_id*/ StrEnc("ujHO)8OfOE", "\x14\x04\x2C\x3D\x46\x51\x2B\x39\x26\x21", 10).c_str()));
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceModel(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("m5I{GKGWBP-VOxkA", "\x0C\x5B\x2D\x09\x28\x22\x23\x78\x2D\x23\x02\x14\x3A\x11\x07\x25", 16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*MODEL*/ StrEnc("|}[q:", "\x31\x32\x1F\x34\x76", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceBrand(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("0iW=2^>0zTRB!B90", "\x51\x07\x33\x4F\x5D\x37\x5A\x1F\x15\x27\x7D\x00\x54\x2B\x55\x54", 16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*BRAND*/ StrEnc("@{[FP", "\x02\x29\x1A\x08\x14", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetPackageName(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
    jmethodID getPackageNameId = env->GetMethodID(contextClass, /*getPackageName*/ StrEnc("YN4DaP)!{wRGN}", "\x3E\x2B\x40\x14\x00\x33\x42\x40\x1C\x12\x1C\x26\x23\x18", 14).c_str(), /*()Ljava/lang/String;*/ StrEnc("VnpibEspM(b]<s#[9cQD", "\x7E\x47\x3C\x03\x03\x33\x12\x5F\x21\x49\x0C\x3A\x13\x20\x57\x29\x50\x0D\x36\x7F", 20).c_str());

    auto str = (jstring) env->CallObjectMethod(context, getPackageNameId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
    jclass uuidClass = env->FindClass(/*java/util/UUID*/ StrEnc("B/TxJ=3BZ_]SFx", "\x28\x4E\x22\x19\x65\x48\x47\x2B\x36\x70\x08\x06\x0F\x3C", 14).c_str());

    auto len = strlen(uuid);

    jbyteArray myJByteArray = env->NewByteArray(len);
    env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);

    jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, /*nameUUIDFromBytes*/ StrEnc("P6LV|'0#A+zQmoat,", "\x3E\x57\x21\x33\x29\x72\x79\x67\x07\x59\x15\x3C\x2F\x16\x15\x11\x5F", 17).c_str(), /*([B)Ljava/util/UUID;*/ StrEnc("sW[\"Q[W3,7@H.vT0) xB", "\x5B\x0C\x19\x0B\x1D\x31\x36\x45\x4D\x18\x35\x3C\x47\x1A\x7B\x65\x7C\x69\x3C\x79", 20).c_str());
    jmethodID toStringMethod = env->GetMethodID(uuidClass, /*toString*/ StrEnc("2~5292eW", "\x46\x11\x66\x46\x4B\x5B\x0B\x30", 8).c_str(), /*()Ljava/lang/String;*/ StrEnc("P$BMc' #j?<:myTh_*h0", "\x78\x0D\x0E\x27\x02\x51\x41\x0C\x06\x5E\x52\x5D\x42\x2A\x20\x1A\x36\x44\x0F\x0B", 20).c_str());

    auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
    auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
    return env->GetStringUTFChars(str, 0);
}

struct MemoryStruct {
    char *memory;
    size_t size;
};
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;

    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

std::string Login(const char *user_key) {
    if (!g_App)
        return "Internal Error";

    auto activity = g_App->activity;
    if (!activity)
        return "Internal Error";

    auto vm = activity->vm;
    if (!vm)
        return "Internal Error";

    auto object = activity->clazz;
    if (!object)
        return "Internal Error";

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);

    std::string hwid = user_key;
    hwid += GetAndroidID(env, object);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);

    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());

    vm->DetachCurrentThread();

    std::string errMsg;

    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;
//https://bantai.vipbombay.online/connect

//https://bantai.vipbombay.online/
    CURL *curl;
        CURLcode res;
        curl = curl_easy_init();
        if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, /*POST*/ StrEnc(",IL=", "\x7C\x06\x1F\x69", 4).c_str());
        std::string sRedLink = "https://freepanal.000webhostapp.com/connect";

        curl_easy_setopt(curl, CURLOPT_URL, sRedLink.c_str());

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, /*https*/ StrEnc("!mLBO", "\x49\x19\x38\x32\x3C", 5).c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, /*Content-Type: application/x-www-form-urlencoded*/ StrEnc("@;Ls\\(KP4Qrop`b#d3094/r1cf<c<=H)AiiBG6i|Ta66s2[", "\x03\x54\x22\x07\x39\x46\x3F\x7D\x60\x28\x02\x0A\x4A\x40\x03\x53\x14\x5F\x59\x5A\x55\x5B\x1B\x5E\x0D\x49\x44\x4E\x4B\x4A\x3F\x04\x27\x06\x1B\x2F\x6A\x43\x1B\x10\x31\x0F\x55\x59\x17\x57\x3F", 47).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        char data[4096];
        sprintf(data, /*game=PUBG&user_key=%s&serial=%s*/ StrEnc("qu2yXK,YkJyGD@ut0.u~Nb'5(:.:chK", "\x16\x14\x5F\x1C\x65\x1B\x79\x1B\x2C\x6C\x0C\x34\x21\x32\x2A\x1F\x55\x57\x48\x5B\x3D\x44\x54\x50\x5A\x53\x4F\x56\x5E\x4D\x38", 31).c_str(), user_key, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                                                if (result[/*status*/ StrEnc("(>_LBm", "\x5B\x4A\x3E\x38\x37\x1E", 6).c_str()] == true) {
                    rng = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*rng*/ StrEnc("+n,", "\x59\x00\x4B", 3).c_str()].get<time_t>();
                      //expiredDate = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*ts*/ StrEnc("4`", "\x40\x13", 2).c_str()].get<std::string>();
                    //  modStatus = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*ms*/ StrEnc("#e", "\x4E\x16", 2).c_str()].get<std::string>();
                    std::string token = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*token*/ StrEnc("{>3Lr", "\x0F\x51\x58\x29\x1C", 5).c_str()].get<std::string>();
                    time_t rng = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*rng*/ StrEnc("+n,", "\x59\x00\x4B", 3).c_str()].get<time_t>();                  
                  
                    if (rng + 30 > time(0)) {
                        std::string auth = /*PUBG*/ StrEnc("Q*) ", "\x01\x7F\x6B\x67", 4).c_str();;
                        auth += "-";
                        auth += user_key;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += /*Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E*/ StrEnc("-2:uwZdV^%]?{{wHs2V,+(^NJU;kC*_{", "\x7B\x5F\x02\x39\x1C\x6D\x31\x3C\x6C\x6F\x30\x4C\x11\x38\x27\x1E\x23\x64\x3C\x5E\x67\x49\x69\x34\x2D\x33\x43\x58\x36\x50\x66\x3E", 32).c_str();
                        std::string outputAuth = Tools::CalcMD5(auth);
     
                        g_Token = token;
                        g_Auth = outputAuth;
				
                        bValid = g_Token == g_Auth;
                    }
                } else {
                    errMsg = result[/*reason*/ StrEnc("LW(3(c", "\x3E\x32\x49\x40\x47\x0D", 6).c_str()].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = "{";
                errMsg += e.what();
                errMsg += "}\n{";
                errMsg += chunk.memory;
                errMsg += "}";
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);

    return bValid ? "OK" : errMsg;
}

	namespace Settings
{
    static int Tab = 1;
}

	EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);

EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    if (glWidth <= 0 || glHeight <= 0)
        return orig_eglSwapBuffers(dpy, surface);

    if (!g_App)
        return orig_eglSwapBuffers(dpy, surface);

    screenWidth = ANativeWindow_getWidth(g_App->window);
    screenHeight = ANativeWindow_getHeight(g_App->window);
    density = AConfiguration_getDensity(g_App->config);

if (!initImGui) {
    ImGui::CreateContext();

    ImGuiStyle* style = &ImGui::GetStyle();

    // Kaydırma çubuğunu çok ince yap
    style->ScrollbarSize = 6.0f;

    // Menü Renkleri
    style->Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.85f); // Gri-siyah, yarı şeffaf
    style->Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);   // Şeffaf
    style->Colors[ImGuiCol_PopupBg] = ImVec4(0.15f, 0.15f, 0.15f, 0.95f); // Hafif daha açık gri

    // Border ve üst kısmın renkleri
    style->Colors[ImGuiCol_Border] = ImVec4(0.9f, 0.7f, 0.0f, 1.00f); // Altın sarısı border
    style->Colors[ImGuiCol_TitleBg] = ImVec4(0.3f, 0.3f, 0.3f, 0.90f); // Gri, yarı saydam
    style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.4f, 0.4f, 0.4f, 1.00f); // Daha koyu gri
    style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.2f, 0.2f, 0.2f, 0.75f); // Daha hafif gri

    // Butonlar - Ateş Renkleri
    style->Colors[ImGuiCol_Button] = ImVec4(0.8f, 0.3f, 0.0f, 1.00f); // Turuncu-kırmızı (ateş tonu)
    style->Colors[ImGuiCol_ButtonHovered] = ImVec4(1.0f, 0.5f, 0.0f, 1.00f); // Daha parlak turuncu
    style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.9f, 0.1f, 0.0f, 1.00f); // Kırmızı

    // Kaydırma çubuğu hover renkleri
    style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.4f, 0.4f, 0.4f, 1.00f); // Gri
    style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.6f, 0.6f, 0.6f, 1.00f); // Açık gri
    style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.8f, 0.8f, 0.8f, 1.00f); // Beyazımsı

    // Genel Ayarlar
    style->WindowRounding = 6.0f; // Daha yumuşak köşeler
    style->FrameRounding = 6.0f;  // Daha yumuşak buton köşeleri
    style->FrameBorderSize = 2.0f; // İnce border

    // Ölçekleme
    style->ScaleAllSizes(1.2f); // Premium bir his için ölçek artırıldı

    ImGui_ImplAndroid_Init();
    ImGui_ImplOpenGL3_Init("#version 300 es");


        ImGuiIO &io = ImGui::GetIO();
        //ImGui::StyleColorsDark(style);
        io.ConfigWindowsMoveFromTitleBarOnly = true;
        io.IniFilename = NULL;

        static const ImWchar ranges[] =
{
    0x20, 0xFF,
    0x2010, 0x205E,
    0x0600, 0x06FF,
    0xFE00, 0xFEFF,   
    0,
};  


        

            io.ConfigWindowsMoveFromTitleBarOnly = false;
            io.IniFilename = NULL;


            //==//
            static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
            ImFontConfig icons_config;

            ImFontConfig CustomFont;
            CustomFont.FontDataOwnedByAtlas = false;

            icons_config.MergeMode = true;
            icons_config.PixelSnapH = true;
            icons_config.OversampleH = 2.5;
            icons_config.OversampleV = 2.5;
            
          io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 25.f, &CustomFont);
       io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 30.0f, &icons_config, icons_ranges);

            ImFontConfig cfg;
            cfg.SizePixels = ((float) density / 20.0f);
            io.Fonts->AddFontDefault(&cfg);

            memset(&Config, 0, sizeof(sConfig));

// ===============================ESPCOLOR ================================== //

  
        Config.ColorsESP.PVisibile = CREATE_COLOR(28, 252, 3, 255);
        Config.ColorsESP.PNonVis = CREATE_COLOR(252, 3, 3, 255);
        Config.ColorsESP.PVLine = CREATE_COLOR(0, 255, 0, 255);
        Config.ColorsESP.PVILine = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.BVLine = CREATE_COLOR(255, 255, 255, 255);
        Config.ColorsESP.BVILine = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.PVBox = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.PVIBox = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.BVBox = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.Box3D = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.BVIBox = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.PVSkeleton = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.PVISkeleton = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.BVSkeleton = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.BVISkeleton = CREATE_COLOR(255, 0, 0, 255);
		Config.ColorsESP.Name = CREATE_COLOR(0, 0, 0, 200);
        Config.ColorsESP.Name = CREATE_COLOR(255, 255, 255, 255);
        Config.ColorsESP.RGB = CREATE_COLOR(255, 255, 255, 255);
		Config.ColorsESP.TeamID = CREATE_COLOR(0, 255, 0, 255);
        Config.ColorsESP.TeamID = CREATE_COLOR(255, 255, 255, 255);
		Config.ColorsESP.Fov = CREATE_COLOR(255, 255, 255, 255);
	    Config.ColorsESP.Text = CREATE_COLOR(255, 255, 255, 255);
	    Config.ColorsESP.Count = CREATE_COLOR(0, 255, 0, 255);
	    Config.ColorsESP.WeaponId = CREATE_COLOR(0, 255, 0, 255);
        Config.ColorsESP.Distance = CREATE_COLOR(255, 255, 255, 255);
        Config.ColorsESP.Vehicle = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.Items = CREATE_COLOR(0, 255, 0, 255);   
		//Config.AimBot.Cross = 60.0f;
		//Config.SilentAim.Cross = 200.0f;
   //     FOVSizea = 180.0f;
   
   for (auto &i : items_data) {
            for (auto &item : i["Items"]) {
                int r, g, b;
                sscanf(item["itemTextColor"].get<std::string>().c_str(), "#%02X%02X%02X", &r, &g, &b);
              
            }
        }
        initImGui = true;
    }

    ImGuiIO &io = ImGui::GetIO();
 //MADE BY HOST OP
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();

    DrawESP(ImGui::GetBackgroundDrawList());
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
if (ImGui::IsMouseDoubleClicked(0)) {   
         HideWindow = HideWindow;
        }
 if (HideWindow) {

    ImGui::SetNextWindowSize(ImVec2((float)glWidth * 0.35f, (float)glHeight * 0.53f), ImGuiCond_Once);

    static bool p_open = true;
    ImGui::PushFont(Arabic);
    if (ImGui::Begin(OBFUSCATE("TRS CHEATS~ARM32~V7A~2.7.0"), &p_open, ImGuiWindowFlags_NoSavedSettings)) {
        static bool isLogin = true;

        if (!isLogin) {
            ImGui::Text("Please Login! (Copy Key to @FTSMOD)");

            ImGui::PushItemWidth(-1);
            static char s[64];
            ImGui::InputText("##key", s, sizeof s);
            ImGui::PopItemWidth();

            if (ImGui::Button("  Paste Your Key  ", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                auto key = getClipboardText();
                strncpy(s, key.c_str(), sizeof s);
            }

            static std::string err;
            if (ImGui::Button("Login", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                err = Login(s);
                if (err == "OK") {
                    isLogin = bValid && g_Auth == g_Token;
                }
            }

            if (!err.empty() && err != "OK") {
                ImGui::Text("Error: %s", err.c_str());
            }
        } else {
            // ESP MENÜ
            ImGui::PushFont(Arabic);
            	    if (ImGui::BekaButton("  Player Esp", Settings::Tab == 1)) 
					Settings::Tab = 1;
		  ImGui::SameLine();
					 if (ImGui::BekaButton(" Aim", Settings::Tab == 2)) 
					Settings::Tab = 2;
					
   ImGui::SetCursorPos(ImVec2(10,90));
				ImGui::BeginChild("##esp",ImVec2(400, 400));{
                	if (Settings::Tab == 1) {
                    // Tablo başlat
                    if (ImGui::BeginTable("split", 2, ImGuiTableFlags_SizingStretchSame)) {
                        ImGui::PushFont(Arabic);

                        // Menü genişliği ve yüksekliği
                        ImVec2 windowSize = ImGui::GetContentRegionAvail();
                        float buttonWidth = windowSize.x / 2.2f; // Buton genişliği
                        float buttonHeight = 40.0f; // Sabit buton yüksekliği
                        float spacing = 5.0f; // Butonlar arası boşluk

                        ImGui::Spacing();

                        // ESP Butonları düzenli yerleştirme
                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"Esp", &Config.PlayerESP.Line);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"Enable All Esp", &Feu);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"ESP Alert", &Config.PlayerESP.Alert);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"ESP Vehicle", &Config.PlayerESP.Vehicle);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"ESP Box3D", &Config.PlayerESP.Box3D);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"ESP Bone", &Config.PlayerESP.Skeleton);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"ESP Line", &Config.PlayerESP.LineTop);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"ESP V-Fuel", &Config.PlayerESP.VehicleFuel);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"ESP V-Hp", &Config.PlayerESP.VehicleHP);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"Granade Alert", &Config.PlayerESP.Grenade);

                        ImGui::TableNextColumn();
                        ImGui::Checkbox(u8"ESP LootBox", &Config.PlayerESP.LootBox);
       ImGui::TableNextColumn();
       
                        ImGui::EndTable();
                        ImGui::PopFont();
             
             
                    }
                    ImGui::EndTabItem();
                }
                
			   }
			   	if (Settings::Tab == 2) {

			   	}
			   ImGui::PushFont(Arabic);
           if (ImGui::BeginTabItem(u8" AIMBOT  ")) {
                    ImGui::Spacing();
                    if (ImGui::BeginTable("split", 1)) {
			            
			            
			            ImGui::Separator();  
                        ImGui::TableNextColumn();
                     //   ImGui::PushFont(Arabic);
                        
                        ImGui::Spacing();
			
                    ImGui::TableNextColumn();
                    ImGui::Separator();  
			
			            ImGui::Separator(); 
			            ImGui::TableNextColumn();
			            ImGui::Spacing();
                     //   ImGui::Checkbox((u8"Silent Aim Enable"), &Config.SilentAim.Enable);
                        ImGui::Checkbox((u8"Aimbot 150M"), &Config.AimBot.Enable);
                        ImGui::Checkbox((u8"BT 50° (risk)"), &Config.SilentAim.Enable);
                        
		             	static int slider_test_0 = 50;
						ImGui::SliderFloat("FOV Size", &Config.AimBot.Cross, 0.0f, 400.0f);
						ImGui::SliderFloat("Anti-Recoil", &Config.Recc, 0.0f, 2.0f);
				 	//	ImGui::SliderFloat("Meter", &Config.Meter, 6.2f, 0.0f, 150.0f, "%.0f");
						
	         	static const char *triggers[] = {"Always", "Shooting"};
	     		ImGui::Combo("Trigger", (int *) &Config.AimBot.Trigger, triggers, 2, -1);

                    //    ImGui::Checkbox("Prediction ", &Config.AimBot.Predection);		
						
                        ImGui::Checkbox("Visibility Check", &Config.AimBot.VisCheck);
				        ImGui::Checkbox("Ignore Knock", &Config.AimBot.IgnoreKnocked);			
						
                        ImGui::Checkbox("Ignore Bot", &Config.AimBot.IgnoreBot);
						
				
	
			            ImGui::EndTable();
			            ImGui::PopFont();
                        
                    }
                    ImGui::EndTabItem();
            
					 

                
		 }
       } 
      } }
   

ImGui::End();
    ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
// ================================================================================================================================ //
        return orig_eglSwapBuffers(dpy, surface);
        }

    int32_t (*orig_onInputEvent)(struct android_app *app, AInputEvent *inputEvent);

    int32_t onInputEvent(struct android_app *app, AInputEvent *inputEvent) {
        if (initImGui) {
            ImGui_ImplAndroid_HandleInputEvent(inputEvent, {(float) screenWidth / (float) glWidth, (float) screenHeight / (float) glHeight});
        }
        return orig_onInputEvent(app, inputEvent);
    }



#define SLEEP_TIME 1000LL / 60LL
[[noreturn]] void *maps_thread(void *) {
    while (true) {
        auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        std::vector<sRegion> tmp;
        char line[512];
        FILE *f = fopen("/proc/self/maps", "r");
        if (f) {
            while (fgets(line, sizeof line, f)) {
                uintptr_t start, end;
                char tmpProt[16];
                if (sscanf(line, "%" PRIXPTR "-%" PRIXPTR " %16s %*s %*s %*s %*s", &start, &end, tmpProt) > 0) {
                    if (tmpProt[0] != 'r') {
                        tmp.push_back({start, end});
                    }
                }
            }
            fclose(f);
        }

        auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
        std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
    }
}
void *main_thread(void *) {
       
        UE4 = Tools::GetBaseAddress("libUE4.so");
        while (!UE4){
        UE4 = Tools::GetBaseAddress("libUE4.so");
        sleep(1);}
        anort = Tools::GetBaseAddress("libanort.so");
        while (!anort){
        anort = Tools::GetBaseAddress("libanort.so");
        sleep(1);}
        anogs = Tools::GetBaseAddress("libanogs.so");
        while (!anogs){
        anogs = Tools::GetBaseAddress("libanogs.so");
        sleep(1);}
        CrashSight = Tools::GetBaseAddress("libCrashSight.so");
        while (!CrashSight){
        CrashSight = Tools::GetBaseAddress("libCrashSight.so");
        sleep(1);}
        while (!g_App){
        g_App = *(android_app **) (UE4 + GNativeAndroidApp_Offset);
        sleep(1);}
        while (!g_App->onInputEvent)
        sleep(1);
        orig_onInputEvent = decltype(orig_onInputEvent)(g_App->onInputEvent);
        g_App->onInputEvent = onInputEvent;
		
int (*sub_60A34)(int a1, unsigned char *a2, size_t a3);
	 
        FName::GNames = GetGNames();
        while (!FName::GNames) {
            FName::GNames = GetGNames();
            sleep(1);
        }
        UObject::GUObjectArray = (FUObjectArray *) (UE4 + GUObject_Offset);

        void *egl = dlopen_ex("libEGL.so", 4);
        while (!egl) {
            egl = dlopen_ex("libEGL.so", 4);
            sleep(1);
        }
        
        void *addr = dlsym_ex(egl, "eglSwapBuffers");
        HOOK(addr, _eglSwapBuffers, &orig_eglSwapBuffers);
        dlclose_ex(egl);
        Tools::Hook((void *) DobbySymbolResolver(OBFUSCATE("/system/lib/libEGL.so"), OBFUSCATE("eglSwapBuffers")), (void *) _eglSwapBuffers, (void **) &orig_eglSwapBuffers);

        pthread_t t;
        pthread_create(&t, 0, maps_thread, 0);
        items_data = json::parse(JSON_ITEMS);
        return 0;
    }

    __attribute__((constructor)) void _init() {
        pthread_t t;
        pthread_create(&t, 0, main_thread, 0);
    }
