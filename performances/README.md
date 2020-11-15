#   Performances des entrées/sorties

Membre du binôme : ***Eliot Viseux***

## le fichier makefile

le fichier comporte la commande `make all` pour tout construire ( Avec le test) ou `make cat` Pour compiler ma version de cat, la commande `make clean` pour supprimer les fichiers compilés, les images PNG des graphiques.

### Pour construire :
```bash 
make all ( Tout construire avec les test inclus )
```
ou
```bash 
make cat
```
et
```bash 
make mcat
```

### Pour Tester :
```bash 
make test_perf
```
Cela va lancer le script *script.sh*, executer les commandes sur le fichier **test** fournit dans le dêpot et va générer un graphique avec gnuplot qui correspond aux temps celon la taille du tampon utilisé.


### Pour Lancer les commandes :

Une fois compilé pour cat :
```bash
./cat <taille du tampon en octets> <optionel fichier à lire>
```

Une fois compilé pour mcat-lib :
```bash
./mcat_lib <taille du tampon en octets> <optionel fichier à lire>
```

### Pour supprimer :
```bash 
make clean
```

# Compte-rendu Stat

Le but de cet exercice était de recréer la commande `cat` qui lit ou écrit dans un fichier avec comme argument une taille de tampon, puis ensuite d'utiliser la commande `time` dans /usr/bin/time pour comparer les différentes durées de la commande pour lire le fichier en fonction de la taille de tampon donné.

Pour cela, dans le script.sh, on crée une boucle for qui va augmenter la taille du tampon en le doublant de 1 octets à 8Mo (2^24 octets)
à chaque appel de la commande, on écrit le résultat dans des fichiers appelés *resultat_cat.dat* et *resultat_mcat_lib.dat* qui vont sauvegarder toutes les différentes vitesses pour chaque tampon.

A la fin de la boucle, le script gnu interprète les resultats et crée des graphiques nommés *resultat_cat.png* et *resultat_mcat_lib.png* et ouvre le premier fichier (avec eog si la commande est autorisée).

Le fichier sur lequel j'ai effectué mes test est le fichier *test* fournit avec le dêpot. c'est un fichier de 10Mo qui est assez gros pour avoir un résultat interprétable.
A la fin de la manipulation, en regardant le graphique nous pouvons voir que ***plus la taille du tampon augmente***, ***plus la vitesse de lecture du fichier est rapide pour cat***.
et
***a tendance à stagner pour la commande mcat-lib***.

**Les graphique resultat_cat.png** et **resultat_mcat_lib.png sont avec le dépôt.**

