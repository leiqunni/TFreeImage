//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "FIPicture.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck �́A�쐬�����R���|�[�l���g�ɏ������z�֐���
// �Ȃ����Ƃ��m�F���邽�߂Ɏg�p���܂��B
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
