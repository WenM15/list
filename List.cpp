#include "Allocator.cpp"

template <typename T, typename Allocator<T>>
class List {
private:
	using value_type = Allocator<T>::value_type;
	using pointer = Allocator<T>::pointer;
	using const_pointer = Allocator<T>::const_pointer;
	using reference = Allocator<T>::reference;
	using const_reference = Allocator<T>::const_reference;
	using size_type = std::size_t;

	class Node {
	private:
		value_type data;
		pointer next;
		pointer prev;
	public:
		Node() = default;

		Node(value_type new_data, pointer next, pointer prev) {
			this->data = new_data;
			this->next = next;
			this->prev = prev;
		}

		Node(const Node& other) {
			this->data = other->data;
			this->next = other->next;
			this->prev = other->prev;
		}

	};
	Allocator<T> nodeAllocator;

public:

	class
};

int main() {
	
}