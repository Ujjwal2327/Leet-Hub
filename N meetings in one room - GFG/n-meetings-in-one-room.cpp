//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool static custom_comparator(pair<int,int>a, pair<int,int>b){
        if(a.second==b.second)
            return a.first<b.first;
        return a.second<b.second;
    }
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>time(n);
        for(int i=0; i<n; i++){
            time[i].first = start[i];
            time[i].second = end[i];
        }
        
        sort(time.begin(),time.end(), custom_comparator);
        
        int ans = 0, lastEnd=-1;
        for(auto p : time){
            if(p.first>lastEnd){
                ans++;
                lastEnd = p.second;
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