How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.

Example:

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 

****************************************************************************************************************************************************************

int Solution::fibsum(int N) {
    vector<int> Fib;
        Fib.push_back(1);
        Fib.push_back(1);
        for(int i = 2; Fib[i - 1] < N; ++i) {
            int data = Fib[i - 1] + Fib[i - 2];
            Fib.push_back(data);
        }
        
        int ans = 0;
        int index = Fib.size() - 1;
        while (N > 0) {
            while (Fib[index] > N) index--;
            N -= Fib[index];
            ans++;
        }
        return ans;
}
