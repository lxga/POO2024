#include <iostream>

template<typename K, typename V>
class Map {
	struct info {
		K key;
		V value;
		int index;
	};
	struct Node {
		info inff;
		Node* next;
		Node() :next(nullptr) {}
		~Node() {
			if (next != nullptr)
				delete next;
		}
	};
	class Iterator {
		Node* node;
	public:
		Iterator(Node* node) : node(node) {}
		bool operator!= (const Iterator& other) const { return node != other.node; }
		void operator++ () { node = node->next; }
		info operator* () const { return node->inff; }
	};
	
	Node *root, *endp;
	int size;
public:
	Map() {
		root = nullptr;
		size = 0;
	}
	V& operator[](const K& x) {
		Node* i = root, * prev = nullptr;
		while (i) {
			if (i->inff.key == x)
				return i->inff.value;
			prev = i;
			i = i->next;
		}
		i = new Node;
		i->inff.key = x;
		endp = i;
		i->inff.index = ++size;
		if (root == nullptr)
			root = i;
		else
			prev->next = i;
		return i->inff.value;
	}
	void Set(const K& key, V& value) {
		(*this)[key] = value;
	}
	bool Get(const K& key, V& value) {
		Node* i = root;
		while (i) {
			if (i->inff.key == key) {
				value = i->inff.value;
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
			if (i->inff.key == key) {
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
	Iterator begin() { return Iterator(root); }
	Iterator end() { return Iterator(nullptr); }
};
