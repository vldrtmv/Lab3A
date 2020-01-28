#pragma once
#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#pragma warning(disable: 26495)

namespace Spisok1
{
	class Spisok
	{
	private:
		static const int SZ = 20;
		int top;
		int ar[SZ];
	public:
		Spisok() : top(0) { }//инициализирующий конструктор по умолчанию
		Spisok(int a) : top(1) { ar[0] = a; }//инициализирующий конструктор единственного элемента
		Spisok(int count, int a);//инициализирующий конструктор размера списка и элементов
		int GetElem(int i) const { return ar[i]; }
		friend std::ostream& operator <<(std::ostream&, const Spisok&);//вывод
		friend std::istream& operator >>(std::istream&, Spisok&);//ввод
		friend const Spisok operator+(const Spisok&, const Spisok&);//слияние списков
		friend Spisok operator+(const Spisok&, int);//перегруженный оператор суммы
		Spisok& operator= (const Spisok&);//перегруженный оператор =
		int sorts();//упорядоченные элементы 
		Spisok& operator +=(int);//присоединение нового элемента в список
		Spisok& operator +=(Spisok&);//перегруженный оператор +=

		int dif_count();//количество групп
		const Spisok& operator()(int);//частота появления
		int& operator[](int);//перегруженный оператор индексирования
		int size_of_list() { return top; }
		int max_size_of_list() { return SZ; }
		int compare(int a, int b) { return a < b; }
	};
}

#endif // HEADER_H