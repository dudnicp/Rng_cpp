# TP1 Modélisation et Programation

Classe Dvector : Constructeurs et premières fonctions.

## Logiciels nécessaires

- C++11 ou supérieur
- CMake 2.8 ou supérieur
- Doxygen (facultatif, sert à générer la documentation)

## Génération des Makefiles à l'aide de Cmake

Depuis la racine du projet:

```bash
cd build
cmake ..
```

## Utilisation

Commandes à lancer depuis le répertoire **build** du projet

- Compiler les executables de tests, les exemples ainsi que la documentation du projet

```bash
make all
```

ou tout simplement

```bash
make
```

- Générer la documentation du projet

```bash
make doc

- Lancer les tests unitaires sur les méthodes de la classe Dvector

  ```bash
  make test
  ```

  Equivalent:  

  ```bash
  make check
  ```

- Executer des examples
Plusieurs exemples sont à disposition (principalement pour répondre aux questions du TP) : DemoQ1 et DemoComplete.
Après compliation, toujours depuis **build**

```bash
examples/<nom_exemple>
```

- Supprimer les executables compilés

```bash
make clean
```

## Auteurs

Paul Dudnic & Adrien Deleplace
