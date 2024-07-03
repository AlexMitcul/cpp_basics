#include <iostream>
#include <format>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Использование std::ranges для фильтрации и преобразования
    auto even_numbers = numbers | std::views::filter([](int n) { return n % 2 == 0; })
                                | std::views::transform([](int n) { return n * n; });

    // Форматирование результата с помощью std::format
    std::string result = "Squared even numbers: ";
    for (int n : even_numbers) {
        result += std::format("{} ", n);
		printf("{%d}", n); // можно, но не совсем безопасно
    }

    std::cout << result << std::endl;

    return 0;
}

/*
	Фильтрация и преобразование:
		Фильтруем и преобразуем числа с использованием std::ranges.

	Форматирование результата:
		Создаем строку с отформатированными результатами с помощью std::format.
*/
