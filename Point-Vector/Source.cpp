#include <iostream>
using namespace std;
class Vector;
class Point
{
private:
	int x;
	int y;
	friend Vector;
	friend bool operator<(const Point& p1, const Point& p2);
	friend bool operator>(const Point& p1, const Point& p2);
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int t)
	{
		this->x = t;
		this->y = t;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()
	{
		cout << "X: " << x << "\nY: " << y << endl << endl;
	}
	Point& operator++(int)
	{
		this->x = this->x + 1;
		this->y = this->y + 1;
		return *this;
	}
	Point& operator++()
	{
		this->x = this->x + 1;
		this->y = this->y + 1;
		return *this;
	}
	Point& operator--(int)
	{
		this->x = this->x - 1;
		this->y = this->y - 1;
		return *this;
	}
	Point& operator--()
	{
		this->x = this->x - 1;
		this->y = this->y - 1;
		return *this;
	}
	Point& operator!()
	{
		this->x = this->x * (-1);
		this->y = this->y * (-1);
		return *this;
	}
};
bool operator<(const Point& p1, const Point& p2)
{
	return ((p1.x - p2.x) + (p1.y - p2.y) > (p2.x - p1.x) + (p2.y - p1.y));
}

bool operator>(const Point& p1, const Point& p2)
{
	return ((p1.x - p2.x) + (p1.y - p2.y) < (p2.x - p1.x) + (p2.y - p1.y));
}

class Vector
{
private:
	Point *arr;
	int size;
public:
	Vector()
	{
		size = 0;
		arr = nullptr;
	}
	Vector(const Vector& tmp)
	{
		this->size = tmp.size;
		this->arr = new Point[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = tmp.arr[i];
		}
	}
	Vector(Vector&& tmp)
	{
		this->size = tmp.size;
		this->arr = tmp.arr;
		tmp.arr = nullptr;
		tmp.size = 0;
	}
	Vector& operator=(const Vector& tmp)
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
	Vector& operator=(Vector&& tmp)
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
	void Add(Point po)
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
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Point " << i + 1<<") ";
			cout << "x: " << arr[i].x << " y: " << arr[i].y << endl;
		}
	}
	~Vector()
	{
		delete[] arr;
	}
};


int main()
{
	Point p1(5, 5);
	Point p2(7, 2);
	cout << (p1 > p2) << endl;
	cout << (p1 < p2) << endl;
	p1.Print();
	Vector f;
	f.Add(p1);
	f.Add(p2);
	f.Print();
	return 0;
}