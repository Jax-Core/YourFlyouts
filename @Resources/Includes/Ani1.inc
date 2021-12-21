[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Show | Repeat #AniDir#In,2,20
; (2000/20)
ActionList2=Repeat #AniDir#Out,2,20 | Hide
Show=[!Show]
Hide=[!Hide]
LeftIn=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#+5),0,100))"][!SetTransparency ((#TweenNode1#+5)/100*255)][!SetWindowPosition (#SkinX#+((#TweenNode1#+5)/100-1)*#ScreenPadding#) #SkinY# #SkinAX# #SkinAY#][!UpdateMeasure ActionTimer]
LeftOut=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#-5),0,100))"][!SetTransparency ((#TweenNode1#-5)/100*255)][!SetWindowPosition (#SkinX#+((#TweenNode1#-5)/100-1)*#ScreenPadding#) #SkinY# #SkinAX# #SkinAY#][!UpdateMeasure ActionTimer]
RightIn=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#+5),0,100))"][!SetTransparency ((#TweenNode1#+5)/100*255)][!SetWindowPosition (#SkinX#+(1-(#TweenNode1#+5)/100)*#ScreenPadding#) #SkinY# #SkinAX# #SkinAY#][!UpdateMeasure ActionTimer]
RightOut=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#-5),0,100))"][!SetTransparency ((#TweenNode1#-5)/100*255)][!SetWindowPosition (#SkinX#+(1-(#TweenNode1#-5)/100)*#ScreenPadding#) #SkinY# #SkinAX# #SkinAY#][!UpdateMeasure ActionTimer]
TopIn=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#+5),0,100))"][!SetTransparency ((#TweenNode1#+5)/100*255)][!SetWindowPosition #SkinX# (#SkinY#+((#TweenNode1#+5)/100-1)*#ScreenPadding#) #SkinAX# #SkinAY#][!UpdateMeasure ActionTimer]
TopOut=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#-5),0,100))"][!SetTransparency ((#TweenNode1#-5)/100*255)][!SetWindowPosition #SkinX# (#SkinY#+((#TweenNode1#-5)/100-1)*#ScreenPadding#) #SkinAX# #SkinAY#][!UpdateMeasure ActionTimer]
BottomIn=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#+5),0,100))"][!SetTransparency ((#TweenNode1#+5)/100*255)][!SetWindowPosition #SkinX# (#SkinY#+(1-(#TweenNode1#+5)/100)*#ScreenPadding#) #SkinAX# #SkinAY#][!UpdateMeasure ActionTimer]
BottomOut=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#-5),0,100))"][!SetTransparency ((#TweenNode1#-5)/100*255)][!SetWindowPosition #SkinX# (#SkinY#+(1-(#TweenNode1#-5)/100)*#ScreenPadding#) #SkinAX# #SkinAY#][!UpdateMeasure ActionTimer]
; In=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#+5),0,100))"][!UpdateMeterGroup Ani][!UpdateMeasure ActionTimer][!Redraw]
; Out=[!SetVariable TweenNode1 "(Clamp((#TweenNode1#-5),0,100))"][!UpdateMeterGroup Ani][!UpdateMeasure ActionTimer][!Redraw]