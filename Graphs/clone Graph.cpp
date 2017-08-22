Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

********************************************************************************************************************

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *src) {
   map<UndirectedGraphNode*,UndirectedGraphNode*> my_map;
   queue<UndirectedGraphNode*> Q;
   Q.push(src);
   UndirectedGraphNode *node = new UndirectedGraphNode(src->label);
   my_map[src] = node;
   while(!Q.empty()){
       UndirectedGraphNode* fr = Q.front();
       Q.pop();
       vector<UndirectedGraphNode *> v = fr->neighbors;
       for(int i=0 ; i<v.size() ; i++){
           if(my_map.find(v[i]) == my_map.end()){
               UndirectedGraphNode *temp = new UndirectedGraphNode(v[i]->label);
               my_map[v[i]] = temp;
               Q.push(v[i]);
           }
           my_map[fr]->neighbors.push_back(my_map[v[i]]);
       }
   }
   return my_map[src];
}
