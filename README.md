# FreeImage VCL wrapper with BCB

## What is this?

To use FreeImage library from C++Builder. I love C++.

## How to use...

1.  Load project.
2.  build and install.
3.  you will see FreeImage tab in tool pallet.
4.  D&D to form.
5.  Execute sample project program, read sample code.

## Sample code

    FIBITMAP *dib = NULL;  
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;  

    // check the file signature and deduce its format  
    // (the second argument is currently not used by FreeImage)  
    fif = FreeImage1-&gt;GetFIFFromFilenameU(FileName.w_str());  
    if (fif == FIF_UNKNOWN) {  
        // no signature ?  
        // try to guess the file format from the file extension  
        fif = FreeImage1-&gt;GetFIFFromFilenameU(FileName.w_str());  
    }  

    // check that the plugin has reading capabilities ...  
    if ((fif != FIF_UNKNOWN) &amp;&amp; FreeImage1-&gt;FIFSupportsReading(fif)) {  
        // ok, let's load the file  
        dib = FreeImage1-&gt;LoadU(fif, FileName.w_str(), Flags);  
    }

    if (dib) {  
        HDC hDc = ::GetDC(0);  

        // create HBitmap from FBitmap
        HBITMAP hBmp = ::CreateDIBitmap(hDc, FreeImage1-&gt;GetInfoHeader(dib), CBM_INIT, FreeImage1-&gt;GetBits(dib), FreeImage1-&gt;GetInfo(dib), DIB_RGB_COLORS);  
        ::ReleaseDC(0, hDc);  
        FreeImage1-&gt;Unload(dib);  

        // hand over to VCL TPicture hBmp pointer.
        this-&gt;Picture-&gt;Bitmap-&gt;Handle = hBmp;  
    }  

" style="border: 0px; display: block;font-family: Consolas, Inconsolata, Courier, monospace; font-weight: bold; white-space: pre; margin: 0px;border-top-left-radius: 3px; border-top-right-radius: 3px; border-bottom-right-radius: 3px; border-bottom-left-radius: 3px; word-wrap: break-word; border: 1px solid rgb(204, 204, 204); padding: 0px 5px; margin: 0px 2px;font-size: 1em; letter-spacing: -1px; font-weight: bold;">ShowMessage(FreeImage1->GetVersion()); FIBITMAP *dib = NULL; FREE_IMAGE_FORMAT fif = FIF_UNKNOWN; // check the file signature and deduce its format // (the second argument is currently not used by FreeImage) fif = FreeImage1->GetFIFFromFilenameU(FileName.w_str()); if (fif == FIF_UNKNOWN) { // no signature ? // try to guess the file format from the file extension fif = FreeImage1->GetFIFFromFilenameU(FileName.w_str()); } // check that the plugin has reading capabilities ... if ((fif != FIF_UNKNOWN) && FreeImage1->FIFSupportsReading(fif)) { // ok, let's load the file dib = FreeImage1->LoadU(fif, FileName.w_str(), Flags); } if (dib) { HDC hDc = ::GetDC(0); // create HBitmap from FBitmap HBITMAP hBmp = ::CreateDIBitmap(hDc, FreeImage1->GetInfoHeader(dib), CBM_INIT, FreeImage1->GetBits(dib), FreeImage1->GetInfo(dib), DIB_RGB_COLORS); ::ReleaseDC(0, hDc); FreeImage1->Unload(dib); // hand over to VCL TPicture hBmp pointer. this->Picture->Bitmap->Handle = hBmp; } /html>