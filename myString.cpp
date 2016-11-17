#include "myString.h"

unsigned int myString::objCount = 0;

myString::myString():str(NULL),size(1)
{
	str = new char[size];
	*str='\0';
	objCount++;
}

myString::myString(const char* t, size_t len):str(NULL),size(0)
{
	if (len==0)
		len = strlen(t);
	size = len+1;

	str = new char[size];
	memcpy(str, t, len);
	str[len] = '\0'; 

	objCount++;
}

myString::myString(const myString &other)
{
	size = other.size;
	str = new char[size];
	memcpy(str, other.str, size);

	objCount++;
}

myString::myString(const myString &t, size_t pos, size_t len):str(NULL),size(0)
{
	if (pos + len < t.size)
	{
		if (len==0)
			len = t.size-pos-1;
		size = len+1;
		
		str = new char[size];
		memcpy(str, t.str+pos, len);
		str[len] = '\0';
	}
	else
		throw std::out_of_range("Выход за пределы копируемой строки construcnor myString size_t size_t");
	
	objCount++;
}

myString::~myString()
{
	delete[] str;
	objCount--;
}

size_t myString::getSize() const
{
	return size;
}

// size_t myString::strLenght()
// {}

char* myString::getAddr() const
{
	return str;
}

void myString::clear()
{
	delete[] str;
	size = 1;
	str = new char[size];
	*str = '\0';
}

bool myString::empty() const
{
	return !(*str);
}

myString& myString::append(const myString& t, size_t pos, size_t len)
{	
	if (pos + len < t.size)
		return this->append(t.str+pos, len);
	else
		throw std::out_of_range("Выход за пределы строки append myString");
}

myString& myString::append(const char* t, size_t n)
{
	if (n==0)
		n = strlen(t);
	
	char* buffer = NULL;
	if (this->isInThis(t))
	{
		buffer = new char[n];
		memcpy(buffer, t, n);
		t = buffer;
	}

	char* newStr = new char[size+n];
	memcpy(newStr, str, size-1);
	memcpy(newStr+size-1, t, n);
	delete[] str;
	str = newStr;
	size = size+n;
	str[size-1]='\0';

	if (buffer!=NULL)
		delete[] buffer;
	
	return *this;
}
myString& myString::append(const char ch)
{
	char* newStr = new char[size+1];
	memcpy(newStr, str, size-1);
	delete[] str;
	str = newStr;
	size = size+1;
	*(str+size-2) = ch;
	*(str+size-1) = '\0';
	return *this;
}

myString& myString::assign(const myString& t, size_t pos, size_t len)
{
	if (pos + len < t.size)
		return this->assign(t.str+pos, len);
	else
		throw std::out_of_range("Выход за пределы строки assign myString");
}

myString& myString::assign(const char* t, size_t n)
{
	if (n == 0)
		n = strlen(t);
	n++;

	char* buffer = NULL;
	if (this->isInThis(t))
	{
		buffer = new char[n];
		memcpy(buffer, t, n);
		t = buffer;
	}

	delete str;
	size = n;
	str = new char[size];
	memcpy(str, t, size-1);
	str[size-1] = '\0';

	if (buffer!=NULL)
		delete[] buffer;

	return *this;
}

myString& myString::assign(const char ch, size_t n)
{
	if (n == 0)
		clear();
	else
	{
		delete str;
		size = n+1;
		str = new char[size];
		memset(str, ch, n);
		str[n] = '\0';
	}
	return *this;
}

myString& myString::insert(size_t pos, const myString& t, size_t subPos, size_t subLen)
{
	if (subPos + subLen < t.size)
		return this->insert(pos, t.str+subPos, subLen);
	else
		throw std::out_of_range("Выход за пределы строки tStr insert myString");
}

myString& myString::insert(size_t pos, const char* t, size_t n)
{
	if(pos > size)
		throw std::out_of_range("Выход за пределы строки insert char*");
	
	if (n==0)
		n = strlen(t);
	
	// std::cout << "insert this " << strAddr() << std::endl;
	// std::cout << "insert pos " << pos << std::endl;
	// std::cout << "insert tStr " << tStr << std::endl;
	// std::cout << "insert n " << n << std::endl;
	if (n != 0)
	{
		char* buffer = NULL;
		if (this->isInThis(t))
		{
			buffer = new char[n];
			memcpy(buffer, t, n);
			t = buffer;
		}
		
		char* newStr = new char[size+n];
		memcpy(newStr, str, pos);
		memcpy(newStr+pos, t, n);
		memcpy(newStr+pos+n, str+pos, size-1-pos);
		delete[] str;
		str = newStr;
		size = size+n;
		str[size-1]='\0';

		if (buffer!=NULL)
			delete[] buffer;
	}
	return *this;
}

myString& myString::insert(size_t pos, char ch, size_t n)
{
	if(pos > size)
		throw std::out_of_range("Выход за пределы строки insert char");

	if (n != 0)
	{
		char* newStr = new char[size+n];
		memcpy(newStr, str, pos);
		memset(newStr+pos, ch, n);
		memcpy(newStr+pos+n, str+pos, size-1-pos);
		delete[] str;
		str = newStr;
		size = size+n;
		str[size-1]='\0';
	}
	
	return *this;
}


myString& myString::replace(size_t pos, size_t len, const myString& t)
{
	if (t.empty())
		this->replace(pos, len, "");
	else
		this->replace(pos, len, t.str);
	
	return *this;
}

myString& myString::replace(size_t pos, size_t len, const char* t)
{
	if(pos + len > size)
		throw std::out_of_range("Выход за пределы строки replace char*");

	if (len != 0)
	{
		size_t subLen = strlen(t);	
		
		char* buffer = NULL;
		if (this->isInThis(t))
		{
			buffer = new char[subLen+1];
			memcpy(buffer, t, subLen);
			t = buffer;
		}
		
		if (len != subLen)
		{
			char* newStr = new char[size+subLen-len];
			memcpy(newStr, str, pos);
			memcpy(newStr+subLen+pos,str+pos+len,size-1-pos);
			delete str;
			size += subLen - len;
			str = newStr;
			str[size-1]='\0';
		}
		memcpy(str+pos, t, subLen);
	
		if (buffer!=NULL)
			delete[] buffer;
	}
	else
		this->insert(pos, t);
	return *this;
}

myString& myString::replace(const myString& oldStr, const myString& newStr, size_t maxcount)
{
	if (oldStr.empty())
		throw std::invalid_argument("Нельзая  заменять пустую строку в строке");
	
	return this->replace(oldStr.str, newStr.str, maxcount);
}	

myString& myString::replace(const char* oldStr, const char* newStr, size_t maxcount)
{
	// if (isInThis(newStr))
	// 	throw std::invalid_argument("")
	if (maxcount == 0)
		maxcount = size;

	int newLen = strlen(newStr);
	int oldLen = strlen(oldStr);
	int pos = 0;
	do
	{
		pos = this->find(oldStr, pos, size-1);
		if (pos >= 0)
		{
			this->replace(pos, oldLen, newStr);
			pos+=newLen;
			maxcount--;
		}
	}while(maxcount > 0 && pos >=0 && pos < size-1);
	
	return *this;

}
myString& myString::replace(const char oldCh, const char newCh, size_t maxcount)
{
	if (maxcount == 0)
		maxcount = size;
	int pos = 0;
	do
	{
		pos = this->find(oldCh, pos, size-1);
		if (pos >= 0)
		{
			maxcount--;
			str[pos++] = newCh;
		}
	}while(maxcount > 0 && pos >= 0 && pos < size);
	
	return *this;
}

void myString::swap(myString& other)
{
	myString tmp  = other;
	other.assign(*this);
	this->assign(tmp);
}

int myString::count(const myString& subStr, size_t start, size_t end) const
{
	return this->count(subStr.str, start, end);
}

int myString::count(const char* subStr, size_t start, size_t end) const
{
	if (start >= size || end >= size)
		throw std::out_of_range("Выход за пределы строки cont char*");
	
	// if (*subStr=='\0')
	// 	std::invalid_argument("Поиск пустой строки")
	
	int result = 0;
	
	if (end == 0 && start==0)
		end = strlen(str);
	
	int way = (start<=end)? 1:-1;
	// int subLen = strlen(subStr);
	int pos;
	
	do
	{
		pos = this->find(subStr, start, end);
		// std::cout << "start " << start << " end " << end << " Str " << strAddr() << " result " << result << std::endl;
		if (pos >=0)
		{
			result++;
			start = pos + way;
		}
	} while(pos >= 0);
	return result;
}

int myString::count(const char ch, size_t start, size_t end) const
{
	if (start >= size || end >= size)
		throw std::out_of_range("Выход за пределы строки cont char");

	int result = 0;
	if (end == 0 && start == 0)
		end = strlen(str);
	int way = (start<=end)? 1:-1;
	for (size_t i = start; i != end; i+=way)
		if (str[i] == ch)
			result++;
	return result;
}

int myString::find(const myString& t, size_t start, size_t end) const
{
	return this->find(t.str, start, end);
}

int myString::find(const char* t, size_t start, size_t end) const
{
	if (start >= size || end >= size)
		throw std::out_of_range("Выход за пределы строки find char*");
	if (*t == '\0')
		throw std::invalid_argument("Поиск пустой строки");
	
	if (end == 0 && start == 0)
		end = size-1;
	
	int way = (start<=end)? 1:-1;

	int tLen = strlen(t);
	int tPos = (way>0)? 0:tLen-1;
	int pos = this->find(t[tPos], start, end);
	// std::cout << str << " pos " << pos << " subStr " << t << tPos << std::endl;
	int result = pos;
	if (pos >= 0)
	{
		while (str[pos] == t[tPos] && tLen > 0)
		{
			tLen--;
			pos+=way;
			tPos+=way;
		}
		if (tLen > 0)
			result = myStringErrors::NOT_FAUND;
	}
	return result;
}
int myString::find(const char ch, size_t start, size_t end) const
{
	if (start >= size || end >= size)
		throw std::out_of_range("Выход за пределы строки find char");
	
	int result = myStringErrors::NOT_FAUND;
	if (end == 0 && start == 0)
		end = strlen(str);
	size_t pos = start;
	int way = (start<=end)? 1:-1;
	int tLen = (end-start)*way;
	// std::cout << "find ch sLen " << tLen << " ch " << ch;
	while(str[pos] != ch && tLen > 0)
	{
		pos+=way;
		// std::cout << "find ch sLen " << tLen << " pos " << pos << std::endl;
		tLen--;
	}
	if (tLen > 0)
		result = pos;
	// if (str[end] == ch)
	// 	return end;
	// std::cout << " result " << result << std::endl;
	return result;
}


bool myString::isInThis(const char* p)
{
	return (str <= p && p <= str+size);
}

unsigned int myString::getObjCount()
{
	return objCount;
}