Implement pow(A, B) % C.

In other words, given A, B and C, 
find (AB)%C.

Input : A = 2, B = 3, C = 3
Return : 2 
2^3 % 3 = 8 % 3 = 2

*********************************************************************************************************************



int Solution::Mod(int x, int n, int p) {
     if (n == 0) return 1 % p;
                long long y = 0;        
                if (n % 2 == 0) {
                    y = Mod(x, n/2, p);
                    y = (y * y) % p;
                } else {
                    y = x % p;
                    y = (y * Mod(x, n - 1, p)) % p;
                }
                return (int)((y + p) % p);
}
