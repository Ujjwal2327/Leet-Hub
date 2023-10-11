//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        
        int fr = 0, lr = r-1, fc = 0, lc = c-1;
        
        int total = r*c;
        vector<int>ans;
        
        while(total){
            
            // start row
            for(int j=fc; j<=lc && total; j++){
                ans.push_back(matrix[fr][j]);
                total--;
            }
            fr++;
            
            // last col
            for(int i=fr; i<=lr && total; i++){
                ans.push_back(matrix[i][lc]);
                total--;
            }
            lc--;
            
            // last row
            for(int j=lc; j>=fc && total; j--){
                ans.push_back(matrix[lr][j]);
                total--;
            }
            lr--;
            
            // start col
            for(int i=lr; i>=fr && total; i--){
                ans.push_back(matrix[i][fc]);
                total--;
            }
            fc++;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends