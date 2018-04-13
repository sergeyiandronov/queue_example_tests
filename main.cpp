// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
template <typename T>
class queue_t {
	struct node_t {
		node_t *next;
		T value;
	};
	node_t *head;
	node_t *tail;
public:
	queue_t() {
		head = nullptr;
		tail = nullptr;
	}
	void push(T value) {
		if (head == nullptr) {
			head = new node_t;
			head->value = value;
			head->next = nullptr;
			tail = head;

		
			return;
		}
		tail->next = new node_t;
		tail->next->value = value;
		
		tail->next->next = nullptr;
		tail = tail->next;
		
		return;
	}
	T pop()  {
		if (head == nullptr) {
			throw "queue is empty";
		}
		T result=head->value;
		node_t *newhead=head->next;
		if (head == tail) {
			newhead = nullptr;
			tail = nullptr;
		}
		delete head;
		head = newhead;
		return result;
	}
	void out() {
		for (node_t* n = head; n!= nullptr; n = n->next) {
			std::cout << n->value;
		}
		return;
	}
	queue_t(queue_t & other) {
		for (node_t* n =other.head; n != nullptr; n = n->next) {
			push(n->value);
		}
	}
	~queue_t() {
		if (head == nullptr) {
			return;
		}
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		while (head != nullptr) {
			pop();
		}
		
		head = nullptr;
		tail = nullptr;
		return;
	}
};

int main()
{
	queue_t<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.out();
	std::cout << q.pop();
	std::cout << q.pop();
	queue_t<int> q1 = q;
	q1.out();
	system("pause");
    return 0;
}

