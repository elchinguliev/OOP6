#include<iostream>
using namespace std;



class Computer {
	static int staticId;
	int objectId;
	char* model;
	char* vendor;
	char* videoCard;
	char* monitor;
	double cpuHz;
	int core;
	int ram;
	int discSize;
	bool isSSD=false;
public:
	static int staticId;

	Computer() {
		objectId = staticId++;
		model=(nullptr);
		vendor=(nullptr);
		videoCard=(nullptr);
		monitor=(nullptr);
		SetCpuHz(0);
		SetCore(0);
		SetRam(0);
		SetDiscSize(0);
		SetIsSdd(0);
	}

	Computer(const Computer& other) {
		objectId = other.objectId;
		SetId(other.staticId);
		SetModel(other.model);
		SetVendor(other.vendor);
		SetVideoCard(other.videoCard);
		SetMonitor(other.monitor);
		SetCpuHz(other.cpuHz);
		SetCore(other.core);
		SetRam(other.ram);
		SetDiscSize(other.discSize);
		SetIsSdd(other.isSSD);
	}
	Computer(int staticId, const char* model, const char* vendor, const char* videoCard, const char* monitor, double cpuHz, int core, int ram, int discSize, bool isSSD) {
		SetId(staticId);
		SetModel(model);
		SetVendor(vendor);
		SetVideoCard(videoCard);
		SetMonitor(monitor);
		SetCpuHz(cpuHz);
		SetCore(core);
		SetRam(ram);
		SetDiscSize(discSize);
		SetIsSdd(isSSD);
		objectId = staticId++;
	}

	Computer& operator=(const Computer& other) {
		SetId(other.staticId);
		SetModel(other.model);
		SetVendor(other.vendor);
		SetVideoCard(other.videoCard);
		SetMonitor(other.monitor);
		SetCpuHz(other.cpuHz);
		SetCore(other.core);
		SetRam(other.ram);
		SetDiscSize(other.discSize);
		SetIsSdd(other.isSSD);
		return*this;
	}

	friend ostream& operator<<(ostream out, const Computer& other) {
		out << "===================COMPUTER INFO==================  " << endl;
		out << "OBject ID : " << other.objectId;
		out << "Model : " << other.model;
		out << "Vendor : " << other.vendor;
		out << "Video Card : " << other.videoCard;
		out << "Monitor : " << other.monitor;
		out << "Cpu hz : " << other.cpuHz;
		out << "Core : " << other.core;
		out << "Ram : " << other.ram;
		out << "Disc size : " << other.discSize;
		out << "Is SSD : " << other.isSSD;
		return out;

	}
	friend istream& operator<<(istream in, Computer& other) {
		char* bf = new char[100] {};
		cout << "Model : ";
		in.getline(bf, 100);
		other.SetModel(bf);

		cout << "Vendor : ";
		in.getline(bf, 100);
		other.SetVendor(bf);

		cout << "Video card : ";
		in.getline(bf, 100);
		other.SetVideoCard(bf);

		cout << "Moniotr : ";
		in.getline(bf, 100);
		other.SetMonitor(bf);

		cout << "Cpu hz : ";
		double y;
		cin >> y;
		other.SetCpuHz(y);

		cout << "Core : ";
		int c;
		cin >> c;
		other.SetCore(c);

		cout << "Ram : ";
		int r;
		cin >> r;
		other.SetRam(r);

		cout << "Disc size  : ";
		int ds;
		cin >> ds;
		other.SetDiscSize(ds);

		cout << "Is SSD or NOT? (1-Yes, 0-No)";
		int ssd;
		cin >> ssd;
		other.SetIsSdd(ssd);

		delete[]bf;
		return in;
	}

