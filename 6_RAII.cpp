#include <iostream>
#include <fstream>

class FileWrapper {
private:
    std::fstream file;

public:
    // Конструктор открывает файл
    FileWrapper(const std::string& filename, std::ios::openmode mode) {
        file.open(filename, mode);
        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file");
        }
        std::cout << "File opened: " << filename << std::endl;
    }

    // Метод для записи в файл
    void write(const std::string& data) {
        if (file.is_open()) {
            file << data;
        }
    }

    // Метод для чтения из файла
    std::string read() {
        std::string data;
        if (file.is_open()) {
            file >> data;
        }
        return data;
    }

    // Деструктор закрывает файл
    ~FileWrapper() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed" << std::endl;
        }
    }
};

int main() {
    try {
        // Создаем объект FileWrapper для работы с файлом example.txt
        FileWrapper file("example.txt", std::ios::out | std::ios::in | std::ios::trunc);

        // Записываем данные в файл
        file.write("Hello, RAII!");

        // Перемещаем указатель в начало файла для чтения
        file.write("\nAppending some text.");

        // Перемещаем указатель в начало файла для чтения
        file.write("\nMore text here.");

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Когда объект file выходит из области видимости, его деструктор автоматически закрывает файл

    return 0;
}


/**
 * пример использования идиомы RAII
 *  (Resource Acquisition Is Initialization) на C++.
 * В этом примере мы создадим класс FileWrapper, который будет обрабатывать открытие
 *  и закрытие файла, гарантируя, что файл всегда будет закрыт корректно,
 * когда объект FileWrapper выходит из области видимости.
 */
