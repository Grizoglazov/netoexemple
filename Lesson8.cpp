#include<iostream>

inline void counting_function() {

    static int count{1};
    std::cout << "Количество вызовов функции counting_function(): " << count++ << std::endl;
}

namespace addition {

    int calc(int x, int y) {                    // Сложение

        std::cout << "Сложение: ";
        return x + y;
    }       
}

namespace subtraction {

    int calc(int x, int y) {                     // Вычитание

        std::cout << "Вычитание: ";
        return x - y;
    }
}

namespace multiplication {

    int calc(int x, int y) {                     // Умножение

        std::cout << "Умножение: ";
        return x * y;
    }      
}

namespace division {

    int calc(int x, int y) {                     // Деление

        if (y) {
            std::cout << "Деление: ";
            return x / y;
        }
        else
            std::cout << "Деление на ноль запрещено!!";

        return 0;
    }     

}


int main(int argc, char** argv) {
    setlocale(LC_CTYPE, "ru_RU.UTF-8");
   
    //Задача 1. Считающая функция
    
    for (int i = 0; i < 15; i++) counting_function();
    std::cout << std::endl;

    //Задача 2. Одинаковые, но разные функции

    std::cout << "Реализация простых арифметических действий:" 
              << "сложение, вычитание, умножение, деление.\n";
    std::cout << "Введите первое число: \n";
    int num1;
    std::cin >> num1;
    std::cout << "Введите второе число: \n";
    int num2;
    std::cin >> num2;

    std::cout << "x = " << num1 << ", " << "y = " << num2 << std::endl << addition::calc(num1, num2) << std::endl;
    std::cout << subtraction::calc(num1, num2) << std::endl;
    std::cout << multiplication::calc(num1, num2) << std::endl;
    std::cout << division::calc(num1, num2) << std::endl;
}

 





