#include <iostream>

class Hamburger {
public:
    void Print() const {
        std::cout << "Hamburger works!" << std::endl;
    }
};

int main() {
    std::cout << "=== Тест Builder паттерна ===" << std::endl;
    
    Hamburger burger;
    burger.Print();
    
    std::cout << "Тест пройден!" << std::endl;
    return 0;
}
