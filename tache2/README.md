# 1. Insertion dans une liste simplement chaînée triée

📌 **Problème**  
Insérer un nouvel élément dans une liste simplement chaînée de manière à maintenir l’ordre croissant (ou décroissant) des éléments.

🧠 **Principe**  
- Parcourir la liste à partir de la tête.  
- Trouver la position correcte où insérer le nouvel élément (en comparant les valeurs).  
- Créer un nouveau nœud.  
- Réajuster les pointeurs pour insérer le nœud sans casser la chaîne.  
- Cas particuliers à gérer :  
  - Insertion en tête (début de la liste).  
  - Insertion en milieu.  
  - Insertion en fin.  

📘 **Dictionnaire**  

| Terme                   | Définition                                                                 |
|--------------------------|-----------------------------------------------------------------------------|
| Liste simplement chaînée | Structure linéaire où chaque nœud contient une valeur et un pointeur vers le nœud suivant. |
| Nœud                     | Élément de la liste contenant une donnée et un pointeur.                   |
| Pointeur                 | Variable contenant l’adresse mémoire d’un autre élément.                   |
| Trié                     | Les éléments sont organisés selon un ordre croissant ou décroissant.       |
| Insertion                | Ajout d’un élément dans une structure tout en maintenant ses propriétés.   |

⏱️ **Complexité**  
- Temps moyen (et pire) : `O(n)`, où *n* est le nombre d’éléments dans la liste (car il faut potentiellement parcourir toute la liste pour trouver la bonne position).  
- Espace : `O(1)` pour l’opération d’insertion (hors espace pour le nouveau nœud).  

