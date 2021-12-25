[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Show | Repeat In,2,#AniSteps#
; (2000/20)
ActionList2=Repeat Out,2,#AniSteps# | Hide
Show=[!Show]
Hide=[!Hide]
In=[!CommandMeasure Func "tweenAnimation('in')"]
Out=[!CommandMeasure Func "tweenAnimation('out')"]