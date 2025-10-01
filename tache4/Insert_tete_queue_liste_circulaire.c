#include<stdio.h>
#include<stdlib.h>


typedef struct cellule {
int val;
struct cellule *suiv;
} cellule ;
void inserer_tete(cellule **tête,int val){
  cellule*new = (cellule*)malloc(sizeof(cellule));
  new->val = val;
  if(*tête == NULL){
  new->suiv = new;
  *tête = new;
  }
  else{
  cellule *p = *tête ;
  while (p->suiv != *tête ){
  p = p->suiv ;
  }
  new->suiv = *tête ;
  p->suiv = new;
  *tête = new;
  }
}

void inserer_queue(cellule **tête, int val){
cellule*new = (cellule*)malloc (sizeof(cellule));
new->val = val;
if (*tête == NULL){
new->suiv = new;
*tête = new;
}
else {
cellule *p = *tête ;
while (p->suiv != *tête ){
p = p->suiv;
} 
p->suiv = new ;
new->suiv = *tête ;
 }
}
void afficher(cellule *tete) {
    if (tete == NULL) {
        printf("Liste vide.\n");
        return;
    }

    cellule *p = tete;
    printf("Contenu de la liste : ");
    do {
        printf("%d ", p->val);
        p = p->suiv;
    } while (p != tete);
    printf("\n");
}

int main() {
    cellule *liste = NULL;
    int n, i, valeur, nb_tete, nb_queue;
    printf("#####LISTE CHAÎNÉES SIMPLEMENT CIRCULAIRES#####\n\n\n");
    printf("Combien de valeurs voulez-vous inserer au total ? \n");
    scanf("%d", &n);
    
    printf("Combien de valeurs voulez-vous inserer en tete ? ");
    scanf("%d", &nb_tete);
    

    nb_queue = n - nb_tete;
    printf("Donc il restera %d valeurs a inserer en queue.\n\n\n", nb_queue);

    // 🔼 Saisie des valeurs à insérer en tête
    for (i = 0; i < nb_tete; i++) {
        printf("Entrez la valeur %d a inserer en tete : \n", i + 1);
        scanf("%d", &valeur);
        inserer_tete(&liste, valeur);
    }

    // 🔽 Saisie des valeurs à insérer en queue
    for (i = 0; i < nb_queue; i++) {
        printf("Entrez la valeur %d a inserer en queue : \n", i + 1);
        scanf("%d", &valeur);
        inserer_queue(&liste, valeur);
    }

    printf("\n✅ Liste finale :\n");
    afficher(liste);

    return 0;
}
    