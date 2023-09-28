//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long smallerCnt(int n,vector<int> a,long long k){
        int i=0,j=0,cnt=0;
        long long currSum = 0, ans=0;
        
        while(j<n){
            currSum += a[j];
            while(currSum>=k){
                currSum -= a[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    
    long long greaterCnt(int n,vector<int> a,long long k){
        int i=0,j=0;
        long long currSum = 0, ans=0;
    
        while(i<n && j<n){
            while(j<n && currSum+a[j]<=k){
                currSum+=a[j];
                j++;
            }
            ans += n-j;
            currSum-=a[i];
            i++;
        }
        return ans;
    }
  
    long long countSubarray(int n,vector<int> a,long long l,long long r) {
        // code here
        
        long long num1 = smallerCnt(n,a,l);
        long long num2 = greaterCnt(n,a,r);
        
        long long size = n;
        long long total = (size*(size+1))/2;
        // cout << num1 << ' ' << num2 << ' ' << total << '\n';
        
        return total-(num1+num2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends