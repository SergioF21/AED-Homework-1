#include <iostream>
#include "forward.h"
#include "double.h"

using namespace std;

void test(List<int>* list) {
    cout << "* Testing " << list->name() << "  *" << endl;
    int n=0;
    // Test is_empty
    n++;
    if (list->is_empty() == true) {
        cout << "Successful Test " << n << endl;
    } else {
        cout << "Failed Test " << n << endl;
    }
    // Test size
    n++;
    if (list->size() == 0) {
        cout << "Successful Test " << n << endl;
    } else {
        cout << "Failed Test " << n << endl;
    }

    // Test push_front/pop_front
    n++;
    list->push_front(5);
    list->push_front(10);
    if (list->pop_front() == 10) {
        cout << "Successful Test " << n << endl;
    } else {
        cout << "Failed Test " << n << endl;
    }

    // Test push_back/pop_back
    n++;
    list->push_back(20);
    list->push_back(15);
    if (list->pop_back() == 15) {
        cout << "Successful Test " << n << endl;
    } else {
        cout << "Failed Test" << n << endl;
    }

    // Test insert and operator[]
    n++;
    list->push_back(30);
    list->push_back(8);
    list->insert(12, 2);
    if ((*list)[2] == 12) {
        cout << "Successful Test " << n << endl;
    } else {
        cout << "Failed Test " << n << endl;
    }

    // Test is_sorted
    n++;
    list->push_back(10);
    list->push_front(3);
    if (list->is_sorted() == false) {
        cout << "Successful Test " << n <<endl;
    } else {
        cout << "Failed Test " << n << endl;
    }

    // Test sort
    n++;
    list->sort();
    if (list->is_sorted() == true) {
        cout << "Successful Test " << n << endl;
    } else {
        cout << "Failed Test " << n << endl;
    }

    // Clear
    n++;
    list->clear();
    cout << "Successful Test " << n << endl;

    delete list;
}

int main()
{
    List<int> *forward = new ForwardList<int>();
    test(forward);

    List<int> *doble = new DoubleList<int>();
    test(doble);

    return 0;
}