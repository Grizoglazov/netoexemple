#include<iostream>
#include<fstream>

int main() {
	setlocale(LC_ALL, "ru.UTF-8");

	// Задача 1. Вывод файла
	std::ifstream file("data.txt");
	std::string s;

	if (file.is_open())
	{
		while (file >> s) std::cout << s << std::endl;
	}
	else
		std::cout << "Не получилось открыть файл!" << std::endl;

	file.close();

	std::cout << std::endl;

	// Задача 2. Чтение массива из файла

	std::ifstream massive("massive.txt");
	int size;
	int number;
	

	if (massive.is_open())
	{
		massive >> size;
		std::cout << size << std::endl;

		int* p_arr = new int[size];

		for (size_t i = 0; i < size; i++)
		{
			massive >> number;
			p_arr[size - 1 - i] = number;
		}
			
		for (size_t j = 0; j < size; j++) std::cout << p_arr[j] << " ";

		delete[] p_arr;
	}
	else
		std::cout << "Не получилось открыть файл!" << std::endl;

	massive.close();

	std::cout << std::endl;


	//Задача 3. Пользовательский массив в файл

	std::cout << "\nУкажите размер массива:\n";
	int sizeMass;
	std::cin >> sizeMass;

	int* newMass = new int[sizeMass];

	std::cout << "Заполните каждый элемент массива целыми числами:\n";
	for (size_t i = 0; i < sizeMass; i++)
	{
		std::cout << "arr[" << i << "]" << " = ";
		std::cin >> newMass[i];
	}

	std::ofstream massOut("out.txt");

	massOut << sizeMass << std::endl;
		
	for (size_t i = 0; i < sizeMass; i++)
		massOut << newMass[sizeMass - 1 - i] << " ";
		
	delete[] newMass;

	massOut.close();
	std::cout << std::endl;


	// Задача 4. Считывание двумерного массива из файла

	std::ifstream fin("in.txt");
	if (fin.is_open())
	{
		int rows, cols;

		fin >> rows;
		fin >> cols;

		int** twoMass = new int* [rows];

		for (size_t i = 0; i < rows; i++)
			twoMass[i] = new int[cols];

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				fin >> twoMass[i][j];
			}
		}

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				std::cout << twoMass[i][cols - 1 - j] << " ";
			}
			std::cout << std::endl;
		}

		for (size_t i = 0; i < rows; i++)
		{
			delete[] twoMass[i];
		}
		delete[] twoMass;
	}
	else
		std::cout << "Файл не найден или его удалили!!!\n";

	fin.close();
}