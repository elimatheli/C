#!/bin/bash
rm -f res.dat
rm -f run.gnu
echo "# taille_genome nombre_thread temps" >> res.dat

for ((i = 100; i < (10**9);i=i*10)); do
	./aleazard $i > test
	for ((j = 1; j <= (2**5);j=j*2)); do
	
       	printf "Ecriture des resultats dans res.dat pour un génome de $i et un nombre de thread de $j \n"
       	/usr/bin/time -f "$i $j %e" ./compteur-gc-thread test $j > /dev/null 2>> res.dat

 done
 done
 
cat <<EOM>> run.gnu
set logscale x
set dgrid3d 30,30
set pm3d
set hidden3d
set terminal png
set view 60, 290
set title "Temps Commande compteur-gc-thread"
unset grid
set xlabel "Taille Génome"
set ylabel "Nombre Thread"
set zlabel "Temps"
set output "res.png"
splot 'res.dat' using 1:2:3 with lines
EOM
gnuplot run.gnu
