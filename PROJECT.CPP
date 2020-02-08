#include<fstream.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

class car
{
 char type[20];
 char colour[20];
 char model[20];
 char company[20];
 char cname[20];
 int chassisno;
 long double price;
 public:
 void getdata()
 {
	cout<<"Enter Type(Sedan/SUV/Sports/Luxury/Mini/Other):";gets(type);
	cout<<"Enter Colour    :";gets(colour);
	cout<<"Enter Model     :";gets(model);
	cout<<"Enter Company   :";gets(company);
	cout<<"Enter CarName   :";gets(cname);
	cout<<"Enter ChassisNo :";cin>>chassisno;
	cout<<"Enter Price     :";cin>>price;
 }

 void showdata()
 {
	cout<<"Type            :"<<type<<endl;
	cout<<"Colour          :"<<colour<<endl;
	cout<<"Model           :"<<model<<endl;
	cout<<"Company         :"<<company<<endl;
	cout<<"CarName         :"<<cname<<endl;
	cout<<"ChassisNo       :"<<chassisno<<endl;
	cout<<"Price           :"<<price<<endl<<endl;
 }

 void inprice(){ cout<<"Enter the new price :"; cin>>price;}
 void inmodel(){ cout<<"Enter the new model :"; gets(model);}
 void incolour(){ cout<<"Enter the new colour :";gets(colour);}


 int rchassis(){ return chassisno;}

 char* rmodel(){ return model;}

 char* rtype(){ return type;}

 long double rprice(){ return price;}
};

class CustomerInfo
{
 char name[30],mail[30];
 long int phoneno;
 int cid;

 public:
 void assignid(int Id){ cid=Id+1;}
 char* retname() { return name; }
 int retid(){ return cid;}
 void input()
 {
	cout<<"Enter your Name        :";gets(name);
	cout<<"Enter your PhoneNo.    :";cin>>phoneno;
	cout<<"Enter your Email-ID    :";gets(mail);
	cout<<"Your customer ID       :"<<cid<<endl;
	cout<<endl;
	cout<<endl;

cout<<"*** Please keep a record of your customer id for future purchases ***\n";
cout<<"                      Press any key to continue";
getch();
clrscr();

}

 void display()
 {
	cout<<"Name       :"<<name<<endl;
	cout<<"PhoneNo.   :"<<phoneno<<endl;
	cout<<"Email-ID   :"<<mail<<endl;
	cout<<"Customer Id:"<<cid<<endl;
 }
};

void Choice();
void Customer();
void NewCustomer();
void OldCustomer();
void Admin();
void AddData();
void DeleteData();
void EditData();
void ViewCata();
void Buy();
void ByModel();
void Model1();
void ByType();
void ByPrice();
void edmodel();
void edcolour();
void edprice();
void Option();
void Scno(int);

void main()
{
 clrscr();

 for(int i=1; i<=80; i++) cout<<"--";
 for(i=1; i<=23; i++) cout<<"|\n";
 for(i=2; i<=24; i++)
 { gotoxy(80, i); cout<<'|'; }
 for( i=1; i<80; i++)
 { gotoxy(i, 24); cout<<"--"; }
 gotoxy(24, 4);
 cout<<" SASHA DEALERSHIP WELCOMES YOU";
 gotoxy(25, 20);
 cout<<"We promise quality service..!";
 getch();
 clrscr();
 cout<<"What do you identify yourself as? "<<endl;
 Choice();
 getch();
}


void Choice()
{
 int cch;
 do
 {
	cout<<"1.Administrator"<<endl;
	cout<<"2.Customer"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Your Choice (1/2/3): ";
	cin>>cch;


	switch(cch)
	{
	 case 1:
		char A[]="Betaan", m;
		int chk=0;
		clrscr();
		cout<<"Enter Password: ";
		for(int i=0; i<6 && !chk; i++)
		{ m=getch(); cout<<'*';
			if(m!=A[i])
			{ cout<<endl;
			  cout<<endl;
			  clrscr();
			  cout<<"\n  Wrong Password!\n";
			  cout<<endl;
			  cout<<endl;
			  cout<<"Please make the correct choice"<<endl;
			  chk++; }
		}
	 if(!chk) { cout<<endl; clrscr(); Admin(); }
	 break;
	 case 2: clrscr();
		 Customer();
	 break;
	 case 3: clrscr();
		 cout<<"Quitting.....\n";
	}
 }while(cch!=3);
}

