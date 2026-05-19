#include <iostream>
#include <cassert>
#include <sstream>
#include <memory>

// Подключаем классы (теперь нет main() в hamburger.cpp)
#include "../src/hamburger.cpp"

int main() {
    std::cout << "=== Testing Builder Pattern ===" << std::endl;
    
    auto builder = std::make_unique<BeefHamburgerBuilder>();
    HamburgerHouse house(std::move(builder));
    Hamburger burger = house.MakeCheeseBurger();
    
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    burger.Print();
    std::cout.rdbuf(old);
    
    std::string output = buffer.str();
    
    bool hasBread = output.find("Bread") != std::string::npos;
    bool hasPatty = output.find("BeefPatty") != std::string::npos;
    bool hasCheese = output.find("Cheese") != std::string::npos;
    bool hasLettuce = output.find("Lettuce") != std::string::npos;
    bool hasTomato = output.find("Tomato") != std::string::npos;
    bool hasSauce = output.find("GarlicSauce") != std::string::npos;
    
    std::cout << "Checking CheeseBurger ingredients:" << std::endl;
    std::cout << "  - Bread: " << (hasBread ? "✓" : "✗") << std::endl;
    std::cout << "  - BeefPatty: " << (hasPatty ? "✓" : "✗") << std::endl;
    std::cout << "  - Cheese: " << (hasCheese ? "✓" : "✗") << std::endl;
    std::cout << "  - Lettuce: " << (hasLettuce ? "✓" : "✗") << std::endl;
    std::cout << "  - Tomato: " << (hasTomato ? "✓" : "✗") << std::endl;
    std::cout << "  - GarlicSauce: " << (hasSauce ? "✓" : "✗") << std::endl;
    
    assert(hasBread);
    assert(hasPatty);
    assert(hasCheese);
    assert(hasLettuce);
    assert(hasTomato);
    assert(hasSauce);
    
    std::cout << "\n Test PASSED" << std::endl;
    return 0;
}
