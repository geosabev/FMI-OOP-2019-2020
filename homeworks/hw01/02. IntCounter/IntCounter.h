//62380
#pragma once
#include <iostream>
using namespace std;

class IntCounter {
public: 
    IntCounter();
    IntCounter(int* _value);
    IntCounter(IntCounter& _other);
    IntCounter& operator=(const IntCounter& _other);
    ~IntCounter();

    void setValue(int* _value);
    int* getValue() const;

    void setAmount(unsigned int* _amount);
    unsigned int* getAmount() const;
    
    unsigned int getCount() const;

private:
    int* value;
    unsigned int* amount;
};