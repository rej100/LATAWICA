// LatawicaBhop.cpp : Defines the entry point for the console application.
//

#include "MemoryManagment.h"
#include "Offsets.h"
#include "BhopT.h"

using std::cout;
using std::endl;

int main()
<<<<<<< HEAD
{	SetConsoleTitle((LPCSTR)"300Bhop v1.5");
=======
{
	SetConsoleTitle((LPCSTR)"300Bhop v1.6");
>>>>>>> origin/master
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