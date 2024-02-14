#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class maxheap {
private:
    int heap[101];
    int size;
    const int MAXSIZE = 101;

public:
    void heapup(int index) {
    }

    void heapdown(int index) {
    }

    maxheap() : size(0) {}

    void additem(int value) {
    }

    void removeroot() {
    }

    void removeall() {
    }

    void printall(int current = 1, int depth = 0) {
    }

    int getsize() {
    }

    int getheap(int index) {
    }

    void addFromFile(string filename) {}
};

int main() {
    maxheap heap = maxheap(); 
    string input;

    while (true) {
        cout << "Enter add, file, delete, clear, print, quit" << endl;
        cin >> input;
        cout << endl;

        if (input == "add") {
            int newitem;
            cout << "What do you want to add?" << endl;
            cin >> newitem;
            cout << endl;
            heap.additem(newitem);
        }
        else if (input == "file") {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            heap.addFromFile(filename); 
        }
        else if (input == "delete") {
            heap.removeroot();
        }
        else if (input == "clear") {
            heap.removeall();
        }
        else if (input == "print") {
            heap.printall();
            cout << endl;
        }
        else if (input == "quit") {
            heap.removeall();
            break;
        }
    }

    return 0;
}