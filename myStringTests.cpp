#include <cxxtest/TestSuite.h>
#include "myString.h"
#include <cstring>
#include <stdexcept>	// out_of_range(), invalid_argument()

const char testStr[] = "Test string";

class myStringTests : public CxxTest::TestSuite
{
public:
	void testDefaultConstructor(void)
	{
		
		myString t;
		TS_ASSERT_EQUALS(t.getSize(), 1);
		TS_ASSERT(t.getAddr());
		TS_ASSERT_EQUALS(*(t.getAddr()), '\0');
	}
	
	void testFromCharsArrayConstructor(void)
	{
		myString t1(testStr);
		TS_ASSERT_EQUALS(t1.getSize(), strlen(testStr)+1);
		TS_ASSERT_SAME_DATA(t1.getAddr(), testStr, t1.getSize());

		myString t2(testStr, 6);
		TS_ASSERT_EQUALS(t2.getSize(), 6+1);
		TS_ASSERT_SAME_DATA(t2.getAddr(), testStr, t2.getSize()-1);

	}

	void testCopyConstructor(void)
	{
		myString t1(testStr);
		myString t2 = t1;
		TS_ASSERT_EQUALS(t2.getSize(), t1.getSize());
		TS_ASSERT_SAME_DATA(t2.getAddr(), t1.getAddr(), t2.getSize());
		TS_ASSERT_DIFFERS(t2.getAddr(), t1.getAddr());
	}

	void testFromMyStringconstructor(void)
	{
		myString src(testStr);
		myString t(src, 2, 6);

		TS_ASSERT_EQUALS(t.getSize(), 6+1);
		TS_ASSERT_SAME_DATA(t.getAddr(), src.getAddr()+2, 6);
		TS_ASSERT_DIFFERS(t.getAddr(), src.getAddr());	

		// out_of_rage
	}	

	void testMyStringClear(void)
	{
		myString t(testStr);
		t.clear();

		TS_ASSERT_EQUALS(t.getSize(), 1);
		TS_ASSERT_EQUALS(*(t.getAddr()), '\0');
	}

	void testMyStringAppendCharArray(void)
	{
		char s1[] = "AsD";
		char s2[] = "FgH";
		char chekStr1[] = "AsDFgH";
		char chekStr2[] = "AsDAs";
		myString t1(s1);
		t1.append(s2);
		TS_ASSERT_EQUALS(t1.getSize(), strlen(chekStr1)+1);
		TS_ASSERT_SAME_DATA(t1.getAddr(), chekStr1, t1.getSize()-1);

		myString t2(s1);
		t2.append(t2.getAddr(),2);
		TS_ASSERT_EQUALS(t2.getSize(), strlen(chekStr2)+1);
		TS_ASSERT_SAME_DATA(t2.getAddr(), chekStr2, t2.getSize()-1);
	}

	void testMyStringAppendMyString(void)
	{
		myString t1 = "AsD";
		char chekStr1[] = "AsDsD";
		TS_ASSERT_THROWS(t1.append(t1, 3, 1), std::out_of_range);
		
		t1.append(t1, 1, 2);
		TS_ASSERT_EQUALS(t1.getSize(), strlen(chekStr1)+1);
		TS_ASSERT_SAME_DATA(t1.getAddr(), chekStr1, t1.getSize()-1);
	}

