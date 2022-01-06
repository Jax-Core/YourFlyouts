mediaPlayers = {'AIMP', 'CAD', 'WMP', 'iTunes', 'Winamp', 'WebNowPlaying'}

function Initialize()
    -- SKIN:Bang('!Hide')
    local pos = SKIN:GetVariable('Position')
    if pos == 'Custom' then
        SKIN:Bang('!Draggable', '1')
    else
        SKIN:Bang('!Draggable', '0')
        local posX = string.sub(pos, 2, 2)
        local posY = string.sub(pos, 1, 1)
        local pad = SKIN:GetVariable('ScreenPadding')
        local MonitorIndex = SKIN:GetVariable('MonitorIndex')
        local sax =SKIN:GetVariable('SCREENAREAX@'..MonitorIndex)
        local say = SKIN:GetVariable('SCREENAREAY@'..MonitorIndex)
        local saw = SKIN:GetVariable('SCREENAREAWIDTH@'..MonitorIndex)
        local sah = SKIN:GetVariable('SCREENAREAHEIGHT@'..MonitorIndex)
        moveX = 0
        moveY = 0
        anchorX = 0
        anchorY = 0
        
        if posX == 'L' then moveX = pad
        elseif posX == 'C' then
            moveX = (sax + saw/2)
            anchorX = "50%"
        elseif posX == 'R' then
            moveX = (sax + saw-pad)
            anchorX = "100%"
        end
        
        if posY == 'T' then moveY = pad
        elseif posY == 'C' then
            moveY = (say + sah/2)
            anchorY = "50%"
        elseif posY == 'B' then
            moveY = (say + sah-pad)
            anchorY = "100%"
        end

        SKIN:Bang('!SetWindowPosition '..moveX..' '..moveY..' '..anchorX..' '..anchorY)
        -- SKIN:Bang('[!SetVariable SkinX '..moveX..'][!SetVariable SkinY '..moveY..'][!SetVariable SkinAX '..anchorX..'][!SetVariable SkinAY '..anchorY..'][!UpdateMeasure ActionTimer]')
    end

    -- --------------------------- handle media toggle -------------------------- --

    if tonumber(SKIN:GetVariable('Media')) == 1 then
        SKIN:Bang('[!Delay 50][!CommandMeasure Func "checkMedia()"]')
        if tonumber(SKIN:GetVariable('FetchImage')) == 0 then
            SKIN:Bang('[!SetOptionGroup MediaImage UpdateDivider -1][!HideMeterGroup MediaImage][!SetOptionGroup MediaImage Group ""][!UpdateMeterGroup MediaImage]')
        end
    else
        SKIN:Bang('[!SetOptionGroup Music UpdateDivider -1][!HideMeterGroup Music][!SetOptionGroup Music Group ""][!UpdateMeterGroup Music]')
    end
    
    -- --------------------------- handle lock toggle --------------------------- --

    if tonumber(SKIN:GetVariable('Locks')) == 0 then
        SKIN:Bang('[!CommandMeasure CapsLock Stop][!CommandMeasure ScrollLock Stop][!CommandMeasure NumLock Stop][!DisableMeasureGroup Locks]')
    else
        SKIN:Bang('[!Delay 100][!SetOptionGroup Locks KeyDownAction """[!CommandMEasure Func "actionLoad(\'Locks\')"][!UpdateMeasure #*CURRENTSECTION*#]"""][!UpdateMeasureGroup Locks]')
    end

    -- ------------------------- handle animation toggle ------------------------ --

    if tonumber(SKIN:GetVariable('Ani')) == 1 then
        AniSteps = tonumber(SKIN:GetVariable('AniSteps'))
        TweenInterval = 100 / AniSteps
        ScreenPadding = SKIN:GetVariable('ScreenPadding')
        AniDir = SKIN:GetVariable('AniDir')
        dofile(SELF:GetOption("ScriptFile"):match("(.*[/\\])") .. "tween.lua")
        subject = {
            TweenNode = 0
        }
        t = tween.new(AniSteps, subject, {TweenNode=100}, SKIN:GetVariable('Easetype'))
    end

end

