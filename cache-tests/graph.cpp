#include "constants.h"
#include <map>

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

int main() {
    
    
    // populate and run DFS on graph

    return 0;
}