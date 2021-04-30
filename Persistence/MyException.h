//
// Created by Simona on 20.03.2021.
//

#pragma once
#include <string>
#include <utility>
#include <exception>
#include <vector>

class MyException : public std::exception {
    std::string M;
public:
    explicit MyException(const char *msg) : M(msg) {}
    const char *what() const noexcept override {
        return M.c_str();
    }
};


