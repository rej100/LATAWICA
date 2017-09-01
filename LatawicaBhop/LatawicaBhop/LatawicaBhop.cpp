#include "MemoryManagment.h"
#include "Offsets.h"
#include "BhopT.h"

using std::cout;
using std::endl;

int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND console = GetConsoleWindow();
	MoveWindow(console, NULL, NULL, 220, 116, TRUE);
	SetConsoleTitle((LPCSTR)"300Bhop v2.4");
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

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