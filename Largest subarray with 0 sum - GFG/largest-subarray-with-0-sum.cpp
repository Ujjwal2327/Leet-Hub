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
    
        unordered_map<int,int>firstOcc;     // {ps,firstOcc}
        long long sum = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            sum += A[i];
            if(sum==0)
                ans=i+1;
            
            long long remainSum = sum;
            if(firstOcc.find(remainSum) != firstOcc.end())
                ans = max(ans,i-firstOcc[remainSum]);
            
            if(firstOcc.find(sum) == firstOcc.end())
                firstOcc[sum] = i;
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