#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <list> // Заголовок списка.
#include <vector> // Класс шаблонов контейнеров.
#include <algorithm> // Набор функций для выполнения алгоритмических операций.
#include <ctime> // Подключаем заголовочный файл времени.

#pragma region Classes  

// Классы для реализации ввода + Наследование + Полиморфизм подтипов.
class Coordinates { // Базовый класс.
public:
	int X, Y, Z, size; // X,Y - координаты объекта в зависимости от класса, size - размер карты.
	int getCoordinates() {
		std::cout << "";
		std::cout << "";
		std::cin >> X;
		std::cout << "";
		std::cin >> Y;
		std::cout << "\n";
		return X, Y;
	}
};

class MapCoordinates : public Coordinates { // Дочерний класс для размеров карты.
public:
	int virtual getCoordinates() {
		std::cout << "Введите размер карты.\n";
	reStartCoordinatesSize:
		std::cout << "Size:= ";
		std::cin >> size;
		if (!std::cin) // Проверка на ошибку ввода
		{ // Пользователь ввёл не int
			std::cin.clear(); // Сбрасываем флаг ошибки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Сбрасываем невалидный ввод		
			std::cout << "\n" << "Ошибка ввода." << "\n";
			goto reStartCoordinatesSize; // Ввод снова.
		}
		if (size < 2) {
			std::cout << "\n" << "Размер карты не может быть меньше 2." << "\n";
			goto reStartCoordinatesSize; // Ввод снова.
		}
		return size;
	}
};

class StartCoordinates : public Coordinates { // Дочерний класс для координатов точки старта.
public:
	int virtual getCoordinates() {
		std::cout << "\n";
		std::cout << "Введите координаты точки старта.\n";
	reStartCoordinatesX:
		std::cout << "X:= ";
		std::cin >> X;
		if (!std::cin || (X < 1)) // Проверка на ошибку ввода
		{ // Пользователь ввёл не int
			std::cin.clear(); // Сбрасываем флаг ошибки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Сбрасываем невалидный ввод		
			std::cout << "\n" << "Ошибка ввода." << "\n";
			goto reStartCoordinatesX; // Ввод снова.
		}
	reStartCoordinatesY:
		std::cout << "Y:= ";
		std::cin >> Y;
		if (!std::cin || (Y < 1)) // Проверка на ошибку ввода
		{ // Пользователь ввёл не int
			std::cin.clear(); // Сбрасываем флаг ошибки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Сбрасываем невалидный ввод		
			std::cout << "\n" << "Ошибка ввода." << "\n";
			goto reStartCoordinatesY; // Ввод снова.
		}
		X--; // Счёт массива начинается с 0, а значит условной точке (1;1), соответствует клетка массива (0;0).
		Y--;
		return X, Y;
	}
};

class TargetCoordinates : public Coordinates { // Дочерний класс для координатов точки конца.
public:
	int virtual getCoordinates() {
		std::cout << "\n";
		std::cout << "Введите координаты точки конца.\n";
	reTargetCoordinatesX:
		std::cout << "X:= ";
		std::cin >> X;
		if (!std::cin || (X < 1)) // Проверка на ошибку ввода
		{ // Пользователь ввёл не int
			std::cin.clear(); // Сбрасываем флаг ошибки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Сбрасываем невалидный ввод		
			std::cout << "\n" << "Ошибка ввода." << "\n";
			goto reTargetCoordinatesX; // Ввод снова.
		}
	reTargetCoordinatesY:
		std::cout << "Y:= ";
		std::cin >> Y;
		if (!std::cin || (Y < 1)) // Проверка на ошибку ввода
		{ // Пользователь ввёл не int
			std::cin.clear(); // Сбрасываем флаг ошибки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Сбрасываем невалидный ввод		
			std::cout << "\n" << "Ошибка ввода." << "\n";
			goto reTargetCoordinatesY; // Ввод снова.
		}
		std::cout << "\n";
		X--; // Счёт массива начинается с 0, а значит условной точке (1;1), соответствует клетка массива (0;0).
		Y--;
		return X, Y;
	}
};

