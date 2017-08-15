Find the longest increasing subsequence of a given sequence / array.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible. 
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.

Example :

Input : [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output : 6
The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]

***************************************************************************************************

int Solution::lis(const vector<int> &A) {
    if(A.size() <= 1)return A.size();
    
    int i=1;
    int gmax = 0;
    vector<int> c1(A.size(),1);
    for(i=1 ; i<A.size() ; i++){
        int j=0;
        while(j<i){
            if(A[j] < A[i])
                c1[i]=max(c1[i],c1[j]+1);
                if(c1[i] > gmax)gmax = c1[i];
                j++;
        }
    }return gmax;
}
