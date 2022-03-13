#pragma once
#include "Room.h"

struct DataBase
{
    int count;
    Flat* data;
};

int addFlat(DataBase& DB);
void printDB(const DataBase& DB);
void exportDB(const DataBase& DB, const char* filename);
void saveDB(const DataBase& DB, const char* filename);
void openDB(DataBase& DB, const char* filename);
void delID(DataBase& DB);
void printNDB(DataBase& DB);
void sortDB(DataBase& DB);
void findID(const DataBase& DB);
int find(const DataBase& DB);


template <typename T>
void mySort(T* M, int n, bool (*comparator)(const T&, const T&))
{
    for (int i = 0; i < n - 1; ++i)
    {
        int tmp = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (comparator(M[j], M[tmp])) tmp = j;
        }
        if (i < tmp) std::swap(M[tmp], M[i]);

    }
}