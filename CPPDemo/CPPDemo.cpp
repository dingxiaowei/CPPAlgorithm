/*
C++常见算法
//排序 冒泡排序、快速排序
//查找 二分查找
//字符串操作 分割、替换
//树操作(遍历)
*/
#include <iostream>
#include <string>
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

//递归方式二分查找
int BinarySearch(int array[], int low, int high, int target) {
	int middle = (low + high) / 2;
	if (low > high) {
		return -1;
	}
	if (target == array[middle]) {
		return middle;
	}
	if (target < array[middle]) {
		return BinarySearch(array, low, middle - 1, target);
	}
	if (target > array[middle]) {
		return BinarySearch(array, middle + 1, high, target);
	}
	return -1;
}

//非递归方式二分查找
int BinarySearch2(int array[], int n, int target) {
	int low = 0, high = n, middle = 0;
	while (low < high) {
		middle = (low + high) / 2;
		if (target == array[middle]) {
			return middle;
		}
		else if (target < array[middle]) {
			high = middle;
		}
		else if (target > array[middle]) {
			low = middle + 1;
		}
	}
	return -1;
}

void StrTest()
{
	/*
	cout << "====输入字符串(字符数组接受的方式)=======" << endl;
	char a[20];
	cin.getline(a,20);
	cout << a << endl;

	cout << "======连续输入两个数字(空格分隔)===========" << endl;
	int m, n;
	cin >> m >> n;
	cout << "m + n = " << m + n << endl;

	cout << "=====输入一个字符===========" << endl;
	char c;
	c = cin.get(); //只能获取一个字符
	cout << c << endl;
	*/
	cout << "=======字符串测试======" << endl;
	//字符串打印
	string str = "hello";
	cout << str << endl;
	//字符串拼接
	str += " world";
	cout << str << endl;
	//字符串的查找
	int index = str.find("llo");
	cout << "llo索引是" << index << endl;
	cout << "第0个字符:" << str[0] << endl;
	//字符串替换
	string str1 = str.replace(0, 2, "111");//从0开始的位置，两个字符被替换
	cout << str1 << endl;
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

	cout << "======二分查找数字3的索引(递归方式)=====" << endl;
	cout << BinarySearch(arr, 0, end, 3) << endl;

	cout << "======二分查找数字3的索引(非递归方式)=====" << endl;
	cout << BinarySearch2(arr, end, 3) << endl;

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

	//StrTest();

	cout << "======整数倒序输出====" << endl;
	int num, sum = 0;
	cin >> num;
	while (num) {
		sum = num % 10 + sum * 10;
		num /= 10;
	}
	cout << sum;
	return 0;
}