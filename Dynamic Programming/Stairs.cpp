You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example :

Input : 3
Return : 3

Steps : [1 1 1], [1 2], [2 1]

******************************************************************************************************

int Solution::climbStairs(int A) {
    if(A <= 1)return A;
    vector<int> fib(A+1 , 1);
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2 ; i<=A ; i++) fib[i]=fib[i-1]+fib[i-2];
    return fib[A];
}
