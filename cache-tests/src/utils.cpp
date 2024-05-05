#ifndef CONSTANST
#define CONSTANTS 1
#include "constants.h"
#include "utils.h"
#endif


int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void swap_quick(vector<pair<int, unsigned long>>& v, int i, int j) {
    pair<int, unsigned long> temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void print_vector(vector<pair<int, unsigned long>> &v) {
    for (pair<int, unsigned long> element : v) {
        cout << element.first << " " << element.second << "\n";
    }
}

// @brief simple hashing algorithm to generate hash from int value
unsigned long hash_33(char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + get_random_number(0, hash) * hash) + c; /* hash * 33 + c */
    }

    return hash;
}


