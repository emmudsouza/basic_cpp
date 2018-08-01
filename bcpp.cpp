#include <iostream>
#include <memory>
#include <string>

using namespace std;

template <typename T>	//Template to use same function for differnt input types of variables
void LOG (T var)
{
	cout << var << endl;
}

struct demoStruct
{
	int var;
	demoStruct(int t) :var(t)
	{
		LOG("struct:constructor");
		LOG(var);
	}
	~demoStruct()
	{
		LOG("struct:destructor");
	}
};

class demoClass
{
private:
	int A, B, R;

public:
	demoClass(int a, int b) : A(a), B(b)
	{
		LOG("class:constructor");
	}

	int add()
	{
		R = A + B;
		return R;
	}

	~demoClass()
	{
		LOG("class:destructor");
	}
};

void POINTER()
{
	//STORED ON THE STACK
	int var = 5;
	int *ptr = NULL;
	ptr = &var;     //address of var is stored in ptr
	cout << "Address=>" << ptr << " / Data=>" << *ptr << endl;

	//STRORED ON THE HEAP
	int *buf = new int();
	*buf = var;     //buf is dereferenced and var is stored at the address of buf
	cout << "Address=>" << buf << " / Data=>" << *buf << endl;
	delete buf;
	cout << "after delete => " << *buf << endl;

	demoStruct *dbuf = new demoStruct(77);
	cout << "Address=>" << dbuf << " / Data=>" << dbuf->var << endl;
}

void SMART_POINTER()	//Automates new/delete, prevents memory leaks, not copable
{
	unique_ptr<int> ptr1;	//Empty Unique pointer
	if (ptr1 == nullptr)
	{
		LOG("Pointer in empty");
	}
	unique_ptr<int> ptr2(new int(10));	//Pointer object
	ptr1.reset();	//Reset pointer
	unique_ptr<int> ptr3 = move(ptr2);	
	LOG(*ptr3);	//Dereference pointer
	unique_ptr<demoStruct> ptr4(new demoStruct(33));
	LOG(ptr4->var);
}

void REFERENCE()
{
	int a = 5;
	int& ref = a;
	ref = 3;
	LOG(ref);
}

void CLASS()
{
	demoClass C(10, 20);
	LOG(C.add());
}

int main()
{
	LOG("\nPOINTER**************************************************\n");
	POINTER();
	LOG("\nSMART_POINTER********************************************\n");
	SMART_POINTER();
	LOG("\nREFERENCE************************************************\n");
	REFERENCE();
	LOG("\nCLASS****************************************************\n");
	CLASS();
	return 0;
