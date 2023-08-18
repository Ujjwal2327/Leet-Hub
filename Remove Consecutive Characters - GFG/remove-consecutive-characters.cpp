//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S){
        int n = S.size();
        int i=1, j=1;
        
        while(i<n && j<n){
            if(S[j] == S[j-1])
                j++;
            else{
                S[i] = S[j];
                i++;
                j++;
            }
        }
        
        return S.substr(0, i);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends