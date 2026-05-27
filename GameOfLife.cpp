#include<iostream>
#include<windows.h>

// Инициализация размера поля 
const int ROWS{ 10 };
const int COLS{ 10 };

// Инициализация значениями мертвой и живой ячеек
char ALIVE = '*';
char DEAD = '-';

int countAliveCellsAround(int x, int y, char mass[][COLS], int r);

int main() {

	setlocale(LC_CTYPE, "ru.UTF-8");
	// Инициализация поколения
	int generation{ 0 };

	// Инициализация статического массива для сохранения значений в процессе работы программы
	static char mass[ROWS][COLS];

	// Для рандомной инициализации ячеек  
	srand(time(nullptr));
	// Количество живых ячеек в поколнении
	int aliveCellsTotal{};
	static int oldAliveCellsTotal{};
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
		for (size_t i = 0; i < ROWS; i++)
		{
			for (size_t j = 0; j < COLS; j++)
			{
				if (mass[i][j] == ALIVE)														// Условие для вывода в консоль живых и мертвых ячеек
				{
					std::cout << "\033[01;38;05;46m" << mass[i][j] << " " << "\033[01m";		// Визуализация цветом green живых ячеек 
					Sleep(20);
					aliveCellsTotal++;
				}
				else
				{
					std::cout << "\033[01;38;05;129m" << mass[i][j] << " " << "\033[01m";		// Визуализация цветом purple мертвых ячеек
					Sleep(20);
				}
			}
			std::cout << std::endl;
		}

		std::cout << "Generation: " << generation << " Amount alive cells: " << aliveCellsTotal << std::endl;  // Вывод контрольных значений каждой итерации поколения


		// Инициализация массива для подсчета количества ячеек рядом с текущей и проверка количества живых клеток рядом с текущей
		int countCells;
		for (size_t i = 0; i < ROWS; i++)
		{
			for (size_t j = 0; j < COLS; j++)
			{
				countCells = countAliveCellsAround(i, j, mass, ROWS);
				if (mass[i][j] == ALIVE)			// если живая клетка
				{
					if (countCells < 2 || countCells > 3) // Если у живой клетки есть две или три живых соседки
					{
						mass[i][j] = DEAD;				  // Клетка умирает от одиночества или перенаселения 
					}

				}
				else
				{
					if (countCells == 3)				 // В пустой (мёртвой) клетке, рядом с которой ровно три живых клетки	
					{
						mass[i][j] == ALIVE;             // клетка становится живой
					}
				}

			}

		}

		if (aliveCellsTotal == 0)
		{
			std::cout << "Игра закочена, живых клеток не осталось.\n";
			break;
		}

		



		if (oldAliveCellsTotal == aliveCellsTotal)
		{
			std::cout << "Игра окончена из-за отуствия изменения состояния системы.\n";
			break;
		}
		
		oldAliveCellsTotal = aliveCellsTotal;

		aliveCellsTotal = 0;					// Обнуление количества ячеек для последующей итерации
		generation++;							// Условие для выхода из цикла
	}
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

			if ((currentX >= 0) && (currentY < r) && (currentY >= 0) && (currentY < COLS))		// Проверка условия чтоб не вышли за границы диапазона
			{
				if (mass[currentX][currentY] == ALIVE)											// Если соседская клетка будет живая то увеличиваем счетчик
				{
					countCells++;																// Количество живых клеток вокруг текущей 
				}
			}

		}
	}
	return countCells;																			// возвращаем количество живых клеток вокруг текущей позиции обртано в текущий массив
}
