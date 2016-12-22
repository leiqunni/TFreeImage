// ---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "FreeImage.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------
// ValidCtrCheck は、作成したコンポーネントに純粋仮想関数が
// ないことを確認するために使用します。
//

static inline void ValidCtrCheck(TFreeImage*)
{
    new TFreeImage(NULL);
}

// ---------------------------------------------------------------------------
__fastcall TFreeImage::TFreeImage(TComponent* Owner)
    : TComponent(Owner)
{
}
// ---------------------------------------------------------------------------
namespace Freeimage {
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = { __classid(TFreeImage) };
		RegisterComponents(L"FreeImage", classes, 0);
	}
}
// ---------------------------------------------------------------------------
// Original functions
// ---------------------------------------------------------------------------
HBITMAP __fastcall TFreeImage::LoadHBitmap(const String filename)
{
    FIBITMAP* dib = NULL;
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

    HBITMAP hBmp = NULL;

    // check the file signature and deduce its format
    // (the second argument is currently not used by FreeImage)
    fif = GetFileTypeU(filename.w_str());
    if (fif == FIF_UNKNOWN) {
        // no signature ?
        // try to guess the file format from the file extension
        fif = GetFIFFromFilenameU(filename.w_str());
    }
    // check that the plugin has reading capabilities ...
    if ((fif != FIF_UNKNOWN) && FIFSupportsReading(fif)) {
        // ok, let's load the file
        dib = LoadU(fif, filename.w_str());
    }
    if (dib) {
        HDC hDc = ::GetDC(0);
        hBmp = ::CreateDIBitmap(hDc, GetInfoHeader(dib), CBM_INIT, GetBits(dib), GetInfo(dib), DIB_RGB_COLORS);
        ::ReleaseDC(0, hDc);
        Unload(dib);
    }

    return hBmp;
}
// ---------------------------------------------------------------------------

TBitmap* __fastcall TFreeImage::LoadTBitmap(const String filename)
{
    FIBITMAP* dib = NULL;
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

    TBitmap* tBmp = NULL;

    // check the file signature and deduce its format
    // (the second argument is currently not used by FreeImage)
    fif = GetFileTypeU(filename.w_str(), 0);
    if (fif == FIF_UNKNOWN) {
        // no signature ?
        // try to guess the file format from the file extension
        fif = GetFIFFromFilenameU(filename.w_str());
    }
    // check that the plugin has reading capabilities ...
    if ((fif != FIF_UNKNOWN) && FIFSupportsReading(fif)) {
        // ok, let's load the file
        dib = LoadU(fif, filename.w_str());
    }
    if (dib) {
        HDC hDc = ::GetDC(0);
        tBmp = new TBitmap();
        tBmp->Handle = ::CreateDIBitmap(hDc, GetInfoHeader(dib), CBM_INIT, GetBits(dib), GetInfo(dib), DIB_RGB_COLORS);
        ::ReleaseDC(0, hDc);
        Unload(dib);
    }

    return tBmp;
}

// ---------------------------------------------------------------------------
// General functions
// ---------------------------------------------------------------------------
void __fastcall TFreeImage::Initialise(bool load_local_plugins_only)
{
    FreeImage_Initialise(load_local_plugins_only);
}
// ---------------------------------------------------------------------------

void __fastcall TFreeImage::DeInitialise()
{
    FreeImage_DeInitialise();
}
// ---------------------------------------------------------------------------

const char* __fastcall TFreeImage::GetVersion()
{
    return FreeImage_GetVersion();
}
// ---------------------------------------------------------------------------

const char* __fastcall TFreeImage::GetCopyrightMessage()
{
    return FreeImage_GetCopyrightMessage();
}
// ---------------------------------------------------------------------------

void __fastcall TFreeImage::SetOutputMessage(FreeImage_OutputMessageFunction omf)
{
    FreeImage_SetOutputMessage(omf);
}

// ---------------------------------------------------------------------------
// Bitmap management functions
// ---------------------------------------------------------------------------
FIBITMAP* __fastcall TFreeImage::Allocate(int width, int height, int bpp, unsigned red_mask, unsigned green_mask, unsigned blue_mask)
{
    return FreeImage_Allocate(width, height, bpp, red_mask, green_mask, blue_mask);
}
// ---------------------------------------------------------------------------

FIBITMAP* __fastcall TFreeImage::AllocateT(FREE_IMAGE_TYPE type, int width, int height, int bpp, unsigned red_mask, unsigned green_mask, unsigned blue_mask)
{
    return FreeImage_AllocateT(type, width, height, bpp, red_mask, green_mask, blue_mask);
}
// ---------------------------------------------------------------------------

FIBITMAP* __fastcall TFreeImage::Load(FREE_IMAGE_FORMAT fif, const char* filename, int flags)
{
    return FreeImage_Load(fif, filename, flags);
}
// ---------------------------------------------------------------------------

FIBITMAP* __fastcall TFreeImage::LoadU(FREE_IMAGE_FORMAT fif, const wchar_t* filename, int flags)
{
    return FreeImage_LoadU(fif, filename, flags);
}
// ---------------------------------------------------------------------------

