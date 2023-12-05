#include "fichier_ppm.h"
#include<fstream>
#include<iostream>
#include<cstring>

#define ROUGE (0x00FF0000) // Rouge
#define BLEU (0x000000FF) // Bleu
#define VERT (0x0000FF00) // Vert

#define BLANC (0x00FFFFFF) // Blanc
#define ROUGEFONCE (0x007D0404) // Rouge foncé


using namespace std ;


// (1) Vérifie si le fichier est bien au format PPM, RVB 255.
bool EstPPM_RVB(char * sNomImage)
{
    bool bEstPPM (false) ;
    bool bVerifierP3 (false) ;
    bool bVerifierNbre (false) ;
    char tampon[71] ;

    // Declaration de l'objet fstream puis ouverture
    fstream monFichier (sNomImage, ios::in);

    // Verifier si l'image existe
    if(!monFichier)
    {
        cout << "Erreur d'ouverture de fichier \" " << sNomImage <<" \""<< endl << endl ;
        exit(-1) ;
    }
    else
    {
        cout << "Le fichier \" "<< sNomImage << " \" a ete ouvert avec succes" << endl << endl ;
    }

    // Lecture de la première ligne
    monFichier.getline(tampon, 71, '\n') ;
    if((tampon[0] == 'P') && (tampon[1] == '3'))
    {
        bVerifierP3 = true ;
    }

    // Lecture des lignes 2, 3, 4
    for (int i (0); i < 3; ++i)
   {
       monFichier.getline(tampon, 71, '\n');
   }

    // Lecture de la cinquième ligne
    if((tampon[0] == '2') && (tampon[1] == '5') && (tampon[2] == '5'))
    {
        bVerifierNbre = true ;
    }

   /* monFichier.getline(tampon, 71, '\n') ;*/
    if((bVerifierP3 == true) && (bVerifierNbre == true))
    {
        bEstPPM = true ;
    }

    // Fermeture du fichier
    monFichier.close() ;

    return bEstPPM ;
}


// (2) Procédure qui retourne les dimensions wHauteur et wLargeur de l’image.
void LirePPM_Dimensions( char * sNomImage,
                        unsigned int & wHauteur,
                        unsigned int & wLargeur)
{
    char tampon[71] ;

    // Declaration de l'objet fstream puis ouverture
    fstream monFichier (sNomImage, ios::in);

    // Verifier si l'image existe
    if(!monFichier)
    {
        cout << "Erreur d'ouverture de fichier" << sNomImage << endl ;
        exit(-1) ;
    }

    // Lecture de la ligne 3 (8 8)
    monFichier.getline(tampon, 71, '\n') ;
    monFichier.getline(tampon, 71, '\n') ;

    // Lecture des dimensions de l'image
    monFichier >> wHauteur >> wLargeur ;

    // Affichage des dimensions de l'image
    cout << "L'image a une dimension de : " << wHauteur << " x " << wLargeur << " pixels." << endl ;

    //Fermeture du fichier
    monFichier.close() ;
}

// (3) Fonction qui verifie si les dimensions de l’image sont identiques
bool EstDeTaille ( char * sNomImage,
                 unsigned int wHauteur,
                 unsigned int wLargeur)
{
    bool bRetourTaille (false) ;
    unsigned int wHauteurAttendue (0) ;
    unsigned int wLargeurAttendue (0) ;

    // Vérifier si les dimensions correspondent à celles requises
    if (wHauteur == wHauteurAttendue && wLargeur == wLargeurAttendue)
    {
        bRetourTaille = true;
        cout << "Les dimensions de l'image sont identiques. (" << bRetourTaille << ")" << endl ;
    }
    else
    {
        bRetourTaille = false;
        cout << "Les dimensions de l'image ne sont pas identiques. (" << bRetourTaille << ")" << endl ;
    }

    return (bRetourTaille) ;
}

