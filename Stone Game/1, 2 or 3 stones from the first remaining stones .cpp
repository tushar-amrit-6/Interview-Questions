class Solution {
public:
int dp[50001] ;
int dfs(vector<int>& sv, int p) {
    if (p >= sv.size())
        return 0;
    if (dp[p] == INT_MIN)
        for (auto i = 0, sum = 0; i < 3 && p + i < sv.size(); ++i) {
            sum += sv[p + i];
            dp[p] = max(dp[p], sum - dfs(sv, p + i + 1));
        }
    return dp[p];
}
string stoneGameIII(vector<int>& sv) {
    for(int i=0;i<50001;i++)
        dp[i]=INT_MIN;

    auto res = dfs(sv, 0);
    return res == 0 ? "Tie" : res < 0 ? "Bob" : "Alice";
}
};
