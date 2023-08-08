#include <limits>
//#include <cassert>
//#include <iostream>

using namespace std;

template <typename T>
class Allocator {
    // Type aliases
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;

public:

    // Default constructor
    Allocator() noexcept = default;

    // Copy constructor
    Allocator(const Allocator& other) noexcept = default;

    // Templated copy constructor (useless)
    template <typename U>
    Allocator(const Allocator<U>& other) noexcept {}

    // Destructor
    ~Allocator() = default;

    // Functions
    pointer allocate(size_type numObjects) const {
        return static_cast<pointer>(::operator new(numObjects * sizeof(value_type)));
    }

    void deallocate(pointer p, size_type numObjects) const {
        ::operator delete(p);
    }

    void construct(pointer p, const_reference val) const {
        new (p) value_type(val);
    }
    
    //template <typename ...Args>
    //void construct() const {

    //}

    template <typename U>
    void destroy(U* p) const {
        p->~U();
    }

    size_type max_size() const noexcept {
        return std::numeric_limits<int>::max();
    }

};

//class Class1 {
//public:
//    static int counter;
//    int abc;
//
//    Class1(int val = 0) : abc(val) {
//        ++counter;
//        /*cout << "Constructing object at address " << this << endl;*/
//    }
//
//    ~Class1() {
//        --counter;
//        /*cout << "Destroying object at address " << this << endl;*/
//    }
//
//};
//int Class1::counter = 0;
//
//int main() {
//    // Test default constructor
//    Allocator<Class1>* alloc1 = new Allocator<Class1>();
//    assert(alloc1);
//
//    // Test copy constructor
//    Allocator<Class1>* allocCopy = new Allocator<Class1>(*alloc1);
//    assert(allocCopy);
//
//    // Test templated copy constructor
//    Allocator<double>* allocDouble = new Allocator<double>(*allocCopy);
//    assert(allocDouble);
//
//    // Test max_size()
//    cout << alloc1->max_size() << endl << endl;
//
//    // Test allocate()
//    Class1* class1P = alloc1->allocate(3);
//    assert(class1P != nullptr);
//
//    // Test construct()
//    for (int i = 0; i <= 3 - 1; ++i) {
//        alloc1->construct(class1P + i, i);
//        cout << (class1P + i)->abc << " ";
//        //cout << Class1::counter << " ";
//        //assert(Class1::counter == i + 1);
//    }
//    cout << endl << endl;
//
//    // Test destroy()
//    for (int i = 0; i <= 3 - 1; ++i) {
//        alloc1->destroy(class1P + i);
//        //assert(Class1::counter == 2 - i);
//    }
//
//    // Test deallocate()
//    alloc1->deallocate(class1P, 3);
//
//}