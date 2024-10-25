#include "affichageEchantillon.h"

  void affiEchantillon(double echec, double ValeurAffiner0, double ValeurAffiner1, double ValeurAffiner2, double ValeurAffiner3, double amp1, double amp2, double phase1, double phase2, double AmpMoyenne, double phaseMoyenne)
  { 

    /*--------------------------------------------------AFFICHAGE DES VALEUR RECOLTER PAR LE REGISTRE ADCH----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    // À des fins de diagnostic, imprimez les comptages individuels des bacs et les 2 gains et phases calculés indépendamment.                                                       
    Serial.println("echec : " +String(echec));
    Serial.write(' ');
    
    if (ValeurAffiner0 >= 0.0) Serial.write(' ');
    Serial.println("ValeurAffiner0 : " +String(ValeurAffiner0, 2)); //Affiche la valeur de ValeurAffiner0 avec une précision de 2décimals
    Serial.write(' ');   //envoie un espace au port série pour aligné l'affichage des valeurs
    if (ValeurAffiner1 >= 0.0) Serial.write(' ');
    Serial.println("ValeurAffiner1 : " +String (ValeurAffiner1, 2)); //Affiche la valeur de ValeurAffiner1 avec une précision de 2décimals
    Serial.write(' ');  
    if (ValeurAffiner2 >= 0.0) Serial.write(' ');
    Serial.println("ValeurAffiner2 :" +String (ValeurAffiner2, 2)); //Affiche la valeur de ValeurAffiner2 avec une précision de 2décimals
    Serial.write(' '); 
    if (ValeurAffiner3 >= 0.0) Serial.write(' ');
    Serial.println("ValeurAffiner3 : " +String(ValeurAffiner3, 2)); //Affiche la valeur de ValeurAffiner3 avec une précision de 2décimals
    Serial.print("    ");  
    Serial.println("Amp1 : " +String(amp1, 2)); //Affiche la valeur de amp1 avec une précision de 2décimals
    Serial.write(' '); 
    Serial.println("Amp2 : " +String(amp2, 2)); //Affiche la valeur de amp2 avec une précision de 2décimals
    Serial.write(' ');  
    if (phase1 >= 0.0) Serial.write(' ');
    Serial.println("Phase1 : " +String(phase1, 2)); //Affiche la valeur de phase1 avec une précision de 2décimals
    Serial.write(' ');  
    if (phase2 >= 0.0) Serial.write(' ');
    Serial.println("Phase2 : " +String(phase2, 2)); //Affiche la valeur de phase2 avec une précision de 2décimals
    if (AmpMoyenne >= 0.0) Serial.write(' ');
    Serial.println("AmpMoyenne : " +String(AmpMoyenne, 1)); //Affiche la valeur de AmpMoyenne avec une précision de 1décimal
    Serial.write(' ');
    if (phaseMoyenne >= 0.0) Serial.write(' ');
    Serial.println("Phase Moyenne : " +String((int)phaseMoyenne));
  Serial.println ();
  Serial.println("---------------------------------------------------------------------------");
  Serial.println ();
    // Imprimez l'amplitude et la phase finales, que nous utilisons pour décider de ce que (le cas échéant) nous avons trouvé).
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
  }
    