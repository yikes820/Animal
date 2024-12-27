#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// �⺻ Ŭ����
class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
    virtual ~Animal() {} // Virtual destructor
};

// ��
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Woof! Woof!" << endl;
    }
};

// �����
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow! Meow!" << endl;
    }
};

// ��
class Cow : public Animal {
public:
    void makeSound() const override {
        cout << "Moo! Moo!" << endl;
    }
};

// ���� ���� ����
Animal* createRandomAnimal() {
    int randomValue = rand() % 3; // Generate a random number between 0 and 2
    switch (randomValue) {
    case 0:
        return new Dog();
    case 1:
        return new Cat();
    case 2:
        return new Cow();
    default:
        return nullptr; // This should never happen
    }
}

class Zoo {
private:
    Animal* animals[10] = { nullptr }; // ���� ��ü�� �����ϴ� ������ �迭
    int animalCount = 0; // ���� ����� ������ ��

public:
    // ������ �������� �߰��ϴ� �Լ�
    void addAnimal(Animal* animal) {
        if (animalCount < 10) {
            animals[animalCount++] = animal;
        }
        else {
            cout << "Zoo is full! Cannot add more animals." << endl;
        }
    }

    // �������� �ִ� ��� ������ �ൿ�� �����ϴ� �Լ�
    void performActions() {
        for (int i = 0; i < animalCount; ++i) {
            animals[i]->makeSound();
        }
    }

    // Zoo �Ҹ���
    ~Zoo() {
        for (int i = 0; i < animalCount; ++i) {
            delete animals[i];
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    Zoo zoo;

    // �������� ���� ���� �߰�
    for (int i = 0; i < 10; ++i) {
        zoo.addAnimal(createRandomAnimal());
    }

    // ���� �ൿ
    zoo.performActions();

    return 0;
}
