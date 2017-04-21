//---------------------------------------------------------------------------

#ifndef frmMainH
#define frmMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "MemoryApi.h"
//---------------------------------------------------------------------------
class TfrmMaiNX : public TForm
{
__published:	// IDE-managed Components
	TEdit *modRun;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *oriAtk;
	TEdit *oriRun;
	TEdit *modAtk;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label3;
	TLabel *Label4;
	TTimer *tReader;
	TTimer *tAttack;
	TTimer *tMovement;
	TTimer *nocdSkill2;
	TLabel *Label5;
	TTimer *Omnislash;
	TButton *Button3;
	TTimer *HotkeyManager;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TTimer *CCombo;
	TLabel *Label6;
	void __fastcall tReaderTimer(TObject *Sender);
	void __fastcall tMovementTimer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall tAttackTimer(TObject *Sender);
	void __fastcall OmnislashTimer(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall HotkeyManagerTimer(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall CComboTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmMaiNX(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMaiNX *frmMaiNX;
//---------------------------------------------------------------------------
#endif
