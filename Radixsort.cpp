#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void FillArr(int* mas, int n) {
	for (int i = 0; i < n; i++)
		mas[i] = rand() % 100;
}
void ShowArr(int* mas, int n) {
	for (int i = 0; i < n; i++)
		cout << mas[i] << "\t";
	cout << endl;
}
int Two(int num)
{
	int bin = 0, k = 1;
	while (num)
	{
		bin += (num % 2) * k;
		k *= 10;
		num /= 2;
	}
	return bin;
}
int Three(int num)
{
	int bin = 0, k = 1;
	while (num)
	{
		bin += (num % 3) * k;
		k *= 10;
		num /= 3;
	}
	return bin;
}
int Eight(int num)
{
	int bin = 0, k = 1;
	while (num)
	{
		bin += (num % 8) * k;
		k *= 10;
		num /= 8;
	}
	return bin;
}

int getMax(int array[], int n) {
	int max = array[0];
	for (int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

////////////////////////////////////////////////////////////////////////////////
void countingSort2(int array[], int  size, int place) {
	const int max = 2;
	int* output=new int[size];
	int count[max];

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 2]++;

	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--) {
		output[count[(array[i] / place) % 2] - 1] = array[i];
		count[(array[i] / place) % 2]--;
	}

	for (int i = 0; i < size; i++)
		array[i] = output[i];
	delete[] output;
}

void radixsort2(int array[], int size) {
	int max = getMax(array, size);
	for (int place = 1; max / place > 0; place *= 2)
		countingSort2(array, size, place);
}


////////////////////////////////////////////////

void countingSort3(int array[], int  size, int place) {
	const int max = 3;
	int* output = new int[size];
	int count[max];

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 3]++;

	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--) {
		output[count[(array[i] / place) % 3] - 1] = array[i];
		count[(array[i] / place) % 3]--;
	}

	for (int i = 0; i < size; i++)
		array[i] = output[i];
	delete[] output;
}

void radixsort3(int array[], int size) {
	int max = getMax(array, size);
	for (int place = 1; max / place > 0; place *= 3)
		countingSort3(array, size, place);
}

/////////////////////////////////////////

void countingSort8(int array[], int  size, int place) {
	const int max = 8;
	int* output = new int[size];
	int count[max];

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 8]++;

	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--) {
		output[count[(array[i] / place) % 8] - 1] = array[i];
		count[(array[i] / place) % 8]--;
	}

	for (int i = 0; i < size; i++)
		array[i] = output[i];
	delete[] output;
}

void radixsort8(int array[], int size) {
	int max = getMax(array, size);
	for (int place = 1; max / place > 0; place *= 3)
		countingSort8(array, size, place);
}

/////////////////////////////////////////////

int main() {
	srand(time(NULL));
	int n;
	cout << "Input size: ";
	cin >> n;
	int* mas = new int[n];
	FillArr(mas, n);
	cout << "Source array:             ";
	ShowArr(mas, n);
	int* newmas1 = new int[n];
	int* newmas2 = new int[n];
	int* newmas3 = new int[n];
	cout << "\nBinary array:           ";
	for (int i = 0; i < n; i++)
		newmas1[i] = Two(mas[i]);
	ShowArr(newmas1, n);
	cout << "Array In ternary system: ";
	for (int i = 0; i < n; i++)
		newmas2[i] = Three(mas[i]);
	ShowArr(newmas2, n);
	cout << "Array In octal system:    ";
	for (int i = 0; i < n; i++)
		newmas3[i] = Eight(mas[i]);
	ShowArr(newmas3, n);

	radixsort2(newmas1, n);
	cout << "\n\nBinary Radix Sort:      ";
	ShowArr(newmas1, n);
	radixsort3(newmas2, n);
	cout << "Ternary Radix Sort:     ";
	ShowArr(newmas2, n);
	radixsort8(newmas3, n);
	cout << "Octal Radix Sort:       ";
	ShowArr(newmas3, n);

	delete[] mas;
	delete[] newmas1;
	delete[] newmas2;
	delete[] newmas3;
	system("pause");
	return 0;
}

