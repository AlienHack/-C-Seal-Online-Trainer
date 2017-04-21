//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMaiNX *frmMaiNX;
//---------------------------------------------------------------------------

DWORD BaseAddress = 0x884d84;
int AtkOffset[1] = {0x1654};
int ComboOffset[1] = {0x1654+0xC};
int SpdOffset[1] = {0x1d9d};
int CDOffset[1] = {0x2a6c};

//---------------------------------------------------------------------------

__fastcall TfrmMaiNX::TfrmMaiNX(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMaiNX::tReaderTimer(TObject *Sender)
{
	oriAtk->Text = IntToStr(ReadIntPointer(BaseAddress,AtkOffset,1,L"SO3D"));
	oriRun->Text = IntToStr(ReadIntPointer(BaseAddress,SpdOffset,1,L"SO3D"));
}
//---------------------------------------------------------------------------
void __fastcall TfrmMaiNX::tMovementTimer(TObject *Sender)
{
	 WriteIntPointer(BaseAddress,SpdOffset,1,StrToInt(modRun->Text),L"SO3D");
}
//---------------------------------------------------------------------------
void __fastcall TfrmMaiNX::Button2Click(TObject *Sender)
{
	tMovement->Enabled = !tMovement->Enabled;
	if(tMovement->Enabled){
		Button2->Caption = L"Activated";
	}else{
		Button2->Caption = L"Deactivated";
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMaiNX::Button1Click(TObject *Sender)
{
	tAttack->Interval=StrToInt(modAtk->Text);
	tAttack->Enabled = !tAttack->Enabled;
	if(tAttack->Enabled){
		Button1->Caption = L"Activated";
	}else{
		Button1->Caption = L"Deactivated";
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMaiNX::tAttackTimer(TObject *Sender)
{
	 WriteIntPointer(BaseAddress,AtkOffset,1,0,L"SO3D");
}
//---------------------------------------------------------------------------
int xMouseOffset[1] = {0x2ba8};
int yMouseOffset[1] = {0x2ba0};
int xOffset[1] = {0x48};
int yOffset[1] = {0x40};

DWORD WINAPI F1Warp( LPVOID lpParam )
{
	while(true){
		if(GetAsyncKeyState(0x70)&1){
			 float getXMouse = ReadFloatPointer(0x40c32c,xMouseOffset,1,L"SO3D");
			 float getYMouse = ReadFloatPointer(0x40c32c,yMouseOffset,1,L"SO3D");
			 WriteFloatPointer(0x00884D84,xOffset,1,getXMouse,L"SO3D");
			 WriteFloatPointer(0x00884D84,yOffset,1,getYMouse,L"SO3D");
		}
        Sleep(1);
    }
}



void __fastcall TfrmMaiNX::OmnislashTimer(TObject *Sender)
{
    if(GetAsyncKeyState(0x01)&1){
		 float getXMouse = ReadFloatPointer(0x40c32c,xMouseOffset,1,L"SO3D");
		 float getYMouse = ReadFloatPointer(0x40c32c,yMouseOffset,1,L"SO3D");
		 if(CheckBox2->Checked){
			  getXMouse-=5;
		 }
		 WriteFloatPointer(0x00884D84,xOffset,1,getXMouse,L"SO3D");
		 WriteFloatPointer(0x00884D84,yOffset,1,getYMouse,L"SO3D");
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMaiNX::Button3Click(TObject *Sender)
{
	Omnislash->Enabled = !Omnislash->Enabled;
	if(Omnislash->Enabled){
		Button3->Caption = L"Activated";
	}else{
		Button3->Caption = L"Deactivated";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMaiNX::HotkeyManagerTimer(TObject *Sender)
{
	if(GetAsyncKeyState(0x71)&1){
		Button3Click(NULL);
	}else if(GetAsyncKeyState(0x72)&1){         //F3
		WriteFloatPointer(0x00884D84,xOffset,1,171,L"SO3D");
		WriteFloatPointer(0x00884D84,yOffset,1,360,L"SO3D");
	}else if  (GetAsyncKeyState(0x73)&1){         //F4
		WriteFloatPointer(0x00884D84,xOffset,1,32,L"SO3D");
		WriteFloatPointer(0x00884D84,yOffset,1,121,L"SO3D");
	}else if(GetAsyncKeyState(0x74)&1){         //F5
		WriteInt(GetMainModule(L"SO3D",L"SO3DReturn.exe")+0x46DCF4,10,L"SO3D");
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMaiNX::CheckBox1Click(TObject *Sender)
{
    //MessageBox(NULL,IntToStr((int)GetMainModule(L"SO3D",L"SO3DReturn.exe")).c_str(),NULL,MB_OK);
	//FIND NAME, NAME - E98
	if(CheckBox1->Checked){
		WriteInt(GetMainModule(L"SO3D",L"SO3DReturn.exe")+0xC8650,327680,L"SO3D");
	}else{
		WriteInt(GetMainModule(L"SO3D",L"SO3DReturn.exe")+0xC8650,65536,L"SO3D");
    }
}
//---------------------------------------------------------------------------
BYTE comboValue[] = {0x05,0x00,0x00,0x00,0xF2,0x2E};
//BYTE comboValue[] = {0x11,0x11,0x11,0x11,0x11,0x11};
void __fastcall TfrmMaiNX::CComboTimer(TObject *Sender)
{
	WriteBytesPointer(BaseAddress,ComboOffset,1,comboValue,6,L"SO3D");
}
//---------------------------------------------------------------------------

void __fastcall TfrmMaiNX::FormCreate(TObject *Sender)
{
ShellExecute(NULL, L"open", L"https://www.facebook.com/alienhack/", NULL, NULL, SW_SHOWNORMAL);
CreateThread(
            NULL,                   // default security attributes
            0,                      // use default stack size
			F1Warp,       // thread function name
			NULL,          // argument to thread function
            0,                      // use default creation flags
			0);   // returns the thread identifier
}
//---------------------------------------------------------------------------


