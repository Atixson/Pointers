#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int value, int index_insert);
int* erase(int arr[], int& n, int index_erase);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращение к элементам массива через оператор индексирования:
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращение к элементам через Арифметику указателей через оператор разыменования
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2) Копируем все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) Удалаяем исходный массив:
	delete[] arr;

	//4) Подменяем адрес старого массива адресом нового массива:
	arr = buffer;

	//5) Только после этого в массив 'arr' можно добавить значение:
	arr[n] = value;

	//5) После того как в массив добавился элемент, количество его элементов увеличивается
	n++;

	//6) Возвращаем новый массив:
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}

int* insert(int arr[], int& n, int value, int index_insert)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		if (i < index_insert)
		{
			buffer[i] = arr[i];
		}
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[index_insert - 1] = value;
	n++;
	return arr;
}
int* erase(int arr[], int& n, int index_erase)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		if (i < index_erase)
		{
			buffer[i] = arr[i];
		}
		buffer[i + 1] = arr[i + 2];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}