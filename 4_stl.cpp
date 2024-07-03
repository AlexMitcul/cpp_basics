#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Для std::accumulate

int main() {
    // Создание и инициализация вектора целых чисел
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Вывод исходного вектора
    std::cout << "Initial vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Использование алгоритма std::sort для сортировки вектора в порядке убывания
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    std::cout << "Sorted vector (descending): ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Использование алгоритма std::reverse для реверса вектора
    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Reversed vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Использование алгоритма std::accumulate для вычисления суммы элементов вектора
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of elements: " << sum << std::endl;

    // Использование алгоритма std::find для поиска элемента в векторе
    int target = 3;
    auto it = std::find(numbers.begin(), numbers.end(), target);
    if (it != numbers.end()) {
        std::cout << "Element " << target << " found at position: " << std::distance(numbers.begin(), it) << std::endl;
    } else {
        std::cout << "Element " << target << " not found" << std::endl;
    }

    // Использование алгоритма std::for_each для выполнения функции для каждого элемента вектора
    std::cout << "Elements incremented by 1: ";
    std::for_each(numbers.begin(), numbers.end(), [](int& num) { num += 1; });
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
