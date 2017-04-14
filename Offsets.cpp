#include "Offsets.h"

using std::cout;
using std::endl;
using std::hex;

namespace Offsets {

	DWORD LocalPlayer = 0xAB16EC; //0xAB0708;
	 DWORD ObjBase;
	 DWORD EntityList = 0x4AD4B04; //0x4AD3A64;
	 

	 DWORD health = 0xFC;
	 DWORD teamNum = 0xF0;
	 DWORD dormant = 0xE9;
	 DWORD bSpotted = 0x939;
	 DWORD index = 0x64;
	 DWORD vecOrigin = 0x134;
	 DWORD flashDuration = 0xA308;
	 DWORD crossId = 0xAA70;
	 DWORD glowIndex = 0xA320;
	 DWORD flags = 0x100;
	 DWORD forceJump = 0x4F6B728; //0x4F6A684; //0x4F6A684;
	 DWORD boneMatrix = 0x2698;
	 DWORD viewOffset = 0x104;
	 DWORD clientState = 0x5CD594; //0x5CC524;
	 DWORD viewAngles = 0x4D0C;
}
