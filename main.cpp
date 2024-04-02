//Work with a LinkedList of different numbers(Taking them one by one)
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

class LinkedList{
public: int data;
        LinkedList* next;
};

vector <int> CreateArray(){
    srand (static_cast <unsigned int>(time(0)));
    vector <int> array(rand() % 100);
    for (int i = 0; i <= array.size(); i++)
        array[i] = rand() % 1000;
    return array;
}

LinkedList* ConvertArray(vector<int>array){ //Function creates a LinkedList
    LinkedList* s1 = new LinkedList;
    LinkedList* node = s1; //Key(head or beginning)
    for (int i = 0; i < array.size() - 1; i++) {
        node->data = array[i]; //each element of array is going to "data" in class
        node->next = new LinkedList; //next step
       // node->next->next = nullptr;
        node = node->next;
    }
    node->data = array[array.size() - 1]; //Last element
    node->next = nullptr;
    return s1; //return the 1st number(Head of the LinkedList)
}

void printList(LinkedList* s1){
    LinkedList* node = s1;
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

void sendToFile(LinkedList* head){ //sending LinkedList to txt file (A)
    ofstream file("ListOfNumbers.txt");
    LinkedList* node = head;
    while (node != nullptr) {
        file << node->data << " ";
        node = node->next;
    }
}

LinkedList* readList(){ //reading a LinkedList of numbers from file (B)
    ifstream beru("ListOfNumbers.txt");
        LinkedList* s1 = new LinkedList;
        LinkedList* node = s1; //Key(head or beginning)
        beru >> node->data; //HERE WAS A PROBLEM, 1ST ELEMENT IN HEAD2 WAS 0(?)
        node->next = nullptr;
        int n;
        while (beru >> n) { //while file gives us a number the cyclus will be work
                node->next = new LinkedList;
                node = node->next;
                node->data = n;
                node->next = nullptr;
        }
        return s1;
}

int pocetEl(LinkedList* s1){ //How many times we meet a number in LinkedList (C)
    int n;
    cout << "\nNumber You want to search: ";
    cin >> n;
    LinkedList* node = s1;
    int count = 0;
    while (node != nullptr) {
        if (node->data == n)
            count++;
        node = node->next;
    }
    cout << "We met " << n << " " << count << " times";
    return count;
}

LinkedList* removeEl(LinkedList* s1){ //removing the last element (D)
    int n;
    cout << "\nNumber You want to remove: ";
    cin >> n;
    LinkedList* node = s1;
    int count = 0;
    while (node != nullptr) {
        if (node->data == n)
            count++;
        node = node->next;
    }
    cout << "We met " << n << " " << count << " times\n";
    int count2 = 0;
    node = s1;
    while (node != nullptr) {
        if (node->data == n)
            count2++;
        if (count == count2) {
            node->data = node->next->data;
            node->next = node->next->next;
            break;
        }
            node = node->next;
    }
    return s1;
}

int main() {
    vector <int> numbers = CreateArray();
    LinkedList* head = ConvertArray(numbers);
    printList(head);
    cout << "\n";
    sendToFile(head);
    LinkedList* head2 = readList();
    printList(head2);
    pocetEl(head);
    LinkedList* head3 = removeEl(head);
    printList(head3);
    return 0;
}
