class disjointSet {
public:
    vector<int> rank, parent, size;

    disjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUparent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUparent(parent[node]);
    }

    bool find(int u, int v) { return (findUparent(u) == findUparent(v)); }

    void unionByRank(int u, int v) {
        int ultp_u = findUparent(u);
        int ultp_v = findUparent(v);

        if (ultp_u == ultp_v)
            return;

        if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
        } else if (rank[ultp_v] < rank[ultp_u]) {
            parent[ultp_v] = ultp_u;
        } else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ultp_u = findUparent(u);
        int ultp_v = findUparent(v);

        if(ultp_u == ultp_v)
            return;

        if (size[ultp_u] < size[ultp_v]) {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        } else {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjointSet ds(n);

        unordered_map<string, int>mapMailNode;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];

                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                } else{
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string>mergedMail[n];

        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.findUparent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i = 0; i < n; i++){
            if(mergedMail[i].size() == 0)continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;

    }
};