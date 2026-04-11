#include<iostream>
#include<windows.h>
#include<string>

int main() {
	setlocale(LC_CTYPE, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Задание 1. Повторите число:
	int num{};
	std::cout << "Введите число:\n";
	std::cin >> num;
	std::cout << "Вы ввели число: " << num << std::endl;
	
	//Задание 2*. Повторите слово:
	// С использованием массива из char (Cи-строка)
	char word[30];
	std::cout << "Введите слово:\n";
	std::cin >> word;
	std::cout << "Вы ввели слово: " << word << std::endl;
	std::cin.get();
	
	// C использованием класса string (C++)
	std::string words;
	std::cout << "Введите слово:\n";
	std::getline(std::cin, words);
	std::cout << "Вы ввели слово: " << words << std::endl;
}