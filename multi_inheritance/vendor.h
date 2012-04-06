#ifndef VENDOR_H
#define VENDOR_H

class Vendor
{
public:
	virtual void v() const;
	void f() const;
	~Vendor();
};

class Vendor1 : public Vendor
{
public:
	void v() const;
	void f() const;
	~Vendor1();
};

void A(const Vendor&);
void B(const Vendor&);
#endif //VENDOR_H
