 There are a total of N courses you have to take, labeled from 1 to N. Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2]. 
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses. return 1/0 if it is possible/not possible.
The list of prerequisite pair are given in two integer arrays B and C where B[i] is a prerequisite for C[i].

 Example: If N = 3 and the prerequisite pairs are [1,2] and [2,3], then you can finish courses in the following order: 1, 2 and 3. But if N = 2 and the prerequisite pairs are [1,2] and [2,1], then it is not possible for you to finish all the courses. 
 
 ******************************************************************************************************************************************

#define MAXN 100005
#define BLACK 0
#define BLUE 1
#define GREY 2
vector<int> g[MAXN];
void check_cycle(int u, int visited[],bool &f) {
  visited[u] = BLUE;
  for(auto v : g[u]) {
    if(visited[v] == BLACK) {
      check_cycle(v, visited, f);
    } else if(visited[v] == BLUE) {
      f = true;
    }
  }
  visited[u] = GREY;
}

int Solution::solve(int N, vector<int> &B, vector<int> &C) {
    bool f = false;
    int visited[MAXN] = {0};
    for(int i = 1;i <= N; i++) {
      g[i].clear();
    }
    for(int i=0; i<B.size(); i++) {
      g[B[i]].push_back(C[i]);
    }
    for(int i = 1; i <= N; i++) {
      if(visited[i] == BLACK) {
        check_cycle(i, visited, f);
        if(f) {
          break;
        }
      }
    }
    return !f;
}
