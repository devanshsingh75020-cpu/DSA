class Solution {
public:
    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> old = board;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int cnt = 0;

                for(int k = 0; k < 8; k++) {

                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if(ni >= 0 && ni < m &&
                       nj >= 0 && nj < n &&
                       old[ni][nj] == 1) {

                        cnt++;
                    }
                }

                if(old[i][j] == 1) {
                    // Alive cell
                    if(cnt < 2 || cnt > 3)
                        board[i][j] = 0;
                }
                else {
                    // Dead cell
                    if(cnt == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};