[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Show | Repeat In,2,#AniSteps#
ActionList2=SaveLocation | Repeat Out,2,#AniSteps# | Hide
Show=[!Show]
Hide=[!Hide]
SaveLocation=[!CommandMeasure Func "saveLocation()"]
In=[!CommandMeasure Func "tweenAnimation('in')"]
Out=[!CommandMeasure Func "tweenAnimation('out')"]