#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;		
const double pi = 3.141592653589;

class figure
{
	public:
		virtual double area() = 0;
};

class square : public figure
{
	private:
		double length;
	public:
		square(double l): length(l) {}
		double area()
		{
			return length * length;
		}
};

class circle : public figure
{
	private:
		double radius;
	public:
		circle(double r) : radius(r) {}
		double area()
		{
			return pi * radius * radius;
		}
};

class triangle : public figure
{
	private:
		double length;
	public:
		triangle(double b) : length(b) {}
		double area()
		{
			double p = 3*length / 2;
			return sqrt(p * (p - length) * (p - length) * (p - length));
		}
};

int main()
{
	int n;
	
	ifstream in("input.txt");
	ofstream out("output.txt"); 

	in >> n;

	figure** figures = new figure*[n];

	for (int i = 0; i < n; i++) {
		char c = ' ';
		double side = 0;
		in >> c;
		switch (c) {
			case 'C':
				in >> side;
				figures[i] = new circle(side);
				break;
			case 'S':
				in >> side;
				figures[i] = new square(side);
				break;
			case 'T':
				in >> side;
				figures[i] = new triangle(side);
				break;
		}
	}
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += figures[i]->area();

	out << std::fixed << std::setprecision(2) << sum;
}
