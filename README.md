# Get Next Line (GNL)

## 📖 À propos du projet
**Get Next Line** est un projet de l'école 42. Le but est de créer une fonction en C qui permet de lire une ligne terminée par un retour à la ligne (`\n`) depuis un descripteur de fichier (`fd`). Ce projet introduit la notion de variables statiques et permet d'en apprendre davantage sur la gestion de la mémoire et les entrées/sorties en C.

## 🚀 Fonctionnalités
- Lecture ligne par ligne depuis un fichier, l'entrée standard ou tout autre descripteur de fichier valide.
- Gestion correcte de la mémoire (aucune fuite).
- Compilation avec une taille de buffer modulable via la macro `BUFFER_SIZE`.

## 🛠️ Prototype
```c
char *get_next_line(int fd);
```
- **Paramètre** : `fd` - Le descripteur de fichier (File Descriptor) sur lequel lire.
- **Valeur de retour** :
  - La ligne lue si tout se passe bien.
  - `NULL` s'il n'y a plus rien à lire ou si une erreur s'est produite.

## ⚙️ Compilation et Utilisation

Pour utiliser la fonction dans votre propre programme, vous devez compiler vos fichiers avec *get_next_line.c* et *get_next_line_utils.c*.

Vous pouvez définir la taille du buffer lors de la compilation :
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

### Exemple (`main.c`) :
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 👨‍💻 Auteur
Développé par [huburton](mailto:huburton@student.s19.fr) pour le cursus 42.