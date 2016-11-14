#include <iostream>
using namespace std;

template <class T>
class Node {
        public:
                Node *right;
                Node *left;
                T data;
};

template <class T>
class Tree {
        private:
                Node<T> *root = nullptr;
                void insert(Node<T> *&current, Node<T> *&temp) {
                        if (current == nullptr)
                                current = temp;
                        else if (current->data > temp->data)
                                insert(current->left, temp);
                        else
                                insert(current->right, temp);
                }
        public:
                void insertNode(T newData) {
                        Node<T> *temp = new Node<T>;
                        temp->data = newData;
                        temp->right = temp->left = nullptr;
                        insert(root, temp);
                }
                bool solvable(T newData) {
                        Node<T> *current = root;
                        while(current) {
                                if (current == nullptr) return false;
                                if (current->data == newData) return true;
                                if (current->data > newData) current = current->left;
                                else current = current->right;
                        }
                }
                void solution(T newData) {
                        Node<T> *current = root;
                        while(current) {
                                if (current->data == newData) {
                                        cout << "Found " << newData << ". Retrace your steps to the entrance." << e$
                                        break;
                                } else if (current->data > newData) {
                                        cout << "Take the left door at the " << current->data << "." << endl;
                                        current = current->left;
                                } else {
                                        cout << "Take the right door at the " << current->data << "." << endl;
                                        current = current->right;
                                }
                        }
                }
};

