#include"fichier_ppm.h"
#include <iostream>
#include<fstream>

using namespace std ;

int main()
{
    //Retour
    bool bVerfifierFichier (false) ;
    bool bVerifierDimensions (false) ;
    unsigned int wResultatRVB(0) ;
    unsigned int * * tabLogo (nullptr) ;

    //Paramètres

    // Chemin du fichier image
    char * sNomFichier  = "C:\\YOUR FILE PPM" ;

    // Variables pour stocker les dimensions de l'image
    unsigned int wHauteur (0) ;
    unsigned int wLargeur (0) ;

    // Dimensions attendues de l'image
    unsigned int wHauteurAttendue (0) ;
    unsigned int wLargeurAttendue (0) ;


    unsigned int wRouge (0) ;
    unsigned int wVert = (0) ;
    unsigned int wBleu = (0) ;

    //Appel fonction/procédures

    // Vérification du format de l'image
    bVerfifierFichier = EstPPM_RVB(sNomFichier) ;

    if (bVerfifierFichier == true)
       {
           cout << "Le fichier est au format PPM, RVB 255. (" << bVerfifierFichier << ")." << endl;

           // Lecture des dimensions de l'image
           LirePPM_Dimensions(sNomFichier, wHauteur, wLargeur) ;

           // Vérification si les dimensions correspondent à celles attendues
           bVerifierDimensions = EstDeTaille(sNomFichier,wHauteurAttendue,wLargeurAttendue) ;

           if (bVerifierDimensions == true)
            {
                // Création du tableau
                tabLogo = CreerTableau2D(wHauteur, wLargeur);

                // Appel de la fonction RVB
                wResultatRVB = RVB(wRouge, wVert, wBleu) ;

                // Lecture de l'image
                LireImagePPM(sNomFichier, tabLogo, wHauteur, wLargeur) ;

                // Affichage de l'image
                AfficherImage(tabLogo, wHauteur, wLargeur) ;

                // Destruction du tableau
                LibererTab2D(tabLogo, wHauteur, wLargeur) ;
            }
    }

    return 0;
}
