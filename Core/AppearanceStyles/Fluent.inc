
[Option01]
Meter=String
Text="Height"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:01]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text="Rounding radius"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:02]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text="Font face"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:05]
Meter=Shape
MeterStyle=Set.Div:S
[Option06]
Meter=String
Text="Bar cap"
MeterStyle=Set.String:S | Set.OptionName:S

[ColorTitle]
Meter=String
Text="Color settings"
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text="Background color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:11]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text="Top tier font color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:13]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text="Second tier font color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:14]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text="Accent color"
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
[Height]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|50|300
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text="#Height#"
MeterStyle=Set.String:S | Set.Value:S
[R]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|20
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text="#R# px"
MeterStyle=Set.String:S | Set.Value:S
[Fontface]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text="#Fontface#"
MeterStyle=Set.String:S | Set.Value:S
[Cap:]
Meter=Shape
0Act=[!WriteKeyValue Variables Cap "Flat" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Cap "Round" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Cap "Triangle" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Cap', 'Round')]+[&Func:returnBool('Cap', 'Triangle')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option06:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Cap:0]
Meter=String
Text=Flat
FontColor=[&Func:returnBool('Cap', 'Flat', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S
[Cap:1]
Meter=String
Text=Round
FontColor=[&Func:returnBool('Cap', 'Round', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S
[Cap:2]
Meter=String
Text=Triangle
FontColor=[&Func:returnBool('Cap', 'Triangle', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S

[Primary]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Num|1|255
[Value11]
Meter=String
Text=#PrimaryOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[FontColor2]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[AccentColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R