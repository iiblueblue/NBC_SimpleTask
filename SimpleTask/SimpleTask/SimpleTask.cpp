#include <iostream>
using namespace std;

// �հ踦 ���ϴ� �Լ�
double SumArray(const double input_array[], int array_size)
{
	double sum_value = 0;
	for (int i = 0; i < array_size; i++)
	{
		sum_value += input_array[i];
	}

	return sum_value;
}

// ����� ���ϴ� �Լ�
double AverageArray(const double input_array[], int array_size)
{
	double sum_value = SumArray(input_array, array_size);
	double average_value = sum_value / array_size;

	return average_value;
}

// �������� ���� �Լ�(���� ����)
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
			// �ּڰ� ã��
			if (min_value >= input_array[i])
			{
				min_value = input_array[i];
				min_value_index = i;
			}
		}

		// �ڸ� �ٲٱ�(�ּڰ� ���� ������)
		swap_container = input_array[j];
		input_array[j] = min_value;
		input_array[min_value_index] = swap_container;
	}
}

// �������� ���� �Լ�(���� ����)
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
			// �ִ� ã��
			if (max_value <= input_array[i])
			{
				max_value = input_array[i];
				max_value_index = i;
			}
		}

		// �ڸ� �ٲٱ�(�ִ� ���� ������)
		swap_container = input_array[j];
		input_array[j] = max_value;
		input_array[max_value_index] = swap_container;
	}
}

int main()
{
	const int kArrayMaxSize = 5;
	double input_array[kArrayMaxSize];

	// ���� 5���� �Է� �޾� �迭�� ����
	for (int i = 0; i < kArrayMaxSize; i++)
	{
		cout << i << "��° ���ڸ� �Է��ϼ��� : ";
		cin >> input_array[i];
	}

	// �հ� ���ϱ�
	cout << "�հ� : " << SumArray(input_array, kArrayMaxSize) << endl;

	// ��� ���ϱ�
	cout << "��� : " << AverageArray(input_array, kArrayMaxSize) << endl;

	// �迭 �����ϱ�
	int sort_type;
	
	cout << "�迭�� �����մϴ�[�������� = 1 / �������� = 2]";
	cin >> sort_type;

	if (sort_type == 1)
	{
		SortAscending(input_array, kArrayMaxSize);
	}
	else if (sort_type == 2)
	{
		SortDescending(input_array, kArrayMaxSize);
	}
	else
	{
		cout << "�Է¿� ������ �ֽ��ϴ�. ������ ������� �ʾҽ��ϴ�." << endl;
		return -1;
	}

	cout << "[";
	for (int i = 0; i < kArrayMaxSize; i++)
	{
		cout << input_array[i] << ", ";
	}
	cout << "\b\b]" << endl;

	return 0;
}