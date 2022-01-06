#SingleInstance Force
#NoTrayIcon
SetTitleMatchMode, 2
DetectHiddenWindows, On
numberkeys := 0

IniRead, OutputVar, Hotkeys.ini, Variables, Key
IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH
IniRead, Media, ..\Vars.inc, Variables, Media
IniRead, OverrideNativeKeyFunction, ..\Vars.inc, Variables, OverrideNativeKeyFunction
IniRead, MediaKeys, ..\Vars.inc, Variables, MediaKeys
IniRead, OptionalKey, ..\Vars.inc, Variables, OptionalKey
IniRead, SmartVolume, ..\Vars.inc, Variables, SmartVolume

if (Media = 1) and (MediaKeys = 1)
{
    if (OverrideNativeKeyFunction = 1)
    {
        Hotkey Media_Play_Pause, actionPause
        Hotkey Media_Next, actionNext
        Hotkey Media_Prev, actionPrev
    }
    else
    {
        Hotkey ~Media_Play_Pause, actionPause
        Hotkey ~Media_Next, actionNext
        Hotkey ~Media_Prev, actionPrev
    }
}
if (OptionalKey = 1)
{
    Hotkey,%OutputVar%,Button
}
if (SmartVolume = 1)
{
    Hotkey +Volume_Up, MediaUp
    Hotkey +Volume_Down, MediaDown
}
Return

Volume_Up::Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('up')" "YourFlyouts\Main" "
Volume_Down::Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('down')" "YourFlyouts\Main" "

Button:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad()" "YourFlyouts\Main" "
Return

actionPause:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('pause')" "YourFlyouts\Main" "
Return

actionNext:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('next')" "YourFlyouts\Main" "
Return

actionPrev:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('prev')" "YourFlyouts\Main" "
Return

MediaUp:
    Run "%RainmeterPath% "!CommandMeasure "Func" "mediaVol('up')" "YourFlyouts\Main" "
Return

MediaDown:
    Run "%RainmeterPath% "!CommandMeasure "Func" "mediaVol('down')" "YourFlyouts\Main" "
Return
