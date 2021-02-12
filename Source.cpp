#include <iostream>

//using namespace std;
using std::cin;
using std::cout;
using std::endl;



//#define DYNAMIC_MEMORY_1
//#define One_DimensionalArray
#define DYNAMIC_MEMORY_2
#define Delimetr "----------------------------------------------"
#define noname



#ifdef One_DimensionalArray

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void push_back_mutable(int*& arr, int& n, int value);
void push_front_mutable(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);

void erase(int*& arr, int& n, int index);
#endif // One-DimensionalArray

int** Allocate(int& m, int& n);

void FillRand(int** arr, const int m, const int n);
void Print(int** arr, const int m, const int n);

void Clear(int** arr, int& m);

void push_row_back(int**& arr, int& m, const int n, int value);
void push_row_front(int**& arr, int& m, const int n, int value);
void insert_row(int**& arr, int& m, const int n, int value, int index);

void push_col_back(int**& arr, const int m, int& n, int value);
void push_col_front(int**& arr, const int m, int& n, int value);
void insert_col(int**& arr, const int m, int& n, int value, int index);

void pop_row_back(int**& arr, int& m, const int n);
void pop_row_front(int**& arr, int& m, const int n);
void erase_row(int**& arr, int& m, const int n, int index);

void pop_col_back(int**& arr, const int m, int& n);
void pop_col_front(int**& arr, const int m, int& n);
void erase_col(int**& arr, const int m, int& n, int index);

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
	int value;

	int m;		//���-�� �����
	int n;		//���-�� �������� (��������� ������)
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� ������: "; cin >> n;
	int** arr = Allocate(m, n);
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

	cout << "��������� ������ � ��������� ������������ ������� �� �������\n ";
	cout << "���� ��������� ������: "; cin >> index;
	cout << "���� ����� ���������� �������: "; cin >> value;
	insert_row(arr, m, n, value, index);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//��������� ������� � ����� ���������� ������������� ������� (++) 
	//push_col_back  



	cout << "��������� ������� � ����� ���������� ������������� �������\n "; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

	cout << "������� ������� � ��������� ������������ ������� �� �������\n " ;
	cout << "�� ������ ������� ���������: "; cin >> index;
	erase_col(arr, m, n, index);
	Print(arr, m, n);

	cout << Delimetr << endl;





	Clear(arr, m);
}




int** Allocate(int& m, int& n)
{
	int** arr = new int* [m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}

	return arr;
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int** arr, const int m, const int n)
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

void Clear(int** arr, int& m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}

void push_row_back(int**& arr, int& m, const int n, int value)
{
		//1 ������ �������� ������ ����������
	int** buffer = new int* [m+1]{};   

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
	buffer[m] = new int[n] {};

		// ������������� �������
	for (int i = 0; i < n; i++)
	{
		buffer[m][i] = value;
	}

	//6 ����� ���������� ������ � ������, ���������� ��� ����� ������������� �� ����
	m++;

	
}
void push_row_front(int**& arr, int& m, const int n, int value)
{
	
	int** buffer = new int* [m + 1]{};
	buffer[0] = new int[n] {};
	
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
void insert_row(int**& arr, int& m, const int n, int value, int index)
{
	if (index > m)return;
	int** buffer = new int* [m + 1]{};
	

	//for (int i = 0; i < m + 1; i++)
	//{
	//	buffer[i] = new int[n] {};
	//}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new int[n] {};
	for (int i = index; i < m; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;

	/*for (int i = 0; i < m; i++)
	{
		buffer[index][i] = rand();
	}*/
	arr = buffer;
	
	/*arr[index] = new int[n] {};*/
	m++;
}

void push_col_back(int**& arr, const int m, int& n, int value)
{
	int** buffer = new int* [m]{};
	
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n + 1]{};
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
void push_col_front(int**& arr, const int m, int& n, int value)
{
	int** buffer = new int* [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n + 1]{};
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
void insert_col(int**& arr, const int m, int& n, int value, int index)
{
	if (index > m)return;

	int** buffer = new int* [m] {};

	
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n + 1]{};

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
	
	for (int i = 0; i < n+1; i++)
	{
		buffer[i][index] = value;
	}

	arr = buffer;
	n++;
}

void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m - 1]{};

	for (int i = 0; i < m-1; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;
	--m;

}
void pop_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m - 1]{};

	for (int i = 0; i < m - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;

	arr = buffer;
	--m;

}
void erase_row(int**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	int** buffer = new int* [m - 1]{};

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

void pop_col_back(int**& arr, const int m, int& n)
{
	int** buffer = new int* [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n - 1]{};
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
void pop_col_front(int**& arr, const int m, int& n)
{
	int** buffer = new int* [m] {};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n - 1]{};
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
void erase_col(int**& arr, const int m, int& n, int index)
{
	if (index > m)return;

	int** buffer = new int* [m] {};


	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n - 1]{};

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
#endif // One-DimensionalArray
