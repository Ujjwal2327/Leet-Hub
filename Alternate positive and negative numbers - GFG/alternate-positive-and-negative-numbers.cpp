//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    
	    vector<int>temp;
	    
	    for(int i=0; i<n; i++)
	        temp.push_back(arr[i]);
	       
	   
	    int i=0, j=0, k=0;
	    
	    while(i<n || j<n){
	        while(i<n && temp[i]<0)
	            i++;
	        if(i<n)
	            arr[k++] = temp[i++];
	        while(j<n && temp[j]>=0)
	            j++;
	        if(j<n)
	            arr[k++] = temp[j++];
	    }
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends