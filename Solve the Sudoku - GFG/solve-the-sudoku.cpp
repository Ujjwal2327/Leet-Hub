//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    
    bool isValid(int sudoku[N][N], int r, int c, int val){
        int n = 9;
        for(int i=0; i<n; i++){
            if(i!=r && sudoku[i][c]==val)
                return false;
        }
    
        for(int j=0; j<n; j++){
            if(j!=c && sudoku[r][j]==val)
                return false;
        }
    
        int bRow = r/3, bCol = c/3;
    
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(sudoku[3*bRow + i][3*bCol + j] == val)
                    return false;
            }
        }
    
        return true;
    }

    
    bool solveSudoku(int sudoku[N][N]){
    int n = 9;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(sudoku[i][j]==0){
                for(int val=1; val<=9; val++){
                    if(isValid(sudoku,i,j,val)){
                        sudoku[i][j] = val;
                        if(solveSudoku(sudoku))
                            return true;
                        sudoku[i][j] = 0;
                    }
                }
                return false;       // IMP
            }
        }
    }

    return true;
}
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solveSudoku(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        int n = 9;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout << grid[i][j] << ' ';
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends