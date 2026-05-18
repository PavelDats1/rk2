#include <iostream>
#include <memory>
#include "../src/hamburger.cpp"

int main() {
    auto builder = std::make_unique<BeefHamburgerBuilder>();
    HamburgerHouse house(std::move(builder));
    Hamburger burger = house.MakeCheeseBurger();

    std::cout << "Тест: создание чизбургера" << std::endl;
    std::cout << "Результат: " << (burger.GetIngredientCount() > 0 ? "OK" : "FAIL") << std::endl;

    return 0;
}
