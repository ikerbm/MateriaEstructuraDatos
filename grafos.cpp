#include <iostream>
#include <vector>

using namespace std;
class AdjMat{
private:
  vector<vector<int>> graph;
public:
  AdjMat(unsigned int nodes)
    : graph (nodes,vector<int>(nodes,0)){}

  unsigned int numNodes() const {
    return graph.size();
  }
  //adicionar arco dirigido
  void addEdge(unsigned int s,unsigned int t){
    graph[s][t]=1;
  }
  //adicionar arco no dirigido
  void addUDEdge(unsigned int s,unsigned int t){
    graph[s][t]=1;
    graph[t][s]=1;
  }
  bool isEdge(unsigned int s,unsigned int t)const{
    return graph[s][t]==1;
  }
  //const vector<unsigned int> neighbors(unsigned int n)const{
    //return graph[n];
  //}

  void print()const{
    for(int i =0; i <numNodes();i++){
      for(int j=0;j<numNodes();j++){
        cout << graph[i][j]<<" ";
      }
      cout<<endl;
    }
  }


};


int main(){
  AdjMat g(7);
  g.addUDEdge(1,0);
  g.addUDEdge(1,2);
  g.addUDEdge(1,3);
  g.print();
  cout<<g.isEdge(3,4)<<endl;
}
