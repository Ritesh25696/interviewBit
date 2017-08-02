
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:
- If K > N, return empty array.

For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].

*********************************************************************************************************************************

vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> mymap;
    vector<int>res;
    if(A.size() < B)return res;
    for(int i=0 ; i<B ; i++){
        if(mymap.find(A[i]) == mymap.end())mymap[A[i]] = 1;
        else mymap[A[i]]++;
    }
            res.push_back(mymap.size());
    if(A.size() == B){
        return res;
    }
    int j = 0;

    for(int i=B ; i<A.size() ; i++){
        if(mymap[A[j]] > 1)
        mymap[A[j]] -= 1;
        else mymap.erase(A[j]);
        j++;
        if(mymap.find(A[i]) == mymap.end())mymap[A[i]] = 1;
        else mymap[A[i]]++;
                res.push_back(mymap.size());
    }
           // res.push_back(mymap.size());
    return res;
}
