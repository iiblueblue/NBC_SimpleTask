#include <iostream>
using namespace std;

// 합계를 구하는 함수
double SumArray(const double input_array[], int array_size)
{
	double sum_value = 0;
	for (int i = 0; i < array_size; i++)
	{
		sum_value += input_array[i];
	}

	return sum_value;
}

// 평균을 구하는 함수
double AverageArray(const double input_array[], int array_size)
{
	double sum_value = SumArray(input_array, array_size);
	double average_value = sum_value / array_size;

	return average_value;
}

// 오름차순 정렬 함수(선택 정렬)
void SortAscending(double input_array[], int array_size)
{
	double min_value;
	int min_value_index = 0;
	double swap_container;

	for (int j = 0; j < array_size; j++)
	{
		min_value = input_array[j];

		for (int i = j; i < array_size; i++)
		{
			// 최솟값 찾기
			if (min_value >= input_array[i])
			{
				min_value = input_array[i];
				min_value_index = i;
			}
		}

		// 자리 바꾸기(최솟값 제일 앞으로)
		swap_container = input_array[j];
		input_array[j] = min_value;
		input_array[min_value_index] = swap_container;
	}
}

// 내림차순 정렬 함수(선택 정렬)
void SortDescending(double input_array[], int array_size)
{
	double max_value;
	int max_value_index = 0;
	double swap_container;

	for (int j = 0; j < array_size; j++)
	{
		max_value = input_array[j];

		for (int i = j; i < array_size; i++)
		{
			// 최댓값 찾기
			if (max_value <= input_array[i])
			{
				max_value = input_array[i];
				max_value_index = i;
			}
		}

		// 자리 바꾸기(최댓값 제일 앞으로)
		swap_container = input_array[j];
		input_array[j] = max_value;
		input_array[max_value_index] = swap_container;
	}
}

int main()
{
	const int kArrayMaxSize = 5;
	double input_array[kArrayMaxSize];

	// 숫자 5개를 입력 받아 배열에 저장
	for (int i = 0; i < kArrayMaxSize; i++)
	{
		cout << i << "번째 숫자를 입력하세요 : ";
		cin >> input_array[i];
	}

	// 합계 구하기
	cout << "합계 : " << SumArray(input_array, kArrayMaxSize) << endl;

	// 평균 구하기
	cout << "평균 : " << AverageArray(input_array, kArrayMaxSize) << endl;

	// 배열 정렬하기
	int sort_type;
	
	cout << "배열을 정렬합니다[오름차순 = 1 / 내림차순 = 2]";
	cin >> sort_type;

	if (sort_type == 1) // 오름차순
	{
		SortAscending(input_array, kArrayMaxSize);
	}
	else if (sort_type == 2) // 내림차순
	{
		SortDescending(input_array, kArrayMaxSize);
	}
	else // 1, 2가 아닌 다른 숫자를 입력했을 경우
	{
		// 오류 메시지 출력
		cout << "입력에 오류가 있습니다. 정렬은 실행되지 않았습니다." << endl;
		return -1;
	}

	// 배열 전체 출력
	cout << "[";
	for (int i = 0; i < kArrayMaxSize; i++)
	{
		cout << input_array[i] << ", ";
	}
	cout << "\b\b]" << endl;

	return 0;
}