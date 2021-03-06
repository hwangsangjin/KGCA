#include <algorithm>
#include <iostream>

using namespace std;

// 버블 정렬
void bubble_sort(int data[], int n)
{
	// data[n-1]부터 data[i]까지 이동하면서
	// 인접한 두 원소를 비교 & 교환
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = n - 1; j > i; j--)
		{
			if (data[j] < data[j - 1])
			{
				swap(data[j], data[j - 1]);
			}
		}

	}
}

// 선택 정렬
void selection_sort(int data[], int n)
{
	// data[i], data[i+1], ..., data[n-1]에 대해
	// 최소값을 갖는 인덱스(idx)를 알아낸 후,
	// data[i]와 data[idx]를 교환
	for (size_t i = 0; i < n - 1; i++)
	{
		int idx = i;

		for (size_t j = i + 1; j < n; j++)
		{
			if (data[j] < data[idx])
			{
				idx = j;
			}
		}

		swap(data[i], data[idx]);
	}
}

// 삽입 정렬
void insertion_sort(int data[], int n)
{
	// data[i]를 임시 변수(key)에 복사한 후,
	// data[i-1]부터 data[0]까지 차례로 검사하면서
	// key를 삽입하기에 적절한 위치를 찾을 때까지
	// 각각의 원소 값을 오른쪽 원소로 복사하고,
	// 적절한 위치에 key 값을 삽입(복사)
	for (size_t i = 1; i < n; i++)
	{
		int key = data[i];
		int j = i - 1;

		while (j >= 0 && data[j] > key)
		{
			data[j + 1] = data[j];
			j--;
		}

		data[j + 1] = key;
	}
}

int main()
{
	int data[] = { 4, 2, 3, 5, 1 };
	
	bubble_sort(data, 5);
	selection_sort(data, 5);
	insertion_sort(data, 5);

	for (auto& n : data)
	{
		cout << n << " ";
	}
	cout << endl;

	return 0;
}