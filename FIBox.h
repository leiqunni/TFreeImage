//---------------------------------------------------------------------------

#ifndef FIBoxH
#define FIBoxH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "FreeImage.h"

//---------------------------------------------------------------------------
class PACKAGE TFIBox : public TScrollBox
{
private:
	void __fastcall srbOnResize(TObject *Sender);

protected:
public:
	TImage *Image;
	TFreeImage *FreeImage;


 //	void __fastcall OnResize(TObject *Sender);

	__fastcall TFIBox(TComponent* Owner);


__published:
	__property OnResize;


};
//---------------------------------------------------------------------------
#endif
