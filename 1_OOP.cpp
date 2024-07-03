#include <iostream>
#include <string>

// Базовый класс "Животное"
class Animal {
protected:
    std::string name;
    int age;

public:
    // Конструктор базового класса
    Animal(std::string n, int a) : name(n), age(a) {}

    // Виртуальный метод для издания звука
    virtual void makeSound() {
        std::cout << "Some generic animal sound!" << std::endl;
    }

    // Метод для получения имени животного
    std::string getName() {
        return name;
    }

    // Метод для получения возраста животного
    int getAge() {
        return age;
    }
};

// Производный класс "Собака"
class Dog : public Animal {
public:
    // Конструктор производного класса
    Dog(std::string n, int a) : Animal(n, a) {}

    // Переопределение метода для издания звука
    void makeSound() override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

// Производный класс "Кошка"
class Cat : public Animal {
public:
    // Конструктор производного класса
    Cat(std::string n, int a) : Animal(n, a) {}

    // Переопределение метода для издания звука
    void makeSound() override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

int main() {
    // Создание объектов классов
    Dog dog("Buddy", 3);
    Cat cat("Whiskers", 2);

    // Вызов методов объектов
    std::cout << "The dog named " << dog.getName() << " says: ";
    dog.makeSound();

    std::cout << "The cat named " << cat.getName() << " says: ";
    cat.makeSound();

    // Использование полиморфизма
    Animal* animals[2];
    animals[0] = &dog;
    animals[1] = &cat;

    std::cout << "\nUsing polymorphism:" << std::endl;
    for(int i = 0; i < 2; i++) {
        std::cout << animals[i]->getName() << " says: ";
        animals[i]->makeSound();
    }

    return 0;
}

/**

 	Инкапсуляция:

	- Класс Animal содержит защищённые данные-члены name и age.
	- Методы getName() и getAge() предоставляют доступ к этим данным, обеспечивая инкапсуляцию.

	Наследование:

	- Классы Dog и Cat наследуют базовый класс Animal с помощью ключевого слова public.
	- Они получают все свойства и методы базового класса и могут добавлять свои собственные или переопределять существующие.

	Полиморфизм:

	- Метод makeSound() объявлен виртуальным в базовом классе Animal и переопределяется в производных классах Dog и Cat.
	- В функции main() показано использование полиморфизма:
		массив указателей на объекты Animal используется для вызова методов makeSound() для объектов Dog и Cat.
 */
