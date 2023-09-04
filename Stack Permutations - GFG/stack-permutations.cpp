//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &arr1,vector<int> &arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();
        if(n1!=n2)
            return false;
        
        int i=0,j=0;
        stack<int>s;
        while(i<n1){
            while(i<n1 && arr1[i]!=arr2[j])
                s.push(arr1[i++]);
            
            if(i==n1)
                return false;
    
            s.push(arr1[i++]);
            
            while(!s.empty() && s.top()==arr2[j]){
                s.pop();
                j++;
            }
            
        }
        return s.empty();
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends