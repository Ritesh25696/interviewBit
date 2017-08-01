Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 

***************************************************************************************************************************

struct Pair{
    int start;
    int end;
};
vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int, Pair> myMap;
    int sum = 0;
    for(int i = 0; i < A.size(); i++){
        sum = sum+A[i];
        if(myMap.find(sum) != myMap.end()){
            myMap[sum].end = i;
        }
        else{
            myMap[sum].start = i;
            myMap[sum].end = -1;
        }
    }
    
    int min = A.size(), max = 0;
    auto it = myMap.begin();
    while(it != myMap.end()){
        if(it->first == 0 ){
            if(it->second.end != -1){
                max = it->second.end;
            }
            else{
                max = it->second.start;
            }
            min = -1;
        }
        else if(it->second.end != -1){
            if((max-min) < (it->second.end-it->second.start)){
                max = it->second.end;
                min = it->second.start;
            }
            else if(((max-min) == (it->second.end-it->second.start)) &&
                    min > it->second.start){
                max = it->second.end;
                min = it->second.start;
            }
        }
        it++;    
    }
    
    vector<int> sol;
    for(int i = min+1; i <= max; i++){
        sol.push_back(A[i]);
    }
    
    return sol;
}

******************************************************************************************************************************************************
using sliding window;-
----------------------

vector<int> Solution::lszero(vector<int> &A) {
    int len = A.size();
    vector<int> res;
    while(len >= 0){
        for(int st=0 ; st<A.size()-len+1 ; st++){
        int sum = 0;
        for(int i=st ; i<st+len ; i++){
            sum+=A[i];
        }
        if(sum == 0){
            for(int i=st ; i<st+len ; i++)res.push_back(A[i]);
            return res;
        }
        }
        len--;
    }
    return res;
}
