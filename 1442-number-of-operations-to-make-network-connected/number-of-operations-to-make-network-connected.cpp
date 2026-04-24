class DisjointSet{
    public: 
    vector<int>parent, rank, size;

        DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUparent(int node){
        if(node == parent[node])return node;

        return parent[node] = findUparent(parent[node]);
    }

    bool find(int u, int v){
        return (findUparent(u) == findUparent(v));
    }

    void unionByRank(int u, int v){
        int ultp_u = findUparent(u);
        int ultp_v = findUparent(v);

        if(ultp_u == ultp_v)return;

        if(rank[ultp_u] < rank[ultp_v]){
            parent[ultp_u] = ultp_v;
        } else if(rank[ultp_v] < rank[ultp_u]){
            parent[ultp_v] = ultp_u;
        } else{
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ultp_u = findUparent(u);
        int ultp_v = findUparent(v);

        if(ultp_u == ultp_v)return;

        if(size[ultp_u] < size[ultp_v]){
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        } else{
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();

        if(size < n-1)return -1;

        DisjointSet ds(n);

        for(auto it: connections){
            ds.unionByRank(it[0], it[1]);
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i)count++;
        }

        return count-1;
    }
};