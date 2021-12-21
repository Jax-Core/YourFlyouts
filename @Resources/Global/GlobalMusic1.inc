; ---------------------------------------------------------------------------- ;
;                                      Gru                                     ;
; ---------------------------------------------------------------------------- ;

[stateAIMP]
Measure=NowPlaying
PlayerName=AIMP
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMedia()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateCAD]
Measure=NowPlaying
PlayerName=CAD
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMedia()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWMP]
Measure=NowPlaying
PlayerName=WMP
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMedia()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateiTunes]
Measure=NowPlaying
PlayerName=iTunes
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMedia()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWinamp]
Measure=NowPlaying
PlayerName=Winamp
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMedia()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWebNowPlaying]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMedia()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

; ---------------------------------------------------------------------------- ;
;                                    Minions                                   ;
; ---------------------------------------------------------------------------- ;

; ------------------------------------ NP ------------------------------------ ;

[npPlayer]
Measure=String
String=#NowPlayingMedia#
UpdateDivider=-1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npCover]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Cover
Substitute="":"#@#Images\Default.png"
OnChangeAction=[!SetOption MainC Path "[#CURRENTSECTION#]"][!UpdateMeter MusicImg][!Redraw]
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npArtist]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Artist
Substitute="":"Fetching..."
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npTrack]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Title
Substitute="":"Fetching..."
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npProgress]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npCurrentPosition]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Position
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npLength]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Duration
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npShuffle]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Shuffle
IfCondition=npShuffle = 0
IfTrueAction=[!SetOption MediaShuffle MeterStyle "Sec.BottomButton:S | Shuffle0"][!UpdateMeter MediaShuffle][!Redraw]
IfFalseAction=[!SetOption MediaShuffle MeterStyle "Sec.BottomButton:S | Shuffle1"][!UpdateMeter MediaShuffle][!Redraw]
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npHeart]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Rating
IfCondition=npHeart = 0
IfTrueAction=[!SetOption MediaHeart MeterStyle "Sec.BottomButton:S | EmptyHeart"][!UpdateMeter MediaHeart][!Redraw]
IfFalseAction=[!SetOption MediaHeart MeterStyle "Sec.BottomButton:S | FullHeart"][!UpdateMeter MediaHeart][!Redraw]
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

; ------------------------------------ WNP ----------------------------------- ;

[wnpPlayer]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Player
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
DefaultPath=#@#Images\Default.png
CoverPath=#@#Images\Cover.png
OnChangeAction=[!SetOption MainC Path "[#CURRENTSECTION#]"][!UpdateMeter MusicImg][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpArtist]
Measure=Plugin
Plugin=WebNowPlaying
OnchangeAction=[!UpdateMeasureGroup Music][!UpdateMeterGroup Music][!Redraw]
PlayerType=Artist
Substitute="":"Fetching..."
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
Substitute="":"Fetching..."
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpCurrentPosition]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Position
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpLength]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Duration
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpShuffle]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Shuffle
IfCondition=wnpShuffle = 0
IfTrueAction=[!SetOption MediaShuffle MeterStyle "Sec.BottomButton:S | Shuffle0"][!UpdateMeter MediaShuffle][!Redraw]
IfFalseAction=[!SetOption MediaShuffle MeterStyle "Sec.BottomButton:S | Shuffle1"][!UpdateMeter MediaShuffle][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpHeart]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Rating
IfCondition=wnpHeart = 0
IfTrueAction=[!SetOption MediaHeart MeterStyle "Sec.BottomButton:S | EmptyHeart"][!UpdateMeter MediaHeart][!Redraw]
IfFalseAction=[!SetOption MediaHeart MeterStyle "Sec.BottomButton:S | FullHeart"][!UpdateMeter MediaHeart][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1