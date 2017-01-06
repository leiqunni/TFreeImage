//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "FIPicture.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck は、作成したコンポーネントに純粋仮想関数が
// ないことを確認するために使用します。
//

static inline void ValidCtrCheck(TFIPicture *)
{
	new TFIPicture(NULL);
}
//---------------------------------------------------------------------------
__fastcall TFIPicture::TFIPicture(System::Classes::TInterfacedPersistent* Owner)
	: TPicture(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall LoadFromFile(const System::UnicodeString Filename)
{
	this->Bitmap = FreeImage1->LoadTBitmap(Filename);
}
//---------------------------------------------------------------------------
namespace Fipicture
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TFIPicture)};
		RegisterComponents(L"FreeImage", classes, 0);
	}
}
//---------------------------------------------------------------------------
