// LatawicaBhop.cpp : Defines the entry point for the console application.
//

#include "MemoryManagment.h"
#include "Offsets.h"

using std::cout;
using std::endl;

int main()
{
	MemoryManagment mem("csgo.exe");

	cout << "Waiting for CS:GO..." << endl;

	while (!mem.Initialize())
	{
		Sleep(300);
	}

	getchar();
    return 0;
}