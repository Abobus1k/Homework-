#include "mydatabase.h"


int menu()
{
	for (int i = 0; i < 40; ++i)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "1. Open database" << std::endl;
	std::cout << "2. Print database" << std::endl;
	std::cout << "3. PrintN database" << std::endl;
	std::cout << "4. Save database" << std::endl;
	std::cout << "5. export database" << std::endl;
	std::cout << "6. add Flat" << std::endl;
	std::cout << "7. Find ID." << std::endl;
	std::cout << "8. Del id" << std::endl;

	std::cout << "0. Exit" << std::endl;

	int tmp;
	std::cin >> tmp;
	return tmp;

}
int main()
{
	DataBase DB = { 0, nullptr };

	int action;
	do {
		action = menu();
		switch (action) {
		case 1: openDB(DB, "out.db"); break;
		case 2: printDB(DB); break;
		case 3: printNDB(DB);  break;
		case 4: saveDB(DB, "out.db"); break;
		case 5: exportDB(DB, "out.txt");  break;
		case 6: addFlat(DB); break;
		case 7: findID(DB); break;			
		case 8: delID(DB);  break;
		}
	} while (action != 0);

	if (DB.data)
		delete[] DB.data;
}