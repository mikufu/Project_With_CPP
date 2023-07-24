//#include <iostream>
//
//using namespace std;
//
//template<typename T>
//void my_swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//template<class T>
//void my_sort(T& arr, int size)
//{
//	int i = 0; int j = 0;
//	for (i = 0; i < size; i++)
//	{
//		int max = i;
//		for (j = i + 1; j < size; j++)
//		{
//			max = (arr[max] > arr[j]) ? max : j;
//		}
//		if (arr[max] > arr[i])
//			my_swap(arr[i], arr[max]);
//	}
//}
//
//template<class T>
//void printArray(T& arr, int size)
//{
//	for (int i = 0; i < size; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//}
//
//void test01()
//{
//	int arr[5] = { 1, 3, 2, 9, 2 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printArray(arr, size);
//
//	my_sort(arr, size);
//
//	printArray(arr, size);
//}
//
//void test02()
//{
//	char arr[5] = { 'a','c','d','b', 'e'};
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	printArray(arr, size);
//
//	my_sort(arr, size);
//
//	printArray(arr, size);
//}
//
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}