#ifndef FICHIER_PPM_H
#define FICHIER_PPM_H


// (1) Vérifie si le fichier est bien au format PPM, RVB 255.
bool EstPPM_RVB(char * sNomImage) ;

// (2) Procédure qui retourne les dimensions wHauteur et wLargeur de l’image.
void LirePPM_Dimensions( char * sNomImage,
                        unsigned int & wHauteur,
                        unsigned int & wLargeur) ;

// (3) Fonction qui verifie si les dimensions de l’image sont identiques
bool EstDeTaille ( char * sNomImage,
                 unsigned int wHauteur,
                 unsigned int wLargeur) ;


// (4) Fonction pour créer un tableau dynamique à deux dimensions
unsigned int * * CreerTableau2D(unsigned int wHauteur, unsigned int wLargeur) ;

// (5) Fonction pour combiner les composantes RVB dans un seul entier
unsigned int RVB(unsigned int wR, unsigned int wV, unsigned int wB) ;

// (6) Fonction qui lit les valeurs RVB depuis le fichier PPM
void LireImagePPM (char * sNomImage,
                   unsigned int * *wTab,
                   unsigned int wHauteur,
                   unsigned wLargeur) ;

void AfficherCouleur(unsigned int couleur) ;


// (7) Fonction pour afficher l'image à partir du tableau wTab
void AfficherImage(unsigned int **wTab, unsigned int wHauteur, unsigned int wLargeur) ;

// (8)
unsigned int * * LibererTab2D( unsigned int ** wTab,
                            unsigned int wHauteur,
                            unsigned int wLargeur) ;

#endif // FICHIER_PPM_H
