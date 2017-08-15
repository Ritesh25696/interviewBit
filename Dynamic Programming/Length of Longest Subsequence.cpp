Given an array of integers, find the length of longest subsequence which is first increasing then decreasing.

**Example: **

For the given array [1 11 2 10 4 5 2 1]

Longest subsequence is [1 2 10 4 2 1]

Return value 6

**************************************************************************************************

int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size() <= 1)return A.size();
    if(A.size() == 2){
        if(A[1] == A[0])return 1;
        return 2;
    }
    int i=1;
    vector<int> c1(A.size(),1);
    for(i=1 ; i<A.size() ; i++){
        int j=0;
        while(j<i){
            if(A[j] < A[i])
                c1[i]=max(c1[i],c1[j]+1);
                j++;
        }
    }
    vector<int> c2(A.size(),1);
    i=A.size()-2;
    for(i=A.size()-2 ; i>=0 ; i--){
        int j=A.size()-1;
        while(j>i){
            if(A[j]<A[i])
            c2[i]=max(c2[i],c2[j]+1);
            j--;
        }
    }
    int max = 0;
    for(i=0 ; i<A.size() ; i++){
        c1[i]+=c2[i];
        if(c1[i] > max) max = c1[i];
    }
    return max-1;
}
