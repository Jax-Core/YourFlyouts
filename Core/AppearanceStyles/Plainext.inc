
[Option01]
Meter=String
Text="Font face"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:01]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text="Divider character"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:02]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text="Divider length"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:03]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text="Divider cap character"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:04]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text="Bar character"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:05]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text="Bar length"
MeterStyle=Set.String:S | Set.OptionName:S

[ColorTitle]
Meter=String
Text="Color settings"
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text="Font color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:11]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text="Shadow color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:12]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text="Bar color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:122]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text="Bar fill color"
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0.5|2
Y=([Option00:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value00]
Meter=String
Text="#Scale#x"
MeterStyle=Set.String:S | Set.Value:S
[Fontface]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text="#Fontface#"
MeterStyle=Set.String:S | Set.Value:S
[DividerCharacter]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text="#DividerCharacter#"
MeterStyle=Set.String:S | Set.Value:S
[DividerLength]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|40
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text="#DividerLength#"
MeterStyle=Set.String:S | Set.Value:S
[DividerCap]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option04:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value04]
Meter=String
Text="#DividerCap#"
MeterStyle=Set.String:S | Set.Value:S
[BarCharacter]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value05]
Meter=String
Text="#BarCharacter#"
MeterStyle=Set.String:S | Set.Value:S
[BarLength]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|0|40
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value06]
Meter=String
Text="#BarLength#"
MeterStyle=Set.String:S | Set.Value:S

[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Primary]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Num|1|255
[Value12]
Meter=String
Text=#PrimaryOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[FontColor2]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[AccentColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R