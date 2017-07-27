You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C. 
         
***********************************************************************************************************************************************************

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
      int i=0,j=0,k=0;
    int diff, g_diff = INT_MAX;
    while(i<A.size() && j<B.size() && k<C.size()){
        int maximum =  max(max(A[i],B[j]),C[k]);
        int minimum = min(min(A[i],B[j]),C[k]);
        diff = maximum - minimum;
        if(diff == 0){g_diff=diff;break;}
        if(diff < g_diff) g_diff = diff;
        if(A[i]==minimum)i++;
        else if(B[j] ==minimum)j++;
        else k++;
    }
    return g_diff;
}
