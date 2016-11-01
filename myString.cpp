#include "myString.h"

unsigned int myString::objCount = 0;

myString::myString():str(NULL),size(1),maxSize(0)
{
	reSize(size);
	*str='\0';
	objCount++;
}

myString::myString(const char* tStr, size_t len):str(NULL),size(0),maxSize(0)
{
	if (len==0)
		len = strlen(tStr);
	size = len+1;

	maxSize = (size/myStringConst::minSize+1)*myStringConst::minSize;
	str = new char[maxSize];
	
	memcpy(str, tStr, len);
	str[len] = '\0'; 

	objCount++;
}

myString::myString(const myString &other)
{
	size = other.size;
	maxSize = other.maxSize;
	str = new char[maxSize];
	memcpy(str, other.strAddr(), size);

	objCount++;
}

myString::myString(const myString &tStr, size_t pos, size_t len):str(NULL),size(0),maxSize(0)
{
	if (pos + len < tStr.strSize())
	{
		if (len==0)
			len = tStr.size-pos-1;
		size = len+1;
		maxSize = (size/myStringConst::minSize+1)*myStringConst::minSize;
		str = new char[maxSize];
		memcpy(str, tStr.strAddr()+pos, len);
		str[len] = '\0';
	}
	else
		throw std::out_of_range("Выход за пределы строки construcnor myString size_t size_t");
	objCount++;
}

myString::~myString()
{
	if (str != NULL)
		delete[] str;

	objCount--;
}

size_t myString::strSize() const
{
	return size;
}

// size_t myString::strLenght()
// {}

char* myString::strAddr() const
{
	return str;
}

void myString::clear()
{
	size = 1;
	reSize(size);
	*str = '\0';
}

bool myString::empty() const
{
	return !(*str);
}

size_t myString::copyToCharArray(char* tStr, const size_t n)
{

	if (n == 0)
		return 0;
	if (size == 0)
	{
		*tStr = '\0';
		return 1;
	}
	int copySize;
	if (size < n)
		copySize = size;
	else
		copySize = n;

	memcpy(tStr, str, copySize);
	return copySize;
}

myString& myString::append(const myString& tStr, size_t pos, size_t len)
{	
	if(len == 0)
			len = tStr.strSize() - pos - 1;
	if (pos + len < tStr.strSize())
	{
		return append(tStr.strAddr()+pos, len);
	}
	else
		throw std::out_of_range("Выход за пределы строки append myString");
}

myString& myString::append(const char* tStr, size_t n)
{
	if (n==0)
		n = strlen(tStr);
	char* buffer = NULL;
	if (isInThis(tStr))
	{
		buffer = new char[n];
		memcpy(buffer, tStr, n);
		tStr = buffer;
	}
	size_t p = size-1;
	reSize(size+n);

	memcpy(str+p, tStr, n);
	str[size-1] = '\0';

	if (buffer!=NULL)
		delete[] buffer;
	return *this;
}
myString& myString::append(const char ch)
{
	reSize(size+1);
	*(str+size-2) = ch;
	*(str+size-1) = '\0';
	return *this;
}

myString& myString::assign(const myString& tStr, size_t pos, size_t len)
{
	if(len == 0)
			len = tStr.strSize() - pos - 1;
	if (pos + len < tStr.strSize())
		return assign(tStr.strAddr()+pos, len);
	else
		throw std::out_of_range("Выход за пределы строки assign myString");
}

myString& myString::assign(const char* tStr, size_t n)
{
	if (n == 0)
		n = strlen(tStr);
	n++;
	if (n > maxSize || n < maxSize/2)
	{
		size_t newMax = (n/myStringConst::minSize+1)*myStringConst::minSize;
		char* newStr = new char[newMax];
		delete[] str;
		str = newStr;
		size = n;
		maxSize = newMax;
	}

	char* buffer = NULL;
	if (isInThis(tStr))
	{
		buffer = new char[n];
		memcpy(buffer, tStr, n);
		tStr = buffer;
	}

	memcpy(str, tStr, n-1);
	str[n-1] = '\0';

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
		n++;
		if (n > maxSize || n < maxSize/2)
		{
			size_t newMax = (n/myStringConst::minSize+1)*myStringConst::minSize;
			char* newStr = new char[newMax];
			delete[] str;
			str = newStr;
			maxSize = newMax;
		}
		size = n--;
		memset(str, ch, n);
		str[n] = '\0';
	}
	return *this;
}

myString& myString::insert(size_t pos, const myString& tStr, size_t subPos, size_t subLen)
{
	if(pos > size)
		throw std::out_of_range("Выход за пределы строки insert myString");

	if(subLen == 0)
			subLen = tStr.strSize() - subPos - 1;

	if (subPos + subLen < tStr.strSize())
		return insert(pos, tStr.strAddr()+subPos, subLen);
	else
		throw std::out_of_range("Выход за пределы строки tStr insert myString");

}
myString& myString::insert(size_t pos, const char* tStr, size_t n)
{
	if(pos > size)
		throw std::out_of_range("Выход за пределы строки insert char*");
	if (n==0)
		n = strlen(tStr);
	std::cout << "insert this " << strAddr() << std::endl;
	std::cout << "insert pos " << pos << std::endl;
	std::cout << "insert tStr " << tStr << std::endl;
	std::cout << "insert n " << n << std::endl;
	char* buffer = NULL;
	if (isInThis(tStr))
	{
		buffer = new char[n];
		memcpy(buffer, tStr, n);
		tStr = buffer;
	}

	reSize(size+n);
	memmove(str+pos+n, str+pos, size-pos);
	memcpy(str+pos, tStr, n);
	std::cout << "insert this2 " << strAddr() << std::endl;
	if (buffer!=NULL)
		delete[] buffer;
	return *this;
}
myString& myString::insert(size_t pos, char ch, size_t n)
{
	if(pos > size)
		throw std::out_of_range("Выход за пределы строки insert char");

	if (n!=0)
	{
		reSize(size+n);
		memmove(str+pos+n, str+pos, size-pos);
		memset(str+pos, ch, n);
	}
	return *this;
}

myString& myString::replace(size_t pos, size_t len, const myString& tStr)
{
	if (tStr.empty())
		replace(pos, len, "");
	else
		replace(pos, len, tStr.strAddr());
	return *this;
}

myString& myString::replace(size_t pos, size_t len, const char* newStr)
{
	if(pos + len > size)
		throw std::out_of_range("Выход за пределы строки replace char*");

	size_t subLen = strlen(newStr);
	char* buffer = NULL;
	if (isInThis(newStr))
	{
		buffer = new char[subLen+1];
		memcpy(buffer, newStr, subLen+1);
		newStr = buffer;
	}
	if (len != subLen)
	{
		char* tmpStr = new char[size-len+subLen];
		memcpy(tmpStr, str, pos);
		memcpy(tmpStr+pos+subLen, str+len, size-(pos+len));
		reSize(size-len+subLen);
		memcpy(str, tmpStr, size);
		delete[] tmpStr;
	}
	memcpy(strAddr()+pos, newStr, subLen);
	if (buffer!=NULL)
		delete[] buffer;
	return *this;
}

myString& myString::replace(const myString& oldStr, const myString& newStr, size_t maxcount)
{
	if (oldStr.empty())
		throw std::invalid_argument("Нельзая  заменять пустую строку в строке");
	
	return replace(oldStr.strAddr(), newStr.strAddr(), maxcount);
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
		pos = find(oldStr, pos, size-2);
		if (pos >= 0)
		{
			replace(pos, oldLen, newStr);
			pos += newLen;
			maxcount--;
		}
	}while(maxcount > 0 && pos >=0 && pos < size);
	return *this;

}
myString& myString::replace(const char oldCh, const char newCh, size_t maxcount)
{
	if (maxcount == 0)
		maxcount = size;
	int pos = 0;
	do
	{
		pos = find(oldCh, pos, size-2);
		if (pos >= 0)
		{
			maxcount--;
			str[pos++] = newCh;
		}
	}while(maxcount > 0 && pos >= 0);
	return *this;
}

