#include"myhead.h"

void Insert_Sort(int* arr, int n) {
	int j,temp = 0;
	for (int i = 1; i < n; ++i) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; --j) {
			arr[j + 1] = arr[j];
		}
		arr[j+1] = temp;
	}
}

void Insert_Sort2(int* arr, int n) {
	int j, temp = 0;
	for (int i = 1; i < n; ++i) {
		int temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j]>temp; --j) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void Insert_Sort03(int* arr, int n) {
	int j, temp = 0;
	for (int i = 1; i < n; ++i) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; --j) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
int main03() {
	int arr[10] = { 3,4,2,1,5,6,8,9,7,0 };
	Insert_Sort03(arr, 10);
	for (auto& x : arr) {
		cout << x << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}