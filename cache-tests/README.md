# Cache Tests

## Objetivos

Analisar o comportamento da memória principal e da memória cache através da execucao de 3 algoritmos:
- [X] Algoritmo de ordenacao (como QuickSort ou MergeSort)
- [X] Algoritmo de processamento de matrizes (como multiplicacao de matrizes)
- [X] Algoritmo de busca ou grafos (como busca em profundidade ou Dijkstra)

E, através desses, analisar as seguintes informacoes:
1. numero de ciclos - _cycles_
2. numero de instrucoes - _instructions_
3. numero de acessos a memoria cache L1D, L2, L3 (misses e hits) - ?
4. numero de acessos a TLB (misses e hits) - ?
5. e numero de acessos a memoria principal - ?
   

### suggested -e command flag 

instructions,cycles,llc misses.data read,llc misses.mem write

### Gethered Info

1. cycles
2. instructions
3. mem_load_retired.l1_hit,mem_load_retired.l1_miss,mem_load_retired.l2_hit,
   mem_load_retired.l2_miss,mem_load_retired.l3_hit,mem_load_retired.l3_miss
4. ?
5. ?