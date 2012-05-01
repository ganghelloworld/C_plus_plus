#ifndef BASIC_H
#define BASIC_H

#include <string>

class Basic
{
public:
	static int a;
	static std::string s;
	static const int b = 1;
	static int c;
};

namespace Tag
{
	class Y{
	public:
		static int i;
	};

	static const int a = 3;
	static const std::string s = "gang";
}
#endif //BASIC_H
