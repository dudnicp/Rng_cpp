# TP1 Modélisation et Programmation

Classe Dvector : constructeurs et premières fonctions.

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

- Compiler les sources et les executables des tests et des exemples

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
  ```

  La documentation sera générée dans le dossier **doc/html** du projet. Le fichier index.html est le fichier racine de la documentation.

- Lancer les tests unitaires sur les méthodes de la classe Dvector

  ```bash
  make test
  ```

  Equivalent:  

  ```bash
  make check
  ```

  Ceci lancera l'execution de tous les tests et produira un apercu succinct du status de chaque test : PASSED ou FAILED.
  Pour plus d'informations sur un test, executer la commande

  ```bash
  test/<nom_test>
  ```

- Executer des examples

  Plusieurs exemples sont à disposition (principalement pour répondre aux questions du TP) : DemoQ1 et DemoComplete.

  ```bash
  examples/<nom_exemple>
  ```

- Supprimer les executables compilés

  ```bash
  make clean
  ```

## Auteurs

Adrien Deleplace & Paul Dudnic
