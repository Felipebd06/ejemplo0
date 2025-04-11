#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
private:
    vector<bool> data; // Estructura interna para almacenar los datos

public:
    MyHashSet() {
        data.resize(1000001, false); // Soporta keys desde 0 hasta 1,000,000
    }
    
    void add(int key) {
        data[key] = true;
    }
    
    void remove(int key) {
        data[key] = false;
    }
    
    bool contains(int key) {
        return data[key];
    }
};

int main() {
    MyHashSet* myHashSet = new MyHashSet();
    
    myHashSet->add(1);
    myHashSet->add(2);

    cout << myHashSet->contains(1) << endl; // Imprime 1 (true)
    cout << myHashSet->contains(3) << endl; // Imprime 0 (false)

    myHashSet->add(2);
    cout << myHashSet->contains(2) << endl; // Imprime 1 (true)

    myHashSet->remove(2);
    cout << myHashSet->contains(2) << endl; // Imprime 0 (false)

    delete myHashSet; // Liberar la memoria reservada

    return 0;
}
