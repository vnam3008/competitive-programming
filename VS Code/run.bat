@echo off
g++ -O2 -std=c++17 -o %~n1 %~n1.cpp && %~n1
:: Dùng khi không cài được extension C/C++ trên VSCode
:: Chạy trên CMD: run + tên file
:: Chạy trên PS: ./run + tên file