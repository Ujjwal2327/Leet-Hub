//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string a, string b)
    {
        //code here.
        int n = a.size();
        if(n != b.size())
            return -1;
        
        vector<int>freqa(256);
        vector<int>freqb(256);
        
        for(int i=0; i<n; i++){
            freqa[a[i]]++;
            freqb[b[i]]++;
        }
        
        for(int i=0; i<256; i++){
            if(freqa[i]!=freqb[i])
                return -1;
        }
        
        queue<char>qa;
        queue<char>qb;
        
        for(int i=n-1; i>=0; i--){
            qa.push(a[i]);
            qb.push(b[i]);
        }
        
        int ans = 0;
        while(!qa.empty()){
            char fronta = qa.front();
            char frontb = qb.front();
            
            if(fronta==frontb){
                qa.pop();
                qb.pop();
            }
            else{
                ans++;
                // qa.push(fronta);
                qa.pop();
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends