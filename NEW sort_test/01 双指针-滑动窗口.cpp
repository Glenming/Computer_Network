#include"myhead.h"
#include<math.h>

class Solution {

public:
	/*01 ��ظ��Ӵ�*/
	//��ָ��һֱ���󴰿ڣ��������ظ�Ԫ�� ��ָ�뿪ʼ��С����
	int lengthOfLongestSubstring(string s) {
		int left = 0, right = 0;
		int ans = 0;
		int window[128] = { 0 };    //���ں��ַ���Ԫ�أ�ʹ������Ч�ʸ���
		while (right < s.size()) {
			while (window[s[right]] >= 1)
				window[s[left++]] = 0;

			++window[s[right]];
			ans = max(ans, right - left + 1);
			++right;
		}
		return ans;
	}

	/*02 ��������---�������������ͷ��������*/
	int maxSubArray(vector<int>& nums) {
		//��̬�滮
		int sum = 0, ans = nums[0];
		for (auto& x : nums) {
			sum = max(sum, sum + x);  //Ҫôȡ��ǰֵ��Ҫôȡ��
			ans = max(ans, sum);      //�������ֵ
		}
		return ans;

		//˫ָ��
		int left = 0,right = 0;
		int ans1 = INT_MIN, window = 0;
		while (right < nums.size()) {

			//01 ���󴰿�
			window += nums[right];
			++right;

			//02 ���½��
			ans1 = max(ans1, window);

			//03 ��С���� (ʹ�ô�����߽�Ϊ����)
			while (window < 0) {
				window -= nums[left];
				++left;
			}
		}
	}
};