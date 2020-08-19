#include "Vector.h"
#include "Point.h"

Vector::Vector()
{
	size = 0;
	arr = new Point[size];
}
Vector::Vector(const Vector& tmp)
{
	this->size = tmp.size;
	this->arr = new Point[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = tmp.arr[i];
	}
}
Vector::Vector(Vector&& tmp)
{
	this->size = tmp.size;
	this->arr = tmp.arr;
	tmp.arr = nullptr;
	tmp.size = 0;
}
Vector& Vector::operator=(const Vector& tmp)
{
	if (this == &tmp)
	{
		return *this;
	}
	if (arr != nullptr)
	{
		delete[] arr;
	}
	this->size = tmp.size;
	this->arr = new Point[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = tmp.arr[i];
	}
	return *this;
}
Vector& Vector::operator=(Vector&& tmp)
{
	if (this == &tmp)
	{
		return *this;
	}
	if (arr != nullptr)
	{
		delete[] arr;
	}
	this->size = tmp.size;
	this->arr = tmp.arr;
	tmp.arr = nullptr;
	tmp.size = 0;
	return *this;
}
void Vector::Add(Point po)
{
	Point* temp = new Point[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = po;
	size = size + 1;
	delete[] arr;
	arr = temp;
}
void Vector::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Point " << i + 1 << "] ";
		cout << "X: " << arr[i].x << " Y: " << arr[i].y << endl;
	}
}
Vector::~Vector()
{
	delete[] arr;
}
