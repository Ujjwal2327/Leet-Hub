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
        
        int cnt1=0, cnt2=0;
        int num1=-1, num2=-1;
        int ans = -1;
        
        for(int i=0; i<n; i++){
            if(arr[i]==num1){
                cnt1++;
            }
            else if(arr[i]==num2){
                cnt2++;
            }
            else{
                if(cnt1==0){
                    num1 = arr[i];
                    cnt1 = 1;
                }
                else if(cnt2==0){
                    num2 = arr[i];
                    cnt2 = 1;
                }
                else{
                    if(cnt1>cnt2)
                        cnt1 = max(0,cnt1-1);
                    else
                        cnt2 = max(0,cnt2-1);

                    if(cnt1==0){
                        num1 = -1;
                    }
                    if(cnt2==0){
                        num2 = -1;
                    }
                }
            }
        }
        
        if(cnt1>n/2)
            return num1;
        else if(cnt2>n/2)
            return num2;
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