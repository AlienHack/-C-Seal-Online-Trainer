//---------------------------------------------------------------------------

#ifndef MemoryAPIH
#define MemoryAPIH
//---------------------------------------------------------------------------
#include <tchar.h>
#include <vcl.h>

#include <TlHelp32.h>


DWORD GetMainModule(wchar_t* gameWindowTitle, wchar_t* gameModule);

void WriteIntPointer(DWORD address, int offsets[], int offsetSize, int value , wchar_t* gameWindowTitle);
void WriteFloatPointer(DWORD address, int offsets[], int offsetSize, float value , wchar_t* gameWindowTitle);
void WriteShortPointer(DWORD address, int offsets[], int offsetSize, short value , wchar_t* gameWindowTitle);
void WriteStringPointer(DWORD address, int offsets[], int offsetSize, wchar_t* value ,int len, wchar_t* gameWindowTitle);
void WriteBytesPointer(DWORD address, int offsets[], int offsetSize, byte value[] ,int sz,wchar_t* gameWindowTitle);

void WriteInt(DWORD address, int value , wchar_t* gameWindowTitle);
void WriteFloat(DWORD address, float value , wchar_t* gameWindowTitle);
void WriteShort(DWORD address, short value , wchar_t* gameWindowTitle);
void WriteBytes(DWORD address, byte value[],int sz, wchar_t* gameWindowTitle);

int ReadIntPointer(DWORD address, int offsets[], int offsetSize , wchar_t* gameWindowTitle);
float ReadFloatPointer(DWORD address, int offsets[], int offsetSize , wchar_t* gameWindowTitle);
short ReadShortPointer(DWORD address, int offsets[], int offsetSize , wchar_t* gameWindowTitle);
void ReadStringPointer(DWORD address, int offsets[], int offsetSize , wchar_t* gameWindowTitle, char* returnArray, int returnSize);

int ReadInt(DWORD address, wchar_t* gameWindowTitle);
short ReadShort(DWORD address, wchar_t* gameWindowTitle);
float ReadFloat(DWORD address, wchar_t* gameWindowTitle);

DWORD FindPattern(DWORD StartAddress, DWORD CodeLen, BYTE* Mask, char* StrMask, unsigned short ignore);
bool DataCompare(const BYTE* OpCodes, const BYTE* Mask, const char* StrMask);
#endif
