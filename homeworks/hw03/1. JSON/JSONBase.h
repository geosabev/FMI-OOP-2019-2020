//62380
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class JSONBase {
public:
    virtual ~JSONBase() = default;

    virtual JSONBase* clone() const = 0;
    virtual void print() const = 0;
};