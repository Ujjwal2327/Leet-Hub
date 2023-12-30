//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool static custom_comparator(vector<int>&a, vector<int>&b){
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>>time(n,vector<int>(2));
        for(int i=0; i<n; i++){
            time[i][0] = start[i];
            time[i][1] = end[i];
        }
        
        sort(time.begin(),time.end(), custom_comparator);
        
        int ans = 0, lastEnd=-1;
        for(auto v : time){
            if(v[0]>lastEnd){
                ans++;
                lastEnd = v[1];
            }
        }


        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends