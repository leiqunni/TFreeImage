//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "ScrollBar1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck �́A�쐬�����R���|�[�l���g�ɏ������z�֐���
// �Ȃ����Ƃ��m�F���邽�߂Ɏg�p���܂��B
//

static inline void ValidCtrCheck(TScrollBar1 *)
{
	new TScrollBar1(NULL);
}
//---------------------------------------------------------------------------
__fastcall TScrollBar1::TScrollBar1(TComponent* Owner)
	: TScrollBar(Owner)
{
}
//---------------------------------------------------------------------------
namespace Scrollbar1
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TScrollBar1)};
		RegisterComponents(L"Samples", classes, 0);
	}
}
//---------------------------------------------------------------------------
