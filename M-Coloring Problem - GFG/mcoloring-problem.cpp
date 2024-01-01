//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
private:
    bool solve(int n, int m, vector<vector<int>>& adj, vector<int>& mark, int node){
        
        vector<bool>validColor(m+1,true);
        for(auto neigh : adj[node]){
            if(mark[neigh])
                validColor[mark[neigh]] = false;
        }
        
        for(int c=1; c<=m; c++){
            if(validColor[c]){
                mark[node] = c;
                bool nextAns = true;
                for(auto neigh : adj[node]){
                    if(!mark[neigh]){
                        if(!solve(n,m,adj,mark,neigh)){
                            nextAns = false;
                            break;
                        }
                    }
                }
                if(nextAns)
                    return true;
                mark[node] = 0;
            }
        }
        
        return false;
    }

public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        vector<vector<int>>adj(n);
        vector<int>mark(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(!mark[i] && !solve(n,m,adj,mark,i))
                return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends