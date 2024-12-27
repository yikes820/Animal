#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// 기본 클래스
class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
    virtual ~Animal() {} // Virtual destructor
};

// 개
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Woof! Woof!" << endl;
    }
};

// 고양이
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow! Meow!" << endl;
    }
};

// 소
class Cow : public Animal {
public:
    void makeSound() const override {
        cout << "Moo! Moo!" << endl;
    }
};

// 랜덤 동물 생성
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
    Animal* animals[10] = { nullptr }; // 동물 객체를 저장하는 포인터 배열
    int animalCount = 0; // 현재 저장된 동물의 수

public:
    // 동물을 동물원에 추가하는 함수
    void addAnimal(Animal* animal) {
        if (animalCount < 10) {
            animals[animalCount++] = animal;
        }
        else {
            cout << "Zoo is full! Cannot add more animals." << endl;
        }
    }

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    void performActions() {
        for (int i = 0; i < animalCount; ++i) {
            animals[i]->makeSound();
        }
    }

    // Zoo 소멸자
    ~Zoo() {
        for (int i = 0; i < animalCount; ++i) {
            delete animals[i];
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    Zoo zoo;

    // 동물원에 랜덤 동물 추가
    for (int i = 0; i < 10; ++i) {
        zoo.addAnimal(createRandomAnimal());
    }

    // 동물 행동
    zoo.performActions();

    return 0;
}
