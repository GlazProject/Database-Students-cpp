#pragma once
#include "Student.h"

template<typename T>
struct Node {
	Node() {};
	T value;
	Node* next;
};

template<typename T>
class List {
public:
	List() {
		head = nullptr;
		tail = nullptr;
	}
	void append(T value) {
		Node<T>* tmp = new Node<T>;
		tmp.next = nullptr;
		tmp.value = value;
		if()
	}

private:
	Node<T>* head;
	Node<T>* tail;
};