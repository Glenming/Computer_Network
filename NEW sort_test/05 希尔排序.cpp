#include"myhead.h"

void Shell_Sort(int* arr, int n) {
	int gap = n;
	do
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; ++i) {
			int j = i-gap;
			if (arr[j] > arr[i]) {
				int temp = arr[i];
				for (; j >= 0 && temp < arr[j]; j -= gap) {
					arr[j + gap] = arr[j];
				}
				arr[j + gap] = temp;
			}
		}
	} while (gap > 1);
}
int main06() {
	int arr[10] = { 3,4,2,1,5,6,8,9,7,0 };
	Shell_Sort(arr, 10);
	for (auto& x : arr) {
			cout << x << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}