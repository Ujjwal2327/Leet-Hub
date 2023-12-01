//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int isValid(vector<vector<int>> &matrix, int rows, int cols, int target, int medianPos){
        
        int cnt = 0;
        for(auto v : matrix){
            int ub = upper_bound(v.begin(), v.end(), target) - v.begin();
            cnt += ub;
        }
        
        return (cnt >= medianPos);
    }

    int median(vector<vector<int>> &matrix, int rows, int cols){
        // code here          
        
        int s = INT_MAX, e = INT_MIN;
        int medianPos = (rows*cols)/2 + 1;
        int ans = e;
        
        for(int i=0; i<rows; i++){
            s = min(s,matrix[i][0]);
            e = max(e,matrix[i][cols-1]);
        }
        
        
        while(s<=e){
            int mid = s + (e-s) / 2;
            
            if(isValid(matrix,rows,cols,mid,medianPos)){
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends