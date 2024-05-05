#ifndef CONSTANST
#define CONSTANTS 1
#include "src/constants.h"
#include "src/utils.h"
#endif

// -----------------------------------------------------------------------
// Algoritmo de ordenação em array (stable quicksort)
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

// @param magnitude: number of elements in array (power of 10)
void sort_rand_array(int magnitude) {
    srand(time(NULL));
    vector<pair<int, unsigned long>> v;
    int n;
    char c;

    // populates vector with 10^magnitude entries
    for (int i = 0; i < pow(10, magnitude); i++) {    
        n = get_random_number(0, pow(10, magnitude));
        c = char(n);

        // Convert the hash value to a string using std::to_string
        unsigned long hashString = hash_33(&c);

        v.push_back(pair<int, unsigned long>(n, hashString));
    }

    // runs quicksort on vector
    stable_quicksort(v, 0, pow(10, magnitude));
}

// -----------------------------------------------------------------------
// Algoritmo de multiplicacao de matrizes
// -----------------------------------------------------------------------

void print_mat(vector<vector<int>> &mat, int rows, int cols) {
    cout << "\nPrinting matrix:\n";
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << mat[i][j] << "\t";

        cout << endl;
    }
    cout << '\n';
}

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
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            mat1[i][j] = get_random_number(0, cols);
            mat2[i][j] = get_random_number(0, cols);
        }
    }

    mult_mat(mat1, mat2, rows, cols);
}


// -----------------------------------------------------------------------
// Algoritmo de caminhamento em grafo
// -----------------------------------------------------------------------

typedef struct node {
    string name;
    vector<struct node*> edges;
} Node;

// adds an edge
void addEdge(Node *n, string name) {
    Node *edge = (Node *) malloc(sizeof(Node));

    edge->name = name;
    n->edges.push_back(edge);
}

// // runs dfs
// void DFS(Node *v) {
//     map<string, bool> visited;
//     map<string, vector<Node *>> adj;

//     visited[v->name] = true;
//     cout << v->name << " ";
 
//     // Recur for all the vertices adjacent
//     // to this vertex
//     vector<string>::iterator i;
//     for (i = adj[v->name].begin(); i != adj[v->name].end(); ++i)
//         if (!visited[*i])
//             DFS(*i);

// }

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "Pass an argument\nS - for array sorting\nM - for matrix multiplication\nG - for DFS on graph\n";
        return 1;
    }

    switch (*argv[1]) {
        case 'S':
            sort_rand_array(6);
            break;
        
        case 'M':
            mult_rand_matrix(ROWS, COLS);
            break;

        default:
            cout << "ERROR: argument passed is not an option\n";
    }

    return 0;
}