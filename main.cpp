#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>

struct node {
    node* next;
    int val;
};

node *merge(node *heads[], int n) {
    node *cursors[n];
    for (int i = 0; i < n; ++i) cursors[i] = heads[i];

    node *head = new node{nullptr, -1};
    node *curr = head;

    int done = 0;
    while (done < n) {
        int minIndex = -1;
        int minValue = INT32_MAX;
        done = 0;
        for (int i = 0; i < n; ++i) {
            if (cursors[i] == nullptr) {
                ++done;
                continue;
            }

            if (cursors[i]->val <= minValue) {
                minValue = cursors[i]->val;
                minIndex = i;
            }
        }

        if (minIndex == -1) break;
        if (done == n) break;

        curr->next = new node{nullptr, minValue};
        curr = curr->next;
        cursors[minIndex] = cursors[minIndex]->next;
    }

    auto result = head->next;
    delete head;

    return result;
}

int main() {
    int n;
    std::cout << "Nr de liste" << std::endl;
    std::cin >> n;

    node *heads[n];
    for (int i = 0, listLength; i < n; ++i) {
        std::cout << "Nr de elemente pentru lista nr " + std::to_string(i) << std::endl;

        heads[i] = nullptr;
        node *curr = heads[i];
        std::cin >> listLength;
        for (int j = 0, x; j < listLength; ++j) {
            std::cin >> x;
            node *next = new node{nullptr, x};
            if (heads[i] == nullptr) heads[i] = next;
            else curr->next = next;
            curr = next;
        }
        for (auto curr = heads[i]; curr != nullptr; curr = curr->next) {
            std::cout << curr->val << " ";
        }
        std::cout << '\n';
    }

    node *result = merge(heads, n);
    for (auto curr = result; curr != nullptr; curr = curr->next) {
        std::cout << curr->val << " ";
    }
    std::cout << '\n';

    return 0;
}
