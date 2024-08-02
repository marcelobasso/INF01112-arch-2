#ifndef UTILS
#define UTILS 1
#include "src/utils.h"
#endif

// -----------------------------------------------------------------------
// Algoritmo de ordenação em array (stable quicksort)
// -----------------------------------------------------------------------

// 3 way partitioning quicksort: duplicate keys remain stable
void stable_quicksort(vector<int>& c, int lo, int hi) {
    int v = c[lo];
    int lt = lo, i = lo + 1, gt = hi;

    if (lo < hi) {
        while (i <= gt) {
            if (c[i] < v)
                swap_quick(c, lt++, i++);
            else if (c[i] > v)
                swap_quick(c, i, gt--);
            else i++;
        }

        stable_quicksort(c, lo, lt - 1);
        stable_quicksort(c, gt + 1, hi);
    }
}

// @param magnitude: number of elements in array (power of 10)
void sort_rand_array(int magnitude) {
    srand(time(NULL));
    vector<int> v;
    int n;

    // populates vector with 10^magnitude entries
    cout << "Populating vector with size 10^" << magnitude << endl;
    for (int i = 0; i < pow(10, magnitude); i++) {    
        n = get_random_number(0, pow(10, magnitude));
        v.push_back(n);
    }

    // runs quicksort on vector
    cout << "Running stable quicksort on vector...";
    stable_quicksort(v, 0, pow(10, magnitude));
}

// -----------------------------------------------------------------------
// Algoritmo de multiplicacao de matrizes
// -----------------------------------------------------------------------

void mult_mat(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int rows, int cols) {
    vector<vector<int>> rslt(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < rows; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void mult_rand_matrix(int rows, int cols) {
    int i, j;
    vector<vector<int>> mat1(rows, vector<int>(cols));
    vector<vector<int>> mat2(rows, vector<int>(cols));
    srand(time(NULL));

    // populates matrixes
    cout << "Populating matrix if size " << rows << " x " << cols << endl;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            mat1[i][j] = get_random_number(0, cols);
            mat2[i][j] = get_random_number(0, cols);
        }
    }

    cout << "Running matrix multiplication...";
    mult_mat(mat1, mat2, rows, cols);
}


// -----------------------------------------------------------------------
// Algoritmo de caminhamento em grafo
// -----------------------------------------------------------------------

Node* populateGraph(Node *n, int level) {
    if (level > 0) {
        n = new Node();
        n->name = gen_random(10);
        n->dir = populateGraph(n->dir, level - 1);
        n->esq = populateGraph(n->esq, level - 1);
    }

    return n;
}

// runs dfs
void DFS(Node *v) {
    string name = v->name;
    if (v->esq != nullptr) DFS(v->esq);
    if (v->dir != nullptr) DFS(v->dir);
}

// -----------------------------------------------------------------------
// funcao main
// -----------------------------------------------------------------------

int main(int argc, char **argv) {
    Node *root = NULL;
    int param = stoi(argv[2]);

    cout << "Int size: " << sizeof(int) << endl;

    if (argc == 1) {
        cout << "Pass an argument\nS - for array sorting\nM - for matrix multiplication\nG - for DFS on graph\n";
        return 1;
    }
    srand((unsigned)time(NULL) * getpid());

    switch (*argv[1]) {
        case 'S':
            sort_rand_array(param);
            break;
        
        case 'M':
            mult_rand_matrix(param, param);
            break;

        case 'G':
            cout << "Populating full tree of height " << param << endl;
            root = populateGraph(nullptr, param);
            cout << "Running DFS on graph..." << endl;
            DFS(root);
            break;

        default:
            cout << "ERROR: argument passed is not an option\n";
    }

    cout << endl;
    return 0;
}