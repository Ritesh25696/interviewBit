Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*******************************************************************************************************************************************************************

void solveutil(vector<vector<char> > &A , int x  , int y){
    queue<pair<int , int>>q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair<int, int> fr = q.front();
        q.pop();
        int x = fr.first;
        int y = fr.second;
        A[x][y] = 'Y';
        if(x>0 && A[x-1][y] == 'O')q.push(make_pair(x-1,y));
        if(x+1<A.size() && A[x+1][y] == 'O')q.push(make_pair(x+1,y));
        if(y>0 && A[x][y-1] == 'O')q.push(make_pair(x,y-1));
        if(y+1<A[0].size() && A[x][y+1] == 'O')q.push(make_pair(x,y+1));
    }
}

void Solution::solve(vector<vector<char> > &A) {
    for(int i=0; i<A[0].size() ; i++){
        if(A[0][i] == 'O'){
            solveutil(A, 0, i);
        }
    }
    for(int i=0; i<A[0].size() ; i++){
        if(A[A.size()-1][i] == 'O'){
            solveutil(A, A.size()-1, i);
        }
    }
    for(int i=0 ; i<A.size() ; i++){
        if(A[i][0] == 'O'){
            solveutil(A, i, 0);
        }
    }
    for(int i=0 ; i<A.size() ; i++){
        if(A[i][A[0].size()-1] == 'O'){
            solveutil(A, i, A[0].size()-1);
        }
    }
    for(int i=0 ; i<A.size(); i++){
        for(int j=0 ; j<A[0].size() ; j++){
            if(A[i][j] == 'O')A[i][j] = 'X';
            else if(A[i][j] == 'Y')A[i][j] = 'O';
        }
    }
}
