//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "FIBox.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck �́A�쐬�����R���|�[�l���g�ɏ������z�֐���
// �Ȃ����Ƃ��m�F���邽�߂Ɏg�p���܂��B
//

static inline void ValidCtrCheck(TFIBox *)
{
	new TFIBox(NULL);

}
//---------------------------------------------------------------------------
__fastcall TFIBox::TFIBox(TComponent* Owner)
	: TScrollBox(Owner)
{
	this->OnResize = TFIBox::srbOnResize;

    //
	FreeImage = new TFreeImage(this);

	Image = new TImage(this);
    Image->Parent = this;
	Image->AutoSize = true;
}
//---------------------------------------------------------------------------
void __fastcall TFIBox::srbOnResize(TObject *Sender)
{
	Image->Left = std::max(((this->ClientWidth - Image->Width) / 2), 0);
	Image->Top = std::max(((this->ClientHeight - Image->Height) / 2), 0);
}//---------------------------------------------------------------------------
namespace Fibox
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TFIBox)};
		RegisterComponents(L"FreeImage", classes, 0);
	}
}
//---------------------------------------------------------------------------
