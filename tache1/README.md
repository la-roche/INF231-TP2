# Dossier Algorithmique : Suppression de toutes les occurrences d’un entier dans une liste chaînée (Insertion en queue)

## 1. Problème
Écrire un programme en C qui :  
- Lit un entier `n` et construit une **liste chaînée** avec `n` éléments, en **préservant l’ordre d’entrée**.  
- Lit des entiers `x` et supprime **toutes leurs occurrences** dans la liste.  
- Affiche la liste après chaque suppression.  
- La suppression se répète jusqu’à ce que l’utilisateur entre `-1`.

**Exemple :**  

Liste initiale : 4 -> 2 -> 3 -> 2 -> 5 -> NULL
Élément à supprimer : 2
Liste après suppression : 4 -> 3 -> 5 -> NULL
Élément à supprimer : -1
Fin du programme


---

## 2. Principe (Algorithme)

**Insertion des éléments (à la fin pour préserver l’ordre) :**  
1. Pour chaque valeur `val` saisie :  
   - Créer une cellule `Node` avec `val`.  
   - Si la liste est vide, cette cellule devient la tête.  
   - Sinon, parcourir la liste jusqu’à la fin et ajouter la cellule.  

**Suppression des occurrences de `x` :**  
1. Supprimer d’abord toutes les occurrences de `x` en tête de liste.  
2. Parcourir le reste de la liste avec un pointeur `cur`.  
3. Si `cur->next->val == x` : supprimer `cur->next` et mettre à jour les liens.  
4. Sinon, avancer `cur`.  
5. Répéter jusqu’à la fin de la liste.  

**Affichage :**  
- Parcourir la liste depuis la tête et afficher chaque élément suivi de `->`.  

**Libération mémoire :**  
- Parcourir la liste et libérer chaque cellule pour éviter les fuites mémoire.

---

## 3. Dictionnaire de données

| Variable | Type | Description |
|----------|------|------------|
| `Node` | struct | Structure représentant une cellule de la liste chaînée |
| `head` | `Node*` | Pointeur sur la tête de la liste |
| `n` | int | Nombre d’éléments à insérer |
| `x` | int | Valeur à insérer ou supprimer |
| `i` | int | Compteur de boucle |
| `cur` | `Node*` | Cellule courante lors de la suppression |
| `tmp` | `Node*` | Cellule temporaire pour libérer la mémoire |

---

## 4. Complexité

- **Insertion en queue :** O(n) pour `n` éléments (chaque insertion parcourt éventuellement toute la liste).  
- **Suppression :** O(m) pour `m` éléments dans la liste (chaque cellule visitée au maximum une fois).  
- **Affichage :** O(m) — parcours complet de la liste.  
- **Mémoire :** O(n) — une cellule par élément.
