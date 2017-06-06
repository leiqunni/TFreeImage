// ---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "FIImageBox.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------
// ValidCtrCheck は、作成したコンポーネントに純粋仮想関数が
// ないことを確認するために使用します。
//

static inline void ValidCtrCheck(TFIImageBox *) {
	new TFIImageBox(NULL);

}

// ---------------------------------------------------------------------------
__fastcall TFIImageBox::TFIImageBox(TComponent* Owner) : TScrollBox(Owner) {
	FZoomMode = 1;

	this->DoubleBuffered = true;
	this->HorzScrollBar->Tracking = true;
	this->VertScrollBar->Tracking = true;

	//
	FreeImage = new TFreeImage(this);

	Image = new TImage(this);
	Image->Parent = this;

	Image->Center = true;

	SetZoomMode(1);

	// events
	Image->OnMouseDown = TFIImageBox::srbOnMouseDown;
	Image->OnMouseMove = TFIImageBox::srbOnMouseMove;
	Image->OnMouseUp = TFIImageBox::srbOnMouseUp;

	this->OnResize = TFIImageBox::srbOnResize;
}

// ---------------------------------------------------------------------------
void __fastcall TFIImageBox::srbOnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y) {
	if (Button == mbLeft) {
		m_MouseX = X;
		m_MouseY = Y;
		m_MouseFlg = true;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFIImageBox::srbOnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y) {
	if (Image->Align == alNone && m_MouseFlg) {
		int x = Image->Left + X;
		int y = Image->Top + Y;

		bool flg = (x > 0) && (x < this->ClientWidth) && (y > 0) && (y < this->ClientHeight);

		if (flg) {
			Image->Left -= (m_MouseX - X);
			Image->Top -= (m_MouseY - Y);
//			this->Update();
		}
		else {
			m_MouseFlg = false;
			// Screen.Cursor := crDefault;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFIImageBox::srbOnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y) {
	if (m_MouseFlg) {
		m_MouseFlg = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFIImageBox::srbOnResize(TObject *Sender) {
	if (Image->Align == alNone) {
		// Image->Left = std::max(((this->ClientWidth - Image->Width) / 2), 0);
		// Image->Top = std::max(((this->ClientHeight - Image->Height) / 2), 0);
	}
}

// ---------------------------------------------------------------------------
int __fastcall TFIImageBox::GetScrollMode() {
	return FScrollMode;
}

// ---------------------------------------------------------------------------
int __fastcall TFIImageBox::SetScrollMode(int value) {
	FScrollMode = value;

	switch (value) {
	case 0: // NORMAL
		this->HorzScrollBar->Visible = true;
		this->VertScrollBar->Visible = true;
		break;
	case 1: // ACTUAL
		this->HorzScrollBar->Visible = false;
		this->VertScrollBar->Visible = false;
		break;
	default: ;
	}

	return value;
}

// ---------------------------------------------------------------------------
int __fastcall TFIImageBox::GetZoomMode() {
	return FZoomMode;
}

// ---------------------------------------------------------------------------
int __fastcall TFIImageBox::SetZoomMode(int value) {
	FZoomMode = value;

	switch (value) {
	case 0: // NORMAL
		Image->Align = alNone;
		Image->AutoSize = false;
		Image->Proportional = false;
		Image->Stretch = false;
		break;
	case 1: // ACTUAL
		Image->Align = alNone;
		Image->AutoSize = true;
		Image->Proportional = false;
		Image->Stretch = false;
		break;
	case 2: // FIT
		Image->Align = alClient;
		Image->AutoSize = false;
		Image->Proportional = true;
		Image->Stretch = false;
		break;
	case 3: // STRETCH
		Image->Align = alClient;
		Image->AutoSize = false;
		Image->Proportional = false;
		Image->Stretch = true;
		break;
	default: ;
	}

	return value;
}

// ---------------------------------------------------------------------------
namespace Fiimagebox {
	void __fastcall PACKAGE Register() {
		TComponentClass classes[1] = {__classid(TFIImageBox)};
		RegisterComponents(L"FreeImage", classes, 0);
	}
}
// ---------------------------------------------------------------------------
