Given an array of integers, return the highest product possible by multiplying 3 numbers from the array

Input:

array of integers e.g {1, 2, 3}
 NOTE: Solution will fit in a 32-bit signed integer 
Example:

[0, -1, 3, 100, 70, 50]

=> 70*50*100 = 350000
****************************************************************************************************************

int Solution::maxp3(vector<int> &A) {
    sort(A.begin(),A.end());
    if(A.size() < 3)return 0;
    return max(A[0]*A[1]*A[A.size()-1] ,A[A.size()-1]*A[A.size()-2]*A[A.size()-3] );
}
