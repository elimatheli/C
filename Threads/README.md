#   Processus légers

Ce dépôt correspond aux TP de PDS sur le thème
« [Processus légers](https://www.fil.univ-lille1.fr/~hym/e/pds/tp/tdth1.html) ».


##  Membre du Binôme

**Membre du binôme : Eliot Viseux**

## Rapport Compteur GC

### le fichier makefile

le fichier comporte la commande `make tout` pour tout construire ou `make <nom du fichier>` pour chaque fichier dans le dossier source, la commande `make realclean` pour supprimer les fichiers.

#### Pour construire :
```bash 
make tout
```

#### Pour Lancer le script :

```bash 
./script.sh
```

#### Pour supprimer :
```bash 
make realclean
```


### Compte-rendu Stat

Le but de cet exercice était de se servir au mieux de la capacité des `Thread` pour calculer le nombre de G et C dans un génome.
`man pthreads`
pour savoir comment fonctionne cette structure et la particularité de la fonction thread avec une entête `static void * function (void * data)`

Le résultat attendu après avoir fait le script avec gnuplot.

![Alt text](schema_UDP.png?raw=true "res.png")

Nous pouvons voir que **plus on créé de thread moins le temps en fonction de la taille du génome est élevé.**
## Rendez-vous

Il s’agit de l’exercice [Rendez-vous].

[Rendez-vous]: https://www.fil.univ-lille1.fr/~hym/e/pds/tp/tdth1-003.html#sec4

`rdv.c`
:   code initial pour l’exercice du rendez-vous


## Travail à faire

Les objectifs sont, successivement, de :

-   compléter la version à processus légers,
-   faire une variante, `rdv3.c`, à 3 processus légers,
-   faire une variante généralisée, `rdvn.c`, avec un nombre
    arbitraire de processus légers (vous ajouterez une constante
    `#define N` qui sera le nombre de processus légers à déclencher et
    vous changerez la fonction déclenchée dans les _threads_ pour
    qu’elle prenne en argument le numéro du processus légers, sur le
    modèle des fonctions `a` et `b`).
