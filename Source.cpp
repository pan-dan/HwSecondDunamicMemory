#include <iostream>
//#include "prototip.h"

//using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define One_DimensionalArray
#define DYNAMIC_MEMORY_2
#define Delimetr "----------------------------------------------"
#define noname

template <typename T>T** Allocate(const int m, const int n);
template <typename T>void Clear(T** arr, int& m);

template <typename T>void Random(T& variable);

template <typename T>void FillRand(T** arr, const int m, const int n);

template <typename T>void Print(T** arr, const int m, const int n);

template <typename T>void push_row_back(T**& arr, int& m, const int n, T value);
template <typename T>void push_row_front(T**& arr, int& m, const int n, T value);
template <typename T>void insert_row(T**& arr, int& m, const int n, T value, int index);


template <typename T>void push_col_back(T**& arr, const int m, int& n, T value);
template <typename T>void push_col_front(T**& arr, const int m, int& n, T value);
template <typename T>void insert_col(T**& arr, const int m, int& n, T value, int index);


template <typename T>void pop_row_back(T**& arr, int& m, const int n);
template <typename T>void pop_row_front(T**& arr, int& m, const int n);
template <typename T>void erase_row(T**& arr, int& m, const int n, int index);


template <typename T>void pop_col_back(T**& arr, const int m, int& n);
template <typename T>void pop_col_front(T**& arr, const int m, int& n);
template <typename T>void erase_col(T**& arr, const int m, int& n, int index);

#ifdef One_DimensionalArray
template <typename T>void FillRand(int arr[], const int n);


template <typename T>void Print(T* arr, const int n);

template <typename T>void push_back_mutable(T*& arr, int& n, T value);
//��������� �������� � ������ �������
template <typename T>void push_front_mutable(T*& arr, int& n, T value);
template <typename T>void insert(T*& arr, int& n, T value, int index);

template <typename T>void pop_back(T*& arr, int& n);
template <typename T>void pop_front(T*& arr, int& n);
template <typename T>void erase(T*& arr, int& n, int index);
#endif // One-DimensionalArray


typedef double DataType;

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef DYNAMIC_MEMORY_1
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
#endif // DYNAMIC_MEMORY_1

	int index;
	DataType value;

	int m;		//���-�� �����
	int n;		//���-�� �������� (��������� ������)
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� ������: "; cin >> n;
	DataType** arr = Allocate<DataType>(m, n);
	//1) ������ ������ ����������

	//int** arr = new int* [m];

	//2) �������� ������ ��� ����� ���������� ������������� �������

	/*for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}*/



	// 3) ������ � ��������� ���������� ��������
	cout << "������ ��������...\n";
	FillRand(arr, m, n);
	Print(arr, m, n);

	// 4) �������� ���������� ������������� �������

	//for (int i = 0; i < m; i++)
	//{
	//	delete[] arr[i];
	//}
	//delete[] arr;

	cout << Delimetr << endl;

	//����� �� ����� � ������� ���������� ���������� (!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)

	/*cout << arr[0] << "\t"<< arr[0][0] << endl;
	cout << arr[1] << "\t"<< arr[0][1] << endl;
	cout << arr[2] << "\t"<< arr[0][2] << endl;



	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr << "\t";
		}
		cout << endl;
	}*/

	cout << Delimetr << endl;



	//��������� ������ � ����� ���������� ������������� �������
