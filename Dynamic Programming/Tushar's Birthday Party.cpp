As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE: 
1. Each dish is supposed to be eaten by only one person. Sharing is not allowed. 
2. Each friend can take any dish unlimited number of times.
2. There always exists a dish with filling capacity 1 so that a solution always exists.

Input Format

Friends : List of integers denoting eating capacity of friends separated by space.
Capacity: List of integers denoting filling capacity of each type of dish.
Cost :    List of integers denoting cost of each type of dish.
Constraints:
1 <= Capacity of friend <= 1000
1 <= No. of friends <= 1000
1 <= No. of dishes <= 1000

Example:

Input:
    2 4 6
    2 1 3
    2 5 3

Output:
    14

********************************************************************************************************************************

int Solution::solve(const vector<int> &F, const vector<int> &D, const vector<int> &E) {
    map<int,int> my_map;
    for(int i=0 ; i<D.size() ; i++){
        if(my_map.find(D[i]) == my_map.end())my_map[D[i]] = E[i];
        else if(my_map[D[i]] > E[i] )my_map[D[i]] = E[i];
    }
    vector<int> A = F;
    int i=0;
    vector<int> B;
    vector<int> C;
    sort(A.begin() ,A.end());
    for(map<int,int>::iterator it = my_map.begin() ; it != my_map.end() ; it++){
        if(i>0 && B[i-1] == it->first){
            continue;
        }
        else{
        B.push_back(it->first) ;
        C.push_back(it->second);
        i++;
        }
    }
   int res[B.size()][A[A.size()-1]+1];
    for(int i=0 ; i<B.size() ; i++){
        res[i][0] = 0;
    }
    for(int i=0 ; i<=A[A.size()-1] ; i++){
           res[0][i] = i*C[0];
    }
    for(int i=1 ; i<B.size() ; i++){
        for(int j=1 ; j<=A[A.size()-1] ; j++){
            if(j >= B[i])
            res[i][j] = min(res[i][j-B[i]] + C[i],res[i-1][j]);
            else res[i][j] = res[i-1][j];
        }
    }

    int total = 0;
    for(int i=0 ; i<A.size() ; i++){
        total += res[B.size()-1][A[i]];
    }
    return total;
}
