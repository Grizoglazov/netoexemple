#include<iostream>
#include<random>

void menu();
void task1();
void task2();
void task3();
void task4();

int main() {
	setlocale(LC_CTYPE, "ru_RU.UTF-8");
	srand(static_cast<unsigned>(time(nullptr)));
	menu();
}

void menu() {

	bool run = true;
	while (run) {

		std::cout << "\t\tВыберите номер задачи: \n";
		std::cout << "\tЗадача 1. Вывод массива на экран\n";
		std::cout << "\tЗадача 2. Максимум и минимум\n";
		std::cout << "\tЗадача 3. Двумерный массив\n";
		std::cout << "\tЗадача 4. Обратный пузырёк\n";
		std::cout << "Для выхода из программы введите \"0\"\n";
		int select;
		std::cin >> select;
		switch (select)
		{
		case 0:
			run = false;
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
		case 4:
			task4();
			break;
		default:
			std::cout << "Не верный номер задачи, повторите еще раз действие.\n";
			break;
		}
	}
}

void task1() {

	int const SIZE{ 10 };
	int arr[SIZE];

	for (size_t i{}; i < SIZE; i++) arr[i] = rand() % 21 - 10;

	for (size_t i{}; i < SIZE; i++) (i == SIZE - 1) ? std::cout << arr[i] << "." : std::cout << arr[i] << ", ";

	std::cout << std::endl << std::endl;
}

void task2() {

	int mass[10];
	int length = sizeof mass / sizeof mass[0];

	for (size_t i{}; i < length; i++)	mass[i] = rand() % 51 - 12;
	for (size_t i{}; i < length; i++)	std::cout << mass[i] << " ";

	int max = mass[0];
	int min = mass[0];
	for (size_t i{ 1 }; i < length; i++) {

		if (max < mass[i]) max = mass[i];
		if (min > mass[i]) min = mass[i];
	}
	std::cout << "\nМинимальный элемент: " << min << std::endl << "Максимальный элемент: " << max << std::endl;
}

void task3() {

	const int ROW{ 3 }, COL{ 6 };
	int array[ROW][COL];
	for (size_t i{}; i < ROW; i++)
		for (size_t j{}; j < COL; j++)
			array[i][j] = rand() % 24 - 5;

	for (size_t i{}; i < ROW; i++) {

		for (size_t j{}; j < COL; j++) {

			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int max = array[0][0];
	int min = array[0][0];

	for (size_t i{}; i < ROW; i++)
	{
		for (size_t j{}; j < COL; j++)
		{
			if (max < array[i][j]) max = array[i][j];
			if (min > array[i][j]) min = array[i][j];
		}
	}

	for (size_t i{}; i < ROW; i++)
	{
		for (size_t j{}; j < COL; j++)
		{
			if (min == array[i][j]) std::cout << "Индекс минимального элемента: " << "min" << "[" << i << "]" << "[" << j << "]" << " = " << min << std::endl;
			if (max == array[i][j]) std::cout << "Индекс максимального элемента: " << "max" << "[" << i << "]" << "[" << j << "]" << " = " << max << std::endl;
		}
	}
}

void task4() {

	int const ROW{ 3 }, COL{ 4 };
	double array[ROW][COL];

	for (size_t i{}; i < ROW; i++)
		for (size_t j{}; j < COL; j++)
			array[i][j] = rand() % 50 - 25;

	std::cout << "Массив до сортировки: \n";
	for (size_t i{}; i < ROW; i++) {

		for (size_t j{}; j < COL; j++)
			std::cout << array[i][j] << " ";
		std::cout << std::endl;
	}

	std::cout << "Массив после сортировки: \n";

	for (size_t i{}; i < ROW; i++)											    // границы строки
	{
		for (size_t j{}; j < COL - 1; j++)										// границы ряда
		{
			for (size_t k{}; k < COL - 1 - j; k++)								// цикл повторрений для сортировки
			{
				if (array[i][k] > array[i][k + 1]) {							// сортировка свапом

					double temp = array[i][k];
					array[i][k] = array[i][k + 1];
					array[i][k + 1] = temp;
				}

			}

		}
	}

	std::cout << std::endl;

	for (size_t i{}; i < ROW; i++) {

		for (size_t j{}; j < COL; j++)
			std::cout << array[i][j] << " ";
		std::cout << std::endl;
	}


}