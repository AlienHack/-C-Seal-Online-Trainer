object frmMaiNX: TfrmMaiNX
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #3650#3611#3619#3649#3585#3619#3617#3650#3585#3591' '#3595#3637#3621#3621#3621#3621#3621' '#3629#3636#3629#3636' [2017.04.07] - AlienHack'
  ClientHeight = 95
  ClientWidth = 574
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 15
    Width = 18
    Height = 13
    Caption = #3605#3637#3652#3623
  end
  object Label2: TLabel
    Left = 13
    Top = 42
    Width = 21
    Height = 13
    Caption = #3623#3636#3656#3591#3652#3623
  end
  object Label3: TLabel
    Left = 375
    Top = 13
    Width = 91
    Height = 13
    Caption = #3588#3623#3619#3605#3633#3657#3591#3652#3623#3657#3607#3637#3656' 40 - 150'
  end
  object Label4: TLabel
    Left = 375
    Top = 42
    Width = 67
    Height = 13
    Caption = #3605#3633#3657#3591#3648#3607#3656#3634#3652#3627#3619#3656#3585#3655#3652#3604#3657
  end
  object Label5: TLabel
    Left = 158
    Top = 74
    Width = 96
    Height = 13
    Caption = 'F1 '#3623#3634#3611#3605#3634#3617#3648#3617#3657#3634#3609#3632' '#3629#3636#3629#3636
    Color = clHighlight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label6: TLabel
    Left = 270
    Top = 74
    Width = 184
    Height = 13
    Caption = #3629#3629#3650#3605#3657#3588#3629#3617#3650#3610' x21 '#3585#3604' D '#3651#3594#3657#3588#3641#3656#3585#3633#3610#3617#3634#3650#3588#3619#3609#3632
    Color = clHighlight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object oriAtk: TEdit
    Left = 40
    Top = 12
    Width = 121
    Height = 21
    Enabled = False
    ReadOnly = True
    TabOrder = 0
  end
  object oriRun: TEdit
    Left = 40
    Top = 39
    Width = 121
    Height = 21
    Enabled = False
    ReadOnly = True
    TabOrder = 1
  end
  object modAtk: TEdit
    Left = 167
    Top = 12
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '70'
  end
  object modRun: TEdit
    Left = 167
    Top = 39
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '300'
  end
  object Button1: TButton
    Left = 294
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Set '#3605#3637#3652#3623
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 294
    Top = 39
    Width = 75
    Height = 25
    Caption = 'Set '#3623#3636#3656#3591#3652#3623
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 476
    Top = 8
    Width = 85
    Height = 61
    Caption = 'Omnislash [F2]'
    TabOrder = 6
    OnClick = Button3Click
  end
  object CheckBox1: TCheckBox
    Left = 40
    Top = 66
    Width = 97
    Height = 17
    Caption = #3605#3637#3652#3585#3621#3649#3626#3609#3652#3585#3621
    TabOrder = 7
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 476
    Top = 75
    Width = 97
    Height = 17
    Caption = #3623#3634#3619#3660#3611#3605#3637#3652#3585#3621#3654
    TabOrder = 8
  end
  object tReader: TTimer
    OnTimer = tReaderTimer
    Left = 560
    Top = 72
  end
  object tAttack: TTimer
    Enabled = False
    OnTimer = tAttackTimer
    Left = 560
    Top = 72
  end
  object tMovement: TTimer
    Enabled = False
    Interval = 200
    OnTimer = tMovementTimer
    Left = 560
    Top = 64
  end
  object nocdSkill2: TTimer
    Enabled = False
    Interval = 1
    Left = 560
    Top = 72
  end
  object Omnislash: TTimer
    Enabled = False
    Interval = 30
    OnTimer = OmnislashTimer
    Left = 560
    Top = 64
  end
  object HotkeyManager: TTimer
    Interval = 1
    OnTimer = HotkeyManagerTimer
    Left = 560
    Top = 64
  end
  object CCombo: TTimer
    Interval = 30
    OnTimer = CComboTimer
    Left = 360
    Top = 72
  end
end
