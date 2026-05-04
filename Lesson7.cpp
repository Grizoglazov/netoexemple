#include<iostream>

void swap(int&, int&);

int main() {

	//Задача 1. Адреса переменных

	bool boolVar;
	short shortNum;
	int intNum;
	long longNum;
	long long longLongNum;
	float floatNum;
	double doubleNum;
	long double longDoubleNum;


	std::cout << "1.Type: bool " << " adress: " << &boolVar << " size: " << sizeof boolVar << " bite.\n";
	std::cout << "2.Type: short " << " adress: " << &shortNum << " size: " << sizeof shortNum << " bite.\n";
	std::cout << "3.Type: int " << " adress: " << &intNum << " size: " << sizeof intNum << " bite.\n";
	std::cout << "4.Type: long " << " adress: " << &longNum << " size: " << sizeof longNum << " bite.\n";
	std::cout << "5.Type: long long " << " adress: " << &longLongNum << " size: " << sizeof longLongNum << " bite.\n";
	std::cout << "6.Type: float " << " adress: " << &floatNum << " size: " << sizeof floatNum << " bite.\n";
	std::cout << "7.Type: double " << " adress: " << &doubleNum << " size: " << sizeof doubleNum << " bite.\n";
	std::cout << "8.Type: long double " << " adress: " << &longDoubleNum << " size: " << sizeof longDoubleNum << " bite.\n";
	std::cout << std::endl;

	//--------------------------------------------------------------------------------------------------------------------//

												//Задача 2. Обмен значениями

	int a = 5, b = 8;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(a, b);
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
}


void swap(int& x, int& y) {

	x += y;
	y = x - y;
	x -= y;
}






