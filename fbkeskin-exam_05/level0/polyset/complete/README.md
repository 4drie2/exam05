# polyset — dossier complet (compile en C++98 `-Wall -Wextra -Werror`)

## ✍️ À APPRENDRE (les 6 fichiers que TU écris à l'exam)

| Fichier | Contenu |
|---|---|
| `searchable_array_bag.hpp` / `.cpp` | hérite `array_bag` + `searchable_bag`, implémente `has()` (boucle) |
| `searchable_tree_bag.hpp` / `.cpp`  | hérite `tree_bag` + `searchable_bag`, implémente `has()` (BST itératif) |
| `set.hpp` / `.cpp`                  | enveloppe un `searchable_bag*`, dédoublonne à l'insert, OCF 4/4 |

## 📦 FOURNIS par l'exam (ici en version C++98-propre pour pouvoir compiler)

`bag.hpp`, `searchable_bag.hpp`, `array_bag.hpp/.cpp`, `tree_bag.hpp/.cpp`, `main.cpp`

> ⚠️ La moulinette fournit peut-être ces fichiers avec `nullptr` (C++11). Ici ils sont
> en `NULL` pour compiler en C++98. Le fix `copy_node void*→node*` (documenté par flmarsou)
> est déjà appliqué dans `tree_bag.hpp`. Tu ne rends PAS ces fichiers.

## ▶️ Tester

```
make
./polyset 5 3 8
```

Compile en `c++ -Wall -Wextra -Werror -std=c++98`. Les lignes `create node` /
`destroying value` / `duplicate value` viennent des fichiers fournis (normal).
