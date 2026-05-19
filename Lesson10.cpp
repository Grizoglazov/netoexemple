#include<iostream>
#include<iomanip>

void menu();
void task1();
void task2();
void task3();
//----------------------------------------------------//
double* create_array(int);
int** create_two_dim_array(int, int );
void fill_two_dim_array(int**, int, int);
void print_two_dim_array(int**, int, int);
void delete_two_dim_array(int**, int, int);

int main() {

	setlocale(LC_CTYPE, "ru.UTP-8");

	menu();
	
}

void menu() {

	bool start = true;
	while (start) {
	
		std::cout << "\tВыберите номер задачи от 1 до 3:\n";
		std::cout << "Задача 1. Ввод массива с консоли\n";
		std::cout << "Задача 2. Создатель массивов\n";
		std::cout << "Задача 3. Динамическая таблица умножения\n";
		std::cout << "\tИли нажмите 0 для выхода из программы\n";
		int select;
		std::cin >> select;
		switch (select)
		{
		case 0:
			start = false;
			break;
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		}
	}
}

void task1() {

	// Задача 1. Ввод массива с консоли

	std::cout << "Введите размер массива: \n";
	int size;
	std::cin >> size;

	int* ptrArray = static_cast<int*>(calloc(size, sizeof(int)));

	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Введите [" << i << "] элемент массива: \n";
		std::cin >> ptrArray[i];
	}

	std::cout << "Введеный массив: \n";

	for (size_t i = 0; i < size; i++)
		std::cout << "Arr[" << i << "] = " << ptrArray[i] << std::endl;

	free(ptrArray);

	std::cout << std::endl;
}

void task2() {

	//Задача 2. Создатель массивов

	std::cout << "Укажите размер для нового массива: \n";
	int sizeMassive;
	std::cin >> sizeMassive;

	double* newMassive = create_array(sizeMassive);
	for (size_t i = 0; i < sizeMassive; i++)
		(i != sizeMassive - 1) ? std::cout << newMassive[i] << ", " : std::cout << newMassive[i] << ".";

	delete[] newMassive;

	std::cout << std::endl;
}

void task3() {

	// Задача 3. Динамическая таблица умножения

	std::cout << "Укажите количество строк в массиве: \n";
	int rows;
	std::cin >> rows;
	std::cout << "Укажите количество столбцов в массиве: \n";
	int columns;
	std::cin >> columns;

	int** newMass = create_two_dim_array(rows, columns);
	fill_two_dim_array(newMass, rows, columns);
	print_two_dim_array(newMass, rows, columns);
	delete_two_dim_array(newMass, rows, columns);

	std::cout << std::endl;

}


double* create_array(int size) { return new double[size] {}; }

int** create_two_dim_array(int r, int c) {

	int** newMassive = new int*[r];

	for (size_t i = 0; i < r; i++) newMassive[i] = new int[c]{};
	
	return newMassive;
}

void fill_two_dim_array(int** arr, int r, int c) {

	for (size_t i = 0; i < r; i++)
		for (size_t j = 0; j < c; j++)  arr[i][j] = (i + 1) * (j + 1); 
}

void print_two_dim_array(int** arr, int r, int c) {

	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j ++)
		{
			std::cout << std::setw(2) << arr[i][j] << std::setw(1) << " ";
		}
		std::cout << std::endl;
	}
}

void delete_two_dim_array(int** arr, int r, int c) {

	for (size_t i = 0; i < r; i++) delete[] arr[i];
		
	delete[] arr;

}

