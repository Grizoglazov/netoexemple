#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>


void menu();
void task1();
void task2();
void task3();
void task4();

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	menu();
}

void menu() {

	char exit{ 'n' };
	while (exit == 'n')
	{
		std::cout << "\t\033[38;05;222mДля выбора задачи, выберите ее номер: \033[m\n";
		std::cout << "\033[38;05;108mЗадание 1. Таблица истинности оператор ||(OR) и таблица истинности оператор &&(AND). Для выбора введите: 1\033[m\n";
		std::cout << "\033[38;05;110mЗадание 2. Сравнение трех целых чисел и вывод их на экран в порядке убывания. Для выбора введите: 2\033[m\n";
		std::cout << "\033[38;05;139mЗадание 3. Гороскоп. Для выбора введите: 3\033[m\n";
		std::cout << "\033[38;05;68mЗадание 4. Сравниваем числа и выводим результат в виде текста. Для выбора введите: 4\033[m\n";
		unsigned short choice;
		std::cin >> choice;
		switch (choice)	{ 
		  case 1: task1();	break;
		  case 2: task2();	break;
		  case 3: task3();	break;
		  case 4: task4();	break;
		  default: std::cout << "Введен не коректный номер задания, укажите правильный номер пожалуйста. \n";
		}
		std::cout << "\nДля завершения программы нажмите: 'y' или если хотите вернутся к задачам нажмите: 'n'\n";
		std::cin >> exit;
	}
}

void task1() {

	std::cout << std::boolalpha;	// отображаем в консоли значения "true" или "false", по умолчанию компилятор выводит в консоль 1 или 0
	
	bool varA{ true };
	bool varB{ true };
	bool resultAB = varA + varB;
	const int SET{ 5 };

	std::cout << "\t    Оператор: ||(OR)\n";
	std::cout << "\t   var A:" << "   var B:" << "     A||B\n";

	std::cout << std::setw(SET) << "\t| " << std::setw(SET) << varA << std::setw(SET)
			  << " | " << std::setw(SET) << varB << std::setw(SET) << " | " << std::setw(SET)
			  << resultAB << std::setw(SET) << " | " << std::endl;

	std::cout << std::setw(SET) << "\t| " << std::setw(SET) << varA << std::setw(SET) << " | "
			  << std::setw(SET) << !varB << std::setw(SET) << " | " << std::setw(SET)
			  << resultAB << std::setw(SET) << " | " << std::endl;

	std::cout << std::setw(SET) << "\t| " << std::setw(SET) << !varA << std::setw(SET)
			  << " | " << std::setw(SET) << varB << std::setw(SET) << " | " << std::setw(SET)
			  << resultAB << std::setw(SET) << " | " << std::endl;

	std::cout << std::setw(SET) << "\t| " << std::setw(SET) << !varA << std::setw(SET)
			  << " | " << std::setw(SET) << !varB << std::setw(SET) << " | " << std::setw(SET)
			  << !resultAB << std::setw(SET) << " | " << std::endl;

	std::cout << std::endl;

	//-------------------------------------------------------------------------------------------//

	bool varX{ true };
	bool varY{ true };
	bool resultXY = varX * varY;

	std::cout << "\t    Оператор: &&(AND)\n";
	std::cout << "\t   var A:" << "   var B:" << "     A&&B\n";

	std::cout << std::setw(SET) << "\t| " << std::setw(SET) << varX << std::setw(SET)
		<< " | " << std::setw(SET) << varY << std::setw(SET) << " | " << std::setw(SET)
		<< resultXY << std::setw(SET) << " | " << std::endl;

	std::cout << std::setw(SET) << "\t| " << std::setw(SET) << varX << std::setw(SET) << " | "
		<< std::setw(SET) << !varY << std::setw(SET) << " | " << std::setw(SET)
		<< !resultXY << std::setw(SET) << " | " << std::endl;

	std::cout << std::setw(SET) << "\t| " << std::setw(SET) << !varX << std::setw(SET)
		<< " | " << std::setw(SET) << varY << std::setw(SET) << " | " << std::setw(SET)
		<< !resultXY << std::setw(SET) << " | " << std::endl;

	std::cout << std::setw(SET) << "\t| " << std::setw(SET) << !varX << std::setw(SET)
		<< " | " << std::setw(SET) << !varY << std::setw(SET) << " | " << std::setw(SET)
		<< !resultXY << std::setw(SET) << " | " << std::endl;

	std::cout << std::noboolalpha;                   // возвращаем обратно отображение bool по умолчанию
}

void task2() {

	 int firstNumber, secondNumber, thirdNumber;

	 std::cout << "Введите первое число: ";
	 std::cin >> firstNumber;
	 std::cout << "\nВведите второе число: ";
	 std::cin >> secondNumber;
	 std::cout << "\nВведите третье число: ";
	 std::cin >> thirdNumber;

	 (firstNumber > secondNumber) ?
		 (firstNumber > thirdNumber) ?
		 (secondNumber > thirdNumber) ? (std::cout << firstNumber << " " << secondNumber << " " << thirdNumber) : (std::cout << firstNumber << " " << thirdNumber << " " << secondNumber)
		 : (thirdNumber > secondNumber) ? (std::cout << thirdNumber << " " << firstNumber << " " << secondNumber) : (std::cout << secondNumber << " " << thirdNumber << " " << firstNumber)
		 : (secondNumber > thirdNumber) ?
		 (firstNumber > thirdNumber) ? (std::cout << secondNumber << " " <<firstNumber << " " << thirdNumber) : (std::cout << secondNumber << " " << thirdNumber << " " << firstNumber)
		 : (thirdNumber > firstNumber) ? (std::cout << thirdNumber << " " << secondNumber << " " << firstNumber) : (std::cout << firstNumber << " " << thirdNumber << " " << secondNumber);
}

void task3() {

   char sex;
   std::string zodiak;
   unsigned short age;
   

   std::cout << "Выберите ваш пол, указав английские символы (m/w): ";
   std::cin >> sex;
   std::cout << "Напишите ваш знак зодиака по английски: ";
   std::cin >> zodiak;
   std::cout << "Введите ваш возраст: ";
   std::cin >> age;

   if (('m' == sex) && (40 > age) && ("cancer" == zodiak || "scorpio" == zodiak || "pisces" == zodiak))											   // Зодиаки стихии Воды	
   {
   	std::cout << "\nСегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным.\n";
   }
   else if (('w' == sex) && (15 <= age) && (30 >= age) && ("taurus" == zodiak || "virgo" == zodiak || "capricorn" == zodiak))						// Зодиаки стихии Земли
   {
   	std::cout << "\nСегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок.\n"
   		<< "Будет не только весело, но и интересно : найдётся дело, которое увлечёт всех.\n";
   }
   else if (('m' == sex || 'w' == sex) && (10 < age) && (60 > age) && ("aries" == zodiak || "leo" == zodiak || "sagittarius" == zodiak))			// Зодиаки стихии Огня
   {
   	std::cout << "Огненные знаки, вечер удачный, если вы не подожжёте друг друга (в переносном смысле)."
   		<< "Расслабьтесь, вы всё равно лучшие — хотя бы в своих глазах.\n";
   }
   else if ((25 <= age || 75 >= age) && ("gemini" == zodiak || "libra" == zodiak || "aquarius" == zodiak))											// Зодиаки стихии Воздуха
   {
   	std::cout << "\nВечер тихий, странный и гениальный — в общем, твой. "
   		<< "Ты изобрёл новый способ заваривать лапшу быстрого приготовления и спас мир в голове три раза. "
   		<< "Окружающие не поймут, почему ты смеёшься в пустоту, но тебе плевать.Главное — не потеряй пульт от телевизора в морозилке.Это уже было\n";
   }
   else
   	std::cout << "\nГороскоп для вас находится в разработке. Приходите чуточку позже ;)\n";
         
}

