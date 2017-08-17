Given A, how many structurally unique BST’s (binary search trees) that store values 1...A?

Example :

Given A = 3, there are a total of 5 unique BST’s.


   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


*****************************************************************************************************

int Solution::numTrees(int n) {
     vector<int> table(n+1,0);
     if (n==0){return 0;}
        table[0]=1;
        table[1]=1;
        table[2]=2;
        for (int i=3;i<=n;i++){
            int res=0;
            for (int j=0;j<=i-1;j++){
                res = res+ table[j]*table[i-1-j];
            }
            table[i]=res;
        }
        return table[n];   
}
