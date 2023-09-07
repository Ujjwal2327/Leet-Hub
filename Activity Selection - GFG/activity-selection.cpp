//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
    
    
        int totalSize = start.size();
    
        vector<pair<int,int>>activities(totalSize,{0,0});
    
        for(int index=0; index < totalSize; index++){
            activities[index] = {end[index],start[index]};
        }
        sort(activities.begin(),activities.end());
    
        int ans = 0;
        int index = 0;
        while(index < totalSize){
            ans++;
            int currStart = activities[index].second;
            int currEnd = activities[index].first;
            index++;
            while(index < totalSize && activities[index].second <= currEnd)
                index++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends