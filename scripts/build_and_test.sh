#!/bin/bash
set -e

echo " Сборка проекта "
mkdir -p build
cd build
cmake ..
make

echo " Запуск тестов "
./test_hamburger

echo " Создание deb-пакета"
cpack

echo "Готово"
ls -lh *.deb
