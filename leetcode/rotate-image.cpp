class Solution {
  struct point {
    int x, y;  
  };
  
  void rotate(vector<vector<int>>& matrix, int r, int w) {
    int n = matrix.size(), tmp;
    
    point p[4] = {
      { w, r },
      { n - 1 - r, w },
      { n - 1 - w, n - 1 - r },
      { r, n - 1 - w }
    };
    
    tmp = matrix[p[3].y][p[3].x];
    for (int i = 3; i > 0; i--) 
      matrix[p[i].y][p[i].x] = matrix[p[i - 1].y][p[i - 1].x];
    
    matrix[p[0].y][p[0].x] = tmp;
  }
  
public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for (int r = 0; r < n / 2; r++) {
      for (int w = r; w < n - 1 - r; w++) {
        rotate(matrix, r, w); 
      } 
    }
  }
};
