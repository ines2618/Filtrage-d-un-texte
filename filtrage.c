#include "filtrage.h"

#ifndef __ABR__
#include "ABR.h"
#endif
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



int filtrage(Arbre *A, Arbre filtre, Arbre *utilise)
{   
   
    if (!(*A) || !filtre)
    {
        return 0;
    }
    if (strcmp((*A)->mot, filtre->mot) == 0)
    {
        ajout(utilise,(*A)->mot);
        suppression(A, (*A)->mot);
        return 1;
    }
    if (strcmp((*A)->mot, filtre->mot) > 0)
    {
        filtrage(&((*A)->fg), filtre, utilise);
        filtrage(A, filtre->fd, utilise);
    }
    else
    {
        filtrage(&((*A)->fd), filtre, utilise);
        filtrage(A, filtre->fg, utilise);
    }
    
    return 1;
}



void creePDF(char *nom, Arbre a)
{
    int len_dot = strlen(nom) + 4;
    char dot[len_dot];
    strcpy(dot, nom);
    strcat(dot, ".dot");

    dessine(dot, a);
    int len = 2 * strlen(dot) + 15;
    char cmd[len];
    strcpy(cmd, "dot -Tpdf ");
    strcat(cmd, dot);
    strcat(cmd, " -o ");
    strcat(cmd, nom);
    strcat(cmd, ".pdf");
    system(cmd);
}


void affichage(Arbre A, Arbre utilise)
{
    printf("Mots présents uniquement dans le texte de référence : \n");
    printf("----------------------------------------------------- \n");
    parcours_infixe(A);
    printf("\n");
    printf("Mots présents dans les deux textes : \n");
    printf("----------------------------------------------------- \n");
    parcours_infixe(utilise);
    printf("\n");
}




int main(int argc, char *argv[])
{
    Noeud *A = NULL;
    Noeud *filtri = NULL;
    Noeud *utilise = NULL;

    char *nom[2];
    int i = 1;
    int j = 0;
    int option_v = 0;

    if (argc == 1 || argc > 4)
    {
        printf("Vous devez reférencez au plus 3 arguments , les deux textes et l'option -v \n");
        exit(EXIT_FAILURE);
    }

    while (i != argc)
    {
        if (strcmp(argv[i], "-v") == 0)
        {
            option_v = 1;
            i++;
        }
        else
        {

            nom[j] = argv[i];
            j++;
            i++;
        }
    }

    FILE *texte = fopen(nom[0], "r");
    FILE *filtre = fopen(nom[1], "r");

    if (!texte || !filtre)
    {
        printf("Fichier introuvable \n");
        exit(EXIT_FAILURE);
    }

    //cas où la creation d'arbre a echoué
    if(cree_arbre(nom[0], &A)){
        if(!cree_arbre(nom[1], &filtri)){
            libere(&A);
            exit(EXIT_FAILURE);
        }
    }
    else{
        exit(EXIT_FAILURE);
    }

    if (!option_v)
    {
        filtrage(&A, filtri, &utilise);
    }
    else
    {
        creePDF(nom[0], A);
        creePDF(nom[1], filtri);
        filtrage(&A, filtri, &utilise);
        creePDF("Filtrage", A);
        creePDF("Commun", utilise);
    }

    affichage(A, utilise);


    fclose(texte);
    fclose(filtre);

    libere(&A);
    libere(&filtri);
    libere(&utilise);

    return 0;
}