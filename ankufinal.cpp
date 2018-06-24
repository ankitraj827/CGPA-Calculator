#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;
unsigned int sub_no,term_no,cgpacredit=0;
float gpa[10],cgpagpa=0,CGPA;
float totCredit[10];
class STUDENT
{
	public:
	string name;
	float To_gpa[8];
	string reg_no,rg_no;
	string roll_no;
	string subjectg[10];
	int subjectc[10];
	public:
		void ankit();
		void calculate();
		void introfunction();
		void read();
		void ptrcalfun();
		
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void STUDENT::introfunction()
{
		cout<<endl<<endl<<endl;
	    cout<<"\t\t******************************************************"<<endl;
		cout<<"\t\t*                 WELCOME TO GPA CALCULATOR          *"<<endl;
		cout<<"\t\t*\t\t\t\t\t\t     *"<<endl;
		cout<<"\t\t******************************************************"<<endl;
		cout<<endl<<endl<<"\tThis program is written under the mini-project.\n\n\tProgram written by: Ankit Raj\n\tReg. No.\t  : 11505308\n\tRoll No.\t  : 08\n\tSection\t\t  : K1506\n\tTopic assigned by : Mr. Raj Karan Singh.\n\n";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void STUDENT::ankit()
{
	    fstream obj;
		cout<<endl<<"Enter the details of student";
		cout<<"\nEnter the name of student : ";
		cin.sync();
		getline(cin,name);
		cout<<endl<<"Enter Registraton no. ";
		cin.sync();
		getline(cin,reg_no);
		cout<<endl<<"Enter the roll no : ";
		cin.sync();
		getline(cin,roll_no);
		rg_no=reg_no+".txt";
		obj.open(rg_no.c_str(),ios::app|ios::out|ios::in);
		obj<<endl<<"Name of student     : "<<name;
		obj<<endl<<"Registration number : "<<reg_no;
		obj<<endl<<"Roll number         : " <<roll_no<<endl;
		calculate();
		fflush(stdin);
		cin.clear();
	cout<<"\nCGPA of your score :"<<CGPA<<endl<<endl;	
	obj<<endl<<"CGPA of your score : "<<CGPA;	
		
	cout<<"\n******************************************************************************"<<endl;
    obj.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void STUDENT::calculate()
{
	fstream obj;
	obj.open(rg_no.c_str(),ios::app|ios::out|ios::in);
	int i,j,term_no;
	char grade[7];
	int credit[10];
	 gpa[0]=0;
	 totCredit[0]=0;
	cout<<"\nEnter number of terms : ";
	cin>>term_no;
	for(j=0;j<term_no;j++)
	{
		cout<<"\nEnter the details of semester"<<j+1;
		cout<<endl<<"Enter the number of subject for which TGPA is to be calculated :";
		cin>>sub_no;
		mogu:
		for(i=0;i<sub_no;i++)
		{
			cout<<endl<<"Enter the details of subject"<<i+1;
			cout<<endl<<"Grade(in A,B,C,D,E,F,G,H): ";
			cin>>grade[i];
			subjectg[i]=grade[i];
			cout<<"Credit(in 1 to 10)       : ";
			cin>>credit[i];
			subjectc[i]=credit[i];
        	switch (grade[i]) 
			{
                        case 'A':
                                gpa[j] = gpa[j] + 10 * credit[i];
                                totCredit[j] = totCredit[j] + credit[i];
                                break;


                        case 'B':

                                gpa[j]= gpa[j] + 9 * credit[i];

                                totCredit[j] = totCredit[j] + credit[i];

                                break;




                        case 'C':

                                gpa[j] = gpa[j] + 8 * credit[i];

                                totCredit[j] = totCredit[j] + credit[i];

                                break;




                        case 'D':

                                gpa[j] = gpa[j] + 7 * credit[i];

                                totCredit[j] = totCredit[j] + credit[i];

                                break;




                        case 'E':

                                gpa[j] = gpa[j] + 6 * credit[i];

                                totCredit[j] = totCredit[j] + credit[i];

                                break;




                        case 'F':

                                gpa[j] = gpa[j] + 5 * credit[i];

                                totCredit[j] = totCredit[j] + credit[i];

                                break;
								
								
						case 'G':
						          
								 gpa[j]=gpa[j] + 4 * credit[i];
								 
								 totCredit[j] = totCredit[j] + credit[i];
								 
								 break;   
								 
						case 'H':
							
							     gpa[j]=gpa[j] + 0 *credit[i];
							     
							     totCredit[j] = totCredit[j] + credit[i];
							     
							     break;
                                
                                




                        default:

                                printf("Given Wrong grade!!\n");
                                cout<<"Enter valid grade."<<endl;
                                goto mogu;

            }

    	}
        cout<<endl<<"Total credit: "<<totCredit[j];
        To_gpa[j] = (gpa[j] / totCredit[j]);
        	
		{
				obj<<endl<<endl<<"Details for semester"<<j+1<<endl;
				cout<<endl<<"Details for semester"<<j+1<<endl;
				obj<<"--------------------------------------------"<<endl;
				obj<<"Subject\t\t"<<"Grade\t\t"<<"Credit"<<endl;
				cout<<"Subject\t\t"<<"Grade\t\t"<<"Credit"<<endl;
				for(i=0;i<sub_no;i++)
				{
				obj<<setw(2)<<i+1<<"."<<setw(16)<<subjectg[i]<<setw(18)<<subjectc[i]<<endl;
				cout<<setw(2)<<i+1<<"."<<setw(16)<<subjectg[i]<<setw(18)<<subjectc[i]<<endl;
				}
		        cout<<endl<<"Total TGPA for your score: "<<To_gpa[j]<<endl;
				obj<<endl<<"Total TGPA for your score:   "<<To_gpa[j]<<endl<<endl<<endl;
			
		}
	}
	for(j=0;j<term_no;j++)
	{
		cgpagpa=cgpagpa+gpa[j];
		cgpacredit=cgpacredit+totCredit[j];
	}
	CGPA=cgpagpa/cgpacredit;
	cin.sync();
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void STUDENT::read()
	{
	ifstream fin;
	string var,reg,rg,pline="";
	cout<<"\n\nEnter registration number : ";
	cin.sync();
	getline(cin,reg);
	system("cls");
	rg=reg+".txt";
	fin.open(rg.c_str(),ios::in);
	if(fin.fail())
		{
		cout<<"\n Entered worng registration number or file does not exist... "<<endl<<"Try again..."<<endl<<endl;
		}
	else
		{
			while(!fin.eof())
			{
				getline(fin,var);
				if(var!=pline)
				{
					
					pline=var;
					cout<<var<<endl;
					
				}
				
			}
			
		}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void STUDENT::ptrcalfun()
{
	cout<<"The calculation of gpa in this program is according to given below pattern "<<endl<<endl;
	cout<<" Letter Grade\t\t\tPerformance\t\t\tGrade Points  "<<endl<<endl;
	cout<<" A           \t\t\tOutstanding\t\t\t       10     "<<endl;
	cout<<" B           \t\t\tVery good  \t\t\t        9     "<<endl;
	cout<<" C           \t\t\tGood       \t\t\t        8     "<<endl;
	cout<<" D           \t\t\tAbove Average\t\t\t        7     "<<endl;
	cout<<" E           \t\t\tAverage    \t\t\t        6     "<<endl;
	cout<<" F           \t\t\tBelow Average\t\t\t        5     "<<endl;
	cout<<" G           \t\t\tMarginal pass\t\t\t        4     "<<endl;
	cout<<" H           \t\t\tFail       \t\t\t        0     "<<endl; 
	//cout<<endl<<"% is calculated on : %(percentile)   = Tgpa * 9"<<endl;                             
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int main()
  {
  	char c;
  	STUDENT s;
  	system("color 0B");
  	s.introfunction();
  	
  	while(1)
  	{
  		cout<<endl<<"\t\t\tMAIN MENU";
  		cout<<endl<<"\t\t\tTo Calculate your GPA\t\t\t\t[press 1] :";
  		cout<<endl<<"\t\t\tTo See previous record\t\t\t\t[press 2] :";
  		cout<<endl<<"\t\t\tTo see pattern of GP(Grade Point) assignment    [press 3] :";
  		cout<<endl<<"\t\t\tExit\t\t\t\t\t\t[press 4] :";
  		cout<<endl<<"Enter your choise :";
  		cin>>c;
  		switch(c)
  		{
  			case '1':
  				{
  					system("cls");
  					s.ankit();
  					cin.sync();
  					break;
  				}
  			case '2':
  				{
  					system("cls");
  					s.read();
  					break;
				}
				
			case '3':
					{
						system("cls");
						s.ptrcalfun();
						break;
						
					}
			case '4':
				{
					cout<<"Thank you.."<<endl<<"written by Ankit raj.";
					getch();
					exit(0);
				}
			default:
				{
					cout<<endl<<"You entered worng choise ";
					cout<<endl<<"Press any key to try again"<<endl<<endl;
					getch();
					break;
				}
		}
   }
  	getch();
  	return 0;
  }
