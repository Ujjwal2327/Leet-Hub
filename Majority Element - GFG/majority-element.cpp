//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {
        
        // your code here
        
        int cnt = 0;
        int maj=-1;

        for(int i=0; i<n; i++){
            if(cnt==0){
                cnt++;
                maj = arr[i];
            }
            else if(maj==arr[i])
                cnt++;
            else
                cnt--;
        }
        
        cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i]==maj)
                cnt++;
        }
        
        if(cnt>n/2)
            return maj;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends