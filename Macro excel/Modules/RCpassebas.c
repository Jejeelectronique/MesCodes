'version A

Dim R As Double
Dim C As Double
Dim Fc As Double
Dim doublePI As Double
Dim selecteur As String








Sub Filtre_passe_bas()






'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'Constante 2 x PI
doublePI = WorksheetFunction.Pi() * 2
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
selecteur = Range("d13").Text


Select Case selecteur

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''


'1er bloc pour calculer Fc en fonction de R et C

Case "Fc"



Range("e13").Value = "R"
R = Range("e14").Value

Range("f13").Value = "C"
C = Range("f14").Value

If R <= 0 Or C <= 0 Then
Fc = 0
Range("d14").Value = Fc

Else
Fc = 1 / (doublePI * R * C)
Range("d14").Value = Fc

End If
'calcul pour Fc si aucune des conditons précédentes n'est vraie


'fin du 1er bloc
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''








'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'2eme bloc pour calculer R en fonction de Fc et C

Case "R"



'mise a jour des valeur des variables des cellules

Range("e13").Value = "Fc"
Fc = Range("e14").Value

Range("f13").Value = "C"
C = Range("f14").Value

If Fc <= 0 Or C <= 0 Then
R = 0
Range("d14").Value = R

Else
R = 1 / (doublePI * Fc * C)
Range("d14").Value = R
End If


'fin du 2eme bloc
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''











'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'3eme bloc pour calculer C en fonction de R et Fc

Case "C"

Range("e13").Value = "Fc"
Fc = Range("e14").Value
    
Range("f13").Value = "R"
R = Range("f14").Value

If Fc <= 0 Or R <= 0 Then
C = 0
Range("d14").Value = C

Else
C = 1 / (doublePI * Fc * R)
Range("d14").Value = C

End If

    
End Select
End Sub
'fin du 3eme bloc

