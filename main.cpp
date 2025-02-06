#include "Includes.h"
#include "Tools.h"
#include "fake_dlfcn.h"
#include "Vector3.hpp"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "StrEnc.h"
#include "plthook.h"

#include <iostream>
#include <thread>
#include <random>
#include <cstring>
#include <unistd.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <dlfcn.h>
#include <vector>
#include <thread>
#include <unistd.h>

#define PATCH_LIB
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
bool Klavye;
#include "Icon.h"
using json = nlohmann::json;
#define SLEEP_TIME 1000LL / 60LL
#include "SDK.hpp"
using namespace SDK;
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "base64/base64.h"
int 系统屏幕宽 = -1; // Объявление переменной
int 屏幕宽度;        // Объявление переменной
int 系统屏幕高 = -1; // Объявление переменной
int 屏幕高度;       // Объявление переменной
static float SliderFloat = 0;
namespace Antiban {
bool fix{ true };
}
bool ui2;
bool 人物血量;
bool 人物姓名;
bool 绘制开关 = true;
std::string UE4数据存储;
std::string PID数据存储;
bool shiftPressed = false;
bool alll;
bool 人物骨骼; // Объявление переменной
std::string UE4数据()
{
    static bool is_initialized = false; // 用于确保初始化只执行一次
    if (!is_initialized) {
        // 使用随机数生成器生成 32 位整数
        std::random_device rd;    // 获取随机数种子
        std::mt19937 gen(rd());   // 使用 Mersenne Twister 算法
        std::uniform_int_distribution<uint32_t> dis(0, 0xFFFFFFFF); // 生成 0 到 0xFFFFFFFF 的随机数

        uint32_t random_number = dis(gen); // 生成随机数

        // 将随机数格式化为十六进制字符串
        std::stringstream ss;
        ss << "0x" << std::hex << std::uppercase << random_number; // 转换为大写十六进制
        UE4数据存储 = ss.str(); // 保存到全局变量

        is_initialized = true; // 标记初始化已完成
    }
    return UE4数据存储;
}


std::string PID数据()
{
    static bool is_initialized = false; // 用于确保初始化只执行一次
    if (!is_initialized) {
        // 使用随机数生成器生成 32 位整数
        std::random_device rd;    // 获取随机数种子
        std::mt19937 gen(rd());   // 使用 Mersenne Twister 算法
        std::uniform_int_distribution<uint32_t> dis(0, 0xFFFF); // 生成 0 到 0xFFFFFFFF 的随机数

        uint32_t random_number = dis(gen); // 生成随机数

        // 将随机数格式化为十六进制字符串
        std::stringstream ss;
        ss << "0x" << std::hex << std::uppercase << random_number; // 转换为大写十六进制
        PID数据存储 = ss.str(); // 保存到全局变量

        is_initialized = true; // 标记初始化已完成
    }
    return PID数据存储;
}


ImFont* inter_bold = nullptr;
ImVec4 RainbowColor(float t)
{
    float r = 0.5f + 0.5f * sinf(2.0f * 3.14159f * t);
    float g = 0.5f + 0.5f * sinf(2.0f * 3.14159f * (t + 0.33f));
    float b = 0.5f + 0.5f * sinf(2.0f * 3.14159f * (t + 0.66f));
    return ImVec4(r, g, b, 1.0f);
}

void SuperText(const char* text)
{
   
    static auto start_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now() - start_time
    ).count() / 1000.0f;

    for (int i = 0; i < strlen(text); ++i)
    {

        float wave_offset = sinf(elapsed_time * 2.0f + i * 0.5f) * 5.0f;

  
        float t = fmodf(elapsed_time + (float)i / (float)strlen(text), 1.0f);
        ImVec4 currentColor = RainbowColor(t);

   
        ImGui::PushStyleColor(ImGuiCol_Text, currentColor);

 
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + wave_offset);
        ImGui::Text("%c", text[i]);
        ImGui::SameLine();

        ImGui::PopStyleColor();
    }
    ImGui::NewLine();
}

const int Colors[] = {
    0xFF0000, // Красный
    0x00FF00, // Зеленый
    0x0000FF, // Синий
    // Добавьте больше цветов по необходимости
};

long GetRandomColorByIndex(int index) {
    srand(index);

    int a = 255;
    int r = ((Colors[rand() % (sizeof(Colors) / sizeof(Colors[0]))] & 0xFF0000) >> 16);
    int g = ((Colors[rand() % (sizeof(Colors) / sizeof(Colors[0]))] & 0x00FF00) >> 8);
    int b = (Colors[rand() % (sizeof(Colors) / sizeof(Colors[0]))] & 0x0000FF);

    return IM_COL32(r, g, b, a);
}

bool On;
bool Of;

float size_child = 0;
// static float SliderFloat = 0;
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

#include "imgui/stb_image.h"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_NOTUSED(v)  (void)sizeof(v)

#include "Image/logo5.h"

struct TextureInfo { ImTextureID textureId; int x; int y; int w; int h; };
void DrawImage(int x, int y, int w, int h, ImTextureID Texture) {
    ImGui::GetForegroundDrawList()->AddImage(Texture, ImVec2(x, y), ImVec2(x + w, y + h));
}

static TextureInfo textureInfo;
TextureInfo CreateTexture(char* ImagePath) {
    int w, h, n;
    stbi_uc* data = stbi_load(ImagePath, &w, &h, &n, 0);
    GLuint texture;
    glGenTextures(1, &texture);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    if (n == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
    else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }stbi_image_free(data);
    textureInfo.textureId = reinterpret_cast<ImTextureID>((GLuint*)texture);
    textureInfo.w = w;
    textureInfo.h = h;
    return textureInfo;
}

TextureInfo CreateTexture(const unsigned char* buf, int len) {
    TextureInfo image;
    unsigned char* image_data = stbi_load_from_memory(buf, len, &image.w, &image.h, NULL, 0);
    if (image_data == NULL) { perror("File does not exist"); }
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.w, image.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);
    image.textureId = (ImTextureID)image_texture;
    return image;
}

static struct Hand {

} hand;

TextureInfo logo5;

void DrawLine(int x1, int y1, int x2, int y2, ImVec4 color, int size);
void DrawRect(int x, int y, int w, int h, ImVec4 color, int size);
void DrawRectFilled(int x, int y, int w, int h, ImVec4 color);
void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, ImVec4 Color, int T);
void DrawCircle(int x, int y, float radius, ImVec4 color, int segments, int thickness);
void DrawStrokeText(int x, int y, ImVec4 color, const char* str);
void DrawImage(int x, int y, int w, int h, ImTextureID Texture);
void DrawCircleFilled(int x, int y, int radius, ImVec4 color, int segments);
float MouseToObjectDistance(float ObjectSrceenX,float ObjectSrceenY);
float GetD2DPosDistance(float ObjectX,float ObjectY);

