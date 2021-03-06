class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> g[n+1];
        vector<double> prob(n+1,0);
        vector<bool> vis(n+1,false);
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        queue<int> q({1});
        vis[1] = true;
        prob[1] = 1.00;
        while(!q.empty() && t-- > 0) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                int u = q.front(); q.pop();
                int cnt = 0;
                for(int v:g[u]) if(!vis[v]) cnt++; 
                for(int v:g[u]) {
                    if(!vis[v]) {
                        q.push(v);
                        prob[v] = prob[u]*1.0/cnt;
                        vis[v] = true;
                    }
                } 
                if(cnt) prob[u] = 0;
            }
        }
        return prob[target];
    }
};
