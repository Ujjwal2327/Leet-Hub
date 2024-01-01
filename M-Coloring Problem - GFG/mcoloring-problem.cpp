//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
private:
    bool isSafe(int n, int node, bool graph[101][101], vector<int>& mark, int c){
        
        for(int i=0; i<n; i++){
            if(i!=node && graph[node][i] && mark[i]==c)
                return false;
        }
        
        return true;
    }

    bool solve(int n, int m, bool graph[101][101], vector<int>& mark, int node){
        
        if(node==n)
            return true;
        
        for(int c=1; c<=m; c++){
            if(isSafe(n,node,graph,mark,c)){
                mark[node] = c;
                if(solve(n,m,graph,mark,node+1))
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
        
        return solve(n,m,graph,mark,0);
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