void InitTexture() {

logo5 = CreateTexture(LogoPIC_data, sizeof(LogoPIC_data));
}



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
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0, 1);

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
if (Antiban::fix){
MemoryPatch::createWithHex("libUE4.so", 0x21C1B08, "70 4C 2D E9").Modify();
PATCH_LIB("libUE4.so","0x971BE014","00 00 A0 E3 1E FF 2F E1"); //971BE014; 167 772 160; Dword
PATCH_LIB("libUE4.so","0x971BE054","00 00 A0 E3 1E FF 2F E1"); //971BE054; 436 207 617; Dword
PATCH_LIB("libUE4.so","0x971BE084","00 00 A0 E3 1E FF 2F E1"); //971BE084; 124 266 488; Dword
PATCH_LIB("libUE4.so","0x971BE0A0","00 00 A0 E3 1E FF 2F E1"); //971BE0A0; 167 772 161; Dword
PATCH_LIB("libUE4.so","0x971BE110","00 00 A0 E3 1E FF 2F E1"); //971BE110; 167 772 191; Dword
PATCH_LIB("libUE4.so","0x971BE124","00 00 A0 E3 1E FF 2F E1"); //971BE124; 436 207 647; Dword
PATCH_LIB("libUE4.so","0x971BE154","00 00 A0 E3 1E FF 2F E1"); //971BE154; 436 207 635; Dword
PATCH_LIB("libUE4.so","0x971BE240","00 00 A0 E3 1E FF 2F E1"); //971BE240; 436 207 617; Dword
PATCH_LIB("libUE4.so","0x971BE2EC","00 00 A0 E3 1E FF 2F E1"); //971BE2EC; 167 772 171; Dword
PATCH_LIB("libUE4.so","0x971BE304","00 00 A0 E3 1E FF 2F E1"); //971BE304; 167 772 163; Dword
PATCH_LIB("libUE4.so","0x971BE334","00 00 A0 E3 1E FF 2F E1"); //971BE334; 436 207 617; Dword
PATCH_LIB("libUE4.so","0x971BE35C","00 00 A0 E3 1E FF 2F E1"); //971BE35C; 167 772 202; Dword
PATCH_LIB("libUE4.so","0x971BE3D0","00 00 A0 E3 1E FF 2F E1"); //971BE3D0; 167 772 171; Dword
PATCH_LIB("libUE4.so","0x971BE3E8","00 00 A0 E3 1E FF 2F E1"); //971BE3E8; 167 772 163; Dword
PATCH_LIB("libUE4.so","0x971BE434","00 00 A0 E3 1E FF 2F E1"); //971BE434; 167 772 218; Dword
PATCH_LIB("libUE4.so","0x971BE44C","00 00 A0 E3 1E FF 2F E1"); //971BE44C; 167 772 197; Dword
PATCH_LIB("libUE4.so","0x971BE478","00 00 A0 E3 1E FF 2F E1"); //971BE478; 167 772 201; Dword
PATCH_LIB("libUE4.so","0x971BE490","00 00 A0 E3 1E FF 2F E1"); //971BE490; 167 772 180; Dword
PATCH_LIB("libUE4.so","0x971BE4BC","00 00 A0 E3 1E FF 2F E1"); //971BE4BC; 167 772 184; Dword
PATCH_LIB("libUE4.so","0x971BE4D4","00 00 A0 E3 1E FF 2F E1"); //971BE4D4; 167 772 163; Dword
PATCH_LIB("libUE4.so","0x971BE520","00 00 A0 E3 1E FF 2F E1"); //971BE520; 436 207 618; Dword
PATCH_LIB("libUE4.so","0x971BE58C","00 00 A0 E3 1E FF 2F E1"); //971BE58C; 452 984 825; Dword
PATCH_LIB("libUE4.so","0x971BE598","00 00 A0 E3 1E FF 2F E1"); //971BE598; 124 265 996; Dword
PATCH_LIB("libUE4.so","0x971BE5DC","00 00 A0 E3 1E FF 2F E1"); //971BE5DC; 167 772 179; Dword
PATCH_LIB("libUE4.so","0x971BE5E8","00 00 A0 E3 1E FF 2F E1"); //971BE5E8; 436 207 620; Dword
PATCH_LIB("libUE4.so","0x971BE610","00 00 A0 E3 1E FF 2F E1"); //971BE610; 167 772 161; Dword
PATCH_LIB("libUE4.so","0x971BE684","00 00 A0 E3 1E FF 2F E1"); //971BE684; 436 207 617; Dword
PATCH_LIB("libUE4.so","0x971BE6A0","00 00 A0 E3 1E FF 2F E1"); //971BE6A0; 436 207 632; Dword
PATCH_LIB("libUE4.so","0x971BE6B4","00 00 A0 E3 1E FF 2F E1"); //971BE6B4; 973 078 539; Dword
PATCH_LIB("libUE4.so","0x971BE6F0","00 00 A0 E3 1E FF 2F E1"); //971BE6F0; 436 207 620; Dword
PATCH_LIB("libUE4.so","0x971BE718","00 00 A0 E3 1E FF 2F E1"); //971BE718; 167 772 161; Dword
PATCH_LIB("libUE4.so","0x971BE758","00 00 A0 E3 1E FF 2F E1"); //971BE758; 124 264 884; Dword
PATCH_LIB("libUE4.so","0x971BE7D0","00 00 A0 E3 1E FF 2F E1"); //971BE7D0; 167 772 192; Dword
PATCH_LIB("libUE4.so","0x971BE7DC","00 00 A0 E3 1E FF 2F E1"); //971BE7DC; 167 772 164; Dword
PATCH_LIB("libUE4.so","0x971BE94C","00 00 A0 E3 1E FF 2F E1"); //971BE94C; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BE9EC","00 00 A0 E3 1E FF 2F E1"); //971BE9EC; 167 772 219; Dword
PATCH_LIB("libUE4.so","0x971BE9F8","00 00 A0 E3 1E FF 2F E1"); //971BE9F8; 167 772 172; Dword
PATCH_LIB("libUE4.so","0x971BEA10","00 00 A0 E3 1E FF 2F E1"); //971BEA10; 167 772 164; Dword
PATCH_LIB("libUE4.so","0x971BEA8C","00 00 A0 E3 1E FF 2F E1"); //971BEA8C; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BEB44","00 00 A0 E3 1E FF 2F E1"); //971BEB44; 436 207 632; Dword
PATCH_LIB("libUE4.so","0x971BEB58","00 00 A0 E3 1E FF 2F E1"); //971BEB58; 973 078 539; Dword
PATCH_LIB("libUE4.so","0x971BEBA0","00 00 A0 E3 1E FF 2F E1"); //971BEBA0; 167 772 201; Dword
PATCH_LIB("libUE4.so","0x971BEBAC","00 00 A0 E3 1E FF 2F E1"); //971BEBAC; 436 207 617; Dword
PATCH_LIB("libUE4.so","0x971BEBF8","00 00 A0 E3 1E FF 2F E1"); //971BEBF8; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BEC28","00 00 A0 E3 1E FF 2F E1"); //971BEC28; 167 772 164; Dword
PATCH_LIB("libUE4.so","0x971BED2C","00 00 A0 E3 1E FF 2F E1"); //971BED2C; 167 772 191; Dword
PATCH_LIB("libUE4.so","0x971BED3C","00 00 A0 E3 1E FF 2F E1"); //971BED3C; 167 772 167; Dword
PATCH_LIB("libUE4.so","0x971BED54","00 00 A0 E3 1E FF 2F E1"); //971BED54; 167 772 163; Dword
PATCH_LIB("libUE4.so","0x971BEDAC","00 00 A0 E3 1E FF 2F E1"); //971BEDAC; 436 207 639; Dword
PATCH_LIB("libUE4.so","0x971BEE08","00 00 A0 E3 1E FF 2F E1"); //971BEE08; 436 207 621; Dword
PATCH_LIB("libUE4.so","0x971BEE20","00 00 A0 E3 1E FF 2F E1"); //971BEE20; 167 772 195; Dword
PATCH_LIB("libUE4.so","0x971BEE34","00 00 A0 E3 1E FF 2F E1"); //971BEE34; 167 772 169; Dword
PATCH_LIB("libUE4.so","0x971BEE4C","00 00 A0 E3 1E FF 2F E1"); //971BEE4C; 167 772 161; Dword
PATCH_LIB("libUE4.so","0x971BEEC0","00 00 A0 E3 1E FF 2F E1"); //971BEEC0; 167 772 165; Dword
PATCH_LIB("libUE4.so","0x971BEEFC","00 00 A0 E3 1E FF 2F E1"); //971BEEFC; 436 207 619; Dword
PATCH_LIB("libUE4.so","0x971BF074","00 00 A0 E3 1E FF 2F E1"); //971BF074; 436 207 619; Dword
PATCH_LIB("libUE4.so","0x971BF10C","00 00 A0 E3 1E FF 2F E1"); //971BF10C; 436 207 759; Dword
PATCH_LIB("libUE4.so","0x971BF120","00 00 A0 E3 1E FF 2F E1"); //971BF120; 167 772 161; Dword
PATCH_LIB("libUE4.so","0x971BF158","00 00 A0 E3 1E FF 2F E1"); //971BF158; 167 772 215; Dword
PATCH_LIB("libUE4.so","0x971BF1BC","00 00 A0 E3 1E FF 2F E1"); //971BF1BC; 167 772 168; Dword
PATCH_LIB("libUE4.so","0x971BF1D4","00 00 A0 E3 1E FF 2F E1"); //971BF1D4; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BF1EC","00 00 A0 E3 1E FF 2F E1"); //971BF1EC; 167 772 160; Dword
PATCH_LIB("libUE4.so","0x971BF20C","00 00 A0 E3 1E FF 2F E1"); //971BF20C; 167 772 170; Dword
PATCH_LIB("libUE4.so","0x971BF234","00 00 A0 E3 1E FF 2F E1"); //971BF234; 436 207 616; Dword
PATCH_LIB("libUE4.so","0x971BF278","00 00 A0 E3 1E FF 2F E1"); //971BF278; 436 207 668; Dword
PATCH_LIB("libUE4.so","0x971BF308","00 00 A0 E3 1E FF 2F E1"); //971BF308; 436 207 632; Dword
PATCH_LIB("libUE4.so","0x971BF31C","00 00 A0 E3 1E FF 2F E1"); //971BF31C; 973 078 539; Dword
PATCH_LIB("libUE4.so","0x971BF364","00 00 A0 E3 1E FF 2F E1"); //971BF364; 97 779 770; Dword
PATCH_LIB("libUE4.so","0x971BF36C","00 00 A0 E3 1E FF 2F E1"); //971BF36C; 167 772 222; Dword
PATCH_LIB("libUE4.so","0x971BF3A0","00 00 A0 E3 1E FF 2F E1"); //971BF3A0; 167 772 178; Dword
PATCH_LIB("libUE4.so","0x971BF484","00 00 A0 E3 1E FF 2F E1"); //971BF484; 366 215 224; Dword
PATCH_LIB("libUE4.so","0x971BF488","00 00 A0 E3 1E FF 2F E1"); //971BF488; 324 009 984; Dword
PATCH_LIB("libUE4.so","0x971BF4F8","00 00 A0 E3 1E FF 2F E1"); //971BF4F8; 167 772 168; Dword
PATCH_LIB("libUE4.so","0x971BF508","00 00 A0 E3 1E FF 2F E1"); //971BF508; 25 165 825; Dword
PATCH_LIB("libUE4.so","0x971BF510","00 00 A0 E3 1E FF 2F E1"); //971BF510; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BF528","00 00 A0 E3 1E FF 2F E1"); //971BF528; 167 772 160; Dword
PATCH_LIB("libUE4.so","0x971BF574","00 00 A0 E3 1E FF 2F E1"); //971BF574; 167 772 168; Dword
PATCH_LIB("libUE4.so","0x971BF584","00 00 A0 E3 1E FF 2F E1"); //971BF584; 25 165 825; Dword
PATCH_LIB("libUE4.so","0x971BF58C","00 00 A0 E3 1E FF 2F E1"); //971BF58C; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BF5A4","00 00 A0 E3 1E FF 2F E1"); //971BF5A4; 167 772 160; Dword
PATCH_LIB("libUE4.so","0x971BF5C4","00 00 A0 E3 1E FF 2F E1"); //971BF5C4; 167 772 170; Dword
PATCH_LIB("libUE4.so","0x971BF5EC","00 00 A0 E3 1E FF 2F E1"); //971BF5EC; 436 207 616; Dword
PATCH_LIB("libUE4.so","0x971BF5FC","00 00 A0 E3 1E FF 2F E1"); //971BF5FC; 167 772 170; Dword
PATCH_LIB("libUE4.so","0x971BF624","00 00 A0 E3 1E FF 2F E1"); //971BF624; 436 207 616; Dword
PATCH_LIB("libUE4.so","0x971BF650","00 00 A0 E3 1E FF 2F E1"); //971BF650; 167 772 190; Dword
PATCH_LIB("libUE4.so","0x971BF664","00 00 A0 E3 1E FF 2F E1"); //971BF664; 167 772 213; Dword
PATCH_LIB("libUE4.so","0x971BF678","00 00 A0 E3 1E FF 2F E1"); //971BF678; 366 215 224; Dword
PATCH_LIB("libUE4.so","0x971BF6E0","00 00 A0 E3 1E FF 2F E1"); //971BF6E0; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BF70C","00 00 A0 E3 1E FF 2F E1"); //971BF70C; 167 772 161; Dword
PATCH_LIB("libUE4.so","0x971BF764","00 00 A0 E3 1E FF 2F E1"); //971BF764; 436 207 631; Dword
PATCH_LIB("libUE4.so","0x971BF76C","00 00 A0 E3 1E FF 2F E1"); //971BF76C; 973 078 541; Dword
PATCH_LIB("libUE4.so","0x971BF7BC","00 00 A0 E3 1E FF 2F E1"); //971BF7BC; 167 772 173; Dword
PATCH_LIB("libUE4.so","0x971BF7CC","00 00 A0 E3 1E FF 2F E1"); //971BF7CC; 436 207 622; Dword
PATCH_LIB("libUE4.so","0x971BF850","00 00 A0 E3 1E FF 2F E1"); //971BF850; 436 207 634; Dword
PATCH_LIB("libUE4.so","0x971BF864","00 00 A0 E3 1E FF 2F E1"); //971BF864; 973 078 541; Dword
PATCH_LIB("libUE4.so","0x971BF8A4","00 00 A0 E3 1E FF 2F E1"); //971BF8A4; 167 772 167; Dword
PATCH_LIB("libUE4.so","0x971BF8F0","00 00 A0 E3 1E FF 2F E1"); //971BF8F0; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x971BF904","00 00 A0 E3 1E FF 2F E1"); //971BF904; 436 207 645; Dword
PATCH_LIB("libUE4.so","0x971BF920","00 00 A0 E3 1E FF 2F E1"); //971BF920; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BF94C","00 00 A0 E3 1E FF 2F E1"); //971BF94C; 167 772 161; Dword
PATCH_LIB("libUE4.so","0x971BF9A0","00 00 A0 E3 1E FF 2F E1"); //971BF9A0; 436 207 631; Dword
PATCH_LIB("libUE4.so","0x971BF9A8","00 00 A0 E3 1E FF 2F E1"); //971BF9A8; 973 078 541; Dword
PATCH_LIB("libUE4.so","0x971BF9F8","00 00 A0 E3 1E FF 2F E1"); //971BF9F8; 167 772 169; Dword
PATCH_LIB("libUE4.so","0x971BFA8C","00 00 A0 E3 1E FF 2F E1"); //971BFA8C; 167 772 168; Dword
PATCH_LIB("libUE4.so","0x971BFA9C","00 00 A0 E3 1E FF 2F E1"); //971BFA9C; 25 165 825; Dword
PATCH_LIB("libUE4.so","0x971BFAA4","00 00 A0 E3 1E FF 2F E1"); //971BFAA4; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BFABC","00 00 A0 E3 1E FF 2F E1"); //971BFABC; 167 772 160; Dword
PATCH_LIB("libUE4.so","0x971BFB08","00 00 A0 E3 1E FF 2F E1"); //971BFB08; 167 772 168; Dword
PATCH_LIB("libUE4.so","0x971BFB20","00 00 A0 E3 1E FF 2F E1"); //971BFB20; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x971BFB38","00 00 A0 E3 1E FF 2F E1"); //971BFB38; 167 772 160; Dword
PATCH_LIB("libUE4.so","0x971BFB5C","00 00 A0 E3 1E FF 2F E1"); //971BFB5C; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x971BFB84","00 00 A0 E3 1E FF 2F E1"); //971BFB84; 167 772 170; Dword
PATCH_LIB("libUE4.so","0x972F2468","00 00 A0 E3 1E FF 2F E1"); //972F2468; 167 772 161; Dword
PATCH_LIB("libUE4.so","0x972F2484","00 00 A0 E3 1E FF 2F E1"); //972F2484; 167 772 175; Dword
PATCH_LIB("libUE4.so","0x972F24AC","00 00 A0 E3 1E FF 2F E1"); //972F24AC; 436 207 621; Dword
PATCH_LIB("libUE4.so","0x972F255C","00 00 A0 E3 1E FF 2F E1"); //972F255C; 167 772 161; Dword
PATCH_LIB("libUE4.so","0x972F25C0","00 00 A0 E3 1E FF 2F E1"); //972F25C0; 365 953 025; Dword
PATCH_LIB("libUE4.so","0x972F25C4","00 00 A0 E3 1E FF 2F E1"); //972F25C4; 324 009 986; Dword
PATCH_LIB("libUE4.so","0x972F25C8","00 00 A0 E3 1E FF 2F E1"); //972F25C8; 436 207 660; Dword
PATCH_LIB("libUE4.so","0x972F2638","00 00 A0 E3 1E FF 2F E1"); //972F2638; 362 610 696; Dword
PATCH_LIB("libUE4.so","0x972F263C","00 00 A0 E3 1E FF 2F E1"); //972F263C; 324 009 984; Dword
PATCH_LIB("libUE4.so","0x972F2640","00 00 A0 E3 1E FF 2F E1"); //972F2640; 167 772 171; Dword
PATCH_LIB("libUE4.so","0x972F2658","00 00 A0 E3 1E FF 2F E1"); //972F2658; 167 772 163; Dword
PATCH_LIB("libUE4.so","0x972F26BC","00 00 A0 E3 1E FF 2F E1"); //972F26BC; 362 610 696; Dword
PATCH_LIB("libUE4.so","0x972F26C0","00 00 A0 E3 1E FF 2F E1"); //972F26C0; 324 009 984; Dword
PATCH_LIB("libUE4.so","0x972F26C4","00 00 A0 E3 1E FF 2F E1"); //972F26C4; 167 772 181; Dword
PATCH_LIB("libUE4.so","0x972F26DC","00 00 A0 E3 1E FF 2F E1"); //972F26DC; 167 772 189; Dword
PATCH_LIB("libUE4.so","0x972F271C","00 00 A0 E3 1E FF 2F E1"); //972F271C; 436 207 619; Dword
PATCH_LIB("libUE4.so","0x972F2744","00 00 A0 E3 1E FF 2F E1"); //972F2744; 167 772 163; Dword
PATCH_LIB("libUE4.so","0x972F27BC","00 00 A0 E3 1E FF 2F E1"); //972F27BC; 167 772 190; Dword
PATCH_LIB("libUE4.so","0x972F27EC","00 00 A0 E3 1E FF 2F E1"); //972F27EC; 436 207 634; Dword
PATCH_LIB("libUE4.so","0x972F281C","00 00 A0 E3 1E FF 2F E1"); //972F281C; 436 207 622; Dword
PATCH_LIB("libUE4.so","0x972F2824","00 00 A0 E3 1E FF 2F E1"); //972F2824; 167 772 205; Dword
PATCH_LIB("libUE4.so","0x972F284C","00 00 A0 E3 1E FF 2F E1"); //972F284C; 436 207 649; Dword
PATCH_LIB("libUE4.so","0x972F2860","00 00 A0 E3 1E FF 2F E1"); //972F2860; 973 078 556; Dword
PATCH_LIB("libUE4.so","0x972F28D0","00 00 A0 E3 1E FF 2F E1"); //972F28D0; 167 772 160; Dword
PATCH_LIB("libUE4.so","0x972F2900","00 00 A0 E3 1E FF 2F E1"); //972F2900; 324 009 984; Dword
PATCH_LIB("libUE4.so","0x972F2904","00 00 A0 E3 1E FF 2F E1"); //972F2904; 436 207 658; Dword
PATCH_LIB("libUE4.so","0x972F2928","00 00 A0 E3 1E FF 2F E1"); //972F2928; 324 009 984; Dword
PATCH_LIB("libUE4.so","0x972F2D20","00 00 A0 E3 1E FF 2F E1"); //972F2D20; 167 772 168; Dword
PATCH_LIB("libUE4.so","0x972F2D40","00 00 A0 E3 1E FF 2F E1"); //972F2D40; 167 772 160; Dword
PATCH_LIB("libUE4.so","0x972F3068","00 00 A0 E3 1E FF 2F E1"); //972F3068; 324 009 984; Dword
PATCH_LIB("libUE4.so","0x972F306C","00 00 A0 E3 1E FF 2F E1"); //972F306C; 436 207 617; Dword
PATCH_LIB("libUE4.so","0x972F308C","00 00 A0 E3 1E FF 2F E1"); //972F308C; 167 772 171; Dword
PATCH_LIB("libUE4.so","0x972F30A8","00 00 A0 E3 1E FF 2F E1"); //972F30A8; 167 772 167; Dword
PATCH_LIB("libUE4.so","0x972F30B0","00 00 A0 E3 1E FF 2F E1"); //972F30B0; 436 207 618; Dword
PATCH_LIB("libUE4.so","0x972F30F0","00 00 A0 E3 1E FF 2F E1"); //972F30F0; 167 772 170; Dword
PATCH_LIB("libUE4.so","0x972F311C","00 00 A0 E3 1E FF 2F E1"); //972F311C; 167 772 176; Dword
PATCH_LIB("libUE4.so","0x972F32E8","00 00 A0 E3 1E FF 2F E1"); //972F32E8; 324 075 524; Dword
PATCH_LIB("libUE4.so","0x972F32F0","00 00 A0 E3 1E FF 2F E1"); //972F32F0; 329 252 864; Dword
PATCH_LIB("libUE4.so","0x972F3560","00 00 A0 E3 1E FF 2F E1"); //972F3560; 167 772 168; Dword
PATCH_LIB("libUE4.so","0x972F356C","00 00 A0 E3 1E FF 2F E1"); //972F356C; 167 772 172; Dword
PATCH_LIB("libUE4.so","0x972F3574","00 00 A0 E3 1E FF 2F E1"); //972F3574; 167 772 185; Dword
PATCH_LIB("libUE4.so","0x972F36A4","00 00 A0 E3 1E FF 2F E1"); //972F36A4; 167 772 195; Dword
PATCH_LIB("libUE4.so","0x972F36C8","00 00 A0 E3 1E FF 2F E1"); //972F36C8; 436 207 630; Dword
PATCH_LIB("libUE4.so","0x972F36DC","00 00 A0 E3 1E FF 2F E1"); //972F36DC; 436 207 625; Dword
PATCH_LIB("libUE4.so","0x972F36F0","00 00 A0 E3 1E FF 2F E1"); //972F36F0; 436 207 620; Dword
PATCH_LIB("libUE4.so","0x972F3704","00 00 A0 E3 1E FF 2F E1"); //972F3704; 167 772 168; Dword
PATCH_LIB("libUE4.so","0x972F3920","00 00 A0 E3 1E FF 2F E1"); //972F3920; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x972F3930","00 00 A0 E3 1E FF 2F E1"); //972F3930; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x972F39EC","00 00 A0 E3 1E FF 2F E1"); //972F39EC; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x972F39FC","00 00 A0 E3 1E FF 2F E1"); //972F39FC; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x972F3AB0","00 00 A0 E3 1E FF 2F E1"); //972F3AB0; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x972F3AC0","00 00 A0 E3 1E FF 2F E1"); //972F3AC0; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x972F3B74","00 00 A0 E3 1E FF 2F E1"); //972F3B74; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x972F3B84","00 00 A0 E3 1E FF 2F E1"); //972F3B84; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x972F3C34","00 00 A0 E3 1E FF 2F E1"); //972F3C34; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x972F3C44","00 00 A0 E3 1E FF 2F E1"); //972F3C44; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x972F3CF4","00 00 A0 E3 1E FF 2F E1"); //972F3CF4; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x972F3D04","00 00 A0 E3 1E FF 2F E1"); //972F3D04; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x972F3DB8","00 00 A0 E3 1E FF 2F E1"); //972F3DB8; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x972F3DC8","00 00 A0 E3 1E FF 2F E1"); //972F3DC8; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x972F3E78","00 00 A0 E3 1E FF 2F E1"); //972F3E78; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x972F3E88","00 00 A0 E3 1E FF 2F E1"); //972F3E88; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x972F3F2C","00 00 A0 E3 1E FF 2F E1"); //972F3F2C; 167 772 166; Dword
PATCH_LIB("libUE4.so","0x972F3F3C","00 00 A0 E3 1E FF 2F E1"); //972F3F3C; 167 772 162; Dword
PATCH_LIB("libUE4.so","0x972F3F7C","00 00 A0 E3 1E FF 2F E1"); //972F3F7C; 436 207 622; Dword
PATCH_LIB("libUE4.so","0x972F3F98","00 00 A0 E3 1E FF 2F E1"); //972F3F98; 167 772 204; Dword
PATCH_LIB("libUE4.so","0x972F3FC8","00 00 A0 E3 1E FF 2F E1"); //972F3FC8; 436 207 648; Dword
PATCH_LIB("libUE4.so","0x972F3FD0","00 00 A0 E3 1E FF 2F E1"); //972F3FD0; 167 772 164; Dword
PATCH_LIB("libUE4.so","0x972F3FF0","00 00 A0 E3 1E FF 2F E1"); //972F3FF0; 167 772 182; Dword
PATCH_LIB("libUE4.so","0x972F4014","00 00 A0 E3 1E FF 2F E1"); //972F4014; 167 772 172; Dword
PATCH_LIB("libUE4.so","0x973BA04C","00 00 A0 E3 1E FF 2F E1"); //973BA04C; 167 772 193; Dword
PATCH_LIB("libUE4.so","0x973BA06C","00 00 A0 E3 1E FF 2F E1"); //973BA06C; 436 207 631; Dword
PATCH_LIB("libUE4.so","0x973BA094","00 00 A0 E3 1E FF 2F E1"); //973BA094; 167 772 180; Dword
PATCH_LIB("libUE4.so","0x973BA0D0","00 00 A0 E3 1E FF 2F E1"); //973BA0D0; 167 772 165; Dword
PATCH_LIB("libUE4.so","0x973BA0E8","00 00 A0 E3 1E FF 2F E1"); //973BA0E8; 436 207 660; Dword
PATCH_LIB("libUE4.so","0x973BA1E4","00 00 A0 E3 1E FF 2F E1"); //973BA1E4; 167 772 170; Dword
PATCH_LIB("libUE4.so","0x973BA20C","00 00 A0 E3 1E FF 2F E1"); //973BA20C; 436 207 644; Dword
PATCH_LIB("libUE4.so","0x973BA24C","00 00 A0 E3 1E FF 2F E1"); //973BA24C; 436 207 655; Dword
PATCH_LIB("libUE4.so","0x973BA26C","00 00 A0 E3 1E FF 2F E1"); //973BA26C; 436 207 620; Dword
PATCH_LIB("libUE4.so","0x973BA324","00 00 A0 E3 1E FF 2F E1"); //973BA324; 167 772 170; Dword
PATCH_LIB("libUE4.so","0x973BA34C","00 00 A0 E3 1E FF 2F E1"); //973BA34C; 436 207 644; Dword
PATCH_LIB("libUE4.so","0x973BA38C","00 00 A0 E3 1E FF 2F E1"); //973BA38C; 436 207 677; Dword
PATCH_LIB("libUE4.so","0x5533b18","00 00 A0 E3 1E FF 2F E1");//[193]
PATCH_LIB("libUE4.so","0x5533b20","00 00 A0 E3 1E FF 2F E1");//[194]
PATCH_LIB("libUE4.so","0x5533b24","00 00 A0 E3 1E FF 2F E1");//[195]
PATCH_LIB("libUE4.so","0x5533b30","00 00 A0 E3 1E FF 2F E1");//[196]
PATCH_LIB("libUE4.so","0x5533b48","00 00 A0 E3 1E FF 2F E1");//[197]
PATCH_LIB("libUE4.so","0x5533b4e","00 00 A0 E3 1E FF 2F E1");//[198]
PATCH_LIB("libUE4.so","0x5533b54","00 00 A0 E3 1E FF 2F E1");//[199]
PATCH_LIB("libUE4.so","0x5533b7c","00 00 A0 E3 1E FF 2F E1");//[200]
PATCH_LIB("libUE4.so","0x5533ba0","00 00 A0 E3 1E FF 2F E1");//[201]
PATCH_LIB("libUE4.so","0x5533bac","00 00 A0 E3 1E FF 2F E1");//[202]
PATCH_LIB("libUE4.so","0x5533bbc","00 00 A0 E3 1E FF 2F E1");//[203]
PATCH_LIB("libUE4.so","0x5533bc0","00 00 A0 E3 1E FF 2F E1");//[204]
PATCH_LIB("libUE4.so","0x5533bcc","00 00 A0 E3 1E FF 2F E1");//[205]
PATCH_LIB("libUE4.so","0x5533be4","00 00 A0 E3 1E FF 2F E1");//[206]
PATCH_LIB("libUE4.so","0x5533bf4","00 00 A0 E3 1E FF 2F E1");//[207]
PATCH_LIB("libUE4.so","0x5533c08","00 00 A0 E3 1E FF 2F E1");//[208]
PATCH_LIB("libUE4.so","0x5533c0c","00 00 A0 E3 1E FF 2F E1");//[209]
PATCH_LIB("libUE4.so","0x5533c30","00 00 A0 E3 1E FF 2F E1");//[210]
PATCH_LIB("libUE4.so","0x5533c4c","00 00 A0 E3 1E FF 2F E1");//[211]
PATCH_LIB("libUE4.so","0x5533c9c","00 00 A0 E3 1E FF 2F E1");//[212]
PATCH_LIB("libUE4.so","0x5533d24","00 00 A0 E3 1E FF 2F E1");//[213]
PATCH_LIB("libUE4.so","0x5533dc0","00 00 A0 E3 1E FF 2F E1");//[214]
PATCH_LIB("libUE4.so","0x5533dd8","00 00 A0 E3 1E FF 2F E1");//[215]
PATCH_LIB("libUE4.so","0x5533e04","00 00 A0 E3 1E FF 2F E1");//[216]
PATCH_LIB("libUE4.so","0x5533e8c","00 00 A0 E3 1E FF 2F E1");//[217]
PATCH_LIB("libUE4.so","0x5533ef0","00 00 A0 E3 1E FF 2F E1");//[218]
PATCH_LIB("libUE4.so","0x5533ef4","00 00 A0 E3 1E FF 2F E1");//[219]
PATCH_LIB("libUE4.so","0x5533f04","00 00 A0 E3 1E FF 2F E1");//[220]
PATCH_LIB("libUE4.so","0x5533f20","00 00 A0 E3 1E FF 2F E1");//[221]
PATCH_LIB("libUE4.so","0x5533f48","00 00 A0 E3 1E FF 2F E1");//[222]
PATCH_LIB("libUE4.so","0x5533f50","00 00 A0 E3 1E FF 2F E1");//[223]
PATCH_LIB("libUE4.so","0x5533f70","00 00 A0 E3 1E FF 2F E1");//[224]
PATCH_LIB("libUE4.so","0x5533f7c","00 00 A0 E3 1E FF 2F E1");//[225]
PATCH_LIB("libUE4.so","0x5533fa0","00 00 A0 E3 1E FF 2F E1");//[226]
PATCH_LIB("libUE4.so","0x5533fb4","00 00 A0 E3 1E FF 2F E1");//[227]
PATCH_LIB("libUE4.so","0x5533fc4","00 00 A0 E3 1E FF 2F E1");//[228]
PATCH_LIB("libUE4.so","0x787D4","00 00 A0 E3 1E FF 2F E1");//4 00 00 0A);//[1]
PATCH_LIB("libUE4.so","0x7869C","00 00 A0 E3 1E FF 2F E1");//A 00 00 0A);//[2]
PATCH_LIB("libUE4.so","0x7868C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x785D8,","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x78564","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x784DC","00 00 A0 E3 1E FF 2F E1");//E E2 56 24);//[6]
PATCH_LIB("libUE4.so","0x784A0","00 00 A0 E3 1E FF 2F E1");//B 10 00 0A);//[7]
PATCH_LIB("libUE4.so","0x78470","00 00 A0 E3 1E FF 2F E1");//F 00 00 0A);//[8]
PATCH_LIB("libUE4.so","0x78454","00 00 A0 E3 1E FF 2F E1");//4 00 00 0A);//[9]
PATCH_LIB("libUE4.so","0x78438","00 00 A0 E3 1E FF 2F E1");// 00 00 0A);//[10]
PATCH_LIB("libUE4.so","0x783F4","00 00 A0 E3 1E FF 2F E1");//A 10 00 0A);//[11]
PATCH_LIB("libUE4.so","0x783D8","00 00 A0 E3 1E FF 2F E1");//2 00 00 81);//[12]
PATCH_LIB("libUE4.so","0x783C8","00 00 A0 E3 1E FF 2F E1");//F 00 00 0A);//[13]
PATCH_LIB("libUE4.so","0x783AC","00 00 A0 E3 1E FF 2F E1");//4 00 00 0A);//[14]
PATCH_LIB("libUE4.so","0x78390","00 00 A0 E3 1E FF 2F E1");// 00 00 0A);//[15]
PATCH_LIB("libUE4.so","0x78348","00 00 A0 E3 1E FF 2F E1");//7 10 00 0A);//[16]
PATCH_LIB("libUE4.so","0x7832C","00 00 A0 E3 1E FF 2F E1");//2 00 00 81);//[17]
PATCH_LIB("libUE4.so","0x7831C","00 00 A0 E3 1E FF 2F E1");//C 00 00 0A);//[18]
PATCH_LIB("libUE4.so","0x78304","00 00 A0 E3 1E FF 2F E1");//4 00 00 0A);//[19]
PATCH_LIB("libUE4.so","0x781D8","00 00 A0 E3 1E FF 2F E1");//A 00 00 0A);//[20]
PATCH_LIB("libUE4.so","0x781BC","00 00 A0 E3 1E FF 2F E1");//4 00 00 0A);//[21]
PATCH_LIB("libUE4.so","0x7818C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x78068","00 00 A0 E3 1E FF 2F E1");//E 20 00 0A);//[23]
PATCH_LIB("libUE4.so","0x77FF4","00 00 A0 E3 1E FF 2F E1");// 10 00 0A);//[24]
PATCH_LIB("libUE4.so","0x77FEC","00 00 A0 E3 1E FF 2F E1");//6 00 00 0A);//[25]
PATCH_LIB("libUE4.so","0x77FC8","00 00 A0 E3 1E FF 2F E1");//6 00 00 0A);//[26]
PATCH_LIB("libUE4.so","0x77F8C","00 00 A0 E3 1E FF 2F E1");//8 10 00 0A);//[27]
PATCH_LIB("libUE4.so","0x77F7C","00 00 A0 E3 1E FF 2F E1");//4 10 00 0A);//[28]
PATCH_LIB("libUE4.so","0x77F68","00 00 A0 E3 1E FF 2F E1");//5 30 00 0A);//[29]
PATCH_LIB("libUE4.so","0x77F58","00 00 A0 E3 1E FF 2F E1");// 30 00 0A);//[30]
PATCH_LIB("libUE4.so","0x77DE4","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[31]
PATCH_LIB("libUE4.so","0x77D1C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[32]
PATCH_LIB("libUE4.so","0x77D0C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[33]
PATCH_LIB("libUE4.so","0x77C64","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[34]
PATCH_LIB("libUE4.so","0x77BE8","00 00 A0 E3 1E FF 2F E1");//8 00 00 0A);//[35]
PATCH_LIB("libUE4.so","0x77BB4","00 00 A0 E3 1E FF 2F E1");//0 10 00 0A);//[36]
PATCH_LIB("libUE4.so","0x77B34","00 00 A0 E3 1E FF 2F E1");//0 00 05 31);//[37]
PATCH_LIB("libUE4.so","0x77B14","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x77AFC","00 00 A0 E3 1E FF 2F E1");//A 20 00 0A);//[39]
PATCH_LIB("libUE4.so","0x77AF0","00 00 A0 E3 1E FF 2F E1");//0 20 00 0A);//[40]
PATCH_LIB("libUE4.so","0x77944,","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x777F4","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[42]
PATCH_LIB("libUE4.so","0x777BC","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[43]
PATCH_LIB("libUE4.so","0x777A0","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[44]
PATCH_LIB("libUE4.so","0x77784","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[45]
PATCH_LIB("libUE4.so","0x77470","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[46]
PATCH_LIB("libUE4.so","0x77460","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[47]
PATCH_LIB("libUE4.so","0x77450","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[48]
PATCH_LIB("libUE4.so","0x7741C","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[49]
PATCH_LIB("libUE4.so","0x77400","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[50]
PATCH_LIB("libUE4.so","0x773E4","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[51]
PATCH_LIB("libUE4.so","0x772D4","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x772C8","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x772B0","00 00 A0 E3 1E FF 2F E1");//C 10 00 0A);//[54]
PATCH_LIB("libUE4.so","0x772A4","00 00 A0 E3 1E FF 2F E1");//2 10 00 0A);//[55]
PATCH_LIB("libUE4.so","0x77270","00 00 A0 E3 1E FF 2F E1");//5 20 00 0A);//[56]
PATCH_LIB("libUE4.so","0x771E0","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[57]
PATCH_LIB("libUE4.so","0x771D8","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x76D94","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[59]
PATCH_LIB("libUE4.so","0x76D84","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[60]
PATCH_LIB("libUE4.so","0x76CF0","00 00 A0 E3 1E FF 2F E1");//6 00 00 A1);//[61]
PATCH_LIB("libUE4.so","0x76CC4","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[62]
PATCH_LIB("libUE4.so","0x76CB4","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[63]
PATCH_LIB("libUE4.so","0x76BA0","00 00 A0 E3 1E FF 2F E1");// 10 00 0A);//[64]
PATCH_LIB("libUE4.so","0x36034","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x35FC0","00 00 A0 E3 1E FF 2F E1");//0 00 48 01);//[66]
PATCH_LIB("libUE4.so","0x35DDC","00 00 A0 E3 1E FF 2F E1");//4 88 29 47);//[67]
PATCH_LIB("libUE4.so","0x35BF8","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x35770","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x3545C","00 00 A0 E3 1E FF 2F E1");//0 00 00 53);//[70]
PATCH_LIB("libUE4.so","0x35458","00 00 A0 E3 1E FF 2F E1");//0 00 0A 31);//[71]
PATCH_LIB("libUE4.so","0x35430","00 00 A0 E3 1E FF 2F E1");//1 00 00 A1);//[72]
PATCH_LIB("libUE4.so","0x3541C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x353BC","00 00 A0 E3 1E FF 2F E1");//E 00 00 0A);//[74]
PATCH_LIB("libUE4.so","0x35380","00 00 A0 E3 1E FF 2F E1");// 00 00 0A);//[75]
PATCH_LIB("libUE4.so","0x3535C","00 00 A0 E3 1E FF 2F E1");//B 00 00 0A);//[76]
PATCH_LIB("libUE4.so","0x35048","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x3502C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[78]
PATCH_LIB("libUE4.so","0x35010","00 00 A0 E3 1E FF 2F E1");//0 00 07 24);//[79]
PATCH_LIB("libUE4.so","0x34F0C","00 00 A0 E3 1E FF 2F E1");//0 00 65 31);//[80]
PATCH_LIB("libUE4.so","0x34DE0","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x34B34","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[82]
PATCH_LIB("libUE4.so","0x348D0","00 00 A0 E3 1E FF 2F E1");//0 00 0F 97);//[83]
PATCH_LIB("libUE4.so","0x348CC","00 00 A0 E3 1E FF 2F E1");//0 00 00 D5);//[84]
PATCH_LIB("libUE4.so","0x3473C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[85]
PATCH_LIB("libUE4.so","0x3472C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[86]
PATCH_LIB("libUE4.so","0x346F8","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[87]
PATCH_LIB("libUE4.so","0x346DC","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[88]
PATCH_LIB("libUE4.so","0x346C0","00 00 A0 E3 1E FF 2F E1");//8 00 00 0A);//[89]
PATCH_LIB("libUE4.so","0x346A0","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[90]
PATCH_LIB("libUE4.so","0x342EC","00 00 A0 E3 1E FF 2F E1");//A 00 00 0A);//[91]
PATCH_LIB("libUE4.so","0x33DAC","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[92]
PATCH_LIB("libUE4.so","0x33D9C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[93]
PATCH_LIB("libUE4.so","0x33D8C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[94]
PATCH_LIB("libUE4.so","0x33D7C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[95]
PATCH_LIB("libUE4.so","0x33B40","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[96]
PATCH_LIB("libUE4.so","0x33B30","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[97]
PATCH_LIB("libUE4.so","0x33B20","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[98]
PATCH_LIB("libUE4.so","0x33B10","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[99]
PATCH_LIB("libUE4.so","0x33B00","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[100]
PATCH_LIB("libUE4.so","0x33A98","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[101]
PATCH_LIB("libUE4.so","0x33A7C","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[102]
PATCH_LIB("libUE4.so","0x33A60","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[103]
PATCH_LIB("libUE4.so","0x33A44","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[104]
PATCH_LIB("libUE4.so","0x33A0C","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[105]
PATCH_LIB("libUE4.so","0x339F0","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[106]
PATCH_LIB("libUE4.so","0x339D4","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[107]
PATCH_LIB("libUE4.so","0x1DFB4","00 00 A0 E3 1E FF 2F E1");//8 00 00 0A);//[108]
PATCH_LIB("libUE4.so","0x1DF68","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[109]
PATCH_LIB("libUE4.so","0x1DF4C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[110]
PATCH_LIB("libUE4.so","0x1DF04","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[111]
PATCH_LIB("libUE4.so","0x1DEC8","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[112]
PATCH_LIB("libUE4.so","0x1DE90","00 00 A0 E3 1E FF 2F E1");//A 00 00 0A);//[113]
PATCH_LIB("libUE4.so","0x1DE84","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[114]
PATCH_LIB("libUE4.so","0x1DE6C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x1DDE8","00 00 A0 E3 1E FF 2F E1");//8 00 00 0A);//[116]
PATCH_LIB("libUE4.so","0x1DD8C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[117]
PATCH_LIB("libUE4.so","0x1DD14","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[118]
PATCH_LIB("libUE4.so","0x1DCBC","00 00 A0 E3 1E FF 2F E1");//0 00 49 51);//[119]
PATCH_LIB("libUE4.so","0x1DCA0","00 00 A0 E3 1E FF 2F E1");//9 00 00 0A);//[120]
PATCH_LIB("libUE4.so","0x1DC5C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[121]
PATCH_LIB("libUE4.so","0x1DC3C","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[122]
PATCH_LIB("libUE4.so","0x1DC20","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[123]
PATCH_LIB("libUE4.so","0x1DBE4","00 00 A0 E3 1E FF 2F E1");//A 20 00 0A);//[124]
PATCH_LIB("libUE4.so","0x1DBD4","00 00 A0 E3 1E FF 2F E1");//9 20 00 0A);//[125]
PATCH_LIB("libUE4.so","0x1DB64","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[126]
PATCH_LIB("libUE4.so","0x1DB48","00 00 A0 E3 1E FF 2F E1");//D 00 00 0A);//[127]
PATCH_LIB("libUE4.so","0x1DB40","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x1DA88","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[129]
PATCH_LIB("libUE4.so","0x1D8D0","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x6A258","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[131]
PATCH_LIB("libUE4.so","0x6A248","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[132]
PATCH_LIB("libUE4.so","0x6A1E4","00 00 A0 E3 1E FF 2F E1");//F 10 00 0A);//[133]
PATCH_LIB("libUE4.so","0x6A1AC","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[134]
PATCH_LIB("libUE4.so","0x6A19C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[135]
PATCH_LIB("libUE4.so","0x6A0E4","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[136]
PATCH_LIB("libUE4.so","0x6A0D4","00 00 A0 E3 1E FF 2F E1");//9 00 00 0A);//[137]
PATCH_LIB("libUE4.so","0x6A0B0","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[138]
PATCH_LIB("libUE4.so","0x6A008","00 00 A0 E3 1E FF 2F E1");//9 20 00 0A);//[139]
PATCH_LIB("libUE4.so","0x69FE4","00 00 A0 E3 1E FF 2F E1");//0 20 00 0A);//[140]
PATCH_LIB("libUE4.so","0x69FD4","00 00 A0 E3 1E FF 2F E1");//C 10 00 0A);//[141]
PATCH_LIB("libUE4.so","0x69FB8","00 00 A0 E3 1E FF 2F E1");//5 10 00 0A);//[142]
PATCH_LIB("libUE4.so","0x69F7C","00 00 A0 E3 1E FF 2F E1");//6 00 00 0A);//[143]
PATCH_LIB("libUE4.so","0x69F40","00 00 A0 E3 1E FF 2F E1");//F 00 00 0A);//[144]
PATCH_LIB("libUE4.so","0x69F34","00 00 A0 E3 1E FF 2F E1");//B 00 00 0A);//[145]
PATCH_LIB("libUE4.so","0x69F04","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[146]
PATCH_LIB("libUE4.so","0x69EB8","00 00 A0 E3 1E FF 2F E1");//A 20 00 0A);//[147]
PATCH_LIB("libUE4.so","0x69E4C","00 00 A0 E3 1E FF 2F E1");//5 10 00 0A);//[148]
PATCH_LIB("libUE4.so","0x69DF8","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x69DE0","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[150]
PATCH_LIB("libUE4.so","0x69DB4","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[151]
PATCH_LIB("libUE4.so","0x69D98","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[152]
PATCH_LIB("libUE4.so","0x69D60","00 00 A0 E3 1E FF 2F E1");//3 10 00 0A);//[153]
PATCH_LIB("libUE4.so","0x69D40","00 00 A0 E3 1E FF 2F E1");//B 00 00 0A);//[154]
PATCH_LIB("libUE4.so","0x69D10","00 00 A0 E3 1E FF 2F E1");// 00 00 0A);//[155]
PATCH_LIB("libUE4.so","0x69C1C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[156]
PATCH_LIB("libUE4.so","0x69C0C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[157]
PATCH_LIB("libUE4.so","0x69BFC","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[158]
PATCH_LIB("libUE4.so","0x69B68","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[159]
PATCH_LIB("libUE4.so","0x69B58","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[160]
PATCH_LIB("libUE4.so","0x69B48","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[161]
PATCH_LIB("libUE4.so","0x69A44","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[162]
PATCH_LIB("libUE4.so","0x69A34","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[163]
PATCH_LIB("libUE4.so","0x32236C","00 00 A0 E3 1E FF 2F E1");//6 00 00 0A);//[164]
PATCH_LIB("libUE4.so","0x322360","00 00 A0 E3 1E FF 2F E1");//6 00 00 0A);//[165]
PATCH_LIB("libUE4.so","0x322350","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x3222D8","00 00 A0 E3 1E FF 2F E1");//0 00 00 A1);//[167]
PATCH_LIB("libUE4.so","0x32229C","00 00 A0 E3 1E FF 2F E1");//5 00 00 0A);//[168]
PATCH_LIB("libUE4.so","0x322284","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x322248","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x322230","00 00 A0 E3 1E FF 2F E1");//2 10 00 0A);//[171]
PATCH_LIB("libUE4.so","0x322224","00 00 A0 E3 1E FF 2F E1");//8 00 00 0A);//[172]
PATCH_LIB("libUE4.so","0x322194","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x322168","00 00 A0 E3 1E FF 2F E1");//7 20 00 0A);//[174]
PATCH_LIB("libUE4.so","0x32215C","00 00 A0 E3 1E FF 2F E1");//9 10 00 0A);//[175]
PATCH_LIB("libUE4.so","0x32214C","00 00 A0 E3 1E FF 2F E1");//0 20 00 0A);//[176]
PATCH_LIB("libUE4.so","0x322140","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x32211C","00 00 A0 E3 1E FF 2F E1");//4 10 00 0A);//[178]
PATCH_LIB("libUE4.so","0x322110","00 00 A0 E3 1E FF 2F E1");// 10 00 0A);//[179]
PATCH_LIB("libUE4.so","0x3220E8","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[180]
PATCH_LIB("libUE4.so","0x321F9C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x321EB8","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[182]
PATCH_LIB("libUE4.so","0x321EA8","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[183]
PATCH_LIB("libUE4.so","0x321E7C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x321DDC","00 00 A0 E3 1E FF 2F E1");//3 20 00 0A);//[185]
PATCH_LIB("libUE4.so","0x321DB8","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x321DA4","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x321D90","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x321D7C","00 00 A0 E3 1E FF 2F E1");//8 00 00 0A);//[189]
PATCH_LIB("libUE4.so","0x321C50","00 00 A0 E3 1E FF 2F E1");//4 00 00 0A);//[190]
PATCH_LIB("libUE4.so","0x321C30","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[191]
PATCH_LIB("libUE4.so","0x321AB8","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x321A74","00 00 A0 E3 1E FF 2F E1");//1 00 00 A1);//[193]
PATCH_LIB("libUE4.so","0x321A60","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x3219C4","00 00 A0 E3 1E FF 2F E1");//B 00 00 0A);//[195]
PATCH_LIB("libUE4.so","0x3219B0","00 00 A0 E3 1E FF 2F E1");//D 10 00 0A);//[196]
PATCH_LIB("libUE4.so","0x3219A4","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[197]
PATCH_LIB("libUE4.so","0x280BAC","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[198]
PATCH_LIB("libUE4.so","0x280B9C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[199]
PATCH_LIB("libUE4.so","0x280B88","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[200]
PATCH_LIB("libUE4.so","0x280B4C","00 00 A0 E3 1E FF 2F E1");//4 00 00 0A);//[201]
PATCH_LIB("libUE4.so","0x280B30","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[202]
PATCH_LIB("libUE4.so","0x280B20","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[203]
PATCH_LIB("libUE4.so","0x280B10","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[204]
PATCH_LIB("libUE4.so","0x280B00","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[205]
PATCH_LIB("libUE4.so","0x280AF0","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[206]
PATCH_LIB("libUE4.so","0x280978","00 00 A0 E3 1E FF 2F E1");//B 10 00 0A);//[207]
PATCH_LIB("libUE4.so","0x280950","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x280918","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x2808FC","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[210]
PATCH_LIB("libUE4.so","0x280898","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[211]
PATCH_LIB("libUE4.so","0x28087C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[212]
PATCH_LIB("libUE4.so","0x280864","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x28083C","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[214]
PATCH_LIB("libUE4.so","0x2807C0","00 00 A0 E3 1E FF 2F E1");// 00 00 0A);//[215]
PATCH_LIB("libUE4.so","0x280774","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x280714","00 00 A0 E3 1E FF 2F E1");//B 00 00 0A);//[217]
PATCH_LIB("libUE4.so","0x28068C","00 00 A0 E3 1E FF 2F E1");//6 30 00 0A);//[218]
PATCH_LIB("libUE4.so","0x280604","00 00 A0 E3 1E FF 2F E1");//B 00 00 0A);//[219]
PATCH_LIB("libUE4.so","0x2805DC","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x2804B0","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x2804A8","00 00 A0 E3 1E FF 2F E1");//B 00 00 0A);//[222]
PATCH_LIB("libUE4.so","0x280490","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[223]
PATCH_LIB("libUE4.so","0x280424","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x2803FC","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[225]
PATCH_LIB("libUE4.so","0x280274","00 00 A0 E3 1E FF 2F E1");//B 10 00 0A);//[226]
PATCH_LIB("libUE4.so","0x28024C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x280214","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x2801F8","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[229]
PATCH_LIB("libUE4.so","0x2801E4","00 00 A0 E3 1E FF 2F E1");//0 00 05 31);//[230]
PATCH_LIB("libUE4.so","0x2801E0","00 00 A0 E3 1E FF 2F E1");//B 00 00 0A);//[231]
PATCH_LIB("libUE4.so","0x2801C8","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[232]
PATCH_LIB("libUE4.so","0x28019C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[233]
PATCH_LIB("libUE4.so","0x28018C","00 00 A0 E3 1E FF 2F E1");//3 20 00 0A);//[234]
PATCH_LIB("libUE4.so","0x280110","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[235]
PATCH_LIB("libUE4.so","0x280100","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[236]
PATCH_LIB("libUE4.so","0x2800D4","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[237]
PATCH_LIB("libUE4.so","0x2800B8","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[238]
PATCH_LIB("libUE4.so","0x2800A8","00 00 A0 E3 1E FF 2F E1");//C 20 00 0A);//[239]
PATCH_LIB("libUE4.so","0x28007C","00 00 A0 E3 1E FF 2F E1");//2 10 00 0A);//[240]
PATCH_LIB("libUE4.so","0x280058","00 00 A0 E3 1E FF 2F E1");//4 10 00 0A);//[241]
PATCH_LIB("libUE4.so","0x280034","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[242]
PATCH_LIB("libUE4.so","0x28001C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x280008","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[244]
PATCH_LIB("libUE4.so","0x27FFF8","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[245]
PATCH_LIB("libUE4.so","0x27FFD4","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[246]
PATCH_LIB("libUE4.so","0x27FF24","00 00 A0 E3 1E FF 2F E1");//A 00 00 0A);//[247]
PATCH_LIB("libUE4.so","0x27FF18","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[248]
PATCH_LIB("libUE4.so","0x27FF00","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x27FE7C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[250]
PATCH_LIB("libUE4.so","0x27FE6C","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[251]
PATCH_LIB("libUE4.so","0x27FE40","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[252]
PATCH_LIB("libUE4.so","0x27FE24","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[253]
PATCH_LIB("libUE4.so","0x27FE14","00 00 A0 E3 1E FF 2F E1");//8 00 00 0A);//[254]
PATCH_LIB("libUE4.so","0x27FDF4","00 00 A0 E3 1E FF 2F E1");//0 00 00 0A);//[255]
PATCH_LIB("libUE4.so","0x27FDDC","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x27FDB4","00 00 A0 E3 1E FF 2F E1");//3 00 00 0A);//[257]
PATCH_LIB("libUE4.so","0x27FD04","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[258]
PATCH_LIB("libUE4.so","0x27FC98","00 00 A0 E3 1E FF 2F E1");//7 00 00 0A);//[259]
PATCH_LIB("libUE4.so","0x27FC7C","00 00 A0 E3 1E FF 2F E1");//0 00 15 31);//[260]
PATCH_LIB("libUE4.so","0x27FC78","00 00 A0 E3 1E FF 2F E1");//E 30 00 0A);//[261]
PATCH_LIB("libUE4.so","0x27FC28","00 00 A0 E3 1E FF 2F E1");//A 20 00 0A);//[262]
PATCH_LIB("libUE4.so","0x27FB8C","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x27FB84","00 00 A0 E3 1E FF 2F E1");
PATCH_LIB("libUE4.so","0x14fdf4","00 00 A0 E3 1E FF 2F E1");//[85]
PATCH_LIB("libUE4.so","0x14fe30","00 00 A0 E3 1E FF 2F E1");//[86]
PATCH_LIB("libUE4.so","0x14fe3c","00 00 A0 E3 1E FF 2F E1");//[87]
PATCH_LIB("libUE4.so","0x14fe98","00 00 A0 E3 1E FF 2F E1");//[88]
PATCH_LIB("libUE4.so","0x14feb0","00 00 A0 E3 1E FF 2F E1");//[89]
PATCH_LIB("libUE4.so","0x14fed8","00 00 A0 E3 1E FF 2F E1");//[90]
PATCH_LIB("libUE4.so","0x14ff14","00 00 A0 E3 1E FF 2F E1");//[91]
PATCH_LIB("libUE4.so","0x14ff30","00 00 A0 E3 1E FF 2F E1");//[92]
PATCH_LIB("libUE4.so","0x14ff58","00 00 A0 E3 1E FF 2F E1");//[93]
PATCH_LIB("libUE4.so","0x14ff74","00 00 A0 E3 1E FF 2F E1");//[94]
PATCH_LIB("libUE4.so","0x14ffa0","00 00 A0 E3 1E FF 2F E1");//[95]
PATCH_LIB("libUE4.so","0x14ffc0","00 00 A0 E3 1E FF 2F E1");//[96]
PATCH_LIB("libUE4.so","0x14ffec","00 00 A0 E3 1E FF 2F E1");//[97]
PATCH_LIB("libUE4.so","0x14fffc","00 00 A0 E3 1E FF 2F E1");//[98]
PATCH_LIB("libUE4.so","0x15000c","00 00 A0 E3 1E FF 2F E1");//[99]
PATCH_LIB("libUE4.so","0x1500d4","00 00 A0 E3 1E FF 2F E1");//[100]
PATCH_LIB("libUE4.so","0x150134","00 00 A0 E3 1E FF 2F E1");//[101]
PATCH_LIB("libUE4.so","0x150138","00 00 A0 E3 1E FF 2F E1");//[102]
PATCH_LIB("libUE4.so","0x15013c","00 00 A0 E3 1E FF 2F E1");//[103]
PATCH_LIB("libUE4.so","0x15014c","00 00 A0 E3 1E FF 2F E1");//[104]
PATCH_LIB("libUE4.so","0x15017c","00 00 A0 E3 1E FF 2F E1");//[105]
PATCH_LIB("libUE4.so","0x150184","00 00 A0 E3 1E FF 2F E1");//[106]
PATCH_LIB("libUE4.so","0x150190","00 00 A0 E3 1E FF 2F E1");//[107]
PATCH_LIB("libUE4.so","0x1501b0","00 00 A0 E3 1E FF 2F E1");//[108]
PATCH_LIB("libUE4.so","0x1501f0","00 00 A0 E3 1E FF 2F E1");//[109]
PATCH_LIB("libUE4.so","0x15021c","00 00 A0 E3 1E FF 2F E1");//[110]
PATCH_LIB("libUE4.so","0x150234","00 00 A0 E3 1E FF 2F E1");//[111]
PATCH_LIB("libUE4.so","0x15023c","00 00 A0 E3 1E FF 2F E1");//[112]
PATCH_LIB("libUE4.so","0x150260","00 00 A0 E3 1E FF 2F E1");//[113]
PATCH_LIB("libUE4.so","0x15027c","00 00 A0 E3 1E FF 2F E1");//[114]
PATCH_LIB("libUE4.so","0x1502c0","00 00 A0 E3 1E FF 2F E1");//[115]
PATCH_LIB("libUE4.so","0x1502d4","00 00 A0 E3 1E FF 2F E1");//[116]
PATCH_LIB("libUE4.so","0x15034c","00 00 A0 E3 1E FF 2F E1");//[117]
PATCH_LIB("libUE4.so","0x150390","00 00 A0 E3 1E FF 2F E1");//[118]
PATCH_LIB("libUE4.so","0x1503a4","00 00 A0 E3 1E FF 2F E1");//[119]
PATCH_LIB("libUE4.so","0x1503a8","00 00 A0 E3 1E FF 2F E1");//[120]
PATCH_LIB("libUE4.so","0x1503d0","00 00 A0 E3 1E FF 2F E1");//[121]
PATCH_LIB("libUE4.so","0x1503e8","00 00 A0 E3 1E FF 2F E1");//[122]
PATCH_LIB("libUE4.so","0x150450","00 00 A0 E3 1E FF 2F E1");//[123]
PATCH_LIB("libUE4.so","0x150454","00 00 A0 E3 1E FF 2F E1");//[124]
PATCH_LIB("libUE4.so","0x150460","00 00 A0 E3 1E FF 2F E1");//[125]
PATCH_LIB("libUE4.so","0x15046c","00 00 A0 E3 1E FF 2F E1");//[126]
PATCH_LIB("libUE4.so","0x150484","00 00 A0 E3 1E FF 2F E1");//[127]
PATCH_LIB("libUE4.so","0x150490","00 00 A0 E3 1E FF 2F E1");//[128]
PATCH_LIB("libUE4.so","0x1504c0","00 00 A0 E3 1E FF 2F E1");//[129]
PATCH_LIB("libUE4.so","0x1504d8","00 00 A0 E3 1E FF 2F E1");//[130]
PATCH_LIB("libUE4.so","0x1504e4","00 00 A0 E3 1E FF 2F E1");//[131]
PATCH_LIB("libUE4.so","0x150528","00 00 A0 E3 1E FF 2F E1");//[132]
PATCH_LIB("libUE4.so","0x15052c","00 00 A0 E3 1E FF 2F E1");//[133]
PATCH_LIB("libUE4.so","0x150548","00 00 A0 E3 1E FF 2F E1");//[134]
PATCH_LIB("libUE4.so","0x150664","00 00 A0 E3 1E FF 2F E1");//[135]
PATCH_LIB("libUE4.so","0x15067c","00 00 A0 E3 1E FF 2F E1");//[136]
PATCH_LIB("libUE4.so","0x150688","00 00 A0 E3 1E FF 2F E1");//[137]
PATCH_LIB("libUE4.so","0x15071c","00 00 A0 E3 1E FF 2F E1");//[138]
PATCH_LIB("libUE4.so","0x150720","00 00 A0 E3 1E FF 2F E1");//[139]
PATCH_LIB("libUE4.so","0x150724","00 00 A0 E3 1E FF 2F E1");//[140]
PATCH_LIB("libUE4.so","0x150728","00 00 A0 E3 1E FF 2F E1");//[141]
PATCH_LIB("libUE4.so","0x15072c","00 00 A0 E3 1E FF 2F E1");//[142]
PATCH_LIB("libUE4.so","0x150750","00 00 A0 E3 1E FF 2F E1");//[143]
PATCH_LIB("libUE4.so","0x15076c","00 00 A0 E3 1E FF 2F E1");//[144]
PATCH_LIB("libUE4.so","0x150770","00 00 A0 E3 1E FF 2F E1");//[145]
PATCH_LIB("libUE4.so","0x15077c","00 00 A0 E3 1E FF 2F E1");//[146]
PATCH_LIB("libUE4.so","0x150804","00 00 A0 E3 1E FF 2F E1");//[147]
PATCH_LIB("libUE4.so","0x150808","00 00 A0 E3 1E FF 2F E1");//[148]
PATCH_LIB("libUE4.so","0x15082c","00 00 A0 E3 1E FF 2F E1");//[149]
PATCH_LIB("libUE4.so","0x1508b0","00 00 A0 E3 1E FF 2F E1");//[150]
PATCH_LIB("libUE4.so","0x1508f0","00 00 A0 E3 1E FF 2F E1");//[151]
PATCH_LIB("libUE4.so","0x150928","00 00 A0 E3 1E FF 2F E1");//[152]
PATCH_LIB("libUE4.so","0x15092c","00 00 A0 E3 1E FF 2F E1");//[153]
PATCH_LIB("libUE4.so","0x150930","00 00 A0 E3 1E FF 2F E1");//[154]
PATCH_LIB("libUE4.so","0x150960","00 00 A0 E3 1E FF 2F E1");//[155]
PATCH_LIB("libUE4.so","0x150990","00 00 A0 E3 1E FF 2F E1");//[156]
PATCH_LIB("libUE4.so","0x1509cc","00 00 A0 E3 1E FF 2F E1");//[157]
PATCH_LIB("libUE4.so","0x1509d8","00 00 A0 E3 1E FF 2F E1");//[158]
PATCH_LIB("libUE4.so","0x150a4c","00 00 A0 E3 1E FF 2F E1");//[159]
PATCH_LIB("libUE4.so","0x150afc","00 00 A0 E3 1E FF 2F E1");//[160]
PATCH_LIB("libUE4.so","0x150b10","00 00 A0 E3 1E FF 2F E1");//[161]
PATCH_LIB("libUE4.so","0x150b14","00 00 A0 E3 1E FF 2F E1");//[162]
PATCH_LIB("libUE4.so","0x150b50","00 00 A0 E3 1E FF 2F E1");//[163]
PATCH_LIB("libUE4.so","0x150b8c","00 00 A0 E3 1E FF 2F E1");//[164]
PATCH_LIB("libUE4.so","0x150bd8","00 00 A0 E3 1E FF 2F E1");//[165]
PATCH_LIB("libUE4.so","0x150c10","00 00 A0 E3 1E FF 2F E1");//[166]
PATCH_LIB("libUE4.so","0x150c1c","00 00 A0 E3 1E FF 2F E1");//[167]
PATCH_LIB("libUE4.so","0x150c98","00 00 A0 E3 1E FF 2F E1");//[168]
PATCH_LIB("libUE4.so","0x150cb4","00 00 A0 E3 1E FF 2F E1");//[169]
PATCH_LIB("libUE4.so","0x150cd0","00 00 A0 E3 1E FF 2F E1");//[170]
PATCH_LIB("libUE4.so","0x150cfc","00 00 A0 E3 1E FF 2F E1");//[171]
PATCH_LIB("libUE4.so","0x150d1c","00 00 A0 E3 1E FF 2F E1");//[172]
PATCH_LIB("libUE4.so","0x150d28","00 00 A0 E3 1E FF 2F E1");//[173]
PATCH_LIB("libUE4.so","0x20bb48","00 00 A0 E3 1E FF 2F E1");//[174]
PATCH_LIB("libUE4.so","0x20bb68","00 00 A0 E3 1E FF 2F E1");//[175]
PATCH_LIB("libUE4.so","0x20bb94","00 00 A0 E3 1E FF 2F E1");//[176]
PATCH_LIB("libUE4.so","0x20bc00","00 00 A0 E3 1E FF 2F E1");//[177]
PATCH_LIB("libUE4.so","0x20bc20","00 00 A0 E3 1E FF 2F E1");//[178]
PATCH_LIB("libUE4.so","0x20bc4c","00 00 A0 E3 1E FF 2F E1");//[179]
PATCH_LIB("libUE4.so","0x20bccc","00 00 A0 E3 1E FF 2F E1");//[180]
PATCH_LIB("libUE4.so","0x20bce4","00 00 A0 E3 1E FF 2F E1");//[181]
PATCH_LIB("libUE4.so","0x20bd10","00 00 A0 E3 1E FF 2F E1");//[182]
PATCH_LIB("libUE4.so","0x20bd8c","00 00 A0 E3 1E FF 2F E1");//[183]
PATCH_LIB("libUE4.so","0x20bda0","00 00 A0 E3 1E FF 2F E1");//[184]
PATCH_LIB("libUE4.so","0x20bde8","00 00 A0 E3 1E FF 2F E1");//[185]
PATCH_LIB("libUE4.so","0x20c43c","00 00 A0 E3 1E FF 2F E1");//[186]
PATCH_LIB("libUE4.so","0x20c45c","00 00 A0 E3 1E FF 2F E1");//[187]
PATCH_LIB("libUE4.so","0x20c488","00 00 A0 E3 1E FF 2F E1");//[188]
PATCH_LIB("libUE4.so","0x20c4a8","00 00 A0 E3 1E FF 2F E1");//[189]
PATCH_LIB("libUE4.so","0x20c4d8","00 00 A0 E3 1E FF 2F E1");//[190]
PATCH_LIB("libUE4.so","0x20c4f4","00 00 A0 E3 1E FF 2F E1");//[191]
PATCH_LIB("libUE4.so","0x20c518","00 00 A0 E3 1E FF 2F E1");//[192]
PATCH_LIB("libUE4.so","0x20c528","00 00 A0 E3 1E FF 2F E1");//[193]
PATCH_LIB("libUE4.so","0xb65e0","00 00 A0 E3 1E FF 2F E1");//[140]
PATCH_LIB("libUE4.so","0xb6638","00 00 A0 E3 1E FF 2F E1");//[141]
PATCH_LIB("libUE4.so","0xb668c","00 00 A0 E3 1E FF 2F E1");//[142]
PATCH_LIB("libUE4.so","0xb66f8","00 00 A0 E3 1E FF 2F E1");//[143]
PATCH_LIB("libUE4.so","0xb6750","00 00 A0 E3 1E FF 2F E1");//[144]
PATCH_LIB("libUE4.so","0xb67bc","00 00 A0 E3 1E FF 2F E1");//[145]
PATCH_LIB("libUE4.so","0xb67d4","00 00 A0 E3 1E FF 2F E1");//[146]
PATCH_LIB("libUE4.so","0xb67dc","00 00 A0 E3 1E FF 2F E1");//[147]
PATCH_LIB("libUE4.so","0xb6818","00 00 A0 E3 1E FF 2F E1");//[148]
PATCH_LIB("libUE4.so","0xb6864","00 00 A0 E3 1E FF 2F E1");//[149]
PATCH_LIB("libUE4.so","0xb6878","00 00 A0 E3 1E FF 2F E1");//[150]
PATCH_LIB("libUE4.so","0xb68c4","00 00 A0 E3 1E FF 2F E1");//[151]
PATCH_LIB("libUE4.so","0xb6934","00 00 A0 E3 1E FF 2F E1");//[152]
PATCH_LIB("libUE4.so","0xb6a3c","00 00 A0 E3 1E FF 2F E1");//[153]
PATCH_LIB("libUE4.so","0xb6a70","00 00 A0 E3 1E FF 2F E1");//[154]
PATCH_LIB("libUE4.so","0xb6ac8","00 00 A0 E3 1E FF 2F E1");//[155]
PATCH_LIB("libUE4.so","0xb6af4","00 00 A0 E3 1E FF 2F E1");//[156]
PATCH_LIB("libUE4.so","0xb6b48","00 00 A0 E3 1E FF 2F E1");//[157]
PATCH_LIB("libUE4.so","0xb6b50","00 00 A0 E3 1E FF 2F E1");//[158]
PATCH_LIB("libUE4.so","0xb6b84","00 00 A0 E3 1E FF 2F E1");//[159]
PATCH_LIB("libUE4.so","0xb6b8c","00 00 A0 E3 1E FF 2F E1");//[160]
PATCH_LIB("libUE4.so","0xb6b90","00 00 A0 E3 1E FF 2F E1");//[161]
PATCH_LIB("libUE4.so","0xb6ba0","00 00 A0 E3 1E FF 2F E1");//[162]
PATCH_LIB("libUE4.so","0xb6ba8","00 00 A0 E3 1E FF 2F E1");//[163]
PATCH_LIB("libUE4.so","0xb6bb0","00 00 A0 E3 1E FF 2F E1");//[164]
PATCH_LIB("libUE4.so","0xb6bc0","00 00 A0 E3 1E FF 2F E1");//[165]
PATCH_LIB("libUE4.so","0xb6bc8","00 00 A0 E3 1E FF 2F E1");//[166]
PATCH_LIB("libUE4.so","0xb6bd0","00 00 A0 E3 1E FF 2F E1");//[167]
PATCH_LIB("libUE4.so","0xb6bec","00 00 A0 E3 1E FF 2F E1");//[168]
PATCH_LIB("libUE4.so","0xb6bf8","00 00 A0 E3 1E FF 2F E1");//[169]
PATCH_LIB("libUE4.so","0xb6c20","00 00 A0 E3 1E FF 2F E1");//[170]
PATCH_LIB("libUE4.so","0xb6c50","00 00 A0 E3 1E FF 2F E1");//[171]
PATCH_LIB("libUE4.so","0xb6c58","00 00 A0 E3 1E FF 2F E1");//[172]
PATCH_LIB("libUE4.so","0xb6ca4","00 00 A0 E3 1E FF 2F E1");//[173]
PATCH_LIB("libUE4.so","0xb6cdc","00 00 A0 E3 1E FF 2F E1");//[174]
PATCH_LIB("libUE4.so","0xb6cec","00 00 A0 E3 1E FF 2F E1");//[175]
PATCH_LIB("libUE4.so","0xb6cf0","00 00 A0 E3 1E FF 2F E1");//[176]
PATCH_LIB("libUE4.so","0xb6d04","00 00 A0 E3 1E FF 2F E1");//[177]
PATCH_LIB("libUE4.so","0xb6d10","00 00 A0 E3 1E FF 2F E1");//[178]
PATCH_LIB("libUE4.so","0xb6d14","00 00 A0 E3 1E FF 2F E1");//[179]
PATCH_LIB("libUE4.so","0xb6d18","00 00 A0 E3 1E FF 2F E1");//[180]
PATCH_LIB("libUE4.so","0xb6d24","00 00 A0 E3 1E FF 2F E1");//[181]
PATCH_LIB("libUE4.so","0xb6d30","00 00 A0 E3 1E FF 2F E1");//[182]
PATCH_LIB("libUE4.so","0xb6d34","00 00 A0 E3 1E FF 2F E1");//[183]
PATCH_LIB("libUE4.so","0x16485c","00 00 A0 E3 1E FF 2F E1");//[184]
PATCH_LIB("libUE4.so","0x164878","00 00 A0 E3 1E FF 2F E1");//[185]
PATCH_LIB("libUE4.so","0x1648a8","00 00 A0 E3 1E FF 2F E1");//[186]
PATCH_LIB("libUE4.so","0x1648e0","00 00 A0 E3 1E FF 2F E1");//[187]
PATCH_LIB("libUE4.so","0x16490c","00 00 A0 E3 1E FF 2F E1");//[188]
PATCH_LIB("libUE4.so","0x164958","00 00 A0 E3 1E FF 2F E1");//[189]
PATCH_LIB("libUE4.so","0x164988","00 00 A0 E3 1E FF 2F E1");//[190]
PATCH_LIB("libUE4.so","0x1649f4","00 00 A0 E3 1E FF 2F E1");//[191]
PATCH_LIB("libUE4.so","0x164a24","00 00 A0 E3 1E FF 2F E1");//[192]
PATCH_LIB("libUE4.so","0x164a94","00 00 A0 E3 1E FF 2F E1");//[193]
PATCH_LIB("libUE4.so","0x164ac4","00 00 A0 E3 1E FF 2F E1");//[194]
PATCH_LIB("libUE4.so","0x164b38","00 00 A0 E3 1E FF 2F E1");//[195]
PATCH_LIB("libUE4.so","0x164b68","00 00 A0 E3 1E FF 2F E1");//[196]
PATCH_LIB("libUE4.so","0x164bdc","00 00 A0 E3 1E FF 2F E1");//[197]
PATCH_LIB("libUE4.so","0x164c0c","00 00 A0 E3 1E FF 2F E1");//[198]
PATCH_LIB("libUE4.so","0x164ce0","00 00 A0 E3 1E FF 2F E1");//[199]
PATCH_LIB("libUE4.so","0x164d08","00 00 A0 E3 1E FF 2F E1");//[200]
PATCH_LIB("libUE4.so","0x164d64","00 00 A0 E3 1E FF 2F E1");//[201]
PATCH_LIB("libUE4.so","0x164d8c","00 00 A0 E3 1E FF 2F E1");//[202]
PATCH_LIB("libUE4.so","0x164de4","00 00 A0 E3 1E FF 2F E1");//[203]
PATCH_LIB("libUE4.so","0x164e0c","00 00 A0 E3 1E FF 2F E1");//[204]
PATCH_LIB("libUE4.so","0x164e7c","00 00 A0 E3 1E FF 2F E1");//[205]
PATCH_LIB("libUE4.so","0x164e98","00 00 A0 E3 1E FF 2F E1");//[206]
PATCH_LIB("libUE4.so","0x164ecc","00 00 A0 E3 1E FF 2F E1");//[207]
PATCH_LIB("libUE4.so","0x164ee4","00 00 A0 E3 1E FF 2F E1");//[208]
PATCH_LIB("libUE4.so","0x164f40","00 00 A0 E3 1E FF 2F E1");//[209]
PATCH_LIB("libUE4.so","0x164f68","00 00 A0 E3 1E FF 2F E1");//[210]
PATCH_LIB("libUE4.so","0x164fc0","00 00 A0 E3 1E FF 2F E1");//[211]
PATCH_LIB("libUE4.so","0x164fe8","00 00 A0 E3 1E FF 2F E1");//[212]
PATCH_LIB("libUE4.so","0x165044","00 00 A0 E3 1E FF 2F E1");//[213]
PATCH_LIB("libUE4.so","0x16506c","00 00 A0 E3 1E FF 2F E1");//[214]
PATCH_LIB("libUE4.so","0x1650c4","00 00 A0 E3 1E FF 2F E1");//[215]
PATCH_LIB("libUE4.so","0x1650ec","00 00 A0 E3 1E FF 2F E1");//[216]
PATCH_LIB("libUE4.so","0x165160","00 00 A0 E3 1E FF 2F E1");//[217]
PATCH_LIB("libUE4.so","0x165178","00 00 A0 E3 1E FF 2F E1");//[218]
PATCH_LIB("libUE4.so","0x20af74","00 00 A0 E3 1E FF 2F E1");//[219]
PATCH_LIB("libUE4.so","0x20af80","00 00 A0 E3 1E FF 2F E1");//[220]
PATCH_LIB("libUE4.so","0x20afc0","00 00 A0 E3 1E FF 2F E1");//[221]
PATCH_LIB("libUE4.so","0x20aff0","00 00 A0 E3 1E FF 2F E1");//[222]
PATCH_LIB("libUE4.so","0x20b01c","00 00 A0 E3 1E FF 2F E1");//[223]
PATCH_LIB("libUE4.so","0x20b02c","00 00 A0 E3 1E FF 2F E1");//[224]
PATCH_LIB("libUE4.so","0x20b080","00 00 A0 E3 1E FF 2F E1");//[225]
PATCH_LIB("libUE4.so","0x20b108","00 00 A0 E3 1E FF 2F E1");//[226]
PATCH_LIB("libUE4.so","0x20b124","00 00 A0 E3 1E FF 2F E1");//[227]
PATCH_LIB("libUE4.so","0x20b16c","00 00 A0 E3 1E FF 2F E1");//[228]
PATCH_LIB("libUE4.so","0x20b18c","00 00 A0 E3 1E FF 2F E1");//[229]
PATCH_LIB("libUE4.so","0x20b1c0","00 00 A0 E3 1E FF 2F E1");//[230]
PATCH_LIB("libUE4.so","0x20b1c4","00 00 A0 E3 1E FF 2F E1");//[231]
PATCH_LIB("libUE4.so","0x20b1fc","00 00 A0 E3 1E FF 2F E1");//[232]
PATCH_LIB("libUE4.so","0x20b22c","00 00 A0 E3 1E FF 2F E1");//[233]
PATCH_LIB("libUE4.so","0x20b2e0","00 00 A0 E3 1E FF 2F E1");//[234]
PATCH_LIB("libUE4.so","0x20b304","00 00 A0 E3 1E FF 2F E1");//[235]
PATCH_LIB("libUE4.so","0x20b310","00 00 A0 E3 1E FF 2F E1");//[236]
PATCH_LIB("libUE4.so","0x20b33c","00 00 A0 E3 1E FF 2F E1");//[237]
PATCH_LIB("libUE4.so","0x20b358","00 00 A0 E3 1E FF 2F E1");//[238]
PATCH_LIB("libUE4.so","0x20b388","00 00 A0 E3 1E FF 2F E1");//[239]
PATCH_LIB("libUE4.so","0x20b3e8","00 00 A0 E3 1E FF 2F E1");//[240]
PATCH_LIB("libUE4.so","0x20b3fc","00 00 A0 E3 1E FF 2F E1");//[241]
PATCH_LIB("libUE4.so","0x20b408","00 00 A0 E3 1E FF 2F E1");//[242]
PATCH_LIB("libUE4.so","0x20b430","00 00 A0 E3 1E FF 2F E1");//[243]
PATCH_LIB("libUE4.so","0x20b480","00 00 A0 E3 1E FF 2F E1");//[244]
PATCH_LIB("libUE4.so","0x20b498","00 00 A0 E3 1E FF 2F E1");//[245]
PATCH_LIB("libUE4.so","0x20b4b0","00 00 A0 E3 1E FF 2F E1");//[246]
PATCH_LIB("libUE4.so","0x20b55c","00 00 A0 E3 1E FF 2F E1");//[247]
PATCH_LIB("libUE4.so","0x20b66c","00 00 A0 E3 1E FF 2F E1");//[248]
PATCH_LIB("libUE4.so","0x20b6a0","00 00 A0 E3 1E FF 2F E1");//[249]
PATCH_LIB("libUE4.so","0x20b6b8","00 00 A0 E3 1E FF 2F E1");//[250]
PATCH_LIB("libUE4.so","0x20b6dc","00 00 A0 E3 1E FF 2F E1");//[251]
PATCH_LIB("libUE4.so","0x20b724","00 00 A0 E3 1E FF 2F E1");//[252]
PATCH_LIB("libUE4.so","0x20b73c","00 00 A0 E3 1E FF 2F E1");//[253]
PATCH_LIB("libUE4.so","0x20b748","00 00 A0 E3 1E FF 2F E1");//[254]
PATCH_LIB("libUE4.so","0x20b814","00 00 A0 E3 1E FF 2F E1");//[255]
PATCH_LIB("libUE4.so","0x20b910","00 00 A0 E3 1E FF 2F E1");//[256]
PATCH_LIB("libUE4.so","0x20b914","00 00 A0 E3 1E FF 2F E1");//[257]
PATCH_LIB("libUE4.so","0x20b938","00 00 A0 E3 1E FF 2F E1");//[258]
PATCH_LIB("libUE4.so","0x20ba0c","00 00 A0 E3 1E FF 2F E1");//[259]
PATCH_LIB("libUE4.so","0x20ba3c","00 00 A0 E3 1E FF 2F E1");//[260]
PATCH_LIB("libUE4.so","0x20ba64","00 00 A0 E3 1E FF 2F E1");//[261]
PATCH_LIB("libUE4.so","0x20ba78","00 00 A0 E3 1E FF 2F E1");//[262]
PATCH_LIB("libUE4.so","0x20ba9c","00 00 A0 E3 1E FF 2F E1");//[263]
PATCH_LIB("libUE4.so","0x20bad4","00 00 A0 E3 1E FF 2F E1");//[264]
PATCH_LIB("libUE4.so","0x20bae8","00 00 A0 E3 1E FF 2F E1");//[265]
PATCH_LIB("libUE4.so","0x20baec","00 00 A0 E3 1E FF 2F E1");//[266]
PATCH_LIB("libUE4.so","0x20bb34","00 00 A0 E3 1E FF 2F E1");//[267]
PATCH_LIB("libUE4.so","0x20bbc0","00 00 A0 E3 1E FF 2F E1");//[268]
PATCH_LIB("libUE4.so","0x20bbfc","00 00 A0 E3 1E FF 2F E1");//[269]
PATCH_LIB("libUE4.so","0x20bc24","00 00 A0 E3 1E FF 2F E1");//[270]
PATCH_LIB("libUE4.so","0x20bc28","00 00 A0 E3 1E FF 2F E1");//[271]
PATCH_LIB("libUE4.so","0x20bcc4","00 00 A0 E3 1E FF 2F E1");//[272]
PATCH_LIB("libUE4.so","0x20bcdc","00 00 A0 E3 1E FF 2F E1");//[273]
PATCH_LIB("libUE4.so","0x20bd1c","00 00 A0 E3 1E FF 2F E1");//[274]
PATCH_LIB("libUE4.so","0x20bd7c","00 00 A0 E3 1E FF 2F E1");//[275]
PATCH_LIB("libUE4.so","0x2a0b7c","00 00 A0 E3 1E FF 2F E1");//[276]
PATCH_LIB("libUE4.so","0x2a0bb8","00 00 A0 E3 1E FF 2F E1");//[277]
PATCH_LIB("libUE4.so","0x2a0c60","00 00 A0 E3 1E FF 2F E1");//[278]
PATCH_LIB("libUE4.so","0x2a0ca0","00 00 A0 E3 1E FF 2F E1");//[279]
PATCH_LIB("libUE4.so","0x2a0eb4","00 00 A0 E3 1E FF 2F E1");//[280]
PATCH_LIB("libUE4.so","0x2a0f50","00 00 A0 E3 1E FF 2F E1");//[281]
PATCH_LIB("libUE4.so","0x2a0f6c","00 00 A0 E3 1E FF 2F E1");//[282]
PATCH_LIB("libUE4.so","0x2a12c8","00 00 A0 E3 1E FF 2F E1");//[283]
PATCH_LIB("libUE4.so","0x2a1358","00 00 A0 E3 1E FF 2F E1");//[284]
PATCH_LIB("libUE4.so","0x2a1378","00 00 A0 E3 1E FF 2F E1");//[285]
PATCH_LIB("libUE4.so","0x2a1394","00 00 A0 E3 1E FF 2F E1");//[286]
PATCH_LIB("libUE4.so","0x2a14dc","00 00 A0 E3 1E FF 2F E1");//[287]
PATCH_LIB("libUE4.so","0x2a1578","00 00 A0 E3 1E FF 2F E1");//[288]
PATCH_LIB("libUE4.so","0x2a1594","00 00 A0 E3 1E FF 2F E1");//[289]
PATCH_LIB("libUE4.so","0x2a18f0","00 00 A0 E3 1E FF 2F E1");//[290]
PATCH_LIB("libUE4.so","0x2a19c4","00 00 A0 E3 1E FF 2F E1");//[291]
PATCH_LIB("libUE4.so","0x2a1b58","00 00 A0 E3 1E FF 2F E1");//[292]
PATCH_LIB("libUE4.so","0x2a1bf4","00 00 A0 E3 1E FF 2F E1");//[293]
PATCH_LIB("libUE4.so","0x2a1c10","00 00 A0 E3 1E FF 2F E1");//[294]
PATCH_LIB("libUE4.so","0x2a1ccc","00 00 A0 E3 1E FF 2F E1");//[295]
PATCH_LIB("libUE4.so", "0xD6A114", "00 20 70 47"); 
PATCH_LIB("libUE4.so", "0x8604C70", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD69354", "00 20 70 47");
PATCH_LIB("libUE4.so","0xD69364", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD69374", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD69384", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD69394", "00 20 70 47");
PATCH_LIB("libUE4.so","0xD693A4", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD693B4", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD693C4", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD693D4", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD693E4", "00 20 70 47");
PATCH_LIB("libUE4.so","0xD693F4", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD69404", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD69414", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD69434", "00 20 70 47");
PATCH_LIB("libUE4.so","0xD69444", "00 20 70 47"); 
PATCH_LIB("libUE4.so","0xD69454", "00 20 70 47");
PATCH_LIB("libUE4.so","0xD69464", "00 20 70 47");
PATCH_LIB("libUE4.so","0xD69474", "00 20 70 47");
PATCH_LIB("libUE4.so","0xD69484", "00 20 70 47");
PATCH_LIB("libUE4.so","0xD69494", "00 20 70 47");
PATCH_LIB("libUE4.so","0xD694A4", "00 20 70 47");
}
    
if(On){
    g_LocalPlayer->CharacterMovement->MaxAcceleration = 9999999.0f; 
g_LocalPlayer->CustomTimeDilation = 0.7f; 
g_LocalPlayer->EnergySpeedScale = 6.0f;
g_LocalPlayer->CharacterMovement->JumpZVelocity = 2200.0f; 
g_LocalPlayer->CharacterMovement->bMaintainHorizontalGroundVelocity = true; 
  }if(Of){
   g_LocalPlayer->CharacterMovement->MaxAcceleration = 10000.828f; 
g_LocalPlayer->CustomTimeDilation = 1.0f; 
g_LocalPlayer->EnergySpeedScale = 1.0f;
   g_LocalPlayer->CharacterMovement->bMaintainHorizontalGroundVelocity = false; 
g_LocalPlayer->CharacterMovement->JumpZVelocity = 500.0f; 
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
auto Actor = getActors();
    int totalEnemies = 0, totalBots = 0;

    ASTExtraPlayerCharacter *localPlayer = 0;
    ASTExtraPlayerController *localController = 0;
    
if (Config.AimBot.Enable) {
            draw->AddText({((float) density / 50.0f), 70}, IM_COL32(0, 255, 0, 255),
                          "AimSimukation 2.0 ~ Enable");
            }else{
            draw->AddText({((float) density / 50.0f), 70}, IM_COL32(255, 0, 0, 255),
                          "AimSimukation 2.0 ~ Disable");
        }

draw->AddText(NULL, ((float) density / 10.0f),{(float) glWidth / 10 + glWidth / 20,610},IM_COL32(255, 255, 255, 255),
                          "");
                          
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
            auto textSize = ImGui::CalcTextSize(s.c_str(), 0, ((float) density / 30.0f));
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
                                
       int CurHP = (int) std::max(0, std::min((int) Player->Health,100));
 int MaxHP = 100;
            

              long HPColor;
                                                    if (Player->Health < 25)
                                                       HPColor = GetRandomColorByIndex(Player->TeamID);
                                                 else if (Player->Health < 50)
                                                       HPColor = GetRandomColorByIndex(Player->TeamID);
                                                 else if ( Player->Health < 75)
                                                       HPColor = GetRandomColorByIndex(Player->TeamID);
                                                  else
                                                     
                                                       
                                                       
                                                       
                           //             int CurHP = (int) std::max(0, std::min((int) Player->Health,100));
 
    if (Player->Health == 0.0f && !Player->bDead) {//--<knocked

                                                    HPColor = GetRandomColorByIndex(Player->TeamID);

                                                    CurHP = (int) std::max(0, std::min((int) Player->NearDeathBreath, 100));
             
                                                    if (Player->NearDeatchComponent) {
                                                    MaxHP = 100;// Player->NearDeatchComponent->BreathMax; <-- you can replace to it
                                                    }}
float boxWidth = density / 1.6f;
                                                boxWidth -= std::min(
                                                        ((boxWidth / 2) / 0.001f) * Distance,
                                                        boxWidth / 2);
                                                float boxHeight = boxWidth * 0.15f;


                                                ImVec2 vStart = {headPosSC.x - (boxWidth / 2), headPosSC.y - (boxHeight * 2.001f)};

                                                ImVec2 vEndFilled = {vStart.x + (CurHP * boxWidth / MaxHP), 
                                 vStart.y + boxHeight};
            
                                                ImVec2 vEndRect = {vStart.x + boxWidth, vStart.y + boxHeight};
                   
            draw->AddRectFilledMultiColor(vStart, vEndFilled, GetRandomColorByIndex(Player->TeamID), HPColor, HPColor, GetRandomColorByIndex(Player->TeamID));
            
                                                draw->AddRect(vStart, vEndRect,
                                                              1.0f);
                                            
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
                         
												  
							auto textSize = ImGui::CalcTextSize(s.c_str(), 0, ((float) density / 30.0f));
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
								auto textSize = ImGui::CalcTextSize(t.c_str(), 0, ((float) density / 17.0f));
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
    
int TotalCount = totalEnemies;
ImGui::SetNextWindowPos(ImVec2(static_cast<float>(glWidth) / 2, 50), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
ImGui::SetNextWindowSize(ImVec2(230.0f, 40.0f));
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 20.0f);
ImGui::Begin("PonCount", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove);
ImGui::SetCursorPos(ImVec2(10, 10));
ImGui::Text("    P: %d", totalEnemies);
   ImGui::SameLine();
ImGui::Text(" BEKA ENGINE  B: %d", totalBots);
ImGui::End();
ImGui::PopStyleVar();	


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
        std::string sRedLink = "https://free.suhani.site/connect";

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
     EXP = result["data"]["EXP"].get<std::string>();
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

std::string inputText = "";
static char b[64] = "";
void AddKeyButton(const char* name) {
    if (ImGui::Button(name, ImVec2(50, 50))) {
        inputText += name;  
		  strncpy(b, inputText.c_str(), sizeof(b));
		
    }
    ImGui::SameLine(0, 5.0f);  
}


#include <iostream>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string getGitHubFile(const std::string& url) {
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    std::string readBuffer;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return readBuffer;
}

int main() {
    std::string url = "https://api.github.com/repos/yourusername/yourrepo/releases/latest";
    std::string fileContent = getGitHubFile(url);
    std::cout << fileContent << std::endl;  // выводим полученные данные
    return 0;
}

void downloadFile(const std::string& fileUrl, const std::string& savePath) {
    CURL* curl;
    CURLcode res;
    FILE* fp = fopen(savePath.c_str(), "wb");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, fileUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    fclose(fp);
}




void AddKeyButtonWithShift(const char* lower, const char* upper) {
    std::string name = shiftPressed ? upper : lower;
    if (ImGui::Button(name.c_str(), ImVec2(50, 50))) {
        inputText += name;
        
  strncpy(b, inputText.c_str(), sizeof(b));
    }
    ImGui::SameLine(0, 5.0f);
}
void AddSpecialKeyButton(const char* label, const char* value) {
    if (ImGui::Button(label, ImVec2(50, 50))) {
        inputText += value;
         strncpy(b, inputText.c_str(), sizeof(b));
    }
    ImGui::SameLine(0, 5.0f);
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

系统屏幕宽 = ANativeWindow_getWidth(g_App->window);
系统屏幕高 = ANativeWindow_getHeight(g_App->window);
    screenWidth = ANativeWindow_getWidth(g_App->window);
    screenHeight = ANativeWindow_getHeight(g_App->window);
    density = AConfiguration_getDensity(g_App->config);
    
    
    
    
    

    // if (!initImGui) {
   // ImGui::CreateContext();
 // ImGuiStyle* style = &ImGui::GetStyle();
    
// ImGui_ImplAndroid_Init();
        // ImGui_ImplOpenGL3_Init("#version 300 es");

      if (!initImGui) {
ImGui::CreateContext();
    InitTexture();
ImGuiStyle* style = &ImGui::GetStyle();
   style->Colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 0, 255); // Цвет захвата слайдера на желтый
style->Colors[ImGuiCol_CheckMark] = ImColor(125, 91, 255);
// style->Colors[ImGuiCol_WindowBg]  = ImColor(24, 24, 24, 200); // Полупрозрачный темный фон
style->Colors[ImGuiCol_WindowBg] = ImColor(255, 255, 255, 150); // Белый фон с прозрачностью
style->Colors[ImGuiCol_Border]                = ImColor(65, 65, 65, 255);  // Цвет границы

// Цвета заголовка
style->Colors[ImGuiCol_TitleBg]               = ImColor(0, 0, 0, 255);     // Черный цвет заголовка
style->Colors[ImGuiCol_TitleBgActive]         = ImColor(0, 0, 0, 255);     // Активный заголовок
style->Colors[ImGuiCol_TitleBgCollapsed]      = ImColor(0, 0, 0, 125);     // Сложенный заголовок (прозрачный)
// Цвета для кнопок
style->Colors[ImGuiCol_Button]                 = ImColor(125, 91, 255);   // Красная кнопка
style->Colors[ImGuiCol_ButtonHovered]          = ImColor(40, 40, 40, 255);   // Темный красный при наведении
style->Colors[ImGuiCol_ButtonActive]           = ImColor(40, 40, 40, 255);   // Более темный красный при активации
// Цвет текста
style->Colors[ImGuiCol_Text] = ImColor(90, 202, 203); // Голубой цвет текста
    style->Colors[ImGuiCol_TextDisabled] = ImColor(150, 200, 255, 255); // Светло-голубой для неактивного текста
// Цвет фона для выделенных элементов
style->Colors[ImGuiCol_ChildBg]                = ImColor(24, 24, 24, 140);    // Цвет фона для дочерних окон
style->Colors[ImGuiCol_FrameBg]                = ImColor(30, 30, 30, 255);    // Цвет фона для рамок
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
            
          io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 18.f, &CustomFont);
       io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 20.0f, &icons_config, icons_ranges);

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
        static bool Beka0;
static bool openmenu = true;
        static bool anticrack = false;
if (openmenu){
        if (ImGui::Begin(" XERO 3 ", 0,ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings)) {
        if (ImGui::Button(OBFUSCATE("  OPEN  "), ImVec2(60, 50))) {

        Beka0 = true; }
	

}}
               if (Beka0){
     
ImGui::SetNextWindowPos(ImVec2(530, 100), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.42f, (float) glHeight * 0.62f), ImGuiCond_Once);
ImGui::Begin("beka32", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);{
	ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.49f, (float) glHeight * 0.64f),ImGuiCond_Once);
ImGui::Begin( "Menu",&Beka0, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar);
	
    static bool p_open = true;
        static bool isLogin = true;
if(Klavye){
   if(ImGui::Begin("##2whsusv8",&Klavye,ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize ))	{		
         
   ImGui::InputText("##name", b, sizeof b);
   
    AddKeyButtonWithShift("q", "Q"); AddKeyButtonWithShift("w", "W"); AddKeyButtonWithShift("e", "E");
    AddKeyButtonWithShift("r", "R"); AddKeyButtonWithShift("t", "T"); AddKeyButtonWithShift("y", "Y");
    AddKeyButtonWithShift("u", "U"); AddKeyButtonWithShift("i", "I"); AddKeyButtonWithShift("o", "O");
    AddKeyButtonWithShift("p", "P");
    ImGui::NewLine();
    ImGui::Dummy(ImVec2(25, 0));
    ImGui::SameLine();
    AddKeyButtonWithShift("a", "A"); AddKeyButtonWithShift("s", "S"); AddKeyButtonWithShift("d", "D");
    AddKeyButtonWithShift("f", "F"); AddKeyButtonWithShift("g", "G"); AddKeyButtonWithShift("h", "H");
    AddKeyButtonWithShift("j", "J"); AddKeyButtonWithShift("k", "K"); AddKeyButtonWithShift("l", "L");
    ImGui::NewLine();
    ImGui::Dummy(ImVec2(50, 0));
    ImGui::SameLine();
    AddKeyButtonWithShift("z", "Z"); AddKeyButtonWithShift("x", "X"); AddKeyButtonWithShift("c", "C");
    AddKeyButtonWithShift("v", "V"); AddKeyButtonWithShift("b", "B"); AddKeyButtonWithShift("n", "N");
    AddKeyButtonWithShift("m", "M"); AddSpecialKeyButton(",", ","); AddSpecialKeyButton(".", ".");
    ImGui::NewLine();
    if (ImGui::Button(shiftPressed ? "SHIFT" : "shift", ImVec2(75, 50))) {
        shiftPressed = !shiftPressed;}
    ImGui::SameLine();
    if (ImGui::Button("Space", ImVec2(200, 50))) {
        inputText += " ";
        strncpy(b, inputText.c_str(), sizeof(b));
    }
    ImGui::SameLine();
    if (ImGui::Button("Delete", ImVec2(75, 50))) {
        if (!inputText.empty()) {
            inputText.pop_back();
            strncpy(b, inputText.c_str(), sizeof(b));
        }
    }
    ImGui::SameLine();
    if (ImGui::Button("PASTE", ImVec2(75, 50))) {
        Klavye = false;
    }
ImGui::NewLine();
    AddKeyButton("1"); AddKeyButton("2"); AddKeyButton("3"); AddKeyButton("4"); AddKeyButton("5");
    AddKeyButton("6"); AddKeyButton("7"); AddKeyButton("8"); AddKeyButton("9"); AddKeyButton("0");
    ImGui::NewLine();

    AddSpecialKeyButton("!", "!"); AddSpecialKeyButton("@", "@"); AddSpecialKeyButton("#", "#");
    AddSpecialKeyButton("$", "$"); AddSpecialKeyButton("%", "%"); AddSpecialKeyButton("_", "_");
    AddSpecialKeyButton("&", "&"); AddSpecialKeyButton("*", "*"); AddSpecialKeyButton("(", "(");
    AddSpecialKeyButton(")", ")");
    ImGui::NewLine();
    ImGui::End();}}
    
        if (!isLogin) {
            ImGui::Text("Please Login! (Copy Key to @Terrible_Pm)");

            ImGui::PushItemWidth(-1);
            static char s[64];
          
            ImGui::InputText("##key", s, sizeof s);
            ImGui::PopItemWidth();
            ImGui::Text(" ");
            ImGui::InputText("##name", b, sizeof b);
            ImGui::PopItemWidth();
               ImGui::SameLine(); 
               if (ImGui::Button("  Your Name  ", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
    Klavye = true;
}

ImGui::Separator(); 

if (ImGui::Button("  Paste Your Key  ", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
    auto key = getClipboardText();
    strncpy(s, key.c_str(), sizeof(s) - 1);
    s[sizeof(s) - 1] = '0'; // Обеспечиваем нулевое окончание
}

static std::string err;
if (ImGui::Button("Login", ImVec2(ImGui::GetContentRegionAvail().x, 0))) {
    err = Login(s);
    if (err == "OK") {
        isLogin = bValid && g_Auth == g_Token;
    }
}

            if (!err.empty() && err != "OK") {
                ImGui::Text("Error: %s", err.c_str());
            }
        } else {
        anticrack = true;
        }
		if(anticrack){
	    ImGui::SetCursorPos(ImVec2(600, 0));
	    ImGui::BeginChild(" ", ImVec2(185, 450), true); {
        ImGui::TextColored(ImColor(255, 255, 255, 255), "BEKA ENGINE v1    ");
        ImGui::SameLine();      
        if (ImGui::Button("X", ImVec2(35, 30))) { Beka0 = false;}
        ImGui::TextColored(ImColor(255, 255, 255, 255), "    ");
        ImGui::SameLine();      
        ImGui::Image(logo5.textureId, {100, 100});
        ImGui::Separator();
	    if(ImGui::BekaButton( "     Main  ",  Settings::Tab == 4))
		Settings::Tab = 4;
		ImGui::Separator();	
        if(ImGui::BekaButton( "     Esp   ",  Settings::Tab == 1)) 
		Settings::Tab = 1;
		ImGui::Separator();	
        if(ImGui::BekaButton( "     Aimbot",  Settings::Tab == 2)) 
  	    Settings::Tab = 2;
  	    ImGui::Separator();	
	    if(ImGui::BekaButton( "     Settings",  Settings::Tab == 5)) 
  	    Settings::Tab = 5;

				ImGui::TextColored(ImColor(250, 255, 265, 255),EXP.c_str());  	
		        }ImGui::EndChild();
		        
		       	if (Settings::Tab == 1) {
		       	ImGui::SetCursorPos(ImVec2(0, 0));
	            ImGui::BeginChild(" espp1", ImVec2(298, 449), true); {
                ImVec2 windowSize = ImGui::GetContentRegionAvail();
                float buttonWidth = windowSize.x / 2.2f; 
                float buttonHeight = 40.0f; 
                float spacing = 5.0f; 
                ImGui::Spacing();
                ImGui::BeginChild(" All", ImVec2(283, 33), true); {
                ImGui::Checkbox(u8"Enable All", &alll);    
                }ImGui::EndChild();  
	            ImGui::BeginChild(" esp1", ImVec2(283, 33), true); {
                ImGui::Checkbox(u8"Esp Health", &Config.PlayerESP.Health);
                }ImGui::EndChild();
                ImGui::BeginChild(" esp2", ImVec2(283, 33), true); {
                ImGui::Checkbox(u8"ESP Alert", &Config.PlayerESP.Alert);
                }ImGui::EndChild();
                ImGui::BeginChild(" esp3", ImVec2(283, 33), true); {
                ImGui::Checkbox(u8"Esp Name", &Config.PlayerESP.Name);    
                }ImGui::EndChild();   
                ImGui::BeginChild(" esp4", ImVec2(283, 33), true); {
                ImGui::Checkbox(u8"Esp Distance", &Config.PlayerESP.Distance);  
                }ImGui::EndChild();
                ImGui::BeginChild(" esp5", ImVec2(283, 33), true); {
                ImGui::Checkbox(u8"Esp TeamID", &Config.PlayerESP.TeamID);
                }ImGui::EndChild();
                ImGui::BeginChild(" esp6", ImVec2(283, 33), true); {
                ImGui::Checkbox(u8"ESP Vehicle", &Config.PlayerESP.Vehicle);
                }ImGui::EndChild();
if (ImGui::BeginPopupModal("New update available!", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::Text("Do you want to download?");
    if (ImGui::Button("Yes")) {
        downloadFile("https://github.com/yourusername/yourrepo/releases/download/latest/file.zip", "file.zip");
        ImGui::CloseCurrentPopup();
    }
    ImGui::SameLine();
    if (ImGui::Button("No")) {
        ImGui::CloseCurrentPopup();
    }
    ImGui::EndPopup();
}
                }ImGui::EndChild();
 
       	        ImGui::SetCursorPos(ImVec2(299, 0));
	            ImGui::BeginChild(" esp32", ImVec2(304, 449), true); {
	            ImGui::BeginChild(" espwjj", ImVec2(284, 33), true); {
                ImGui::Checkbox(u8"ESP Box3D", &Config.PlayerESP.Box3D);
                }ImGui::EndChild();
                ImGui::BeginChild(" esp8", ImVec2(284, 33), true); {
                ImGui::Checkbox(u8"ESP Bone", &Config.PlayerESP.Skeleton);
                }ImGui::EndChild();
                ImGui::BeginChild(" esp9", ImVec2(284, 33), true); {
                ImGui::Checkbox(u8"ESP Line", &Config.PlayerESP.LineTop);
                }ImGui::EndChild();
                ImGui::BeginChild(" esp10", ImVec2(284, 33), true); {
                ImGui::Checkbox(u8"ESP V-Fuel", &Config.PlayerESP.VehicleFuel);
                }ImGui::EndChild();
                ImGui::BeginChild(" esp11", ImVec2(284, 33), true); {
                ImGui::Checkbox(u8"ESP V-Hp", &Config.PlayerESP.VehicleHP);
                }ImGui::EndChild();
                ImGui::BeginChild(" esp12", ImVec2(284, 33), true); {
                ImGui::Checkbox(u8"Granade Alert", &Config.PlayerESP.Grenade);
                }ImGui::EndChild();
                ImGui::BeginChild(" esp13", ImVec2(284, 33), true); {
                ImGui::Checkbox(u8"ESP LootBox", &Config.PlayerESP.LootBox);
                }ImGui::EndChild();
                
                }ImGui::EndChild();}
                
	 		    if (Settings::Tab == 5) {
		       	ImGui::SetCursorPos(ImVec2(0, 0));
	            ImGui::BeginChild(" Main", ImVec2(599, 450), true); {
	            ImGui::BulletText("Settings"); 
	            ImGui::Separator();	
	            if (ImGui::Button("Name", ImVec2(75, 50))) {
                Klavye = true;
                }
	            ImGui::BulletText("Memory"); 
	            ImGui::Separator();	
	            ImGui::Checkbox("Fly (ban)", &On);
	            ImGui::Checkbox("Disable Fly", &Of);
	            ImGui::Separator();	
	            }}
		      	if (Settings::Tab == 4) {
		       	ImGui::SetCursorPos(ImVec2(0, 0));
	            ImGui::BeginChild(" Main", ImVec2(599, 450), true); {
	            ImGui::BulletText("Main Menu"); 
	            ImGui::Text (" Device resolution is: %dx%d", 系统屏幕宽, 系统屏幕高);
	            	if (ImGui::SubTab(0 == Settings::Tab, "OPEN TELEGRAM", ImVec2(180, 62))) Settings::Tab = 0;

	        //    ImGui::TextColored(ImColor(0, 255, 0,225), " libUE4.so: 0x%lX  <驱动正常>", UE4数据存储);  
               // SuperText("Welcome user");
	            }}
	            
			   	if (Settings::Tab == 2) {
		       	ImGui::SetCursorPos(ImVec2(0, 0));
	            ImGui::BeginChild(" Aimbot", ImVec2(599, 450), true); {
	   	        ImGui::BulletText("Aimbot"); 
	   	        ImGui::Separator();
                ImGui::Checkbox((u8"Aimbot 150M"), &Config.AimBot.Enable);
             //   ImGui::SameLine(300);           
                ImGui::Checkbox((u8"BT 50° (risk)"), &Config.SilentAim.Enable);
                ImGui::Text(" ");
                ImGui::Separator();	
		        static int slider_test_0 = 50;
		        ImGui::SliderFloat("Aim fov", &Config.AimBot.Cross, 0.0f, 400.0f);
		        ImGui::SliderFloat("Anti-Recoil", &Config.Recc, 0.0f, 2.0f);
		        ImGui::Text("");
	            static const char *triggers[] = {"Always", "Shooting"};
	     	    ImGui::Combo("Trigger", (int *) &Config.AimBot.Trigger, triggers, 1, -1);
                ImGui::Checkbox("Visibility Check", &Config.AimBot.VisCheck);
		        ImGui::Checkbox("Ignore Knock", &Config.AimBot.IgnoreKnocked);
                ImGui::Checkbox("Ignore Bot", &Config.AimBot.IgnoreBot);				
                    } }           
		 }
      } 
   }

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

uintptr_t GetLibMapFileSize(const char *libraryName) {
    if(strstr(libraryName, "anon:libc_malloc"))
    return 0;
    FILE *fp = fopen("/proc/self/maps", "rt");
    uintptr_t baseAddress = 0;
    if (fp != NULL) {
        char line[512] = {0};
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, libraryName)) {
                uintptr_t startAddr, endAddr;
                sscanf(line, "%lx-%lx", &startAddr, &endAddr);
                baseAddress = endAddr - startAddr;
                break;
            }
        }
       fclose(fp);
    }
 return baseAddress;
}


unsigned int libanogsSize = GetLibMapFileSize("libanogs.so");
unsigned int libUE4Size = GetLibMapFileSize("libUE4.so");

long new_UE4, libUE4, safe;
long UE4_size = 0;
long new_anogs, libanogs, safe1;
long anogs_size = 0;

size_t getLibrarySize(const char *libraryName)
{
    FILE *mapsFile = fopen("/proc/self/maps", "r");
    if (mapsFile == nullptr)
    {
        return 0;
    }

    char line[256];
    size_t size = 0;
    uintptr_t startAddr = 0, endAddr = 0;
    while (fgets(line, sizeof(line), mapsFile))
    {
        if (strstr(line, libraryName))
        {
            sscanf(line, "%lx-%lx", &startAddr, &endAddr);
            size = endAddr - startAddr;
            break;
        }
    }

    fclose(mapsFile);
    return size;
}

char *Offset;

 

long GetModuleBase(const char *name)
{
 char buff[1024];
 long address = 0;
 FILE *fp = fopen("/proc/self/maps", "r");
 while (fgets(buff, sizeof(buff), fp))
 {
  if (strstr(buff, name))
  {
   sscanf(buff, "%lx-%*lx", &address);
   fclose(fp);
   return address;
  }
 }
 fclose(fp);
 return 0;
}

size_t GetLibrarySize(const char* libName) {
    std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));

    if (strcmp(libName, "libUE4.so") == 0) {
        std::uniform_int_distribution<size_t> dist(0x22EDF68, 0x825CE6C); // Диапазон для libUE4.so
        return dist(rng);
    } else {
        std::cerr << "Unknown library: " << libName << std::endl;
        return 0;
    }
}

uintptr_t GetRandomAddress(uintptr_t baseAddress, size_t librarySize) {
    std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<size_t> dist(0, librarySize - 1);
    return baseAddress + dist(rng);
}

void PatchMemory(uintptr_t address, const uint8_t* newBytes, size_t size) {
    if (mprotect(reinterpret_cast<void*>(address & ~(sysconf(_SC_PAGESIZE) - 1)), 
                  sysconf(_SC_PAGESIZE), PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        std::cerr << "Failed to change memory protection." << std::endl;
        return;
    }
    memcpy(reinterpret_cast<void*>(address), newBytes, size);
}

uintptr_t GetLibraryBaseAddress(const char* libName) {
    void* handle = dlopen(libName, RTLD_NOW);
    if (!handle) {
        std::cerr << "Failed to load library: " << dlerror() << std::endl;
        return 0;
    }
    return reinterpret_cast<uintptr_t>(handle);
}

void PatchLibrary(const char* libraryName) {
    uintptr_t baseAddress = GetLibraryBaseAddress(libraryName);

    if (baseAddress == 0) {
        return; 
    }
size_t librarySize = GetLibrarySize(libraryName);
    std::vector<uint8_t> newBytes = { 0x00, 0x00, 0xA0, 0xE3, 0x1E, 0xFF, 0x2F, 0xE1 }; 
    size_t size = newBytes.size();

    size_t patchCount = 0; 

    while (true) {
        uintptr_t targetAddress = GetRandomAddress(baseAddress, librarySize);
        PatchMemory(targetAddress, newBytes.data(), size);
        patchCount++;

        std::cout << "Patched memory in " << libraryName << " | Successful patches: " << patchCount << std::endl;

        usleep(1);  
    }
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_myapp_MainActivity_patchMemory(JNIEnv *env, jobject /* this */) {
    const char* libraries[] = { "libUE4.so" }; 
    std::vector<std::thread> threads;

    for (const char* library : libraries) {
        threads.emplace_back(PatchLibrary, library); 
    }

    for (auto& thread : threads) {
        thread.join(); 
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
