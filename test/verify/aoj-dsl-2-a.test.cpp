#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include<iostream>
#include "../../structure/segment-tree/segment-tree.hpp"

using namespace std;

int main() {
  int n, q; cin >> n >> q;
  while(q--){
    int com, x, y; cin >> com >> x >> y;
    if(com == 0){
      seg.update(x, y);
    }else{
      cout << seg.query(x, y+1) << endl;
    }
  }
}