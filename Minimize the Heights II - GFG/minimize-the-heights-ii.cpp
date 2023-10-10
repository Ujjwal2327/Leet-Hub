//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        if(n==1)
            return 0;
        
        sort(arr,arr+n);
        
        // for(int i=0; i<n; i++)
        //     cout << arr[i] << ' ' ;
        // cout << '\n';
    
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            
            if(i+1<n && arr[i+1]-k<0)
                continue;
            
            int maxi = max(arr[i]+k,arr[n-1]-k);
            
            int temp = (i+1<n) ? arr[i+1]-k : INT_MAX;

            int mini = max(0 , min(arr[0]+k,temp));
            ans = min(ans,maxi-mini);
            // cout << i << ' ' << maxi << ' ' << mini << ' ' << ans << '\n';
            // cout << ans << ' ';
        }
        
        // cout << "\n\n";
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends