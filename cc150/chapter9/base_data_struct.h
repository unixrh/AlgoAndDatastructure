#include <iostream>
#include <vector>
#include <map>
using namespace std;

template <typename T=int>
class TreeNode {
  public:
    TreeNode(T x):val(x), left(NULL), right(NULL){}
    T val;
    TreeNode* left;
    TreeNode* right;
};

template <typename T=int>
class TreeNodeP {
  public:
    TreeNodeP(T x):val(x), left(NULL), right(NULL){}
    T val;
    TreeNodeP* left;
    TreeNodeP* right;
    TreeNodeP* parent;
};

template <typename T=int>
class GraphNode {
  public:
    enum State {
      Unvisited,
      Visiting,
      Visited
    };
    GraphNode(T x) {
      val = x;
      state = Unvisited;
      adj = new vector<GraphNode>();
    }
    T val;
    State state;
    vector<GraphNode> adj;
    vector<GraphNode<T> > getAdjacent() {
      return adj;
    }
    bool operator==(GraphNode<T> a) {
      return a.val == val;
    }

};

template <typename T=int>
class Graph {
  public:
    Graph(){}
    map<GraphNode<T>, vector<GraphNode<T> > > graph;
    /*
    vector<GraphNode<T> > getNodes() {
      vector<GraphNode<T> > res;
      for(auto it = graph.begin(); it != graph.end(); it++) {
        res.push_back(it->second);
      }
      return res;
    }
    */
};
