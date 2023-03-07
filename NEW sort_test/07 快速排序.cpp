#include"myhead.h"
#include<time.h>
#include<random>

//1. ������������ѡȡһ������ΪΪ��׼
//2. ������Ƚ� �ϴ�ķ��ұߣ���С�ķ����
//3. �ݹ���øú�����ʹ������������

/*��������1.0*/
void Swap(int* arr, int& a, int& b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
int Partition(int* arr,int low,int high){    //����
	int i = low, j = high;
	int key = arr[low];      //ѡȡ��һ��Ԫ����Ϊ�ؼ�Ԫ��
	while (i < j) {
		while(i < j && arr[j] >= key)
			--j;
		while(i < j && arr[i] <= key)
			++i;
		//������Ԫ��
		if (i < j)
			Swap(arr, i, j);
	}
	arr[low] = arr[i];
	arr[i] = key;
	return i;
}

void Quick_Sort(int* arr, int low,int high) {
	if (low < high) {
		int pivote = Partition(arr, low, high);    //��������ֵ
		Quick_Sort(arr, low, pivote-1 );
		Quick_Sort(arr, pivote + 1, high);
	}
}

/*
	����������2.0���������Ϊ����ʽ��
		----���ڵ����������ͬԪ�أ����Կ��ٵõ����
*/
vector<int> partition(int* arr, int low, int hight);

//����
void myswap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
void quickSort_2_0(int* arr, int low, int hight) {
	if (low >= hight) {
		return;
	}
	srand((unsigned)time(NULL));
	myswap(arr[hight], arr[low + rand() % (hight - low + 1)]);
	vector<int> ans;
	ans = partition(arr, low,hight);
	quickSort_2_0(arr, low, ans[0] - 1);
	quickSort_2_0(arr, ans[1] + 1, hight);
}

vector<int> partition(int* arr, int low, int hight) {
	int less = low-1, more = hight;           //  less��< �м�ֵ���ұ߽�   more��> �м�ֵ����߽�
	while (low < more) {
		if (arr[low] < arr[hight])
			myswap(arr[++less], arr[low++]);
		else if (arr[low] > arr[hight])
			myswap(arr[--more], arr[low]);
		else
			++low;
	}
	myswap(arr[more], arr[hight]);
	return { less + 1,more };
}





int main321() {
	int arr[6] = { 5,8,4,3,2,1 };
	quickSort_2_0(arr, 0, 5 );
	for (auto& x : arr) {
		cout << x << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}