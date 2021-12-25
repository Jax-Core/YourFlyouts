[Variables]
W=(#Width#*#scale#)
VolumeH=(50*#Scale#)
MediaH=(190*#Scale#)
LocksH=(50*#Scale#)
P=(15*#Scale#)

SliderM=[VolumeBar:X]
SliderW=((#Width#-120)*#scale#)

[Sec.BottomButton:S]
X=(#P#*2)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Grayscale=1
ImageTint=#FontColor#
DynamicVariables=1
Group=Music | Standard
Container=MediaC

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
Formula=((#SliderX#-(#SliderM#))*100/(((#SliderM#)+#SliderW#)-(#SliderM#)))
OnUpdateAction=[!CommandMeasure "mVolume" "SetVolume [#CURRENTSECTION#]"][!UpdateMeasure mVolume]
DynamicVariables=1
Disabled=1
Group=NUOL

[VolumeMouse]
Measure=Plugin
Plugin=Mouse
; this measure uses the Plugin:Mouse
LeftMouseDragAction=[!SetVariable SliderX "(Clamp(($MouseX$),(#SliderM#),((#SliderM#)+#SliderW#)))"][!UpdateMeasure SliderPercent]
; actions to be executed when the mouse drags. The first bang gets the mouse value and make sure it's in the slider. The bangs after that updates the required measures and the slider.
LeftMouseUpAction=[!SetVariable SliderX "(Clamp(($MouseX$),(#SliderM#),((#SliderM#)+#SliderW#)))"][!UpdateMeasure SliderPercent][!CommandMeasure VolumeMouse "Stop"]
; actions to be executed after the mouse click is lifted. The first bang stops the measure to retrieve information from mouse dragging.
RelativeToSkin=1
RequireDragging=1
DynamicVariables=1


; --------------------------------- VolumeBar -------------------------------- ;

[VolumeB]
Meter=Shape
X=1
Y=1
Shape=Rectangle 0,0,#W#,#VolumeH#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #SecondaryColor#,#SecondaryOpacity#
Group=Standard
[VolumeC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#W#,#VolumeH#,#R# | StrokeWidth 0
Group=Standard



[VolumeIcon]
Meter=String
MeterStyle=String:S
X=#P#
Y=(#VolumeH#/2)
FontFace=Segoe MDL2 Assets
StringAlign=LeftCenter
FontSize=(16*#scale#)
Group=Dynamic | Standard
Container=VolumeC
[VolumeBar]
Meter=Shape
X=#P#R
Y=(#VolumeH#/2)
Shape=Line 0,0,(#SliderW#),0 | StrokeWidth 2 | Stroke Color #FontColor#,150 | StrokeStartCap #cap# | StrokeEndCap #cap#
Shape2=Line 0,0,(#SliderW#*[mVolume:]/100),0 | StrokeWidth 2 | Stroke Color #AccentColor# | StrokeStartCap #cap# | StrokeEndCap #cap#
Shape3=Line 0,0,(#SliderW#),0 | StrokeWidth (20*#scale#) | Stroke Color 0,0,0,1
Shape4=Rectangle (#SliderW#*[mVolume:]/100-#DotSize#*#scale#/2),(-#DotSize#*#scale#/2),(#DotSize#*#scale#),(#DotSize#*#scale#),(#DotSize#*#scale#/2) | StrokeWidth 0 | Fill Color #AccentColor#
LeftMouseDownAction=[!CommandMeasure VolumeMouse "Start"]
DynamicVariables=1
Container=VolumeC
Group=Dynamic | Standard
[VolumeString]
Meter=String
MeterStyle=String:S
X=(#W#-30*#scale#)
Y=(#VolumeH#/2)
StringAlign=CenterCenter
Text=[mVolume:]
DynamicVariables=1
Group=Dynamic | Standard
Container=VolumeC

; ------------------------------ MediaPlayerBar ------------------------------ ;

[MediaB]
Meter=Shape
X=r
Y=(20*#Scale#)R
Shape=Rectangle 0,0,#W#,#MediaH#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #SecondaryColor#,#SecondaryOpacity#
Group=Music | Standard
[MediaC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#W#,#MediaH#,#R# | StrokeWidth 0
Group=Music | Standard


[MediaImageFade]
Meter=Image
W=(#W#)
H=(#MediaH#)
PreserveAspectRatio=2
MaskImageName=#@#Images\FadeMask.png
ImageName=[#PlayerType#Cover]
DynamicVariables=1
Group=Music | Standard | MediaImage
Container=MediaC

[MusicIcon]
Meter=String
MeterStyle=String:S
X=(#P#)
Y=(#P#)
Text=[\xe3a1]
FontFace=Material Icons Round
FontSize=(12*#Scale#)
Group=Music | Standard
Container=MediaC

[MediaName]
Meter=String
MeterStyle=String:S
X=(#P#*3)
Y=r
W=(#W#-(#MediaH#+2*#P#))
ClipString=1
Text=[#PlayerType#Player]
DynamicVariables=1
FontSize=(9*#Scale#)
Group=Music | Standard
Container=MediaC

[MediaTrack]
Meter=String
MeterStyle=String:S
X=(#P#)
Y=(#P#)R
W=(#W#-(#MediaH#+2*#P#))
ClipString=1
Text=[#PlayerType#Track]
DynamicVariables=1
FontSize=(12*#Scale#)
FontWeight=650
Group=Music | Standard
Container=MediaC

[MediaArtist]
Meter=String
MeterStyle=String:S
X=r
Y=(5*#Scale#)R
W=(#W#-(#MediaH#+2*#P#))
ClipString=1
Text=[#PlayerType#Artist]
DynamicVariables=1
Group=Music | Standard
Container=MediaC

[ProgBar]
Meter=Shape
X=#P#
Y=(110*#scale#)
Shape=Line 0,0,(#W#-#P#*2),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color #FontColor2# | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,((#W#-#P#*2)*[#PlayerType#Progress]/100),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color #AccentColor# | StrokeStartCap Round | StrokeEndCap Round
Shape3=Ellipse ((#W#-#P#*2)*[#PlayerType#Progress]/100),0,(#DotSize#/4),(#DotSize#/4) | strokeWidth 0 | Fill Color #AccentColor# | Scale #Scale#,#Scale#
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#W#-#P#*2)*100)"][!UpdateMeasure PosCalc]
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
[MediaCurrent]
Meter=String
MeterStyle=String:S
X=r
Y=R
FontColor=#FontColor2#
DynamicVariables=1
UpdateDivider=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#CurrentPosition
Group=Music | Standard
Container=MediaC
[MediaLength]
Meter=String
MeterStyle=String:S
X=(#W#-#P#*2)r
Y=r
FontColor=#FontColor2#
StringAlign=Right
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=#PlayerType#Length
Group=Music | Standard
Container=MediaC

[MediaHeart]
Meter=Image
X=(#W#/2-(20*5*#scale#+#P#*2*4)/2)
Y=(20*#scale#)R
MeterStyle=Sec.BottomButton:S
[FullHeart]
ImageName=#@#Icons\HeartFull.png
LeftMouseUpAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.BottomButton:S | EmptyHeart"][!UpdateMeter #CURRENTSECTION#][!Redraw][!CommandMeasure state#NowPlayingMedia# "ToggleThumbsDown"]
[EmptyHeart]
ImageName=#@#Icons\Heart.png
LeftMouseUpAction=[!SetOption #CURRENTSECTION# MeterStyle "Sec.BottomButton:S | Fullheart"][!UpdateMeter #CURRENTSECTION#][!Redraw][!CommandMeasure state#NowPlayingMedia# "ToggleThumbsUp"]

[MediaPrev]
Meter=Image
ImageName=#@#Icons\Previous.png
LeftMouseUpAction=[!CommandMeasure state#NowPlayingMedia# "Previous"]
MeterStyle=Sec.BottomButton:S

[MediaPlayPause]
Meter=Image
MeterStyle=Sec.BottomButton:S
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Pause"][!UpdateMeter MediaPlayPause][!Redraw][!CommandMeasure state#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Play"][!UpdateMeter MediaPlayPause][!Redraw][!CommandMeasure state#NowPlayingMedia# "PlayPause"]

[MediaNext]
Meter=Image
ImageName=#@#Icons\Next.png
LeftMouseUpAction=[!CommandMeasure state#NowPlayingMedia# "Next"]
MeterStyle=Sec.BottomButton:S

[MediaShuffle]
Meter=Image
ImageName=#@#Icons\Shuffle.png
MeterStyle=Sec.BottomButton:S
[Shuffle0]
ImageAlpha=150
LeftMouseUpAction=[!SetOption MediaShuffle MeterStyle "Sec.BottomButton:S | Shuffle1"][!UpdateMeter MediaShuffle][!Redraw][!CommandMeasure state#NowPlayingMedia# "Shuffle"]
[Shuffle1]
ImageAlpha=255
LeftMouseUpAction=[!SetOption MediaShuffle MeterStyle "Sec.BottomButton:S | Shuffle0"][!UpdateMeter MediaShuffle][!Redraw][!CommandMeasure state#NowPlayingMedia# "Shuffle"]


[MediaImage]
Meter=Image
X=(#W#-(80*#Scale#)-#P#)
Y=#P#
W=(80*#Scale#)
H=(80*#Scale#)
PreserveAspectRatio=2
MaskImageName=#@#Images\Mask.png
ImageName=[#PlayerType#Cover]
DynamicVariables=1
Group=Music | Standard | MediaImage
Container=MediaC

; ---------------------------------------------------------------------------- ;
;                                    Special                                   ;
; ---------------------------------------------------------------------------- ;

; ----------------------------------- Caps ----------------------------------- ;

[LocksB]
Meter=Shape
X=1
Y=1
Shape=Rectangle 0,0,#W#,#LocksH#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #SecondaryColor#,#SecondaryOpacity#
Group=Locks | Special
Hidden=1
[LocksC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#W#,#LocksH#,#R# | StrokeWidth 0
Group=Locks | Special
Hidden=1



[LocksIcon]
Meter=String
MeterStyle=String:S
X=#P#
Y=(26*#scale#)
Text=[\xe835]
FontFace=Material Icons Round
StringAlign=LeftCenter
FontSize=(16*#scale#)
Group=Locks | Special
Container=LocksC
Hidden=1
[LocksText]
Meter=String
MeterStyle=String:S
X=(#P#)R
Y=r
StringAlign=LeftCenter
Group=Locks | Special
Container=LocksC
Hidden=1