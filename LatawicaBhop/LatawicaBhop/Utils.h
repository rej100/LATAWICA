#pragma once

#include "MemoryManagment.h"
#include "Offsets.h"

namespace Utils
{
	int playerBase = 0, flag = 0;

	bool PlayerInAir(MemoryManagment* mem)
	{
		playerBase = mem->Read<int>( (mem->clientModuleBase + Offsets::LocalPlayer) );
		flag = mem->Read<int>( (playerBase + Offsets::flags) );
		
		return flag = flag == 256 || flag == 258 || flag == 260 || flag == 262;
	}
}