[Variables]
Sec.SaveLocation=#SKINSPATH##Skin.Name#\Main\Vars\#Layout#.inc
Sec.AnchorName=AnchorSuppli
@includeSaveLocation=#SKINSPATH##Skin.Name#\Main\Vars\#Layout#.inc

[HotkeysTitle]
Meter=String
Text=These settings are linked to the layout you've selected.
MeterStyle=Set.String:S | Set.OptionCat:S
[HeaderImage]
Meter=Image
X=r
Y=(10*[Set.S])R
W=([ContentContainer:W]-#Set.P#)
H=(150*[Set.S])
ImageName=#SKINSPATH##Skin.Name#\Core\Layout\#Layout#.png
PreserveAspectRatio=2
DynamicVariables=1
MaskImageName=#@#Images\LayoutMask.png
Container=ContentContainer
[Set.Div:112312311]
Meter=Shape
MeterStyle=Set.Div:S
[Option00]
Meter=String
Text=Layout scale
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:1123123]
Meter=Shape
MeterStyle=Set.Div:S

@includeCoreAppearanceStyles=#SKINSPATH##SKin.Name#\Core\AppearanceStyles\#Layout#.inc