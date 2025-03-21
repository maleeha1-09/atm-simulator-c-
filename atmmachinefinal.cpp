#include <iostream>
#include<fstream>
#include<ctime>
using namespace std;


long long balance = 845678;
long long card_no=12345678910;
long pin=8990;
long long eaccno;
long epin;


int i;


//funtions
int casemenu();
void displayBalance();
void withdrawmoney();
void depositmoney();
void view_transaction();



time_t t=time(0);
char*st=ctime(&t);



void withdrawmoney()
{
double withdraw=0;
cout<<endl;
cout<<" \t\tYour balance is "<<balance<<endl<<endl;
	cout<<"\t\tHow much money you want to withdraw : ";
	cin>>withdraw;
	if(withdraw==0)
{
	 
                system ("CLS");
	casemenu();
}


	else if (withdraw > balance)
	{
		cout<<"\t\tYou have exceeded balance limit ...please enter smaller amount\n\n";
		
	cout<<"\t\tHow much money you want to withdraw : ";
	cin>>withdraw;
	}
	
		cout<<endl;
	cout<<"\t\tWithdrawal succesful.\n"<<endl;
		cout<<"\t\tYou have withdrawed "<<withdraw<<" from your current balance\n\n";
		balance = balance - withdraw;
	cout<<"\t\tNew  balance : "<<balance<<endl<<endl;
    
	ofstream outfile;
	outfile.open("D:\\atmmachine\\transactionz.txt",ios::app );
	outfile<<"---------------------------------------"<<endl<<"Account no. : **********"<<endl<<"Name : Dr.Ayesha Hakim"<<endl<<"Transaction : "
<<"Withdrawal of: "<<withdraw<<endl<<" At time :"<<st<<endl;
	outfile.close();

	 system ("PAUSE");
                system ("CLS");
	
	
}

void view_transaction(){
	ifstream infile;
	infile.open("D:\\atmmachine\\transactionz.txt");
	string readatm;
	if(infile.is_open()){
		while(getline(infile,readatm)){
			cout<<readatm<<endl;
			
		}
		infile.close();
	}else{
		cout<<"error opening file"<<endl;
	}
	 system ("PAUSE");
                system ("CLS");
	
}



void  displaybalance()
{
	cout<<endl;
	cout<<"\t\tYour current balance is :"<<balance<<endl<<endl;
		ofstream outfile;
	outfile.open("D:\\atmmachine\\transactionz.txt",ios::app );
	outfile<<"---------------------------------------"<<endl<<"Account no . : **********"<<endl<<"Name : Dr.Ayesha Hakim"<<endl<<"Transaction : "
	<<"Viewed balance : "<<balance<<endl<<"  at time : "<<st<<endl;
	outfile.close();
 system ("PAUSE");
                system ("CLS");

	
}

void depositmoney()
{
double deposit=0;

	cout<<endl;
	cout<<"\t\tHow much money you want to deposit : ";
	cin>>deposit;
	if(deposit==0)
{
	casemenu();
}

    

	cout<<"\t\tDeposit succesful.\n"<<endl;
		cout<<"\t\tYou have deposited "<<deposit<<" into your account\n\n";
		balance = balance + deposit;
		
		cout<<"\t\tNew  balance : "<<balance<<endl;
	   
	ofstream outfile;
	outfile.open("D:\\atmmachine\\transactionz.txt",ios::app );
	outfile<<"---------------------------------------"<<endl<<"Account no . : **********"<<endl<<"Name : Dr.Ayesha Hakim"<<endl<<"Transaction : "
	<<"deposit : "<<deposit<<endl<<"  at time : "<<st<<endl;
	outfile.close();

		 system ("PAUSE");
                system ("CLS");
	

}
	
int casemenu()
{

	char input;
	cout<<"\n\t   WELCOME DR. AYESHA HAKIM    \t"<<endl;
	do {
		cout<<"\n------------------------------------------------------------------------\n";
	cout<<"\t Which type of transaction do you want : \n\n";
	cout<<"\t[a]****Withdrawal\n";
	cout<<"\t[b]****displaybalance\n";
	cout<<"\t[c]****Deposit money\n";
	cout<<"\t[d]****View previous transactions\n";
	cout<<"\t[e]****Exit\n\n";
	
	cout<<"\tEnter type of transaction :: ";
	cin>>input;
	

	switch( input )	
	{
	
	case 'a' :
	{
			withdrawmoney();
	
			
		break;}
	case 'b' :
	{
			displaybalance();
	
		break;}
		
		
		case 'c' :
	{
			depositmoney();
		
		break;}
		case 'd':
			{
			view_transaction();
			
			break;
			}
		
		
	case 'e' :
	{
			exit(0);
		break;}
	}

}while(input<'f');

return 0;
}



   int main()
{

    
	cout << "\t**********************************************************\n" << endl
			<< " \t\t    THE MNSUA INTERNATIONAL BANK\n\n\t\t\t ------* WELCOME *------\n" << endl
			<< "\t**********************************************************\n\n"			
			<< "\t\t\t\tUSER LOGIN\n" << endl
			<< "\t\tENTER ACCOUNT NUMBER AND PIN\n" << endl
			<< "\n\t\t\t------ Enter Account Number: ";
		cin>>eaccno ;
		cout << "\n\t\t\t------ Enter PIN: ";
		cin >> epin;
		cout << "\n";
 

	if (card_no != eaccno || pin != epin)
	{
	for(i=0;i<2;i++)
	{
	
		system("cls");
		cout << "\t**********************************************************\n" << endl
			<< " \t\t    THE MNSUA INTERNATIONAL BANK\n\n\t\t\t ------* WELCOME *------\n" << endl
			<< "\t**********************************************************\n\n"
			<< "\t\t\t\tUSER LOGIN\n" << endl
			<< "\t\tINVALID ACCOUNT NUMBER OR PIN WAS ENTERED\n" << endl
			<< "\n\t\t\t------ Enter Account Number: ";
		cin>>eaccno;
		cout << "\n\t\t\t------ Enter PIN: ";
		cin >> epin;
		cout << "\n";
}

	system("CLS");
	cout << "\t**********************************************************\n" << endl
			<< " \t\t    THE MNSUA INTERNATIONAL BANK"<<endl <<endl << endl
			<< "\t**********************************************************\n\n"	
            <<"\t\t-------*YOUR CARD IS BLOCKED*--------"
            << endl <<"\n\t**********************************************************\n\n";

  
}
  	if (card_no == eaccno && pin == epin)
{
system("CLS");
casemenu();} 


	return 0 ;
}