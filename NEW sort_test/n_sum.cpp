#include"myhead.h"
#include<unordered_map>
#include<unordered_set>

class Solution {
public:
	/*����֮��*/
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

	/*����֮�͡�����������Ŀ����*/   //ʱ�临�Ӷ�O(N*logN)
	vector<vector<int>> twosum_target(vector<int>& nums,int start, int target) {
		sort(nums.begin(), nums.end());
		int low = start, hight = nums.size() - 1;
		vector<vector<int>> ans;
		while (low < hight) {
			int left = nums[low], right = nums[hight];
			int sum = left + right;
			if (sum < target) {
				while (low < hight && nums[low] == left) ++low;  //ѭ��ȥ���ظ�̼Ԫ��
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
	//����֮�� ��������֮��
	vector<vector<int>> three_sum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (int i = 0; i < nums.size(); ++i) {
			vector<vector<int>> rets = twosum_target(nums, i + 1, 0 - nums[i]);
			for (auto& ret : rets) {
				ret.emplace_back(nums[i]);
				ans.emplace_back(ret);
			}
			//������һ��Ԫ���ظ������
			while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
		}
		return ans;
	}

	/*����֮��*/
	vector<vector<int>> threesum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) break;    //�������飬���治����
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