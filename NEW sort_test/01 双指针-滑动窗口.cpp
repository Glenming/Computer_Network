#include"myhead.h"
#include<math.h>

class Solution {

public:
	/*01 最长重复子串*/
	//右指针一直扩大窗口，当遇到重复元素 左指针开始缩小窗口
	int lengthOfLongestSubstring(string s) {
		int left = 0, right = 0;
		int ans = 0;
		int window[128] = { 0 };    //对于含字符串元素，使用数组效率更高
		while (right < s.size()) {
			while (window[s[right]] >= 1)
				window[s[left++]] = 0;

			++window[s[right]];
			ans = max(ans, right - left + 1);
			++right;
		}
		return ans;
	}

	/*02 最大子序和---穷举所有正数开头的子数组*/
	int maxSubArray(vector<int>& nums) {
		//动态规划
		int sum = 0, ans = nums[0];
		for (auto& x : nums) {
			sum = max(sum, sum + x);  //要么取当前值，要么取和
			ans = max(ans, sum);      //跟新最大值
		}
		return ans;

		//双指针
		int left = 0,right = 0;
		int ans1 = INT_MIN, window = 0;
		while (right < nums.size()) {

			//01 扩大窗口
			window += nums[right];
			++right;

			//02 更新结果
			ans1 = max(ans1, window);

			//03 缩小窗口 (使得窗口左边界为正数)
			while (window < 0) {
				window -= nums[left];
				++left;
			}
		}
	}
};