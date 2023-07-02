#include "ABR.h"


/// @brief cette fonction supprime de l’arbre *A tous les nœuds contenant un mot présent dans l’arbre *filtre et insère ce
/// mot dans l’ABR *utilises.
/// @param A (type Noeud ** car suppression effectué )
/// @param filtre (type Noeud * car  aucune operation ne sera effectué sur cette arbre)
/// @param utilise (type Noeud ** car on ajoutera les noeuds representant les mots contenu dans les deux textes)
/// @return 1 en cas de suppresion dans A , 0 sinon
int filtrage(Arbre *A, Arbre filtre, Arbre *utilise);

/// @brief fonction qui crée des fichiers pdf contenant une representation visuelle des arbres
/// @param nom nom du fichier via lequel on cree le pdf
/// @param a
void creePDF(char *nom, Arbre a);


/// @brief fonction qui affichera les mots contenu dans le texte de reference uniquement
/// ainsi que dans les deux textes sous le format donnée en exemple dans le sujet
/// @param A
/// @param utilise
void affichage(Arbre A, Arbre utilise);