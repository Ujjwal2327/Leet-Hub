//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int longestRoute (vector<vector<int>>& matrix, vector<int>& dest, int r, int c){
    int rows = matrix.size();
    int cols = matrix[0].size();

    if(r<0 || r>=rows || c<0 || c>=cols || matrix[r][c]==0)
        return INT_MIN;
    
    if(r==dest[0] && c==dest[1])
        return 0;

    int dr[] = {-1,0,1,0};
    int dc[] = {0,-1,0,1};

    int ans = INT_MIN;

    matrix[r][c] = 0;
    for(int i=0; i<4; i++){
        int temp = longestRoute(matrix,dest,r+dr[i],c+dc[i]);
        if(temp!=INT_MIN)
            ans = max(ans, temp);
    }
    matrix[r][c] = 1;

    return ans==INT_MIN ? INT_MIN : ans+1;
}

    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        vector<int>src = {xs,ys};
        vector<int>dest = {xd,yd};
        int ans = longestRoute(matrix,dest,xs,ys);
        
        return ans==INT_MIN ? -1 : ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends