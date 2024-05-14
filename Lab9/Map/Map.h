#include <iostream>
template<typename K, typename V>
class Map {
	struct Node {
		K key;
		V value;
		int index;
		Node* next;
		Node() :next(nullptr) {}
		~Node() {
		}
		Node* operator++() {
			return this->next;
		}
		bool operator != (Node* m) { return this->key != m->key; }
		auto operator* () { return { key,value,index }; }
	};
	Node* root, * endp;
	int size;
public:
	Map() {
		root = nullptr;
		size = 0;
	}
	V& operator[](const K& x) {
		Node* i = root, * prev = nullptr;
		while (i) {
			if (i->key == x)
				return i->value;
			prev = i;
			i = i->next;
		}
		i = new Node;
		i->key = x;
		endp = i;
		i->index = ++size;
		if (root == nullptr)
			root = i;
		else
			prev->next = i;
		return i->value;
	}
	void Set(const K& key, V& value) {
		Node* i = root, * prev = nullptr;
		while (i) {
			if (i->key == key) {
				i->value = value; return;
			}
			prev = i;
			i = i->next;
		}
		i = new Node;
		i->key = key;
		endp = i;
		i->index = ++size;
		if (root == nullptr)
			root = i;
		else
			prev->next = i;
		i->value = value;
	}
	bool Get(const K& key, V& value) {
		Node* i = root;
		while (i) {
			if (i->key == key) {
				value = i->value;
				return 1;
			}
			i = i->next;
		}
		return 0;
	}
	int Count() {
		return size;
	}
	void Clear() {
		delete root;
		root = nullptr;
	}
	bool Delete(const K& key) {
		Node* i = root, * prev = nullptr;
		while (i) {
			if (i->key == key) {
				if (prev != nullptr)
					prev->next = i->next;
				else
					root = i->next;
				i->next = nullptr;
				delete i;
				return 1;
			}
			prev = i;
			i = i->next;
		}
		return 0;
	}
	bool Includes(const Map<K, V>& map) {
		for (auto [key, value, next] : map) {
			V val;
			if (!Get(key, val) || val != value)
				return 0;
		}
		return 1;
	}
	Node* begin() {
		return root;
	}
	Node* end() {
		return nullptr;
	}
};
