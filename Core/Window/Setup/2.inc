[Header.Image]
Y=(50*[S])

[Header.String]
Text=Media flyouts

[Description.String]
Text=YourFlyouts can work with both NowPlaying and the Windows API. Which one do you want to use?
InlinePattern=NowPlaying|Windows API

[Box.1.Shape]
Meter=Shape
X=(#W#/2-(620*[S])/2)
Y=R
LeftMouseUpAction=[!WriteKeyValue Variables MediaType "Modern" "#SKINSPATH#YourFlyouts\@Resources\Vars.inc"][!WriteKeyValue Variables Sec.arg2 "3" "#CURRENTPATH#Main.ini"][!Refresh]
MeterStyle=Pos_Box.Shape:S
[Box.2.String]
Meter=String
Text=Windows API#CRLF#Expected to work for all players  with no setup. Not all players support all the features, but does more than enough
MeterStyle=Sec.String:S | Box.String:S

[Box.2.Shape]
Meter=Shape
LeftMouseUpAction=[!WriteKeyValue Variables MediaType "Auto" "#SKINSPATH#YourFlyouts\@Resources\Vars.inc"][!WriteKeyValue Variables Sec.arg2 "3" "#CURRENTPATH#Main.ini"][!Refresh]
MeterStyle=Box.Shape:S
[Box.1.String]
Meter=String
Text=NowPlaying#CRLF#Recommended if you've used AUTO media method in other modules. Fully supports a selection of players.
MeterStyle=Sec.String:S | Box.String:S