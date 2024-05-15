#include <iostream>
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
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator();
    ArrayIterator& operator ++ ();
    ArrayIterator& operator -- ();
    bool operator= (ArrayIterator<T>&);
    bool operator!=(ArrayIterator<T>&);
    T* GetElement();
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
        for (int i = 0; i < capacity; i++)
            list[i] = new T;
    }
    Array(const Array<T>& otherArray) {
        list = new T * [otherArray.capacity];
        for (int i = 0; i < capacity; i++) {
            list[i] = otherArray.list[i];
        }
    }

    T& operator[] (int index) {
        if (index >= capacity || index < 0)
            throw outofbounds;
        return list[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (size == capacity)
            throw outofspace;
        list[++size] = newElem;
        return *this;

    }// adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem) {
        if (index >= capacity || index < 0)
            throw outofbounds;
        list[index] = newElem;
        return *this;
    }// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

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
        sort(this->GetBeginIterator(), this->GetEndIterator());
    }// sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

    int GetSize();
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};
