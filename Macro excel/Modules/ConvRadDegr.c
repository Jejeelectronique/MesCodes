Sub Convertisseur_degres_radians()

    Dim convert_degrés As Double
    Dim convert_radians As Double

    If Range("N22").Value = "Degrès" Then
        ' Convertir degrés en radians
        convert_radians = Range("l22").Value * 0.0174532925
        ' Afficher le résultat dans la cellule M24
        Range("l23").Value = convert_radians
        Range("n23").Value = "Radians"
    
    
    ElseIf Range("N22").Value = "Radians" Then
    
    convert_degrés = Range("l22").Value * (180 / 3.1415926535)
        
        Range("l23").Value = convert_degrés
        Range("n23").Value = "Degrès"
    Else
        ' Si la cellule N32 ne contient ni "Degrès" ni "Radians", afficher un message d'erreur
        MsgBox "La cellule N32 doit contenir soit ""Degrès"" soit ""Radians""."
    End If

End Sub
