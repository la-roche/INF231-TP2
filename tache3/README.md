# 📂 Dossier Algorithmique

## 🔧 Problème

Insérer un nouvel élément dans une **liste doublement chaînée** tout en maintenant l’ordre trié des éléments.

---

## 💡 Principe

- Parcourir la liste à partir de la tête ou de la queue (selon le sens du tri).
- Trouver l’emplacement correct pour le nouvel élément.
- Créer une nouvelle cellule.
- Réajuster les deux pointeurs (`next` et `prev`) du nouveau nœud et des cellules adjacentes.
  
### 🧩 Cas particuliers :
- Insertion en tête.
- Insertion en milieu.
- Insertion en fin.
- Liste vide.

---

## 📘 Dictionnaire

| Terme                    | Définition |
|--------------------------|------------|
| **Liste doublement chaînée** | Liste où chaque cellule contient une valeur, un pointeur vers le précédent et un vers le suivant. |
| **Nœud**                 | Élément contenant les données et deux pointeurs (`prev`, `next`). |
| **Insertion triée**      | Ajout d’un élément dans une position respectant l’ordre des valeurs. |
| **Pointeur `prev`**      | Lien vers le nœud précédent. |
| **Pointeur `next`**      | Lien vers le nœud suivant. |

---

## 📈 Complexité

- ⏱️ **Temps moyen (et pire)** : `O(n)` – car il faut parcourir la liste pour trouver la bonne position.
- 💾 **Espace** : `O(1)` – pour l’opération d’insertion (hors mémoire du nouveau nœud).

---
