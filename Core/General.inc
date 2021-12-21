[HotkeysTitle]
Meter=String
Text=Flyouts activation
MeterStyle=Set.String:S | Set.OptionCat:S


[Option01]
Meter=String
Text=Timeout duration (seconds)
MeterStyle=Set.String:S | Set.OptionName:S


[ModuelsTitle]
Meter=String
Text=Flyouts modules
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
Text=Fetch media thumbnail
FontColor=#Set.Text_Color#,(150+105*#Media#)
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S12391]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=CapsLock / NumLock / ScrollLock
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

[Media]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])
[FetchImage]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option12:Y]-#Set.P#+(-20/2+8)*[Set.S])
Hidden=(1-#Media#)
[Locks]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option13:Y]-#Set.P#+(-20/2+8)*[Set.S])