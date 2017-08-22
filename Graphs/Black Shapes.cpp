Given N * M field of O's and X's, where O=white, X=black
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Example:

OOOXOOO
OOXXOXO
OXOOOXO

answer is 3 shapes are  :
(i)    X
     X X
(ii)
      X
 (iii)
      X
      X
Note that we are looking for connected shapes here.

For example,

XXX
XXX
XXX
is just one single connected black shape.

*******************************************************************************************************************************************************

// bool notin(unordered_set<int>& blacks, int st , int end, bool &k ){
//     bool done = false;
//     for(int i=st ; i<=end ; i++){
//         if(blacks.find(i) != blacks.end()){k = false; done = true;}
//         else{
//             blacks.insert(i);
//         }
//     }
//     if(!done)
//     k = true;
// }

// int Solution::black(vector<string> &A) {
//   unordered_set<int> blacks;
//   int count = 0;
//   for(int i=0 ;i<A.size() ; i++){
//       for(int j=0; j<A[0].size() ; j++){
//           if(A[i][j] == 'X' && (blacks.find(j) == blacks.end())){
//               int st = j;
//               while(A[i][j+1] == 'X' && j+1 < A[0].length()) {
//                   j++;}
//                   bool k;
//                   notin(blacks, st , j, k);
//               if(k){
//                   count++;
//               }
//           }
//           else if(A[i][j] == 'O' && (blacks.find(j) != blacks.end()) ){
//               blacks.erase(j);
//           }
//       }
//   }
//   return count;
// }

void bfs(int i, int j, vector<string> &A){
	if(i>0 && A[i-1][j]=='X'){
		A[i-1][j]='Y';
		bfs(i-1,j,A);
	}
	
	if(i<(A.size()-1) && A[i+1][j]=='X'){
		A[i+1][j]='Y';
		bfs(i+1,j,A);
	}
	
	if(j>0 && A[i][j-1]=='X'){
		A[i][j-1]='Y';
		bfs(i,j-1,A);
	}
	
	if(j<(A[0].size()-1) && A[i][j+1]=='X'){
		A[i][j+1]='Y';
		bfs(i,j+1,A);
	}
	
}
int Solution::black(vector<string> &A) {
    if(A.size()==0) return 0;
    
    int n = A.size();
    int m = A[0].size();
    
    int ct=0;
    
    for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(A[i][j]=='X'){
				A[i][j]='Y';
				bfs(i,j, A);
				ct++;
			}
		}
	}
	return ct;
}
