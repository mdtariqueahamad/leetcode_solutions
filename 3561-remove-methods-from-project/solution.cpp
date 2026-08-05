class Solution {
public:

    void trav(vector<vector<int>>& path, vector<bool> &visited, int k, int idx){
        visited[k] = true;
        if(idx == path[k].size()) return;

        if(!visited[path[k][idx]])
        trav(path, visited, path[k][idx], 0);
        trav(path, visited, k, idx+1);
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> path(n);
        for(int i = 0; i < invocations.size(); i++)
            path[invocations[i][0]].push_back(invocations[i][1]);
        
        vector<bool> visited(n, false);
        trav(path, visited, k, 0);

        for(auto edge : invocations){
            if(!visited[edge[0]] && visited[edge[1]]){
                vector<int> ans;

            for (int j = 0; j < n; j++)
                ans.push_back(j);

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                ans.push_back(i);
        }

        return ans;
    }
};
