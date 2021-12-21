[Rainmeter]
SkinWidth=(600*#scale#)

[Variables]
W=(500*#scale#)
P=(10*#scale#)

[String:S]
X=r
Y=R
InlineSetting=Shadow | 0 | 0 | 5 | #PrimaryColor#,#PrimaryOpacity#
FontSize=(16*#scale#)
DynamicVariables=1
[Sec.Div:S]
X=r
Y=R
Text=#DividerCap#[&Func:returnDiv('#DividerCharacter#')]#DividerCap#
H=(30*#scale#)
DynamicVariables=1
FontFace=#FontFace#
FontSize=(16*#scale#)
AntiAlias=1
FontColor=#FontColor#

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;


[mVolume]
Measure=Plugin
Plugin=Win7AudioPlugin
DynamicVariables=1
OnChangeAction=[!UpdateMeterGroup Dynamic][!Redraw]
UpdateDivider=1

; ---------------------------------- Volume ---------------------------------- ;

[Volume]
Meter=String
MeterStyle=String:S
X=#P#
Y=#p#
Text=Volume: [mVolume:]% [&Func:returnDiv('#BarCharacter#')]
inlinepattern2=[&Func:checkEscape('#BarCharacter#')']
InlineSetting2=Color | #FontCOlor2#
InlinePattern3=\s[&Func:checkEscape('#BarCharacter#')']{[&Func:returnBar('mVolume')]}
InlineSetting3=Color | #AccentColor#
DynamicVariables=1
Group=Dynamic | Standard
[Div:1]
Meter=String
MEterStyle=Sec.Div:S
Group=Standard

; ----------------------------------- Media ---------------------------------- ;

[MediaTrack]
Meter=String
MeterStyle=String:S
Text=[#PlayerType#Track] [&Func:returnBool('[&state#NowPlayingMedia#:]', '2', '> Paused <', '')]
FontWeight=650
FontSize=(18*#scale#)
Group=Music | Standard
[MediaArtist]
Meter=String
MeterStyle=String:S
Text=[#PlayerType#Artist]
Group=Music | Standard
[MediaBar]
Meter=String
Y=(10*#Scale#)R
MeterStyle=String:S
FontSize=(12*#scale#)
Text=[#PlayerType#CurrentPosition] [&Func:returnDiv('#BarCharacter#')] [#PlayerType#Length]
inlinepattern2=[&Func:checkEscape('#BarCharacter#')']
InlineSetting2=Color | #FontCOlor2#
InlinePattern3=\s[&Func:checkEscape('#BarCharacter#')']{[&Func:returnBar('#PlayerType#Progress')]}
InlineSetting3=Color | #AccentColor#
Group=Music | Standard
UpdateDivider=1
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/([#CURRENTSECTION#:W]-#P#)*100)"][!UpdateMeasure PosCalc]
[PosCalc]
Measure=calc
OnUpdateAction=[!CommandMeasure state#NowPlayingMedia# "SetPosition [PosCalc]"]
Disabled=1
DynamicVariables=1
UpdateDivider=-1
Group=NUOL
[MediaStates]
Meter=String
X=r
MeterStyle=String:S
FontSize=(12*#scale#)
Text=[#PlayerType#Player] | Heart: [#PlayerType#Heart] Shuffle: [#PlayerType#Shuffle]
Group=Music | Standard




; ---------------------------------------------------------------------------- ;
;                                    Special                                   ;
; ---------------------------------------------------------------------------- ;

; ----------------------------------- Caps ----------------------------------- ;
[LocksText]
Meter=String
MeterStyle=String:S
X=#P#
Y=#p#
Group=Locks | Special
[Div:2]
Meter=String
MEterStyle=Sec.Div:S
Group=Locks | Special