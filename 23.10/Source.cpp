#include <iostream>
#include <cstring>
using namespace std;

class Transport
{
	char* type;
	string color;
	int speed;
	int fuelcons;
	int passenger;
public:
	Transport()
	{
		type = nullptr;
		color = "";
		speed = fuelcons = passenger = 0;
	}
	Transport(const char* t, string c, int s, int f, int p)
	{
		if (type != nullptr)
			delete[]type;
		type = new char[strlen(t) + 1];
		strcpy_s(type, strlen(t) + 1, t);
		color = c;
		speed = s;
		fuelcons = f;
		passenger = p;
	}
	virtual void Show()
	{
		cout << "���������: " << type << endl;
		cout << "����: " << color << endl;
		cout << "��������: " << speed << " ��\\�\n";
		cout << "������ �������: " << fuelcons << " L\\100 ��\n";
		cout << "��������: " << passenger << endl;
	}
	virtual void Init()
	{
		cout << "Transport: ";
		char* temp = new char[128];
		cin >> temp;
		if (type != nullptr)
			delete[]type;
		type = new char(strlen(temp) + 1);
		strcpy_s(type, strlen(temp) + 1, temp);
		delete[]temp;
		cout << "����: ";
		cin >> color;
		cout << "��������: ";
		cin >> speed;
		cout << "������ �������: ";
		cin >> fuelcons;
		cout << "��������: ";
		cin >> passenger;
	}
	virtual int GetFuel()
	{
		return fuelcons;
	}
	virtual~Transport();
};

Transport::~Transport()
{
	cout << "���������� ����������" << endl;
	delete[]type;
}

class car :public Transport
{
	char* company;
public:
	car()
	{
		company = nullptr;
	}
	car(const char* t, string c, int s, int f, int p, const char* co) :Transport(t, c, s, f, p)
	{
		if (company != nullptr)
			delete[]company;
		company = new char[strlen(co) + 1];
		strcpy_s(company, strlen(co) + 1, co);
	}
	void Show()
	{
		Transport::Show();
		cout << "��������: " << company << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "��������: ";
		char* temp = new char[128];
		cin >> temp;
		if (company != nullptr)
			delete[]company;
		company = new char(strlen(temp) + 1);
		strcpy_s(company, strlen(temp) + 1, temp);
		delete[]temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~car()
	{
		cout << "���������� ������" << endl;
		delete[]company;
	}
};

class helicopter :public Transport
{
	double* tire_size;
public:
	helicopter()
	{
		tire_size = nullptr;
	}
	helicopter(const char* t, string c, int s, int f, int p, double ti) :Transport(t, c, s, 0, p)
	{
		if (tire_size != nullptr)
			delete tire_size;
		tire_size = new double;
		*tire_size = ti;
	}
	void Show()
	{
		Transport::Show();
		cout << "������� ����: " << *tire_size << " ��" << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "������ ���: ";
		if (tire_size != nullptr)
			delete tire_size;
		tire_size = new double;
		double temp;
		cin >> temp;
		*tire_size = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~helicopter()
	{
		cout << "���������� ��������" << endl;
		delete tire_size;
	}
};

class bike :public Transport
{
	bool* offroad;
public:
	bike()
	{
		offroad = nullptr;
	}
	bike(const char* t, string c, int s, int f, int p, bool off) :Transport(t, c, s, f, p)
	{
		if (offroad != nullptr)
			delete offroad;
		offroad = new bool;
		*offroad = off;
	}
	void Show()
	{
		Transport::Show();
		if (*offroad)
			cout << "�����������" << endl;
		else
			cout << "����������������" << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "�����������?" << endl;
		cout << "\t1.��" << endl;
		cout << "\t0.���" << endl;
		if (offroad != nullptr)
			delete offroad;
		offroad = new bool;
		bool temp;
		cin >> temp;
		*offroad = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~bike()
	{
		cout << "���������� ����������" << endl;
		delete offroad;
	}
};

class plane :public Transport
{
	double* carr_cap;
public:
	plane()
	{
		carr_cap = 0;
	}
	plane(const char* t, string c, int s, int f, int p, double cc) :Transport(t, c, s, f, p)
	{
		if (carr_cap != nullptr)
			delete carr_cap;
		carr_cap = new double;
		*carr_cap = cc;
	}
	void Show()
	{
		Transport::Show();
		cout << "����������������: " << *carr_cap << " ����" << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "����������������: ";
		if (carr_cap != nullptr)
			delete carr_cap;
		carr_cap = new double;
		double temp;
		cin >> temp;
		*carr_cap = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~plane()
	{
		cout << "���������� �������" << endl;
		delete carr_cap;
	}
};

class bigfoot :public Transport
{
	int* HP;
public:
	bigfoot()
	{
		HP = nullptr;
	}
	bigfoot(const char* t, string c, int s, int f, int p, int hp) :Transport(t, c, s, f, p)
	{
		if (HP != nullptr)
			delete HP;
		HP = new int;
		*HP = hp;
	}
	void Show()
	{
		Transport::Show();
		cout << "��������� ���: " << *HP << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "��������� ���: ";
		if (HP != nullptr)
			delete HP;
		HP = new int;
		double temp;
		cin >> temp;
		*HP = temp;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
	~bigfoot()
	{
		cout << "���������� ������" << endl;
		delete HP;
	}
};

int menu1()
{
	int choose;
	cout << "1.������" << endl;
	cout << "2.�������" << endl;
	cout << "3.���������" << endl;
	cout << "4.������" << endl;
	cout << "5.������" << endl;
	cout << "��� �����: ";
	cin >> choose;
	return choose;
}

int menu2()
{
	int choose;
	cout << "1.�����" << endl;
	cout << "2.�������� ������ �� 100��" << endl;
	cin >> choose;
	return choose;
}

int main()
{
	setlocale(0, "ru");
	int choose = menu1();
	Transport* Ttmp = nullptr;
	switch (choose)
	{
	case 1:
		Ttmp = new car();
		Ttmp->Init();
		break;
	case 2:
		Ttmp = new helicopter();
		Ttmp->Init();
		break;
	case 3:
		Ttmp = new bike();
		Ttmp->Init();
		break;
	case 4:
		Ttmp = new plane();
		Ttmp->Init();
		break;
	case 5:
		Ttmp = new bigfoot();
		Ttmp->Init();
		break;
	default:
		break;
	}
	system("cls");
	int choose2 = menu2();
	switch (choose2)
	{
	case 1:
		Ttmp->Show();
		break;
	case 2:
		cout << Ttmp->GetFuel();
		break;
	default:
		break;
	}
	delete Ttmp;
}