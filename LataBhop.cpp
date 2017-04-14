#include "MemoryManagment.h"

using std::cout;
using std::endl;

int main()
{
	SetConsoleTitle("LataBhop 0.1");

	MemoryManagment mem("csgo.exe")
	cout << "Waiting for CSGO" << endl;
	while(!mem.initialize())
	{
		Sleep(300);
	}
	
	return 0;
}