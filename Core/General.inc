; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Sec.DirButton:S]
X=((26+5)*[Set.S])r
Y=r
Shape=Rectangle 0,0,26,26,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Shape2=Path Arrow | StrokeWidth (2*[Set.S]) | StrokeStartCap Round | StrokeEndCap Round | Fill Color 0,0,0,1 | Stroke Color #Set.Text_Color# | Scale [Set.S],[Set.S],0,0 | Extend Rotation
Arrow=8,6 | LineTo 18,12 | LineTo 8,18
OverColor=[&Func:returnBool('AniDir', '#CURRENTSECTION#', '#Set.Accent_Color#', '#Set.Text_Color#')],200
LeaveColor=[&Func:returnBool('AniDir', '#CURRENTSECTION#', '#Set.Accent_Color#', '#Set.Text_Color#')],150
LeftMouseUpAction=[!WriteKeyValue Variables AniDir "#CURRENTSECTION#" #Sec.SaveLocation#][!UpdateMeasure Auto_Refresh:M][!Refresh]
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')]"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentContainer
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[HotkeysTitle]
Meter=String
Text=Activation
MeterStyle=Set.String:S | Set.OptionCat:S


[Option01]
Meter=String
Text=Timeout duration (seconds)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:322]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Activate flyouts when media keys are pressed
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:223]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Override native media key functions
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:224123]
Meter=Shape
MeterStyle=Set.Div:S
[Option04]
Meter=String
Text=Activate flyouts with a hotkey
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:22143]
Meter=Shape
MeterStyle=Set.Div:S
[Option05]
Meter=String
Text=Activation hotkey
FontColor=#Set.Text_Color#,(150+105*#OptionalKey#)
MeterStyle=Set.String:S | Set.OptionName:S


[ModuelsTitle]
Meter=String
Text=Modules
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Media / Music
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S12]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=CapsLock / NumLock / ScrollLock
MeterStyle=Set.String:S | Set.OptionName:S


[FunctionTitle]
Meter=String
Text=Operation
MeterStyle=Set.String:S | Set.OptionCat:S

[Option21]
Meter=String
Text=Smart volume keys - hold shift to change player volume instead of system
FontColor=#Set.Text_Color#,(150+105*#Media#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S12391321]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Volume to change when volume key is pressed
MeterStyle=Set.String:S | Set.OptionName:S

[HotkeysTitle3]
Meter=String
Text=Animation
MeterStyle=Set.String:S | Set.OptionCat:S
[Option31]
Meter=String
Text=Slide animations
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S132]
Meter=Shape
MeterStyle=Set.Div:S
[Option32]
Meter=String
Text=Animation easing type
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S1342]
Meter=Shape
MeterStyle=Set.Div:S
[Option33]
Meter=String
Text=Animation direction
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S21342]
Meter=Shape
MeterStyle=Set.Div:S
[Option34]
Meter=String
Text=Animation steps
MeterStyle=Set.String:S | Set.OptionName:S


; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;


[Timeout]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|1|20
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Timeout#
MeterStyle=Set.String:S | Set.Value:S
[MediaKeys]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])
[OverrideNativeKeyFunction]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option03:Y]-#Set.P#+(-20/2+8)*[Set.S])
[OptionalKey]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option04:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Button04]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option05:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startSide('Hotkey')"]
Hidden=(1-#OptionalKey#)
[Value04]
Meter=String
Text=#KeyInString#
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#OptionalKey#)

[Media]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Locks]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option12:Y]-#Set.P#+(-20/2+8)*[Set.S])

[SmartVolume]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option21:Y]-#Set.P#+(-20/2+8)*[Set.S])
[MediaKeyChange]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|1|20
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value22]
Meter=String
Text=#MediaKeyChange#
MeterStyle=Set.String:S | Set.Value:S

[Ani]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option31:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Easetype]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option32:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startSide('Ease')"]
[Value32]
Meter=String
Text=#Easetype#
MeterStyle=Set.String:S | Set.Value:S
[Left]
Meter=Shape
X=(#Set.W#-#Set.L#-#Set.P#*2-((26*4+5*3)*[Set.S]))
Y=([Option33:Y]-#Set.P#+(-26/2+8)*[Set.S])
MeterStyle=Sec.DirButton:S
[Right]
Meter=Shape
Rotation=Rotate 180
MeterStyle=Sec.DirButton:S
[Top]
Meter=Shape
Rotation=Rotate 90
MeterStyle=Sec.DirButton:S
[Bottom]
Meter=Shape
Rotation=Rotate 270
MeterStyle=Sec.DirButton:S
[AniSteps]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int|10|40
Y=([Option34:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value34]
Meter=String
Text=#AniSteps#
MeterStyle=Set.String:S | Set.Value:S

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini