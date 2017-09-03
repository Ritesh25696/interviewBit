Given a number N, return number of ways you can draw N chords in a circle with 2*N points such that no 2 chords intersect.
Two ways are different if there exists a chord which is present in one way and not in other.

For example,

N=2
If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
{(1-2), (3-4)} and {(1-4), (2-3)}

So, we return 2.
Notes:

1 ≤ N ≤ 1000
Return answer modulo 109+7.
***************************************************************************************************************************
int catalan(int A){
      vector<long long> cat(A+1 , 0);
    cat[0] = 1;
    cat[1] = 1;
    cat[2] = 2;
    for(int i = 3 ; i<=A ; i++){
        long long r = 0;
        for(int j=0 ; j<i ; j++){
            r += (long long)(cat[j]*cat[i-j-1])%1000000007;
        }

        cat[i] = r%1000000007;
    }
    return cat[A];
}

int Solution::chordCnt(int A){
    return catalan(A);
}
