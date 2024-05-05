#include "constants.h"

void swap_quick(vector<pair<int, unsigned long>>& v, int i, int j) {
    pair<int, unsigned long> temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// -----------------------------------------------------------------------
// Um algoritmo de ordenação (como QuickSort ou MergeSort)
// -----------------------------------------------------------------------

// 3 way partitioning quicksort: duplicate keys remain stable
void stable_quicksort(vector<pair<int, unsigned long>>& c, int lo, int hi) {
    pair<int, unsigned long> v = c[lo];
    int lt = lo, i = lo + 1, gt = hi;

    if (lo < hi) {
        while (i <= gt) {
            if (c[i].first < v.first)
                swap_quick(c, lt++, i++);
            else if (c[i].first > v.first)
                swap_quick(c, i, gt--);
            else i++;
        }

        stable_quicksort(c, lo, lt - 1);
        stable_quicksort(c, gt + 1, hi);
    }
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

unsigned long hash_33(char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + get_random_number(0, hash) * hash) + c; /* hash * 33 + c */
    }

    return hash;
}

void print_vector(vector<pair<int, unsigned long>> &v) {
    for (pair<int, unsigned long> element : v) {
        cout << element.first << " " << element.second << "\n";
    }
}

// @param magnitude: number of elements in array (power of 10)
void sortRandArray(int magnitude) {
    srand(time(NULL));
    vector<pair<int, unsigned long>> v;
    int n;
    char c;

    // populate array with 10^magnitude entries
    for (int i = 0; i < pow(10, magnitude); i++) {    
        n = get_random_number(0, pow(10, magnitude));
        c = char(n);

        // Convert the hash value to a string using std::to_string
        unsigned long hashString = hash_33(&c);

        v.push_back(pair<int, unsigned long>(n, hashString));
    }

    stable_quicksort(v, 0, pow(10, magnitude));
}