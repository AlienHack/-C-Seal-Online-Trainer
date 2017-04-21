//---------------------------------------------------------------------------

#pragma hdrstop


#include "MemoryAPI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//Pointer

DWORD GetMainModule(wchar_t* gameWindowTitle, wchar_t* gameModule){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
	unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
		DWORD dwModuleBaseAddress = 0;
		if (hSnapshot != INVALID_HANDLE_VALUE)
		{
			MODULEENTRY32 ModuleEntry32 = { 0 };
			ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
			if (Module32First(hSnapshot, &ModuleEntry32))
			{
				do
				{

					if (wcscmp(ModuleEntry32.szModule, gameModule) == 0)
					{

						dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;

						break;
					}
				} while (Module32Next(hSnapshot, &ModuleEntry32));
			}
			CloseHandle(hSnapshot);
		}
		return dwModuleBaseAddress;
	}
    return 0;

}

//WRITE

void WriteIntPointer(DWORD address, int offsets[], int offsetSize, int value , wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
	unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
            VirtualProtectEx(phandle, (void*)address, sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle,(void*)address,&addrTemp,sizeof(value),0);
			VirtualProtectEx(phandle, (void*)address, sizeof(value), oldProtection , &oldProtection);

			for(int i = 0 ; i < offsetSize-1; ++i){
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
				ReadProcessMemory(phandle,(void*)(addrTemp+offsets[i]),&addrTemp,sizeof(value),0);
                VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), oldProtection , &oldProtection);
			}
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			WriteProcessMemory(phandle, (void*)(addrTemp+offsets[offsetSize-1]), &value  , sizeof(value),0);
            VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(value), oldProtection , &oldProtection);
		}
	}
}

void WriteInt(DWORD address, int value , wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)(address), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			WriteProcessMemory(phandle, (void*)(address), &value  , sizeof(value),0);
            VirtualProtectEx(phandle, (void*)(address), sizeof(value), oldProtection , &oldProtection);
		}
	}
}

void WriteFloatPointer(DWORD address, int offsets[], int offsetSize, float value , wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
            VirtualProtectEx(phandle, (void*)address, sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle,(void*)address,&addrTemp,sizeof(value),0);
			VirtualProtectEx(phandle, (void*)address, sizeof(value), oldProtection , &oldProtection);

			for(int i = 0 ; i < offsetSize-1; ++i){
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
				ReadProcessMemory(phandle,(void*)(addrTemp+offsets[i]),&addrTemp,sizeof(value),0);
                VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), oldProtection , &oldProtection);
			}
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			WriteProcessMemory(phandle, (void*)(addrTemp+offsets[offsetSize-1]), &value  , sizeof(value),0);
            VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(value), oldProtection , &oldProtection);
		}
	}
}

void WriteFloat(DWORD address, float value , wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)(address), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			WriteProcessMemory(phandle, (void*)(address), &value  , sizeof(value),0);
            VirtualProtectEx(phandle, (void*)(address), sizeof(value), oldProtection , &oldProtection);
		}
	}
}

void WriteShortPointer(DWORD address, int offsets[], int offsetSize, short value , wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
            VirtualProtectEx(phandle, (void*)address, sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle,(void*)address,&addrTemp,sizeof(value),0);
			VirtualProtectEx(phandle, (void*)address, sizeof(value), oldProtection , &oldProtection);

			for(int i = 0 ; i < offsetSize-1; ++i){
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
				ReadProcessMemory(phandle,(void*)(addrTemp+offsets[i]),&addrTemp,sizeof(value),0);
                VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), oldProtection , &oldProtection);
			}
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			WriteProcessMemory(phandle, (void*)(addrTemp+offsets[offsetSize-1]), &value  , sizeof(value),0);
            VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(value), oldProtection , &oldProtection);
		}
	}
}

void WriteShort(DWORD address, short value , wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)(address), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			WriteProcessMemory(phandle, (void*)(address), &value  , sizeof(value),0);
            VirtualProtectEx(phandle, (void*)(address), sizeof(value), oldProtection , &oldProtection);
		}
	}
}

