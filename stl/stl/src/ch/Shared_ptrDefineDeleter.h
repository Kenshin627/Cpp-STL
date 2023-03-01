#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <functional>

class Person
{
public:
	Person(const std::string& name, int age) :name(name), age(age) {}
	~Person()
	{
		std::cout << "delete person:" << name << std::endl;
	}
	const std::string & getName() const
	{
		return name;
	}
private:
	std::string name;
	int age;
};

int main()
{
	/**�Զ���shared_ptr��ɾ����*/
	std::shared_ptr<std::string> pNOCI(new std::string("nico"), [](std::string* p) {
		std::cout << "delete " << *p << std::endl;
		delete p;
		});
	pNOCI = nullptr;

	/**weak_ptr*/
	std::shared_ptr<Person> sp{ new Person{"xiaoming", 18} };
	std::weak_ptr<Person> wp{ sp };

	/**����weak_ptrָ�������*/
	std::cout << wp.lock()->getName() << std::endl;

	/**���weak_ptr������ָ���Ƿ���ʧЧ*/
	std::shared_ptr<std::string> sp1(new std::string("hola"));
	std::weak_ptr<std::string> wp1{ sp1 };
	sp1.reset();
	/**1. use_count*/
	std::cout << wp1.use_count() << std::endl;

	/**2. expired*/
	std::cout << wp1.expired() << std::endl;
	

	/**����ʱ���󣺶�ͬһ��ָ����delete*/
	//int* pp = new int;
	//std::shared_ptr<int> sp2(pp);
	//std::shared_ptr<int> sp3(pp);

	//std::enable_shared_from_this<Person>;

	/**��ȡɾ����*/
	auto deleter = [](int* p) {delete p;  };
	std::shared_ptr<int> ip{ new int(32), deleter };
	auto del = std::get_deleter<decltype(deleter)>(ip);
	std::cout << del << std::endl;

	/**ת��unique_ptr������Ȩ*/

	/**1. std::move*/
	std::unique_ptr<std::string> up1{ new std::string("hola") };
	std::unique_ptr<std::string> up2{ std::move(up1) };
	//std::cout << *up1.get() << std::endl;
	std::cout << *up2.get() << std::endl;

	/**2. release set*/
	std::unique_ptr<std::string> up3{ new std::string("hello") };
	std::unique_ptr<std::string> up4;
	up4.reset(up3.release());
	std::cout << *up4 << std::endl;

	/**unique_ptr��������*/
	std::unique_ptr<std::string[]> up5{ new std::string[10] };
	/**����汾��unique_ptrû��*��->������������ṩ��[]*/
	up5[0] = "hola";

	/**unuque_ptr�Զ���ɾ����*/
	std::function<void(int*)> deleter2 = [](int* p) { 
		delete[] p; 
		std::cout << "delete array int" << std::endl;
	};
	std::unique_ptr<int, std::function<void(int*)>> up6{ new int[19], deleter2 };
	up6.get_deleter();
	up6.reset();
}