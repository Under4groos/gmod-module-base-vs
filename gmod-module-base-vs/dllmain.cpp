




#include "Headers.h"


LUA_FUNCTION(MyExampleFunction)
{
    double first_number = LUA->CheckNumber(1);
    double second_number = LUA->CheckNumber(2);

    LUA->PushNumber(first_number + second_number);
    return 1;
}

GMOD_MODULE_OPEN()
{
    LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
    LUA->PushString("TestFunction");
    LUA->PushCFunction(MyExampleFunction);
    LUA->SetTable(-3); // `_G.TestFunction = MyExampleFunction`

    return 0;
}

GMOD_MODULE_CLOSE()
{
    return 0;
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

