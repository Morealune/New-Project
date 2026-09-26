#include <iostream>
#include <vector>
#include "worker.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<WORKER> workers;
    int n;

    std::cout << "Введите количество сотрудников для ввода: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string surname, position;
        double salary;
        int year;

        std::cout << "\n--- Сотрудник " << (i + 1) << " ---\n";
        std::cout << "Фамилия и инициалы: ";
        std::cin.ignore(); // очистка буфера после предыдущего ввода
        std::getline(std::cin, surname);

        std::cout << "Должность: ";
        std::getline(std::cin, position);

        std::cout << "Зарплата (руб.): ";
        std::cin >> salary;

        std::cout << "Год поступления на работу: ";
        std::cin >> year;

        workers.emplace_back(surname, position, salary, year);
    }

    // Вывод всех введённых сотрудников
    std::cout << "\n--- Список всех сотрудников ООО ЦТО «Ин‑Кас» ---\n";
    for (const auto& w : workers) {
        w.display();
        std::cout << "--------------------------\n";
    }

    // Поиск по стажу
    int threshold;
    std::cout << "\nВведите минимальный стаж (лет) для поиска: ";
    std::cin >> threshold;

    bool found = false;
    std::cout << "\nСотрудники со стажем более " << threshold << " лет:\n";
    for (const auto& w : workers) {
        if (w.getExperienceYears() > threshold) {
            std::cout << w.getSurnameInitials() << " (стаж: "
                << w.getExperienceYears() << " лет)\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Сотрудников с таким стажем не найдено.\n";
    }

    return 0;
}
