//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    int smallestExactlyKDistinct(string str, int k){
        int n = str.size();
        unordered_map<char,int>freq;
        int ans = n;
        
        int i=0, j=0;
        
        while(j<n){
            freq[str[j]]++;
            
            if(freq.size()<k){
                j++;
                continue;
            }
            
            while(freq[str[i]]>1){
                freq[str[i]]--;
                i++;
            }
            ans = min(ans,j-i+1);
            // cout << ans << ' ' << j << ' ' << i << '\n';
            j++;
        }
        return ans;
    }
    
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,bool>vis;
        int n = str.size();
        
        for(int i=0; i<n; i++){
            vis[str[i]] = true;
        }
        
        int k = vis.size();

        return smallestExactlyKDistinct(str,k);
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends