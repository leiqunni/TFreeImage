//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "FreeImage.h"
#include <Vcl.ExtCtrls.hpp>
#include <System.Math.hpp>
#include <stdio.h>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include "FIImageBox.h"
#include <Vcl.WinXCtrls.hpp>
#include "FIImageBox.h"
#include <Vcl.Menus.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TImage *Image1;
	TMainMenu *MainMenu1;
	TMenuItem *mnuFile;
	TMenuItem *mnuView;
	TMenuItem *mnuViewArctual;
	TMenuItem *mnuViewFit;
	TMenuItem *mnuViewStretch;
	TMenuItem *mnuViewZoomMode;
	TFreeImage *FreeImage1;
	TFIImageBox *FIImageBox1;

	void __fastcall FormActivate(TObject *Sender);
	void __fastcall mnuViewArctualClick(TObject *Sender);
	void __fastcall mnuViewFitClick(TObject *Sender);
	void __fastcall mnuViewStretchClick(TObject *Sender);
private:	// ユーザー宣言

public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
