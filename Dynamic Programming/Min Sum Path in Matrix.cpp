Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time. 
Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1
     
***************************************************************************************************************

int Solution::minPathSum(vector<vector<int> > &A) {
    for(int i=1 ; i<A.size() ; i++){
        A[i][0] += A[i-1][0]; 
    }
    for(int j=1 ; j<A[0].size(); j++){
        A[0][j] += A[0][j-1]; 
    }
    for(int i=1 ; i<A.size() ; i++){
        for(int j=1 ; j<A[0].size() ; j++){
            A[i][j] += min(A[i-1][j],A[i][j-1]);
        }
    }
    return A[A.size()-1][A[0].size()-1];
}