//push_row_back

	cout << "��������� ������ � ����� ���������� ������������� �������\n ";
	cout << "���� ����� ���������� �������: "; cin >> value;
	push_row_back(arr, m, n, value);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//��������� ������ � ������ ���������� ������������� ������� (++)
	//push_row_front

	cout << "��������� ������ � ������ ���������� ������������� �������\n ";
	cout << "���� ����� ���������� �������: "; cin >> value;
	push_row_front(arr, m, n, value);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//��������� ������ � ��������� ������������ ������� �� ������� (++)
	//insert_row

	cout << "��������� ������ � ��������� ������������ ������� �� �������\n "; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cout << "���� ��������� ������: "; cin >> index;
	cout << "���� ����� ���������� �������: "; cin >> value;
	insert_row(arr, m, n, value, index);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//��������� ������� � ����� ���������� ������������� ������� (++) 
	//push_col_back  



	cout << "��������� ������� � ����� ���������� ������������� �������\n ";
	cout << "���� ����� ���������� �������: "; cin >> value;
	push_col_back(arr, m, n, value);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//��������� ������� � ������ ���������� ������������� �������	(++)
	//push_col_front

	cout << "��������� ������� � ������ ���������� ������������� �������\n ";
	cout << "���� ����� ���������� �������: "; cin >> value;
	push_col_front(arr, m, n, value);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//��������� ������� � ��������� ������������ ������ �� �������	(++)
	//insert_col

	cout << "��������� ������� � ��������� ������������ ������ �� �������\n ";
	cout << "�� ������ ������� ���������: "; cin >> index;
	cout << "���� ����� ���������� �������: "; cin >> value;
	insert_col(arr, m, n, value, index);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//������� ������ � ����� ���������� ������������� �������	(++)
	//pop_row_back

	cout << "������� ������ � ����� ���������� ������������� �������\n ";
	pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//������� ������ � ������ ���������� ������������� �������	(++)
	//pop_row_front

	cout << "������� ������ � ������ ���������� ������������� �������\n ";
	pop_row_front(arr, m, n);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//������� ������ �� ���������� ������������� ������ �� ���������� �������	(++)
	//erase_row

	cout << "������� ������ �� ���������� ������������� ������ �� ���������� �������\n ";
	cout << "�� ������ ������� �������: "; cin >> index;
	erase_row(arr, m, n, index);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//������� ������� � ����� ���������� ������������� �������		(++) 
	//pop_col_back

	cout << "������� ������� � ����� ���������� ������������� �������\n ";
	pop_col_back(arr, m, n);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//������� ������� � ������ ���������� ������������� �������		(++)
	//pop_col_front

	cout << "������� ������� � ������ ���������� ������������� �������\n ";
	pop_col_front(arr, m, n);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//������� ������� � ��������� ������������ ������� �� �������	(++)
	//erase_col

	cout << "������� ������� � ��������� ������������ ������� �� �������\n ";
	cout << "�� ������ ������� ���������: "; cin >> index;
	erase_col(arr, m, n, index);
	Print(arr, m, n);

	cout << Delimetr << endl;

	Clear(arr, m);
}

template <typename T>T** Allocate(const int m, const int n)
{
	T** arr = new T* [m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n];
	}

	return arr;
}

template <typename T>void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Random(arr[i][j]);
			/*arr[i][j] = rand() % 100;*/
		}
	}
}

template <typename T>void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template <typename T>void Clear(T** arr, int& m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}

template<typename T>void Random(T& variable)
{
	if (typeid(variable) == typeid(int))
	{
		variable = rand() % 100;
	}
	else if (typeid(variable) == typeid(float) || typeid(variable) == typeid(double))
	{
		variable = double(rand() % 10000) / 100;
	}
	else if (typeid(variable) == typeid(char))
	{
		variable = rand();
	}
	else
	{
		variable = T(); //���������� ���������� �� ���������
	}

}

