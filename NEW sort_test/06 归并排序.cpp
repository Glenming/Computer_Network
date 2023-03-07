#include"myhead.h"

//low为第1有序区的第1个元素，i指向第1个元素,mid为第1有序区的最后1个元素
//mid+1为第二个有序区间的第一个元素

void Merge(int* arr, int low, int mid, int high) {
	int i = low, j = mid + 1, k = 0;
	vector<int> temp(high - low + 1, 0);
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	//两区间剩余元素放到后边
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= high)
		temp[k++] = arr[j++];

	//最后将容器内元素放回数组
	i = low, k = 0;
	while (i <= high)
		arr[i++] = temp[k++];
}

//void Merge02(int* arr, int low, int mid, int high) {
//	int i = low, j = mid + 1, k = 0;
//	vector<int> temp(high - low + 1);
//	while (i <= mid && j <= high) {
//		if (arr[i] < arr[j])
//			temp[k++] = arr[i++];
//		else if (arr[i] > arr[j])
//			temp[k++] = arr[j++];
//	}
//	while (i <= mid)
//		temp[k++] = arr[i++];
//	while (j <= high)
//		temp[k++] = arr[j++];
//
//	k = 0;
//	while (low<= high) {
//		arr[low++] = temp[k++];
//	}
//}
//二叉树后序遍历
void Merge_Sort(int arr[], int low, int high) {
	if (low == high) {
		return;
	}
	int mid = low + (high - low) / 2;
	Merge_Sort(arr, low, mid);
	Merge_Sort(arr, mid + 1, high);
	Merge(arr, low, mid, high);
}



int main101() {
	int arr[6] = { 5,0,4,3,1,2 };
	Merge_Sort(arr, 0, 5 );
	for (auto& x : arr) {
		cout << x << " ";
	}
		cout << endl;

	system("pause");
	return 0;
}