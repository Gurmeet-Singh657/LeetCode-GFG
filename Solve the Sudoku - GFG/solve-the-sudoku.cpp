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
    bool isSafe(int row,int col,int grid[N][N],int attempt)
    {
       for(int i=0;i<N;i++)
       {
           if(grid[i][col]==attempt) return false;
       }
       for(int i=0;i<N;i++)
       {
           if(grid[row][i]==attempt) return false;
       }
       row=(row/3)*3;
       col=(col/3)*3;
       for(int i=row;i<row+3;i++)
       {
           for(int j=col;j<col+3;j++)
           {
               if(grid[i][j]==attempt) return false;
           }
       }
       return true;
    }
    bool Sudoku(int i,int j,int grid[N][N])
    {
        if(i==N) return true;
        if(j==N) return Sudoku(i+1,0,grid);
        if(grid[i][j]!=0)
        {
            return Sudoku(i,j+1,grid);
        }
        for(int attempt=1;attempt<=9;attempt++)
        {
            if(isSafe(i,j,grid,attempt))
            {
                grid[i][j]=attempt;
                if(Sudoku(i,j+1,grid)) return true;
                grid[i][j]=0;
            }
        }
        return false;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        return Sudoku(0,0,grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
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