void task4() {

	int number1, number2;


	std::cout << "Введите целое число: ";
	std::cin >> number1;
	std::cout << "Введите целое число: ";
	std::cin >> number2;

	if ((-100 < number1 && 100 > number1) && (-100 < number2 && 100 > number2)) {

		int categoryOfUnits1 = number1 / 10;						// разряд единиц первого числа
		int categoryTen1 = number1 % 10;							// разряд десяток первого числа

		if (categoryOfUnits1 == 0)
		{
			if (0 > number1)
			{
				std::cout << "Минус ";

				switch (number1) {
				case -1: std::cout << "один ";	break;
				case -2: std::cout << "два ";	break;
				case -3: std::cout << "три ";	break;
				case -4: std::cout << "четыре "; break;
				case -5: std::cout << "пять ";   break;
				case -6: std::cout << "шесть ";  break;
				case -7: std::cout << "семь ";   break;
				case -8: std::cout << "восемь "; break;
				case -9: std::cout << "девять "; break;

				}
			}
			else
			{
				switch (number1) {
				case 0: std::cout << "Ноль ";	break;
				case 1: std::cout << "Один ";	break;
				case 2: std::cout << "Два ";	break;
				case 3: std::cout << "Три ";	break;
				case 4: std::cout << "Четыре "; break;
				case 5: std::cout << "Пять ";   break;
				case 6: std::cout << "Шесть ";  break;
				case 7: std::cout << "Семь ";   break;
				case 8:	std::cout << "Восемь "; break;
				case 9: std::cout << "Девять "; break;
				}
			}
		}
		else
		{
			if (0 > number1)
			{
				std::cout << "Минус ";
				switch (categoryOfUnits1)
				{
				case -1:
					switch (categoryTen1)
					{
					case 0: std::cout << "десять ";			break;
					case -1: std::cout << "одиннадцать ";	break;
					case -2: std::cout << "двенадцать ";	break;
					case -3: std::cout << "тринадцать ";	break;
					case -4: std::cout << "четырнадцать ";  break;
					case -5: std::cout << "пятнадцать ";	break;
					case -6: std::cout << "шестнадцать ";   break;
					case -7: std::cout << "семнадцать ";	break;
					case -8: std::cout << "восемнадцать ";  break;
					case -9: std::cout << "девятнадцать ";  break;
					}
					break;
				case -2:
					std::cout << "двадцать ";
					switch (categoryTen1)
					{
					case -1: std::cout << "один ";	 break;
					case -2: std::cout << "два ";	 break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -3:
					std::cout << "тридцать ";
					switch (categoryTen1)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -4:
					std::cout << "сорок ";
					switch (categoryTen1)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -5:
					std::cout << "пятьдесят ";
					switch (categoryTen1)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -6:
					std::cout << "шестьдесят ";
					switch (categoryTen1)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -7:
					std::cout << "семьдесят ";
					switch (categoryTen1)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -8:
					std::cout << "восемьдесят ";
					switch (categoryTen1)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -9:
					std::cout << "девяносто ";
					switch (categoryTen1)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				}
			}
			else
			{
				switch (categoryOfUnits1) {
				case 1:
					switch (categoryTen1)
					{
					case 0: std::cout << "Десять ";			break;
					case 1: std::cout << "Одиннадцать ";	break;
					case 2: std::cout << "Двенадцать ";		break;
					case 3: std::cout << "Тринадцать ";		break;
					case 4: std::cout << "Четырнадцать ";   break;
					case 5: std::cout << "Пятнадцать ";		break;
					case 6: std::cout << "Шестнадцать ";    break;
					case 7: std::cout << "Семнадцать ";		break;
					case 8: std::cout << "Восемнадцать ";   break;
					case 9: std::cout << "Девятнадцать ";   break;
					}
					break;
				case 2:
					std::cout << "Двадцать ";
					switch (categoryTen1)
					{
					case 1: std::cout << "один ";	 break;
					case 2: std::cout << "два ";	 break;
					case 3: std::cout << "три ";	 break;
					case 4: std::cout << "четыре ";  break;
					case 5: std::cout << "пять ";    break;
					case 6: std::cout << "шесть ";   break;
					case 7: std::cout << "семь ";    break;
					case 8: std::cout << "восемь ";  break;
					case 9: std::cout << "девять ";  break;
					}
					break;
				case 3:
					std::cout << "Тридцать ";
					switch (categoryTen1)
					{
					case 1: std::cout << "один ";    break;
					case 2: std::cout << "два ";     break;
					case 3: std::cout << "три ";	 break;
					case 4: std::cout << "четыре ";  break;
					case 5: std::cout << "пять ";    break;
					case 6: std::cout << "шесть ";   break;
					case 7: std::cout << "семь ";    break;
					case 8: std::cout << "восемь ";  break;
					case 9: std::cout << "девять ";  break;
					}
					break;
				case 4:
					std::cout << "Сорок ";
					switch (categoryTen1)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 5:
					std::cout << "Пятьдесят ";
					switch (categoryTen1)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 6:
					std::cout << "Шестьдесят ";
					switch (categoryTen1)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 7:
					std::cout << "Семьдесят ";
					switch (categoryTen1)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 8:
					std::cout << "Восемьдесят ";
					switch (categoryTen1)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 9:
					std::cout << "Девяносто ";
					switch (categoryTen1)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				}
			}
		}

		if (number1 > number2) std::cout << "больше чем ";
		else if (number1 == number2) std::cout << "равно ";
		else std::cout << "меньше чем ";

		int categoryOfUnits2 = number2 / 10;			// разряд единиц второго числа
		int categoryTen2 = number2 % 10;				// разряд десяток второго числа

		if (categoryOfUnits2 == 0)
		{
			if (0 > number2)
			{
				std::cout << "минус ";
				switch (number2) {
				case -1: std::cout << "один ";	break;
				case -2: std::cout << "два ";	break;
				case -3: std::cout << "три ";	break;
				case -4: std::cout << "четыре "; break;
				case -5: std::cout << "пять ";   break;
				case -6: std::cout << "шесть ";  break;
				case -7: std::cout << "семь ";   break;
				case -8: std::cout << "восемь "; break;
				case -9: std::cout << "девять "; break;

				}
			}
			else
			{
				switch (number2) {
				case 0: std::cout << "ноль ";	break;
				case 1: std::cout << "один ";	break;
				case 2: std::cout << "два ";	break;
				case 3: std::cout << "три ";	break;
				case 4: std::cout << "четыре "; break;
				case 5: std::cout << "пять ";   break;
				case 6: std::cout << "шесть ";  break;
				case 7: std::cout << "семь ";   break;
				case 8:	std::cout << "восемь "; break;
				case 9: std::cout << "девять "; break;
				}
			}
		}
		else
		{
			if (0 > number2)
			{
				std::cout << "минус ";
				switch (categoryOfUnits2) {
				case -1:
					switch (categoryTen2)
					{
					case 0: std::cout << "десять ";			break;
					case -1: std::cout << "одиннадцать ";	break;
					case -2: std::cout << "двенадцать ";	break;
					case -3: std::cout << "тринадцать ";	break;
					case -4: std::cout << "четырнадцать ";  break;
					case -5: std::cout << "пятнадцать ";	break;
					case -6: std::cout << "шестнадцать ";   break;
					case -7: std::cout << "семнадцать ";	break;
					case -8: std::cout << "восемнадцать ";  break;
					case -9: std::cout << "девятнадцать ";  break;
					}
					break;
				case -2:
					std::cout << "двадцать ";
					switch (categoryTen2)
					{
					case -1: std::cout << "один ";	 break;
					case -2: std::cout << "два ";	 break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -3:
					std::cout << "тридцать ";
					switch (categoryTen2)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -4:
					std::cout << "сорок ";
					switch (categoryTen2)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -5:
					std::cout << "пятьдесят ";
					switch (categoryTen2)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -6:
					std::cout << "шестьдесят ";
					switch (categoryTen2)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -7:
					std::cout << "семьдесят ";
					switch (categoryTen2)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -8:
					std::cout << "восемьдесят ";
					switch (categoryTen2)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				case -9:
					std::cout << "девяносто ";
					switch (categoryTen2)
					{
					case -1: std::cout << "один ";   break;
					case -2: std::cout << "два ";    break;
					case -3: std::cout << "три ";	 break;
					case -4: std::cout << "четыре "; break;
					case -5: std::cout << "пять ";   break;
					case -6: std::cout << "шесть ";  break;
					case -7: std::cout << "семь ";   break;
					case -8: std::cout << "восемь "; break;
					case -9: std::cout << "девять "; break;
					}
					break;
				}
			}
			else
			{
				switch (categoryOfUnits2) {
				case 1:
					switch (categoryTen2)
					{
					case 0: std::cout << "десять ";			break;
					case 1: std::cout << "одиннадцать ";	break;
					case 2: std::cout << "двенадцать ";		break;
					case 3: std::cout << "тринадцать ";		break;
					case 4: std::cout << "четырнадцать ";   break;
					case 5: std::cout << "пятнадцать ";		break;
					case 6: std::cout << "шестнадцать ";    break;
					case 7: std::cout << "семнадцать ";		break;
					case 8: std::cout << "восемнадцать ";   break;
					case 9: std::cout << "девятнадцать ";   break;
					}
					break;
				case 2:
					std::cout << "двадцать ";
					switch (categoryTen2)
					{
					case 1: std::cout << "один ";	 break;
					case 2: std::cout << "два ";	 break;
					case 3: std::cout << "три ";	 break;
					case 4: std::cout << "четыре ";  break;
					case 5: std::cout << "пять ";    break;
					case 6: std::cout << "шесть ";   break;
					case 7: std::cout << "семь ";    break;
					case 8: std::cout << "восемь ";  break;
					case 9: std::cout << "девять ";  break;
					}
					break;
				case 3:
					std::cout << "тридцать ";
					switch (categoryTen2)
					{
					case 1: std::cout << "один ";    break;
					case 2: std::cout << "два ";     break;
					case 3: std::cout << "три ";	 break;
					case 4: std::cout << "четыре ";  break;
					case 5: std::cout << "пять ";    break;
					case 6: std::cout << "шесть ";   break;
					case 7: std::cout << "семь ";    break;
					case 8: std::cout << "восемь ";  break;
					case 9: std::cout << "девять ";  break;
					}
					break;
				case 4:
					std::cout << "сорок ";
					switch (categoryTen2)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 5:
					std::cout << "пятьдесят ";
					switch (categoryTen2)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 6:
					std::cout << "шестьдесят ";
					switch (categoryTen2)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 7:
					std::cout << "семьдесят ";
					switch (categoryTen2)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 8:
					std::cout << "восемьдесят ";
					switch (categoryTen2)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				case 9:
					std::cout << "девяносто ";
					switch (categoryTen2)
					{
					case 1: std::cout << "один ";   break;
					case 2: std::cout << "два ";    break;
					case 3: std::cout << "три ";	break;
					case 4: std::cout << "четыре "; break;
					case 5: std::cout << "пять ";   break;
					case 6: std::cout << "шесть ";  break;
					case 7: std::cout << "семь ";   break;
					case 8: std::cout << "восемь "; break;
					case 9: std::cout << "девять "; break;
					}
					break;
				}
			}
		}
	}
	else
		std::cout << "Ошибка! Одно из чисел вне диапазона!\n";
}