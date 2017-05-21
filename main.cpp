//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FreeImage"
#pragma link "FIBox"
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
	FIBox1->Image->Picture->Bitmap = FreeImage1->LoadTBitmap(FileName);
}
//---------------------------------------------------------------------------