void Admin()
{
 int adch;
 do
 {      clrscr();
	cout<<"  What do you want to do? "<<endl;
	cout<<"  1.Add new cars in database"<<endl;
	cout<<"  2.Delete cars from database"<<endl;
	cout<<"  3.Edit details of cars existing in database"<<endl;
	cout<<"  4.Exit to main menu"<<endl;
	cout<<"  Enter your choice(1/2/3/4): ";
	cin>>adch;
	switch(adch)
	{
	 case 1:clrscr();
		AddData();
	 break;
	 case 2:DeleteData();
	 break;
	 case 3:clrscr();
		EditData();
	 break;
	 case 4:clrscr();

	}
 }while(adch!=4);
}

void AddData()
{
 clrscr();
 fstream fil;
 fil.open("carlist.dat",ios::binary|ios::app);
 car c;
 char reply;
 do
 {
	clrscr();
	c.getdata();
	fil.write((char*)&c,sizeof(c));
	clrscr();
	cout<<"Do you want to add more cars in the record? (y/n) ";
	cin>>reply;
 }while(reply=='y');
}


void DeleteData()
{
    clrscr();
    char z;
    fstream fil1,fil2;
    fil1.open("carlist.dat",ios::binary|ios::in);
    fil2.open("temp.dat",ios::binary|ios::out);
    car c;
    int del=0,sno;
    cout<<"Enter chassis no. of the car to delete from record: ";
    cin>>sno;
    cout<<endl; cout<<endl;
    cout<<"Are you sure you want to delete record with chassis no "<<sno<<" ? (y/n) ";
    cin>>z;
    if(z=='y')
  {
    while(fil1.read((char*)&c,sizeof(c)))
    {
      char z;
      if(c.rchassis()!=sno)
      fil2.write((char*)&c,sizeof(c));
      else
      {
	del++;
	clrscr();
	cout<<"Following car deleted from record: \n";
	c.showdata();cout<<endl;
	cout<<endl;
	cout<<"Press any key to continue ";
	getch();
	clrscr();

      }
   }

}

 else
  {
    clrscr(); DeleteData();
  }

if(!del)
 {      int ch3;
	remove("temp.dat");


	do
	{
	 clrscr();
	 cout<<"Car searched not found!";
	 cout<<endl; cout<<endl;
	 cout<<"What do you want to do ?"<<endl;
	 cout<<"1.Retry entering chassis no? "<<endl;
	 cout<<"2.Go back"<<endl;
	 cout<<"Enter your choice(1/2): ";
	 cin>>ch3;

	   switch(ch3)
	      {
		case 1: clrscr();
			DeleteData();
			break;
		case 2: clrscr();

	      }

	}while(ch3!=2);


 }

 fil1.close();
 fil2.close();


 remove("carlist.dat");
 rename("temp.dat","carlist.dat");

}


void EditData()
{ clrscr();
  int ch2;
    do
    {
      cout<< "What do you want to do? "<<endl;
       cout<<"1.Edit the colour of the car "<<endl;
       cout<<"2.Edit the model of the car "<<endl;
       cout<<"3.Edit the price of the car "<<endl;
       cout<<"4.Exit to administrator menu " <<endl;
      cout<< "Your choice (1/2/3/4): "; cin>>ch2;

	 switch (ch2)
	 {
	   case 1: clrscr();
		   edcolour();
	   break;

	   case 2: clrscr();
		   edmodel();
	   break;

	   case 3: clrscr();
		   edprice();
	   break;

	 case 4: clrscr();
	 }

    }while (ch2!=4);

}

void edcolour()
 {
      fstream fil;
      fil.open("carlist.dat",ios::binary|ios::in|ios::out);
      car c;
      int sno,found=0;
      cout<<"Enter chassis no of the car whose colour has to be edited: ";
      cin>>sno;
      while(!found && fil.read((char*)&c,sizeof(c)))
	{
	  if(c.rchassis()==sno)
	    {   char z;
		c.incolour();
		fil.seekg(fil.tellg()-sizeof(c));
		fil.write((char*)&c,sizeof(c));
		found++;
		cout<<endl;
		cout<<endl;
		cout<<"Please verify the change as shown below: \n";
		c.showdata();
		cout<<endl; cout<<endl;
		cout<<"Are you sure the change is correct?(y/n) ";
		cin>>z;
		if(z=='y')
		clrscr();
		else
		{ clrscr(); edcolour();}
	      }
	   }
		 if(!found)
		    { int ch3;
		      clrscr();
		      cout<<"Car searched doesn't exist in record! \n";
		     do
		     {
		      cout<<endl;
		      cout<<"What do you want to do ?"<<endl;
		      cout<<"1.Retry entering chassis no? "<<endl;
		      cout<<"2.Go back to edit options"<<endl;
		      cout<<"Enter your choice(1/2): ";
		      cin>>ch3;

		       switch(ch3)
		       {
			case 1: clrscr();
				edcolour();
			break;
			case 2: clrscr();

		       }
		     }while(ch3!=2);


		  }
		   fil.close();
     }


