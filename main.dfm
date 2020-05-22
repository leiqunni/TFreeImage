object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 350
  ClientWidth = 761
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 316
    Height = 350
    Align = alLeft
    ExplicitLeft = -6
    ExplicitHeight = 190
  end
  object FIImageBox1: TFIImageBox
    Left = 316
    Top = 0
    Width = 445
    Height = 350
    HorzScrollBar.Tracking = True
    VertScrollBar.Tracking = True
    Align = alClient
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 0
    ExplicitLeft = 472
    ExplicitTop = 112
    ExplicitWidth = 241
    ExplicitHeight = 193
  end
  object MainMenu1: TMainMenu
    Left = 72
    Top = 144
    object mnuFile: TMenuItem
      Caption = '&File'
      Checked = True
    end
    object mnuView: TMenuItem
      Caption = '&View'
      object mnuViewZoomMode: TMenuItem
        Caption = 'Zoom Mode'
        object mnuViewArctual: TMenuItem
          AutoCheck = True
          Caption = 'Arctual'
          RadioItem = True
          OnClick = mnuViewArctualClick
        end
        object mnuViewFit: TMenuItem
          AutoCheck = True
          Caption = 'Fit'
          RadioItem = True
          OnClick = mnuViewFitClick
        end
        object mnuViewStretch: TMenuItem
          AutoCheck = True
          Caption = 'Stretch'
          RadioItem = True
          OnClick = mnuViewStretchClick
        end
      end
    end
  end
  object FreeImage1: TFreeImage
    Left = 360
    Top = 232
  end
end
