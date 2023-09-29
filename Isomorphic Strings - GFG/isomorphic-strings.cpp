//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n = str1.size();
        if(n != str2.size())
            return false;
        
        unordered_map<char,char>hash;
        unordered_map<char,bool>str2Vis;
        
        for(int i=0; i<n; i++){
            if(hash.find(str1[i]) == hash.end()){
                if(str2Vis[str2[i]])
                    return false;
                    
                hash[str1[i]] = str2[i];
                str2Vis[str2[i]] = true;
            }
            else{
                if(!str2Vis[str2[i]])
                    return false;
                    
                else if(hash[str1[i]] != str2[i])
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends