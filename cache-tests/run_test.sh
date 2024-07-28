REQUIRED_INFO="instructions,
               cycles,
               cache-references,
               cache-misses,
               mem_load_retired.l1_hit,
               mem_load_retired.l1_miss,
               mem_load_retired.l2_hit,
               mem_load_retired.l2_miss,
               mem_load_retired.l3_hit,
               mem_load_retired.l3_miss,
               mem-loads,
               mem-stores"


if [ -z $1 ]; then
    echo "Pass an argument:"
    echo "  S - for array sorting"
    echo "  M - for matrix multiplication"
    echo "  G - for DFS on graph"
    exit 1
fi

if [ -z $2 ]; then
    echo "Pass a size according to the algorithm ur executing"
    exit 1
fi

if [ "$1" != "S" -a "$1" != "M" -a "$1" != "G" ]; then
    echo "ERROR: argument passed is not an option"
    exit 1
fi

echo "Compilling code..."
g++ src/utils.cpp main.cpp -o main

# if verbose mode
echo "Runing tests for option $1..."
sudo perf stat -e ${REQUIRED_INFO//[$'\t\r\n ']} ./main $1 $2


