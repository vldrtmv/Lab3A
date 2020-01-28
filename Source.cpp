#include "Header.h"
#include "Header1.h"
#pragma warning(disable: 26495)
#pragma warning(disable: 6001)

namespace Spisok1
{
	Spisok::Spisok(int countt, int a)
	{
		top = countt;
		try {
			for (int i = 0; i < top; ++i)
				ar[i] = a * i + 5;
		}
		catch (std::exception& msg) {
			std::cout << "Too many elements" << msg.what() << std::endl;
		}
	}

	std::ostream& operator <<(std::ostream& s, const Spisok& sp)
	{
		s << "{ ";
		if (sp.top == 0)
			s << "List is empty";
		else
		{
			for (int i = 0; i < sp.top; ++i)
			{
				if (i == sp.top - 1)
					s << sp.ar[i];
				else
					s << sp.ar[i] << ", ";
			}
		}
		s << " }";
		s << std::endl;
		return s;
	}

	std::istream& operator >>(std::istream& s, Spisok& sp)
	{
		std::cout << "Enter size of List: ";
		s >> sp.top;
		std::cout << "Enter elements of List: \n";
		for (int i = 0; i < sp.top; ++i)
			s >> sp.ar[i];
		return s;
	}

	const Spisok operator+(const Spisok& first, const Spisok& second)
	{
		Spisok tmp;
		if (first.top + second.top > first.SZ)
		{
			std::cout << "Line over flow" << std::endl;
			return tmp;
		}
		tmp.top = first.top + second.top;
		for (int i = 0; i < first.top; ++i)
			tmp.ar[i] = first.ar[i];
		for (int i = 0; i < second.top; ++i)
			tmp.ar[i + first.top] = second.ar[i];
		return tmp;
	}

	Spisok operator+(const Spisok& list, int a)
	{
		Spisok tmp;
		tmp.top = list.top;
		for (int i = 0; i < list.top; ++i) { tmp.ar[i] = list.ar[i]; }
		if (tmp.top < tmp.SZ) {
			tmp.top++;
			tmp.ar[tmp.top - 1] = a;
		}
		else
			std::cout << "List if full" << std::endl;
		return tmp;
	}

	Spisok& Spisok::operator=(const Spisok& sp)
	{
		if (this != &sp) {
			top = sp.top;
			for (int i = 0; i < top; ++i)
				ar[i] = sp.ar[i];
		}
		return *this;
	}

	int Spisok::sorts()
	{
		if (top < 3) return 0;
		int comp[SZ];
		for (int i = 0; i < top - 1; ++i)
			comp[i] = compare(ar[i], ar[i + 1]);
		int i = 0;
		int beg = 0, fin = 0;
		while (top > 2 && i < top - 2) {
			if (comp[i] == comp[i + 1]) {
				beg = i;
				while (comp[i] == comp[i + 1])
					i++;
				fin = i + 1;
				break;
			}
			else i++;
		}
		if (fin) {
			std::cout << "{ ";
			for (i = beg; i <= fin; ++i) {
				if (i != fin)
					std::cout << ar[i] << ", ";
				else
					std::cout << ar[i];
			}
			std::cout << " }" << std::endl << std::endl;
			return 1;
		}
		else return -1;
	}

	Spisok& Spisok::operator+=(int a)
	{
		if (top < SZ)
			ar[top++] = a;
		else
			throw std::exception("List overflow");
		return *this;
	}



	Spisok& Spisok::operator+=(Spisok& list)
	{
		if (top + list.top > SZ)
		{
			std::cout << "List is full" << std::endl;
			return *this;
		}
		int n = top;
		top += list.top;
		for (int i = 0; i < list.top; ++i)
			ar[i + n] = list.ar[i];
		return *this;
	}

	int Spisok::dif_count()
	{
		int count = 0;
		for (int i = 0; i < top; ++i)
			for (int j = i + 1; j < top; ++j)
				if (ar[i] == ar[j])
					count++;
		if (count)
			return top - 2 * count;
		else
			return top;
	}

	const Spisok& Spisok::operator()(int a)
	{
		int count = 0;
		for (int i = 0; i < this->top; ++i)
			if (this->ar[i] == a)
				count++;
		std::cout << "Element " << a << " repeated " << count << " times" << std::endl << std::endl;
		return *this;
	}

	int& Spisok::operator[](int index)
	{
		if (0 < index < top)
			return ar[index];
		else
			std::cout << "Out of range" << std::endl;
	}

		unsigned getnum(const char* msg)
		{
			while (true) {
				std::cout << msg;
				int a;
				std::cin >> a;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Incorrect input. Try again." << std::endl;
				}
				else {
					std::cin.ignore(32767, '\n');
					return a;
				}
			}
		}

	Spisok case1()
	{
		int a1 = getnum("Enter the element: ");
		Spisok sp1(a1);
		std::cout << ">>>List created" << std::endl;
		return sp1;
	}

	Spisok case2()
	{
		int count = getnum("Enter size of the list: ");
		int a2 = getnum("Enter the element to generate the list: ");
		Spisok sp2(count, a2);
		std::cout << ">>>List created" << std::endl;
		return sp2;
	}
}
