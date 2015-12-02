#include "Hooks.hpp"
#include "jmphookedfunction.hpp"
#include <cstdint>


//static FILE* fp = 0;
static void** ppBufApp0xC10 = (void**)(0x1A79F60);

void* getBufApp0xC10()
{
    void* pReturn = *ppBufApp0xC10;

    return pReturn;
}

struct FFModuleInterface
{
    uint32_t initSystems;
    uint32_t exitSystems;
    uint32_t field08;
    uint32_t field0C;
    uint32_t mainLoop;
    uint32_t mouseInputHandler;
    uint32_t keyboardInputHandler;
};

struct BufApp0xC10
{
    uint32_t field000;
    uint32_t field004;
    uint32_t field008;
    uint32_t field00C;
    uint32_t fieldRest0[661];
    uint32_t isRequestedModuleChange;   // 0xA64
    uint32_t fieldRest1[50];
    FFModuleInterface currentModule;    // 0xB30
    FFModuleInterface nextModule;       // 0xB4C
    uint32_t fieldRest2[42];            // 0xB68
};

uint32_t FFSwitchModule(FFModuleInterface* pFFModuleInterface, BufApp0xC10* pBufApp0xC10)
{
    if (pFFModuleInterface == 0)
        return 0;

    if (pBufApp0xC10 == 0)
        return 0;

    if (pBufApp0xC10->isRequestedModuleChange != 0)
        return 0;

    // Copy Module Interface to pBufApp0xC10
    memcpy(&pBufApp0xC10->nextModule, pFFModuleInterface, sizeof(FFModuleInterface));

    pBufApp0xC10->isRequestedModuleChange = 1;

    // Dump the module's mainLoop address to the file for debug
    fprintf(fp, "Module switch, mainLoop = 0x%08x\n", pFFModuleInterface->mainLoop);
    fflush(fp);

    return 1;
}

struct colorBGRA
{
    float B;
    float G;
    float R;
    float A;
};

typedef uint64_t FFTime;

uint32_t (*sub_45B2E0)() = (uint32_t (*)())0x45B2E0;
FFTime* pDWORD_1D2BD60 = (FFTime*)0x1D2BD60;
void (*FFSetBGMaterial_Gx_real)(colorBGRA*, BufApp0xC10*) = (void (*)(colorBGRA*, BufApp0xC10*))0x41E168;
void (*FFClearViewport_Gx_real)(uint32_t, uint32_t, uint32_t, BufApp0xC10*) = (void (*)(uint32_t, uint32_t, uint32_t, BufApp0xC10*))0x41DFBA;
uint32_t (*FFBeginAndDrawScene_Gx)(uint32_t, BufApp0xC10*) = (uint32_t (*)(uint32_t, BufApp0xC10*))0x41E972;
void (*sub_43FBE8)(BufApp0xC10*) = (void (*)(BufApp0xC10*))0x43FBE8;
void (*sub_409B42)(BufApp0xC10*) = (void (*)(BufApp0xC10*))0x409B42;
void (*sub_409B08)(BufApp0xC10*) = (void (*)(BufApp0xC10*))0x409B08;
void (*sub_409B25)(BufApp0xC10*) = (void (*)(BufApp0xC10*))0x409B25;
uint32_t* pDWORD_1D2A45C = (uint32_t*)0x1D2A45C;
void (*sub_416B9A)(uint32_t) = (void (*)(uint32_t))0x416B9A;
uint32_t* pDWORD_1D2A460 = (uint32_t*)0x1D2A460;
void (*sub_424BF9)(uint32_t) = (void (*)(uint32_t))0x424BF9;
void (*sub_49B120)() = (void (*)())0x49B120;
void (*sub_56B870)() = (void (*)())0x56B870;
uint32_t (*sub_497380)(uint32_t, uint32_t, uint32_t, uint32_t) = (uint32_t (*)(uint32_t, uint32_t, uint32_t, uint32_t))0x497380;
uint32_t* pDWORD_1D2BD74 = (uint32_t*)0x1D2BD74;
uint32_t* pDWORD_1CD30A0 = (uint32_t*)0x1CD30A0;
void (*sub_56D7F0)() = (void (*)())0x56D7F0;
void (*FFGetTime_real)(FFTime*) = (void (*)(FFTime*))0x40AA12;
void (*FFGetTimeDiff_real)(FFTime*, FFTime*, FFTime*) = (void (*)(FFTime*, FFTime*, FFTime*))0x40AA62;
double (*FFConvertU64ToDouble_real)(FFTime*) = (double (*)(FFTime*))0x40AAEF;
double* pDbl_1D2BD58 = (double*)0x1D2BD58;
void (*sub_4980C0)() = (void (*)())0x4980C0;
void (*sub_56B880)(uint32_t, BufApp0xC10*) = (void (*)(uint32_t, BufApp0xC10*))0x56B880;
void (*FFDrawSceneIndex_Gx_real)(uint32_t, BufApp0xC10*) = (void (*)(uint32_t, BufApp0xC10*))0x41E947;
uint32_t* pDWORD_206AD28 = (uint32_t*)0x206AD28;
uint32_t* pDWORD_206AD30 = (uint32_t*)0x206AD30;
void (*sub_499EA0)() = (void (*)())0x499EA0;
void (*sub_45B450)() = (void (*)())0x45B450;
void (*sub_499A40)() = (void (*)())0x499A40;
void (*FFEndScene_Gx_real)(BufApp0xC10*) = (void (*)(BufApp0xC10*))0x41E99D;

