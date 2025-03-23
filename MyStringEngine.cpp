#include "MyString.h"

MyString::MyString() {}
MyString::MyString(unsigned int count, char ch)
{
	sizeStr = count; capacity = count;
	str = new char[sizeStr];
	for (unsigned int i = 0; i < sizeStr; i++)
		str[i] = ch;
}
MyString::MyString(const char* string)
{
	sizeStr = 0;
	while (string[sizeStr] != '\0') sizeStr += 1;
	capacity = sizeStr;
	str = new char[sizeStr];
	for (unsigned int i = 0; i < sizeStr; i++)
		str[i] = string[i];
}
//RULE OF THREE
MyString::MyString(const MyString& copy) {
	sizeStr = copy.sizeStr; capacity = copy.capacity;
	str = new char[sizeStr];
	for (unsigned int i = 0; i < sizeStr; i++)
		str[i] = copy.str[i];
}

MyString& MyString::operator=(const MyString& v) {
	if (&v != this) {
		delete[] str;
		sizeStr = v.sizeStr;  capacity = v.capacity;
		str = new char[sizeStr];
		for (unsigned int i = 0; i < sizeStr; i++)
			str[i] = v.str[i];
	}
	return *this;
}

MyString::~MyString() {
	delete[] str;
}
//RULE OF THREE ^^^
//Auxiliary
bool MyString::empty() const
{
	for (unsigned int i = 0; i < sizeStr; i++)
	{
		if (str[i] != '\0')
		{
			return false;
		}
	}
	return true;
}
unsigned int MyString::size() const
{
	return sizeStr;
}
unsigned int MyString::length() const
{
	return this->size();
}
void MyString::print() const {
	for (unsigned int i = 0; i < sizeStr; i++) std::cout << str[i];
	std::cout << std::endl;
}
//Element access without bound checking
char& MyString::operator[](unsigned int index)
{
	return str[index];
}
char MyString::operator[](unsigned int index) const
{
	return str[index];
}
//Element access with bound checking
char& MyString::at(unsigned int index)
{
	if (index < sizeStr)
		return str[index];
	throw "Error#At: Array index out of bounds";
}
char MyString::at(unsigned int index) const
{
	if (index < sizeStr)
		return str[index];
	throw "Error#At: Array index out of bounds";
}
//Raw data access
const char* MyString::c_str() const
{
	return str;
}
char* MyString::data()
{
	return str;
}
const char* MyString::data() const
{
	return str;
}
//Modifiers
void MyString::clear()
{
	str = nullptr;
	sizeStr = 0; capacity = 0;
}
void MyString::resize(unsigned int count)
{
	if (count <= capacity && count >= sizeStr)
	{
		sizeStr = count;
	}
	else if (count == 0) { this->clear(); }
	else if (count == sizeStr) {}
	else
	{
		char* dop = new char[count];
		unsigned int min = std::min(sizeStr, count);
		for (unsigned int i = 0; i < min; i++)
		{
			dop[i] = str[i];
		}
		delete[] str;
		sizeStr = count; capacity = count;
		str = dop;
		for (unsigned int i = min; i < sizeStr; i++)
		{
			str[i] = ' ';//'\0'
		}
	}
}
void MyString::realloc(unsigned int count)
{
	if (count >= sizeStr)
	{
		char* dop = new char[count];
		for (unsigned int i = 0; i < sizeStr; i++)
		{
			dop[i] = str[i];
		}
		delete[] str;
		capacity = count;
		str = dop;
	}
	else
	{
		std::cout << "Error#Realloc: count can not be < than sizeStr(sizeStr->sizeStr, capacity -> count)" << "\n";
	}
}
unsigned int MyString::insert(unsigned int pos, char ch)  // aad, insert(2, 'b') => aabd, return pos
{
	if (pos <= sizeStr)
	{
		this->resize(sizeStr + 1);
		for (unsigned int i = sizeStr - 1; i > pos; i--)
			str[i] = str[i - 1];
		str[pos] = ch;
		return pos;
	}
	else
	{
		std::cout << "Error#Insert: Out-of-bounds" << "\n";
	}
}
unsigned int MyString::insert(unsigned int pos, const MyString& substr) // aad__, insert(2, "bc") => aabcd
{
	if (pos <= sizeStr)
	{
		this->resize(sizeStr + substr.sizeStr);
		for (unsigned int i = sizeStr - 1; i > pos + substr.sizeStr; i--)
			str[i] = str[i - substr.sizeStr];
		for (unsigned int i = pos; i < pos + substr.sizeStr; i++)
			str[i] = substr.str[i - pos];
		return pos;
	}
	else
	{
		std::cout << "Error#(Long)Insert: Out-of-bounds" << "\n";
	}
}
unsigned int MyString::erase(unsigned int pos)  // aabd, erase(2) => aad
{
	if (pos < sizeStr)
	{
		for (unsigned int i = pos; i < sizeStr - 1; i++)
			str[i] = str[i + 1];
		this->resize(sizeStr - 1);
		return pos;
	}
	else
	{
		std::cout << "Error#Erase: Out-of-bounds" << "\n";
	}
}
unsigned int MyString::erase(unsigned int pos, unsigned int count)  // aabdcc, erase(2, 2) => aacc
{
	if (pos < sizeStr - count)
	{
		for (unsigned int i = pos; i < sizeStr - count; i++)
			str[i] = str[i + count];
		this->resize(sizeStr - count);
		return pos;
	}
	else
	{
		std::cout << "Error#(Long)Erase: Out-of-bounds" << "\n";
	}
}
void MyString::push_back(char ch) // insert to the end
{
	if (sizeStr + 1 > capacity)
	{
		this->realloc(unsigned int(round(double(sizeStr) * 1.5)));
	}
	sizeStr++;
	str[sizeStr - 1] = ch;
}
void MyString::pop_back()  // erase from the end
{
	if (sizeStr > 0)
	{
		sizeStr--;
	}
	else
	{
		std::cout << "Error#Pop_Back: Out-of-bounds" << "\n";
	}
}
//Concatenation, "aaa" + "bb" => "aaabb"
MyString MyString::operator+(const MyString& string)
{
	MyString dop;
	dop = *this;
	dop.insert(sizeStr, string);
	return dop;
}
MyString& MyString::operator+=(const MyString& string)
{
	this->insert(sizeStr, string);
	return *this;
}
//Search
unsigned int MyString::find(const MyString& substr, unsigned int pos)  // MyString("aaab").find("ab") => 2
{
	if (substr.sizeStr <= sizeStr)
	{
		for (unsigned int a = 0; a < (sizeStr - substr.sizeStr + 1); a++)
		{
			if (str[a] == substr.str[0])
			{
				bool flag = 1;
				for (unsigned int b = 1; b < substr.sizeStr; b++)
				{
					if (str[a + b] != substr.str[b])
					{
						flag = 0;
						break;
					}
				}
				if (flag == 1)
					return a;
			}
		}
	}
	else
	{
		throw;
	}
}
//Compare, lexicograph. order
int MyString::compare(const MyString& string) const
{
	unsigned int min = std::min(sizeStr, string.sizeStr);
	for (unsigned int i = 0; i < min; i++)
	{
		if (str[i] > string.str[i])
			return 1;
		if (str[i] < string.str[i])
			return -1;
	}
	if (sizeStr > string.sizeStr)
		return 1;
	else if (sizeStr < string.sizeStr)
		return -1;
	else
	{
		return 0;
	}
}
bool MyString::operator==(const MyString& string) const
{
	if (this->compare(string) == 0)
		return true;
	return false;
}
bool MyString::operator!=(const MyString& string) const
{
	if (this->compare(string) != 0)
		return true;
	return false;
}
bool MyString::operator<(const MyString& string) const
{
	if (this->compare(string) < 0)
		return true;
	return false;
}
bool MyString::operator>(const MyString& string) const
{
	if (this->compare(string) > 0)
		return true;
	return false;
}
bool MyString::operator<=(const MyString& string) const
{
	if (this->compare(string) <= 0)
		return true;
	return false;
}
bool MyString::operator>=(const MyString& string) const
{
	if (this->compare(string) >= 0)
		return true;
	return false;
}