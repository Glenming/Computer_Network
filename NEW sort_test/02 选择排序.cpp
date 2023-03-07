#include"myhead.h"

template <class T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

	
void Select_Sort(int *arr,int n) {
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (arr[min] != arr[i]) {
			Swap(arr[min], arr[i]);
		}
	}
}

//ѡ������ ʱ�临�Ӷ�O(n2) �ռ临�Ӷ�O(1) ���ȶ�
int main02() {
	int arr[10] = { 3,4,2,1,5,6,8,9,7,0 };
	Select_Sort(arr, 10);
	for (auto& x : arr) {
		cout << x << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}