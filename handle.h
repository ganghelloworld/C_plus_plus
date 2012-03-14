#ifndef HANDLE_H
#define HANDLE_H

class Handle
{
	struct Cheshire;
	Cheshire* smile;
	
public:
	void initialize();
	void cleanup();
	int read();
	void change(int);
	void print();
	
	int read_num;
};

#endif
