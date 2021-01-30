#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void push_back_mutable(int*& arr, int& n, int value);
void push_front_mutable(int*& arr, int& n, int value);



void main()
{
	setlocale(LC_ALL, "Rus");

	int n;	//Размер массива
	int nplus;

	cout << "ВВедите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	// дописать алгоритм добавления элемента в массив

	push_back_mutable(arr, n, value);

	//buffer = nullptr;		// указатель на ноль
	//delete[] buffer;

	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	push_front_mutable(arr, n, value);
	Print(arr, n);

	delete[] arr;
}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void push_back_mutable(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	arr = buffer;		// можно сказать заменяем массив arr на массив brr
	arr[n] = value;
	n++;
}


//Добавляет значение в начало массива
void push_front_mutable(int*& arr, int& n, int value)
{
	// 1. Создаём буферный массив нужного размера
	int* buffer = new int[n + 1]{};
	// 2. Копируем значения из исходного массива в буферный (со смещением на 1 элемент)
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	// 3. Удаляем массив
	delete[] arr;
	// 4. Подменяaем указатель на адрес нового массива
	arr = buffer;
	// 5. Добавляем значение в начало массива
	arr[0] = value;
	// 6. Увеличиваем замер массива
	n++;
}