//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    // ps means prefix sum
	    unordered_map<long long,int>firstOcc;
	    long long pSMod = 0;
	    int ans = 0;
	    
	    for(int i=0; i<n; i++){
	        arr[i] = (arr[i]%k + k)%k ;
	        pSMod += arr[i];
	        pSMod = pSMod % k;

	        if(pSMod==0)
	            ans = i+1;
	        
	        if(firstOcc.find(pSMod) == firstOcc.end())
	            firstOcc[pSMod] = i;
	        else
	            ans = max(ans,i-firstOcc[pSMod]);
	    }
	    
	   // cout << -5 % 3 << '\n';
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends