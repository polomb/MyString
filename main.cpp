#include "MyString.h"


int main() 
{
	try
	{
		MyString a;
		MyString b(10, 'a');
		MyString c("");
		MyString d("Hello");
		b.print();
		std::cout << "a, b, c, d empty?:" << a.empty() << " " << b.empty() << " " << c.empty() << " " << d.empty() << "\n";
		std::cout << "a, b(length), b(size), c, d size:" << a.size() << " " << b.length() << " " << b.size() << " " << c.size() << " " << d.size() <<"\n";
		//
		std::cout << "Resize function" << "\n";
		b.print();
		b.resize(6);
		b.print();
		b.resize(9);
		b[8] = 'a';
		b.print();
		//
		std::cout << "Insert and Erase functions" << "\n";
		b.insert(2, 'g');
		b.print();
		b.insert(7, d);
		d.print();
		b.print();
		b.erase(7, 5);
		b.print();
		b.erase(2);
		b.print();
		b.insert(100, 'g');
		b.insert(100, d);
		b.erase(100);
		b.erase(100, 5);
		//
		std::cout << "push_back and pop_back functions" << "\n";
		b.push_back('g');
		b.print();
		b.pop_back();
		b.print();
		//
		MyString e("GG");
		e += d;;
		MyString f = e + d;
		std::cout << "f, e, d after e+=d and f = e + d (d was Hello, e was GG, f was ___(empty))" << "\n";
		f.print();
		e.print();
		d.print();
		MyString r1("G");
		MyString r2("GG");
		MyString r3("GGG");
		MyString r4("AG");
		MyString r5("XG");
		//
		std::cout << "r1 is G, r2 is GG, r3 is GGG, r4 is AG, r5 is XG" << "\n" << "We compare r2 & r1; r2 & r2; r2 & r3; r2 & r4; r2 & r5" << "\n";
		std::cout << r2.compare(r1) << " " << r2.compare(r2) << " " << r2.compare(r3) << "\n";
		std::cout << r2.compare(r4) << " " << r2.compare(r5) << "\n";
		//
		std::cout << "r2 == r1; r2 == r2:" << (r2 == r1) << " " << (r2 == r2) << "\n";
		std::cout << "r2 != r1; r2 != r2:" << (r2 != r1) << " " << (r2 != r2) << "\n";
		std::cout << "r2 < r1; r2 < r2; r2 < r3; r2 < r4; r2 < r5:" << (r2 < r1) << " " << (r2 < r2) << " " << (r2 < r3) << " " << (r2 < r4) << " " << (r2 < r5) << "\n";
		std::cout << "r2 > r1; r2 > r2; r2 > r3; r2 > r4; r2 > r5:" << (r2 > r1) << " " << (r2 > r2) << " " << (r2 > r3) << " " << (r2 > r4) << " " << (r2 > r5) << "\n";
		std::cout << "r2 <= r1; r2 <= r2; r2 <= r3; r2 <= r4; r2 <= r5:" << (r2 <= r1) << " " << (r2 <= r2) << " " << (r2 <= r3) << " " << (r2 <= r4) << " " << (r2 <= r5) << "\n";
		std::cout << "r2 >= r1; r2 >= r2; r2 >= r3; r2 >= r4; r2 >= r5:" << (r2 >= r1) << " " << (r2 >= r2) << " " << (r2 >= r3) << " " << (r2 >= r4) << " " << (r2 >= r5) << "\n";
		//
		std::cout << "r1 += r2 += r3" << "\n";
		r1 += r2 += r3;
		r1.print();
		r2.print();
		r3.print();
		MyString rr1 = r1 + r2 + r3;
		MyString rr2 = (r1 + r2) + r3;
		MyString rr3 = r1 + (r2 + r3);
		std::cout << "r1 + r2 + r3; (r1 + r2) + r3; r1 + (r2 + r3)" << "\n";
		rr1.print();
		rr2.print();
		rr3.print();
		//
		std::cout << "We clear d and print it" << "\n";
		d.clear();
		d.print();
		//
		std::cout << "r6 is AFAHBFHAWBfYAWAAF, r7 is AAF, we find(function) r7 in r6" << "\n";
		MyString r6("AFAHBFHAWBfYAWAAF");
		MyString r7("AAF");
		std::cout << r6.find(r7) << "\n";
		//
		std::cout << "b[5] and b.at(5) is in range of Array, b[10] and b.at(10) is out of range of Array" << "\n";
		std::cout << b[5] << " " << b.at(5) << " " << b[10] << "\n";
		std::cout << b.at(10) << "\n";
	}
	catch (const char* error_message)
	{
		std::cout << error_message << std::endl;
	}
}
