//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FreeImage"
#pragma link "FIBox"
#pragma link "FIImageBox"
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

	Image1->Picture->Bitmap = FreeImage1->LoadTBitmap(FileName);
	FIImageBox1->Image->Picture->Bitmap = FreeImage1->LoadTBitmap(FileName);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::mnuViewArctualClick(TObject *Sender)
{
	FIImageBox1->ZoomMode = 1;
    FIImageBox1->ScrollMode = 1;
//	FIImageBox1->SetZoomMode(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuViewFitClick(TObject *Sender)
{
	FIImageBox1->ZoomMode = 2;
//	FIImageBox1->SetZoomMode(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuViewStretchClick(TObject *Sender)
{

	FIImageBox1->ZoomMode = 3;
//	FIImageBox1->SetZoomMode(3);
}
//---------------------------------------------------------------------------