void WriteStringPointer(DWORD address, int offsets[], int offsetSize, wchar_t* value ,int len, wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
            VirtualProtectEx(phandle, (void*)address, sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle,(void*)address,&addrTemp,sizeof(value),0);
			VirtualProtectEx(phandle, (void*)address, sizeof(value), oldProtection , &oldProtection);

			for(int i = 0 ; i < offsetSize-1; ++i){
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
				ReadProcessMemory(phandle,(void*)(addrTemp+offsets[i]),&addrTemp,sizeof(value),0);
                VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), oldProtection , &oldProtection);
			}
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), len, PAGE_EXECUTE_READWRITE , &oldProtection);
			WriteProcessMemory(phandle, (void*)(addrTemp+offsets[offsetSize-1]), &value  , len,0);
            VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), len, oldProtection , &oldProtection);
		}
	}
}

void WriteBytesPointer(DWORD address, int offsets[], int offsetSize, byte value[],int sz, wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
            VirtualProtectEx(phandle, (void*)address, sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle,(void*)address,&addrTemp,sizeof(value),0);
			VirtualProtectEx(phandle, (void*)address, sizeof(value), oldProtection , &oldProtection);

			for(int i = 0 ; i < offsetSize-1; ++i){
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), PAGE_EXECUTE_READWRITE , &oldProtection);
				ReadProcessMemory(phandle,(void*)(addrTemp+offsets[i]),&addrTemp,sizeof(value),0);
                VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(value), oldProtection , &oldProtection);
			}
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sz, PAGE_EXECUTE_READWRITE , &oldProtection);
			WriteProcessMemory(phandle, (void*)(addrTemp+offsets[offsetSize-1]), value  , sz,0);
            VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sz, oldProtection , &oldProtection);
		}
	}
}

void WriteBytes(DWORD address, byte value[],int sz, wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
	unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)address, sz, PAGE_EXECUTE_READWRITE , &oldProtection);
			WriteProcessMemory(phandle, (void*)address, value  , sz,0);
            VirtualProtectEx(phandle, (void*)address, sz, oldProtection , &oldProtection);
		}
	}
}

//Read
int ReadIntPointer(DWORD address, int offsets[], int offsetSize , wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
    int toReturn = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)address, sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle,(void*)address,&addrTemp,sizeof(toReturn),0);
			VirtualProtectEx(phandle, (void*)address, sizeof(toReturn), oldProtection , &oldProtection);

			for(int i = 0 ; i < offsetSize-1; ++i){
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
				ReadProcessMemory(phandle,(void*)(addrTemp+offsets[i]),&addrTemp,sizeof(toReturn),0);
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(toReturn), oldProtection , &oldProtection);
			}
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle, (void*)(addrTemp+offsets[offsetSize-1]), &toReturn  , sizeof(toReturn),0);
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(toReturn), oldProtection , &oldProtection);
		}
	}
    return toReturn;
}

int ReadInt(DWORD address, wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
    int toReturn = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)(address), sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle, (void*)(address), &toReturn  , sizeof(toReturn),0);
			VirtualProtectEx(phandle, (void*)(address), sizeof(toReturn), oldProtection , &oldProtection);
		}
	}
    return toReturn;
}

float ReadFloatPointer(DWORD address, int offsets[], int offsetSize , wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
    float toReturn = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)address, sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle,(void*)address,&addrTemp,sizeof(toReturn),0);
			VirtualProtectEx(phandle, (void*)address, sizeof(toReturn), oldProtection , &oldProtection);

			for(int i = 0 ; i < offsetSize-1; ++i){
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
				ReadProcessMemory(phandle,(void*)(addrTemp+offsets[i]),&addrTemp,sizeof(toReturn),0);
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(toReturn), oldProtection , &oldProtection);
			}
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle, (void*)(addrTemp+offsets[offsetSize-1]), &toReturn  , sizeof(toReturn),0);
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(toReturn), oldProtection , &oldProtection);
		}
	}
    return toReturn;
}

