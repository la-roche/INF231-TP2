#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

/* Insert at tail (preserve input order) */
void insert_tail(Node **head, int value) {
    Node *n = malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->val = value;
    n->next = NULL;
    if (*head == NULL) {
        *head = n;
    } else {
        Node *t = *head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

/* Delete all occurrences of 'x' */
void delete_occurrences(Node **head, int x) {
    while (*head && (*head)->val == x) {
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    Node *cur = *head;
    while (cur && cur->next) {
        if (cur->next->val == x) {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        } else {
            cur = cur->next;
        }
    }
}

/* Print list */
void print_list(Node *head) {
    Node *p = head;
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("\n");
}

/* Free whole list */
void free_list(Node *head) {
    Node *p;
    while (head) {
        p = head;
        head = head->next;
        free(p);
    }
}

int main(void) {
    Node *head = NULL;
    int n, x, i;

    puts("##########################    Hello !!!  ##########################");
    printf("Entrez le nombre d'elements a inserer:  ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Nombre invalide.\n");
        return 1;
    }

    for (i = 1; i <= n; ++i) {
        printf("Entrez la valeur %d:  ", i);
        if (scanf("%d", &x) != 1) { fprintf(stderr, "Entree invalide.\n"); free_list(head); return 1; }
        insert_tail(&head, x);
    }

    print_list(head);

    /* Boucle de suppression : entrer -1 pour quitter */
    while (1) {
        printf("\nEntrez l'element a suprimer (ou -1 pour quitter) :  ");
        if (scanf("%d", &x) != 1) break;
        if (x == -1) break;
        delete_occurrences(&head, x);
        print_list(head);
    }

    free_list(head);
    return 0;
}
