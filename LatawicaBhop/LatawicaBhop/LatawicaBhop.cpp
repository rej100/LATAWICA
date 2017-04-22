// LatawicaBhop.cpp : Defines the entry point for the console application.
//

#include "MemoryManagment.h"
#include "Offsets.h"
#include "BhopT.h"

using std::cout;
using std::endl;

int main()
{
	SetConsoleTitle((LPCSTR)"300Bhop v1.6");

	MemoryManagment mem("csgo.exe");

	cout << "Waiting for CS:GO..." << endl;

	while (!mem.Initialize())
	{
		Sleep(300);
	}
	BhopT::BhopInit(&mem);

	getchar();
    return 0;
}