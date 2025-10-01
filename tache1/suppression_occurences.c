#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule {
    int val;
    struct Cellule *next;
} Cellule;

/* Insert at tail (preserve input order) */
void insert_tail(Cellule **head, int value) {
    Cellule *c = malloc(sizeof(Cellule));
    if (!c) { perror("malloc"); exit(EXIT_FAILURE); }
    c->val = value;
    c->next = NULL;
    if (*head == NULL) {
        *head = c;
    } else {
        Cellule *t = *head;
        while (t->next) t = t->next;
        t->next = c;
    }
}

/* Delete all occurrences of 'x' */
void delete_occurrences(Cellule **head, int x) {
    while (*head && (*head)->val == x) {
        Cellule *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    Cellule *cur = *head;
    while (cur && cur->next) {
        if (cur->next->val == x) {
            Cellule *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        } else {
            cur = cur->next;
        }
    }
}

/* Print list */
void print_list(Cellule *head) {
    Cellule *p = head;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

/* Free whole list */
void free_list(Cellule *head) {
    Cellule *p;
    while (head) {
        p = head;
        head = head->next;
        free(p);
    }
}

int main(void) {
    Cellule *head = NULL;
    int n, x, i;

    puts("##########################    Hello !!!  ##########################");
    printf("Entrez le nombre d'elements a inserer:  ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Nombre invalide.\n");
        return 1;
    }

    for (i = 1; i <= n; ++i) {
        printf("Entrez la valeur %d:  ", i);
        if (scanf("%d", &x) != 1) {
            fprintf(stderr, "Entree invalide.\n");
            free_list(head);
            return 1;
        }
        insert_tail(&head, x);
    }

    print_list(head);

    /* Boucle de suppression : entrer -1 pour quitter */
    while (1) {
        printf("\nEntrez l'element a supprimer (ou -1 pour quitter) :  ");
        if (scanf("%d", &x) != 1) break;
        if (x == -1) break;
        delete_occurrences(&head, x);
        print_list(head);
    }

    free_list(head);
    return 0;
}
