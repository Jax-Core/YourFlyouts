[Option01]
Meter=String
X=r
Text=Select a layout, this will change your base settings that are not attached to the layout.
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
; ---------------------------------------------------------------------------- ;

[Preset:M]
Measure=Script
ScriptFile=#@#Lua\PresetLoad.lua

[Select:S]
X=(20*[Set.S])R
Y=r
W=([ContentContainer:W]/2-20*[Set.S])
ImageName=#SKINSPATH##Skin.Name#\Core\Layout\#CURRENTSECTIOn#.png
DynamicVariables=1
ImageAlpha=200
MouseOverAction=[!SetOption #CURRENTSECTION# ImageAlpha "255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageAlpha "200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Leftmouseupaction=[!CommandMeasure Preset:M "ChangeTo('#CURRENTSECTION#')"][!UpdateMeasure Auto_Refresh:M][!Refresh]
DynamicVariables=1
MaskImageName=#SKINSPATH##Skin.Name#\Core\Layout\Mask.png
Container=ContentContainer
[Selected:S]
ImageAlpha=255
MouseOverAction=
MouseLeaveAction=
LeftMouseUpAction=

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


[CoreUI]
Meter=Image
X=r
Y=(30*[Set.S])R
MeterStyle=Select:S

[Side]
Meter=Image
MeterStyle=Select:S

[Modern]
Meter=Image
X=(20*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Select:S

[Plainext]
Meter=Image
MeterStyle=Select:S

[Simple]
Meter=Image
X=(20*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Select:S

[center]
Meter=Image
MeterStyle=Select:S