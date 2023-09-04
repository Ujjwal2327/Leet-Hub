//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		    // Code here
            int n = str.size();
            queue<char>q;
            string ans;
            int cnt[26] = {0};
        
            for(char ch : str){
                cnt[ch-'a']++;
                q.push(ch);
                while(!q.empty() && cnt[q.front()-'a'] > 1)
                    q.pop();
                if(q.empty())
                    ans += '#';
                else
                    ans += q.front();
            }
        
            return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends