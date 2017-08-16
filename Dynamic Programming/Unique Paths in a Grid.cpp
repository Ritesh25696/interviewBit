Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

 Note: m and n will be at most 100. 
 
 ******************************************************************************************************************

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A[0][0]  == 1)return 0;
    int k = A.size();
    int p = A[0].size();
    for(int i=0 ; i<A.size() ; i++){
        if(A[i][0] == 1){
            k=i;
            break;
        }
        A[i][0] = 1;
    }
    for(int i = k ; i<A.size() ; i++){
        A[i][0] = 0;
    }
    for(int j = 1 ; j<A[0].size() ; j++){
        if(A[0][j] == 1){
            p = j;
            break;
        }
        A[0][j] = 1;
    }
    for(int j=p ; j<A[0].size() ; j++){
        A[0][j] = 0;
    }
    for(int i=1 ; i<A.size() ; i++){
        for(int j=1 ; j<A[0].size() ; j++){
            if(A[i][j] == 1)A[i][j] = 0;
            else A[i][j] = A[i-1][j]+A[i][j-1];
        }
    }
    return A[A.size()-1][A[0].size()-1];
}
