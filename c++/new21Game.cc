#include <vector>

/* 算法思想：首先要明确状态为当前分数，抽卡的概率只与当前分数有关
 * 然后明确base case: 当分数为[K,N)时，小于N的概率必然为1
 *                    当分数为[N,K-1+W]时，大于N的概率必然为0
 * 当计算dp[i]时，我们已知道dp[i+1],dp[i+2],...,dp[K+W-1]
 * 当分数为i时，接下来我们可能抽取到1,2,3,...W点，概率相等均为1/W
 * 因为我们已知道分数为i+1,i+2,i+3的概率
 * 所以当分数为i时，概率则为(dp[i+1]+dp[i+2]+dp[i+3]+...+dp[i+W-1])/W
 * 依次类推分数为i-1时，概率为(dp[i]+dp[i+1]+dp[i+2]+...+dp[i+W-2])/W
 * 可以看到有很多的重复项，根据基本的数学知识我们可以算出dp[i-1] = dp[i]+(dp[i]-dp[i+W-1])/W
 */ 

/* 总结：此题的难点有3(处处是难点..)
 * 1. <状态> 不太容易想到把分数作为状态，容易被N K W 概率这几个变量给搞蒙，无从下手
 * 2. <base case> 此题的base case也不太容易想到 
 * 3. <状态转移方程> 此题的状态有点自顶向下的意思，而不是通常的自底向上，也很难想到
 */ 

using namespace std;
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==0)
            return 1.0;
        vector<double> dp(K+W);
        for(int i = K; i <= N && i < K+W; ++i){
            dp[i] = 1.0;
        }
        dp[K-1] = (double)(N-K+1)/W;
        for(int i = K-2; i >= 0; --i) {
            dp[i] = dp[i+1]+(dp[i+1]-dp[i+1+W])/W;
        }
        return dp[0];
    }
};

