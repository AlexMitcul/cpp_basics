#include <iostream>
#include <cstring> // Для функции std::memcpy

int main() {
    // Размер массива
    const int size = 100'000'000;

    // Динамическое выделение памяти для массива
    int* array = new int[size];

    // Инициализация массива с использованием указателя
    for (int i = 0; i < size; ++i) {
        *(array + i) = i * 2;
    }

    // Вывод элементов массива
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

    // Пример использования std::memcpy для копирования массива
    int* arrayCopy = new int[size];
    std::memcpy(arrayCopy, array, size * sizeof(int));

    // Вывод элементов скопированного массива
    std::cout << "Copied array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << *(arrayCopy + i) << " ";
    }
    std::cout << std::endl;

    // Освобождение памяти
    delete[] array;
    delete[] arrayCopy;

    return 0;
}
