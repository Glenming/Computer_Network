#include"myhead.h"

template <class T> 
void Swap(T& a, T& b) {
	if (a > b) {
		T temp = a;
		a = b;
		b = temp;
	}
}
void Bubble_Sort1(int *arr,int n) {
	bool flag = true;                //添加标示flag 当已经满足排序要求时 直接结束循环
	for (int i = 0; i < n - 1 && flag; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			flag = false;          
			if (arr[j] > arr[j + 1]) {
				Swap(arr[j], arr[j + 1]);
				flag = true;
			}			
		}
	}
}
//冒泡排序 时间复杂度O(n2) 空间复杂度O(1) 稳定排序

int main00() {

	int arr[10] = { 3,4,2,1,5,6,8,9,7,0 };
	Bubble_Sort1(arr, 10);
	for (auto &x : arr) {
		cout << x << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}