void edmodel()
 {
      fstream fil;
      fil.open("carlist.dat",ios::binary|ios::in|ios::out);
      car c;
      int sno,found=0;
      cout<<"Enter chassis no of the car whose model has to be edited: ";
      cin>>sno;
      while(!found && fil.read((char*)&c,sizeof(c)))
	{
	  if(c.rchassis()==sno)
	    {   char z;
		c.inmodel();
		fil.seekg(fil.tellg()-sizeof(c));
		fil.write((char*)&c,sizeof(c));
		found++;
		cout<<endl;
		cout<<endl;
		cout<<"Please verify the change as shown below:\n";
		c.showdata();
		cout<<endl; cout<<endl;
		cout<<"Are you sure the change is correct?(y/n) ";
		cin>>z;
		if(z=='y')
		clrscr();
		else
	       { clrscr();  edcolour();}
	      }
	   }

		  if(!found)
		    { int ch3;
		      clrscr();
		      cout<<"Car searched doesn't exist in record! \n";
		     do
		     {
		      cout<<endl; cout<<endl;
		      cout<<"What do you want to do ?"<<endl;
		      cout<<"1.Retry entering chassis no? "<<endl;
		      cout<<"2.Go back to edit options"<<endl;

		     cout<< "Enter your choice(1/2): ";
		     cin>>ch3;

		       switch(ch3)
		       {
			case 1: clrscr();
				edmodel();
			break;
			case 2: clrscr();
		       }
		     }while(ch3!=2);


		  }
		   fil.close();
     }


void edprice()
 {
      fstream fil;
      fil.open("carlist.dat",ios::binary|ios::in|ios::out);
      car c;
      int sno,found=0;
      cout<<"Enter chassis no of the car whose price has to be edited: ";
      cin>>sno;
      while(!found && fil.read((char*)&c,sizeof(c)))
	{
	  if(c.rchassis()==sno)
	    {   char z;
		c.inprice();
		fil.seekg(fil.tellg()-sizeof(c));
		fil.write((char*)&c,sizeof(c));
		found++;
		cout<<endl;
		cout<<endl;
		cout<<"Please verify the change as shown below:\n";
		c.showdata();

			cout<<endl; cout<<endl;
		cout<<"Are you sure the change is correct?(y/n) ";
		cin>>z;
		if(z=='y')
		clrscr();
		else
		{clrscr(); edcolour();}
	      }
	   }


	       if(!found)
		    { int ch3;
		      clrscr();
		      cout<<"Car searched doesn't exist in record! \n";
		     do
		     {
		      cout<<endl; cout<<endl;
		      cout<<"What do you want to do ?"<<endl;
		      cout<<"1.Retry entering chassis no? "<<endl;
		      cout<<"2.Go back to edit options"<<endl;

		     cout<<endl;
		     cout<<"Enter your choice(1/2): ";
		     cin>>ch3;

		       switch(ch3)
		       {
			case 1: clrscr();
				edprice();
			break;
			case 2: clrscr();
		       }
		     }while(ch3!=2);


		  }
		   fil.close();
     }



void Customer()
{
 int op;
 do
 {
	cout<<"1.New Customer"<<endl;
	cout<<"2.Old Customer"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Your Choice? (1/2/3): ";
	cin>>op;

	switch(op)
	{
	 case 1: clrscr();
		 NewCustomer();
	 break;
	 case 2: clrscr();
		 OldCustomer();
	 break;
	 default: clrscr();
		  cout<<"Quitting from Customer....\n"; getch();
		  clrscr();
	}
 }while(op==1||op==2);
}

void NewCustomer()
{
 clrscr();
 cout<<"Enter your details below: \n";
 CustomerInfo x;
 fstream fin;
 fin.open("custin.dat",ios::out|ios::in|ios::binary);
 fin.seekp(0, ios::end);
 if(!fin.tellg()) x.assignid(100);
 else
 { fin.seekp(fin.tellg()-sizeof(x));
	 fin.read((char*)&x, sizeof(x));
	 x.assignid(x.retid());
 }
 x.input();
 fin.write((char*)&x,sizeof(x));
 cout<<"You are logged in as our new customer...!"<<endl;
 cout<<"Enjoy our services! "<<endl;
 cout<<endl;
 cout<<"1.View our catalogue to find your desired car"<<endl;
 cout<<"2.Search for the desired car using filters"<<endl;
 int opt; cout<<"Enter your choice:";
 cin>>opt;
 switch(opt)
 {       case 1: clrscr();
		 ViewCata();
		 Option();
	 break;
	 case 2: clrscr();
		 Buy();
	 break;
	 default: clrscr();
		  cout<<"Quitting..."; getch();
 }                clrscr();
 fin.close();
}

