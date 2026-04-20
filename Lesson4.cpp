#include<iostream>
#include<windows.h>

void menu();
void task1();
void task2();
void task3();

int main() {
	setlocale(LC_CTYPE,"ru_RU.UTF - 8");
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	menu();
}

void menu() {
	
	bool exit{ true };
	while (exit) {

		std::cout << "\t\033[38;05;201mВыберите для просмотра номер задачи или нажмите \"0\" для выхода из программы:\033[m\n";
		std::cout << "\033[38;05;108mЗадача 1. Сумматор.\033[m\n";
		std::cout << "\033[38;05;67mЗадача 2. Сумма цифр числа.\033[m\n";
		std::cout << "\033[38;05;222mЗадача 3. Таблица умножения для числа.\033[m\n";
		
		int choice;
		std::cin >> choice;
	
		switch (choice) {
		
		case 0:
			exit = choice;
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
		default:
			std::cout << "\033[38;05;196mТакой номер в выборе задач отсутсвует.Введите корректный номер задачи\033[m\n";
		}
		std::cout << std::endl;
	}
}

void task1() {				// Задача 1. Сумматор

	int integer;
	int amount{};

	while (true) {
	
		std::cout << "\n\033[38;05;108mВведите целое число или число \"0\" для выхода\n";
		std::cin >> integer;
		if (integer == 0) break;
		amount += integer;
	}
	std::cout << "Сумма введённых чисел равна: " << amount << std::endl;
}

void task2() {			   // Задача 2. Сумма цифр числа

	int number;
	do {
		std::cout << "\n\033[38;05;67mВведите число чтоб узнать сумму всех его цифр или число \"0\" для выхода\n";
		std::cin >> number;
		if ((1000 <= number && 9999 >= number) || (-9999 <= number && -1000 >= number)) 
		{
			int categoryNumber = number / 100;
			int numUnit1 = categoryNumber / 10;
			int numUnit2 = categoryNumber % 10;

			categoryNumber = number % 100;
			int numUnit3 = categoryNumber / 10;
			int numUnit4 = categoryNumber % 10;

			int adder = numUnit1 + numUnit2 + numUnit3 + numUnit4;
			std::cout << "Сумма цифр числа " << number << " равна " << adder << std::endl;
		}
		else if ((100 <= number && 999 >= number) || (-999 <= number && -100 >= number)) 
		{
			
			int numUnit1 = number / 100;

			int categoryNumber = number % 100;
			int numUnit2 = categoryNumber / 10;
			int numUnit3 = categoryNumber % 10;

			int adder = numUnit1 + numUnit2 + numUnit3;
			std::cout << "Сумма цифр числа " << number << " равна " << adder << std::endl;
		}
		else if ((10 <= number && 99 >= number) || (-99 <= number && -10 >= number)) 
		{
			int numUnit1 = number / 10;
			int numUnit2 = number % 10;

			int adder = numUnit1 + numUnit2;
			std::cout << "Сумма цифр числа " << number << " равна " << adder << std::endl;
		}
		else 
			std::cout << "Сумма цифр числа " << number << " равна " << number << std::endl;

	} while (number != 0);
	
}

void task3() {			// Задача 3. Таблица умножения для числа

	while (true) {
		
		std::cout << "\n\033[38;05;222mВведите целое число для вывода таблицы умножения с этим числом или число \"0\" для выхода\n";
		int number;
		std::cin >> number;
		if (number == 0) break;
		for (int i{ 1 }; i <= 10; i++) std::cout << number << " x " << i << " = " << number * i << std::endl;
	}
	
}