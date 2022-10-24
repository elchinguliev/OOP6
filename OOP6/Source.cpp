#include<iostream>
#include <assert.h>
using namespace std;

class Computer {

	static int staticID;
	int id;
	char* vendor;
	char* model;
	char* videocard;
	char* monitor;
	double cpuhz;
	int core;
	int ram;
	int discsize;
	bool isSSD;

public:

	void SetVendor(const char* value) {
		delete[]vendor;
		int len = strlen(value) + 1;
		vendor = new char[len];
		strcpy_s(vendor, len, value);
	}

	void SetModel(const char* value) {
		delete[]model;
		int len = strlen(value) + 1;
		model = new char[len];
		strcpy_s(model, len, value);
	}

	void SetVideoCard(const char* value) {
		delete[]videocard;
		int len = strlen(value) + 1;
		videocard = new char[len];
		strcpy_s(videocard, len, value);
	}

	void SetMonitor(const char* value) {
		delete[]monitor;
		int len = strlen(value) + 1;
		monitor = new char[len];
		strcpy_s(monitor, len, value);
	}

	void SetCpuHz(double value) {
		cpuhz = value;
	}

	void SetCore(int value) {
		core = value;
	}

	void SetRam(int value) {
		ram = value;
	}

	void SetDiscSize(int value) {
		discsize = value;
	}

	void SetisSSD(bool value) {
		isSSD = value;
	}

	int GetId()const {
		return this->id;
	}

	const char* GetVendor()const {
		return this->vendor;
	}

	const char* GetModel()const {
		return this->model;
	}

	const char* GetVideoCard()const {
		return this->videocard;
	}

	const char* GetMonitor()const {
		return this->monitor;
	}

	double GetCpuHz()const {
		return this->cpuhz;
	}

	int GetCore()const {
		return this->core;
	}

	int GetRam()const {
		return this->ram;
	}

	int GetDiscSize()const {
		return this->discsize;
	}

	bool GetisSSD()const {
		return this->isSSD;
	}

	Computer() {

		id = staticID++;
		vendor = nullptr;
		model = nullptr;
		videocard = nullptr;
		monitor = nullptr;
		SetCpuHz(0);
		SetCore(0);
		SetRam(0);
		SetDiscSize(0);
		SetisSSD(0);

	}

	Computer(const char* vendor, const char* model, const char* videocard, const char* monitor, double cpuhz, int core, int ram, int discsize, bool isSSD) {

		id = staticID++;
		SetVendor(vendor);
		SetModel(model);
		SetVideoCard(videocard);
		SetMonitor(monitor);
		SetCpuHz(cpuhz);
		SetCore(core);
		SetRam(ram);
		SetDiscSize(discsize);
		SetisSSD(isSSD);

	}

	Computer(const Computer& other) {

		id = other.id;
		SetVendor(other.vendor);
		SetModel(other.model);
		SetVideoCard(other.videocard);
		SetMonitor(other.monitor);
		SetCpuHz(other.cpuhz);
		SetCore(other.core);
		SetRam(other.ram);
		SetDiscSize(other.discsize);
		SetisSSD(other.isSSD);

	}

	Computer& operator=(const Computer& other) {

		SetVendor(other.vendor);
		SetModel(other.model);
		SetVideoCard(other.videocard);
		SetMonitor(other.monitor);
		SetCpuHz(other.cpuhz);
		SetCore(other.core);
		SetRam(other.ram);
		SetDiscSize(other.discsize);
		SetisSSD(other.isSSD);
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Computer& comp) {
		out << "Computer Information" << endl;
		out << "Object Id : " << comp.id << endl;
		out << "Vendor : " << comp.vendor << endl;
		out << "Model : " << comp.model << endl;
		out << "Monitor : " << comp.monitor << endl;
		out << "Cpu Hz : " << comp.cpuhz << endl;
		out << "Core : " << comp.core << endl;
		out << "Ram : " << comp.ram << endl;
		out << "Disc Size : " << comp.discsize << endl;
		out << "is SSD : " << comp.isSSD << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Computer& comp) {

		char* buffer = new char[100];
		cout << "Model : ";
		in.getline(buffer, 100);
		comp.SetModel(buffer);

		cout << "Vendor : ";
		in.getline(buffer, 100);
		comp.SetVendor(buffer);

		cout << "VideoCard : ";
		in.getline(buffer, 100);
		comp.SetVideoCard(buffer);

		cout << "Monitor : ";
		in.getline(buffer, 100);
		comp.SetMonitor(buffer);

		cout << "Cpu Hz : ";
		double cpu;
		cin >> cpu;
		comp.SetCpuHz(cpu);

		cout << "Core : ";
		int c;
		cin >> c;
		comp.SetCore(c);

		cout << "Ram : ";
		int r;
		cin >> r;
		comp.SetRam(r);

		cout << "Disc Size : ";
		int ds;
		cin >> ds;
		comp.SetDiscSize(ds);

		cout << "is SSD ? :";
		int is;
		cin >> is;
		comp.SetisSSD(is);

		delete[]buffer;
		return in;
	}

	~Computer() {
		delete[]vendor;
		delete[]model;
		delete[]videocard;
		delete[]monitor;
	}


};
int Computer::staticID;

class ComputerStore {

	char* name;
	char* address;
	Computer** computers;
	int count;

public:

	ComputerStore(const char* name, const char* add) {
		SetName(name);
		SetAddress(add);
		computers = nullptr;
		count = 0;
	}

	void SetName(const char* value) {
		delete[]name;
		int len = strlen(value) + 1;
		name = new char[len];
		strcpy_s(name, len, value);
	}

	void SetAddress(const char* value) {
		delete[]address;
		int len = strlen(value) + 1;
		address = new char[len];
		strcpy_s(address, len, value);
	}

	const char* GetName()const {
		return this->name;
	}

	const char* GetAddress()const {
		return this->address;
	}

	void AddComputer(const Computer* value) {
		Computer** temp = new Computer * [count + 1];
		for (size_t i = 0; i < count; i++)
			temp[i] = computers[i];
		temp[count] = new Computer;
		*temp[count] = *value;
		delete[]computers;
		computers = temp;
		count++;
		temp = nullptr;

	}

	void DeleteComputer(int id) {
		int index = -1;
		for (size_t i = 0; i < count; i++)
		{
			if (computers[i]->GetId() == id) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			Computer** temp = new Computer * [count - 1];
			for (size_t i = 0; i < index; i++)
			{
				temp[i] = computers[i];
			}
			for (size_t i = index; i < count; i++)
			{
				temp[i] = computers[i + 1];
			}
			delete[]computers;
			computers = temp;
			count--;
			temp = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const ComputerStore& obj) {
		out << obj.name << endl;
		out << obj.address << endl;
		for (size_t i = 0; i < obj.count; i++)
		{
			cout << *obj.computers[i] << endl;
		}
		return out;
	}

	~ComputerStore() {
		for (size_t i = 0; i < count; i++)
			delete computers[i];
		delete[]computers;


	}

};


void main() {
	ComputerStore store("World telecom", "Akhmedli");
	store.AddComputer(new Computer("asus", "zenbook pro duo", "gforce rtx 1050ti", "QLED", 2.8, 16, 64, 1024, true));
	store.AddComputer(new Computer("asus", "zenbook pro", "gforce gtx 1050ti", "QLED", 2.8, 8, 16, 512, true));
	cout << store << endl;


}
