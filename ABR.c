#include "ABR.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 512


Noeud *alloue_noeud(char *mot)
{
    assert(mot != NULL);
    Noeud *new = (Noeud *)malloc(sizeof(Noeud));
    if (!new)
    {
        return NULL;
    }
    new->mot = (char *)malloc(sizeof(char)*(strlen(mot) + 1));
    
    if(!new->mot){
        free(new);
        return NULL;
    }
    
    strcpy(new->mot, mot);
    new->fd = new->fg = NULL;

    return new;
}

void parcours_infixe(Arbre A)
{
    if (A)
    {
        parcours_infixe(A->fg);
        printf("%s \n", A->mot);
        parcours_infixe(A->fd);
    }
}

Noeud *ajout(Arbre *A, char *mot)
{
    assert(mot != NULL);
    if (!(*A))
    {
        *A = alloue_noeud(mot);
        return *A;
    }
    if (strcmp((*A)->mot, mot) == 0)
    {
        return *A;
    }
    if (strcmp((*A)->mot, mot) > 0)
    {
        return ajout(&((*A)->fg), mot);
    }
    else
    {
        return ajout(&((*A)->fd), mot);
    }
}


Noeud *extrait_max(Arbre *A)
{
    Noeud *tmp = NULL;

    if (!(*A))
    {
        return *A;
    }
    if (!(*A)->fd)
    {
        tmp = *A;
        *A = (*A)->fg;
        tmp->fd = tmp->fg = NULL;
        return tmp;
    }
    return extrait_max(&((*A)->fd));
}


Noeud *suppression(Arbre *A, char *mot)
{
    assert(mot != NULL);
    Noeud *tmp = NULL;
    Noeud *max = NULL;
    if (!*A)
    {
        return *A;
    }
    if (strcmp((*A)->mot, mot) > 0)
    {
        return suppression(&((*A)->fg), mot);
    }
    if (strcmp((*A)->mot, mot) < 0)
    {
        return suppression(&((*A)->fd), mot);
    }
    tmp = *A;
    if (strcmp((*A)->mot, mot) == 0)
    {
        if (!(*A)->fd && !(*A)->fg)
        {
            // cas : feuille
            *A = NULL;
        }
        if (!(*A)->fd)
        {
            // cas 1 seul fils
            *A = (*A)->fg;
        }
        if (!(*A)->fg)
        {
            // cas 1 seul fils
            *A = (*A)->fd;
        }
        else
        {
            // cas deux fils
            max = extrait_max(&((*A)->fg));
            (*A)->mot = max->mot;
        }
    }
    return tmp;
}


void libere(Arbre *A)
{
    if(!(*A)){ 
        return ; 
    }

    libere(&((*A)->fg));
    libere(&((*A)->fd));
    free(((*A)->mot));
    (*A)->mot = NULL;
    free(*A);
    *A = NULL;
}




int cree_arbre(char *nom, Arbre *A)
{
    assert(nom != NULL);
    FILE *fichier = fopen(nom, "r");

    if (!fichier)
    {
        printf("Fichier introuvable \n");
        return 0;
    }

    char mot_lu[TAILLE+1];
    const char *delimiteur = " \n,;:.?!\"()-'";
    char *tokens = NULL;

    while (fgets(mot_lu, TAILLE, fichier) != NULL)
    {
        tokens = strtok(mot_lu, delimiteur);
        while (tokens != NULL)
        {
            if(!ajout(A,tokens)){
                //cas d'echec d'ajout
                libere(A);
                return 0;
            }
            tokens = strtok(NULL, delimiteur);
        }
    }

    fclose(fichier);
    
    return 1;
}

void ecrireDebut(FILE *f)
{
    fprintf(f, "digraph arbre { \n");
    fprintf(f, " \tnode [ shape = record , height = .1 ] \n");
    fprintf(f, "\tedge [ tailclip = false , arrowtail = dot , dir = both ]; \n");
}

void ecrireArbre(FILE *f, Arbre A)
{
    if (A)
    {
        fprintf(f, "\tn%p [ label = \"<gauche > | <valeur > %s | <droit>\"]; \n", A, A->mot);
        if (A->fg)
        {
            fprintf(f, "\tn%p : gauche : c -> n%p: valeur ;\n", A, A->fg);
        }
        if (A->fd)
        {
            fprintf(f, "\tn%p : droit : c -> n%p: valeur ; \n", A, A->fd);
        }
        ecrireArbre(f, A->fg);
        ecrireArbre(f, A->fd);
    }
}

void ecrireFin(FILE *f)
{
    fprintf(f, "}");
}

void dessine(char *nom, Arbre A)
{
    assert(nom != NULL);
    FILE *fichier = fopen(nom, "w");
    ecrireDebut(fichier);
    ecrireArbre(fichier, A);
    ecrireFin(fichier);
    fclose(fichier);
}
