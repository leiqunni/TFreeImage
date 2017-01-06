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

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TScrollBox *ScrollBox1;
	TImage *Image1;
	TButton *Button1;
	TFIBox *FIBox1;
	TFreeImage *FreeImage1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall ScrollBox1Resize(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// ユーザー宣言
    int m_MouseX;       // マウスＸ
    int m_MouseY;       // マウスＹ
	int m_MouseFlg;     // マウスクリックフラグ


public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
