[Variables]
H=(#Height#*#scale#)
VolumeW=(80*#Scale#)
MediaW=(500*#Scale#)
LocksW=(250*#Scale#)
LocksH=(50*#Scale#)
P=(20*#Scale#)

SliderM=(#P#+8*#scale#)
SliderW=(#H#-#P#*2-(30+8*2)*#Scale#)

MHC_Reset=[!SetOption MediaHoverCircle Stroke "Stroke Color #FontColor#,20"][!UpdateMeter MediaHoverCircle][!Redraw]

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
MouseOverAction=[!SetOption MediaHoverCircle X "([#CURRENTSECTION#:X]-#VolumeW#)"][!SetOption MediaHoverCircle Y "([#CURRENTSECTION#:Y])"][!ShowMeter MediaHoverCircle][!UpdateMeter MediaHoverCircle][!Redraw]
MouseLeaveAction=[!HideMeter MediaHoverCircle][!Redraw]
LeftMouseDownAction=[!SetOption MediaHoverCircle Stroke "Stroke Color #FontColor#,150"][!UpdateMeter MediaHoverCircle][!Redraw]

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;


[mVolume]
Measure=Plugin
Plugin=Win7AudioPlugin
DynamicVariables=1
OnChangeAction=[!UpdateMeterGroup Dynamic][!Redraw]
UpdateDivider=1

[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=#Blur#
Corner=#BlurCorner#
Border=None

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
LeftMouseUpAction=[!SetVariable SliderX "(Clamp(($MouseY$),(#SliderM#),((#SliderM#)+#SliderW#)))"][!UpdateMeasure SliderPercent][!CommandMeasure VolumeMouse "Stop"][!SetOption VolumeBar BackStroke "Stroke Color #FontColor#,50"][!SetOption VolumeBar Stroke "Stroke Color #AccentColor#"][!UpdateMeter VolumeBar][!Redraw]
; actions to be executed after the mouse click is lifted. The first bang stops the measure to retrieve information from mouse dragging.
RelativeToSkin=1
RequireDragging=1
DynamicVariables=1

[SysColor]
Measure=Plugin
Plugin=SysColor
ColorType=Aero
OnUpdateAction=[!SetVariable AccentColor "[SysColor]"]
DynamicVariables=1
DisplayType=RGB
Disabled=(1-#SysAccent#)

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
Shape=Line 0,#SliderW#,0,0 | StrokeWidth (4*#scale#) | Fill Color 0,0,0,1 | Stroke Color #FontColor#,50 | StrokeStartCap #Cap# | StrokeEndCap #Cap# | Extend Backstroke
Shape2=Line 0,#SliderW#,0,(#SliderW#*(1-[mVolume:]/100)) | StrokeWidth (4*#Scale#) | Fill Color 0,0,0,1 | StrokeStartCap #Cap# | StrokeEndCap #Cap# | Extend Stroke
Shape3=Ellipse 0,(#SliderW#*(1-[mVolume:]/100)),(8*#scale#) | StrokeWidth 0 | Fill Color #FontColor#
Shape4=Line 0,#SliderW#,0,0 | StrokeWidth (20*#Scale#) | Fill Color 0,0,0,1 | Stroke Color 0,0,0,1
Stroke=Stroke Color #AccentColor#
BackStroke=Stroke Color #FontColor#,50
LeftMouseDownAction=[!SetOption #CURRENTSECTION# BackStroke "Stroke Color #FontColor#,25"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #AccentColor#,100"][!UpdateMeter #CURRENTSECTION#][!Redraw][!CommandMeasure VolumeMouse "Start"]
DynamicVariables=1
Group=Dynamic | Standard
Container=VolumeC

[VolumeString]
Meter=String
MeterStyle=String:S
X=(#VolumeW#/2)
Y=(#H#-#P#)
StringAlign=CenterBottom
FontSize=(10*#scale#)
Text=[mVolume:]
FontColor=#FontColor2#
DynamicVariables=1
Group=Dynamic | Standard
Container=VolumeC

; --------------------------------- Media -------------------------------- ;

[MediaB]
Meter=Shape
X=1
Y=r
Shape=Rectangle 0,0,(#MediaW#+#VolumeW#),#H#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity#
Shape2=Rectangle 0,0,#VolumeW#,#H#,(#R#+1) | StrokeWidth #Stroke#
Shape3=Combine Shape | XOR Shape2
Shape4=Line #VolumeW#,(#P#),#VolumeW#,(#P#+(#H#-#P#*2)*#TweenNode1#) | StrokeStartCap Round | StrokeEndCap ROund | StrokeWidth (1*#Scale#) | Stroke Color #FontColor#,50
DynamicVariables=1
Group=Music | Standard | Animated
[MediaC]
Meter=Shape
X=(#VolumeW#)
Y=r
DynamicVariables=1
Shape=Rectangle 0,0,(#MediaW#*#TweenNode1#),#H#,#R# | StrokeWidth 0 | Fill Color 255,255,255,(255*#TweenNode1#)
Group=Music | Standard | Animated

[MediaImage]
Meter=Image
X=(#MediaW#-#H#*1.5+#P#)
Y=0
W=(#H#*1.5)
H=(#H#)
PreserveAspectRatio=2
MaskImageName=#@#Images\FadeMask.png
ImageName=[#PlayerType#Cover]
DynamicVariables=1
Group=Music | Standard | MediaImage
Container=MediaC

[MediaPlayerImage]
Meter=Image
X=(8*#Scale#+#P#)
Y=(#P#+8*#Scale#)
W=(48*#Scale#)
H=(48*#Scale#)
PreserveAspectRatio=2
ImageName=#@#Icons\Players\[#PlayerType#Player].png
DynamicVariables=1
Group=Music | Standard
Container=MediaC

[MediaTrack]
Meter=String
MeterStyle=String:S
X=#P#R
Y=(#P#)
W=(#MediaW#-#P#*3-64*#Scale#)
FontSize=(18*#scale#)
ClipString=1
FontWeight=650
Text=[#PlayerType#Track]
DynamicVariables=1
Group=Music | Standard
Container=MediaC
[MediaArtist]
Meter=String
MeterStyle=String:S
X=r
Y=R
W=(#MediaW#-#P#*3-64*#Scale#)
FontSize=(12*#scale#)
ClipString=1
Text=[#PlayerType#Artist]
DynamicVariables=1
Group=Music | Standard
Container=MediaC

; ---------------------------------- Buttons --------------------------------- ;

[MediaShuffle]
Meter=Image
X=((#MediaW#)/2-(20*5*#scale#+#P#*2*4)/2)
Y=(#H#-#P#*4)
ImageName=#@#Icons\FluentShuffle.png
MeterStyle=Sec.BottomButton:S
[Shuffle0]
ImageAlpha=150
LeftMouseUpAction=[!SetOption MediaShuffle MeterStyle "Sec.BottomButton:S | Shuffle1"][!UpdateMeter MediaShuffle]#MHC_Reset#[!CommandMeasure state#NowPlayingMedia# "Shuffle"]
[Shuffle1]
ImageAlpha=255
LeftMouseUpAction=[!SetOption MediaShuffle MeterStyle "Sec.BottomButton:S | Shuffle0"][!UpdateMeter MediaShuffle]#MHC_Reset#[!CommandMeasure state#NowPlayingMedia# "Shuffle"]


[MediaPrev]
Meter=Image
ImageName=#@#Icons\FluentPrevious.png
LeftMouseUpAction=[!CommandMeasure state#NowPlayingMedia# "Previous"]#MHC_Reset#
MeterStyle=Sec.BottomButton:S

[MediaPlayPause]
Meter=Image
MeterStyle=Sec.BottomButton:S
[Play]
ImageName=#@#Icons\FluentPlay.png
LeftMouseUpAction=[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Pause"][!UpdateMeter MediaPlayPause]#MHC_Reset#[!CommandMeasure state#NowPlayingMedia# "PlayPause"]
[Pause]
ImageName=#@#Icons\FluentPause.png
LeftMouseUpAction=[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Play"][!UpdateMeter MediaPlayPause]#MHC_Reset#[!CommandMeasure state#NowPlayingMedia# "PlayPause"]

[MediaNext]
Meter=Image
ImageName=#@#Icons\FluentNext.png
LeftMouseUpAction=[!CommandMeasure state#NowPlayingMedia# "Next"]#MHC_Reset#
MeterStyle=Sec.BottomButton:S

[MediaRepeat]
Meter=Image
MeterStyle=Sec.BottomButton:S
LeftMouseUpAction=[!CommandMeasure state#NowPlayingMedia# "Repeat"]#MHC_Reset#
[Repeat0]
ImageAlpha=150
ImageName=#@#Icons\FluentRepeat.png
[Repeat1]
ImageName=#@#Icons\FluentRepeat.png
[Repeat2]
ImageName=#@#Icons\FluentRepeat2.png

[MediaHoverCircle]
Meter=Shape
Shape=Ellipse (10*#scale#),(10*#scale#),(20*#Scale#) | StrokeWidth 1 | Fill Color 0,0,0,0 | Extend Stroke
Stroke=Stroke Color #FontColor#,20
Container=MediaC
Hidden=1

; ------------------------------------ Bar ----------------------------------- ;

[MediaCurrent]
Meter=String
MeterStyle=String:S
X=(35*#Scale#+#P#)
Y=(#H#-#P#*1.5)
FontWeight=600
FontColor=#FontColor2#
DynamicVariables=1
UpdateDivider=1
StringAlign=RightCenter
MeasureName=#PlayerType#CurrentPosition
Group=Music | Standard
Container=MediaC

[ProgBar]
Meter=Shape
X=(#P#)r
Y=r
Shape=Line 0,0,(#MediaW#-#P#*4-70*#Scale#),0 | StrokeWidth (4*#Scale#) | Fill Color 0,0,0,1 | StrokeStartCap #Cap# | StrokeEndCap #Cap# | Extend BackStroke
Shape2=Line 0,0,((#MediaW#-#P#*4-70*#Scale#)*[#PlayerType#Progress]/100),0 | StrokeWidth (4*#Scale#) | Fill Color 0,0,0,1 | StrokeStartCap #Cap# | StrokeEndCap #Cap# | Extend Stroke
Shape3=Ellipse ((#MediaW#-#P#*4-70*#Scale#)*[#PlayerType#Progress]/100),0,(8*#scale#) | StrokeWidth 0 | Fill Color #FontColor#
Shape4=Line 0,0,(#MediaW#-#P#*4-70*#Scale#),0 | StrokeWidth (20*#Scale#) | Fill Color 0,0,0,1 | Stroke Color 0,0,0,1
Stroke=Stroke Color #AccentColor#
BackStroke=Stroke Color #FontColor#,50
LeftMouseDownAction=[!SetOption #CURRENTSECTION# BackStroke "Stroke Color #FontColor#,25"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #AccentColor#,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#MediaW#-#P#*4-70*#Scale#)*100)"][!UpdateMeasure PosCalc][!SetOption #CURRENTSECTION# BackStroke "Stroke Color #FontColor#,50"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #AccentColor#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
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

[MediaLength]
Meter=String
MeterStyle=String:S
X=(#MediaW#-#P#-35*#Scale#)
Y=r
FontColor=#FontColor2#
FontWeight=600
DynamicVariables=1
StringAlign=LeftCenter
MeasureName=#PlayerType#Length
Group=Music | Standard
Container=MediaC

; ---------------------------------------------------------------------------- ;
;                                    Special                                   ;
; ---------------------------------------------------------------------------- ;

; ----------------------------------- Caps ----------------------------------- ;

[LocksB]
Meter=Shape
X=1
Y=1
Shape=Rectangle 0,0,#LocksW#,#LocksH#,#R# | StrokeWidth #Stroke# | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #SecondaryColor#,#SecondaryOpacity#
Group=Locks | Special
Hidden=1
[LocksC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#LocksW#,#LocksH#,#R# | StrokeWidth 0
Group=Locks | Special
Hidden=1

[LocksIcon]
Meter=String
MeterStyle=String:S
X=#P#
Y=(26*#scale#)
FontFace=Segoe Fluent Icons 
StringAlign=LeftCenter
FontSize=(12*#scale#)
Group=Locks | Special
Container=LocksC
Hidden=1
[LocksText]
Meter=String
MeterStyle=String:S
X=(#P#)R
Y=(-2*#scale#)r
StringAlign=LeftCenter
Group=Locks | Special
Container=LocksC
Hidden=1

[LocksIcon.On:S]
Text=[\xe73a]
[LocksIcon.Off:S]
Text=[\xe739]



[MediaHeart]
Meter=String
Hidden=1

