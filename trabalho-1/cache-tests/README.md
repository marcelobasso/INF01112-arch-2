# Cache Tests

## Objetivos

Analisar o comportamento da memória principal e da memória cache através da execucao de 3 algoritmos:
- [X] Algoritmo de ordenacao (como QuickSort ou MergeSort)
- [X] Algoritmo de processamento de matrizes (como multiplicacao de matrizes)
- [X] Algoritmo de busca ou grafos (como busca em profundidade ou Dijkstra)

E, através desses, analisar as seguintes informacoes:
1. numero de ciclos
2. numero de instrucoes
3. numero de acessos a memoria cache L1D, L2, L3 (misses e hits)
4. numero de acessos a TLB (misses e hits)
5. e numero de acessos a memoria principal
   

### Perf params

1. cycles
2. instructions
3. L1-dcache-load-misses,L1-dcache-loads,L2-load-misses,L2-loads,LLC-load-misses,LLC-loads
   cache_misses
   cache_references
4. dTLB-load-misses,dTLB-store-misses,dTLB-stores
5. mem-loads,mem-stores

---

## Commands
~$ sudo perf mem record -a ./main <OPTION> <SIZE>
~$ sudo perf mem report
~$ perf mem -t load report --sort=mem
~$ perf stat -e <PARAMS> ./main <OPTION> <SIZE>

~$ sudo perf record -e cache-misses,cache-references ./main
~$ sudo perf stat -e dTLB-load-misses,dTLB-store-misses,dTLB-stores ./main
~$ sudo perf stat -e L1-dcache-load-misses,L1-dcache-loads,L2-load-misses,L2-loads,LLC-load-misses,LLC-loads

## Cache Info
Cache Level-1
Type: Data
Size: 32K
Number of Sets: 64
Ways of Associativity: 8
Coherence line-size: 64
 
Cache Level-1
Type: Instruction
Size: 32K
Number of Sets: 64
Ways of Associativity: 8
Coherence line-size: 64
 
Cache Level-2
Type: Unified
Size: 256K
Number of Sets: 1024
Ways of Associativity: 4
Coherence line-size: 64
 
Cache Level-3
Type: Unified
Size: 6144K
Number of Sets: 8192
Ways of Associativity: 12
Coherence line-size: 64

sudo perf stat -e L1-dcache-load-misses,L1-dcache-loads,L2-load-misses ./main
sudo perf stat -e L2-loads,LLC-load-misses,LLC-loads ./main

sudo perf stat -e cycles,instructions,cache-misses,cache-references ./main
sudo perf stat -e dTLB-load-misses,dTLB-store-misses,dTLB-stores ./main