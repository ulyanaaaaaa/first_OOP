#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



class Date {
public:
    ~Date(){}
    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    Date(){
        day = 1;
        month = 1;
        year = 2010;
    }
    int setDay();
    int setMonth();
    int setYear();
    void setDate();
    void printDate();
    int writeInFile();
private:
    int day;
    int month;
    int year;
};

void Date::setDate() {
    this->day = (day >= 0 && day < 32) ? day : 1;
    this->month = (month >= 0 && month < 13) ? month : 1;
    this->year = (year >= 0 && year < 2023) ? year : 2000;
}

int Date::setDay() {
    cout << "Enter day:" << endl;
    cin >> day;
    fstream fout("d://БГУИР//ООПиП//file.txt", ios::out);
    return day;
}
 
int Date::setMonth() {
    cout << "Enter month:" << endl;
    cin >> month;
    fstream fout("d://БГУИР//ООПиП//file.txt", ios::out);
    return month;
}

int Date::setYear() {
    cout << "Enter year:" << endl;
    cin >> year;
    fstream fout("d://БГУИР//ООПиП//file.txt", ios::out);
    return year;
}

void Date::printDate() {
    cout << day << "." << month << "." << year << endl;
}

enum Position
{
    laborant,
    secretary,
    manager,
    director
};

void getPosition() {
    cout << "Choose position: 1 - laborant, 2 - secretary 3 - manager, 4 - director" << endl;
    int k;
    cin >> k;
    switch (k) {
    case 1: cout << "laborant" << endl; break;
    case 2: cout << "Secretary" << endl; break;
    case 3: cout << "Manager" << endl; break;
    case 4: cout << "Director" << endl; break;
    }
}


int Date::writeInFile() {
    ifstream file;
    file.open("d://БГУИР//ООПиП//file.txt");
    if (!file)
    {
        cout << "Файл не открыт\n\n";
        return -1;
    }
    else
    {
        cout << "Все ОК! Файл открыт!\n\n";
        return 1;
    }
}


class Employee
{
private:
    int number;
    float salary;
    class Date;
    enum Position;
    Position pos;
public:
    ~Employee() {
        cout << "Destructor" << endl;
    }

    Employee(Employee& obj);  //конструктор копирования

    Employee(int number = {}, float salary = {}, Position pos = {}){
        this->number = number;
        this->salary = salary;
        this->pos = pos;
    }

   Employee(Position pos){
        number = 1;
        salary = 100;
        this->pos = pos;
    }

    int getSalary();
    int getNumber();
    void printEmployee();
};

int Employee::getSalary()
{
    cout << "Enter salary:";
    cin >> salary;
    fstream fout("d://1//file.txt", ios::out);
    return salary;
}

int Employee::getNumber()
{
    cout << "Enter number of employee";
    cin >> number;
    fstream fout("d://1//file.txt", ios::out);
    return number;
} 

void Employee::printEmployee() {
    cout << "Number:" << number << endl << "Salary:" << salary << endl;
}

Employee::Employee(Employee &obj) {

    this->number = obj.number;
    
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Date date1;
    date1.setDay();
    date1.setMonth();
    date1.setYear();
    date1.setDate();
    date1.printDate();
    date1.writeInFile();
    Employee player;
    player.getSalary();
    player.getNumber();   
    player.printEmployee();
}

