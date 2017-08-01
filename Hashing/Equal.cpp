Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty 

***********************************************************************************************************************************************

vector<int> Solution::equal(vector<int> &A) {
    vector<int> res;
    if(A.size() < 4)return res;
    unordered_map<int , vector<int> > mymap;
    for(int i=0 ; i<A.size() ; i++){
        mymap[A[i]].push_back(i);
    }

    for(int a = 0 ; a<A.size()-3 ; a++){
        for(int b = a+1 ; b<A.size() ; b++){
            int sum = A[a]+A[b];
            for(int c = a+1 ; c<A.size() ; c++){
              if(c == b)continue;
              if(mymap.find(sum-A[c]) != mymap.end()){
                  for(int i=0 ; i<mymap[sum-A[c]].size() ; i++){
                      if(mymap[sum-A[c]][i] > c && mymap[sum-A[c]][i] != b){
                          res.push_back(a);res.push_back(b);res.push_back(c);
                          res.push_back(mymap[sum-A[c]][i]);
                          return res;
                      }
                  }
              }
            }
        }
    }return res;
}
