//---------------------------------------------------------------------------

#ifndef FIPictureH
#define FIPictureH
//---------------------------------------------------------------------------
#include <Vcl.Graphics.hpp>

#include "FreeImage.h"

class TFIPicture : public TPicture
{
private:
protected:
public:

	TFreeImage* FreeImage;

	__fastcall TFIPicture();

	void __fastcall LoadFromFile(const String Filename);

__published:
};

#endif

