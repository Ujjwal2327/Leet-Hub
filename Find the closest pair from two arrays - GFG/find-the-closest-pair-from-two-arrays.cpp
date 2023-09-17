//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        
        int s = 0, e = m-1;
        int ans = INT_MIN;
        
        while(s<n && e>=0){
            int num1 = arr[s];
            int num2 = brr[e];
            
            if(abs(x-ans) > abs(x-(num1+num2)))
                ans = num1+num2;
            
            if(num1+num2 > x)
                e--;
            else
                s++;
        }
        
        vector<int>ansVector;
        ansVector.push_back(ans);
        return ansVector;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends