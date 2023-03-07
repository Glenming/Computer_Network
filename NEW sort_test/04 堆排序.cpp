#include"myhead.h"

//堆排序 
//1.将无续数组构建一个堆，根据升序降序规则构建大顶堆；
//
//2.将堆顶元素与末尾元素互换，将最大元素沉到数组末端；
//
//3.重新调整结构，使其重新满足堆的定义，继续重复步骤2，直到整个序列有序。
//void AdjustHeap(int *arr, int i,int n);
//void myswap(int* arr, int a, int b);
//void Heap_Sort(int* arr, int n) {
//	//1.构建大顶堆
//	for (int i = n / 2 - 1; i >= 0; --i) {  //从最下端非叶子结点开始 i为非叶子结点的最大值 i减小，逐个遍历非叶子结点
//		AdjustHeap(arr, i, n);
//	}
//
//	//2.调整堆结构+堆顶元素与末尾元素互换
//	for (int m = n - 1; m > 0; --m) {   //不断将较大元素置换到后边
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
	//01 将无序数组构建成大顶堆
	for (int i = n / 2 - 1; i >= 0; --i) {
		Adjust_Heap(arr, i, n);
	}

	//02 交换堆顶与末尾叶子结点，使大元素下沉
	//03 重新调整结构 构造大顶堆
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