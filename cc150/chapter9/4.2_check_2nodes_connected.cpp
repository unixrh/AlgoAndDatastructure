#include "base_data_struct.h"
#include <queue>

bool checkConnected(Graph<> g, GraphNode<> start, GraphNode<> end) {
  queue<GraphNode<> > q;
  for(auto item : g.graph) {
    for(auto it : item.second)
    it.state = GraphNode<>::Unvisited;
  }
  q.push(start);
  while(!q.empty()) {
    auto u = q.front();
    q.pop();
    for(auto v : u.getAdjacent()){
      if(v.state == GraphNode<>::Unvisited) {
        if(v == end) {
          return true;
        } else {
          v.state = GraphNode<>::Visiting;
          q.push(v);
        }
      }
    }
    u.state = GraphNode<>::Visited;
  }
  return false;
}
