#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	T* data;
	int size, capacity;


	void copy(const Vector& other)
	{
		this->capacity = other.capacity;

		this->data = new T[capacity];

		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}

		this->size = other.size;
	}

	void erase()
	{
		delete[] this->data;
	}

	void resize()
	{
		if (this->size >= this->capacity)
			this->capacity *= 2;

		T* bigger = new T[this->capacity];

		for (int i = 0; i < this->size; i++)
		{
			bigger[i] = this->data[i];
		}

		this->erase();
		this->data = bigger;
	}
public:
	Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	// Ïîëå íà êëàñà - òèïà íà åëåìåíòèòå ñå ïàçè â VALUE TYPE
	using value_type = T;

	void push_back(const T& el);
	void pop_back();
	void push_front(const T& el);
	void pop_front();
	void push_at(const T& el, int position);
	void pop_at(int position);
	void pop_by_data(const T& el);
	bool contains(const T& el);

	int getSize() const;
	int getCapacity() const;
	bool isEmpty() const;
	void print() const;

	Vector<T> operator +(const Vector& other);
	Vector<T>& operator +=(const Vector& other);
	T& operator [](int i);
	const T& operator [] (int i) const;
	bool operator==(const Vector& other);
	bool operator!=(const Vector& other);

	class Iterator
	{
	public:
		Iterator(size_t pos, Vector& _vector);
		bool operator!=(const Iterator& it);
		Iterator& operator++();
		T& operator*();

	private:
		size_t index;
		Vector& vector;
	};

	Iterator begin();
	Iterator end();
};

template <typename T>
Vector<T>::Vector()
{
	this->data = nullptr;
	this->size = 0;
	this->capacity = 8;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}

	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	this->erase();
}

template <typename T>
void Vector<T>::push_back(const T& el)
{
	if (size == capacity || this->data == nullptr) {
		resize();
	}

	this->data[size] = el;
	this->size++;
}

template <typename T>
void Vector<T>::pop_back()
{
	T* smaller = new T[this->capacity];

	for (int i = 0; i < this->size - 1; i++)
	{
		smaller[i] = this->data[i];
	}

	--this->size;
	this->erase();
	this->data = smaller;
}

template <typename T>
void Vector<T>::push_front(const T& el)
{
	if (size == capacity || this->data == nullptr) {
		resize();
	}

	T* bigger = new T[this->size + 1];

	for (int i = 0; i < this->size; i++)
	{
		bigger[i + 1] = this->data[i];
	}

	++size;
	bigger[0] = el;
	this->erase();
	this->data = bigger;
}

template <typename T>
void Vector<T>::pop_front()
{
	T* smaller = new T[this->size + 1];

	for (int i = 0; i < this->size; i++)
	{
		smaller[i] = this->data[i + 1];
	}

	--this->size;
	this->erase();
	this->data = smaller;
}

template <typename T>
void Vector<T>::push_at(const T& el, int position)
{
	if (size == capacity || this->data == nullptr) {
		resize();
	}

	if (this->size >= position)
	{
		for (int i = this->size; i >= position; i--)
		{
			this->data[i] = this->data[i - 1];
		}

		++this->size;
		this->data[position - 1] = el;
	}
	else
		cout << "Position greater than the SIZE!" << endl;
}

template <typename T>
void Vector<T>::pop_at(int position)
{
	for (int i = position - 1; i < this->size; i++)
	{
		this->data[i] = this->data[i + 1];
	}

	--this->size;
}

template <typename T>
void Vector<T>::pop_by_data(const T& el)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == el)
			this->pop_at(i + 1);
	}
}

template<typename T>
bool Vector<T>::contains(const T& el)
{
	for (int i = 0; i < this->size; i++) {
		if (this->data[i] == el)
			return true;
	}

	return false;
}

template <typename T>
int Vector<T>::getSize() const
{
	return this->size;
}

template <typename T>
int Vector<T>::getCapacity() const
{
	return this->capacity;
}

template <typename T>
bool Vector<T>::isEmpty() const
{
	return this->size == 0;
}

template <typename T>
void Vector<T>::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->data[i] << " ";
	}

	cout << std::endl;
}

template <typename T>
Vector<T> Vector<T>::operator +(const Vector<T>& other)
{
	Vector<T> result;

	this->resize();
	result.data = new T[this->capacity + other.capacity];

	for (int i = 0; i < this->size; i++)
	{
		result[i] = this->data[i];
	}

	for (int i = 0; i < other.size; i++)
	{
		result[this->size + i] = other.data[i];
	}


	result.size = this->size + other.size;
	return result;
}

template <typename T>
Vector<T>& Vector<T>::operator +=(const Vector& other)
{
	this->resize();
	T* bigger = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		bigger[i] = this->data[i];
	}

	for (int i = 0; i < other.size; i++)
	{
		bigger[this->size + i] = other.data[i];
	}

	this->erase();
	this->data = bigger;
	this->size = this->size + other.size;

	return *this;
}

template <typename T>
T& Vector<T>::operator [](int i)
{
	return data[i];
}

template <typename T>
const T& Vector<T>::operator[] (int i) const
{
	return data[i];
}

template <typename T>
bool Vector<T>::operator==(const Vector& other)
{
	if (this->size != other.size)
		return false;

	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] != other.data[i])
			return false;
	}

	return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector& other)
{
	return !(this == &other);
}


template <typename T>
ostream& operator<<(ostream& stream, Vector<T> v)
{
	for (int i = 0; i < v.getSize(); i++)
	{
		cout << v[i] << " ";
	}

	return stream;
}

// For Iterator

template <class T>
Vector<T>::Iterator::Iterator(size_t pos, Vector<T>& _vector) : index(pos), vector(_vector) {}

template<typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
	return typename Vector<T>::Iterator(0, *this);
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
	return typename Vector<T>::Iterator(size, *this);
}

template <typename T>
bool Vector<T>::Iterator::operator!=(const typename Vector<T>::Iterator& it) {
	// data?
	return index != it.index;
}

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
	if (index >= vector.getSize()) {
		throw std::out_of_range("Going past end of vector!");
	}

	++index;
	return *this;
}

template <typename T>
T& Vector<T>::Iterator::operator*() {
	if (index >= vector.getSize()) {
		throw std::out_of_range("Reading past end of vector!");
	}

	return vector[index];
}