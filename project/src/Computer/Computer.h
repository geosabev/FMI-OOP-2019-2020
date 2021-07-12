#pragma once
#include "Product.h"

class Computer : public Product {
public:
    Computer() = delete;
    Computer(string b, string m, double p, unsigned int w, string cpu,
        string gpu, string os, unsigned int storage, unsigned int RAM);

    virtual Product* clone() const = 0;

    virtual void specifications() const override;

    string getProcessor() const;
    string getGraphicsCard() const;
    string getOS() const;
    unsigned int getStorage() const;
    unsigned int getRAM() const;

protected:
    string processor, graphicsCard, OS;
    unsigned int storage, RAM;
};