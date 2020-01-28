#include "Header.h"
#include "Header1.h"

using namespace Spisok1;

const char* MENU[]{ "1. Create the list with one element", "2. Create the list with size and element", "3. Create the list", "4. Sum 'Second(size and elements)' and 'List 1'", "5. Show the list", "6. Count the number of different groups in the list", "7. Show the first sorted piece of the list", "8. Show count of the same number in the list", "9. Add new element in the list", "10. Show the menu", "0. Exit" };
const char* LISTS[]{ "First(one element)", "Second(size and elements)", "List 1", "New list" };
const unsigned listSZ = sizeof(LISTS) / sizeof(LISTS[0]);
const unsigned menuSZ = sizeof(MENU) / sizeof(MENU[0]);


int main()
{
	Spisok sp, sp1, sp2, newlist;
	unsigned ch = 1, ch2 = 1, ch7 = 1, ch8 = 1, ch9 = 1;
	std::cout << "Max size of the Lists = " << sp.max_size_of_list() << std::endl;
	unsigned menu = 1;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	if (menu)
		for (size_t i = 0; i < menuSZ; ++i)
			std::cout << MENU[i] << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	do
	{
		std::cout << std::endl;
		menu = getnum("Make your choice ---> ");
		std::cout << std::endl;
		switch (menu)
		{

		case 1:
			sp1 = case1();
			break;
		case 2:
			sp2 = case2();
			break;
		case 3:
			std::cin >> sp;
			std::cout << ">>>List created" << std::endl;
			break;
		case 4:
			try {
				newlist = sp + sp2;
				std::cout << ">>>List created" << std::endl;
			}
			catch (const std::exception& msg) {
				std::cout << msg.what() << std::endl;
			}
			break;
		case 5:
			if (ch)
				for (size_t i = 0; i < listSZ; ++i)
					std::cout << i + 1 << ". " << LISTS[i] << std::endl;
			std::cout << "0. Exit" << std::endl;
			do {
				std::cout << std::endl;
				ch = getnum("Choose the list ---> ");
				std::cout << std::endl;
				switch (ch) {
				case 0:
					break;
				case 1:
					std::cout << sp1 << std::endl;
					break;
				case 2:
					std::cout << sp2 << std::endl;
					break;
				case 3:
					std::cout << sp << std::endl;
					break;
				case 4:
					std::cout << newlist << std::endl;
					break;
				default:
					if (!ch)
						break;
				}
			} while (ch);
			ch = 1;
			break;
		case 6:
			if (ch2)
				for (size_t i = 0; i < listSZ; ++i)
					std::cout << i + 1 << ". " << LISTS[i] << std::endl;
			std::cout << "0. Exit" << std::endl;
			do {
				std::cout << std::endl;
				ch2 = getnum("Choose the list ---> ");
				std::cout << std::endl;
				switch (ch2) {
				case 1:
					std::cout << "The number of different groups in the list = " << sp1.dif_count() << std::endl;
					break;
				case 2:
					std::cout << "The number of different groups in the list = " << sp2.dif_count() << std::endl;
					break;
				case 3:
					std::cout << "The number of different groups in the list = " << sp.dif_count() << std::endl;
					break;
				case 4:
					std::cout << "The number of different groups in the list = " << newlist.dif_count() << std::endl;
					break;
				default:
					std::cout << "The number of different groups in the list = "  "Incorrect input" << std::endl;
					break;
				}
			} while (ch2);
			ch2 = 1;
			break;
		case 7:
			if (ch7)
				for (size_t i = 0; i < listSZ; ++i)
					std::cout << i + 1 << ". " << LISTS[i] << std::endl;
			std::cout << "0. Exit" << std::endl;
			do {
				std::cout << std::endl;
				ch7 = getnum("Choose the list ---> ");
				std::cout << std::endl;
				switch (ch7) {
				case 1:
					std::cout << sp1.sorts() << std::endl;
					break;
				case 2:
					sp2.sorts();
					std::cout << std::endl;
					break;
				case 3:
					std::cout << sp.sorts() << std::endl;
					break;
				case 4:
					std::cout << newlist.sorts() << std::endl;
					break;
				default:
					if (!ch7)
						break;
				}
			} while (ch7);
			ch7 = 1;
			break;
		case 8:
			if (ch8)
				for (size_t i = 0; i < listSZ; ++i)
					std::cout << i + 1 << ". " << LISTS[i] << std::endl;
			std::cout << "0. Exit" << std::endl;
			do {
				std::cout << std::endl;
				ch8 = getnum("Choose the list ---> ");
				std::cout << std::endl;
				switch (ch8) {
				case 1:
					std::cout << "Choose the number for count it in '" << LISTS[0] << "' list: ";
					int el1;
					std::cin >> el1;
					sp1(el1);
					break;
				case 2:
					std::cout << "Choose the number for count it in '" << LISTS[1] << "' list: ";
					int el2;
					std::cin >> el2;
					sp2(el2);
					break;
				case 3:
					std::cout << "Choose the number for count it in '" << LISTS[2] << "' list: ";
					int el3;
					std::cin >> el3;
					sp(el3);
					break;
				case 4:
					std::cout << "Choose the number for count it in '" << LISTS[3] << "' list: ";
					int el4;
					std::cin >> el4;
					newlist(el4);
					break;
				default:
					if (!ch8)
						break;
				}
			} while (ch8);
			ch8 = 1;
			break;
		case 9:
			if (ch9)
				for (size_t i = 0; i < listSZ; ++i)
					std::cout << i + 1 << ". " << LISTS[i] << std::endl;
			std::cout << "0. Exit" << std::endl;
			do {
				std::cout << std::endl;
				ch9 = getnum("Choose the list ---> ");
				std::cout << std::endl;
				switch (ch9) {
				case 1:
					std::cout << "Enter the number to add it in '" << LISTS[0] << "' list: ";
					int el5;
					std::cin >> el5;
					sp1 = sp1 + el5;
					break;
				case 2:
					std::cout << "Enter the number to add it in '" << LISTS[1] << "' list: ";
					int el6;
					std::cin >> el6;
					sp2 = sp2 + el6 + el6 + sp1;
					break;
				case 3:
					std::cout << "Enter the number to add it in '" << LISTS[2] << "' list: ";
					int el7;
					std::cin >> el7;
					sp += el7;
					break;
				case 4:
					std::cout << "Enter the number to add it in '" << LISTS[3] << "' list: ";
					int el8;
					std::cin >> el8;
					newlist += el8;
					break;
				default:
					if (!ch9)
						break;
				}
			} while (ch9);
			ch9 = 1;
			break;
		case 10:
			std::cout << "***********************************************" << std::endl;
			if (menu)
				for (size_t i = 0; i < menuSZ; ++i)
					std::cout << MENU[i] << std::endl;
			std::cout << "***********************************************" << std::endl;
		default:
			if (!menu)
				std::cout << "Bye!" << std::endl;
			break;
		}
	} while (menu != 0);
	return 0;
}