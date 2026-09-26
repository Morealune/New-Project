#pragma once
#include <string>

class WORKER {
private:
    std::string surnameInitials; // Фамилия и инициалы
    std::string position;        // Должность
    double salary;               // Зарплата
    int yearOfEmployment;         // Год поступления на работу

public:
    // Конструкторы
    WORKER();
    WORKER(const std::string& s, const std::string& p, double sal, int y);
    WORKER(const WORKER& other);

    // Деструктор
    ~WORKER();

    // Сеттеры
    void setSurnameInitials(const std::string& s);
    void setPosition(const std::string& p);
    void setSalary(double sal);
    void setYearOfEmployment(int y);

    // Геттеры
    std::string getSurnameInitials() const;
    std::string getPosition() const;
    double getSalary() const;
    int getYearOfEmployment() const;

    // Вспомогательный метод: расчёт стажа на текущий год (2024)
    int getExperienceYears() const;

    // Метод отображения информации о работнике
    void display() const;
};
