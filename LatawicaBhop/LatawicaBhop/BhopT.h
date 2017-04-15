#pragma once

#include "MemoryManagment.h"
#include "Offsets.h"
#include "Utils.h"

namespace BhopT
{
	void DoBhop(MemoryManagment mem)
	{
		while (true)
		{
			if ( (GetAsyncKeyState(VK_SPACE) & 0x8000) && !Utils::PlayerInAir())
			{
				
			}
			Sleep(1)
		}
	}

	void BhopInit(MemoryManagment mem)
	{

	}
}
