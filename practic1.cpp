#include<bits/stdc++.h>
using namespace std;
class UnionFind {
    int n, Components;
    vector<int> Rank, Parent;
public:
    UnionFind(int size) : n(size + 1) {
        Rank.assign(n, 1), Components = n;
        for (int i = 1; i <= n; i++)
            Parent[i] = i;
    }
    int find(int node) {
        if (Parent[node] == node)
            return node;
        return Parent[node] = find(Parent[node]);
    }
    int size() { return Components; }
    void Union(int u, int v) {
        int aset = find(u), bset = find(v);
        if (aset == bset) return ;
        if (Rank[aset] >= Rank[bset]) {
            Parent[bset] = aset; 
            Rank[aset] += Rank[bset];
        } else {
            Parent[aset] = bset;
            Rank[bset] += Rank[aset];  
        } 
    }
};
int main(int argc, char const *argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout << "hello world bro" << endl;
    return 0;
}