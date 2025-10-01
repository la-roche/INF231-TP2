//liste simple:

#include <stdio.h>
#include <stdlib.h>

// Définition de la cellule:
struct cellule {
    int val;
    struct cellule* suiv;
};
typedef struct cellule* liste;

// Insertion triée dans une liste simplement chaînée
liste insertion_liste_triee(liste l, int x) {
    // Création du nouveau nœud
    liste nouveau = (liste)malloc(sizeof(liste));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    nouveau->val = x;
    nouveau->suiv = NULL;

    // Cas 1 : Liste vide ou insertion en tête
    if (l == NULL || x < l->val) {
        nouveau->suiv = l;
        l=nouveau;
        printf("Opération réussie!\n");
        return l;
    }

    // Cas 2 : Insertion au milieu ou à la fin
    liste courant = l;
    while (courant->suiv != NULL && courant->suiv->val < x) {
        courant = courant->suiv;
    }
    nouveau->suiv = courant->suiv;
    courant->suiv = nouveau;

    printf("Opération réussie!\n");
    return l;
}

// Affichage de la liste
void affiche_liste(liste l) {
    int a=0;
    if (l == NULL) {
        printf("Liste vide!\n");
        return 0;
    }

    liste courant = l;
    while (courant != NULL) {
            a=courant->val;
        printf("%d -> ",a );
        courant = courant->suiv;
    }
    printf("NULL\n");
}


int main() {
    liste maliste = NULL;

    maliste = insertion_liste_triee(maliste, 2);
    affiche_liste(maliste);

    maliste = insertion_liste_triee(maliste, 1);
    affiche_liste(maliste);

    maliste = insertion_liste_triee(maliste, 3);
    affiche_liste(maliste);

    maliste = insertion_liste_triee(maliste, 0);
    affiche_liste(maliste);

    maliste = insertion_liste_triee(maliste, 4);
    affiche_liste(maliste);

    return 0;
}
