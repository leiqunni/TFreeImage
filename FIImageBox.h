//---------------------------------------------------------------------------

#ifndef FIImageBoxH
#define FIImageBoxH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "FreeImage.h"

enum EScrollMode
{
	SCROLLBAR   = 0,
	MOUSEDRAG   = 1,
};

enum EZoomMode
{
	NOMAL	    = 0,
	ACTUAL      = 1,
	FIT         = 2,
	STRETCH     = 3,
};

//---------------------------------------------------------------------------
class PACKAGE TFIImageBox : public TScrollBox
{
private:
    int m_MouseX;       // マウスＸ
    int m_MouseY;       // マウスＹ
    int m_MouseFlg;     // マウスクリックフラグ

	int FScrollMode;
	int FZoomMode;

	void __fastcall srbOnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall srbOnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall srbOnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall srbOnResize(TObject *Sender);

	int __fastcall TFIImageBox::GetScrollMode();
	int __fastcall TFIImageBox::SetScrollMode(int value);
	int __fastcall TFIImageBox::GetZoomMode();
	int __fastcall TFIImageBox::SetZoomMode(int value);


protected:
public:
	TImage *Image;
	TFreeImage *FreeImage;

	__property int ScrollMode = {read = GetScrollMode, write=SetScrollMode}; //
	__property int ZoomMode = {read = GetZoomMode, write=SetZoomMode}; //



	__fastcall TFIImageBox(TComponent* Owner);


__published:
	__property OnResize;


};
//---------------------------------------------------------------------------
#endif
