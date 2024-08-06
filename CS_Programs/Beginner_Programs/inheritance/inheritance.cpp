#include <iostream>

using namespace std;

class Chef{
    public:
        void makeChicken(){
            cout << "The chef makes chicken." << endl;
        }
        void makeSalad(){
            cout << "The chef makes a salad." << endl;
        }
        void makeSpecialDish(){
            cout << "The chef makes bbq ribs." << endl;
        }
};

// : public Chef - inherits all public elements from Chef object
class ItalianChef : public Chef{
    public:
        void makePasta(){
            cout << "The chef makes pasta." << endl;
        }
        // Overriding the function
        void makeSpecialDish(){
            cout << "The chef makes chicken parmesan." << endl;
        }

};

int main(){
    
    Chef chef;
    chef.makeChicken();

    // ItalianChef is empty
    ItalianChef italianChef;
    italianChef.makeChicken();
    italianChef.makePasta();
    // chef.makePasta()

    chef.makeSpecialDish();
    italianChef.makeSpecialDish();

    return 0;
}