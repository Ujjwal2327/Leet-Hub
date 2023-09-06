//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        int rupee[] = {1,2,5,10,20,50,100,200,500,2000};
        
        vector<int>ans;
        
        while(n){
            int index = upper_bound(rupee,rupee+10,n) - rupee;
            index--;
            ans.push_back(rupee[index]);
            n = n-rupee[index];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends