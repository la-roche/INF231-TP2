# Dossier Algorithmique : Liste Chaînée Circulaire Simple avec Insertion en Tête et en Queue

## 1. Problème
Créer et gérer une **liste simplement chaînée circulaire** en C, permettant :  
- L’insertion d’éléments en tête de liste.  
- L’insertion d’éléments en queue de liste.  
- L’affichage complet de la liste en conservant sa circularité.  

L’utilisateur définit le nombre total d’éléments et choisit combien insérer en tête et combien en queue.

---

## 2. Principe (Algorithme)
1. **Initialisation** : La liste est vide (`tête = NULL`).  
2. **Insertion en tête** :  
   - Créer un nouveau nœud.  
   - Si la liste est vide, le nœud pointe vers lui-même et devient la tête.  
   - Sinon :  
     - Parcourir la liste jusqu’au dernier nœud (celui qui pointe vers la tête).  
     - Relier le nouveau nœud à l’ancienne tête.  
     - Relier le dernier nœud au nouveau nœud.  
     - Mettre à jour la tête pour qu’elle pointe sur le nouveau nœud.  
3. **Insertion en queue** :  
   - Créer un nouveau nœud.  
   - Si la liste est vide, le nœud pointe vers lui-même et devient la tête.  
   - Sinon :  
     - Parcourir jusqu’au dernier nœud.  
     - Relier le dernier nœud au nouveau nœud.  
     - Relier le nouveau nœud à la tête.  
4. **Affichage** :  
   - Si la liste est vide, afficher un message.  
   - Sinon, parcourir la liste à partir de la tête et afficher chaque valeur jusqu’à revenir à la tête.  
5. **Interaction avec l’utilisateur** :  
   - Demander le nombre total d’éléments.  
   - Demander combien insérer en tête et en queue.  
   - Lire les valeurs et les insérer selon le choix.  
   - Afficher la liste finale.

---

## 3. Dictionnaire de données

| Variable | Type | Description |
|----------|------|------------|
| `cellule` | `struct` | Structure représentant un nœud de la liste, avec `val` et `suiv`. |
| `tête` | `cellule*` | Pointeur vers le premier élément de la liste circulaire. |
| `valeur` | `int` | Valeur à insérer dans un nœud. |
| `nb_tete` | `int` | Nombre de valeurs à insérer en tête. |
| `nb_queue` | `int` | Nombre de valeurs à insérer en queue. |
| `n` | `int` | Nombre total de valeurs à insérer. |
| `p` | `cellule*` | Pointeur utilisé pour parcourir la liste. |
| `i` | `int` | Indice de boucle pour les saisies et parcours. |

---

## 4. Complexité

- **Temps :**  
  - Insertion en tête : `O(n)` dans le pire cas (parcours du dernier nœud).  
  - Insertion en queue : `O(n)` dans le pire cas.  
  - Affichage : `O(n)` pour parcourir tous les nœuds.  
  - Global pour `n` insertions : `O(n²)` si insertion répétée en tête ou en queue car chaque insertion nécessite parfois un parcours complet.  

- **Mémoire :**  
  - `O(n)` pour `n` nœuds.  
  - Chaque nœud contient un entier et un pointeur vers le suivant.
