#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx; // Объявляем мьютекс
int sharedCounter = 0; // Общий счётчик

void increment(int id) {
    for (int i = 0; i < 100; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Блокируем мьютекс на время работы в критической секции
        ++sharedCounter; // Увеличиваем общий счётчик
        std::cout << "Thread " << id << " incremented counter to " << sharedCounter << std::endl;
    } // Мьютекс автоматически освобождается в конце области видимости lock_guard
}

int main() {
    const int numThreads = 5; // Количество потоков
    std::vector<std::thread> threads;

    // Создаём и запускаем потоки
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(increment, i); // Передаём id потока
    }

    // Ожидаем завершения всех потоков
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Final counter value: " << sharedCounter << std::endl;

    return 0;
}


