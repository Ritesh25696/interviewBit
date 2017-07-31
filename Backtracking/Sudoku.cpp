Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.' 
You may assume that there will be only one unique solution.

************************************************************************************************************************************************88

bool UsedInBox(vector<vector<char> > &grid, int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num + '0')
                return true;
    return false;
}

bool UsedInCol(vector<vector<char> > &grid, int col, int num)
{
    for (int row = 0; row < grid.size(); row++)
        if (grid[row][col] == num+'0')
            return true;
    return false;
}

bool UsedInRow(vector<vector<char> > &grid, int row, int num)
{
    for (int col = 0; col < grid.size(); col++)
        if (grid[row][col] == num+'0')
            return true;
    return false;
}

bool isSafe(vector<vector<char> > &grid, int row, int col, int num)
{
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%3 , col - col%3, num);
}

bool FindUnassignedLocation(vector<vector<char> > &grid, int &row, int &col)
{
    for (row = 0; row < grid.size(); row++)
        for (col = 0; col < grid[0].size(); col++)
            if (grid[row][col] == '.')
                return true;
    return false;
}

bool SolveSudoku(vector<vector<char> > &grid)
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true; 
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num + '0';
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = '.';
        }
    }
    return false; 
}


void Solution::solveSudoku(vector<vector<char> > &A) {
    bool k = SolveSudoku(A);
}
