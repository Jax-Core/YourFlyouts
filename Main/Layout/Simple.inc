[Variables]
H=(#Height#*#scale#)
VolumeW=(#H#)
MediaW=(470*#Scale#)
LocksW=(#H#)
P=(20*#Scale#)

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;


[mVolume]
Measure=Plugin
Plugin=Win7AudioPlugin
DynamicVariables=1
OnChangeAction=[!UpdateMeterGroup Dynamic][!Redraw]
; IfCondition=mVolume < 20
; IfTrueAction=[!SetOption VolumeIcon Text "[\xE992]"]
; IfCondition2=(mVolume >= 20) && (mVolume < 50)
; IfTrueAction2=[!SetOption VolumeIcon Text "[\xE993]"]
; IfCondition3=(mVolume >= 50) && (mVolume < 90)
; IfTrueAction3=[!SetOption VolumeIcon Text "[\xE994]"]
; IfCondition4=(mVolume >= 90)
; IfTrueAction4=[!SetOption VolumeIcon Text "[\xE995]"]
UpdateDivider=1


; --------------------------------- VolumeBar -------------------------------- ;

[VolumeB]
Meter=Shape
X=1
Y=1
Shape=Rectangle 0,0,#VolumeW#,#H#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity#
Group=Standard
MouseScrollUpAction=[!CommandMeasure "mVolume" "ChangeVolume 2"][!UpdateMeasure mVolume]
MouseScrollDownAction=[!CommandMeasure "mVolume" "ChangeVolume -2"][!UpdateMeasure mVolume]
[VolumeC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#VolumeW#,#H#,#R# | StrokeWidth 0
Group=Standard

[RoundLineBehind]
Meter=RoundLine
X=#P#
Y=#P#
W=(#H#-2*#P#)
H=(#H#-2*#P#)
StartAngle=4.712
RotationAngle=6.283
LineLength=((#H#-2*#P#)/2)
LineStart=((#H#-2*#P#)/2-2*#scale#)
LineColor=#FontColor2#
Solid=1
AntiAlias=1
Container=VolumeC
[RoundLine]
Meter=RoundLine
MeasureName=mVolume
X=#P#
Y=#P#
W=(#H#-2*#P#)
H=(#H#-2*#P#)
StartAngle=4.712
RotationAngle=6.283
LineLength=((#H#-2*#P#)/2)
LineStart=((#H#-2*#P#)/2-4*#scale#)
LineColor=#AccentColor1#
Solid=1
AntiAlias=1
Group=Dynamic
Container=VolumeC

[VolumeString]
Meter=String
MeterStyle=String:S
X=(#H#/2)
Y=(#H#/2)
StringAlign=CenterCenter
FontWeight=650
FontSize=(20*#scale#)
Text=[mVolume:]
DynamicVariables=1
Group=Dynamic | Standard
Container=VolumeC
FontFace=#FontFace2#

; --------------------------------- Media -------------------------------- ;

[MediaB]
Meter=Shape
X=#P#R
Y=r
Shape=Rectangle 0,0,#MediaW#,#H#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity#
Group=Music | Standard
[MediaC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#MediaW#,#H#,#R# | StrokeWidth 0
Group=Music | Standard

[MediaTrack]
Meter=String
MeterStyle=String:S
X=#P#
Y=(20*#scale#)r
W=(#MediaW#-#P#*2)
FontSize=(20*#scale#)
ClipString=1
Text=[#PlayerType#Track]
DynamicVariables=1
FontFace=#FontFace2#
Group=Music | Standard
Container=MediaC
[MediaArtist]
Meter=String
MeterStyle=String:S
X=r
Y=R
W=(#MediaW#-#P#*2)
FontSize=(10*#scale#)
ClipString=1
Text=[#PlayerType#Artist]
FontWeight=600
DynamicVariables=1
Group=Music | Standard
Container=MediaC
[MediaProgress]
Meter=String
MeterStyle=String:S
X=r
Y=R
W=(#MediaW#-#P#*2)
FontSize=(10*#scale#)
ClipString=1
Text=[#PlayerType#CurrentPosition] / [#PlayerType#Length]
FontColor=#FontColor2#
FontWeight=600
DynamicVariables=1
UpdateDivider=1
Group=Music | Standard
Container=MediaC

[MediaPlayPauseBackground]
Meter=Shape
X=([MediaPlayPause:X]+10*#Scale#-[MediaB:X])
Y=([MediaPlayPause:Y]+10*#Scale#)
DynamicVariables=1
Shape=Ellipse 0,0,25 | StrokeWidth 0 | Fill Color #AccentColor1#,50 | Scale #Scale#,#Scale#
Shape2=Ellipse 0,0,20 | StrokeWidth 0 | Fill LinearGradient This | Scale #Scale#,#Scale#
This=0 | #AccentColor1# ; 0.0 | #AccentColor2# ; 1.0
Group=Music | Standard
Container=MediaC


[Previous]
Meter=Image
ImageName=#@#Icons\Previous.png
X=(#MediaW#-#P#-140*#scale#)
Y=(#H#/2-10*#scale#)
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure state#NowPlayingMedia# "Previous"]
Group=Music | Standard
Container=MediaC


[MediaPlayPause]
Meter=Image
X=(40*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music | Standard
Container=MediaC
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption MediaPlayPause MeterStyle Pause][!UpdateMeter MediaPlayPause][!Redraw][!CommandMeasure state#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption MediaPlayPause MeterStyle Play][!UpdateMeter MediaPlayPause][!Redraw][!CommandMeasure state#NowPlayingMedia# "PlayPause"]

[Next]
Meter=Image
ImageName=#@#Icons\Next.png
X=(40*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure state#NowPlayingMedia# "Next"]
Group=Music | Standard
Container=MediaC

[ProgBar]
Meter=Shape
X=#P#
Y=(#H#-#P#)
Shape=Line 0,0,(#MediaW#-#P#*2),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color #FontColor#,50 | StrokeStartCap #Cap# | StrokeEndCap #Cap#
Shape2=Line 0,0,((#MediaW#-#P#*2)*[#PlayerType#Progress]/100),0 | StrokeWidth 4 | Fill Color 0,0,0,1 | Stroke LinearGradient This | StrokeStartCap #Cap# | StrokeEndCap #Cap#
This=0 | #AccentCOlor1# ; 0.0 | #AccentColor2# ; 1.0
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#MediaW#-#P#*2)*100)"][!UpdateMeasure PosCalc]
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