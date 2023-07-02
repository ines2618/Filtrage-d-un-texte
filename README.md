# Filtrage-texte (Text Filtering)

**English Version**


**Introduction**

The objective of this assignment was to create an efficient text filtering algorithm using binary search trees. We paid particular attention to the filtering function in order to optimize its performance.

**Implementation**

To implement our text filtering algorithm, we divided our program into two distinct modules:

1. ABR Module (Binary Search Tree): This module contains all the functions for processing binary search trees. It includes operations such as node insertion, node search, tree traversal, and more. These functions allow us to construct and manipulate the binary search trees "arbre" and "filtre".

2. Filtrage Module: This module contains functions specific to filtering the "arbre" and "filtre" trees. It includes functions such as root comparison, recursion on sub-trees, PDF file creation, and displaying results according to the specified criteria.

By modularizing our program, we were able to separate the logic for processing binary search trees from the specific logic for text filtering.

**Description**

To compile the entire program, you can use the makefile by executing the command "make filtre".

During program execution, the user can enter the "-v" option in any order, but it is important to respect the following order when entering the files: "texte.txt" followed by "filtre.txt".

These instructions will efficiently filter the text and generate PDF files if the "-v" option is used. The program will also display words that are present only in the text and words that are common to both, following the specified format.

Thank you for your attention!


-------------------------------------------------------------------------------------------------------------------

**French version**

**Introduction**

L'objectif de ce devoir était de créer un algorithme de filtrage de texte efficace en utilisant des arbres binaires de recherche. Nous avons accordé une attention particulière à la fonction de filtrage pour optimiser sa performance.

**Implémentation**

Pour implémenter notre algorithme de filtrage, nous avons divisé notre programme en deux modules distincts :

Module ABR (Arbre Binaire de Recherche) : Ce module contient toutes les fonctions de traitement des arbres binaires de recherche. Il inclut des opérations telles que l'insertion d'un nœud, la recherche d'un nœud, le parcours de l'arbre, etc. Ces fonctions nous permettent de construire et de manipuler les arbres binaires de recherche "arbre" et "filtre".

Module Filtrage : Ce module contient les fonctions spécifiques au filtrage des arbres "arbre" et "filtre". Il inclut des fonctions telles que le comparatif des racines, la récursivité sur les sous-arbres, la création des fichiers PDF, et l'affichage des résultats selon les critères demandés.

Grâce à la modularité de notre programme, nous avons pu séparer la logique du traitement des arbres binaires de recherche de la logique spécifique au filtrage des textes.


**Description**

Pour compiler l'ensemble du programme, vous pouvez utiliser le makefile en exécutant la commande "make filtre".

Lors de l'exécution du programme, l'utilisateur peut entrer l'option "-v" dans n'importe quel ordre, mais il est important de respecter l'ordre suivant lors de la saisie des fichiers : "texte.txt" puis "filtre.txt".

Ces instructions permettront de filtrer efficacement le texte et de générer des fichiers PDF en cas d'utilisation de l'option "-v". Le programme affichera également les mots présents uniquement dans le texte et les mots communs aux deux, en suivant le format spécifié dans le sujet.

Merci de votre attention ! 

