#include "Shop.h"

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Account Georgi("Georgi Sabev", "123456", 19, "geosabev@gmail.com", "Sofia, Bulgaria");

    Desktop desktop("Acer", "Nitro N50-600 Tower", 2950.00, 24, "Intel Core i7-9700",
        "NVIDIA GeForce RTX 2070 8GB", "Windows 10", 1256, 16);
    Laptop laptop("Dell", "G5 15", 3500.00, 24, "Intel Core i9-8950HK",
        "NVIDIA GeForce GTX 1060 6GB", "Windows 10", 1256, 16);
    Smartphone phone("Samsung", "Galaxy S7 Edge", 650, 12, "Android", 5.5);
    Mouse mouse("Trust", "GXT 103 Gav", 30, 12, "Wireless", 2000, 6);
    Keyboard keyboard("Trust", "GXT 830-RW Avonn", 30, 12, "Wired", true, false);

    Product* p1 = new Desktop(desktop);
    Product* p2 = new Laptop(laptop);
    Product* p3 = new Smartphone(phone);
    Product* p4 = new Mouse(mouse);
    Product* p5 = new Keyboard(keyboard);

    Shop shop("MyStore");
    
    shop.addProduct(p1);
    shop.addProduct(p2);
    shop.addProduct(p3);
    shop.addProduct(p4);
    shop.addProduct(p5);

    //Even after deleting the objects that were added it is still working because of clone() method
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    shop.registerAccount(Georgi);

    shop.productsList();

    cout << endl;

    //However, by adding products to shopping cart new memory is not allocated
    shop.addToCart(0, 0);
    shop.addToCart(0, 1);
    shop.printCart(0);
    shop.removeFromCart(0, 0);

    cout << endl;

    shop.addToCart(0, 1);

    cout << endl;

    shop.buyCart(0);

    cout << endl;

    shop.deleteProduct(4);

    //And at the end the copies made for products catalogue are also deleted by the destructors and no memory leaks ocurr
} 