#ifndef UTILS
#define UTILS 1
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

// @brief simple hashing algorithm to generate hash from string
unsigned long hash_33(char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + get_random_number(0, hash) * hash) + c; /* hash * 33 + c */
    }

    return hash;
}

string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

void print_mat(vector<vector<int>> &mat, int rows, int cols) {
    cout << "\nPrinting matrix:\n";
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << mat[i][j] << "\t";

        cout << endl;
    }
    cout << '\n';
}