float ReadFloat(DWORD address, wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
    float toReturn = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)(address), sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle, (void*)(address), &toReturn  , sizeof(toReturn),0);
			VirtualProtectEx(phandle, (void*)(address), sizeof(toReturn), oldProtection , &oldProtection);
		}
	}
    return toReturn;
}

short ReadShortPointer(DWORD address, int offsets[], int offsetSize , wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
    short toReturn = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)address, sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle,(void*)address,&addrTemp,sizeof(toReturn),0);
			VirtualProtectEx(phandle, (void*)address, sizeof(toReturn), oldProtection , &oldProtection);

			for(int i = 0 ; i < offsetSize-1; ++i){
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
				ReadProcessMemory(phandle,(void*)(addrTemp+offsets[i]),&addrTemp,sizeof(toReturn),0);
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(toReturn), oldProtection , &oldProtection);
			}
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle, (void*)(addrTemp+offsets[offsetSize-1]), &toReturn  , sizeof(toReturn),0);
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(toReturn), oldProtection , &oldProtection);
		}
	}
    return toReturn;
}

short ReadShort(DWORD address, wchar_t* gameWindowTitle){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
    short toReturn = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)(address), sizeof(toReturn), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle, (void*)(address), &toReturn  , sizeof(toReturn),0);
			VirtualProtectEx(phandle, (void*)(address), sizeof(toReturn), oldProtection , &oldProtection);
		}
	}
    return toReturn;
}

void ReadStringPointer(DWORD address, int offsets[], int offsetSize , wchar_t* gameWindowTitle, char* returnArray){
	DWORD pid;
	HWND hwnd = FindWindow(NULL,gameWindowTitle);
	int addrTemp = 0;
    unsigned long oldProtection;
	if(hwnd)
	{
		GetWindowThreadProcessId(hwnd,&pid);
		HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		if(phandle)
		{
			VirtualProtectEx(phandle, (void*)address, sizeof(int), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle,(void*)address,&addrTemp,sizeof(int),0);
			VirtualProtectEx(phandle, (void*)address, sizeof(int), oldProtection , &oldProtection);

			for(int i = 0 ; i < offsetSize-1; ++i){
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(int), PAGE_EXECUTE_READWRITE , &oldProtection);
				ReadProcessMemory(phandle,(void*)(addrTemp+offsets[i]),&addrTemp,sizeof(int),0);
				VirtualProtectEx(phandle, (void*)(addrTemp+offsets[i]), sizeof(int), oldProtection , &oldProtection);
			}
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(returnArray), PAGE_EXECUTE_READWRITE , &oldProtection);
			ReadProcessMemory(phandle, (void*)(addrTemp+offsets[offsetSize-1]), &returnArray[0]  , sizeof(returnArray),0);
			VirtualProtectEx(phandle, (void*)(addrTemp+offsets[offsetSize-1]), sizeof(returnArray), oldProtection , &oldProtection);
		}
	}
}

bool DataCompare(const BYTE* OpCodes, const BYTE* Mask, const char* StrMask)
{
        while (*StrMask)
        {
                if (*StrMask == 'x' && *OpCodes != *Mask)
                        return false;

                ++StrMask;
                ++OpCodes;
                ++Mask;
        }

        return true;
}

//FindPattern((DWORD)eac_module, 0xFFFFF, (BYTE*)"\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x81\xEC\x9C\x02\x00", "x????x????xxxxxx", 0);
DWORD FindPattern(DWORD StartAddress, DWORD CodeLen, BYTE* Mask, char* StrMask, unsigned short ignore)
{
        unsigned short Ign = 0;
        DWORD i = 0;

        while (Ign <= ignore)
        {
                if (DataCompare((BYTE*)(StartAddress + i++), Mask, StrMask))
                        ++Ign;

                else if (i >= CodeLen)
                        return 0;
        }
        return StartAddress + i - 1;
}
