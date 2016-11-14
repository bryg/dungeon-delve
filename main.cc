#include <iostream>
#include <cctype>
#include "tree.h"
#include <vector>
#include <string>
using namespace std;

int main() {
        Tree<char> bst;
        string str;
        // Creates dungeon.
        while (true) {
                char ch = cin.get();
                if(ch == EOF) break;
                if(isdigit(ch)) {
                        break;
                }
                if(isalpha(ch)) {
                        bst.insertNode(ch);
                } else cout << "This should not show 1" << endl;
        }

        // Creates vector of key.
        cin >> str;
        vector<char> ans(str.begin(), str.end());

        // Determines if solvable.
        bool solved = false;
        for (char i : ans) {
                solved = bst.solvable(i);
                if (!solved) {
                        cout << "NOT SOLVABLE" << endl;
                        return 0;
                }
        }

        // Show solution.
        for (char i : ans) {
                bst.solution(i);
        }
        cout << "Exit the dungeon!" << endl;
        return 0;
}
