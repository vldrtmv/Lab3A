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
		Spisok() : top(0) { }//���������������� ����������� �� ���������
		Spisok(int a) : top(1) { ar[0] = a; }//���������������� ����������� ������������� ��������
		Spisok(int count, int a);//���������������� ����������� ������� ������ � ���������
		int GetElem(int i) const { return ar[i]; }
		friend std::ostream& operator <<(std::ostream&, const Spisok&);//�����
		friend std::istream& operator >>(std::istream&, Spisok&);//����
		friend const Spisok operator+(const Spisok&, const Spisok&);//������� �������
		friend Spisok operator+(const Spisok&, int);//������������� �������� �����
		Spisok& operator= (const Spisok&);//������������� �������� =
		int sorts();//������������� �������� 
		Spisok& operator +=(int);//������������� ������ �������� � ������
		Spisok& operator +=(Spisok&);//������������� �������� +=

		int dif_count();//���������� �����
		const Spisok& operator()(int);//������� ���������
		int& operator[](int);//������������� �������� ��������������
		int size_of_list() { return top; }
		int max_size_of_list() { return SZ; }
		int compare(int a, int b) { return a < b; }
	};
}

#endif // HEADER_H