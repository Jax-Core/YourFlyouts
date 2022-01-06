[Variables]
H=(#Height#*#scale#)
VolumeW=(50*#Scale#)
MediaW=(470*#Scale#)
LocksW=(#H#)
P=(20*#Scale#)

SliderM=#P#
SliderW=(#H#-#P#-40*#Scale#)

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

[SliderPercent]
Measure=Calc
Formula=(100-(#SliderX#-(#SliderM#))*100/(((#SliderM#)+#SliderW#)-(#SliderM#)))
OnUpdateAction=[!CommandMeasure "mVolume" "SetVolume [#CURRENTSECTION#]"][!UpdateMeasure mVolume]
DynamicVariables=1
Disabled=1
Group=NUOL

[VolumeMouse]
Measure=Plugin
Plugin=Mouse
LeftMouseDragAction=[!SetVariable SliderX "(Clamp(($MouseY$),(#SliderM#),((#SliderM#)+#SliderW#)))"][!UpdateMeasure SliderPercent]
; actions to be executed when the mouse drags. The first bang gets the mouse value and make sure it's in the slider. The bangs after that updates the required measures and the slider.
LeftMouseUpAction=[!SetVariable SliderX "(Clamp(($MouseY$),(#SliderM#),((#SliderM#)+#SliderW#)))"][!UpdateMeasure SliderPercent][!CommandMeasure VolumeMouse "Stop"]
; actions to be executed after the mouse click is lifted. The first bang stops the measure to retrieve information from mouse dragging.
RelativeToSkin=1
RequireDragging=1
DynamicVariables=1


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

[VolumeBar]
Meter=Shape
X=(#VolumeW#/2)
Y=(#SliderM#)
Shape=Line 0,#SliderW#,0,0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color #FontColor#,50 | StrokeStartCap #Cap# | StrokeEndCap #Cap#
Shape2=Line 0,#SliderW#,0,(#SliderW#*(1-[mVolume:]/100)) | StrokeWidth 4 ==| Fill Color 0,0,0,1 | Stroke LinearGradient This | StrokeStartCap #Cap# | StrokeEndCap #Cap#
This=270 | #AccentCOlor1# ; 0.0 | #AccentColor2# ; 1.0
LeftMouseDownAction=[!CommandMeasure VolumeMouse "Start"]
DynamicVariables=1
Group=Dynamic | Standard
Container=VolumeC

[VolumeString]
Meter=String
MeterStyle=String:S
X=(#VolumeW#/2)
Y=(#H#-#P#/2)
StringAlign=CenterBottom
FontWeight=650
FontSize=(10*#scale#)
Text=[mVolume:]
DynamicVariables=1
Group=Dynamic | Standard
Container=VolumeC
FontFace=#FontFace#

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

[MediaHeart]
Meter=String
[MediaShuffle]
Meter=String

; ---------------------------------------------------------------------------- ;
;                                    Special                                   ;
; ---------------------------------------------------------------------------- ;

; ----------------------------------- Caps ----------------------------------- ;

[LocksB]
Meter=Shape
X=1
Y=1
Shape=Rectangle 0,0,#LocksW#,#H#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #SecondaryColor#,#SecondaryOpacity#
Group=Locks | Special
Hidden=1
[LocksC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#LocksW#,#H#,#R# | StrokeWidth 0
Group=Locks | Special
Hidden=1



[LocksIcon]
Meter=String
MeterStyle=String:S
X=(#Locksw#/2)
Y=(#Locksw#/2)
Text=[\xe835]
FontFace=Material Icons Round
StringAlign=CenterCenter
FontSize=(32*#scale#)
Group=Locks | Special
InlineSetting=Shadow | 0 | 0 | 10 | 0,0,0,150
Container=LocksC
Hidden=1
[LocksText]
Meter=String
MeterStyle=String:S
X=r
Y=(#P#*2)r
W=(#LocksW#)
StringAlign=Center
ClipString=2
FontSize=(8*#scale#)
Fontcolor=#FontColor2#
Group=Locks | Special
Container=LocksC
Hidden=1