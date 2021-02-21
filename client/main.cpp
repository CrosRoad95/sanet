#include "main.h"
#include "patches/CGamePatches.h"

std::vector<bool(__cdecl*)(unsigned int)> Patch_Funcs;

class client 
{
public:
	client()
	{
		DisableThreadLibraryCalls(GetModuleHandle(NULL));

		AllocConsole();
		freopen("CONOUT$", "w", stdout);

		printf(PROJECT_INFO);

		CGamePatches::Init();
        CVehicleManager::Init();
        CPlayerPedManager::Init();
        CPedManager::Init();
<<<<<<< HEAD
=======
        CPopulationManager::Init();
>>>>>>> 31dbb5c74b29a47df4cf41280887a66794fdc5ff
        CRenderManager::Init();
        CNetworkManager::Init();
        COptions::Init();
    }
} _client;