// (4) Fonction pour créer un tableau dynamique à deux dimensions
unsigned int * * CreerTableau2D(unsigned int wHauteur, unsigned int wLargeur)
{
    // Création du tableau à deux dimensions
    unsigned int * * wTab (nullptr) ;
    wTab = new unsigned int * [wHauteur] ;

    for (unsigned int i (0); i < wHauteur; ++i)
    {
        wTab[i] = new unsigned int [wLargeur] ;
    }

    // Desalllocation de la mémoire mais pas besoin pour l'instant
//    if (wTab != nullptr)
//    {
//        CreerTabIeau2D(wTab, wHauteur, wLargeur) ;
//        delete [] wTab ;
//        wTab = nullptr ;
//    }
    return wTab; // Retourne le tableau alloué dynamiquement
}

// (5) Fonction pour combiner les composantes RVB dans un seul entier
unsigned int RVB(unsigned int wR, unsigned int wV, unsigned int wB)
{
    unsigned int wRvb (0) ;

    // Vérifier si les couleurs sont inférieurs à 255
    if (wR <= 255 && wV <= 255 && wB <= 255)
    {
        // Combinaison des valeurs RVB dans un seul entier en utilisant des décalages bit à bit
        wRvb = wRvb | (wR << 16) ; // Ajoute la composante rouge (décalage 16 bits)
        wRvb = wRvb | (wV << 8) ;  // Ajoute la composante verte (décalage 8 bits)
        wRvb = wRvb | (wB) ;       // Ajoute la composante bleue (pas de décalage)
    }
    return (wRvb) ;
}

// (6) Fonction qui lit les valeurs RVB depuis le fichier PPM
void LireImagePPM (char * sNomImage,
                   unsigned int * * wTab,
                   unsigned int wHauteur,
                   unsigned wLargeur)
{
    char tampon[71] ;
    unsigned int wRouge(0);
    unsigned int wVert(0) ;
    unsigned int wBleu(0) ;
    unsigned int wRvb(0) ;
    ifstream monFichier(sNomImage, ios::in) ;

       // Lecture des; lignes 1, 2, 3
       for (int i (0); i <= 3; ++i)
       {
           monFichier.getline(tampon, 71, '\n') ;
       }

       // Boucle pour lire les valeurs RVB de chaque pixel
       for (unsigned int i = 0; i < wHauteur; ++i)
       {
           for (unsigned int j = 0; j < wLargeur; ++j)
           {
               // Lecture des couleurs
               monFichier >> wRouge >> wVert >> wBleu ;

               // Appel de la fonction RVB
               wRvb = RVB(wRouge, wVert, wBleu) ;

               // Stockage des valeurs RVB dans le tableau
               wTab[i][j] = wRvb  ;
           }
       }
       monFichier.close();
}

void AfficherCouleur(unsigned int couleur)
{
    if (couleur == ROUGE)
    {
        cout << "\033[31m.\033[0m "; // Rouge
    } else if (couleur == ROUGEFONCE)
    {
        cout << "\033[31;2m.\033[0m "; // Rouge foncé
    } else if (couleur == BLANC)
    {
        cout << "\033[37m.\033[0m "; // Blanc
    } // Ajouter d'autres couleurs si nécessaire
    else
    {
        cout << " "; // Couleur par défaut ou non reconnue
    }
}

// (7) Fonction pour afficher l'image à partir du tableau wTab
void AfficherImage(unsigned int * * wTab, unsigned int wHauteur, unsigned int wLargeur)
{
   // Boucle pour lire les valeurs RVB de chaque pixel
   for (unsigned int i = 0; i < wHauteur; ++i)
   {
       for (unsigned int j = 0; j < wLargeur; ++j)
       {
           AfficherCouleur(wTab[i][j]);
          }
          cout << endl;
   }
}

// (8)
unsigned int * * LibererTab2D( unsigned int ** wTab,
                            unsigned int wHauteur,
                            unsigned int wLargeur)
{

   if(wTab != nullptr)
   {
       for (unsigned int i (0); i < wHauteur; ++i)
       {
           for(unsigned int j (0); j < wLargeur; ++i)
           {
               wTab[i][j] = 0 ;
           }
       }

    for (unsigned int i (0); i < wHauteur; ++i)
    {
       if(wTab[i] != nullptr)
       {
           delete [] wTab[i] ;
           wTab = nullptr ;
       }
    }
    delete [] wTab ;
    wTab = nullptr ;
   }

   return wTab;
}
