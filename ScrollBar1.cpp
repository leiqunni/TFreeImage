//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "ScrollBar1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck は、作成したコンポーネントに純粋仮想関数が
// ないことを確認するために使用します。
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
