[Variables]
H=(#Height#*#scale#)
VolumeW=(80*#Scale#)
MediaW=(500*#Scale#)
LocksW=(250*#Scale#)
LocksH=(50*#Scale#)
P=(20*#Scale#)

MHC_Reset=[!SetOption MediaHoverCircle Stroke "Stroke Color #FontColor#,20"][!UpdateMeter MediaHoverCircle][!Redraw]

SliderRotation=v
SliderEndAction=[!SetOption VolumeBar MeterStyle "VolumeBar:0"][!UpdateMeter Volumebar][!Redraw]

[SliderStart]
Formula=(#P#+8*#scale#)
[SliderEnd]
Formula=(#H#-#P#*2-(30+8*2)*#Scale#)

; ---------------------------------------------------------------------------- ;
;                                  MeterStyle                                  ;
; ---------------------------------------------------------------------------- ;

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
OnUpdateAction=[!SetOption VolumeString Text """[&Func:volumeLevel()]"""][!SetOption VolumeString FontFace "#FontFace#"]

[mBrightness]
IfCondition=(mBrightness = 0) && (#ShowBrightnessVal# = 0)
IfTrueAction=[!SetOption VolumeString Text "[\xEC8A]"][!SetOption VolumeString FontFace "Segoe MDL2 Assets"]
IfCondition2=(mBrightness > 0) && (#ShowBrightnessVal# = 0)
IfTrueAction2=[!SetOption VolumeString Text "[\xE706]"][!SetOption VolumeString FontFace "Segoe MDL2 Assets"]
IfCondition3=(#ShowBrightnessVal# = 1)
IfTrueAction3=[!SetOption VolumeString Text "[mBrightness:]%"][!SetOption VolumeString FontFace "#fontFace#"]
IfConditionMode=1

[FrostedGlass]
Measure=Plugin
Plugin=FrostedGlass
Type=#Blur#
Corner=#BlurCorner#
Border=All

[SysColor]
Measure=Plugin
Plugin=SysColor
ColorType=Aero
OnUpdateAction=[!SetVariable AccentColor "[SysColor]"]
DynamicVariables=1
DisplayType=RGB
Disabled=(1-#SysAccent#)

; --------------------------------- VolumeBar -------------------------------- ;

[StrokeB]
Meter=Shape
X=#Border#
Y=#Border#
Shape=Rectangle 0,0,(#VolumeW#+#MediaW#*#MusicVisible#),(#H#),#StaticWin11Corner# | Stroke Color #FontColor#,50 | StrokeWidth (#Border#*#Scale#) | Fill Color 0,0,0,0
DynamicVariables=1
Group=Standard | Music
Hidden=(1-#Border#)

[VolumeB]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#VolumeW#,#H#,#StaticWin11Corner# | StrokeWidth 0 | Fill Color #PrimaryColor#,#PrimaryOpacity#
Group=Standard
DynamicVariables=1
MouseScrollUpAction=[!CommandMeasure "mVolume" "ChangeVolume 2"][!UpdateMeasure mVolume]
MouseScrollDownAction=[!CommandMeasure "mVolume" "ChangeVolume -2"][!UpdateMeasure mVolume]
[VolumeC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#VolumeW#,#H#,#StaticWin11Corner# | StrokeWidth 0
Group=Standard
DynamicVariables=1

[VolumeBar]
Meter=Shape
X=(#VolumeW#/2)
Y=([SliderStart])
Shape=Line 0,[SliderEnd],0,0 | StrokeWidth (4*#scale#) | Fill Color 0,0,0,1 | Stroke Color #FontColor#,50 | StrokeStartCap #Cap# | StrokeEndCap #Cap# | Extend Backstroke
Shape2=Line 0,[SliderEnd],0,([SliderEnd]*(1-[#CurrentSlider#:]/100)) | StrokeWidth (4*#Scale#) | Fill Color 0,0,0,1 | StrokeStartCap #Cap# | StrokeEndCap #Cap# | Extend Stroke
Shape3=Ellipse 0,([SliderEnd]*(1-[#CurrentSlider#:]/100)),(8*#scale#) | StrokeWidth 0 | Fill Color #FontColor#
Shape4=Line 0,[SliderEnd],0,0 | StrokeWidth (20*#Scale#) | Fill Color 0,0,0,1 | Stroke Color 0,0,0,1
LeftMouseDownAction=[!SetOption VolumeBar MeterStyle "VolumeBar:1"][!UpdateMeter Volumebar][!Redraw][!CommandMeasure VolumeMouse "Start"]
DynamicVariables=1
Group=Dynamic | Standard
Container=VolumeC
MeterStyle=Volumebar:0
[VolumeBar:0]
BackStroke=Stroke Color #FontColor#,50
Stroke=Stroke Color #AccentColor#
[VolumeBar:1]
BackStroke=Stroke Color #FontColor2#,25
Stroke=Stroke Color #AccentColor#,100

[VolumeString]
Meter=String
MeterStyle=String:S
X=(#VolumeW#/2)
Y=(#H#-#P#)
StringAlign=CenterBottom
FontSize=(10*#scale#)
Text=[&Func:volumeLevel()]
FontColor=#FontColor2#
DynamicVariables=1
Group=Dynamic | Standard
Container=VolumeC

; --------------------------------- Media -------------------------------- ;

[MediaB]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,(#MediaW#+#VolumeW#),#H#,#StaticWin11Corner# | StrokeWidth 0 | Fill Color #PrimaryColor#,#PrimaryOpacity#
Shape2=Rectangle 0,0,#VolumeW#,#H#,(#StaticWin11Corner#+1) | StrokeWidth 0
Shape3=Combine Shape | XOR Shape2
Shape4=Line #VolumeW#,(#P#),#VolumeW#,(#P#+(#H#-#P#*2)*#TweenNode1#) | StrokeStartCap Round | StrokeEndCap ROund | StrokeWidth (1*#Scale#) | Stroke Color #FontColor#,50
DynamicVariables=1
Group=Music | Standard | Animated
[MediaC]
Meter=Shape
X=(#VolumeW#)
Y=r
DynamicVariables=1
Shape=Rectangle 0,0,(#MediaW#*#TweenNode1#+1),#H#,#StaticWin11Corner# | StrokeWidth 0 | Fill Color 255,255,255,(255*#TweenNode1#)
Group=Music | Standard | Animated

[MediaImage]
Meter=Image
X=(#MediaW#-#H#*1.5+#VolumeW#)
Y=0
W=(#H#*1.5)
H=(#H#)
PreserveAspectRatio=2
MaskImageName=#@#Images\FadeMask.png
ImageName=[#PlayerType#Cover]
DynamicVariables=1
Group=Music | Standard | MediaImage
Container=MediaC

[MediaImageTopLeft]
Meter=Image
X=(#P#)
Y=(#P#)
W=(64*#Scale#)
H=(64*#Scale#)
PreserveAspectRatio=2
ImageName=[#PlayerType#Cover]
MaskImageName=#@#Images\SquareRoundedMask.png
DynamicVariables=1
Group=Music | Standard | MediaImage
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
X=#Border#
Y=#Border#
Shape=Rectangle 0,0,#LocksW#,#LocksH#,#StaticWin11Corner# | StrokeWidth (#Border#*#Scale#) | Fill Color #PrimaryColor#,#PrimaryOpacity# | Stroke Color #FontColor#,50 
Group=Locks | Special
Hidden=1
[LocksC]
Meter=Shape
X=r
Y=r
Shape=Rectangle 0,0,#LocksW#,#LocksH#,#StaticWin11Corner# | StrokeWidth 0
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
[FlightIcon.On:S]
Text=[\xe709]
[FlightIcon.Off:S]
Text=[\xe709]



[MediaHeart]
Meter=String
Hidden=1

