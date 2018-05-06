#include <cstdio>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <vector>
#include "Polinoms.h"
#include <Windows.h>


int main() {
	//HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hwnd, FOREGROUND_ | FOREGROUND_INTENSITY);
	system("color 0F");
	std::string s;
	std::cout << "Enter your polinom. It must be like '25x^2+34x^2y^8z^4' " << std::endl;
	//std::cin >> s;

	TPolinom zero("");
	std::vector<TPolinom> Vector_of_Polinoms;
	TPolinom temp1("-50xy^3+xyz+4zxy-5y+y+z");
	Vector_of_Polinoms.push_back(temp1);
	TPolinom temp2("25x^2-34y^2z^6x^4");
	Vector_of_Polinoms.push_back(temp2);
	TPolinom temp3("58x^1y^2z^3");
	Vector_of_Polinoms.push_back(temp3);
	int menu = 1;
	int nPolinoms = 1;
	int a, b, c;
	std::cout << "Menu:" << endl;
	std::cout << "1. Add new polinom" << endl;
	std::cout << "2. Delete existing polinom" << endl;
	std::cout << "3. Sum two polinoms" << endl;
	std::cout << "4. Multiple two polinoms" << endl;
	std::cout << "5. Multiple polinom on number" << endl;
	std::cout << "6. Print polinom" << endl;
	std::cin >> menu;
	while (menu < 7 && menu > 0)
	{
		switch (menu)
		{
		case 1: 
		{ std::cout << "Enter your polinom. It must be like '25x^2+34x^2y^8z^4' " << std::endl;
		std::cin >> s;
		TPolinom temp1(s);
		Vector_of_Polinoms.push_back(temp1);
		nPolinoms++;
		std::cout << "Menu:" << endl;
		std::cout << "1. Add new polinom" << endl;
		std::cout << "2. Delete existing polinom" << endl;
		std::cout << "3. Sum two polinoms" << endl;
		std::cout << "4. Multiple two polinoms" << endl;
		std::cout << "5. Multiple polinom on number" << endl;
		std::cout << "6. Print polinom" << endl;
		std::cin >> menu;
		break; }
		case 2:
			do {
				std::cout << "Enter number of the polinom you want to delete " << std::endl;
				std::cin >> a;
			} while (a < 0 || a > nPolinoms);
			Vector_of_Polinoms[a]=zero;
			std::cout << "Menu:" << endl;
			std::cout << "1. Add new polinom" << endl;
			std::cout << "2. Delete existing polinom" << endl;
			std::cout << "3. Sum two polinoms" << endl;
			std::cout << "4. Multiple two polinoms" << endl;
			std::cout << "5. Multiple polinom on number" << endl;
			std::cout << "6. Print polinom" << endl;
			std::cin >> menu;
			break;
		case 3:
			do {
				std::cout << "Enter number of the first polinom you want to sum " << std::endl;
				std::cin >> a;
			} while (a < 0 || a > Vector_of_Polinoms.size());
			do {
				std::cout << "Enter number of the second polinom you want to sum " << std::endl;
				std::cin >> b;
			} while (b < 0 || b > Vector_of_Polinoms.size());
			do {
				std::cout << "Enter number of the polinom you want to save the result. If you dont want to save, enter '-1' " << std::endl;
				std::cin >> c;
			} while (c < -1 || c > (int)Vector_of_Polinoms.size());
			if (c == -1)
			{
				TPolinom res;
				res = Vector_of_Polinoms[a] + Vector_of_Polinoms[b];
				std::cout << res;
			}
			else if (c > -1)
				Vector_of_Polinoms[c] = Vector_of_Polinoms[a] + Vector_of_Polinoms[b];
			std::cout << "Menu:" << endl;
			std::cout << "1. Add new polinom" << endl;
			std::cout << "2. Delete existing polinom" << endl;
			std::cout << "3. Sum two polinoms" << endl;
			std::cout << "4. Multiple two polinoms" << endl;
			std::cout << "5. Multiple polinom on number" << endl;
			std::cout << "6. Print polinom" << endl;
			std::cin >> menu;
			break;
		case 4:
			do {
				std::cout << "Enter number of the first polinom you want to multiple " << std::endl;
				std::cin >> a;
			} while (a < 0 || a > Vector_of_Polinoms.size());
			do {
				std::cout << "Enter number of the second polinom you want to multiple " << std::endl;
				std::cin >> b;
			} while (b < 0 || b > Vector_of_Polinoms.size());
			do {
				std::cout << "Enter number of the polinom you want to save the result. If you dont want to save, enter '-1' " << std::endl;
				std::cin >> c;
			} while (c < -1 || c > (int)Vector_of_Polinoms.size());
			if (c == -1)
			{
				TPolinom res;
				res = Vector_of_Polinoms[a] * Vector_of_Polinoms[b];
				std::cout << res;
			}
			else if (c > -1)
				Vector_of_Polinoms[c] = Vector_of_Polinoms[a] * Vector_of_Polinoms[b];
			std::cout << "Menu:" << endl;
			std::cout << "1. Add new polinom" << endl;
			std::cout << "2. Delete existing polinom" << endl;
			std::cout << "3. Sum two polinoms" << endl;
			std::cout << "4. Multiple two polinoms" << endl;
			std::cout << "5. Multiple polinom on number" << endl;
			std::cout << "6. Print polinom" << endl;
			std::cin >> menu;
			break;
		case 5:
			double d;
			do {
				std::cout << "Enter number of the first polinom you want to multiple " << std::endl;
				std::cin >> a;
			} while (a < 0 || a > Vector_of_Polinoms.size());
			std::cout << "Enter number you want your polinom to multiple" << std::endl;
			std::cin >> d;
			do {
				std::cout << "Enter number of the polinom you want to save the result. If you dont want to save, enter '-1' " << std::endl;
				std::cin >> c;
			} while (c < -1 || c > (int)Vector_of_Polinoms.size());
			if (c == -1)
			{
				TPolinom res;
				res = Vector_of_Polinoms[a] * d;
				std::cout << res;
			}
			else if (c > -1)
				Vector_of_Polinoms[c] = Vector_of_Polinoms[a] * d;
			std::cout << "Menu:" << endl;
			std::cout << "1. Add new polinom" << endl;
			std::cout << "2. Delete existing polinom" << endl;
			std::cout << "3. Sum two polinoms" << endl;
			std::cout << "4. Multiple two polinoms" << endl;
			std::cout << "5. Multiple polinom on number" << endl;
			std::cout << "6. Print polinom" << endl;
			std::cin >> menu;
			break;
		case 6:
			do {
				std::cout << "Choose polinom you want to print" << std::endl;
				std::cin >> a;
			} while (a < 0 || a >= Vector_of_Polinoms.size());
			std::cout << Vector_of_Polinoms[a];
			std::cout << "Menu:" << endl;
			std::cout << "1. Add new polinom" << endl;
			std::cout << "2. Delete existing polinom" << endl;
			std::cout << "3. Sum two polinoms" << endl;
			std::cout << "4. Multiple two polinoms" << endl;
			std::cout << "5. Multiple polinom on number" << endl;
			std::cout << "6. Print polinom" << endl;
			std::cin >> menu;
			break;
		default:exit(1);
		}
	}
	return 0;
}
