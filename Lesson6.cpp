#include<iostream>
#include<windows.h>

int sum(int, int);
int diff(int, int);
int multiplication(int, int);
double division(int, int);
int degree(int, int);
void fibonacci(int);


int main() {
	setlocale(LC_CTYPE, "ru_RU.UTF-8");
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	// Задача 1. Арифметические функции

	int a = 5, b = 10;

	int s = sum(a, b);
	int dif = diff(a, b);
	int mult = multiplication(a, b);
	double div = division(a, b);

	std::cout << a << " + " << b << " = " << s << std::endl;
	std::cout << a << " - " << b << " = " << dif << std::endl;
	std::cout << a << " * " << b << " = " << mult << std::endl;
	std::cout << a << " / " << b << " = " << div << std::endl << std::endl;
	//-----------------------------------------------------------------//

	// Задача 2. Устранение дублирования

	int value = 5, power = 2;									// значение и степень
	int result = degree(value, power);
	std::cout << value << " в степени " << power << " = " << result << std::endl;
	value = 3, power = 3;
	result = degree(value, power);
	std::cout << value << " в степени " << power << " = " << result << std::endl;
	value = 4, power = 4;
	result = degree(value, power);
	std::cout << value << " в степени " << power << " = " << result << std::endl << std::endl;
	//-----------------------------------------------------------------//

	// Задача 3. Числа Фибоначчи
	std::cout << "Введите число - номер элемента последовательности для вывода последовательности Фибоначчи:\n";
	int number;
	std::cin >> number;
	std::cout << "Числа Фибоначчи: ";
	fibonacci(number);



}

int sum(int x, int y) { return x + y; }						// выполняет операцию сложения

int diff(int x, int y) { return x - y; }					// выполняет операцию вычитания

int multiplication(int x, int y) { return x * y; }			// выполняет операцию умножения

double division(int x, int y)								// выполняет операцию деления	
{
	if (y == 0) return 0;

	double result = static_cast<double>(x) / y;
	return result;
}


int degree(int x, int y)									// выполняет операцию возведения числа(x) в степень(y)
{
	int result{ 1 };
	for (size_t i = 0; i < y; i++) result *= x;
	return result;
}

void fibonacci(int x) {							// для вычисление последовательности чисел Фибоначчи

	int num1 = 0, num2 = 1;
	unsigned long F;

	if (x)
	{
		for (size_t i = 0; i < x; i++)
		{
			F = num1 + num2;
			std::cout << F << " ";
			num1 = num2;
			num2 = F;
		}
	}
	else
		std::cout << "Введите число кроме 0 \n";
}
// Введите число: 10
// Числа Фибоначчи : 0 1 1 2 3 5 8 13 21 34