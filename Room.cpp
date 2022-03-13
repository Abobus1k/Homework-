#include<iostream>

#include "Room.h"


std::ostream& operator<< (std::ostream& out, const Flat& room) {
 
    out << "Flat: " << room.id<<", Flat price: "<<room.price << ", Nummber of rooms: " << room.countRooms << ", Floor: " << room.floor << ", Flat area: " << room.area << ", Flat address: " << room.address << ", Date"<< room.day << '.' << room.month << '.' << room.year << '\n';
    return out;
}

std::istream& operator>> (std::istream& in, Flat& room) {
    std::cout << "Price: ";
    in >> room.price;
    in.ignore();

    std::cout << "Number of rooms: ";
    in >> room.countRooms;
    in.ignore();

    std::cout << "Floor: ";
    in >> room.floor;
    in.ignore();

    std::cout << "Flat area: ";
    in >> room.area;
    in.ignore();

    std::cout << "Adress: ";
    in.getline(room.address, 64);

    do {
        std::cout << "Day: ";
        in >> room.day;
        in.ignore();
    

        std::cout << "Month: ";
        in >> room.month;
        in.ignore();

        std::cout << "Year: ";
        in >> room.year;
        in.ignore();

        
        if (room.day > 31 || room.day < 1 ||
            room.month > 12 || room.month < 1 ||
            (room.month % 2 == 0 && room.month < 8 && room.day > 30) ||
            (room.month % 2 != 0 && room.month > 8 && room.day > 30) ||
            (room.year % 4 == 0 && room.month == 2 && room.day > 29) ||
            (room.year % 4 != 0 && room.month == 2 && room.day > 28))
        {
            if (room.month > 12 || room.month < 1)
            {
                std::cout << "Month value if invalid: " << room.month << std::endl;
            }
            else {
                std::cout << "Day value is invalid: " << room.day << std::endl;
            }

            std::cout << "Wrong date format : " << room.day << '.'
                << room.month << '.' << room.year << std::endl;

            std::cout << "Try again silly boy " << std::endl;
        }

    } while (room.day > 31 || room.day < 1 ||
        room.month > 12 || room.month < 1 ||
        (room.month % 2 == 0 && room.month < 8 && room.day > 30) ||
        (room.month % 2 != 0 && room.month > 8 && room.day > 30) ||
        (room.year % 4 == 0 && room.month == 2 && room.day > 29) ||
        (room.year % 4 != 0 && room.month == 2 && room.day > 28));

    return in;
}

bool sortByPrice(const Flat& first, const Flat& second)
{
    return first.price > second.price;
}