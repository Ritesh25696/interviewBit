Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

****************************************************************************************************************************888

int maxArea(vector<int> A){
stack<int> S;
int area = 0, maxarea = 0 , i;
for(i=0 ; i<A.size() ; i++){
    if(S.empty() || A[i] > A[S.top()]){
        S.push(i);
    }
    else{
        while(!S.empty() && A[i] < A[S.top()]){
            int top = S.top();
            S.pop();
            if(S.empty()){
               area = A[top]*i;
            }
            else{
                area = A[top]*(i-S.top()-1);
            }
            if(area > maxarea)maxarea = area;
        }
        S.push(i);
    }
}
while(!S.empty()){
            int top = S.top();
            S.pop();
            if(S.empty()){
               area = A[top]*i;
            }
            else{
                area = A[top]*(i-S.top()-1);
            }
            if(area > maxarea)maxarea = area;
        }
return maxarea;
}


int Solution::maximalRectangle(vector<vector<int> > &A) {
    int area = 0, maxarea = 0;
    area = maxArea(A[0]);
    if(area > maxarea)maxarea = area;
    for(int i= 1 ; i<A.size() ; i++){
        for(int j=0 ; j<A[0].size() ; j++){
            if(A[i][j] == 0)A[i][j] = 0;
            else A[i][j]+=A[i-1][j];
            area = maxArea(A[i]);
            if(area > maxarea)maxarea = area;
        }
    } 
    return maxarea;
}
