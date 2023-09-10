//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        
        map<int,int>hash;
        for(int i=0; i<n; i++)
            hash[arr[i]]++;
            
        int ans = 0;
        for(auto &p : hash){
            int num1 = p.first;
            int freq1 = p.second;
            int num2 = k - num1;
            int freq2 = hash[num2];
            
            if(num1==num2)
                ans += (freq1)*(freq1-1) / 2;
            else
                ans += freq1*freq2;
            hash[num1] = 0;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends