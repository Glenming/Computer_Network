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
	bool flag = true;                //��ӱ�ʾflag ���Ѿ���������Ҫ��ʱ ֱ�ӽ���ѭ��
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
//ð������ ʱ�临�Ӷ�O(n2) �ռ临�Ӷ�O(1) �ȶ�����

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