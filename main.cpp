#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution{
public:
    void solveSudoku(std::vector<std::vector<char>>& board)
    { 
      solve(board);
    }
    bool solve(std::vector<vector<char>>& board)
    {
      for(int i=0;i<board.size();i++)
      {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]=='.')
            {
                for(char c='1';c<='9';c++)
                {
                    if(isValid(board,i,j,c))
                    {
                        board[i][j]=c;

                        if(solve(board)==true)
                        {
                            return true;
                        }
                        else 
                        board[i][j]='.';
                    }
                }
                return false;
            }
         }
     }
    return true;
   }

  bool isValid(vector<vector<char>>& board,int row,int col,char c)
  {
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==c)
        {
            return false;
        }
        if(board[row][i]==c)
        {
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
        {
            return false;
        }
    }
    return true;
  }


};

int main() {
  std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Create a Solution object
    Solution solution;

    // Solve the Sudoku
    solution.solveSudoku(board);

    // Print the solved Sudoku
    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}






