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

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	//cout << "Введите удаляемое значение значение: "; cin >> value;
	pop_back(arr, n);
	Print(arr, n);

	cout << "----------------------------------------------------" << endl;

	pop_front(arr, n);
	Print(arr, n);

	cout << "----------------------------------------------------" << endl;

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);


	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int index;
	int value;

	int m;		//Кол-во строк
	int n;		//Кол-во столбцов (элементов строки)
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;
	int** arr = Allocate(m, n);
	//1) Создаём массив указателей

	//int** arr = new int* [m];

	//2) Выделяем память для строк двумерного динамического массива

	/*for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}*/

	

	// 3) Работа с двумерным диначиским массивом
	cout << "Память выделена...\n";
	FillRand(arr, m, n);
	Print(arr, m, n);

	// 4) Удаление двумерного динамического массива

	//for (int i = 0; i < m; i++)
	//{
	//	delete[] arr[i];
	//}
	//delete[] arr;

	cout << Delimetr << endl;

	//Вывод на экран с помощью арифметики указателей (!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)

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



	//добавляет строку в конец двумерного динамического массива
//push_row_back

	cout << "добавляет строку в конец двумерного динамического массива\n ";
	cout << "Чему равен добавочный элемент: "; cin >> value;
	push_row_back(arr, m, n, value);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//добавляет строку в начало двумерного динамического массива (++)
	//push_row_front

	cout << "добавляет строку в начало двумерного динамического массива\n ";
	cout << "Чему равен добавочный элемент: "; cin >> value;
	push_row_front(arr, m, n, value);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//добавляет строку в двумерный динамический массива по индексу (++)
	//insert_row

	cout << "добавляет строку в двумерный динамический массива по индексу\n "; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cout << "Куда вставляем строку: "; cin >> index;
	cout << "Чему равен добавочный элемент: "; cin >> value;
	insert_row(arr, m, n, value, index);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//добавляет столбик в конец двумерного динамического массива (++) 
	//push_col_back  



	cout << "добавляет столбик в конец двумерного динамического массива\n "; 
	cout << "Чему равен добавочный элемент: "; cin >> value;
	push_col_back(arr, m, n, value);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//добавляет столбик в начало двумерного динамического массива	(++)
	//push_col_front

	cout << "добавляет столбик в начало двумерного динамического массива\n ";
	cout << "чему равен добавочный элемент: "; cin >> value;
	push_col_front(arr, m, n, value);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//вставляет столбик в двумерный динамический массив по индексу	(++)
	//insert_col

	cout << "вставляет столбик в двумерный динамический массив по индексу\n ";
	cout << "По какому индексу вставляем: "; cin >> index;
	cout << "Чему равен добавочный элемент: "; cin >> value;
	insert_col(arr, m, n, value, index);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//удаляет строку в конце двумерного динамического массива	(++)
	//pop_row_back

	cout << "удаляет строку в конце двумерного динамического массива\n ";
	pop_row_back(arr, m, n);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//удаляет строку в начале двумерного динамического массива	(++)
	//pop_row_front

	cout << "удаляет строку в начале двумерного динамического массива\n ";
	pop_row_front(arr, m, n);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//удаляет строку из двумерного динамического массив по указанному индексу	(++)
	//erase_row

	cout << "удаляет строку из двумерного динамического массив по указанному индексу\n ";
	cout << "По какому индексу удаляем: "; cin >> index;
	erase_row(arr, m, n, index);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//удаляет столбик в конце двумерного динамического массиве		(++) 
	//pop_col_back

	cout << "удаляет столбик в конце двумерного динамического массиве\n ";
	pop_col_back(arr, m, n);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//удаляет столбик в начале двумерного динамического массива		(++)
	//pop_col_front

	cout << "удаляет столбик в начале двумерного динамического массива\n ";
	pop_col_front(arr, m, n);
	Print(arr, m, n);

	cout << Delimetr << endl;

	//удаляет столбик в двумерном динамическом массиве по индексу	(++)
	//erase_col

	cout << "удаляет столбик в двумерном динамическом массиве по индексу\n " ;
	cout << "По какому индексу вставляем: "; cin >> index;
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
		//1 Создаём буферный массив указателей
	int** buffer = new int* [m+1]{};   

		//2 Копируем адреса строк массива в буферный массив указателей

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
		
		//3 Удаляем исхнодный массив указателей
	delete[] arr;
	

		//4 Говорим, что буфер - наш новый массив
	arr = buffer;
		
		//5 Теперь в нашем массиве есть место для дополнения ещё одной строки
	buffer[m] = new int[n] {};

		// Необязателный элемент
	for (int i = 0; i < n; i++)
	{
		buffer[m][i] = value;
	}

	//6 После добавления строки в массив, количество его строк увеличивается на одну
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

	for (int i = 0; i < n; i++)
	{
		buffer[index][i] = rand();
	}
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
	
	for (int i = 0; i < m; i++)
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


void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	//1 вариант
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}*/

	/*for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}*/

	//2 вариант
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
