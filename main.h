//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include <Vcl.ExtCtrls.hpp>
#include <System.Math.hpp>
#include <stdio.h>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>

#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Menus.hpp>
#include "FIImageBox.h"
#include "FreeImage.h"


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TImage *Image1;
	TMainMenu *MainMenu1;
	TMenuItem *mnuFile;
	TMenuItem *mnuView;
	TMenuItem *mnuViewArctual;
	TMenuItem *mnuViewFit;
	TMenuItem *mnuViewStretch;
	TMenuItem *mnuViewZoomMode;
	TFIImageBox *FIImageBox1;
	TFreeImage *FreeImage1;

	void __fastcall FormActivate(TObject *Sender);
	void __fastcall mnuViewArctualClick(TObject *Sender);
	void __fastcall mnuViewFitClick(TObject *Sender);
	void __fastcall mnuViewStretchClick(TObject *Sender);
private:	// ���[�U�[�錾

public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
