//---------------------------------------------------------------------------

#pragma hdrstop

#include "FIPicture.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall TFIPicture::TFIPicture()
	: TPicture()
{
	FreeImage = new TFreeImage(NULL);
}

//---------------------------------------------------------------------------

void __fastcall TFIPicture::LoadFromFile(const String Filename)
{
	this->Bitmap = FreeImage->LoadTBitmap(Filename);


}






