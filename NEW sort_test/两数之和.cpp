#include"myhead.h"
#include<unordered_map>
#include<algorithm>

class Solution {
public:
	//两数之和
	vector<int> twosum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = mp.find(target - nums[i]);
			if (it != mp.end()) {
				return { i,it->second };
			}
			mp[nums[i]] = i;
		}
		return { };
	}

	//两数之和——返回数组对
	vector<vector<int> > two_sum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int low = 0, hight = nums.size() - 1;
		vector<vector<int>> ans;
		while (low < hight) {
			int left = nums[low], right = nums[hight];
			int sum = left + right;
			if (sum < target) {
				while (low < hight && nums[low] == left) ++low;  //重复元素只计算一个
			}
			else if (sum > target) {
				while (low < hight && nums[hight] == right) --hight;
			}
			else {
				ans.emplace_back(left, right);
				while (low < hight && nums[low] == left) ++low;
				while (low < hight && nums[hight] == right) --hight;
			}
		}
		return ans;
	}

	//三数之和——返回不重复 和为0的数组对
	vector<vector<int> > threesum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > ans;

		//固定第一个元素 剩余两数之和
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) break;       //递增数组 首元素大于0 不满足条件
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			
			int low = i + 1, hight = nums.size() - 1;
			while (low < hight) {
				int left = nums[low], right = nums[hight];
				int sum = left + right;
				if (sum < 0 - nums[i])
					++low;
				else if (sum > 0 - nums[i])
					--hight;
				else {
					ans.push_back({ nums[i], low, hight });
					while (low < hight && nums[low] == left) ++low;
					while (low < hight && nums[hight] == right) --hight;
				}
			}
		}
		return ans;
	}
};