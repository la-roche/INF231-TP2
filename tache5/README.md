# 📂 Dossier Algorithmique : Liste doublement chaînée circulaire

## 1. Problème

Élaborer des algorithmes permettant :\
- d'insérer un élément en **tête** d'une liste doublement chaînée
circulaire,\
- d'insérer un élément en **queue** d'une liste doublement chaînée
circulaire,\
- puis d'afficher la liste obtenue.

------------------------------------------------------------------------

## 2. Principe

-   Une liste doublement chaînée circulaire est composée de maillons
    contenant :

    -   une valeur,\
    -   un pointeur vers le suivant,\
    -   un pointeur vers le précédent.

-   **Insertion en tête** :\
    Créer un nouveau maillon et l'insérer avant la tête, puis mettre à
    jour la tête.

-   **Insertion en queue** :\
    Créer un nouveau maillon et l'insérer après le dernier élément
    (juste avant la tête). La tête reste inchangée.

------------------------------------------------------------------------

## 3. Dictionnaire de données

-   `ListeD` : pointeur vers une cellule (type `Cellule`).\
-   `Cellule` : structure contenant :
    -   `int val` : la valeur stockée,\
    -   `Cellule* suiv` : pointeur vers la cellule suivante,\
    -   `Cellule* prec` : pointeur vers la cellule précédente.
-   `L` : pointeur vers la tête de la liste.\
-   `n` : nombre d'éléments à insérer.\
-   `val` : valeur saisie par l'utilisateur.\
-   `p` : pointeur temporaire pour parcourir ou créer un maillon.

------------------------------------------------------------------------

## 4. Algorithme

### **Insertion en tête**

``` text
Fonction inserer_tete(L, n)
  Pour i ← 1 à n faire
      Lire val
      Allouer p
      p.val ← val
      Si L = NULL alors
          p.suiv ← p
          p.prec ← p
          L ← p
      Sinon
          p.suiv ← L
          p.prec ← L.prec
          L.prec.suiv ← p
          L.prec ← p
          L ← p
      FinSi
  FinPour
  Retourner L
FinFonction
```

------------------------------------------------------------------------

### **Insertion en queue**

``` text
Fonction inserer_queue(L, n)
  Pour i ← 1 à n faire
      Lire val
      Allouer p
      p.val ← val
      Si L = NULL alors
          p.suiv ← p
          p.prec ← p
          L ← p
      Sinon
          p.suiv ← L
          p.prec ← L.prec
          L.prec.suiv ← p
          L.prec ← p
      FinSi
  FinPour
  Retourner L
FinFonction
```

------------------------------------------------------------------------

### **Affichage**

``` text
Procédure afficher(L)
  Si L = NULL alors
      Écrire "Liste vide"
  Sinon
      p ← L
      Répéter
          Écrire p.val
          p ← p.suiv
      Jusqu’à (p = L)
  FinSi
FinProcédure
```

------------------------------------------------------------------------

## 5. Complexité

-   **Insertion en tête** : O(1)\
-   **Insertion en queue** : O(1) (accès direct via L-\>prec)\
-   **Affichage** : O(n), avec *n* la taille de la liste.
