#include<iostream>
#include<string>


void hello();
void guess();

int main() {

	setlocale(LC_CTYPE, "ru.UTF-8");
	
	//Задача 1. Приветствие

	hello();

	std::cout << std::endl;
	
	//Задача 2. Угадайка
	guess();
}

void hello() {

	std::cout << "Введите имя:  \n";
	std::string name;
	std::cin >> name;

	std::cout << "Введите фамилию:  \n";
	std::string secondName;
	std::cin >> secondName;

	std::cout << "Приветствую тебя, " << name + " " + secondName + "!" << std::endl;
}

void guess() {

	srand(time(nullptr));

	std::string fruit;
	int select = rand() % 6;
	switch (select)
	{
	case 0: fruit = "pineapple"; break;
	case 1: fruit = "banana";    break;
	case 2: fruit = "apple";     break;
	case 3: fruit = "mango";     break;
	case 4: fruit = "pear";      break;
	case 5: fruit = "kiwi";      break;
	
	}
	
	std::string answer;
	int count{};
	bool begin = true;

	std::cout << "Вот весь список фруктов: \n";
	std::cout << "pineapple, banana, apple, mango, pear, kiwi. \n";

	while (begin) {
	
		std::cout << "\nУгадай какой фрукт я загадал?!\n";
		std::cin >> answer;
		

		if (fruit != answer) 
		{
			std::cout << "Неправильно, попробуй еще раз, давай!!!\n";
			count++;
		}
		else
		{
			std::cout << "Правильно! Вы победили! Загаданное слово — " << fruit;
			break;
		}

		if (count == 2 || count == 4) 
		{
			
			if (count == 2) 
			{
				std::cout << "\nЛадно так и быть подсказка тебе!!))\n";
				std::cout << "Этот фрукт начинается на букву: " <<  fruit[0] << std::endl;
			}
			else if (count == 4)
			{
				std::cout << "\nЕще одна подсказка тебе!!))\n";
				std::cout << "Это вторая буква фрукта: \n" << fruit[1] << std::endl;
				
			}
		}
		
		
	}

	

}