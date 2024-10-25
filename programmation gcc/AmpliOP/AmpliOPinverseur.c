#include <stdio.h>


int VE;
int R1;
int R2;
int VSVE;
int VS;
int VSATP;
int VSATN;
int i;
int operateur;


#define Vout 0
#define Vgen 1
#define valR1 2
#define valR2 3
 
int main(void){


printf ("Rentrer la valeur associée au calcul que vous souhaitée éxécuter\n" , "VS : 0\n" , "VE : 0\n" , "R1 : 0\n" , "R2 : 0\n");
scanf("%d" , &operateur);


swithc(operateur){

case Vout

printf ("Calcul de VS en fonction de VE , R1 et R2\n" , "Rentrer une valeur pour VE : \n");
scanf("&d" , &VE);
printf ("Rentrer une valeur pour R1 : \n");
scanf("&d" , &R1);
printf ("Rentrer une valeur pour R2 : \n");
scanf("&d" , &R2);
printf ("Rentrer la tension d'alimentation positive de l'AOP : \n");
scanf("&d" , &VSATP);
printf ("Rentrer la tension d'alimentation negative de l'AOP : \n");
scanf("&d" , &VSATN);

 If (R1 > 0 And R2 <= 0)
 {
 	VS = 0;
 	R2 = 0;
 }

ElseIf (R1 <= 0 And R2 <= 0)
{
	VS = VE;
	R2 = 0;
	R1 = 0;
}


ElseIf (R1 <= 0 And R2 > 0 And VE > 0)
{
	VS = VSATN;
	R1 = 0;
}

ElseIf (R1 <= 0 And R2 > 0 And VE < 0)
{
VS = VSATP;
R1 = 0;
}
 

ElseIf (R1 <= 0 And R2 > 0 And VE = 0)
{
	VS = 0;
	R1 = 0;
}


Else
{
	VS = -(VE * (R2 / R1));

If (VS < VSATN)
{
	VS = VSATN;
}

ElseIf (VS > VSATP)
{
	VS = VSATP
}
}


'2eme Bloc pour calculer VE en fonction des différentes entrée

If Range("b9") = "VE" Then

'test de condition de notre cellule déroulante; si Vraie alors c'est ce bloc qui sera éxecuter
'Si faux alors tous le bloc sera ignorée et la condition du bloc suivant sera tester

Range("f9") = "VS"
VS = Range("f10").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("g9") = "R1"
R1 = Range("g10").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("h9") = "R2"
R2 = Range("h10").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

If VS < VSATN Then
VS = VSATN
Range("f10").Value = VS

'condition pour limité VS par rapport a VSATN et ainsi réspecter le VCC- max de sortie de l'opamp
'nous le déclarons en local dans ce bloc car la conditions prend en compte l'emplacement de VS
'qui peut changer d'emplacement dans les autres bloc, il fudra donc réexecuter ce test de conditions
'pour les autres bloc en changeant l'emplacement de la variable VS

ElseIf VS > VSATP Then
VS = VSATP
Range("f10").Value = VS

'condition pour limité VS par rapport a VSATN et ainsi réspecter le VCC+ max de sortie de l'opamp
'nous le déclarons en local dans ce bloc car la conditions prend en compte l'emplacement de VS
'qui peut changer d'emplacement dans les autres bloc, il fudra donc réexecuter ce test de conditions
'pour les autres bloc en changeant l'emplacement de la variable VS

ElseIf R1 <= 0 And R2 > 0 And VS <> 0 Then
R1 = 0
Range("g10").Value = R1
VE = VS * -1
Range("b10").Value = VE

'test de conditions pour R1, si R1 inf ou égal a 0 alors VE = VSATN

ElseIf R1 > 0 And R2 <= 0 And VS <> 0 Then

VE = 0
Range("b10").Value = "impossible"
R2 = 0
Range("h10").Value = R2

'test cond pour R2, si R2 inf ou égal a 0 alors VE = VS*-1

ElseIf R1 <= 0 And R2 <= 0 Then
R1 = 0
Range("g10").Value = R1
R2 = 0
Range("h10").Value = R2
VE = VS
Range("b10").Value = VE

'condition pour R2 et R1, si les 2 sont nul alors VS = VE

Else

VE = (VS / (R2 / R1) * -1)
Range("b10").Value = VE

'si les autres conditions sont fausse alors ce code sera éxécuter en
'procédant au calcul de VE en fonction de (VS / (R2/R1) *-1)

End If
End If
'Fin du 2éme bloc VE
'il y a plusieur end if a la fin car plusieurs test de conditions on etais effectuer
'lors de ce bloc et il étais nécessaire de les laisser actif jusqu'a la fin du bloc
'complet pour que ceux-ci s'applique a tous le bloc
























'3eme Bloc pour calculer R1 en fonction des différentes entrée (Fonctionnelle mais pas finie)

If Range("b9") = "R1" Then

'test de condition de notre cellule déroulante; si Vraie alors c'est ce bloc qui sera éxecuter
'Si faux alors tous le bloc sera ignorée et la condition du bloc suivant sera tester

Range("f9") = "VE"
VE = Range("f10").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("g9") = "VS"
VS = Range("g10").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("h9") = "R2"
R2 = Range("h10").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

If VSVE = 0 And R2 >= 0 Then
R1 = 0

'test de condition; si VS/VE et R2 sont tous les 2 égal a 0 alors R1 forcément égal a 0

ElseIf VS > VSATP Then
VS = VSATP
Range("g10").Value = VS

'on limite la valeur positive de VS par la variable VSATP

ElseIf VS < VSATN Then
VS = VSATN
Range("g10").Value = VS

'on limite la valeur négative de VS par la variable VSATN

ElseIf R1 < 0 Then
R1 = R1 * (-1)
Range("b10").Value = R1
'permet de maintenir une valeur positive pour la variable R1


ElseIf VSVE <> 0 And R2 = 0 Then

'test de condition; si VS/VE et different de 0 et R2 est égal a 0 alors R1 ne peut prendre n'importe quelle valeur

R1 = 0

'mise a zero de R1 pour évite les plantage lié a une division par zero

Range("b10").Value = "inconnue"

'l'on fait apparaitre "inconnue" sur la case de R1

ElseIf VE <> 0 And VS = 0 Then
R1 = 0.1
Range("b10").Value = "infinie"

ElseIf VE = 0 And VS <> 0 Then
Range("b10").Value = "impossible"
R1 = 0

Else

R1 = (R2 / VSVE)
Range("b10").Value = R1

'si aucune des conditons précédente ne se sont révéler vraie alors cette équation
'sera éxécuter pour trouver R1 et on affichera ensuite le résultat dans la céllule
'de R1

End If
End If
'fin du 3eme bloc R1
'il y a plusieur end if a la fin car plusieurs test de conditions on etais effectuer
'lors de ce bloc et il étais nécessaire de les laisser actif jusqu'a la fin du bloc
'complet pour que ceux-ci s'applique a tous le bloc




















'4eme Bloc pour calculer R2 en fonction des différentes entrée (Fonctionnelle mais pas finie)

If Range("b9") = "R2" Then

'test de condition de notre cellule déroulante; si Vraie alors c'est ce bloc qui sera éxecuter
'Si faux alors tous le bloc sera ignorée et la condition du bloc suivant sera tester

Range("f9") = "VE"
VE = Range("f10").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("g9") = "VS"
VS = Range("g10").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

Range("h9") = "R1"
R1 = Range("h10").Value

'mise a jour des Valeurs et emplacement des cellules pour s'adapter a ce bloc

If R2 < 0 Then
R2 = R2 * -1
Range("b10").Value = R2
'l'on fixe la valeur de R2 comme étant positive

ElseIf VS = 0 And VE <> 0 Then
R2 = 0
Range("b10").Value = R2

ElseIf VE = VS And R1 = 0 Then
R2 = 0
Range("b10").Value = R2

ElseIf VE = 0 And VS <> 0 Then
R2 = 0
Range("b10").Value = "impossible"


Else
R2 = (R1 * VSVE)
Range("b10").Value = R2

'équation qui permet de trouvé R2 en fonction de R1 multiplié par VS/VE

End If
End If
'Fin du 4eme bloc R2














'Variable VS/VE qui permet de connaitre le rapport entre la sortie et l'entrée
'également indispensable pour pouvoir calculer R1 et R2
'on le déclar en bas du code en dehors des différentes boucles if des différents bloc
'pour que celui-ci sois valabe partout et cela évite de le redéclarer


If VE = 0 Then
VSVE = 0
Range("c10").Value = VSVE

'test de condition si VE inférieur ou égal a 0 alors VSVE  est forcément = 0
'nous sommes obligé de passer par cette méthode pour VE = 0 sinon le compilateur essayera
'de diviser VSVE par 0 (qui fait donc 0) et il plantera; nous assignons donc manuellement
'0 a VSVE (puisque c'est le résultat d'une div par 0) sans passer par une division du compilateur


ElseIf VS > 0 And VE > 0 Then
VSVE = VS / VE
Range("c10").Value = VSVE

'test de condition pour VS et VE pour éviter d'avoir une valeur négative si VS et VE tous les 2 positifs alors VSVE = VS / VE

ElseIf VS < 0 And VE < 0 Then
VSVE = VS / VE
Range("c10").Value = VSVE

'test de condition pour VS et VE pour éviter d'avoir une valeur négative, si VS et VE tous les 2 négatifs alors VSVE = VS / VE *-1

ElseIf VS > 0 And VE < 0 Then
VSVE = (VS / VE) * -1
Range("c10").Value = VSVE

'test de condition pour VS et VE pour éviter d'avoir une valeur négative, si VS positif et VE négatifs alors VSVE = VS / VE *-1

ElseIf VS < 0 And VE > 0 Then
VSVE = (VS / VE) * -1
Range("c10").Value = VSVE

'test de condition pour VS et VE pour éviter d'avoir une valeur négative, si VS négatif et VE négatifs alors VSVE = VS / VE *-1


End If
'Fin de déclaration de VSVE

Next i

End Sub
'Fin de l'ensemble du code

}
}