void myString::swap(myString& tStr)
{
	myString tmp  = tStr;
	tStr.assign(*this);
	this->assign(tmp);
}

int myString::count(const myString& subStr, size_t start, size_t end) const
{
	return count(subStr.strAddr(), start, end);
}

int myString::count(const char* subStr, size_t start, size_t end) const
{
	if (start > size|| end > size)
		throw std::out_of_range("Выход за пределы строки cont char*");
	// if (*subStr=='\0')
	// 	std::invalid_argument("Поиск пустой строки")
	int result = 0;
	if (end == 0)
		end = strlen(str);
	int way = (start<=end)? 1:-1;
	int subLen = strlen(subStr);
	int pos = 0;
	while(pos >= 0)
	{
		pos = find(subStr, start, end);
		// std::cout << "start " << start << " end " << end << " Str " << strAddr() << " result " << result << std::endl;
		if (pos >=0)
		{
			result++;
			start = pos + subLen*way;

		}
	}
	return result;
}

int myString::count(const char ch, size_t start, size_t end) const
{
	if (start > size || end > size)
		throw std::out_of_range("Выход за пределы строки cont char");

	int result = 0;
	if (end == 0)
		end = strlen(str);
	int way = (start<=end)? 1:-1;
	for (size_t i = start; i != end; i+=way)
		if (str[i] == ch)
			result++;
	return result;
}

int myString::find(const myString& subStr, size_t start, size_t end) const
{

	return find(subStr.strAddr(), start, end);
}

int myString::find(const char* subStr, size_t start, size_t end) const
{
	if (start > size || end > size)
		throw std::out_of_range("Выход за пределы строки find char*");
	if (*subStr == '\0')
		throw std::invalid_argument("Поиск пустой строки");
	if (end == 0)
		end = strlen(str);
	
	int way = (start<=end)? 1:-1;

	int subLen = strlen(subStr);
	int subPos = (way>0)? 0:subLen-1;
	int pos = find(subStr[subPos], start, end);
	// std::cout << "pos " << pos << " subStr " << subStr << std::endl;
	int result = pos;
	if (pos >= 0)
	{
		while (str[pos] == subStr[subPos] && subLen > 0)
		{
			subLen--;
			pos+=way;
			subPos+=way;
		}
		if (subLen > 0)
			result = myStringErrors::NOT_FAUND;
	}
	return result;
}
int myString::find(const char ch, size_t start, size_t end) const
{
	if (start > size || end > size)
		throw std::out_of_range("Выход за пределы строки find char");
	
	if (end == 0)
		end = strlen(str);
	size_t pos = start;
	int way = (start<=end)? 1:-1;
	int subLen = (end-start)*way;
	while(str[pos] != ch && subLen > 0)
	{
		pos+=way;
		// std::cout << "find ch sLen " << subLen << std::endl;
		subLen--;
	}
	if (subLen > 0)
		return pos;
	// if (str[end] == ch)
	// 	return end;

	return myStringErrors::NOT_FAUND;
}

char* myString::reSize(size_t newSize)
{
	if (newSize > maxSize || newSize < maxSize/2)
	{
		size_t newMax = (newSize/myStringConst::minSize+1)*myStringConst::minSize;
		char* newStr = new char[newMax];
		memcpy(newStr, str, newSize);
		delete[] str;
		str = newStr;
		size = newSize;
		maxSize = newMax;
	}
	else
		size = newSize;
	return str;
}

bool myString::isInThis(const char* p)
{
	return (strAddr() <= p && strAddr()+size >= p);
}

unsigned int myString::getObjCount()
{
	return objCount;
}