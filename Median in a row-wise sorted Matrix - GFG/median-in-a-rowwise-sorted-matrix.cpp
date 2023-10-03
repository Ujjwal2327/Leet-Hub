//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    pair<int,int> solve(vector<vector<int>> &matrix, int r, int c, int target){
        
        int firstCnt = 0;
        int lastCnt = 0;
        
        for(int i=0; i<r; i++){
            int first = lower_bound(matrix[i].begin(), matrix[i].end(), target)-matrix[i].begin();
            int last = upper_bound(matrix[i].begin(), matrix[i].end(), target)-matrix[i].begin();
        
            firstCnt += first;
            lastCnt += last;
        }
        
        return {firstCnt,lastCnt};
    }

    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        
        int s = INT_MAX;
        int e = INT_MIN;
        
        for(int i=0; i<r; i++){
            s = min(s,matrix[i][0]);
            e = max(e,matrix[i][c-1]);
        }
        
        int cnt = r*c;
        int medianCnt = (cnt+1)/2;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            pair<int,int>p = solve(matrix,r,c,mid);
            
            // cout << mid << ' ' << p.first << ' ' << p.second << '\n';
            
            if(medianCnt > p.first && medianCnt <= p.second){
                return mid;
            }
            else if(medianCnt <= p.first){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return -1;
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