function tweenAnimation(dir)
    if dir == 'in' then 
        local complete = t:update(1)
    else
        local complete = t:update(-1)
    end
    resultantTN = subject.TweenNode
    if resultantTN > 100 then resultantTN = 100 elseif resultantTN < 0 then resultantTN = 0 end
    local bang = '[!SetVariable TweenNode1 '..resultantTN..'][!SetTransparency '..(resultantTN / 100 * 255)..']'
    if AniDir == 'Left' then
        bang = bang..'[!SetWindowPosition '..moveX + (resultantTN / 100 - 1) * ScreenPadding..' '..moveY..' '..anchorX..' '..anchorY..']'
    elseif AniDir == 'Right' then
        bang = bang..'[!SetWindowPosition '..moveX + (1 - resultantTN / 100) * ScreenPadding..' '..moveY..' '..anchorX..' '..anchorY..']'
    elseif AniDir == 'Top' then
        bang = bang..'[!SetWindowPosition '..moveX..' '..moveY + (resultantTN / 100 - 1) * ScreenPadding..' '..anchorX..' '..anchorY..']'
    elseif AniDir == 'Bottom' then
        bang = bang..'[!SetWindowPosition '..moveX..' '..moveY + (1 - resultantTN / 100) * ScreenPadding..' '..anchorX..' '..anchorY..']'
    end
    bang = bang..'[!UpdateMeasure ActionTimer]'
    SKIN:Bang(bang)
end

function actionLoad(type)
    local function checkShow()
        if tonumber(SKIN:GetVariable('mToggle')) == 0 then
            SKIN:Bang('[!EnableMeasure Tick][!CommandMeasure ActionTimer "Stop 2"][!CommandMeasure ActionTimer "Execute 1"][!SetVariable mToggle 1]')
        end
    end
    if type ~= 'Locks' then
        SKIN:Bang('[!HideMeterGroup Special][!ShowMeterGroup Standard]')
        if checkingPlayerState == 0 then
            SKIN:Bang('[!HideMeterGroup Music]')
        end
        SKIN:Bang('[!UpdateMeterGroup Standard][!Redraw][!CommandMeasure Tick "Reset"]')

        checkShow()

        if type == 'up' then
            SKIN:Bang('[!CommandMeasure "mVolume" "ChangeVolume #MediaKeyChange#"][!UpdateMeasure mVolume]')
        elseif type == 'down' then
            SKIN:Bang('[!CommandMeasure "mVolume" "ChangeVolume -#MediaKeyChange#"][!UpdateMeasure mVolume]')
        end
        if tonumber(SKIN:GetVariable('OverrideNativeKeyFunction')) == 1 then
            if type == 'pause' then
                SKIN:Bang('[!CommandMeasure "state'..currentPlayer..'" "PlayPause"]')
            elseif type == 'next' then
                SKIN:Bang('[!CommandMeasure "state'..currentPlayer..'" "next"]')
            elseif type == 'prev' then
                SKIN:Bang('[!CommandMeasure "state'..currentPlayer..'" "previous"]')
            end
        end
    else
        SKIN:Bang('[!HideMeterGroup Standard][!ShowMeterGroup '..type..'][!UpdateMeterGroup "Standard | '..type..'"][!Redraw]')
        SKIN:Bang('[!CommandMeasure Tick "Reset"]')

        checkShow()
    end
end

function mediaVol(dir)
    if dir == 'up' then
        SKIN:Bang('[!CommandMeasure "state'..currentPlayer..'" "SetVolume +#MediaKeyChange#"]')
    else
        SKIN:Bang('[!CommandMeasure "state'..currentPlayer..'" "SetVolume -#MediaKeyChange#"]')
    end
end


-- -------------------------------------------------------------------------- --
--                                 Media logic                                --
-- -------------------------------------------------------------------------- --

