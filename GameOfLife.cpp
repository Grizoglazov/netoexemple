#include<iostream>
#include<windows.h>
#include<fstream>
//#include<cstdlib>

// Инициализация размера поля 
const int ROWS{ 10 };
const int COLS{ 10 };

// Инициализация значениями мертвой и живой ячеек
const char ALIVE = '*';
const char DEAD = '-';

int countAliveCellsAround(int x, int y, char mass[][COLS], int r);

int main() {

	setlocale(LC_CTYPE, "ru.UTF-8");
	std::ofstream fout("C:\\Users\\greez\\Desktop\\Netologia\\GameOfLife\\Data.txt");  // открыли файл для записи
	// Инициализация поколения
	int generation{ 0 };

	// Инициализация массива для сохранения значений в процессе работы программы
	char mass[ROWS][COLS];
	// Инициализация нового массива для сохранеия изменеий 
	char newMass[ROWS][COLS];

	// Для рандомной инициализации ячеек  
	srand(time(nullptr));
	// Количество живых ячеек в поколнении
	int aliveCellsTotal{};
	int oldAliveCellsTotal{};
	// Заполнение поля массива рандомными значениями ячеек и фиксирование количества живых клеток
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			int seed = rand() % 2;			// Если зерно не равно 0 данные в массиве принимают значения живых клеток  
			if (seed)
			{
				mass[i][j] = ALIVE;
				aliveCellsTotal++;			// Подсчет количества живых ячеек
			}
			else
				mass[i][j] = DEAD;
		}
	}
	// Инициализация цикла для итерации поколений и вывода изменеий состояния ячеек массива в консоль
	while (generation <= 10)
	{
		//std::system("cls");
		aliveCellsTotal = 0;					// Обнуление количества ячеек для последующей итерации
		for (size_t i = 0; i < ROWS; i++)
		{
			for (size_t j = 0; j < COLS; j++)
			{
				if (mass[i][j] == ALIVE)														// Условие для вывода в консоль живых и мертвых ячеек
				{
					std::cout << "\033[01;38;05;46m" << mass[i][j] << " " << "\033[01m";		// Визуализация цветом green живых ячеек 
					Sleep(20);
					fout << mass[i][j] << " ";
					aliveCellsTotal++;
				}
				else
				{
					std::cout << "\033[01;38;05;129m" << mass[i][j] << " " << "\033[01m";		// Визуализация цветом purple мертвых ячеек
					Sleep(20);
					fout << mass[i][j] << " ";
				}
			}
			std::cout << std::endl;
		}

		std::cout << "Generation: " << generation << " Amount alive cells: " << aliveCellsTotal << std::endl;  // Вывод контрольных значений каждой итерации поколения
		fout << "Generation: " << generation << " Amount alive cells: " << aliveCellsTotal << std::endl;

		// Инициализация массива для подсчета количества ячеек рядом с текущей и проверка количества живых клеток рядом с текущей
		//int countCells;
		for (size_t i = 0; i < ROWS; i++)
		{
			for (size_t j = 0; j < COLS; j++)
			{
				int countCells = countAliveCellsAround(i, j, mass, ROWS);
				if (mass[i][j] == ALIVE)			// если живая клетка
				{
					if (countCells < 2 || countCells > 3) // Если у живой клетки есть две или три живых соседки
					{
						newMass[i][j] = DEAD;				  // Клетка умирает от одиночества или перенаселения 
					}
					else
						newMass[i][j] = ALIVE;

				}
				else
				{
					if (countCells == 3)				 // В пустой (мёртвой) клетке, рядом с которой ровно три живых клетки	
					{
						newMass[i][j] = ALIVE;             // клетка становится живой
					}
					else
						newMass[i][j] = DEAD;
				}

			}

		}

		for (size_t i = 0; i < ROWS; i++)
		{
			for (size_t j = 0; j < COLS; j++)
			{
				mass[i][j] = newMass[i][j];
			}
		}

		if (aliveCellsTotal == 0)
		{
			std::cout << "Игра закочена, живых клеток не осталось.\n";
			fout << "Игра закочена, живых клеток не осталось.\n";
			break;
		}

		if (oldAliveCellsTotal == aliveCellsTotal)
		{
			std::cout << "Игра окончена из-за отсутствия изменения состояния системы.\n";
			fout << "Игра окончена из-за отсутствия изменения состояния системы.\n";
			break;
		}

		oldAliveCellsTotal = aliveCellsTotal;


		generation++;							// Условие для выхода из цикла
	}

	std::system("pause");
	fout.close();
	return 0;
}

int countAliveCellsAround(int x, int y, char mass[][COLS], int r) {						// Подсчет количества живых соседних ячеек массива для текущей клетки

	//Инициализация счетчика для проверки условия игры
	int countCells{};

	for (int Xnum = -1; Xnum <= 1; Xnum++)														// Инициализация границ соседник клеток от -1 до +1 по строкам
	{
		for (int Ynum = -1; Ynum <= 1; Ynum++)													// Инициализация границ соседних клеток от -1 до +1 по стобцам
		{
			int currentX = x + Xnum;															// Инициализация локальных позиции Х и У соседних клеток
			int currentY = y + Ynum;
			if (Xnum == 0 && Ynum == 0) continue;												// Отсекаем координаты текущей позиции клетки

			if ((currentX >= 0) && (currentX < r) && (currentY >= 0) && (currentY < COLS))		// Проверка условия чтоб не вышли за границы диапазона
			{
				if (mass[currentX][currentY] == ALIVE)											// Если соседская клетка будет живая то увеличиваем счетчик
				{
					countCells++;																// Количество живых клеток вокруг текущей 
				}
			}

		}
	}
	return countCells;																			// возвращаем количество живых клеток вокруг текущей позиции обратно в текущий массив
	
}
