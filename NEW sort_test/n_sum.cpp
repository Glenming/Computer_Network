#include"myhead.h"
#include<unordered_map>
#include<unordered_set>

class Solution {
public:
	/*两数之和*/
	vector<int> twosum(vector<int>& nums, int target) {
		unordered_map<int,int> mp;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = mp.find(target - nums[i]);
			if (it != mp.end()) {
				return { it->second ,i };
			}
			mp[nums[i]] = i;
		}
		return { };
	}

	/*两数之和——返回所有目标数*/   //时间复杂度O(N*logN)
	vector<vector<int>> twosum_target(vector<int>& nums,int start, int target) {
		sort(nums.begin(), nums.end());
		int low = start, hight = nums.size() - 1;
		vector<vector<int>> ans;
		while (low < hight) {
			int left = nums[low], right = nums[hight];
			int sum = left + right;
			if (sum < target) {
				while (low < hight && nums[low] == left) ++low;  //循环去除重复碳元素
			}
			else if (sum > target) {
				while (low < hight && nums[hight] == right) --hight;
			}
			else{
				ans.push_back({ left, right });
				while (low < hight && nums[low] == left) ++low;
				while (low < hight && nums[hight] == right) --hight;
			}
		}
		return ans;
	}
	//三数之和 调用两数之和
	vector<vector<int>> three_sum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (int i = 0; i < nums.size(); ++i) {
			vector<vector<int>> rets = twosum_target(nums, i + 1, 0 - nums[i]);
			for (auto& ret : rets) {
				ret.emplace_back(nums[i]);
				ans.emplace_back(ret);
			}
			//跳过第一个元素重复的情况
			while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
		}
		return ans;
	}

	/*三数之和*/
	vector<vector<int>> threesum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) break;    //递增数组，后面不存在
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			int left = i + 1, right = nums.size() - 1;
			while (left < right) {
				int low = nums[left], hight = nums[right];
				int sum = low + hight;
				if (sum > 0-nums[i]) {
					--right;
				}
				else if (sum<0-nums[i]) {
					++left;
				}
				else{
					ans.push_back({ nums[i], low, hight });
					while (left < right && nums[right] == hight) --right;
					while (left < right && nums[left] == low) ++left;
				}				
			}
		}
		return ans;
	}
};

//int main111() {
//	vector<int> nums = {-1,0,1,2,-1,-4};
//	Solution s1;
//	/*vector<int> ans = s1.twosum(nums, 8);
//	for (auto& x : ans) {
//		cout << x << " ";
//	}
//	cout << endl;*/
//
//	vector<vector<int>> ans = s1.threesum(nums);
//	for (auto& x : ans) {
//		cout << x[0] << "," << x[1] << "," << x[2] << " " << endl;
//	}
//	cout << endl;
//	cout << ans.size() << endl;
//
//
//
//	system("pause");
//	return 0;
//}