
//iste dou_chainees:

#include <stdio.h>
#include <stdlib.h>

struct cellule {
    int val;
    struct cellule *suiv;
    struct cellule *prec;
};
typedef struct cellule *liste;

liste insertion_liste_triee(liste l, int x) {
    liste nouveau = (liste)malloc(sizeof(liste));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    nouveau->val = x;
    nouveau->suiv = NULL;
    nouveau->prec = NULL;

    // Cas 1 : Liste vide
    if (l == NULL) {
            l=nouveau;
        printf("Opération réussie!\n");
        return l;
    }

    // Cas 2 : Insertion en tête
    if (x < l->val) {
        nouveau->suiv = l;
        l->prec = nouveau;
         l=nouveau;
        printf("Opération réussie !\n");
        return l;
    }

    // Cas 3 : Insertion au milieu ou à la fin
    liste courant = l;
    while (courant->suiv != NULL && courant->suiv->val < x) {
        courant = courant->suiv;
    }

    nouveau->suiv = courant->suiv;
    nouveau->prec = courant;

    if (courant->suiv != NULL) {
        courant->suiv->prec = nouveau;
    }

    courant->suiv = nouveau;

    printf("Opération réussie!\n");
    return l;
}

void affiche_liste(liste l) {
    if (l == NULL) {
        printf("Liste vide!\n");
        return 0;
    }

    liste courant = l;
    while (courant != NULL) {
        printf("%d <-> ", courant->val);
        courant = courant->suiv;
    }
    printf("NULL\n");
}

int main() {
    liste maliste = NULL;
    affiche_liste(maliste);
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