	void SetId(int & staticId) {
		
		this->staticId = staticId;
	}
	void SetModel(const char* model) {
		int l = strlen(model);
		this->model = new char[l + 1] {};
		strcpy_s(this->model, l + 1, model);

	}
	void SetVendor(const char* vendor) {
		int l = strlen(vendor);
		this->vendor = new char[l + 1] {};
		strcpy_s(this->vendor, l + 1, vendor);
	}
	void SetVideoCard(const char* videoCard) {
		int l = strlen(videoCard);
		this->videoCard = new char[l + 1] {};
		strcpy_s(this->videoCard, l + 1, videoCard);
	}
	void SetMonitor(const char* monitor) {
		int l = strlen(monitor);
		this->monitor = new char[l + 1] {};
		strcpy_s(this->monitor, l + 1, monitor);
	}
	void SetCpuHz(const double& cpuHz) {
		this->cpuHz = cpuHz;
	}
	void SetCore(const int& core) {
		this->core = core;
	}
	void SetRam(const int& ram) {
		this->ram = ram;
	}
	void SetDiscSize(const int& discSize) {
		this->discSize = discSize;
	}
	void SetIsSdd(const bool isSSD) {
		this->isSSD = isSSD;
	}
	int GetObjectId()const {
		return objectId;
	}
	char* GetModel()const {
		return model;
	}
	char* GetVendor()const {
		return vendor;
	}
	char* GetVideoCard()const {
		return videoCard;
	}
	char* GetMonitor()const {
		return monitor;
	}
	double GetCpuHz()const {
		return cpuHz;
	}
	int GetCore()const {
		return core;
	}
	int GetRam()const {
		return ram;
	}
	int GetDiscSize()const {
		return discSize;
	}
	bool GetSdd()const {
		return isSSD;
	};



	~Computer() {
		delete[]model;
		delete[]vendor;
		delete[]videoCard;
		delete[]monitor;
	}
};
int Computer::staticId = 0;



class ComputerStore {
	char* storeName;
	char* storeAddress;
	int count = 0;
	Computer** computers;
	
public:

	ComputerStore( char* storeName, char* storeAddress) {
		SetStoreName(storeName);
		StoreAdress(storeAddress);
		computers = nullptr;
		count = 0;
	}


	void SetStoreName(const char* storeName) {
		if (storeName != nullptr)
		{
			int l = strlen(storeName);
			this->storeName = new char[l + 1] {};
			strcpy_s(this->storeName, l + 1, storeName);

		}
	}
	void StoreAdress(const char* storeAddress) {
		if (storeAddress != nullptr)
		{
			int l = strlen(storeAddress);
			this->storeAddress = new char[l + 1] {};
			strcpy_s(this->storeAddress, l + 1, storeAddress);

		}
	}
	 char* GetStoreName() {
		return storeName;
	}
	 char* GetStoreAdress() {
		return storeAddress;
	}

	void AddComputer(const Computer* value) {
		Computer** temp = new Computer * [count + 1];
		for (size_t i = 0; i < count; i++)
		{
			temp[i] = computers[i];
		}temp[count] = new Computer;
		*temp[count] = *value;
		delete[]computers;
		computers = temp;
		count++;
		temp = nullptr;

	}


	void  DeleteComputer(int id) {
		int index = -1;
		for (size_t i = 0; i < count; i++)
		{
			if (computers[i]->GetObjectId()==id)
			{
				index = i; 
				break;
			}
		}
		if (index!=1&&0<count)
		{
			Computer** temp = new Computer * [count - 1];
			for (size_t i = 0; i < index; i++)
			{
				temp[i] = computers[i];
			}
			for (size_t i = index; i < count; i++)
			{
				temp[i] = computers[i];
			}
			delete[] computers;
			computers = temp;
			count--;
			temp = nullptr;
		}
	}

	friend ostream& operator<<(ostream& out, const ComputerStore& other) {
		out <<  other.storeName;
		out <<  other.storeAddress;
		for (size_t i = 0; i < other.count; i++)
		{
			cout << *other.computers[i] << endl;
		}
		return out;
	}

	
	~ComputerStore()
	{
		for (size_t i = 0; i < count; i++)
		{
			delete computers[i];
		}delete[] computers;
	}



};



void main() {
	auto c = new Computer("Asus", "zenbook", "RTX 3050 ti", "qled", 10, 16, 64, 1000, true);
	ComputerStore compstore("medovik", "bufet");
	compstore.AddComputer(new Computer ("Hp", "PAvillov", "RTX 3040 ti", "qled", 10, 8, 256, 1200, true));
	cout << compstore << endl;

}

