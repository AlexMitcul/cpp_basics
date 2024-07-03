#include <iostream>

// Шаблон класса Pair
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    // Конструктор
    Pair(T1 f, T2 s) : first(f), second(s) {}

    // Методы для получения значений
    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Pair<T1, T2>& p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
};


// Пример использования шаблонного класса
int main() {
    Pair<int, std::string> p1(1, "one");
    Pair<double, char> p2(3.14, 'a');
	Pair<Pair<int, double>, Complex> p3(new Pair(3, 3.14), new Complex(1, 2));

    std::cout << "Pair 1: " << p1 << std::endl;
    std::cout << "Pair 2: " << p2 << std::endl;

    return 0;
}