void nullSub()
{
}

// start Menu main loop = 0x4A2320
void startMenuMainLoop(BufApp0xC10* pBufApp0xC10)
{
    pDWORD_1D2BD60[0] = pDWORD_1D2BD60[1];

    if (sub_45B2E0() != 0)
        return;

    colorBGRA bgColor;
    bgColor.B = 0.0f;
    bgColor.G = 0.0f;
    bgColor.R = 0.0f;
    bgColor.A = 1.0f;
    FFSetBGMaterial_Gx_real(&bgColor, pBufApp0xC10);

    FFClearViewport_Gx_real(1, 1, 1, pBufApp0xC10);

    if (FFBeginAndDrawScene_Gx(0, pBufApp0xC10) != 0)
    {
        sub_43FBE8(pBufApp0xC10);
        sub_409B42(pBufApp0xC10);
        sub_409B08(pBufApp0xC10);
        sub_409B25(pBufApp0xC10);
        sub_416B9A(*pDWORD_1D2A45C);
        sub_424BF9(*pDWORD_1D2A460);
        sub_49B120();
        uint32_t result = sub_497380(0x19, 0, 0, 0);

        if ((result & 0x400) != 0)
        {
            *pDWORD_1D2BD74 = result;
            *pDWORD_1CD30A0 = (result & 2) >> 1;
            FFModuleInterface newModule;
            newModule.field08 = 0x470550;
            newModule.field0C = (uint32_t)nullSub;
            newModule.mainLoop = 0x470620;
            newModule.mouseInputHandler = 0;
            newModule.keyboardInputHandler = 0;
            FFSwitchModule(&newModule, pBufApp0xC10);
        }

        sub_4980C0();
        sub_56B880(*pDWORD_206AD28, pBufApp0xC10);
        FFDrawSceneIndex_Gx_real(1, pBufApp0xC10);
        sub_56B880(*pDWORD_206AD30, pBufApp0xC10);
        sub_499EA0();
        sub_45B450();
        sub_499A40();
        FFEndScene_Gx_real(pBufApp0xC10);
    }

    sub_56D7F0();
    double timeDiff;

    do
    {
        FFGetTime_real(&pDWORD_1D2BD60[1]);
        FFTime frameTime;
        FFGetTimeDiff_real(&pDWORD_1D2BD60[1], &pDWORD_1D2BD60[0], &frameTime);
        //timeDiff = FFConvertU64ToDouble_real(&frameTime);
        timeDiff = (double)(frameTime);
    } while (timeDiff < *pDbl_1D2BD58);

    fprintf(fp, "Menu main loop, frame time = %f\n", timeDiff);
    fflush(fp);

    pDWORD_1D2BD60[0] = pDWORD_1D2BD60[1];
}

typedef decltype(&getBufApp0xC10) GetBufApp0xC10_type;
static GetBufApp0xC10_type real_GetBufApp0xC10 = (GetBufApp0xC10_type)0x0040A04A;
static JmpHookedFunction<GetBufApp0xC10_type>* GetBufApp0xC10_hook;

typedef decltype(&FFSwitchModule) FFSwitchModule_type;
static FFSwitchModule_type real_FFSwitchModule = (FFSwitchModule_type)0x00409A57;
static JmpHookedFunction<FFSwitchModule_type>* FFSwitchModule_hook;

typedef decltype(&startMenuMainLoop) MainLoop_type;
static MainLoop_type real_startMenuMainLoop = (MainLoop_type)0x4A2320;
static JmpHookedFunction<MainLoop_type>* startMenuMainLoop_hook;

void InstallHooks()
{
    if (!fp)
    {
        fp = fopen("hooked.txt", "wb");
    }

    GetBufApp0xC10_hook = new JmpHookedFunction<GetBufApp0xC10_type>(real_GetBufApp0xC10, &getBufApp0xC10);
    FFSwitchModule_hook = new JmpHookedFunction<FFSwitchModule_type>(real_FFSwitchModule, &FFSwitchModule);
    startMenuMainLoop_hook = new JmpHookedFunction<MainLoop_type>(real_startMenuMainLoop, &startMenuMainLoop);
}
