#!/bin/bash
set -eu

make data

rm -rf desempenho

mkdir desempenho
mkdir desempenho/memSizeConst
mkdir desempenho/memSizeConst/logs/
mkdir desempenho/pageSizeConst
mkdir desempenho/pageSizeConst/logs/

declare -a commandStart=(
  "./genData fifo logs/compilador.log"
  "./genData fifo logs/compressor.log"
  "./genData fifo logs/matriz.log"
  "./genData fifo logs/simulador.log"
  "./genData lefe logs/compilador.log"
  "./genData lefe logs/compressor.log"
  "./genData lefe logs/matriz.log"
  "./genData lefe logs/simulador.log"
  "./genData lru logs/compilador.log"
  "./genData lru logs/compressor.log"
  "./genData lru logs/matriz.log"
  "./genData lru logs/simulador.log"
)

declare -a memSizes=(128 256 512 1024 2048 4096 8192 16384)

declare -a pageSizes=(2 4 8 16 32 64)

echo "Calculando tempos quando o tamanho da memória cresce, mas pageSize permanece igual a 4 KB ..."

for start in "${commandStart[@]}"
do
  for memSize in "${memSizes[@]}"
  do
    command="${start} 4 ${memSize} pageConst"
    echo "${command}"
    for j in {1..100}
    do 
      eval $command
    done
  done
done

echo "Calculando tempos quando o tamanho da memória permanece constante e igual a 2048, mas pageSize varia de 2 a 64 (pot2)..."

for start in "${commandStart[@]}"
do
  for pageSize in "${pageSizes[@]}"
  do
    command="${start} ${pageSize} 2048 memConst"
    echo "${command}"
    for j in {1..100}
    do 
      eval $command
    done
  done
done

exit 0