class BarrierCoordinates : public Coordinates { // Дочерний класс для препятствий.
public:
	int virtual getCoordinates() {
		std::cout << "\n";
		std::cout << "Введите координаты препятствия.\n";
	reBarrierCoordinatesX:
		std::cout << "X:= ";
		std::cin >> X;
		if (!std::cin || (X < 1)) // Проверка на ошибку ввода
		{ // Пользователь ввёл не int
			std::cin.clear(); // Сбрасываем флаг ошибки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Сбрасываем невалидный ввод		
			std::cout << "\n" << "Ошибка ввода." << "\n";
			goto reBarrierCoordinatesX; // Ввод снова.
		}
	reBarrierCoordinatesY:
		std::cout << "Y:= ";
		std::cin >> Y;
		if (!std::cin || (Y < 1)) // Проверка на ошибку ввода
		{ // Пользователь ввёл не int
			std::cin.clear(); // Сбрасываем флаг ошибки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Сбрасываем невалидный ввод		
			std::cout << "\n" << "Ошибка ввода." << "\n";
			goto reBarrierCoordinatesY; // Ввод снова.
		}
		std::cout << "\n";
		X--; // Счёт массива начинается с 0, а значит условной точке (1;1), соответствует клетка массива (0;0).
		Y--;
		return X, Y;
	}
};

class Vector2 // Для хранения\ввода координат конца и начала.
{
	int x, y;
public:
	Vector2(int _x, int _y) : x(_x), y(_y) {}
	Vector2() = default;
	Vector2 operator +(const Vector2& other) {
		Vector2 temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}
	int getX() const { return x; }
	int getY() const { return y; }

	friend class Map;
};

struct Node // Совокупность переменных, объединенных одним именем.(Структура)
{
	Vector2 position;
	int G, H, F;
	Node* parent = nullptr;

	Node() = default;
	Node(const Node& other) = default;
	Node(Vector2 pos) :position(pos) {};

	void calc(const Vector2& endPos) {
		H = static_cast<int>((abs(static_cast<double>(position.getX() - endPos.getX())) + abs(static_cast<double>(position.getY() - endPos.getY()))));
		G = parent ? parent->G + 1 : 1;
		F = G + H; //G — расстояние от старта до точки, H — примерное расстояние от точки до цели.
	}

	bool operator==(const Node& other) const {
		return (position.getX() == other.position.getX() && position.getY() == other.position.getY());
	}
	bool operator!=(const Node& other) const {
		return !(*this == other);
	}
	bool operator<(const Node& other)  const {
		return(F < other.F);
	}
};

class Map // Возможности карты.
{
	std::vector<char> data;
	int size;
public:
	Map() = default;
	Map(int _size) : size(_size) {
		data.resize(size * size);
		for (int i = 0; i < size * size; ++i) data[i] = '.';
	}
	void display() const {
		for (int i = 1; i <= size * size; ++i) {
			std::cout << data[i - 1] << " ";
			if (!(i % size)) std::cout << "\n";
		}
	}
	bool getIfInDanger(Vector2 position) const {
		if (position.y < 0) position.y = 0;
		if (position.x < 0) position.x = 0;
		if (position.y >= size) position.y = size - 1;
		if (position.x >= size) position.x = size - 1;
		return(data[position.getX() + (position.getY() * size)] == '#');
	}
	void setElement(char&& asda, Vector2 position) {
		data[position.getX() + (position.getY() * size)] = asda;
	}
};

