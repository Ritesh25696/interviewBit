You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

****************************************************************************************************************************************************

vector<int> Solution::maxone(vector<int> &arr, int m) {
 int wL = 0, wR = 0; 
 int n = arr.size();
vector<int> res;
    int bestL = 0, bestWindow = 0; 
 
    int zeroCount = 0; 
 
    while (wR < n)
    {
        if (zeroCount <= m)
        {
            if (arr[wR] == 0)
              zeroCount++;
            wR++;
        }
 
        if (zeroCount > m)
        {
            if (arr[wL] == 0)
              zeroCount--;
            wL++;
        }
 
        if (wR-wL > bestWindow)
        {
            bestWindow = wR-wL;
            bestL = wL;
        }
    }
 
    for (int i=0; i<bestWindow; i++)
    {
        res.push_back(bestL+i);}
        return res;
}