void OldCustomer()
{
 fstream f;
 CustomerInfo c;
 int found=0,sid;
 cout<<"Enter your Customer ID: ";
 cin>>sid;
 f.open("custin.dat",ios::binary|ios::in);
 while(!found && f.read((char*)&c,sizeof(c)))
	if(c.retid()==sid)
	{
	 clrscr();
	 cout<<"Welcome "<<c.retname()<<endl;
	 found++;
	}

 if(!found)
	{
	 cout<<"You are not an old customer!"<<endl;
	 cout<<"Please Register as New Customer...\n";
	 Customer();
	}
 else
 {       cout<<"1.View our catalogue to find your desired car"<<endl;
	 cout<<"2.Search for the desired car using filters"<<endl;
	 cout<<"Enter your choice:";

	 int opt; cin>>opt;

	 switch(opt)
	 {
		 case 1: clrscr();
			 ViewCata();
			 Option();
		 break;
		 case 2: clrscr();
			 Buy();
		 break;
		 default:clrscr();
			 cout<<"Quitting..."; getch();
			 clrscr();
	 }
 }
}

void ViewCata()
{
 fstream fil;
 car c; int opt, chk1;
 fil.open("carlist.dat",ios::binary|ios::in);
 clrscr();
 cout<<"Following are the cars for sale: \n";
 while(fil.read((char*)&c,sizeof(c)))
 c.showdata();
 fil.close();
}

void Option()
 { int opt;
   cout<<endl; cout<<endl;
   cout<<"1.Buy"<<endl;
   cout<<"2.Exit"<<endl;
   cout<<"Enter your choice:";
   cin>>opt;
   switch(opt)
   {
     case 1: clrscr();
	     ViewCata();
	     Model1();
	     break;

	   default: clrscr();
		    cout<<"Quitting..."; getch();
		    clrscr();
   }
}


void Model1()
{
 fstream fil;
 fil.open("carlist.dat",ios::binary|ios::in);
 car c; int found=0;
 char smod[10],ch5;
 cout<<endl;
 cout<<"Enter the model of car you want to buy from the above menu:";
 gets(smod);
 clrscr();
 while(fil.read((char*)&c, sizeof(c)) && !found)
	if(strcmpi(c.rmodel(),smod)==0)
	{
		cout<<"Verify the details of your selection: "<<endl;
		c.showdata();cout<<endl; cout<<endl;
		cout<<"Do you want to purchase this car?(y/n)";
		cin>>ch5;
		cout<<endl; cout<<endl;
       if(ch5=='y')
	      {
		int scar;
		scar=c.rchassis();
		clrscr();
		cout<<"Generating your cash memo.... ";
		getch();
		clrscr();
		Scno(scar);
		found++;
	      }

   else { clrscr(); ViewCata(); Model1();  }
 }

 if(!found)
 { char a;
   clrscr();
   cout<<" There is no such model in our stock!"<<endl;
   cout<<endl; cout<<endl;
   cout<<" Press any key to view the catalogue again"<<endl;
   getch();
   clrscr();
   ViewCata();
   cout<<"Did you find your desired car?(y/n): ";
   cin>>a;

   if(a=='y')
   Model1();
   else
  {clrscr(); Customer(); }
 }
}


void Buy()
{
 int bch;
 do
 {

	cout<<"You can use following search filters to find your car: \n";
	cout<<"1.By Model"<<endl;
	cout<<"2 By Type"<<endl;
	cout<<"3 By Price"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"Your choice? (1/2/3/4): ";
	cin>>bch;
	switch(bch)
	{
	 case 1:clrscr();
		ByModel();
	 break;
	 case 2:clrscr();
		ByType();
	 break;
	 case 3:clrscr();
		ByPrice();
	 break;
	 case 4: clrscr();
		 cout<<"Quitting from Buying Option...\n"; getch();
		 clrscr();

	}
 }while(bch!=4);
}

