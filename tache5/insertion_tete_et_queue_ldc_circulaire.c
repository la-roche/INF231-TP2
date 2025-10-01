#include <stdio.h>
#include <stdlib.h>

//structure liste double
typedef struct Cellule{
    int val;
    struct Cellule *suiv;
    struct Cellule *prec;
}Cellule;
typedef  Cellule* ListeD;


// Insertion en tête
ListeD inserer_tete_liste_double_circulaire(ListeD L, int n){
    int i, val;
    ListeD p;
    for (i=1; i<=n; i++){
        printf("Entrer une valeur a inserer en tete:\n");
        scanf("%d", &val);
        p=(ListeD)malloc(sizeof(Cellule));
        p->val=val;
        if (L==NULL){
            p->suiv=p;
            p->prec=p;
            L=p;
        }
        else{
            p->suiv=L;
            p->prec=L->prec;
            L->prec->suiv=p;
            L->prec=p;
            L=p; 
        }
    }
    return L;
}

// Insertion en queue
ListeD inserer_queue_liste_double_circulaire(ListeD L, int n){
    int i, val;
    ListeD p;
    for (i=1; i<=n; i++){
        printf("Entrer une valeur a inserer en queue:\n");
        scanf("%d", &val);
        p=(ListeD)malloc(sizeof(Cellule));
        p->val=val;
        if (L==NULL){
            p->suiv=p;
            p->prec=p;
            L=p;
        }
        else{
            p->suiv=L;         
            p->prec=L->prec;   
            L->prec->suiv=p;   
            L->prec=p;         
        }
    }
    return L;
}

// Affichage
void afficher_liste_double_circulaire(ListeD L){
    if (L==NULL){
        printf("Liste vide\n");
        return;
    }
    ListeD p=L;
    printf("Affichage de la liste :\n");
    do{
        printf("%d -> ", p->val);
        p=p->suiv;
    }
    while (p!=L);
    printf("(retour a la tete)\n");
}


int main(){
    ListeD L = NULL;
    int n;

    printf("Entrer le nombre d'elements a inserer en tete:\n");
    scanf("%d", &n);
    L = inserer_tete_liste_double_circulaire(L, n);
    afficher_liste_double_circulaire(L);

    printf("\nEntrer le nombre d'elements a inserer en queue:\n");
    scanf("%d", &n);
    L = inserer_queue_liste_double_circulaire(L, n);
    afficher_liste_double_circulaire(L);

    return 0;
}
