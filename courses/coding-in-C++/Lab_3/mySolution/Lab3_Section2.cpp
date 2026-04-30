#include <string>
#include <iostream>

class User
{
protected:
    std::string name;
    int id;

public:
    User(std::string name, int id) : name(name), id(id)
    {
    };
    void printInfo();
};

void User::printInfo()
{
    std::cout << "Name: " << this->name << '\n';
    std::cout << "ID: " << this->id << '\n';
}

class Student : public User
{
private:
    int matNr;

public:
    Student(std::string name, int id, int matNr) : User(name, id), matNr(matNr)
    {
    };
    void printRole()
    {
        std::cout << "Rolle: " << "Student" << '\n';
        std::cout << "Matrikelnr: " << this->matNr << '\n';
    }
};

class Instructor : public User
{
private:
    const double DEFAULT_SALARY = 3000;
    double salary;

public:
    Instructor(std::string name, int id, double salary) : User(name, id), salary(DEFAULT_SALARY)
    {
        if (salary >= 0)
        {
            this->salary = salary;
        }
    };
    void printRole()
    {
        std::cout << "Rolle: " << "Lehrer" << '\n';
        std::cout << "Gehalt: " << this->salary << '\n';
    }
};

//////////////////////////////////////////////////////////MAIN//////////////////////////////////////////////////////////
int main()
{
    Student student1("Bennet Gewicht", 69, 187187);
    Instructor instructor1("Julien Kwouw", 31, 4500);

    student1.printInfo();
    student1.printRole() ;
    
    std::cout << "----------------" << '\n';

    instructor1.printInfo();
    instructor1.printRole();

    return 0;
}
//////////////////////////////////////////////////////////MAIN//////////////////////////////////////////////////////////
