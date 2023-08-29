//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>>& maze, int &n, int r, int c, vector<string>& ans, string& currOutput){
        if(r<0 || c<0 || r>=n || c>=n || maze[r][c]==0)
            return;
        
        if(r==n-1 && c==n-1){
            ans.push_back(currOutput);
            return;
        }
        
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        char ch[] = {'U','D','L','R'};
        
        maze[r][c] = 0;
        for(int i=0; i<4; i++){
            currOutput += ch[i];
            solve(maze, n, r+dr[i], c+dc[i], ans, currOutput);
            currOutput.pop_back();
        }
        maze[r][c] = 1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string>ans;
        string currOutput;

        solve(maze,n,0,0,ans,currOutput);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends