//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        
        unordered_map<int,int>firstOcc;
        int prefixSum = 0;
        int ans = 0;
        
        for(int i=0; i<N; i++){
            prefixSum += A[i];
            int remainPS = prefixSum - K;
            if(prefixSum == K){
                ans = i+1;
                if(firstOcc.find(prefixSum) == firstOcc.end()){
                    firstOcc[prefixSum] = i;
                }
            }
            
            else{
                if(firstOcc.find(prefixSum) == firstOcc.end()){
                    firstOcc[prefixSum] = i;
                }
                if(firstOcc.find(remainPS) != firstOcc.end()){
                    ans = max(ans,i-firstOcc[remainPS]);
                }
            }
            
        }
        
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends