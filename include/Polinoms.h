#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "RingList.h"
#include <Windows.h>

using namespace std;

struct Tmonom {
	double cf;
	unsigned int abc;
	Tmonom(const double d = 0.0, const unsigned int m = 0) { cf = d; abc = m; };
	Tmonom(const Tmonom& _Tmonom) {
		cf = _Tmonom.cf;
		abc = _Tmonom.abc;
	};
	const Tmonom& operator = (const Tmonom& _Tmonom)
	{
		cf = _Tmonom.cf;
		abc = _Tmonom.abc;
		return *this;
	};
	bool operator < (const Tmonom& _tmonom) const
	{
		return abc < _tmonom.abc;
	};
	bool operator != (const Tmonom& _tmonom) const
	{
		return abc != _tmonom.abc;
	};
	bool operator == (const Tmonom& _tmonom) const
	{
		return abc == _tmonom.abc;
	};
	Tmonom operator+ (const Tmonom& _tmonom)
	{
		Tmonom res;
		if ((*this).abc == _tmonom.abc)
		{
			res.abc = (*this).abc;
			res.cf = (*this).cf + _tmonom.cf;
		}
		else throw "unable to sum monoms!";
		return res;
	};
};

//
//friend TPolinom operator+ (const TPolinom & left_polinom, const TPolinom & right_polinom)
//{
//	TPolinom copy_of_polinom_left(left_polinom);
//	TPolinom copy_of_polinom_right(right_polinom);
//	copy_of_polinom_left.monoms.Reset();
//	copy_of_polinom_right.monoms.Reset();
//	TPolinom res(copy_of_polinom_left);
//	res.monoms.Reset();
//	for (res.monoms.current; !res.monoms.IsEnded(); res.monoms.GetNext())
//	{
//		for (copy_of_polinom_right.monoms.current; !copy_of_polinom_right.monoms.IsEnded(); copy_of_polinom_right.monoms.GetNext())
//		{
//			TLink<Tmonom>* link = res.monoms.Search(copy_of_polinom_right.monoms.current->data);
//			if (link != NULL && link->data.cf + copy_of_polinom_right.monoms.current->data.cf!= 0.0)
//				link->data.cf += copy_of_polinom_right.monoms.current->data.cf;
//			else
//				res.monoms.Insert(copy_of_polinom_right.monoms.current->data);
//		}
//	}
//	return res;
//}
//
//friend TPolinom operator* (const TPolinom &p, double d)
//{
//	TPolinom res(p);
//	res.monoms.Reset();
//	if (d == 0)
//		res.monoms.Clean();
//	else {
//		for (res.monoms.current; !res.monoms.IsEnded(); res.monoms.GetNext())
//		{
//			res.monoms.current->data.cf *= d;
//		}
//	}
//	return res;
//}
//
//friend TPolinom operator* (double d, const TPolinom &p)
//{
//	return p * d;
//}
class TPolinom {
private:
	TRingList<Tmonom> monoms;
public:
	TPolinom() {  }
	TPolinom(const string & s);
	TPolinom(const TPolinom &);
	~TPolinom();
	TPolinom operator+ (const TPolinom & _polinom);
	TPolinom operator* (const TPolinom & _polinom);
	TPolinom operator* (double d);
	TPolinom& operator = (const TPolinom& _polinom);
	friend ostream& operator<< (ostream &out, const TPolinom& _polinom)
	{
		TPolinom copy_of_polinom(_polinom);
		copy_of_polinom.monoms.Reset();
		// ЧТоб было K P A C U B O;
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 3));
		out << copy_of_polinom.monoms.current->data.cf;
		SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));
		if ((copy_of_polinom.monoms.current->data.abc / 100) != 0) {
			if ((copy_of_polinom.monoms.current->data.abc / 100) == 1)
				out << "x";
			else
				out << "x^" << (copy_of_polinom.monoms.current->data.abc / 100);
		}

		if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 != 0) {
			if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 == 1)
				out << "y";
			else out << "y^" << (copy_of_polinom.monoms.current->data.abc / 10) % 10;
		}
		if ((copy_of_polinom.monoms.current->data.abc) % 10 != 0) {
			if ((copy_of_polinom.monoms.current->data.abc % 10) == 1)
				out << "z";
			else out << "z^" << (copy_of_polinom.monoms.current->data.abc) % 10;
		}
		copy_of_polinom.monoms.GetNext();
	//c:\Users\morko\Documents\GitHub\mp2 - lab3 - arithmetic\include\Polinoms.h
		for (copy_of_polinom.monoms.current; !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
		{
			//TLink<Tmonom>* end = copy_of_polinom.monoms.GetNext();
			
			if (copy_of_polinom.monoms.current->data.cf > 0)
			{
				SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 3)); //system("color 0B");
				out << " +" << copy_of_polinom.monoms.current->data.cf;
				SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 15));//system("color 0F");
			}
			else out << copy_of_polinom.monoms.current->data.cf;
			if ((copy_of_polinom.monoms.current->data.abc / 100) != 0) {
				if ((copy_of_polinom.monoms.current->data.abc / 100) == 1)
					out << "x";
				else
					out << "x^" << (copy_of_polinom.monoms.current->data.abc / 100);
			}

			if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 != 0)
			{
				if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 == 1)
					out << "y";
				else out << "y^" << (copy_of_polinom.monoms.current->data.abc / 10) % 10;
			}
				if ((copy_of_polinom.monoms.current->data.abc) % 10 != 0) {
					if ((copy_of_polinom.monoms.current->data.abc % 10) == 1)
						out << "z";
					else out << "z^" << (copy_of_polinom.monoms.current->data.abc) % 10;
			}
			/*if ((copy_of_polinom.monoms.current->data.abc / 100) != 0) out << "x^" << (copy_of_polinom.monoms.current->data.abc / 100);
			if ((copy_of_polinom.monoms.current->data.abc / 10) % 10 != 0 ) out << " y^" << (copy_of_polinom.monoms.current->data.abc / 10) % 10;
			if ((copy_of_polinom.monoms.current->data.abc) % 10 != 0) out << " z^" << (copy_of_polinom.monoms.current->data.abc) % 10;*/
			
		}
		out << endl;
		return out;
	}
};





TPolinom::TPolinom(const string& s)
{
	string str = s;
	if (str[0] != '\0')
	{
		while (str.length() > 0)
		{
			string monom = "";
			Tmonom temp;
			string coeff = "";
			double number = 0;
			int i = 0, j = 1;
			j = 1;
			while (j < str.length() && str[j] != '+' && str[j] != '-')
				j++;
			monom = str.substr(0, j);
			str.erase(0, j);
			j = 0;
			while (j < monom.length() && !isalpha(monom[j]))
				j++;
			coeff = monom.substr(0, j);
			if (coeff == "" || coeff == "+")
				temp.cf = 1;
			else if (coeff == "-")
				temp.cf = -1;
			else temp.cf = atof(coeff.c_str());
			monom.erase(0, j);
			j = 0;
			while (j < monom.length()) // формирование степени
			{
				if (isalpha(monom[j]) && monom[j + 1] == '\0') // последняя буква в строке
				{
					switch (monom[j])
					{
					case 'x':
						temp.abc += 1 * 100;
						break;
					case 'y':

						temp.abc += 1 * 10;
						break;
					case 'z':
						temp.abc += 1;
						break;
					default:
						throw "Input error:end of string";
						break;
					} 
					j++;
				}
				else if (isalpha(monom[j]) && isalpha(monom[j+1])) // 2 буквы подряд
				{
					switch (monom[j])
					{
					case 'x':
						temp.abc += 1 * 100;
						break;
					case 'y':

						temp.abc += 1 * 10;
						break;
					case 'z':
						temp.abc += 1;
						break;
					default:
						throw "Input error:end of string";
						break;
					}
					j++;
				}
				else if (isalpha(monom[j]) && monom[j + 1] == '^' && monom[j + 2] != '\0' && isdigit(monom[j + 2]))
				{
					switch (monom[j])
					{ 
					case 'x': 
						temp.abc += atoi(&monom[j + 2]) * 100;
						j += 3;
						break;
					case 'y':
						temp.abc += atoi(&monom[j + 2]) * 10;
						j += 3;
						break;
					case 'z': 
						temp.abc += atoi(&monom[j + 2]) * 1;
						j += 3;
						break;
					}
				}
			}
			if (temp.abc != 0) {
				TLink<Tmonom>* link = monoms.Search(temp);
				if (link != NULL)
				{
					link->data.cf += temp.cf;
				}
				else
					monoms.Insert(temp);
			}
			else
			{/*
				TLink<Tmonom>* link = monoms.Search(temp);
				if (link != NULL)
				{
					link->data.cf += temp.cf;
				}
				else*/
					monoms.InsertInEnd(temp);
			}
		}

		//if (str.length() == 2) {
		//	if (isalpha(str[0]) && isalpha(str[1]))
		//	{
		//		unsigned int tempabc = 0;
		//		number = 1;
		//		if (str[0] == 'x')
		//			tempabc += 100;
		//		else if (str[0] == 'y')
		//			tempabc += 10;
		//		else if (str[0] == 'z')
		//			tempabc += 1;
		//		if (str[1] == 'x')
		//			tempabc += 100;
		//		else if (str[1] == 'y')
		//			tempabc += 10;
		//		else if (str[1] == 'z')
		//			tempabc += 1;
		//		Tmonom temp;
		//		temp.abc = tempabc;
		//		temp.cf = number;
		//		monoms.Insert(temp);
		//	}
		//	if (isdigit(str[0]) && isalpha(str[1]))
		//	{
		//		unsigned int tempabc = 0;
		//		number = double(str[0]) - 48;
		//		if (str[1] == 'x')
		//			tempabc += 100;
		//		else if (str[1] == 'y')
		//			tempabc += 10;
		//		else if (str[1] == 'z')
		//			tempabc += 1;
		//		Tmonom temp;
		//		temp.abc = tempabc;
		//		temp.cf = number;
		//		monoms.Insert(temp);
		//	}
		//	if (isdigit(str[0]) && isdigit(str[1]))
		//	{
		//		number = stod(str);
		//		Tmonom temp;
		//		temp.cf = number;
		//		monoms.Insert(temp);
		//	}
		//}

	
		}
}



