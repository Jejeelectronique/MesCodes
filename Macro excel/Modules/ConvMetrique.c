


Private Sub convert_metrique()
'déclaration variable.
Dim convert_mm As Double
Dim convert_cm As Double
Dim convert_dm As Double
Dim convert_m As Double
Dim convert_dam As Double
Dim convert_hm As Double
Dim convert_km As Double
Dim valeur As Double





'configuré nos variables.
convert_mm = WorksheetFunction.Convert(Range("l21"), Range("m21"), "mm")
convert_cm = WorksheetFunction.Convert(Range("l21"), Range("m21"), "cm")
convert_m = WorksheetFunction.Convert(Range("l21"), Range("m21"), "dm")
convert_dm = WorksheetFunction.Convert(Range("l21"), Range("m21"), "m")
convert_dam = WorksheetFunction.Convert(Range("l21"), Range("m21"), "dam")
convert_hm = WorksheetFunction.Convert(Range("l21"), Range("m21"), "hm")
convert_km = WorksheetFunction.Convert(Range("l21"), Range("m21"), "km")
valeur = Range("l21")


Range("m22") = convert_mm
Range("m23") = convert_cm
Range("m24") = convert_m
Range("m25") = convert_dm
Range("m26") = convert_dam
Range("m27") = convert_hm
Range("m28") = convert_km

If Not IsNumeric(valeur) Then
    valeur = ""

    End If

End Sub



