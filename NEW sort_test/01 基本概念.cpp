#include"myhead.h"

class DP {
public:

	/*01 �һ���Ǯ*/
	int coinChange(vector<int>& coins, int amount) {
		vector<int> meme(amount + 1,-666);
		return dp(coins, amount,meme);
	}

	int dp(vector<int>& coins, int amount,vector<int>& meme) {
		if (amount == 0) return 0;
		if (amount < 0 ) return -1;

		if (meme[amount] != -666)
			return meme[amount];

		int res = INT_MAX;
		for (auto& coin : coins) {
			int subProblem = dp(coins, amount - coin, meme);

			if (subProblem == -1) continue;

			res = min(res, subProblem + 1);
		}
		meme[amount] = (res == INT_MAX) ? -1 : res;
		return meme[amount];
	}

	int coinChange02(vector<int>& coins, int amount) {
		int Max = amount + 1;
		vector<int> dp(amount + 1, Max);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j < (int)coins.size(); ++j) {
				if (coins[j] <= i) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}

	/*02 �����������*/
	int lengthOfLIS(vector<int>& nums) {
		//01 ����һ��dp���飬��ȷdp����ĺ���  dp[i]��ʾnums[i]�����β������������еĳ���
		vector<int> dp(nums.size(), 1);

		//02 �������� 
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		//03 ����dp[i]��������ֵ
		int ans = 0;
		for (auto& x : dp) {
			ans = max(ans, x);
		}
		return ans;
	}
};

//int main() {
//	vector<int> arr = { 3,2,1,4,5,2,8 };
//	DP s1;
//	cout << s1.lengthOfLIS(arr);
//
//	cout << endl;
//
//	system("pause");
//	return 0;
//}