template <typename T>void push_row_back(T**& arr, int& m, const int n, T value)
{
		//1 ������ �������� ������ ����������
	T** buffer = new T* [m+1]{};   

		//2 �������� ������ ����� ������� � �������� ������ ����������

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
		
		//3 ������� ��������� ������ ����������
	delete[] arr;
	

		//4 �������, ��� ����� - ��� ����� ������
	arr = buffer;
		
		//5 ������ � ����� ������� ���� ����� ��� ���������� ��� ����� ������
	buffer[m] = new T[n] {};

		// ������������� �������
	for (int i = 0; i < n; i++)
	{
		buffer[m][i] = value;
	}

	//6 ����� ���������� ������ � ������, ���������� ��� ����� ������������� �� ����
	m++;

	
}
template <typename T>void push_row_front(T**& arr, int& m, const int n, T value)
{
	
	T** buffer = new T* [m + 1]{};
	buffer[0] = new T[n] {};
	
	for (int i = 0; i < m; i++)
	{
		buffer[i+1] = arr[i];
	}

	delete[] arr;

	for (int i = 0; i < n; i++)
	{
		buffer[0][i] = value;
	}


	arr = buffer;
	m++;
}
template <typename T>void insert_row(T**& arr, int& m, const int n, T value, int index)
{
	if (index > m)return;
	T** buffer = new T* [m + 1]{};
	

	//for (int i = 0; i < m + 1; i++)
	//{
	//	buffer[i] = new int[n] {};
	//}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new T[n] {};
	for (int i = index; i < m; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;

	for (int i = 0; i < n; i++)
	{
		buffer[index][i] = rand();
	}
	arr = buffer;
	
	/*arr[index] = new int[n] {};*/
	m++;
}


template <typename T>void push_col_back(T**& arr, const int m, int& n, T value)
{
	T** buffer = new T* [m]{};
	
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}

	delete[] arr;
	arr = buffer;
	

	for (int i = 0; i < m; i++)
	{
		arr[i][n] = value;
	}
	n++;
	
}
template <typename T>void push_col_front(T**& arr, const int m, int& n, T value)
{
	T** buffer = new T* [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
		delete arr[i];
	}
	delete[] arr;

	for (int i = 0; i < m; i++)
	{
		buffer[i][0] = value;
	}

	arr = buffer;
	n++;
}
template <typename T>void insert_col(T**& arr, const int m, int& n, T value, int index)
{
	if (index > m)return;
	T** buffer = new T* [m] {};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n + 1]{};

		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}

		for (int z = index; z < n; z++)
		{
			buffer[i][z + 1] = arr[i][z];
		}

		delete arr[i];
	}
	delete[] arr;
	
	for (int i = 0; i < m; i++)
	{
		buffer[i][index] = value;
	}

	arr = buffer;
	n++;
}


template <typename T>void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T* [m - 1]{};

	for (int i = 0; i < m-1; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;
	--m;

}
template <typename T>void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [m - 1]{};

	for (int i = 0; i < m - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;

	arr = buffer;
	--m;

}
template <typename T>void erase_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T* [m - 1]{};

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;


	arr = buffer;
	m--;
}


template <typename T>void pop_col_back(T**& arr, const int m, int& n)
{
	T** buffer = new T* [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template <typename T>void pop_col_front(T**& arr, const int m, int& n)
{
	T** buffer = new T* [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n - 1]{};
		for (int j = 0; j < n-1; j++)
		{
			buffer[i][j] = arr[i][j+1];
		}
		delete arr[i];
	}
	delete[] arr;

	arr = buffer;
	n--;
}
template <typename T>void erase_col(T**& arr, const int m, int& n, int index)
{
	if (index >= m)return;

	T** buffer = new T* [m] {};


	for (int i = 0; i < m; i++)
	{
		buffer[i] = new T[n - 1]{};

		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}

		for (int z = index; z < n; z++)
		{
			buffer[i][z] = arr[i][z + 1];
		}

		delete arr[i];
	}
	delete[] arr;

	arr = buffer;
	n--;
}
	




#ifdef One_DimensionalArray
template <typename T> void FillRand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		Random(arr[i]);
		/**(arr + i) = rand() % 100;*/
	}
}


template <typename T>
void Print(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template <typename T>
void push_back_mutable(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
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
template <typename T>
void push_front_mutable(T*& arr, int& n, T value)
{
	// 1. ������ �������� ������ ������� �������
	T* buffer = new T[n + 1]{};
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

template <typename T>
void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
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

template <typename T>
void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	arr = buffer;
}

template <typename T>
void pop_front(T*& arr, int& n)
{
	T* buffer = new T[--n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;
	arr = buffer;

}

template <typename T>
void erase(T*& arr, int& n, int index)
{
	T* buffer = new T[--n];

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
#endif // One-DimensionalArray
