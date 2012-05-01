#ifndef STACK_H
#define STACK_H

class Stack
{
	struct Link
	{
		void *data;
		Link *next;
		Link(void *dat, Link *nex) : data(dat), next(nex){};
	}* head;
public:
	Stack() : head(0)
	{}
	~Stack()
	{
		if(head != 0);
	}
	void push(void *dat)
	{
		head = new Link(dat, head);
	}
	void *peek() const
	{
		return head ? head->data : 0;
	}
	void *pop()
	{
		if(head == 0) return 0;
		void *result = head->data;
		Link * old_head = head;
		head = head->next;
		delete old_head;
		return result;
	}
};

#endif
