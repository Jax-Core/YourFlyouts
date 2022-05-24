[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Show | Repeat In,2,#AniSteps# | Wait 100 | Repeat In2,2,#AniSteps#
ActionList2=SaveLocation | Repeat Out2,2,#AniSteps# | Wait 100 | Repeat Out,2,#AniSteps# | Hide
Show=[!Show]
Hide=[!Hide]
SaveLocation=[!CommandMeasure Func "saveLocation()"]
In=[!CommandMeasure Func "tweenAnimation('in')"]
Out=[!CommandMeasure Func "tweenAnimation('out')"]
In2=[!CommandMeasure Func "tweenAnimation2('in')"]
Out2=[!CommandMeasure Func "tweenAnimation2('out')"]