此文件内测试一些C++中比较微妙的语法问题
======================================


引用若想引用数组变量，应该如何做
--------------------------------

	int test[10] = {0, 1, 2}; 
	int (&ref_test)[10] = test; //此种方法会把test和ref_test变得很像，也就是sizeof(test) = sizeof(ref_test) = 40
	cout << ref_test[4] << endl;
	int* const& p_test = test; //指针的引用
	cout << *(p_test + 3) << endl;

拷贝构造函数的参数最好为const
-----------------------------
要不然如果想用临时变量初始化一个类，在链接时会出现问题，因为临时变量是const的

默认函数的参数赋值
------------------
只能出现在函数申明，或者是函数的申明加定义中。反之，如果只是函数的定义，加默认参数的不对的样

	1.  void Test::func(int a, int i = 0); //OK 仅申明

	2.	void Test::func(int a, int i = 0) //OK 申明加定义
		{
		}

	3.  void Test::func(int a, int i = 0); //OK 仅申明
		void Test::func(int a, int i = 0) //ERROR 已有申明,仅定义
		{
		}

two_dim_array.cpp
-----------------
测试了动态二维数组的new及delete

测试了delete数组
-----------------
只能整个delete, 如delete []test, 如果

	delete &test[0]
	
会引起段错误 

	delete &test[i]

i > 0 会引起异常, 打印如下信息摘录*** glibc detected *** ./a.out: free(): invalid pointer: 0x0999800e *** 

类成员变量如果是const
---------------------

1.则只有一种初始化方式，在构造函数的初始化列表中为const赋值

2.用const int Test::a = 10,这种是错的，

3.直接在类申明里面赋值也是错的

4.在构造函数里面赋值也是错的Test(){a = 10}

函数定义时后面加不加";"都行的
----------------------------
gcc,g++都可以通过
