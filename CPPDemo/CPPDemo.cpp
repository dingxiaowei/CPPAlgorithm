/*
C++常见算法
*/
#include <iostream>
using namespace std;

//快速排序，找一个基准数，比它小的放左边，比它大的放右边
void QuickSort(int arr[], int left, int right) {
	if (left >= right)
		return;
	//选取最左边的元素作为基准元素
	int num = arr[left];
	//定义首尾指针
	int start = left;
	int end = right;
	//指针未相交
	while (start < end) {
		//先移动右边的指针
		while (start < end && arr[end] >= num)
			end--;
		//再移动左边的指针
		while (start < end && arr[start] <= num)
			start++;
		//两指针终止但没相交，交换元素
		if (start < end) {
			int t = arr[start];
			arr[start] = arr[end];
			arr[end] = t;
		}
	}
	//两指针相交，将基准元素放入指针相交的位置
	arr[left] = arr[start];
	arr[start] = num;
	//分别对基准元素左右元素进行快排
	QuickSort(arr, left, start - 1);
	QuickSort(arr, start + 1, right);
}

int main()
{
	//冒泡排序
	//正序
	int arr[] = { 9,8,7,4,5,3,1,2,6 };
	int begin = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;

	cout << "======打印原数组========" << endl;
	for (int i = 0; i <= end; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	QuickSort(arr, begin, end);
	cout << "======快速排序正序排列========" << endl;
	for (int i = 0; i <= end; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < end; i++)
	{
		for (int j = 0; j < end - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "======冒泡正序排列========" << endl;
	for (int i = 0; i <= end; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//倒序
	for (int i = 0; i < end; i++) {
		for (int j = end; j >= i; j--) {
			if (arr[j] < arr[j + 1])
			{
				//a = a + b;
				//b = a - b;
				//a = a - b;
				arr[j] = arr[j] + arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] = arr[j] - arr[j + 1];
			}
		}
	}

	cout << "======冒泡倒序排列========" << endl;
	for (int i = 0; i <= end; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "======打印乘法口诀表========" << endl;
	//九宫格
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << "*" << i << "=" << j * i << "\t";
		}
		cout << endl;
	}

	cout << "======双重循环打印长方形===" << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 14; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << "=====双重循环打印等腰梯形===" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6 - i; j++)
		{
			cout << " ";
		}
		for (int j = 6 - i; j < 14; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << "=====双重循环打印平行四边形===" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6 - i; j++)
		{
			cout << " ";
		}
		for (int j = 6 - i; j < 14 - i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << "======双重循环打印等腰三角形=====" << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6 - i; j++) {
			cout << " ";
		}
		for (int j = 6 - i; j < 6 + i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}