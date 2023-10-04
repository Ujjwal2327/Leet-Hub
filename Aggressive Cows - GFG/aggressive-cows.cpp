//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isValid(int n, int k, vector<int> &nums, long long maxi){
        
        int i = 0;
        int cnt = 0;
        
        
        while(i<n){
            cnt++;
            
            if(cnt == k)
                return true;
            
            int j = i+1;
            while(j<n && nums[j]-nums[i] < maxi){
                j++;
            }
            
            i = j;
        }
        
        return false;
    }
    
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(),stalls.end());

        
        long long s = 0, e = stalls[n-1], ans = 0;
        
        while(s<=e){
            long long mid = s + (e-s) / 2;
            
            if(isValid(n,k,stalls,mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends