[Variables]
H=(#Height#*#scale#)
VolumeW=(#H#)
MediaW=(#H#)
LocksW=(#H#)
P=(10*#Scale#)
SeparateMedia=1

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=#Blur#
Corner=#BlurCorner#

[mVolume]
Measure=Plugin
Plugin=Win7AudioPlugin
DynamicVariables=1
OnChangeAction=[!UpdateMeterGroup Dynamic][!Redraw]
IfCondition=mVolume < 20
IfTrueAction=[!SetOption VolumeIcon Text "[\xe04f]"]
IfCondition2=(mVolume >= 20) && (mVolume < 50)
IfTrueAction2=[!SetOption VolumeIcon Text "[\xe04e]"]
IfCondition3=(mVolume >= 50) && (mVolume < 90)
IfTrueAction3=[!SetOption VolumeIcon Text "[\xe04d]"]
IfCondition4=(mVolume >= 90)
IfTrueAction4=[!SetOption VolumeIcon Text "[\xe050]"]
UpdateDivider=1


; --------------------------------- VolumeBar -------------------------------- ;

[VolumeB]
Meter=Shape
X=1
Y=1
Shape=Rectangle 0,0,#VolumeW#,#H#,[&Func:returnCorner()] | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #BorderColor#,#BorderOpacity#
Group=Standard
DynamicVariables=1
[VolumeC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#VolumeW#,#H#,[&Func:returnCorner()]  | StrokeWidth 0
Group=Standard
DynamicVariables=1

[VolumeIcon]
Meter=String
MeterStyle=String:S
X=(#VolumeW#/2)
Y=(#H#/2)
FontFace=Material Icons Round
StringAlign=CenterCenter
FontSize=(34*#scale#)
Group=Dynamic | Standard
FontColor=#FontColor#,(255*[mVolume:]/100)
DynamicVariables=1
InlineSetting=Shadow | 0 | 0 | 5 | #GlowColor#,#GlowOpacity#
Container=VolumeC

[VolumeString]
Meter=String
MeterStyle=String:S
X=(#VolumeW#/2)
Y=(#p#*3)r
StringAlign=Center
FontWeight=650
FontSize=(10*#scale#)
Text=[mVolume:]
DynamicVariables=1
Group=Dynamic | Standard
Container=VolumeC
InlineSetting=Shadow | 0 | 0 | 5 | #GlowColor#,#GlowOpacity#
FontFace=#FontFace#

; ---------------------------------------------------------------------------- ;
;                                  End of port                                 ;
; ---------------------------------------------------------------------------- ;

; ; --------------------------------- Media -------------------------------- ;

[MediaB]
Meter=Shape
X=1
Y=1
Shape=Rectangle 0,0,#MediaW#,#H#,[&Func:returnCorner()] | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #BorderColor#,#BorderOpacity#
Group=Music | Standard
DynamicVariables=1
[MediaC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#MediaW#,#H#,[&Func:returnCorner()] | StrokeWidth 0
Group=Music | Standard
DynamicVariables=1

[MediaPlayPause]
Meter=Image
W=(#MediaW#)
H=(#MediaW#)
PreserveAspectRatio=2
ImageAlpha=#MediaImageOpacity#
ImageName=[#PlayerType#Cover]
DynamicVariables=1
Group=Music | Standard | MediaImage
Container=MediaC
[Play]
Greyscale=1
LeftMouseUpAction=[!SetOption MediaPlayPause MeterStyle Pause][!UpdateMeter MediaPlayPause][!Redraw][!CommandMeasure state#NowPlayingMedia# "PlayPause"]
[Pause]
Greyscale=0
LeftMouseUpAction=[!SetOption MediaPlayPause MeterStyle Play][!UpdateMeter MediaPlayPause][!Redraw][!CommandMeasure state#NowPlayingMedia# "PlayPause"]

[MediaTrack]
Meter=String
MeterStyle=String:S
X=(#MediaW#/2)
Y=#P#
W=(#MediaW#-#P#*2)
FontSize=(Clamp(14*#scale#, 0, 14))
ClipString=1
StringAlign=Center
Text=[#PlayerType#Track]
DynamicVariables=1
Group=Music | Standard
Container=MediaC
[MediaArtist]
Meter=String
MeterStyle=String:S
X=r
Y=(#P#/2)R
W=(#MediaW#-#P#*2)
FontSize=(Clamp(10*#scale#, 0, 10))
ClipString=1
StringAlign=Center
Text=[#PlayerType#Artist]
FontWeight=600
DynamicVariables=1
Group=Music | Standard
Container=MediaC


[Previous]
Meter=String
[Next]
Meter=String
[MediaHeart]
Meter=String
[MediaShuffle]
Meter=String


[MediaCurrentPosition]
Meter=String
MeterStyle=String:S
X=#P#
Y=(#H#-#P#*2)
W=(#MediaW#-#P#*2)
FontSize=(8*#scale#)
ClipString=1
StringAlign=LeftBottom
Text=[#PlayerType#CurrentPosition]
DynamicVariables=1
UpdateDivider=1
FontColor=#FontColor#,100
Group=Music | Standard
Container=MediaC
[MediaLength]
Meter=String
MeterStyle=String:S
X=(#MediaW#-#P#)
Y=(#H#-#P#*2)
W=(#MediaW#-#P#*2)
FontSize=(8*#scale#)
ClipString=1
StringAlign=RightBottom
Text=[#PlayerType#Length]
DynamicVariables=1
FontColor=#FontColor#,100
Group=Music | Standard
Container=MediaC
[ProgBar]
Meter=Shape
Y=(#H#-5*#scale#)
Shape=Rectangle 0,0,(#MediaW#),(5*#scale#) | StrokeWidth 0 | Fill Color #FontColor#,50
Shape2=Rectangle 0,0,((#MediaW#)*[#PlayerType#Progress]/100),(5*#scale#) | StrokeWidth 0 | Fill Color #FontColor#
This=0 | #AccentCOlor1# ; 0.0 | #AccentColor2# ; 1.0
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#MediaW#)*100)"][!UpdateMeasure PosCalc]
DynamicVariables=1
UpdateDivider=1
Group=Music | Standard
Container=MediaC
[PosCalc]
Measure=calc
OnUpdateAction=[!CommandMeasure state#NowPlayingMedia# "SetPosition [PosCalc]"][!UpdateMeasure #PlayerType#Progress]
Disabled=1
DynamicVariables=1
UpdateDivider=-1
Group=NUOL

; ---------------------------------------------------------------------------- ;
;                                    Special                                   ;
; ---------------------------------------------------------------------------- ;

; ----------------------------------- Caps ----------------------------------- ;

[LocksB]
Meter=Shape
X=1
Y=1
Shape=Rectangle 0,0,#LocksW#,#H#,[&Func:returnCorner()] | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #BorderColor#,#BorderOpacity#
Group=Locks | Special
Hidden=1
DynamicVariables=1
[LocksC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#LocksW#,#H#,[&Func:returnCorner()] | StrokeWidth 0
Group=Locks | Special
Hidden=1
DynamicVariables=1



[LocksIcon]
Meter=String
MeterStyle=String:S
X=(#Locksw#/2)
Y=(#Locksw#/2)
Text=[\xe835]
FontFace=Material Icons Round
StringAlign=CenterCenter
FontSize=(32*#scale#)
InlineSetting=Shadow | 0 | 0 | 5 | #GlowColor#,#GlowOpacity#
Group=Locks | Special
Container=LocksC
Hidden=1
[LocksText]
Meter=String
MeterStyle=String:S
X=r
Y=(#P#*3)r
W=(#LocksW#)
StringAlign=Center
ClipString=2
FontSize=(10*#scale#)
InlineSetting=Shadow | 0 | 0 | 5 | #GlowColor#,#GlowOpacity#
Group=Locks | Special
Container=LocksC
Hidden=1