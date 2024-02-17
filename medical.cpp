#include<iostream>
using namespace std;
#include<stdlib.h>
#include<fstream>
#include<string>
void last();
void bill();
void Password();
void initializing();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu()
{
	    system("cls");
		cout<<"\n                                 W E L C O M E   T O     M E D I C A L   C A R E ";
		cout<<"\n                                 -------------   ---     -------------   ------- ";
		cout<<"\n\n\n                                               PATIENT MENU                                ";
		cout<<"\n                                               --------------                              ";
		cout<<"\n\n                                               1.Admit patient                             ";
		cout<<"\n                                               2.Search patient                            ";
		cout<<"\n                                               3.Modify Records                                  ";
		cout<<"\n                                               4.Display Records                                  ";
		cout<<"\n                                               5.Medicines Records                                ";
		cout<<"\n                                               6.Bill Calculation                          ";
		cout<<"\n                                               7.Terms And Conditions                      ";
		cout<<"\n                                               8.Exit                                      ";
	    cout<<"\n\n                                        Enter your choice(1-8):"     ;
}//menu end

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Patient
{ //patient class start
int ptno,age;
char mob[12];
char pt_name[50],address[50],relative[50],prob[50];
public:
	void PatientInsert()
	{
		cout<<"\n\n\n\t1. Enter the patient registration number:";
		cin>>ptno;
		cout<<"\n\t2. Enter the name of patient:";
		cin>>pt_name;
		cout<<"\n\t3. Enter the age of patient:";
		cin>>age;
		cout<<"\n\t4. Enter the address  of patient:";
		cin>>address;
		cout<<"\n\t5. Enter the mobile number of patient:";
		cin>>mob;
		cout<<"\n\t6. Enter the problem/disease patient suffered:";
		cin>>prob;
		cout<<"\n\t7. Enter any known person or relatives:";
		cin>>relative;
		cout<<"\n\n\t\t\t\t Saved Successfully!!!\n";
	}
	int Register()
	{
		return ptno;
	}
	void dishead()
	{
       cout<<endl<<"\t\t\t\t* PERSONAL INFORMATION *";
       cout<<endl<<"________________________";
	   cout<<"\n\n\t\t|PatReg|   Pat Name |    Age   |    Mobile   |   Address |   Problem | Relatives | ";
	   cout<<"\n\n\t\t----------------------------------------------------------------------";
	}
	void head()
	{
		cout<<"\n  				 ****************  M E D I C A L    C A R E****************";

	}
	void display()
	{
		cout<<"\n\t\t "<<ptno<<"|      |"<<pt_name<<"|       |"<<age<<"|     |"<<mob<<"|      |"<<address<<"|      |"<<prob<<"|      |"<<relative;
	}
};// patient class end
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Medicine //class medicine class start
{
char medicine[50],disease[50];
int medno;
public:
	void in() 
		{
		cout<<"\n\n\n\t * Enter the medicine number:";
		cin>>medno;
		cout<<"\n\t * Enter the disease for which medicine is specified:";
		cin>>disease;
		cout<<"\n\t * Enter the Name of medicine:";
		cin>>medicine;
		cout<<"\n\n\t\t\t\t Saved Successfully!!!\n";
	}//end of in function
	void dishead()
	{
		cout<<endl<<"\n* MEDICINE INFORMATION *";
		cout<<endl<<" ____________________";
		cout<<"\n\n\t\t | Medicine Number  |  Medicine Name  | Desease Name |  ";
		cout<<"\n\n\t\t ----------------------------------------------------";
	}
	void meddisplay()
	{
		cout<<"\n\n\t\t|\t\t|"<<medno<<"| \t\t|"<<medicine<<"|\t\t|"<<disease;
	}
};//end of medicine class 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	Patient ob;
	Medicine m;
	char option,ch;
	int rg;
	system("cls");
	initializing();
	Password();
    fstream file;
	file.open("Medical.txt",ios::ate|ios::in|ios::out|ios::binary);
	do
	{
	menu();
	cin>>option;
	switch(option)
	{
		case '1':
			system("cls");
			cout<<"\n                                 W E L C O M E   T O     M E D I C A L   C A R E ";
	    	cout<<"\n                                 -------------   ---     -------------   ------- ";
			cout<<"\n\n                               *************** ADMIT  PATIENT *************** ";
		    ob.PatientInsert();
		    file.seekp(0,ios::end);
			file.write((char*)&ob,sizeof(ob));
			break;
		   //end of case 1
		   
		 case '2':
		 {
		    system("cls");
			cout<<"\n                                 W E L C O M E   T O     M E D I C A L   C A R E ";
	       	cout<<"\n                                 -------------   ---     -------------   ------- ";	
		 	int	isFound=0;
		 	        cout<<"\n\n\t\t\t           *************** SEARCH  PATIENT *************** ";
					cout<<endl<<"\n\n\t* Enter  patient register numbmer  to be searched:";
					cin>>rg;
					file.seekg(0,ios::beg);
					file.read((char*)&ob,sizeof(ob));
					while(!file.eof())
					{
						if(ob.Register()==rg)
						{
							isFound=1;
							cout<<endl<<"\n\n\n\t\t********The  seached date is**********";
							ob.dishead();
							ob.display();
						
							break;
							
						}
						file.read((char*)&ob,sizeof(ob));
					}
					file.clear();
					if(isFound==0)
					cout<<endl<<"********************Data not found***********";
	                file.close();
	                break;
		  }//end of case 2
		  case '3':
		  		
				{
			    system("cls");
			    cout<<"\n                                 W E L C O M E   T O     M E D I C A L   C A R E ";
	        	cout<<"\n                                 -------------   ---     -------------   ------- ";
			    cout<<"\n\n\t\t\t          *************** MODIFY  PATIENT RECORD*************** ";
				int recordNo=0;
				cout<<endl<<"\n\t * Enter patient register number to be updated :";
				cin>>rg;
				 int isFound=0;
				file.seekg(0,ios::beg);
				file.read((char*)&ob,sizeof(ob));
				       while(!file.eof())
				       {
				       	recordNo++;
				       	if(ob.Register()==rg)
				       	  {
				       	  	isFound=1;
							cout<<endl<<"\t* OLD RECORD *";
							cout<<endl<<"\t _____________";
							ob.dishead(); 
				       	  	ob.display();
				       	  	break;
							 }
						 file.read((char*)&ob,sizeof(ob));
							 
					   }
					   if(isFound==0)
					    {
					   	cout<<endl<<"****************Data not Found*********"<<endl;
					   	system("pause");
					   	menu();
					   	break;
					    }
					   file.clear();
					   int location=(recordNo-1)*sizeof(ob);
					   file.seekp(location,ios::beg);
					   cout<<endl<<"\n\t * NEW INFORMATION *";
					   cout<<endl<<"\t  __________________";
					   ob.PatientInsert();
					   file.write((char*)&ob,sizeof(ob));
					   break;
				
			}  //end of case3
			  case '4':
			  		system("cls");
			  		cout<<"\n                                 W E L C O M E   T O     M E D I C A L   C A R E ";
	            	cout<<"\n                                 -------------   ---     -------------   ------- ";
			  		cout<<"\n\n\t\t\t          *************** PATIENT RECORD*************** ";
					file.clear();
					file.seekg(0,ios::beg);
					while(file.read((char*)&ob,sizeof(ob))>0);
					{
						ob.dishead();
						ob.display();
						cout<<"\n\n**********************************************************************"<<endl;
						m.dishead();
						m.meddisplay();
						cout<<endl<<"\n*******************************************************************";
							}
							file.clear();
							break;
				 			 //end of case 4
				 case '5':
				 	        system("cls");
				 	        cout<<"\n                                 W E L C O M E   T O     M E D I C A L   C A R E ";
	                    	cout<<"\n                                 -------------   ---     -------------   ------- ";
				 			cout<<endl<<"\n\n\t\t\t\t\t************ Medicine details *************";
							m.in();
							file.seekp(0,ios::end);
			         		file.write((char*)&ob,sizeof(ob));
			    			break;
					 
				 case '6':
				 	{
			     	system("cls");
					cout<<"\n                                 W E L C O M E   T O     M E D I C A L   C A R E ";
	            	cout<<"\n                                 -------------   ---     -------------   ------- ";	
					cout<<"\n\n\t\t\t           *************** BILL CALCULATION *************** "; 
                    int	isFound=0;
					cout<<endl<<"\n\n\t * Enter  patient register number  to be searched:";
					cin>>rg;
					file.seekg(0,ios::beg);
					file.read((char*)&ob,sizeof(ob));
					while(!file.eof())
					{
						if(ob.Register()==rg)
						{
							isFound=1;
							ob.dishead();
						
							ob.display();
							bill();
						
							break;
							
						}
						file.read((char*)&ob,sizeof(ob));
					}
					file.clear();
					if(isFound==0)
					cout<<endl<<"**************Data not found***********";
	                file.close();
	                last();
	                break;
                 
					 }//end of case6
				 case '7':
				 	       system("cls");
				 	        cout<<"\n\n                            W E L C O M E   T O     M E D I C A L   S Y S T E M ";
	                 		cout<<"\n                             -------------   ---     -------------   -----------";
 							cout<<"\n\n         ************** TERMS   AND   CONDITION ***************         ";
                         	cout<<"\n\n         1.Each and every patient are equal for us and we treat them equal.";
                        	cout<<"\n\n         2.medical care is registered clinic so no argument to be listened about the service.";
                           	cout<<"\n\n         3.If you have any problem then please kindly contact us and feel free.";
                           	cout<<"\n\n         4.Payment to the clinic must be made available before patient leave the clinic.";
                           	cout<<"\n\n         5.Payment made avialable is not refundable.";
                           	cout<<"\n\n         6.People should pre book their appointments to avoid inconvinance.";
                           	cout<<"\n\n         7.In case of emegency extra charge is taken.";
	                        cout<<"\n\n         8.For any dispute last decision is of medical care authorities.\n";
					 break;
			      case '8':
					exit(0);
					break;
					 default:
					 	system("cls");
					 cout<<"invalid options"<<endl;
					 	}
					   		cout<<"\n\n\n\t\t\t\t  Do you want continue...?(y/n)";
					   		cin>>ch;		
					
	}//end of switch 
		while(ch!='n');
	return 0;
}//end of program
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void last()
{
	system("cls");
	cout<<"\n                                 W E L C O M E   T O     M E D I C A L   C A R E ";
	cout<<"\n                                 -------------   ---     -------------   ------- ";
	cout<<"\n\n\n\t\t               Created By:";
	cout<<"\n                   1.Krishna Kumar Khanw";
	cout<<"\n                   2.Sabita Thapa Magar";
	cout<<"\n                   3.Rejina Mainali";
	cout<<"\n                   4.Pratigya Mishra";
	cout<<"\n\n        **ARYAN SCHOOL OF  ENGINEERING AND MANAGEMENT **";
}//end of last function
void bill()
{
		char c;
	int doc_fee,c_p,n,c_m,t_m,x;
	char pro[50];
	cout<<"\n * Enter the problem/disease patient suffered :";
	cin>>pro;
	cout<<"\n * Enter the number of days for which patient is admitted:";
	cin>>n;
	cout<<"\n * Enter the charges per day for bed:";
	cin>>c_p;
	cout<<"\n * Enter the medicine fee:";
	cin>>c_m;
	cout<<"\n * Enter the doctor fee:";
	cin>>doc_fee;
	cout<<"\n* Do you want to proceed to calculate the bill(Y/N):";
	cin>>c;
	if(c=='y'||c=='Y')
	{
		
		t_m=(c_p*n)+c_m+doc_fee;
		cout<<"\n--> Your calculated bill is:"<<t_m<<endl;
		system("PAUSE");
		
	}//end of if
}//end of bill funtion
void Password()
{
	system("cls");
	
	cout<<"\n                                 W E L C O M E   T O     M E D I C A L   C A R E ";
	cout<<"\n                                 -------------   ---     -------------   ------- ";

    char userinput[20];
    string password="aryanschool";
    cout<<"\n\n\n\n\n                                   Enter password:";
    cin>>userinput;
    if(userinput !=password)
       {
       	cout<<"\n\n                                   Invalid password ......."<<endl;
       	system("pause");
       	Password();
       	   
	   }
    else 
    cout<< "\n\n                                    Password  Match .........."<<endl;
    system("pause");
}//end of password function
void initializing()
{
	 int i; 
 i=1; 

  
 system("cls") ;
 while(i<=50) 
 { 
 cout<<"\nInitializing ............"; 
 if(i<50) 
 { 
 system("cls"); 
  } 
  i++; 
  } 
  cout<<".";
  cout<<".";
  cout<<".";
  cout<<".";
  cout<<".";
  cout<<".";
  cout<<".";
  cout<<".";
  cout<<".";
  cout<<".";
  cout<<".";
  

}



