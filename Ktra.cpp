#include<bits/stdc++.h>
using namespace std;

void Intro(const char intro[200])
{
	cout << intro;
	cout << setw(30) << "Ho ten";
	cout << setw(28) << "dd/mm/yyyy";
	cout << setw(20) << "Que quan";
	cout << setw(30) << "Bo mon";
	cout << setw(20) << "Thu nhap";
	cout << setw(20) << "Thong tin CLB";
	cout << setw(20) << "Vi tri" << endl;
}

class Person
{
	protected:
	    char hoTen[50];
	    int d, m, y;
	    char queQuan[100];
	public:
	    void Input()
	    {
	        cout << "Nhap ho ten: "; cin.getline(hoTen, 50);
	        cout << "Nhap d, m, y: "; cin >> d >> m >> y;
	        cin.ignore();
	        cout << "Nhap que quan: "; cin.getline(queQuan, 100);
	    }
	    void Output()
		{
	    	cout << setw(30) << hoTen;
	    	cout << setw(20) << d << "/" << m << "/" << y;
	    	cout << setw(20) << queQuan;
		}
};

class VANDONGVIEN: public Person
{
	protected:
		char boMon[30];
		float thuNhap;
	public:
		void Input()
		{
			Person::Input();
			cout << "Nhap bo mon: "; cin.getline(boMon, 30);
			cout << "Nhap thu nhap: "; cin >> thuNhap;
			cin.ignore();
		}
		void Output()
		{
			Person::Output();
			cout << setw(30) << boMon;
			cout << setw(20) << thuNhap;
		}
};

class CLB: public VANDONGVIEN
{
	private:
		char infCLB[100];
		char viTri[100];
	public:
		void Input()
		{
			VANDONGVIEN::Input();
			cout << "Nhap thong tin CLB: "; cin.getline(infCLB, 100);
			cout << "Nhap vi tri: "; cin.getline(viTri, 100);
		}
		void Output()
		{
			VANDONGVIEN::Output();
			cout << setw(20) << infCLB;
			cout << setw(20) << viTri << endl;
		}
//		const char *getCLB()
//		{
//			return infCLB;
//		}
//		float getTN()
//		{
//			return thuNhap;
//		}
        void isFind(int n, CLB *a)
        {
            for(int i = 0; i < n; i++)
            {
                if(strcmp(a[i].getCLB(), "T&T") == 0)
                {
                    a[i].Output();
                }
            }
        }

};

void isFind(int n, CLB *a)
{
	for(int i = 0; i < n; i++)
	{
		if(strcmp(a[i].getCLB(), "T&T") == 0)
		{
			a[i].Output();
		}
	}
}

void isMax(int n, CLB *a)
{
	int max = a[0].getTN();
	for(int i = 0; i < n; i++)
	{
		if(max < a[i].getTN())
		{
			max = a[i].getTN();
		}
	}
	for(int i = 0; i < n ; i++)
	{
		if(max == a[i].getTN())
		{
			a[i].Output();
		}
	}
}

int main()
{
	int n;
	cout << "Nhap so cau thu: "; cin >> n;
	cin.ignore();

	CLB a;
	a = new CLB[n];
	for(int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin cau thu thu " << i+1 << " : \n";
		a[i].Input();
	}
	Intro("\n- THONG TIN CAU THU -------------------------------\n");
	for(int i = 0; i < n; i++)
	{
		a[i].Output();
	}
	cout << "\n---------------------------------------------------\n";
	isFind(n, a);
	isMax(n, a);
}
