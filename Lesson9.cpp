#include<iostream>

void printSortBubble(int* p_arr, int length);
void printSortBubble(float* p_arr, int length);
void printSortBubble(char* p_arr, int length);
void swapping(int* x, int* y);
void reverse(int* p_arr, int length);

int main() {

	setlocale(LC_CTYPE, "ru_RU.UTF-8");
	// Задача 1. Вывод массива разного размера через функцию

	srand(time(nullptr));

	const int SIZE{ 20 };

	int mass[SIZE]{};
	for (size_t i = 0; i < SIZE; i++) mass[i] = rand() % 21 - 10;

	printSortBubble(mass, SIZE);

	std::cout << std::endl;

	float digital[]{ 14.5F, 12.87F, 47.45F, -12.64F, -9.24F, -3.07F };
	int sizeDigital = sizeof digital / sizeof digital[0];

	printSortBubble(digital, sizeDigital);

	std::cout << std::endl;

	char simbol[] = { 't', 'a', 'z','l','i' };
	int sizeSimbol = sizeof simbol / sizeof simbol[0];

	printSortBubble(simbol, sizeSimbol);
	std::cout << std::endl << std::endl;
	//------------------------------------------------------------------------------------------//

	// Задача 2. Снова поменяйтесь местами
	std::cout << "Поменяем местами А и В:\n"
		<< "Введите число для А: ";
	int A;
	std::cin >> A;
	std::cout << "Введите число для B: ";
	int B;
	std::cin >> B;

	std::cout << "Мы ввели А = " << A << " B = " << B << std::endl;

	swapping(&A, &B);
	std::cout << "А теперь поменяем местами А и В: -> A = " << A << " B = " << B << std::endl << std::endl;
	//-----------------------------------------------------------------------------------------//

	// Задача 3. Переворот массива

	const int NUMBERS{ 20 };
	int massive[NUMBERS]{};


	for (size_t i = 0; i < NUMBERS; i++)  massive[i] = rand() % 101;
	std::cout << "Массив до реверса: \n";
	for (size_t i = 0; i < NUMBERS; i++)  std::cout << massive[i] << " ";

	std::cout << std::endl;

	std::cout << "Массив после реверса: \n";
	reverse(massive, NUMBERS);
	for (size_t i = 0; i < NUMBERS; i++)  std::cout << massive[i] << " ";
	std::cout << std::endl << std::endl;

}

void printSortBubble(int* arr, int length) {

	std::cout << "Не отсортированный массив: ";
	for (size_t i = 0; i < length; i++) std::cout << arr[i] << " ";

	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	std::cout << "\nОтсоритированный массив: ";

	for (size_t i = 0; i < length; i++)	std::cout << arr[i] << " ";
}

void printSortBubble(float* arr, int length) {

	std::cout << "Не отсортированный массив: ";
	for (size_t i = 0; i < length; i++) std::cout << arr[i] << " ";

	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	std::cout << "\nОтсоритированный массив: ";

	for (size_t i = 0; i < length; i++)	std::cout << arr[i] << " ";
}

void printSortBubble(char* arr, int length) {

	std::cout << "Не отсортированный массив: ";
	for (size_t i = 0; i < length; i++) std::cout << arr[i] << " ";

	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	std::cout << "\nОтсоритированный массив: ";

	for (size_t i = 0; i < length; i++)	std::cout << arr[i] << " ";
}


void swapping(int* x, int* y) {

	*x += *y;
	*y = *x - *y;
	*x -= *y;
}


void reverse(int* p_arr, int length)
{
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t k = 0; k < length - 1 - k; k++)
		{
			int temp = p_arr[k];
			p_arr[k] = p_arr[length - 1 - k];
			p_arr[length - 1 - k] = temp;
		}
	}
}