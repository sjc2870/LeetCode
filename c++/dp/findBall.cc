#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    typedef enum {left, right} direct;
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        /* 用一个数组判断小球的当前列坐标 */
        vector<int> ball_at_column(column);
        for(int i = 0; i < column; ++i) {
            ball_at_column[i] = i;
        }

        for(int i = 0;i < column; ++i) {
            direct flag = grid[0][ball_at_column[i]] == 1 ? right : left;
            for(int j = 0; j < row; ++j) {
                /* 进入新的坐标，判断方向 */
                flag = grid[j][ball_at_column[i]] == 1 ? right : left;
                /* 判断在箱子角落被卡住的情况 */
                if((ball_at_column[i] == 0 && flag == left) || (ball_at_column[i] == column-1 && flag == right)) {
                    ball_at_column[i] = -1;
                    break;
                /* 判断是对角的情况 */
                }else if((flag == left && grid[j][ball_at_column[i]-1] == 1) || (flag == right && grid[j][ball_at_column[i]+1] == -1)) {
                    ball_at_column[i] = -1;
                    break;
                /* 如果方向向右，则列坐标+1*/
                }else if(flag == right) {
                    ++ball_at_column[i];
                /* 否则列坐标-1 */
                }else if(flag == left) {
                    --ball_at_column[i];
                }
            }
        }
        return ball_at_column;
    }
};

int main(){
    vector<vector<int>> pa {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    Solution so;
    auto ret = so.findBall(pa);
    for(auto i: ret) {
        printf("%d ",i);
    }
    printf("\n");
}
