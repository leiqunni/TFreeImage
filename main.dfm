object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 306
  ClientWidth = 575
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object ScrollBox1: TScrollBox
    Left = 288
    Top = 0
    Width = 287
    Height = 306
    HorzScrollBar.Smooth = True
    HorzScrollBar.Tracking = True
    VertScrollBar.Smooth = True
    VertScrollBar.Tracking = True
    Align = alRight
    TabOrder = 0
    OnResize = ScrollBox1Resize
    object Image1: TImage
      Left = 152
      Top = 112
      Width = 89
      Height = 73
      AutoSize = True
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
      OnMouseUp = Image1MouseUp
    end
  end
  object Button1: TButton
    Left = 24
    Top = 8
    Width = 25
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object FIBox1: TFIBox
    Left = 0
    Top = 0
    Width = 288
    Height = 306
    Align = alClient
    TabOrder = 2
  end
  object FreeImage1: TFreeImage
    Left = 184
    Top = 16
  end
end
