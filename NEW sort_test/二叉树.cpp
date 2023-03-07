#include"TreeNode.h"
#include<vector>
#include<random>

class Solution {
public:
	/*二叉树最大直径问题*/
	int maxDiam = 0;  
	int maxDiameter(TreeNode* root) {
		maxdepth(root);
		return maxDiam;
	}

	int maxdepth(TreeNode* root) {
		if (root == nullptr) return 0;

		int left_depth = maxdepth(root->left);
		int right_depth = maxdepth(root->right);
		int sum_depth = left_depth + right_depth;
		maxDiam = max(maxDiam, sum_depth);
		return max(left_depth, right_depth) + 1;
	}

	/*归并排序——本质为后序遍历*/
	//先将左边元素排序好，再将右边元素排序好，然后将两半数组排序
	void mergeSort(int arr[],int low,int hight) {
		if (low >= hight)
			return;

		int mid = low + (hight - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, hight);
		Merge(arr, low, mid, hight);
	}
	void Merge(int* arr, int low, int mid, int hight) {
		vector<int> temp(hight - low + 1, 0);
		int i = low, j = mid + 1, k = 0;
		while (i <= mid && j <= hight) {
			if (arr[i] < arr[j])
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		while (i <= mid)
			temp[k++] = arr[i++];
		while (j <= hight)
			temp[k++] = arr[j++];

		k = 0;
		while (low <= hight) {
			arr[low++] = temp[k++];
		}
	}

	/*快速排序——本质为先序排序*/
	//先将一个元素排序好，然后将剩下元素排序好
	vector<int> sortArray(vector<int>& nums) {
		quicksort(nums, 0, nums.size() - 1);
		return nums;
	}
	void quicksort(vector<int>& nums, int low, int hight) {
		if (low >= hight)
			return;
		
		//随机数
		/*srand((unsigned)time(NULL));
		myswap(nums[low], nums[low + rand() % (hight - low + 1)]);*/

		myswap(nums[low], nums[getrd(low, hight)]);
		int p = partition(nums, low, hight);
		quicksort(nums, low, p - 1);
		quicksort(nums, p + 1, hight);
	}
	int partition(vector<int>& nums, int low, int hight) {
		int i = low, j = hight;
		int key = nums[i];
		while (i < j) {
			while (i < j && nums[j] >= key)
				--j;
			while (i < j && nums[i] <= key)
				++i;

			if (i < j) {
				myswap(nums[i], nums[j]);
			}
		}
		nums[low] = nums[i];
		nums[i] = key;
		return i;
	}

	//交换
	void myswap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	//获取随机数
	int getrd(const int& min, const int& max) {
		random_device rd;
		return min + rd() % (max - min + 1);
	}



	//void swap(int& a, int& b) {
	//	if (a == b)
	//		return;
	//	a = a ^ b;
	//	b = a ^ b;
	//	a = a ^ b;
	//}
	//int getrd11(const int& min, const int& max) {
	//	random_device rd;
	//	return min + rd() % (max - min);
	//}
	//int* Mypartition(vector<int>& nums, int L, int R) {
	//	int less(L - 1), more(R);
	//	int i(L);
	//	while (i < more) {
	//		if (nums[i] < nums[R]) {
	//			swap(nums[++less], nums[i++]);
	//		}
	//		else if (nums[i] > nums[R]) {
	//			swap(nums[i], nums[--more]);
	//		}
	//		else
	//			i++;
	//	}
	//	swap(nums[more], nums[R]);
	//	return new int[2]{ less, more + 1 };
	//}
	//void process(vector<int>& nums, int L, int R) {
	//	if (L < R) {
	//		// cout<<"L ="<<L<<"\t R="<<R<<endl;
	//		swap(nums[getrd11(L, R)], nums[R]);
	//		int* p = Mypartition(nums, L, R);
	//		process(nums, L, p[0]);
	//		process(nums, p[1], R);
	//	}
	//}
	//vector<int> sortArray22(vector<int>& nums) {
	//	process(nums, 0, nums.size() - 1);
	//	return nums;
	//}
};

int main1212() {
	vector<int> arr = { 5,8,4,3,2,1 };
	Solution s1;
	s1.sortArray(arr);
	for (auto& x : arr) {
		cout << x << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}