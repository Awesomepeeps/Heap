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
        if (index == 1) {
            return;
        }
        int parent = floor(index / 2);
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapup(parent);
        }
    }

    void heapdown(int index) {
        int leftchild = 2 * index;
        int rightchild = 2 * index + 1;

        if (leftchild > size) {
            return;
        }

        int largest = index;
        if (heap[leftchild] > heap[largest]) {
            largest = leftchild;
        }
        if (rightchild <= size && heap[rightchild] > heap[largest]) {
            largest = rightchild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapdown(largest);
        }
    }

    maxheap() : size(0) {}

    void additem(int value) {
        if (size >= MAXSIZE) {
            cout << "Heap is full" << endl;
            return;
        }
        size++;
        heap[size] = value;
        heapup(size);
    }

    void removeroot() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        heap[1] = heap[size];
        size--;
        heapdown(1);
    }

    void removeall() {
        while (size != 0) {
            removeroot();
        }
    }

    void printall(int current = 1, int depth = 0) {
        if (current > size) {
            return;
        }
        printall(2 * current + 1, depth + 1); 
        for (int i = 0; i < depth; i++) {
            cout << "\t";
        }
        cout << heap[current] << endl;
        printall(2 * current, depth + 1); 
    }

    int getsize() {
        return size;
    }

    int getheap(int index) {
        return heap[index];
    }

    void addFromFile(string filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Could not open file" << endl;
            return;
        }
        int value;
        while (file >> value && size < MAXSIZE) { 
            additem(value);
        }
        file.close(); 
    }
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