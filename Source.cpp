#include <iostream>

using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void push_back_mutable(int*& arr, int& n, int value);
void push_front_mutable(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);

void erase(int*& arr, int& n, int index);

void main()
{
	setlocale(LC_ALL, "Rus");

	int n;	//������ �������
	int nplus;

	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	// �������� �������� ���������� �������� � ������

	push_back_mutable(arr, n, value);

	//buffer = nullptr;		// ��������� �� ����
	//delete[] buffer;

	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	push_front_mutable(arr, n, value);
	Print(arr, n);
	
	int index;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	//cout << "������� ��������� �������� ��������: "; cin >> value;
	pop_back(arr, n);
	Print(arr, n);

	cout << "----------------------------------------------------" << endl;

	pop_front(arr, n);
	Print(arr, n);

	cout << "----------------------------------------------------" << endl;

	cout << "������� ������ ���������� ��������: "; cin >> index;
	erase(arr, n, index);
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
	arr = buffer;		// ����� ������� �������� ������ arr �� ������ brr
	arr[n] = value;
	n++;
}


//��������� �������� � ������ �������
void push_front_mutable(int*& arr, int& n, int value)
{
	// 1. ������ �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	// 2. �������� �������� �� ��������� ������� � �������� (�� ��������� �� 1 �������)
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	// 3. ������� ������
	delete[] arr;
	// 4. �������a�� ��������� �� ����� ������ �������
	arr = buffer;
	// 5. ��������� �������� � ������ �������
	arr[0] = value;
	// 6. ����������� ����� �������
	n++;
}


void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	//1 �������
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}*/

	/*for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}*/

	//2 �������
	for (int i = 0; i < n; i++)
	{
		//if (i < index)  buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
		//(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
		(i < index) ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		
	}
	
	


	delete[] arr;

	arr = buffer;
	arr[index] = value;
	n++;

}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	arr = buffer; 
}

void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;
	arr = buffer;

}

void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[--n];

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}

	
	


	delete[] arr;

	arr = buffer;
	
}