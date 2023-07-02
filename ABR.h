#define __ABR__

typedef struct noeud
{
    char *mot;
    struct noeud *fg, *fd;
} Noeud, *Arbre;


/// @brief alloue un noeud dont l'etiquette est mot
/// @param mot etiquette du noeud alloué
/// @return un noeud alloué si l'allocation s'est bien passé , NULL sinon
Noeud *alloue_noeud(char *mot);



/// @brief affiche le parcours infixe d'un arbre quelconque
/// @param a arbre binaire
void parcours_infixe(Arbre A);



/// @brief fonction qui ajoute dans l'arbre le mot passé en paramètre
/// @param A
/// @param mot
/// @return l'adresse du noeud crée si c'est possible
Noeud *ajout(Arbre *A, char *mot);



/// @brief extrait/supprime le plus grand mot contenu dans l'arbre
/// @param A
/// @return renvoie l'adresse du plus grand mot supprimé
Noeud *extrait_max(Arbre *A);



/// @brief supprime le plus grand mot que l'arbre contient
/// @param A
/// @return
Noeud *suppression(Arbre *A, char *mot);



/// @brief libère tout les noeuds contenu dans l'arbre *A
/// @param A
void libere(Arbre *A);



/// @brief crée un fichier pdf qui contiendra une representation graphique de l'arbre
/// @param nom que le fichier crée portera
/// @param A
void dessine(char *nom, Arbre A);



/// @brief gènere un ABR de recherche à partir d'un fichier
/// @param nom
/// @param A
/// @return 1 si l'arbre a bien été crée 0 sinn
int cree_arbre(char *nom, Arbre *A);