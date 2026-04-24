#include<iostream>
#include<fstream>
#include<exception>

using namespace std;

class myexp : public exception {
public:
    void geterror() const {   
        cout << "Error code";
    }
};

int main() {
    int age = 8;

    try {
        if(age == 18) {
            throw myexp();
        }
        cout << age;
    }
    catch(const myexp& e) {
        e.geterror();  
    }

    return 0;
}
