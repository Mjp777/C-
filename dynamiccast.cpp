#include<iostream>
#include<typeinfo.h>
using namespace std;
class Emp{
	public:virtual void calSalary()
	{
		cout<<"----Employee CalsSalary----"<<endl;
	}
	void display()
	{
		cout<<"----Employee details----"<<endl;
	}
};
class Mgr :public Emp{
	public:void ManagerTask()
	{
		cout<<"-----Manager Task-----"<<endl;
	}
	void calSalary()
	{
		cout<<"----Manager CalsSalary----"<<endl;
	}
};
class Admin:public Emp{
public :void AdminTask()
	{
		cout<<"-----Admin Task-----"<<endl;
	}	
	void calSalary()
	{
		cout<<"----Admin CalsSalary----"<<endl;
	}
};
class MarketinExe:public Emp{
public:void MarketinExeTask()
	{
		cout<<"-----MarketinExe Task-----"<<endl;
	}	
void calSalary()
	{
		cout<<"----Marketing CalsSalary----"<<endl;
	}
};



//common method
//void display(Mgr &mgrObj)
//{
//	mgrObj.ManagerTask();//mgr
//    mgrObj.calSalary();//mgr
//}
//void display(MarketinExe &me)
//{
//	me.MarketinExeTask();
//    me.calSalary();// 
//}
void display(Emp* empObj)//
{
	empObj->calSalary();
	
	if(typeid(empObj)==typeid(MarketinExe))
	{
		//downcast
	}
}

int main()
{
	Emp emp;
	emp.calSalary();//emp
	emp.display();
	cout<<"\n-----manager --------"<<endl;
	Mgr mgr;
	mgr.calSalary();
	mgr.ManagerTask();
	cout<<"\n-----Admin --------"<<endl;
	Admin admin;
	admin.calSalary();
	admin.AdminTask();
	cout<<"\n-----MarketingExe --------"<<endl;
	MarketinExe me;
	me.calSalary();
	me.MarketinExeTask();
	
	cout<<"\n----generic pointer--------"<<endl;
	
	Emp* ptr;//compile time type:Emp
	ptr=&mgr;//dynamic(runtime) data type:Mgr
	ptr->calSalary();//as per compiler ptr type is Emp
	     //calSalary ---->Emp
	//imp note:to achive dynamic binding(runtime /late)
	//use virtual keyword for overriden method in base class
cout<<"\n\n---array-----"<<endl;
Emp* allemp[4];
allemp[0]=&emp;
allemp[1]=&mgr;
allemp[2]=&admin;
allemp[3]=&me;
 cout<<typeid(int).name();
for(int i=0;i<4;i++)
{
	allemp[i]->calSalary();//0-->emp  1->mgr  2-->Admin  3-->
//hoe to get dynmaic data type
//use typeid:run time data type
//cout<<" Data Type At index  "<<i<<typeid(*allemp[i])<<endl;
 //cout<<typeid(*allemp[i].name());
 if(typeid(*allemp[i])==typeid(Emp))
 {
 	cout<<"Emp type type at idex:"<<i<<endl;;
 }
 if(typeid(*allemp[i])==typeid(Admin))
 {
 	cout<<"\n Admin type type at idex:"<<i<<endl;;
 	//so to invoke all the Admin methods
 	//Emp forcefully convert to Admin
 	//downcast:parent obj convrted into child class
 	Admin* ad=dynamic_cast<Admin*>(allemp[i]);
 	 ad->AdminTask();
 }
 if(typeid(*allemp[i])==typeid(Mgr))
 {
 	cout<<"Mgr type at idex:"<<i<<endl;
    Mgr* m= dynamic_cast<Mgr*>(allemp[i]);
 	m->ManagerTask();
 }
 if(typeid(*allemp[i])==typeid(MarketinExe))
 {
 	cout<<"\nMarketinExe type type at idex:"<<i<<endl;;
    MarketinExe* m1=dynamic_cast<MarketinExe*>(allemp[i]);
 	m1->MarketinExeTask();
 	
 }
 
 cout<<"\n\n"<<endl;
 display(&mgr);//
 display(&me);//
 //100+ childs
}

return 0;
}

