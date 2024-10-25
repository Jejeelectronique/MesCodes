
Option Explicit
Public valeur As Double
Public mesure As String

Private Sub Label3_Click()

End Sub

Private Sub Label8_Click()

End Sub

Private Sub Txt_mm_Change()
If Not IsNumeric(Txt_mm) Then
    Txt_mm = ""
    
Else
    valeur = Txt_mm
    mesure = "mm"
    
    Call convert_all
    
End If
End Sub
Private Sub Txt_cm_Change()
If Not IsNumeric(Txt_cm) Then
    Txt_cm = ""
    
Else
    valeur = Txt_cm
    mesure = "cm"
    
Call convert_all
    
End If
End Sub

Private Sub Txt_dm_Change()
If Not IsNumeric(Txt_dm) Then
    Txt_dm = ""
    
Else
    valeur = Txt_dm
    mesure = "dm"
    
Call convert_all
    
End If
End Sub

Private Sub Txt_m_Change()
If Not IsNumeric(Txt_m) Then
    Txt_m = ""
    
Else
    valeur = Txt_m
    mesure = "m"
   
Call convert_all
    
End If
End Sub

Private Sub Txt_dam_Change()
If Not IsNumeric(Txt_dam) Then
    Txt_dam = ""
    
Else
    valeur = Txt_dam
    mesure = "dam"
    
 Call convert_all
    
End If
End Sub

Private Sub Txt_hm_Change()
If Not IsNumeric(Txt_hm) Then
    Txt_hm = ""
    
Else
    valeur = Txt_hm
    mesure = "hm"
    
 Call convert_all
    
End If
End Sub

Private Sub Txt_km_Change()
If Not IsNumeric(Txt_km) Then
    Txt_km = ""
    
Else
    valeur = Txt_km
    mesure = "km"
    
 Call convert_all
    
End If
End Sub


Public Sub convert_all()

'déclaration variable.
Dim convert_mm As Double
Dim convert_cm As Double
Dim convert_dm As Double
Dim convert_m As Double
Dim convert_dam As Double
Dim convert_hm As Double
Dim convert_km As Double

'configuré nos variables.
convert_mm = WorksheetFunction.Convert(valeur, mesure, "mm")
convert_dm = WorksheetFunction.Convert(valeur, mesure, "dm")
convert_cm = WorksheetFunction.Convert(valeur, mesure, "cm")
convert_m = WorksheetFunction.Convert(valeur, mesure, "m")
convert_dam = WorksheetFunction.Convert(valeur, mesure, "dam")
convert_hm = WorksheetFunction.Convert(valeur, mesure, "hm")
convert_km = WorksheetFunction.Convert(valeur, mesure, "km")

Txt_mm = convert_mm
Txt_cm = convert_cm
Txt_dm = convert_dm
Txt_m = convert_m
Txt_dam = convert_dam
Txt_hm = convert_hm
Txt_km = convert_km

End Sub

Private Sub UserForm_Click()

End Sub
