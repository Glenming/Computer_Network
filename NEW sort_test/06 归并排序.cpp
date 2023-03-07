#include"myhead.h"

//lowΪ��1�������ĵ�1��Ԫ�أ�iָ���1��Ԫ��,midΪ��1�����������1��Ԫ��
//mid+1Ϊ�ڶ�����������ĵ�һ��Ԫ��

void Merge(int* arr, int low, int mid, int high) {
	int i = low, j = mid + 1, k = 0;
	vector<int> temp(high - low + 1, 0);
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	//������ʣ��Ԫ�طŵ����
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= high)
		temp[k++] = arr[j++];

	//���������Ԫ�طŻ�����
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
//�������������
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