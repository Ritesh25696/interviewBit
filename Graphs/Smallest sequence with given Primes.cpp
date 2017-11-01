Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3 or a combination of them as their prime factors.

Example:

Input : 
Prime numbers : [2,3,5] 
k : 5

If primes are given as p1=2, p2=3 and p3=5 and k is given as 5, then the sequence of first 5 integers will be: 

Output: 
{2,3,4,5,6}

Explanation : 
4 = p1 * p1 ( 2 * 2 )
6 = p1 * p2 ( 2 * 3 )

*********************************************************************************************************************************************************************
vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    res.push_back(1);
    int i=0, j=0 , k=0;
    while(res.size() <= D){
        if(res[i]*A<=res[j]*B && res[i]*A<=res[k]*C){
            if(res[res.size()-1] != res[i]*A)
            res.push_back(res[i]*A);
            i++;
        }
        else if(res[j]*B < res[i]*A && res[j]*B < res[k]*C){
            if(res[res.size()-1] != res[j]*B)
            res.push_back(res[j]*B);
            j++;
        }
        else{
            if(res[res.size()-1] != res[k]*C)
            res.push_back(res[k]*C);
            k++;
        }
    }
    res.erase(res.begin()+0);
    return res;
}