	void testMyStringAppendChar(void)
	{
		myString t = "ASDF";
		char ch = 'z';
		char chekStr[] = "ASDFz";
		
		t.append(ch);
		TS_ASSERT_EQUALS(t.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(t.getAddr(), chekStr, t.getSize()-1);
		
	}

	void testMyStringAssignCharArray(void)
	{
		char s1[] = "AsD";
		char s2[] = "FgH";
		char chekStr1[] = "FgH";
		char chekStr2[] = "As";
		
		myString t1(s1);
		t1.assign(s2);
		TS_ASSERT_EQUALS(t1.getSize(), strlen(chekStr1)+1);
		TS_ASSERT_SAME_DATA(t1.getAddr(), chekStr1, t1.getSize()-1);

		myString t2(s1);
		t2.assign(t2.getAddr(),2);
		TS_ASSERT_EQUALS(t2.getSize(), strlen(chekStr2)+1);
		TS_ASSERT_SAME_DATA(t2.getAddr(), chekStr2, t2.getSize()-1);
	}

	void testMyStringAssignMyString(void)
	{
		myString t1 = "AsD";
		char chekStr1[] = "sD";
		TS_ASSERT_THROWS(t1.assign(t1, 3, 1), std::out_of_range);
		
		t1.assign(t1, 1, 2);
		TS_ASSERT_EQUALS(t1.getSize(), strlen(chekStr1)+1);
		TS_ASSERT_SAME_DATA(t1.getAddr(), chekStr1, t1.getSize()-1);
	}

	void testMyStringAssignChar(void)
	{
		myString t = "ASDF";
		t.assign('A', 0);
		TS_ASSERT(t.empty());

		char chekStr[] = "AAAA";
		t.assign(chekStr[0], strlen(chekStr));
		TS_ASSERT_EQUALS(t.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(t.getAddr(), chekStr, t.getSize()-1);
	}

	void testMyStringInsertMyString(void)
	{
		myString t = "AsD";
		char chekStr[] = "ADsD";
		TS_ASSERT_THROWS(t.insert(1, t, 3, 1), std::out_of_range);
		
		t.insert(1, t, 2, 1);
		TS_ASSERT_EQUALS(t.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(t.getAddr(), chekStr, t.getSize()-1);	
	}

	void testMyStringInsertCharArray(void)
	{
		myString t = "ASDF";
		TS_ASSERT_THROWS(t.insert(7, "Z"), std::out_of_range);

		char chekStr[] = "ASQWERDF";
		t.insert(2, "QWER");
		TS_ASSERT_EQUALS(t.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(t.getAddr(), chekStr, t.getSize()-1);
	}

	void testMyStringInsertChar(void)
	{
		myString t = "ASDF";
		TS_ASSERT_THROWS(t.insert(7, 'Z'), std::out_of_range);

		char chekStr[] = "ASQQQDF";
		t.insert(2, chekStr[2], 3);
		TS_ASSERT_EQUALS(t.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(t.getAddr(), chekStr, t.getSize()-1);
	}

	void testMyStringReplaceMySrting(void)
	{
		myString t = "ABCD";
		myString r1;
		myString r2 = "ZXCV";

		char chekStr[] = "AD";
		t.replace(1, 2, r1);
		TS_ASSERT_EQUALS(t.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(t.getAddr(), chekStr, t.getSize()-1);

		char chekStr1[] = "AZXCV";
		t.replace(1, 1, r2);
		TS_ASSERT_EQUALS(t.getSize(), strlen(chekStr1)+1);
		TS_ASSERT_SAME_DATA(t.getAddr(), chekStr1, t.getSize()-1);
	}

	void testMyStringReplaceCharArray(void)
	{
		myString t = "ASDF";
		TS_ASSERT_THROWS(t.replace(3, 3, "Z"), std::out_of_range);

		char r1[] = "ZXCV";
		char chekStr[] = "ZXCVDF";
		t.replace(0, 2, r1);
		TS_ASSERT_EQUALS(t.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(t.getAddr(), chekStr, t.getSize()-1);
	}

	void testMyStringReplaceMySrtingMyString(void)
	{
		TS_TRACE("Testing myString.replace(myString, myString, size_t)");
		myString testStr = "ASDFGHJ";
		myString newStr = "ZXC";
		myString oldStr;
		oldStr.clear();
		char chekStr[] = "ZXCDFGHJ";

		TS_TRACE("Cheking exeptions...");
		TS_ASSERT_THROWS(testStr.replace(oldStr, newStr), std::invalid_argument);

		TS_ASSERT_THROWS_NOTHING(oldStr.assign("AS"));
		TS_ASSERT_THROWS_NOTHING(testStr.replace(oldStr, newStr, 1));
		TS_TRACE("Cheking metod...");
		TS_ASSERT_EQUALS(testStr.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(testStr.getAddr(), chekStr, testStr.getSize()-1);
	}

	void testMyStringReplaceCharArrayCharArray(void)
	{
		myString testStr = "ASASASASASAS";
		TS_ASSERT_THROWS(testStr.replace("", "newStr"), std::invalid_argument);		

		TS_ASSERT_THROWS_NOTHING(testStr.replace("AS", "ZX"));
		const char* chekStr = "ZXZXZXZXZXZX";
		TS_ASSERT_EQUALS(testStr.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(testStr.getAddr(), chekStr, testStr.getSize());

		TS_ASSERT_THROWS_NOTHING(testStr.replace("ZX", "AS", 3));
		chekStr = "ASASASZXZXZX";
		TS_ASSERT_EQUALS(testStr.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(testStr.getAddr(), chekStr, testStr.getSize());

		TS_ASSERT_THROWS_NOTHING(testStr.replace("ZXC", "AS"));
		chekStr = "ASASASZXZXZX";
		TS_ASSERT_EQUALS(testStr.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(testStr.getAddr(), chekStr, testStr.getSize());
	}

	void testMyStringReplaceCharChar(void)
	{
		myString testStr = "ASASASASASAS";

		TS_ASSERT_THROWS_NOTHING(testStr.replace('S', 'D'));
		const char* chekStr = "ADADADADADAD";
		TS_ASSERT_EQUALS(testStr.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(testStr.getAddr(), chekStr, testStr.getSize());

		TS_ASSERT_THROWS_NOTHING(testStr.replace('A', 'F', 3));
		chekStr = "FDFDFDADADAD";
		TS_ASSERT_EQUALS(testStr.getSize(), strlen(chekStr)+1);
		TS_ASSERT_SAME_DATA(testStr.getAddr(), chekStr, testStr.getSize());
	}

	void testMyStringSwap(void)
	{
		char chekStr1[] = "QWER";
		char chekStr2[] = "ASDFGHJK";

		myString t1(chekStr1);
		myString t2(chekStr2);

		t1.swap(t2);

		TS_ASSERT_EQUALS(t1.getSize(), strlen(chekStr2)+1);
		TS_ASSERT_SAME_DATA(t1.getAddr(), chekStr2, t1.getSize());

		TS_ASSERT_EQUALS(t2.getSize(), strlen(chekStr1)+1);
		TS_ASSERT_SAME_DATA(t2.getAddr(), chekStr1, t2.getSize());
	}

	void testMyStringCountMyString(void)
	{}

	void testMyStringCountCharArray(void)
	{
		myString testStr("ASDFASDF");

		TS_ASSERT_THROWS(testStr.count("'A'", testStr.getSize(), 0), std::out_of_range);
		TS_ASSERT_THROWS(testStr.count("'A'", 0, testStr.getSize()), std::out_of_range);

		TS_ASSERT_EQUALS(testStr.count("DS"), 0);
		TS_ASSERT_EQUALS(testStr.count("AS"), 2)
		TS_ASSERT_EQUALS(testStr.count("SD", testStr.getSize()-1, 3), 1);

		testStr.assign("AAAA");
		TS_ASSERT_EQUALS(testStr.count("AA"), 3);
	}

	void testMyStringCountChar(void)
	{
		myString testStr("ASDFASDF");

		TS_ASSERT_THROWS(testStr.count('A', testStr.getSize(), 0), std::out_of_range);
		TS_ASSERT_THROWS(testStr.count('A', 0, testStr.getSize()), std::out_of_range);

		TS_ASSERT_EQUALS(testStr.count('Q'), 0);
		TS_ASSERT_EQUALS(testStr.count('S'), 2)
		TS_ASSERT_EQUALS(testStr.count('D', testStr.getSize()-1, 3), 1);

	}

	void testMyStringFindMyString(void)
	{}

	void testMyStringFindCharArray(void)
	{
		TS_TRACE("Testing myString.find(char*, size_t, size_t)");
		myString testStr("ASDFASDF");

		TS_ASSERT_THROWS(testStr.find("'A'", testStr.getSize(), 0), std::out_of_range);
		TS_ASSERT_THROWS(testStr.find("'A'", 0, testStr.getSize()), std::out_of_range);
		TS_ASSERT_THROWS(testStr.find(""), std::invalid_argument);

		TS_ASSERT_EQUALS(testStr.find("SD"), 1);
		TS_ASSERT_EQUALS(testStr.find("DS"), -1);
		TS_ASSERT_EQUALS(testStr.find("SD", testStr.getSize()-1, 0), 6);

	}

	void testMyStringFindChar(void)
	{
		TS_TRACE("Testing myString.find(char, size_t, size_t)");
		myString testStr("ASDFASDF");

		TS_ASSERT_THROWS(testStr.find('A', testStr.getSize(), 0), std::out_of_range);
		TS_ASSERT_THROWS(testStr.find('A', 0, testStr.getSize()), std::out_of_range);

		TS_ASSERT_EQUALS(testStr.find('S'), 1);
		TS_ASSERT_EQUALS(testStr.find('S', 2, 4), -1);
		TS_ASSERT_EQUALS(testStr.find('D', testStr.getSize()-1, 0), 6);
	}
};
