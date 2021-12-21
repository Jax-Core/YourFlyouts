#SingleInstance Force
#NoTrayIcon
SetTitleMatchMode, 2
DetectHiddenWindows, On
numberkeys := 0

; IniRead, OutputVar, Hotkeys.ini, Variables, Key
IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH
IniRead, Media, ..\Vars.inc, Variables, Media

if (Media = 1)
{
    Hotkey Media_Play_Pause, actionPause
    Hotkey Media_Next, actionNext
    Hotkey Media_Prev, actionPrev
    Return
}
Return
if (Media = 0)
{
    Hotkey Media_Play_Pause, rejectPause
    Hotkey Media_Next, rejectNext
    Hotkey Media_Prev, rejectPrev
    Return
}
Return

Volume_Up::Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('up')" "YourFlyouts\Main" "
Volume_Down::Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('down')" "YourFlyouts\Main" "

actionPause:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('pause')" "YourFlyouts\Main" "
Return

actionNext:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('next')" "YourFlyouts\Main" "
Return

actionPrev:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('prev')" "YourFlyouts\Main" "
Return

rejectPause:
    Send {Media_Play_Pause}
Return

rejectNext:
    Send {Media_Next}
Return

rejectPrev:
    Send {Media_Prev}
Return