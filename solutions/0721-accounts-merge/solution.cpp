class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unite(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisjointSet ds(n);

        vector<vector<string>> output(n);

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (mp.find(email) == mp.end()) {
                    mp[email] = i;
                } else {
                    ds.unite(i, mp[email]);
                }
            }
        }

        for (auto& i : mp) {

            string email = i.first;
            int num = i.second;

            int parent = ds.findParent(num);

            output[parent].push_back(email);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (output[i].empty())
                continue;

            sort(output[i].begin(), output[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (string e : output[i]) {
                temp.push_back(e);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
