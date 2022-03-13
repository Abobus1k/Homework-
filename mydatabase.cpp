#include "mydatabase.h"
#include<fstream>


int addFlat(DataBase& DB)
{
	Flat* tmp = new Flat[DB.count + 1];
	for (int i = 0; i < DB.count; ++i)
	{
		tmp[i] = DB.data[i];
	}
	if (DB.data)
		delete[] DB.data;
	DB.data = tmp;

	std::cin >> DB.data[DB.count];

	DB.data[DB.count].id = DB.count;

	++DB.count;

	return DB.count;
}
void printDB(const DataBase& DB) {
	mySort(DB.data, DB.count, sortByPrice);

	for (int i = 0; i < DB.count; ++i)
		std::cout << DB.data[i] << std::endl;
}

void exportDB(const DataBase& DB, const char* filename)
{
	std::ofstream outFile(filename, std::ios_base::binary);
	if (!outFile.is_open())
	{
		std::cout << "Can not open";
		return;
	}

	
	for (int i = 0; i < DB.count; ++i)
	{
		outFile << DB.data[i];
		outFile << std::endl;
	}

	outFile.close();

}
void saveDB(const DataBase& DB, const char* filename)
{
	std::ofstream outFile(filename, std::ios_base::binary);
	if (!outFile.is_open())
	{
		std::cout << "Can not open";
		return;
	}
	outFile.write((const char*)&DB.count, sizeof(int));
	outFile.write((const char*)DB.data, DB.count * sizeof(Flat));

	outFile.close();
}
void openDB(DataBase& DB, const char* filename)
{
	std::ifstream in(filename, std::ios_base::binary);
	if (!in.is_open())
	{
		std::cout << "Can not open";
		return;
	}

	int count;
	in.read((char*)&count, sizeof(int));

	if (DB.data) delete[] DB.data;
	DB.data = new Flat[count];
	DB.count = count;
	in.read((char*)DB.data, sizeof(Flat) * DB.count);
	in.close();

}
void delID(DataBase& DB)
{
	int tmp;
	std::cout << "ID to delete: ";
	std::cin >> tmp;
	if (tmp < 0) return;

	for (int i = tmp + 1; i < DB.count; ++i)
		DB.data[i - 1] = DB.data[i];
	--DB.count;
}
void printNDB(DataBase& db)
{
	std::cout << "Count rooms: ";
	int countRoom, count = 0;
	std::cin >> countRoom;


	for (int i = 0; i < db.count; ++i)
	{
		if (db.data[i].countRooms == countRoom)
		{
			++count;
		}
	}
	Flat* tmp = new Flat[count];
	int j = 0;
	for (int i = 0; i < db.count; ++i)
	{
		if (db.data[i].countRooms == countRoom)
		{
			tmp[j] = db.data[i];
			++j;
		}
	}
	DataBase sortDB = { count,tmp };

	mySort(sortDB.data, sortDB.count, sortByPrice);
	printDB(sortDB);
	delete[] tmp;
}

void sortDB(DataBase& DB)
{

	mySort(DB.data, DB.count, sortByPrice);
}
int find(const DataBase& DB, int id)
{
	for (int i = 0; i < DB.count; ++i)
		if (DB.data[i].id == id) return i;
	return -1;
}
void findID(const DataBase& DB)
{
	int tmpId;
	std::cout << "ID: ";
	std::cin >> tmpId;

	int currentRoom = find(DB, tmpId);
	for (int i = 0; i < DB.count; ++i)
	{
		if ((DB.data[i].floor == DB.data[currentRoom].floor) && (DB.data[i].countRooms == DB.data[currentRoom].countRooms) &&
			(DB.data[i].area <= 1.2 * DB.data[currentRoom].area) && (DB.data[i].area >= 0.8 * DB.data[currentRoom].area))
			std::cout << DB.data[i] << std::endl;
	}
}