# malloc
recode optimized Malloc with : mmap


Sujet



• La fonction malloc() alloue “size” octets de mémoire et retourne un pointeur sur
la mémoire allouée.

• La fonction realloc() essaye de modifier la taille de l’alloction pointée par “ptr”
à “size” octets, et retroune “ptr”. Si il n’y a pas assez de place à l’emplacement
mémoire pointé par “ptr”, realloc() crée une nouvelle allocation, y copie autant
de données de l’ancienne allocation que possible dans la limite de la taille de la
nouvelle allocation, libère l’ancienne allocation et retourne un pointeur sur cette
nouvelle allocation.

• La fonction free() libère l’allocation de la mémoire pointée par “ptr”. Si “ptr” vaut
NULL, free() ne fait rien.

• En cas d’erreur, les fonctions malloc() et realloc() retournent un pointeur NULL ;

• Vous devez utiliser les syscall mmap(2) et munmap(2) pour réclamer et rendre des
zones mémoire au système.

• Vous devez gérer vos propres allocations mémoires pour le fonctionnement interne
de votre projet sans utiliser la fonction malloc de la libc.

• Vous devez dans un soucis de performance limiter le nombre d’appel à mmap(),
mais aussi à munmap(). Vous devrez donc “pré-allouer” des zones mémoire pour
y stocker vos “petits” et “moyens” malloc.

• La taille de ces zones devra impérativement être un multiple de getpagesize().
• Chaque zone doit pouvoir contenir au moins 100 allocations.
◦ Les mallocs “TINY”, de 1 à n octets, seront stockés dans des zones de N octets
◦ Les mallocs “SMALL”, de (n+1) à m octets, seront stockés dans des zones de
M octets
◦ Les mallocs “LARGE”, de (m+1) octets et plus, seront stockés hors zone, c’est
à dire simplement avec un mmap(), ils seront en quelquesorte une zone à eux
tout seul.

• C’est à vous de définir la taille de n, m, N et M afin de trouver un bon compromis
entre vitesse (économie d’appel système) et économie de mémoire.
