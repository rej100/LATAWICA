#pragma once

#include "MemoryManagment.h"
#include "Offsets.h"
#include "Utils.h"
#include "thread"
#include "iostream"

using std::thread;
using std::cout;
using std::endl;

namespace BhopT
{
	bool jumped = false;
	void DoBhop(MemoryManagment *mem)
	{
		while (true) 
		{
				if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && !Utils::PlayerInAir(mem)) 
				{
					SendMessage(mem -> processHWND, WM_KEYDOWN, VK_SPACE, 0x390000);
					jumped = true;
				}
				else if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && Utils::PlayerInAir(mem)) 
				{
					SendMessage(mem -> processHWND, WM_KEYUP, VK_SPACE, 0x390000);
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
	}

	void BhopInit(MemoryManagment *mem)
	{
		cout << "Configuring..." << endl;
		Sleep(2000);
		cout << "Ready for Bhopping :)" << endl;
		cout<<"Toggle Bhop (USE F1 & F2) ";
		while (true)
		{
			if (GetAsyncKeyState(VK_F1) & 0x1)
			{
				system("cls");
				cout << "Waiting for CS:GO..." << endl;
				cout << "Configuring..." << endl;
				cout << "Ready for Bhopping :)" << endl;
				cout << "Toggle Bhop (USE F1) ";
				cout << "ON" << endl;
				Sleep(10);
			}
			if (GetAsyncKeyState(VK_F2) & 0x1)
			{
				system("cls");
				cout << "Waiting for CS:GO..." << endl;
				cout << "Configuring..." << endl;
				cout << "Ready for Bhopping :)" << endl;
				cout << "Toggle Bhop (USE F1) ";
				cout << "OFF";
				bool jumped = true;
				Sleep(10);
			}	}
		thread BhopThread(DoBhop, mem);
		BhopThread.join();
<<<<<<< HEAD
		
=======
		cout << "Done." << endl;
>>>>>>> origin/master
	}
}
