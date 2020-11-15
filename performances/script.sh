#!/bin/bash
rm -f resultat_cat.dat
echo "# taille_tampon duree_execution vitesse_utilisateur vitesse_systeme" >> resultat_cat.dat
for((i = 1; i < (2**24);i=i*2)); do
       printf "Ecriture des resultats dans resultat_cat.dat pour le tampon de $i Octets \n"
       /usr/bin/time -f $i' %e %U %S' ./cat $i test > /dev/null 2>> resultat_cat.dat

  done

  cat <<EOM>> run.gnu
set title "Temps et vitesse d'execution"
set logscale x
set xlabel "Taille Tampon en Octets"
set logscale y
set ylabel "temps en s ou vitesse en octets/s"
set style data linespoints
set terminal png
set output "resultat_cat.png"
plot "resultat_cat.dat" using 1:2 title "duree", \
     "resultat_cat.dat" using 1:3 title "vitesse"
EOM
gnuplot run.gnu

rm -f resultat_mcat_lib.dat
echo "# taille_tampon duree_execution vitesse_utilisateur vitesse_systeme" >> resultat_mcat_lib.dat
for((i = 1; i < (2**24);i=i*2)); do
       printf "Ecriture des resultats dans resultat_mcat_lib.dat pour le tampon de $i Octets \n"
       /usr/bin/time -f $i' %e %U %S' ./mcat_lib $i test > /dev/null 2>> resultat_mcat_lib.dat

  done

cat <<EOM>> run.gnu
set title "Temps et vitesse d'execution"
set logscale x
set xlabel "Taille Tampon en Octets"
set logscale y
set ylabel "temps en s ou vitesse en octets/s"
set style data linespoints
set terminal png
set output "resultat_mcat_lib.png"
plot "resultat_mcat_lib.dat" using 1:2 title "duree", \
     "resultat_mcat_lib.dat" using 1:3 title "vitesse"
EOM
gnuplot run.gnu

eog resultat_cat.png
