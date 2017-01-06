//---------------------------------------------------------------------------

#ifndef FIPictureH
#define FIPictureH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class PACKAGE TFIPicture : public TPicture
{
private:
protected:
public:
	__fastcall TFIPicture(System::Classes::TInterfacedPersistent* Owner);

	void __fastcall LoadFromFile(const System::UnicodeString Filename);

//	__property TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};



__published:
};
//---------------------------------------------------------------------------
#endif
