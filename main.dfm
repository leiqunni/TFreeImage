object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 190
  ClientWidth = 632
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
    Height = 190
    Align = alLeft
    ExplicitHeight = 330
  end
  object FIImageBox1: TFIImageBox
    Left = 316
    Top = 0
    Width = 316
    Height = 190
    Align = alClient
    TabOrder = 0
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
    Left = 240
    Top = 96
  end
end
