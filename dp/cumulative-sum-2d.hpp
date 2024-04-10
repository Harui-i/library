
template<class T>
struct CumulativeSum2D {
  vector<vector<T>> data;
  CumulativeSum2D(int H, int W)  {
    data.resize(H+1, vector<T>(W+1));
  }

  void add (int i, int j, T x) {
    assert(0 <= i && i < data.size() && 0 <= j && j < data[0].size() );
    data[i+1][j+1] += x;
  }

  void build() {
    for(int i=0; i<data.size()-1; i++) {
      for(int j=0; j<data[0].size()-1; j++) {
        data[i+1][j+1] += data[i][j+1] + data[i+1][j] - data[i][j];
      }
    }
  }

  T query(int si, int sj, int gi, int gj) {
    return data[gi][gj] - data[si][gj] - data[gi][sj] + data[si][sj];
  }
};