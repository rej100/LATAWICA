#pragma once

#include "MemoryManagment.h"
#include "Offsets.h"
#include "Utils.h"

using std::thread;
using std::cout;
using std::endl;

namespace BhopT
{
	void on()
	{
		system("cls");
		cout << "Waiting for CS:GO..." << endl;
		cout << "Initializing..." << endl;
		cout << "Initialized." << endl;
		cout << "Ready to bhop!" << endl;
		cout << "Toggle bhop (F1) -> ON";
	}

	void off()
	{
		system("cls");
		cout << "Waiting for CS:GO..." << endl;
		cout << "Initializing..." << endl;
		cout << "Initialized." << endl;
		cout << "Ready to bhop!" << endl;
		cout << "Toggle bhop (F1) -> OFF";
	}


	bool jumped = false;

	bool toggle = true;

	void ToggleL()
	{
		while (true)
		{
			if (GetAsyncKeyState(VK_F1) & 0x1)
			{
				if (toggle)
				{
					toggle = false;
					off();
				}
				else if (!toggle)
				{
					toggle = true;
					on();
				}
			}
		}
	}

	void DoBhop(MemoryManagment *mem)
	{
		while (true) 
		{
			if (toggle)
			{
				if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && !Utils::PlayerInAir(mem))
				{
					SendMessage(mem->processHWND, WM_KEYDOWN, VK_SPACE, 0x390000);
					jumped = true;
				}
				else if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && Utils::PlayerInAir(mem))
				{
					SendMessage(mem->processHWND, WM_KEYUP, VK_SPACE, 0x390000);
					if (jumped)
					{
						Sleep(16);
						SendMessage(mem->processHWND, WM_KEYDOWN, VK_SPACE, 0x390000);
						SendMessage(mem->processHWND, WM_KEYUP, VK_SPACE, 0x390000);
						jumped = false;
					}
				}
				else
				{
					Sleep(1);
				}
			}
			Sleep(1);
		}
	}

	void BhopInit(MemoryManagment *mem)
	{
		Utils::bhopOn = true;
		cout << "Initializing..." << endl;
		cout << "Initialized." << endl;
		cout << "Ready to bhop!" << endl;
		cout << "Toggle bhop (F1) -> ON";
		thread ToggleR(ToggleL);
		thread BhopThread(DoBhop, mem);
		ToggleR.join();
		BhopThread.join();		
	}
}