class Solver // Класс который хранит решение.
{
	char question;
	Vector2 startPos, endPos;
	std::vector<Vector2> directions;
	Map map;
public:
	Solver(Vector2 _startPos, Vector2 _endPos, int size) : startPos(_startPos), endPos(_endPos) {
		Map temp(size);
		map = temp;

		BarrierCoordinates barrier; // Объявляем объект target, класса TargetCoordinates.

		std::cout << "Хотите добавить препядствия?(+/-)";
	reAnsverAboutCreateBarrier:
		std::cin >> question;
		if (question != '+' && question != '-')
		{
			system("cls");
			std::cout << "\n" << "Некорректный ввод, введите \"+\" или \"-\": ";
			goto reAnsverAboutCreateBarrier;
		}
		if (question == '+') {
			BarrierCoordinates barrier; // Объявляем объект target, класса TargetCoordinates.
		createBarrier: // Ещё 1 препятствиие.
		barrierMoreThenMap:
			barrier.getCoordinates(); // Вызов функции класса, получаем координаты препятствия.
			if (barrier.X >= size || barrier.Y >= size) {
				std::cout << "Препятствие не может быть за пределами карты!" << "\n" << "Повторите попытку." << "\n";
				goto barrierMoreThenMap;
			}

			if ((startPos.getX() == barrier.X && startPos.getY() == barrier.Y) || (endPos.getX() == barrier.X && endPos.getY() == barrier.Y)) {
				std::cout << "Нельзя поставить препядствие в точке начала или конца." << "\n";
				goto createBarrier;
			}

			map.setElement('#', Vector2(barrier.X, barrier.Y));
			std::cout << "Ещё препятствие?(+/-)";
			std::cin >> question;
		reAnsverBarrier:
			if (question == '+' || question == '-') {
				if (question == '+') {
					goto createBarrier;
				}
			}
			else {
				system("cls");
				std::cout << "\n" << "Некорректный ввод, введите \"+\" или \"-\": ";
				std::cin >> question;
				goto reAnsverBarrier;
			}
		}
		
		system("cls");

		directions.resize(8); // Направления.
		directions[0] = Vector2(-1, 1);
		directions[1] = Vector2(-1, 0);
		directions[2] = Vector2(-1, -1);
		directions[3] = Vector2(0, 1);
		directions[4] = Vector2(0, -1);
		directions[5] = Vector2(1, 1);
		directions[6] = Vector2(1, 0);
		directions[7] = Vector2(1, -1);
	}
	bool aStar(int size) {
		
		Node startNode(startPos);
		Node goalNode(Vector2(endPos.getX(), endPos.getY()));

		std::list<Node> openList;
		std::list<Node> closedList;

		startNode.calc(endPos);
		openList.push_back(startNode);

		while (!openList.empty()) {
			auto current = Node(*std::min_element(openList.begin(), openList.end()));

			current.calc(endPos);

			closedList.push_back(current);
			openList.remove(current);
			if (current == goalNode) break;

			for (auto& direction : directions) {
				Node successor(direction + current.position);

				if (map.getIfInDanger(successor.position) || successor.position.getX() > size - 1 ||
					successor.position.getY() > size - 1 || successor.position.getX() < 0 ||
					successor.position.getY() < 0 ||
					std::find(closedList.begin(), closedList.end(), successor) != closedList.end()) {
					continue;
				}

				successor.calc(endPos);

				auto inOpen = std::find(openList.begin(), openList.end(), successor);
				if (inOpen == openList.end()) {
					successor.parent = &closedList.back();
					successor.calc(endPos);

					openList.push_back(successor);
				}
				else
					if (successor.G < inOpen->G) successor.parent = &closedList.back();
			}
		}

		if (!openList.size()) {
			std::cout << "Маршрута не существует!\n";
			return false;
		}

		auto inClosed = std::find(closedList.begin(), closedList.end(), goalNode);
		if (inClosed != closedList.end()) {
			while (*inClosed != startNode) {
				map.setElement('o', inClosed->position);
				*inClosed = *inClosed->parent;
			}
		}

		std::cout << "Маршрут существует!\n" << "\n";

		clock_t time; // Тип данных способный представлять временные тики. 
		time = clock();

		map.display();

		time = clock() - time;
		std::cout << "\n";
		printf("Маршрут найден, за: %f\n", (double)time / CLOCKS_PER_SEC);
		return true;
	}
};

int main()
{
	char question;

	setlocale(LC_ALL, "Russian"); // Русификатор.

	beginning:

	MapCoordinates map; // Объявляем объект map, класса MapCoordinates.
	map.getCoordinates(); // Вызов функции класса, получаем размер карты.

	StartCoordinates start; // Объявляем объект start, класса StartCoordinates.
	startMoreThenMap:
	start.getCoordinates(); // Вызов функции класса, получаем координаты начала.
	if (start.X >= map.size || start.Y >= map.size) {
		std::cout << "\n";
		std::cout << "Точка старта не может быть за пределами карты!" << "\n" << "Повторите попытку." << "\n";
		goto startMoreThenMap;
	}

	TargetCoordinates target; // Объявляем объект target, класса TargetCoordinates.
	targetMoreThenMap:
	target.getCoordinates(); // Вызов функции класса, получаем координаты конца.
	if (target.X >= map.size || target.Y >= map.size) {
		std::cout << "Точка конца не может быть за пределами карты!" << "\n" << "Повторите попытку." << "\n";
		goto targetMoreThenMap;
	}

	Solver solve(Vector2(start.X, start.Y), Vector2(target.X, target.Y), map.size);

	clock_t time; // Тип данных способный представлять временные тики. 
	time = clock();

	solve.aStar(map.size);

	time = clock() - time;
	printf("Программа отработала, за: %f\n", (double)time / CLOCKS_PER_SEC);

	std::cout << "\n" << "Хотите ввести другие значения?(+/-)";
	std::cin >> question;
reAnsverEnd:
	if (question == '+' || question == '-') {
		if (question == '+') { // Повторное выполнение программы при question == "+".
			system("cls"); // Очистка экрана.
			goto beginning; // На начало.
		}
		else {
			return 0;
		}
	}
	else {
		system("cls");
		std::cout << "\n" << "Некорректный ввод, введите \"+\" или \"-\": ";
		std::cin >> question;
		goto reAnsverEnd; 
	}
}