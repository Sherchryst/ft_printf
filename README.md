#FT_printf

## Description

This project aims at rebuilding the printf library with basic functionality. I
tried to implement as much of the original as possible, and also have a few
extra things which I found to be rather useful.

Some choices were not intentional (some behaviors were replicated from OS X's
printf, others were not replicated).

Ce projet vise à reconstruire la bibliothèque printf avec des fonctionnalités de base. J'ai
essayé d'implémenter comme l'original, autant que possible, tout en l'optimisant un peu plus
en rajoutant ma touche personnelle.

Certains choix n'étaient pas intentionnels (certains comportements ont été reproduits à partir d'OS X
printf, d'autres n'ont pas été répliqués) et dans l'ensemble, le code est plus compliqué que je ne l'espérais. Au moins ça marche !

## Usage

```c
int   ft_printf(char const *str, ...)
```

``make`` will compile a ``libftprintf.a`` binary.
<br><br>
ft_printf works with :
* Conversions : ``c`` ``s`` ``p`` ``d`` ``i`` ``u`` ``x`` ``X`` ``%`` ``n``
* Flags : ``space`` ``#`` ``+`` ``0`` ``*`` ``-``
* Flags : ``l`` ``ll`` ``h`` ``hh``
* Minimum width
* Precision ``.``
