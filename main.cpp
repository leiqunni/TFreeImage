//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FreeImage"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
	FIBITMAP* dib = NULL;
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	String FileName = L"sample.jpg";

//	// check the file signature and deduce its format
//	// (the second argument is currently not used by FreeImage)
//	fif = FreeImage1->GetFIFFromFilenameU(FileName.w_str());
//	if (fif == FIF_UNKNOWN) {
//		// no signature ?
//		// try to guess the file format from the file extension
//		fif = FreeImage1->GetFIFFromFilenameU(FileName.w_str());
//	}
//	// check that the plugin has reading capabilities ...
//	if ((fif != FIF_UNKNOWN) && FreeImage1->FIFSupportsReading(fif)) {
//		// ok, let's load the file
//		dib = FreeImage1->LoadU(fif, FileName.w_str());
//	}
//	if (dib) {
//		HDC hDc = ::GetDC(0);
//		HBITMAP hBmp = ::CreateDIBitmap(hDc, FreeImage1->GetInfoHeader(dib), CBM_INIT, FreeImage1->GetBits(dib), FreeImage1->GetInfo(dib), DIB_RGB_COLORS);
//		::ReleaseDC(0, hDc);
//		FreeImage1->Unload(dib);
//		Image1->Picture->Bitmap->Handle = hBmp;
//	}
//	Image1->Picture->Bitmap->Handle = FreeImage1->LoadHBitmap(FileName);
	Image1->Picture->Bitmap = FreeImage1->LoadTBitmap(FileName);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    // 左クリック中
	if( m_MouseFlg )
    {
        // 水平方向のスクロールバーにマウスポインタの移動値を反映する
		ScrollBox1->HorzScrollBar->Position = ScrollBox1->HorzScrollBar->Position + (m_MouseX - X);
		// 垂直方向のスクロールバーにマウスポインタの移動値を反映する
        ScrollBox1->VertScrollBar->Position = ScrollBox1->VertScrollBar->Position + (m_MouseY - Y);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    // 左クリック
    if( Button == mbLeft )
    {
        m_MouseX    = X;        // マウスＸ
		m_MouseY    = Y;        // マウスＹ
        m_MouseFlg  = true;     // 左クリック中
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    // 左クリック中
    if( m_MouseFlg )
    {
        m_MouseFlg  = false;    // 左クリック終了
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBox1Resize(TObject *Sender)
{
	Image1->Left = Max(((ScrollBox1->ClientWidth - Image1->Width) / 2), 0);
	Image1->Top = Max(((ScrollBox1->ClientHeight - Image1->Height) / 2), 0);
}
//---------------------------------------------------------------------------