TPolinom::TPolinom(const TPolinom & _polinom)
{
	monoms = _polinom.monoms;
}

TPolinom::~TPolinom()
{
}

TPolinom TPolinom::operator+ (const TPolinom & _polinom)
{
	(*this).monoms.Reset();
	TPolinom copy_of_polinom(_polinom);
	copy_of_polinom.monoms.Reset();
	TPolinom res;
	res.monoms.Reset();
	/*for ((*this).monoms.current; !(*this).monoms.IsEnded(); (*this).monoms.GetNext())
	{
		for (copy_of_polinom.monoms.current; !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
		{*/
	while (!copy_of_polinom.monoms.IsEnded() && !(*this).monoms.IsEnded())
	{
		if (copy_of_polinom.monoms.current->data < (*this).monoms.current->data)
		{
			res.monoms.InsertInEnd((*this).monoms.current->data);
			(*this).monoms.GetNext();
		}
		else if ((copy_of_polinom.monoms.current->data == (*this).monoms.current->data)
			&& ((*this).monoms.current->data.cf + copy_of_polinom.monoms.current->data.cf != 0.0))
		{
			res.monoms.InsertInEnd((*this).monoms.current->data + copy_of_polinom.monoms.current->data);
			(*this).monoms.GetNext();
			copy_of_polinom.monoms.GetNext();
		}
		else
		{
			res.monoms.InsertInEnd(copy_of_polinom.monoms.current->data);
			copy_of_polinom.monoms.GetNext();
		}
	}
	while (!copy_of_polinom.monoms.IsEnded())
	{
		res.monoms.InsertInEnd(copy_of_polinom.monoms.current->data);
		copy_of_polinom.monoms.GetNext();
	}
	while (!(*this).monoms.IsEnded())
	{
		res.monoms.InsertInEnd((*this).monoms.current->data);
		(*this).monoms.GetNext();
	}
	return res;
}

TPolinom TPolinom::operator* (const TPolinom & _polinom)
{
	(*this).monoms.Reset();
	TPolinom copy_of_polinom(_polinom);
	copy_of_polinom.monoms.Reset();
	TPolinom res;
	res.monoms.Reset();
	for ((*this).monoms.current; !(*this).monoms.IsEnded(); (*this).monoms.GetNext())
	{
		for (copy_of_polinom.monoms.current; !copy_of_polinom.monoms.IsEnded(); copy_of_polinom.monoms.GetNext())
		{
			if (((*this).monoms.current->data.abc + copy_of_polinom.monoms.current->data.abc < 1000) &&
				(((*this).monoms.current->data.abc / 10 % 10  + copy_of_polinom.monoms.current->data.abc / 10 % 10) < 10) &&
				(((*this).monoms.current->data.abc % 10 + copy_of_polinom.monoms.current->data.abc % 10) < 10))
			{
				unsigned int tmpabc = (*this).monoms.current->data.abc + copy_of_polinom.monoms.current->data.abc;
				Tmonom tmp((*this).monoms.current->data.cf * copy_of_polinom.monoms.current->data.cf, tmpabc);
				TLink<Tmonom>* tmp2 = res.monoms.Search(tmp);
				if (tmp2 != NULL)
					tmp2->data.cf = (*this).monoms.current->data.cf * copy_of_polinom.monoms.current->data.cf;
				else
					res.monoms.Insert(tmp);
			}
			else throw "Power is more then expected";
		}
		copy_of_polinom.monoms.Reset();
	}
	return res;
}

//const TPolinom TPolinom::operator- (const TPolinom & _polinom)
//{
//	TPolinom res, operand2;
//	operand2 = _polinom * (-1);
//	res = *this + operand2;
//	return res;
//}

TPolinom TPolinom::operator* (double d)
{
	TPolinom res = (*this);
	res.monoms.Reset();
	if (d == 0)
		res.monoms.Clean();
	else {
		while (!res.monoms.IsEnded())
		{
			res.monoms.current->data.cf *= d;
			res.monoms.GetNext();
		}
	}
	return res;
}
TPolinom& TPolinom::operator =(const TPolinom& _polinom)
{
	monoms = _polinom.monoms;
	return *this;
};
