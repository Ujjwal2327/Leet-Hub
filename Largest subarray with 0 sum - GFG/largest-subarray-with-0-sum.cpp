//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        vector<int>prefixSum(n+1,0);
        prefixSum[0] = 0;
        
        for(int i=1; i<=n; i++){
            prefixSum[i] = prefixSum[i-1] + A[i-1];
        }
        
        map<int,int>startOcc;
        
        int maxi = 0;
        int endIdx = -1;
        
        for(int i=0; i<=n; i++){
            if(startOcc.find(prefixSum[i]) != startOcc.end()){
                maxi = max( maxi , i-startOcc[prefixSum[i]]+1 );
                endIdx = i-1;
            }
            else
                startOcc[prefixSum[i]] = i;
        }

        if(maxi==0)
            return 0;
        return maxi - 1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends