# TP1 Modélisation et Programation

Classe Dvector : Constructeurs et premières fonctions.

## Logiciels nécessaires

- C++11 ou supérieur
- CMake 2.8 ou supérieur
- Doxygen (facultatif, sert à générer la documentation)

## Génération des Makefiles à l'aide de Cmake

Depuis le répértoire source du projet:

```bash
cd build
cmake ..
```

## Utilisation

Commandes à lancer depuis le répertoire **build** du projet

- Génération de la documentation

```bash
make doc
```

- Démonstration courte montrant les différences entre les deux écritures

```C++
Dvector x;
x = Dvector(3, 1);
```

et

```C++
 Dvector x = Dvector(3, 1);
```

```bash
make demo
```

- Tests unitaires sur les méthodes de la classe **Dvector**

  - Apercu abrégé

  ```bash
  make test
  ```

  - Apercu complet

  ```bash
  make check
  ```

## Auteurs

Paul Dudnic & Adrien Deleplace
