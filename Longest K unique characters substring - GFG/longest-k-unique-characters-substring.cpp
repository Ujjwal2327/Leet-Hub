//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n = s.size();
        
        unordered_map<char,int>freq;
        int i=0, j=0, ans = 0;
        
        while(j<n){
            
            freq[s[j]]++;
            while(freq.size()>k){
                freq[s[i]]--;
                if(freq[s[i]]==0)
                    freq.erase(s[i]);
                i++;
            }
            if(freq.size()==k)
                ans = max(ans,j-i+1);
            j++;
        }
        return ans==0 ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends