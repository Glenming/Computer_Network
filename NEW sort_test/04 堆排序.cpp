#include"myhead.h"

//������ 
//1.���������鹹��һ���ѣ�������������򹹽��󶥶ѣ�
//
//2.���Ѷ�Ԫ����ĩβԪ�ػ����������Ԫ�س�������ĩ�ˣ�
//
//3.���µ����ṹ��ʹ����������ѵĶ��壬�����ظ�����2��ֱ��������������
//void AdjustHeap(int *arr, int i,int n);
//void myswap(int* arr, int a, int b);
//void Heap_Sort(int* arr, int n) {
//	//1.�����󶥶�
//	for (int i = n / 2 - 1; i >= 0; --i) {  //�����¶˷�Ҷ�ӽ�㿪ʼ iΪ��Ҷ�ӽ������ֵ i��С�����������Ҷ�ӽ��
//		AdjustHeap(arr, i, n);
//	}
//
//	//2.�����ѽṹ+�Ѷ�Ԫ����ĩβԪ�ػ���
//	for (int m = n - 1; m > 0; --m) {   //���Ͻ��ϴ�Ԫ���û������
//		myswap(arr, 0, m);
//		AdjustHeap(arr, 0, m);
//	}
//	
//}
//void AdjustHeap(int* arr, int i, int n) {
//    int temp = arr[i];
//	for (int j = 2 * i + 1; j < n; j=2*j+1) {
//		if (j<n-1 && arr[j] < arr[j + 1]) {
//			++j;
//		}
//		if (temp >= arr[j]) {
//			break;
//		}
//		arr[i]=arr[j];
//		i = j;
//	}
//	arr[i] = temp;
//}

void myswap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void Adjust_Heap(int* arr, int i, int n) {
	int temp = arr[i];
	for (int j = 2 * i + 1; j < n; j = 2 * j + 1) {
		if (j < n - 1 && arr[j] < arr[j + 1])
			++j;
		if (arr[j] <= temp)
			break;
		arr[i] = arr[j];
		i = j;
	}
	arr[i] = temp;
}


void HeapSort(int* arr, int n) {
	//01 ���������鹹���ɴ󶥶�
	for (int i = n / 2 - 1; i >= 0; --i) {
		Adjust_Heap(arr, i, n);
	}

	//02 �����Ѷ���ĩβҶ�ӽ�㣬ʹ��Ԫ���³�
	//03 ���µ����ṹ ����󶥶�
	for (int m = n - 1; m > 0; --m) {
		myswap(arr, 0, m);
		Adjust_Heap(arr, 0, m);
	}
}


int main04() {

	int arr[10] = { 3,4,2,1,5,6,8,9,7,0 };
	HeapSort(arr, 10);
	for (auto& x : arr) {
		cout << x << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}