function checkMedia()

    if currentPlayer == nil then currentPlayer = SKIN:GetVariable('NowPlayingMedia') end
    if checkingPlayer == nil then checkingPlayer = 'AIMP' end
    for i = 1, 6 do
        if SKIN:GetMeasure('state'..mediaPlayers[i]):GetValue() ~= 0 then
            checkingPlayer = mediaPlayers[i]
            break
        end
    end
    checkingPlayerState = SKIN:GetMeasure('state'..checkingPlayer):GetValue()

    -- if currentPlayer ~= checkingPlayer then
    if checkingPlayer == 'WebNowPlaying' then
        SKIN:Bang('[!EnableMeasureGroup WNP][!DisableMeasureGroup NP]')
        SKIN:Bang('[!SetVariable PlayerType WNP][!UpdateMeterGroup Music]')

        if SKIN:GetVariable('FetchImage') == 0 then
            SKIN:Bang('[!DisableMeasure wnpCover]')
        end
    else 
        SKIN:Bang('[!EnableMeasureGroup NP][!DisableMeasureGroup WNP]')
        SKIN:Bang('[!SetVariable PlayerType NP][!UpdateMeterGroup Music]')

        if SKIN:GetVariable('FetchImage') == 0 then
            SKIN:Bang('[!DisableMeasure npCover]')
        end
    end
    
    SKIN:Bang('[!SetVariable NowPlayingMedia '..checkingPlayer..']')
    SKIN:Bang('[!UpdateMeasureGroup Music]')

    currentPlayer = checkingPlayer


    if checkingPlayerState == 1 then SKIN:Bang('[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Pause"][!UpdateMeter MediaPlayPause]')
    elseif checkingPlayerState == 2 then SKIN:Bang('[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Play"][!UpdateMeter MediaPlayPause]')
    elseif checkingPlayerState == 0 then SKIN:Bang('[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Play"][!UpdateMeter MediaPlayPause]')
    end

    if checkingPlayerState == 0 then
        SKIN:Bang('[!HideMeterGroup Music][!UpdateMeterGroup Music]')
    else
        SKIN:Bang('[!ShowMeterGroup Music][!UpdateMeterGroup Music]')
    end
    
    if tonumber(SKIN:GetVariable('mToggle')) ~= 0 then
        SKIN:Bang('[!Redraw]')
    end
end

-- -------------------------------------------------------------------------- --
--                       Dropdown and utility functions                       --
-- -------------------------------------------------------------------------- --



function startDrop(variant, handler, offset)
	local File = SKIN:GetVariable('ROOTCONFIGPATH')..'Main\\Accessories\\Drop.ini'
	local MyMeter = SKIN:GetMeter(handler)
	local scale = tonumber(SKIN:GetVariable('Scale'))
    local PosX = SKIN:GetX() + MyMeter:GetX() + offset * scale
    local PosY = SKIN:GetY() + MyMeter:GetY() + offset * scale
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.name', skin, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', variant, File)
	SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
	SKIN:Bang('!PauseMeasure', 'mToggle')
    SKIN:Bang('!ZPos', '0')
	SKIN:Bang('!Activateconfig', 'QuickNote\\Main\\Accessories', 'Drop.ini')
	SKIN:Bang('!Move', PosX, PosY, 'QuickNote\\Main\\Accessories')
end

function returnDiv(divChar)
    local divLength = SKIN:GetVariable('DividerLength')
    local this = divChar
    for i = 1, divLength - 1 do
        this = this..divChar
    end
    return this
end

function returnBar(measureName, multiplier)
    local function DIV(a,b)
        return (a - a % b) / b
    end
    if multiplier == nil then multiplier = 1 end
    local VolumeLevel = SKIN:GetMeasure(measureName):GetValue() * multiplier
    local barChar = SKIN:GetVariable('BarCharacter')
    local barLength = SKIN:GetVariable('BarLength')
    local resultBarLength = DIV((barLength * VolumeLevel), 100)
    -- local this = ''
    -- for i = 1, resultBarLength do
    --     this = this..barChar
    -- end
    return resultBarLength
end

function checkEscape(char)
    if char == '|' or char == '\\' or char == '/' or char == '*' or char == '.' then
        return '\\'..char
    else
        return char 
    end
end

function returnBool(String, Match, ReturnStringT, ReturnStringF)
	local function startswith(text, prefix)
		return text:find(prefix, 1, true) == 1
	end

	ReturnStringT = ReturnStringT or '1'
	ReturnStringF = ReturnStringF or '0'
	if string.find(String, Match) then
		return(ReturnStringT)
	  else
		return(ReturnStringF)
	end
end