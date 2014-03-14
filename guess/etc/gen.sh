#!/bin/sh

for i in 01 02 03 04 05 06 07 08 09 10
do
  ./gen 1 $i > ../'in'/01-${i}.txt
  ../sol/sol < ../'in'/01-${i}.txt > ../out/01-${i}.txt
done
for i in 01 02 03 04 05 06 07 08 09 10
do
  ./gen 2 $i > ../'in'/02-${i}.txt
  ../sol/sol < ../'in'/02-${i}.txt > ../out/02-${i}.txt
done
