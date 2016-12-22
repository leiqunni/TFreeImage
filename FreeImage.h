// ---------------------------------------------------------------------------

#ifndef FreeImageH
#define FreeImageH
// ---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Vcl.Graphics.hpp>

#include "Dist\FreeImage.h"

// ---------------------------------------------------------------------------
class PACKAGE TFreeImage : public TComponent {
private:
protected:
public:
    const char* __fastcall GetFIFExtensionList(FREE_IMAGE_FORMAT fif);

    FIBITMAP* __fastcall Rescale(FIBITMAP* dib, int dst_width, int dst_height, FREE_IMAGE_FILTER filter);

    bool __fastcall FIFSupportsReading(FREE_IMAGE_FORMAT fif);
    FREE_IMAGE_FORMAT __fastcall GetFIFFromFilename(const char* filename);
    FREE_IMAGE_FORMAT __fastcall GetFIFFromFilenameU(const wchar_t* filename);

    BITMAPINFOHEADER* __fastcall GetInfoHeader(FIBITMAP* dib);
    BITMAPINFO* __fastcall GetInfo(FIBITMAP* dib);
    BYTE* __fastcall GetBits(FIBITMAP* dib);

    // Original functions
    HBITMAP __fastcall LoadHBitmap(const String filename);
    TBitmap* __fastcall LoadTBitmap(const String filename);

    // General functions
    void __fastcall Initialise(bool load_local_plugins_only = false);
    void __fastcall DeInitialise();
    const char* __fastcall GetVersion();
    const char* __fastcall GetCopyrightMessage();
    void __fastcall SetOutputMessage(FreeImage_OutputMessageFunction omf);
    void __fastcall SetOutputMessageStdCall(FreeImage_OutputMessageFunctionStdCall omf);
    bool __fastcall Save(FREE_IMAGE_FORMAT fif, FIBITMAP* dib, const char* filename, int flags FI_DEFAULT(0));
	bool __fastcall SaveU(FREE_IMAGE_FORMAT fif, FIBITMAP* dib, const wchar_t* filename, int flags FI_DEFAULT(0));
    bool __fastcall SaveToHandle(FREE_IMAGE_FORMAT fif, FIBITMAP* dib, FreeImageIO* io, fi_handle handle, int flags = 0);
    FIBITMAP* __fastcall Clone(FIBITMAP* dib);
    void __fastcall Unload(FIBITMAP* dib);

    // Bitmap management functions
    //	unsigned int __fastcall GetColorsUsed(FIBITMAP *dib);
    FIBITMAP* __fastcall Allocate(int width, int height, int bpp, unsigned red_mask FI_DEFAULT(0), unsigned green_mask FI_DEFAULT(0), unsigned blue_mask FI_DEFAULT(0));
    FIBITMAP* __fastcall AllocateT(FREE_IMAGE_TYPE type, int width, int height, int bpp = 8, unsigned red_mask = 0, unsigned green_mask = 0, unsigned blue_mask = 0);
    FIBITMAP* __fastcall Load(FREE_IMAGE_FORMAT fif, const char* filename, int flags = 0);
    FIBITMAP* __fastcall LoadU(FREE_IMAGE_FORMAT fif, const wchar_t* filename, int flags = 0);
    FIBITMAP* __fastcall LoadFromHandle(FREE_IMAGE_FORMAT fif, FreeImageIO* io, fi_handle handle, int flags = 0);

    // Bitmap information functions
    FREE_IMAGE_TYPE __fastcall GetImageType(FIBITMAP* dib);
    unsigned int __fastcall GetColorsUsed(FIBITMAP* dib);
    unsigned int __fastcall GetBPP(FIBITMAP* dib);
    unsigned int __fastcall GetWidth(FIBITMAP* dib);
    unsigned int __fastcall GetHeight(FIBITMAP* dib);
    unsigned int __fastcall GetLine(FIBITMAP* dib);
    unsigned int __fastcall GetPitch(FIBITMAP* dib);
    unsigned int __fastcall GetDIBSize(FIBITMAP* dib);
    RGBQUAD* __fastcall GetPalette(FIBITMAP* dib);

    // Pixel access functions

    // Conversion functions

    // Filetype functions
    FREE_IMAGE_FORMAT __fastcall GetFileType(const char* filename, int size = 0);
    FREE_IMAGE_FORMAT __fastcall GetFileTypeU(const wchar_t* filename, int size = 0);
    FREE_IMAGE_FORMAT __fastcall GetFileTypeFromHandle(FreeImageIO* io, fi_handle handle, int size = 0);
    FREE_IMAGE_FORMAT __fastcall GetFileTypeFromMemory(FIMEMORY* stream, int size = 0);

    // Rotation and flipping
    FIBITMAP* __fastcall Rotate(FIBITMAP* dib, double angle, const void* bkcolor = NULL);
    FIBITMAP* __fastcall RotateEx(FIBITMAP* dib, double angle, double x_shift, double y_shift, double x_origin, double y_origin, bool use_mask);

    // Plugin functions

    // Multipage functions
    FIMULTIBITMAP* __fastcall OpenMultiBitmap(FREE_IMAGE_FORMAT fif, const char* filename, bool create_new, bool read_only, bool keep_cache_in_memory = false, int flags = 0);
    FIMULTIBITMAP* __fastcall OpenMultiBitmapFromHandle(FREE_IMAGE_FORMAT fif, FreeImageIO* io, fi_handle handle, int flags = 0);
    bool __fastcall CloseMultiBitmap(FIMULTIBITMAP* bitmap, int flags = 0);

    __fastcall TFreeImage(TComponent* Owner);

__published:
};
// ---------------------------------------------------------------------------
#endif
