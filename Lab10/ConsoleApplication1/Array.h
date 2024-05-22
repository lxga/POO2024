#include <iostream>
#include <algorithm>
#include <exception>

class exceptie1 : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
} outofbounds;
class exceptie2 : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Array-ul este plin!";
    }
} outofspace;

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator {
private:
    T** list;
    int current;
public:
    ArrayIterator(T** list,int current) : list(list), current(current) {}
    
    ArrayIterator& operator ++ () {
        current++;
        return *this;
    }
    ArrayIterator& operator -- () {
        current--;
        return *this;
    }
    void operator= (const ArrayIterator<T>& a) {
        *this = a;
        //return *this;
    }
    bool operator!=(const ArrayIterator<T>& a) {
        return Current != a.Current;
    }
    T& operator*() {
        return list[current];
    }
};


template<class T>
class Array {
private:
    T** list; // lista cu pointeri la obiecte de tipul T*
    int capacity; // dimensiunea listei de pointeri
    int size; // cate elemente sunt in lista
public:
    Array() : list(nullptr), capacity(0), size(0) {}// Lista nu e alocata, Capacity si Size = 0
    ~Array() {
        for (int i = 0; i < size; i++)
            delete list[i];
        if (list != nullptr)
            delete list;
    }

    Array(int capacity) : capacity(capacity), size(0) {
        list = new T * [capacity];
    }
    Array(const Array<T>& otherArray) {
        list = new T * [otherArray.capacity];
        capacity = otherArray.capacity;
        size = otherArray.size;
        for (int i = 0; i < size; i++) {
            list[i] = otherArray.list[i];
        }
    }

    T& operator[] (int index) {
        if (index >= size || index < 0)
            throw outofbounds;
        return list[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (size == capacity)
            throw outofspace;
        list[++size] = new T(newElem);
        return *this;

    }// adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem) {
        if (index >= capacity || index < 0)
            throw outofbounds;
        if (size == capacity)
            throw outofspace;
        size++;
        for (int i = size-1; i >= index; i--) {
            list[i] = list[i - 1];
        }
        list[index] = new T(newElem);
        return *this;
    }// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index >= capacity || index < 0)
            throw outofbounds;
        if (size+otherArray.size > capacity)
            throw outofspace;
        size += otherArray.size;
        for (int i = size-1; i >= index; i--)
            list[i] = list[i - otherArray.size];
        for (int i = index; i <= index + otherArray.size - 1; i++)
            list[i] = new T(otherArray[i - index]);
    }// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index) {
        for (int i = index; i < size-1; i++) {
            list[i] = list[i + 1];
        }
        size--;
    }// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray) {
        if (size != otherArray.size)
            return 0;
        for (int i = 0; i < size; i++) {
            if (otherArray.list[i] != list[i])
                return 0;
        }
        return 1;
    }

    void Sort() {
        std::sort(this->begin(), this->end(), [](const T& a, const T& b) -> bool { return a<b });
    }// sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)) {
        std::sort(this->begin(), this->end(),compare);
    }// sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator) {
        std::sort(this->begin(), this->end(), comparator);
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) {
        return BinarySearch(elem, [](const T& a, const T& b) -> int { if (a < b) return -1; else return a > b; });
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int l = 0, r = size - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (compare(elem,list[mid])<0)
                r = mid;
            else
                l = mid;
        }
        if (compare(elem,list[l])==0)
            return l;
        else
            return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator) {
        int l = 0, r = size - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (comparator->CompareElements(elem,list[mid])<0)
                r = mid;
            else
                l = mid;
        }
        if (comparator->CompareElements(elem, list[l]) == 0)
            return l;
        else
            return -1;
    } 
    int Find(const T& elem) {
        return std::find(begin(), end(), elem);
    }
    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        //return std::find(begin(), end(), elem, compare);
    }
    int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

    int GetSize() {
        return size;
    }
    int GetCapacity() {
        return capacity;
    }

    ArrayIterator<T> begin() {
        return ArrayIterator<T>(list,0);
    }
    ArrayIterator<T> end() {
        return ArrayIterator<T>(list, size);
    }
};
