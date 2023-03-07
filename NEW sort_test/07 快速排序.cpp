#include"myhead.h"
#include<time.h>
#include<random>

//1. 在无序数组中选取一个数作为为基准
//2. 与该数比较 较大的放右边，较小的放左边
//3. 递归调用该函数，使整个数组有序

/*快速排序1.0*/
void Swap(int* arr, int& a, int& b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
int Partition(int* arr,int low,int high){    //分区
	int i = low, j = high;
	int key = arr[low];      //选取第一个元素作为关键元素
	while (i < j) {
		while(i < j && arr[j] >= key)
			--j;
		while(i < j && arr[i] <= key)
			++i;
		//交换两元素
		if (i < j)
			Swap(arr, i, j);
	}
	arr[low] = arr[i];
	arr[i] = key;
	return i;
}

void Quick_Sort(int* arr, int low,int high) {
	if (low < high) {
		int pivote = Partition(arr, low, high);    //计算枢轴值
		Quick_Sort(arr, low, pivote-1 );
		Quick_Sort(arr, pivote + 1, high);
	}
}

/*
	·快速排序2.0（将结果分为三段式）
		----用于当包含许多相同元素，可以快速得到结果
*/
vector<int> partition(int* arr, int low, int hight);

//交换
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
	int less = low-1, more = hight;           //  less：< 中间值的右边界   more：> 中间值的左边界
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