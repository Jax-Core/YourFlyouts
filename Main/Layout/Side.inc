[Variables]
H=(#Height#*#scale#)
VolumeW=(12*#Scale#)
MediaW=(100*#Scale#)
Locksw=(100*#Scale#)
P=(15*#Scale#)

SliderM=0
SliderW=(#H#)

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;


[mVolume]
Measure=Plugin
Plugin=Win7AudioPlugin
DynamicVariables=1
OnChangeAction=[!Setvariable SliderX ([mVolume:]/100*#SliderW#+#SliderM#)][!UpdateMeterGroup Dynamic][!Redraw]
IfCondition=mVolume < 20
IfTrueAction=[!SetOption VolumeIcon Text "[\xE992]"]
IfCondition2=(mVolume >= 20) && (mVolume < 50)
IfTrueAction2=[!SetOption VolumeIcon Text "[\xE993]"]
IfCondition3=(mVolume >= 50) && (mVolume < 90)
IfTrueAction3=[!SetOption VolumeIcon Text "[\xE994]"]
IfCondition4=(mVolume >= 90)
IfTrueAction4=[!SetOption VolumeIcon Text "[\xE995]"]
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
X=(1+20*#Scale#+#MediaW#)
Y=1
Shape=Rectangle 0,0,#VolumeW#,#H#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity#
Group=Standard
[VolumeC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#VolumeW#,#H#,#R# | StrokeWidth 0
Group=Standard



[VolumeBar]
Meter=Shape
Shape=Rectangle 0,#H#,(#VolumeW#),(-#H#*[mVolume:]/100) | StrokeWidth 0 | Fill Color #AccentColor#
LeftMouseDownAction=[!CommandMeasure VolumeMouse "Start"]
DynamicVariables=1
Container=VolumeC
Group=Dynamic | Standard

; ------------------------------ MediaPlayerBar ------------------------------ ;

[MediaB]
Meter=Shape
X=1
Y=(#H#/2-#MediaW#/2)
Shape=Rectangle 0,0,#MediaW#,#MediaW#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity#
Group=Music | Standard
[MediaC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#MediaW#,#MediaW#,#R# | StrokeWidth 0
Group=Music | Standard



[MediaBar]
Meter=Shape
Shape=Rectangle 0,0,(#MediaW#*[#PlayerType#Progress]/100),(#MediaW#) | StrokeWidth 0 | Fill Color #AccentColor#
DynamicVariables=1
Group=Music | Standard
Container=MediaC

[MediaImage]
Meter=Image
X=#P#
Y=#P#
W=(#MediaW#-2*#P#)
H=(#MediaW#-2*#P#)
PreserveAspectRatio=2
MaskImageName=#@#Images\Mask.png
ImageName=[#PlayerType#Cover]
DynamicVariables=1
Group=Music | Standard | MediaImage
Container=MediaC

[MediaHeartUnderlay]
Meter=Image
X=(#MediaW#/2-32/2*#scale#)
Y=(#MediaW#/2-32/2*#scale#)
W=(32*#scale#)
H=(32*#scale#)
ImageName=#@#Icons\HeartFull.png
Grayscale=1
Imagealpha=150
ImageTint=0,0,0
DynamicVariables=1
Group=Music | Standard
Container=MediaC
[MediaHeart]
Meter=Image
X=r
Y=r
W=(32*#scale#)
H=(32*#scale#)
Grayscale=1
ImageTint=#AccentColor#
DynamicVariables=1
Group=Music | Standard
Container=MediaC
[FullHeart]
ImageName=#@#Icons\HeartFull.png
LeftMouseUpAction=[!SetOption #CURRENTSECTION# MeterStyle EmptyHeart][!UpdateMeter #CURRENTSECTION#][!Redraw][!CommandMeasure state#NowPlayingMedia# "ToggleThumbsDown"]
[EmptyHeart]
ImageName=#@#Icons\Heart.png
LeftMouseUpAction=[!SetOption #CURRENTSECTION# MeterStyle Fullheart][!UpdateMeter #CURRENTSECTION#][!Redraw][!CommandMeasure state#NowPlayingMedia# "ToggleThumbsUp"]

; ; ---------------------------------------------------------------------------- ;
; ;                                    Special                                   ;
; ; ---------------------------------------------------------------------------- ;

; ; ----------------------------------- Caps ----------------------------------- ;

[LocksB]
Meter=Shape
X=(1+20*#Scale#+#VolumeW#)
Shape=Rectangle 0,0,#Locksw#,#Locksw#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity#
Group=Locks | Special
Hidden=1
[LocksC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#Locksw#,#Locksw#,#R# | StrokeWidth 0
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