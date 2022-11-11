#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
 
vector<int> adj[MAX];
int vis[MAX];
int Euler[2 * MAX];

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
} // pushing in both lists as it's an undirected graph

void eulerTree(int u, int &index) {
    vis[u] = 1;
    Euler[index++] = u;
    for (auto it : adj[u]) {
        if (!vis[it]) {
            eulerTree(it, index);
            Euler[index++] = u;
        }
    }
} // generate euler tree of indices

void calculateSum(int root, int N, int* tree) {
    int index = 0; 
    int res = 0;
    eulerTree(root, index);
    for (int i = 0; i < (2*N-1); i++) {
        res += tree[Euler[i]-1];
    }
    cout << res;   
}

int main() {
    int N;
    cin >> N;
    int tree[N];

    for(int i=0;i<N;i++) {
        cin >> tree[i];
    }

    for(int i=0;i<N-1;i++) {
        int a,b;
        cin >> a >> b;
        add_edge(a,b);
    }

    calculateSum(1, N, tree);
 
    return 0;
}