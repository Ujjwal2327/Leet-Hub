//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        // code here
        
        int prefixSum = 0;
        map<int,int>freq;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            prefixSum += arr[i];
            
            if(prefixSum==k)
                ans++;
            
            int remainSum = prefixSum - k;
            
            if(freq.find(remainSum) != freq.end()){
                ans+= freq[remainSum];
            }
            freq[prefixSum]++;
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends