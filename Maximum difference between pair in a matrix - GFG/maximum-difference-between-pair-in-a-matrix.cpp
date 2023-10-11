//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findMaxValue(vector<vector<int>>&mat, int n)
    {
        //Write your code here   
        
        vector<vector<int>>temp = mat;
        
        int ans = INT_MIN;
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                temp[i][j] = INT_MIN;
                int maxi = INT_MIN;
                
                if(i+1<n && j+1<n)
                    maxi = max(maxi,max(mat[i+1][j+1],temp[i+1][j+1]));
                if(maxi != INT_MIN)
                    ans = max(ans,maxi-mat[i][j]);
                if(i+1<n)
                    maxi = max(maxi,max(mat[i+1][j],temp[i+1][j]));
                if(j+1<n)
                    maxi = max(maxi,max(mat[i][j+1],temp[i][j+1]));
                temp[i][j] = maxi;
            }
        }
       
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << temp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        //     cout << '\n';
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
	    int n;
	    cin >> n;
	    vector<vector<int>>mat(n,vector<int>(n, 0));
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            cin >> mat[i][j];
	        }
	    }
	    Solution ob;
	    int ans = ob.findMaxValue(mat, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends