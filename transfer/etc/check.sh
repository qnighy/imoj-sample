#!/bin/sh
set -ve

make checker

for f in ../in/01-*.txt; do
  echo $f
  ./checker 1 < $f
done
for f in ../in/02-*.txt; do
  echo $f
  ./checker 2 < $f
done
