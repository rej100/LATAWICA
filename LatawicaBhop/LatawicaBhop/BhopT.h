#pragma once

#include "MemoryManagment.h"
#include "Offsets.h"
#include "Utils.h"
#include <thread>
#include <iostream>

using std::thread;
using std::cout;
using std::endl;

namespace BhopT
{
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
					system("cls");
					cout << "Waiting for CS:GO..." << endl;
					cout << "Configuring..." << endl;
					cout << "Ready for Bhopping :)" << endl;
					cout << "Toggle bhop F1 ";
					cout << "OFF";
					}
				else if (!toggle)
				{
					toggle = true;
					system("cls");
					cout << "Waiting for CS:GO..." << endl;
					cout << "Configuring..." << endl;
					cout << "Ready for Bhopping :)" << endl;
					cout << "Toggle bhop F1 ";
					cout << "ON";
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
		cout << "Configuring..." << endl;
		Utils::bhopOn = true;
		Sleep(2000);
		cout << "Ready to Bhop :)" << endl;
		cout << "Toggle bhop F1 ";
		thread ToggleR(ToggleL);
		thread BhopThread(DoBhop, mem);
		ToggleR.join();
		BhopThread.join();		
	}
}
