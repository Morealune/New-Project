#include "worker.h"
#include <iostream>

WORKER::WORKER()
    : surnameInitials("Неизвестно"), position("Неизвестно"), salary(0.0), yearOfEmployment(0) {
}

WORKER::WORKER(const std::string& s, const std::string& p, double sal, int y)
    : surnameInitials(s), position(p), salary(sal), yearOfEmployment(y) {
}

WORKER::WORKER(const WORKER& other)
    : surnameInitials(other.surnameInitials), position(other.position),
    salary(other.salary), yearOfEmployment(other.yearOfEmployment) {
}

WORKER::~WORKER() {}

void WORKER::setSurnameInitials(const std::string& s) { surnameInitials = s; }
void WORKER::setPosition(const std::string& p) { position = p; }
void WORKER::setSalary(double sal) { salary = sal; }
void WORKER::setYearOfEmployment(int y) { yearOfEmployment = y; }

std::string WORKER::getSurnameInitials() const { return surnameInitials; }
std::string WORKER::getPosition() const { return position; }
double WORKER::getSalary() const { return salary; }
int WORKER::getYearOfEmployment() const { return yearOfEmployment; }

int WORKER::getExperienceYears() const {
    const int currentYear = 2024;
    if (yearOfEmployment > currentYear || yearOfEmployment <= 0) return 0;
    return currentYear - yearOfEmployment;
}

void WORKER::display() const {
    std::cout << "Фамилия и инициалы: " << surnameInitials << "\n"
        << "Должность: " << position << "\n"
        << "Зарплата: " << salary << " руб.\n"
        << "Год поступления: " << yearOfEmployment
        << " (стаж: " << getExperienceYears() << " лет)\n";
}
