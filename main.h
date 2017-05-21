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
#include "FIBox.h"
#include <Vcl.WinXCtrls.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TFIBox *FIBox1;
	TFreeImage *FreeImage1;
	TImage *Image1;
	TSplitter *Splitter1;
	void __fastcall FormActivate(TObject *Sender);
private:	// ユーザー宣言

public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
