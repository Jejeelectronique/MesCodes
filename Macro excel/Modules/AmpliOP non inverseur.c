Dim VE As Double
Dim R1 As Double
Dim R2 As Double
Dim VSVE As Double
Dim VS As Double
Dim VSATP As Double
Dim VSATN As Double
Dim i As Double



Sub Ampli_op_non_inverseur()


'nous mettons une boucle i pour éxecuter le code 2 fois par appuie de bouton car certaines variables prennent leur valeur finale apres 2 éxecution complete du code
'et cela évite a avoir a appuyer 2 fois sur le bouton sur la feuille


'1er Bloc pour calculer VS en fonction des différentes entrée

If Range("b34") = "VS" Then

'test de condition de notre cellule déroulante; si Vraie alors c'est ce bloc qui sera éxecuter
'Si faux alors tous le bloc sera ignorée et la condition du bloc suivant sera tester

Range("d34") = "VE"
VE = Range("d35").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("e34") = "R1"
R1 = Range("e35").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("f34") = "R2"
R2 = Range("f35").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc



 If R1 > 0 And R2 <= 0 Then
 VS = 0
 Range("b35").Value = VS
 R2 = 0
 Range("f35").Value = R2

'test pour R1 et R2 tous les 2 égal ou inf a zéro
'si vraie alors VS sera égal a VE

ElseIf R1 <= 0 And R2 <= 0 Then
VS = 0
Range("b35").Value = VS

 R2 = 0
 Range("f35").Value = R2
 R1 = 0
 Range("e35").Value = R1

'test condition si R1 inf ou égal a 0 et R2 inf ou égal a zero alors VS = VE



ElseIf R1 <= 0 And R2 > 0 Then
VS = VE
Range("b35").Value = VS

 R1 = 0
 Range("e35").Value = R1

'test condition si R1 inf ou égal a 0 et R2 sup a zero et VE = 0 alors VS = 0
Else

VS = VE * (R2 / (R1 + R2))
Range("b35").Value = VS

'si tous les conditions précdentes sont fausse alors cette condition
'sera éxecuter en procédant au calcul de VS

End If
End If
'Fin du 1er bloc VS
'il y a plusieur end if a la fin car plusieurs test de conditions on etais effectuer
'lors de ce bloc et il étais nécessaire de les laisser actif jusqu'a la fin du bloc
'complet pour que ceux-ci s'applique a tous le bloc














If Range("b34") = "VE" Then

'test de condition de notre cellule déroulante; si Vraie alors c'est ce bloc qui sera éxecuter
'Si faux alors tous le bloc sera ignorée et la condition du bloc suivant sera tester

Range("d34") = "VS"
VS = Range("d35").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("e34") = "R1"
R1 = Range("e35").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("f34") = "R2"
R2 = Range("f35").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

If VS = 0 And R1 = 0 Then
VE = 0
Range("b35").Value = VE



Else

VE = VS / (R2 / (R1 + R2))



End If
End If

VSVE = VS / VE
Range("c35").Value = VSVE






End Sub