FIBITMAP* __fastcall LoadFromHandle(FREE_IMAGE_FORMAT fif, FreeImageIO* io, fi_handle handle, int flags)
{
    return FreeImage_LoadFromHandle(fif, io, handle, flags);
}
// ---------------------------------------------------------------------------

bool __fastcall Save(FREE_IMAGE_FORMAT fif, FIBITMAP* dib, const char* filename, int flags)
{
    return FreeImage_Save(fif, dib, filename, flags);
}
// ---------------------------------------------------------------------------

bool __fastcall TFreeImage::SaveU(FREE_IMAGE_FORMAT fif, FIBITMAP* dib, const wchar_t* filename, int flags)
{
    return FreeImage_SaveU(fif, dib, filename, flags);
}
// ---------------------------------------------------------------------------

bool __fastcall SaveToHandle(FREE_IMAGE_FORMAT fif, FIBITMAP* dib, FreeImageIO* io, fi_handle handle, int flags)
{
    return FreeImage_SaveToHandle(fif, dib, io, handle, flags);
}
// ---------------------------------------------------------------------------

FIBITMAP* __fastcall TFreeImage::Clone(FIBITMAP* dib)
{
    return FreeImage_Clone(dib);
}
// ---------------------------------------------------------------------------

void __fastcall TFreeImage::Unload(FIBITMAP* dib)
{
    FreeImage_Unload(dib);
}
// ---------------------------------------------------------------------------
FREE_IMAGE_FORMAT __fastcall TFreeImage::GetFIFFromFilename(const char* filename)
{
    return FreeImage_GetFIFFromFilename(filename);
}
// ---------------------------------------------------------------------------
FREE_IMAGE_FORMAT __fastcall TFreeImage::GetFIFFromFilenameU(const wchar_t* filename)
{
    return FreeImage_GetFIFFromFilenameU(filename);
}
// ---------------------------------------------------------------------------

bool __fastcall TFreeImage::FIFSupportsReading(FREE_IMAGE_FORMAT fif)
{
    return FreeImage_FIFSupportsReading(fif);
}

// ---------------------------------------------------------------------------

unsigned int __fastcall TFreeImage::GetBPP(FIBITMAP* dib)
{
    return FreeImage_GetBPP(dib);
}
// ---------------------------------------------------------------------------

unsigned int __fastcall TFreeImage::GetWidth(FIBITMAP* dib)
{
    return FreeImage_GetWidth(dib);
}
// ---------------------------------------------------------------------------

unsigned int __fastcall TFreeImage::GetHeight(FIBITMAP* dib)
{
    return FreeImage_GetHeight(dib);
}

// ---------------------------------------------------------------------------
FREE_IMAGE_TYPE __fastcall TFreeImage::GetImageType(FIBITMAP* dib)
{
    return FreeImage_GetImageType(dib);
}

// ---------------------------------------------------------------------------
BITMAPINFOHEADER* __fastcall TFreeImage::GetInfoHeader(FIBITMAP* dib)
{
    return FreeImage_GetInfoHeader(dib);
}

// ---------------------------------------------------------------------------
BITMAPINFO* __fastcall TFreeImage::GetInfo(FIBITMAP* dib)
{
    return FreeImage_GetInfo(dib);
}

// ---------------------------------------------------------------------------
BYTE* __fastcall TFreeImage::GetBits(FIBITMAP* dib)
{
    return FreeImage_GetBits(dib);
}

// ---------------------------------------------------------------------------
FIBITMAP* __fastcall TFreeImage::Rescale(FIBITMAP* dib, int dst_width, int dst_height, FREE_IMAGE_FILTER filter)
{
    return FreeImage_Rescale(dib, dst_width, dst_height, filter);
}

// ---------------------------------------------------------------------------
const char* __fastcall TFreeImage::GetFIFExtensionList(FREE_IMAGE_FORMAT fif)
{
    return FreeImage_GetFIFExtensionList(fif);
}

// ---------------------------------------------------------------------------
FIBITMAP* __fastcall TFreeImage::Rotate(FIBITMAP* dib, double angle, const void* bkcolor)
{
    return FreeImage_Rotate(dib, angle, bkcolor);
}

// ---------------------------------------------------------------------------
FIBITMAP* __fastcall TFreeImage::RotateEx(FIBITMAP* dib, double angle, double x_shift, double y_shift, double x_origin, double y_origin, bool use_mask)
{
    return FreeImage_RotateEx(dib, angle, x_shift, y_shift, x_origin, y_origin, use_mask);
}

// ---------------------------------------------------------------------------
// Filetype functions
// ---------------------------------------------------------------------------
FREE_IMAGE_FORMAT __fastcall TFreeImage::GetFileType(const char* filename, int size)
{
    return FreeImage_GetFileType(filename, size);
}
// ---------------------------------------------------------------------------
FREE_IMAGE_FORMAT __fastcall TFreeImage::GetFileTypeU(const wchar_t* filename, int size)
{
    return FreeImage_GetFileTypeU(filename, size);
}
