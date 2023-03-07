#include"myhead.h"

void Count_Sort(vector<int>& arr) {
	int len = arr.size();
	if (len < 2) return;

	//1. 找到数组的最大值
	int max_num = arr[0];
	for (int i = 1; i < len; ++i) {
		if (max_num < arr[i]) {
			max_num = arr[i];
		}
	}
	
	//2. 计数统计
	vector<int> count(max_num + 1, 0);
	for (auto& x : arr) {
		++count[x];
	}
	int m = 0;
	for (int i = 0; i < max_num + 1; ++i) {
		while (count[i] > 0) {
			arr[m++] = i;
			--count[i];
		}
	}
}
int main08() {
	vector<int> vi = { 5,8,4,3,1,2 };
	Count_Sort(vi);
	for (auto& x : vi) {
		cout << x << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}