void ByModel()
{
 fstream fil;
 fil.open("carlist.dat",ios::binary|ios::in);
 car c; int found=0;
 char smod[10],ch6;
 cout<<"Enter model of car you want to buy: ";
 gets(smod);
 while(fil.read((char*)&c, sizeof(c)) && !found)
	if(strcmpi(c.rmodel(),smod)==0)
	{
		clrscr();
		cout<<"Bingo..! We have the car you want to buy..!";
		cout<<endl;
		cout<<"Check out the details below: "<<endl;
		c.showdata();
		cout<<endl;
		cout<<"Do you want to buy this car ?(y/n) " ;
		cin>>ch6;
		if(ch6=='y')
		 {
		  cout<<endl;
		  cout<<"Generating your cash memo...";
		  getch();
		  int scar;
		  scar=c.rchassis();
		  Scno(scar);
		  found++;
		}
		else
		{clrscr(); Customer();}
	   }
 if(!found)
 {
   clrscr();
   cout<<" Model searched, not found!"<<endl;
   cout<<" We regret the inconvenience caused to you \n"<<endl;
   cout<<endl;
   cout<<" Press enter to go back to main search options";
   getch();
   clrscr();
 }
}

void ByType()
{
 fstream fil;
 fil.open("carlist.dat",ios::binary|ios::in);
 car c; int found=0;
 char smod[10];
 cout<<"Enter type of car you want to buy: ";
 gets(smod);
 while(fil.read((char*)&c, sizeof(c)) && !found)
	if(strcmpi(c.rtype(),smod)==0)
	{       char ch6;
		clrscr();
		cout<<"Bingo..! We have the car you want to buy..!";
		cout<<endl;
		cout<<"Check out the details below: "<<endl;
		cout<<endl; cout<<endl;
		c.showdata();
		cout<<endl;
		cout<<"Do you want to buy this car ?(y/n) " ;
		cin>>ch6;
		if(ch6=='y')
		 {
		  cout<<endl;
		  clrscr();
		  cout<<"Generating your cash memo...";
		  getch();
		  int scar;
		  scar=c.rchassis();
		  clrscr();
		  Scno(scar);
		  found++;
		}
		else
		{clrscr(); Customer();}
	 }

 if(!found)
 {
   clrscr();
   cout<<" Type searched, not found!"<<endl;
   cout<<" We regret the inconvenience caused to you \n"<<endl;
   cout<<endl;
   cout<<" Press enter to go back to main search options";
   getch();
   clrscr();
 }
}

void ByPrice()
{
 fstream fil;
 fil.open("carlist.dat",ios::binary|ios::in);
 car c;
 double slprice,suprice;
 cout<<"We need your budget to find the best fit for you "<<endl;
 cout<<"Enter minimum amount to search by: ";cin>>slprice;
 cout<<"Enter maximum amount to search by: ";cin>>suprice;
  while(fil.read((char*)&c, sizeof(c)))
{
   if(c.rprice()<=suprice && c.rprice()>=slprice)
    {      char ch6;
	   clrscr();
	   cout<<"This is what we found out:" <<endl;
	   c.showdata();
	   cout<<endl;
	   cout<<"Do you want to buy this car ?(y/n) " ;
	   cin>>ch6;
	   if(ch6=='y')
		 {
		  clrscr();
		  cout<<"Generating your cash memo...";
		  getch();
		  clrscr();
		  int scar;
		  scar=c.rchassis();
		  Scno(scar);
		}
		else
			{clrscr(); Customer();}
    }

 else
 {
   clrscr();
   cout<<" Model searched, not found!"<<endl;
   cout<<" We regret the inconvenience caused to you \n"<<endl;
   cout<<endl;
   cout<<" Press enter to go back to main search options";
   getch();
   clrscr();
 }

fil.close();
}
}
void Scno(int scar)
{
 fstream f;
 car c;
 int found=0;
 f.open("carlist.dat",ios::binary|ios::in);
 while(!found && f.read((char*)&c,sizeof(c)))
 {
	if(c.rchassis()==scar)
	{
	  cout<<"-------------------------------------CASH MEMO----------------------------------";
	  cout<<endl;
	  cout<<endl;
	  cout<<endl;
	  cout<<"Below are the details of your purchase" <<endl;
	  cout<<endl;
	  c.showdata();
	  cout<<endl;

	  cout<<"NET PAYABLE AMOUNT:"<< c.rprice()<<endl;

	  cout<<endl; cout<<endl; cout<<endl; cout<<endl;
	  cout<<"                               Thanks for your purchase \n";
	  cout<<"                                   Please visit again \n";
	  found++;
	}
 }
getch();
clrscr();
Customer();

}

