#include"myhead.h"
#include<unordered_map>
#include<algorithm>

class Solution {
public:
	//����֮��
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

	//����֮�͡������������
	vector<vector<int> > two_sum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int low = 0, hight = nums.size() - 1;
		vector<vector<int>> ans;
		while (low < hight) {
			int left = nums[low], right = nums[hight];
			int sum = left + right;
			if (sum < target) {
				while (low < hight && nums[low] == left) ++low;  //�ظ�Ԫ��ֻ����һ��
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

	//����֮�͡������ز��ظ� ��Ϊ0�������
	vector<vector<int> > threesum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > ans;

		//�̶���һ��Ԫ�� ʣ������֮��
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) break;       //�������� ��Ԫ�ش���0 ����������
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