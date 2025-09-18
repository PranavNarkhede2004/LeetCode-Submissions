class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat[0].size();
        int top = 0;
        int down = n - 1;

        while (top < down) {
            if (mat[top][down])             // top knows down -> top can't be celeb
                top++;
            else if (mat[down][top])        // down knows top -> down can't be celeb
                down--;
            else {                          // neither knows the other -> eliminate both
                top++;
                down--;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == top) continue;
            if (mat[top][i] == 1 || mat[i][top] == 0) return -1;
        }
        return top;
    }
};
