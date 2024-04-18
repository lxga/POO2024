#pragma once
#include <iostream>
#include <algorithm>

template<typename T>
class Node {
public:
	T val;
	Node<T>* parent;
	Node<T>** next;
	int k;
	Node(T val,Node<T>* parent) : parent(parent) {
		this->val = val;
		this->next = nullptr;
		k = 0;
	}
	~Node() {
		if (next == nullptr)
			return;
		for (int i = 0; i < k; i++) {
			delete next[i];
		}
		delete[] next;
	}
	void add_node(T& val) {
		Node<T>* i = next;
		Node<T>** temp = new Node* [k + 1];
		for (int i = 0; i < k; i++)
			temp[i] = next[i];
		temp[k] = new Node(val, this);
		k++;
		delete[] next;
		next = temp;
	}
	void delete_node(Node* p) {
		Node<T>* i = next;
		Node<T>** temp = new Node * [k - 1];
		bool ok = 1;
		for (int i = 0; i < k; i++) {
			if (next[i] == p) {
				ok = 0;
				delete p;
			}
			else if (ok)
				temp[i] = next[i];
			else
				temp[i-1] = next[i];
		}
		k--;
		delete[] next;
		next = temp;
	}
	Node& get_node(T& val) {
		Node<T>* i = next;
		while (i) {
			if (i->val == val)
				return *i;
			i++;
		}
		return nullptr;
	}
	Node& find(T& val) {
		for (int i = 0; i < k; i++) {
			if (next[i]->val == val)
				return next[i];
			else {
				Node& res = next[i]->find(val);
				if (res != nullptr)
					return res;
			}
				
		}
		return nullptr;
	}
	void insert(T& val, int index) {
		if (index >= k)
			return;
		Node<T>* i = next;
		Node<T>** temp = new Node * [k + 1];
		bool ok = 1;
		for (int i = 0; i <= k; i++) {
			if (i==index) {
				ok = 0;
				temp[i] = new Node(val, this);
			}
			else if (ok)
				temp[i] = next[i];
			else
				temp[i] = next[i-1];
		}
		k++;
		delete[] next;
		next = temp;
	}
	void sort(bool (*func)(const T& a, const T& b)) {
		int last = k - 1;
		while(last) {
			last = 0;
			for (int i = 0; i < k-1; i++) {
				if (!func(next[i]->val, next[i + 1]->val)) {
					last = i;
					std::swap(next[i], next[i + 1]);
				}
			}
		}
	}
	int count() {
		int ans = k;
		for (int i = 0; i < k; i++) {
			ans += next[i]->count();
		}
		return ans;
	}
};

template<typename T>
class Tree {
	Node<T>* root;
public:
	Tree() {
		root = nullptr;
	}
	~Tree() {
		if (root == nullptr) return;
		delete root;
	}
	void add_node(Node<T>* p, T& val) {
		if (p == nullptr) {
			if (root != nullptr)
				delete root;
			root = new Node(val,nullptr);
		}
		else {
			p->add_node(val);
		}
	}
	Node<T>& get_node(Node<T>* p, T& val) {
		if (p == nullptr)
			return *root;
		return p->get_node(val);
	}
	void delete_node(Node<T>* p) {
		if (p == nullptr)
			return;
		if (p == root)
			delete root;
		else
			p->parent->delete_node(p);
	}
	Node<T>& find(T& val) {
		if (root == nullptr)
			return nullptr;
		return root->find(val);
	}
	void insert(Node<T>* p, T& val, int index) {
		p->insert(val, index);
	}
	void sort(Node<T>* p, bool (*func)(const T& a, const T& b)) {
		p->sort(func);
	}
	int count(Node<T>* p) {
		return p->count();
	}
};