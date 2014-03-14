#!/bin/sh
set -ve

make generator

./generator 1 1 > ../in/01-01.txt
./generator 1 2 > ../in/01-02.txt
./generator 1 3 > ../in/01-03.txt
./generator 1 4 > ../in/01-04.txt
./generator 1 5 > ../in/01-05.txt

./generator 2 1 > ../in/02-01.txt
./generator 2 2 > ../in/02-02.txt
./generator 2 3 > ../in/02-03.txt
./generator 2 4 > ../in/02-04.txt
./generator 2 5 > ../in/02-05.txt

for st in 01 02; do
  for i in 01 02 03 04 05; do
    touch ../out/$st-$i.txt
  done
done
