#include "includes.hpp"

//pollotherunner porra


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)InitHook, nullptr, 0, nullptr);
		break;

	case DLL_PROCESS_DETACH:
		RemoveHookAndFreeLibrary(hModule);
		break;

	default:
		return FALSE;
	}

	return TRUE;
}