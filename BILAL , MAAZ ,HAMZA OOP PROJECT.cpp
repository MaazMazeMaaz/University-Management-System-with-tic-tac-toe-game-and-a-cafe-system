#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;
int n= 100;
int m= 50;
class portal
{
	private:
	string  *name=new string [n];
	int   *roll_number= new int [n];
	float *lab_report= new float [n*m];
    float *lab_assessment= new float [n*m];
	float *mid_marks= new float [n];
	float *cep_marks=new float [n];
	float *final_marks=new float [n];
	float *total_lab_assessments=new float[n];
	float *total_lab_reports=new float[n];
	float *total=new float[n];
	int num;
	public: 
	void input(int a)
	{
		cout<<"ENTER THE TOTAL NUMBER OF LABS : ";
		cin>>num;
		for(int i=0;i<a;i++)
		{	
			cout<<"ENTER THE NAME OF STUDENT : ";
			cin>>name[i];
			cout<<"ENTER THE ROLL NUMBER OF STUDENT : ";
			cin>>roll_number[i];
			for(int j=0;j<num;j++)
			{
				cout<<"ENTER THE MARKS OF LAB ASSESSMENTS OUT OF 15 : "<<j+1<<" : ";
				cin>>lab_assessment[i*j];
			}
				for(int j=0;j<num;j++)
			{
				cout<<"ENTER THE MARKS OF LAB REPORTS OUT OF 15 : "<<j+1<<" : ";
				cin>>lab_report[i*j];
			}
			cout<<"ENTER THE MARKS OF MIDS OUT OF 50 : ";
			cin>>mid_marks[i];
			cout<<"ENTER THE MARKS OF CEP OUT OF 40 : ";
			cin>>cep_marks[i];
			cout<<"ENTER THE MARKS OF FINAL OUT 50 : ";
			cin>>final_marks[i];
		}
	}
	void result(int a)
	{
		float w;
		for(int i=0;i<a;i++)
		{
		for(int j=0;j<num;j++)
		{
		total_lab_assessments[i]=total_lab_assessments[i]+lab_assessment[i*j];
		total_lab_reports[i]=total_lab_reports[i]+lab_report[i*j];
		}
		w=num*15;
		total[i]=(total_lab_assessments[i]/w)*20+(total_lab_reports[i]/w)*15+(mid_marks[i]/50)
		*15+(cep_marks[i]/40)*20+(final_marks[i]/50)*30;
		}
		do
		{
		cout<<"PRESS 1 FOR CLASS RESULT "<<endl;
		cout<<"Press 2 FOR INDIVIDUAL RESULT "<<endl;
		cout<<"PRESS KEY : ";
		cin>>w;
		if(w==1)
		{
		cout<<"\t\t\t\t\t_________ RESULT __________  "<<endl<<endl<<endl;
		cout<<setw(10)<<"NAME"<<setw(20)<<"ROLL NUMBER"<<setw(20)<<"LAB ASSESSMENT"
		<<setw(20)<<"LAB REPORTS"<<setw(20)<<"MIDS MARKS"<<setw(20)<<"CEP MARKS"<<
		setw(20)<<"FINAL MARKS"<<setw(15)<<"TOTAL"<<endl;
		for(int i=0;i<a;i++)
		{
		cout<<i+1<<"- "<<name[i]<<setw(20)<<roll_number[i]<<setw(20)
		<<total_lab_assessments[i]<<setw(20)<<total_lab_reports[i]<<
		setw(20)<<mid_marks[i]<<setw(20)<<cep_marks[i]<<setw(20)<<
		final_marks[i]<<setw(20)<<total[i]<<endl;	
		}
	    }
	    else if(w==2)
	    {
	    	int r,p;
	    do
		{
			cout<<"ENTER  THE ROLL NUMBER OF STUDENT : ";
	    	cin>>r;
	    	for(int i=0;i<a;i++)
	    	{
	    		if(roll_number[i]==r)
	    		p=i;
	    		else
	    		{
	    			cout<<"YOU ENTER INVALID ROLL NUMBER "<<endl;
	    			p=-1;
				}
		    }
	   }while(p==-1);
	   cout<<"\t\t\t\t\t__________ RESULT __________ "<<endl;
	   cout<<setw(10)<<"NAME"<<setw(20)<<"ROLL NUMBER"<<setw(20)<<"LAB ASSESSMENT"
	   <<setw(20)<<"LAB REPORTS"<<setw(20)<<"MIDS MARKS"<<setw(20)<<"CEP MARKS"<<
	   setw(20)<<"FINAL MARKS"<<setw(15)<<"TOTAL"<<endl;
	   cout<<name[p]<<setw(20)<<roll_number[p]<<setw(20)
	   <<total_lab_assessments[p]<<setw(20)<<total_lab_reports[p]<<
	   setw(20)<<mid_marks[p]<<setw(20)<<cep_marks[p]<<setw(20)<<
	   final_marks[p]<<setw(20)<<total[p]<<endl;
		}
	else
	{
		cout<<"ENTER INVALID KEY ";
		w=0;
	}
    }while(w==0);
	}
	void GPA(int a)
	{
		cout<<"\t\t\t\t\t____________GPA___________"<<endl<<endl<<endl;
		for(int i=0;i<a;i++)
		{
		if(total[i]>80)
		cout<<name[i]<<" GOT  4 GPA "<<endl;
		else if(40<total[i]<=60)
		cout<<name[i]<<" GOT 3 GPA "<<endl;
		else 
		cout<<name[i]<<" GOT 2 GPA "<<endl;
		}
	}
	void file(int a)
	{
		fstream result;
		result.open("result",ios::out);
		result<<"\t\t\t\t\t______________ RESULT_____________ "<<endl<<endl<<endl;
		result<<setw(10)<<"NAME"<<setw(20)<<"ROLL NUMBER "<<setw(20)<<"LAB ASSESSMENT"
		<<setw(20)<<"LAB REPORTS"<<setw(20)<<"MIDS MARKS"<<setw(20)<<"CEP MARKS"<<
		setw(20)<<"FINAL MARKS"<<setw(15)<<"TOTAL"<<endl;
		for(int i=0;i<a;i++)
		{
		result<<i+1<<"- "<<name[i]<<setw(20)<<roll_number[i]<<setw(20)
		<<total_lab_assessments[i]<<setw(20)<<total_lab_reports[i]<<
		setw(20)<<mid_marks[i]<<setw(20)<<cep_marks[i]<<setw(20)<<
		final_marks[i]<<setw(20)<<total[i]<<endl;	
		}
	}
	
};
class cafe
{
	private:
	float total;
	int year,month,day;
	int hr,min,sec;
	float bill=0;
	public:
	cafe()
	{
	time_t t_time=time(0);
	tm *local_time=localtime(&t_time);
	year=1900+local_time->tm_year;
	month=1+local_time->tm_mon;
	day=local_time->tm_mday;
	hr=1+local_time->tm_hour;
	min=1+local_time->tm_min;
	sec=1+local_time->tm_sec;	
	}
	int getweekday()
{

    int d = day+ ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
        + (365 * (year + 4800 - ((14 - month) / 12)))
        + ((year + 4800 - ((14 - month) / 12)) / 4)                             // using Zeller's congruence algorithm
        - ((year + 4800 - ((14 - month) / 12)) / 100)
        + ((year + 4800 - ((14 - month) / 12)) / 400)
        - 32045;
    return (d + 1) % 7;
}   
    void menu()
	{
		int check,d;
		d=getweekday()+1;
		switch(d)
		{
			case 1:
			do
			{
				check=0;
			cout<<"\t ________TODAY IS SUNDAY WE OFFERING YOU FOLLOWING MENU________ "<<endl;
			cout<<"Press 1 for BIRYANI in only 250 "<<endl;
			cout<<"Press 2 for BURGER in only 200 "<<endl;
			cout<<"Press 3 for FRIES in only 100 "<<endl;
			cout<<"PRESS KEY : ";
			cin>>check;
			switch(check)
			{
				case 1:
				bill=bill+250;
				break;
				case 2:
				bill=bill+200;
				break;
				case 3:
				bill=bill+100;
				break;
				default:
				cout<<"YOU ENTER INVALID KEY  "<<endl;
	    	}
			cout<<"PRESS 1 IF YOU WANT TO RAPEAT MENU : ";
			cin>>check;
		    }while (check==1);
		    break;
		    case 2:
			do
			{
				check=0;
			cout<<"\t ________TODAY IS MONDAY WE OFFERING YOU FOLLOWING MENU________ "<<endl;
			cout<<"Press 1 for SHAKE in only 250 "<<endl;
			cout<<"Press 2 for BURGER in only 200 "<<endl;
			cout<<"Press 3 for SANDWITCH in only 100 "<<endl;
			cout<<"PRESS KEY : ";
			cin>>check;
			switch(check)
			{
				case 1:
				bill=bill+250;
				break;
				case 2:
				bill=bill+200;
				break;
				case 3:
				bill=bill+100;
				break;
				default:
			cout<<"YOU ENTER INVALID KEY  "<<endl;
			}
	cout<<"PRESS 1 IF YOU WANT TO RAPEAT MENU : ";
		cin>>check;
		    }while (check==1);
		    break;
		    case 3:
			do
			{
				check=0;
		cout<<"\t ________TODAY IS TUESDAY WE OFFERING YOU FOLLOWING MENU________ "<<endl;
			cout<<"Press 1 for PIZZA in only 250 "<<endl;
			cout<<"Press 2 for BIRYANI in only 200 "<<endl;
			cout<<"Press 3 for COKE in only 100 "<<endl;
			cout<<"PRESS KEY : ";
			cin>>check;
			switch(check)
			{
				case 1:
				bill=bill+250;
				break;
				case 2:
				bill=bill+200;
				break;
				case 3:
				bill=bill+100;
				break;
				default:
				cout<<"YOU ENTER INVALID KEY  "<<endl;;
			}
		   cout<<"PRESS 1 IF YOU WANT TO RAPEAT MENU : ";
	     	cin>>check;
		    }while (check==1);
		    break;
		    case 4:
			do
			{
				check=0;
			cout<<"\t ________TODAY IS WEDNESDAY WE OFFERING YOU FOLLOWING MENU________ "<<endl;
			cout<<"Press 1 for BANANAS in only 250 "<<endl;
			cout<<"Press 2 for BURGER in only 200 "<<endl;
			cout<<"Press 3 for SAMOSA in only 100 "<<endl;
			cout<<"PRESS KEY : ";
			cin>>check;
			switch(check)
			{
				case 1:
				bill=bill+250;
				break;
				case 2:
				bill=bill+200;
				break;
				case 3:
				bill=bill+100;
				break;
				default:
				cout<<"YOU ENTER INVALID KEY  "<<endl;
			}
		   	cout<<"PRESS 1 IF YOU WANT TO RAPEAT MENU : ";
	     	cin>>check;
		    }while (check==1);
		    break;
		    case 5:
			do
			{
				check=0;
		    cout<<"\t ________TODAY IS THURSDAY WE OFFERING YOU FOLLOWING MENU________ "<<endl;
			cout<<"Press 1 for PARATHA ROLL in only 250 "<<endl;
			cout<<"Press 2 for CHIPS in only 200 "<<endl;
			cout<<"Press 3 for COKE in only 100 "<<endl;
			cout<<"PRESS KEY : ";
			cin>>check;
			switch(check)
			{
				case 1:
				bill=bill+250;
				break;
				case 2:
				bill=bill+200;
				break;
				case 3:
				bill=bill+100;
				break;
				default:
				cout<<"YOU ENTER INVALID KEY  "<<endl;
			}
		   	cout<<"PRESS 1 IF YOU WANT TO RAPEAT MENU : ";
	     	cin>>check;
		    }while (check==1);
		    break;
		    case 6:
			do
			{
				check=0;
			cout<<"\t ________TODAY IS FRIDAY WE OFFERING YOU FOLLOWING MENU________ "<<endl;
			cout<<"Press 1 for BIRYANI in only 250 "<<endl;
			cout<<"Press 2 for PIZZA in only 200 "<<endl;
			cout<<"Press 3 for COKE in only 100 "<<endl;
			cout<<"PRESS KEY : ";
			cin>>check;
			switch(check)
			{
				case 1:
				bill=bill+250;
				break;
				case 2:
				bill=bill+200;
				break;
				case 3:
				bill=bill+100;
				break;
			    default:
			cout<<"YOU ENTER INVALID KEY  "<<endl;
			}
		   	cout<<"PRESS 1 IF YOU WANT TO RAPEAT MENU : ";
	     	cin>>check;
		    }while (check==1);
		    break;
		    case 7:
			do
			{
				check=0;
		cout<<"\t ________TODAY IS SATURDAY WE OFFERING YOU FOLLOWING MENU________ "<<endl;
			cout<<"Press 1 for WINGS in only 250 "<<endl;
			cout<<"Press 2 for LAYS in only 200 "<<endl;
			cout<<"Press 3 for JUICE in only 100 "<<endl;
			cout<<"PRESS KEY : ";
			cin>>check;
			switch(check)
			{
				case 1:
				bill=bill+250;
				break;
				case 2:
				bill=bill+200;
				break;
				case 3:
				bill=bill+100;
				break;
				default:
				cout<<"YOU ENTER INVALID KEY  "<<endl;
			}
			cout<<"PRESS 1 IF YOU WANT TO RAPEAT MENU : ";
			cin>>check;
		    }while (check==1);
		    break;
		}
    }   
	void printbill()
	{
	cout<<"\t\t\t\t\t __ ___ ___ ___ ___ ___ ___ ___ ___ "<<endl<<endl;
	cout<<"\t\t\t\t\t| \t\t\t\t   | "<<endl;
	cout<<"\t\t\t\t\t| \t\t\t\t   | "<<endl;
	cout<<"\t\t\t\t\t|\tYOUR TOTAL BILL = "<<bill<<"      |"<<endl;
	cout<<"\t\t\t\t\t| \t\t\t\t   | "<<endl;
	cout<<"\t\t\t\t\t| \t\t\t\t   | "<<endl;
	cout<<"\t\t\t\t\t| \t\t\t\t   | "<<endl;
	cout<<"\t\t\t\t\t| \t\t\t\t   | "<<endl;
	cout<<"\t\t\t\t\t|DATE = "<<day<<"/"<<month<<"/"<<year<<"\t\t   |"<<endl;
	cout<<"\t\t\t\t\t|TIME = "<<hr<<":"<<min<<":"<<sec<<"\t\t\t   |"<<endl;
	cout<<"\t\t\t\t\t __ ___ ___ ___ ___ ___ ___ ___ ___"<<endl;
	bill=0;	
	}                                    
};
class tictac{
public:
    char spaces[3][3];
    char player;
    tictac(){
        for (int i= 0;i<3;i++) {
            for (int j = 0; j<3; j++) {
                spaces[i][j]='-';
            }
        }
        player='X';
    }
    void display(){
        cout<<endl;
        for (int i=0;i<3;i++) {
            cout<<"| ";
            for(int j = 0; j < 3; j++) {
            cout<<spaces[i][j]<<" | ";
            }
            cout<<endl;
        }
    }
     bool play(int row, int col) {
        
        if(spaces[row][col]!='-') {
            return false;
        }
        spaces[row][col]=player;
        changeplayer();
        return true;
    }
     char check(){
        for(int i=0;i<3;i++) {
            if(spaces[i][0]==spaces[i][1]&&spaces[i][1]==spaces[i][2]&&spaces[i][0]!='-') {
                return spaces[i][0];
            }
        }
        
        for(int j=0;j<3;j++){
            if(spaces[0][j]==spaces[1][j]&&spaces[1][j]==spaces[2][j]&&spaces[0][j]!='-') {
                return spaces[0][j];
            }
        }
        
        if(spaces[0][0]==spaces[1][1]&&spaces[1][1]==spaces[2][2]&&spaces[0][0]!='-') {
            return spaces[0][0];
        }
        if(spaces[0][2]==spaces[1][1]&&spaces[1][1]==spaces[2][0]&&spaces[0][2]!='-') {
            return spaces[0][2];
        }
        int draw =1;
        for (int i = 0; i < 3; i++) 
		{
        for (int j = 0; j < 3; j++)
		 {
                if (spaces[i][j] == '-') 
				{
                    draw =0;
                    break;
                }
            }
        }
        if (draw==1) {
            return 'D';
        }
        else
        return '-';
    }
        
    void changeplayer(){
        if(player=='X') {
        player='O';
        } else{
        player='X';
        }
    }
    char getplayer()
    {
    	return player;
	}
};

int main()
{
	cafe uni;
	const char *day[]={"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"}; 
	portal Air[4];
	int check,st_num;
	int ch_num=0;

	do
	{
 cout<<"\t\t\t\t\t ___________________________________________________________"<<endl;		  
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl;  
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl;
 cout<<"\t\t\t\t\t|***************** -------------------- ********************|"<<endl;
 cout<<"\t\t\t\t\t|*****************|  CEP PRESENTATION  |********************|"<<endl;
 cout<<"\t\t\t\t\t|*****************|  PRESENTED BY      |********************|"<<endl;
 cout<<"\t\t\t\t\t|*****************|  BILAL TARIQ       |********************|"<<endl;
 cout<<"\t\t\t\t\t|*****************|  M. MAAZ           |********************|"<<endl;
 cout<<"\t\t\t\t\t|*****************|  HAMZA SARFRAZ     |********************|"<<endl;
 cout<<"\t\t\t\t\t|***************** -------------------- ********************|"<<endl;
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl;  
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl; 
 cout<<"\t\t\t\t\t ___________________________________________________________"<<endl;  
  cout<<endl<<endl; 
	cout<<"PRESS 1 FOR TEACHER PORTAL "<<endl;
	cout<<"PRESS 2 FOR UNVERSITY CAFE "<<endl;
	cout<<"PRESS 3 FOR GAMING ZONE "<<endl;
	cout<<"PRESS KEY : ";
	cin>>check;
	if(check==1)
	{
	do
	{
	do
	{
 cout<<"\t\t\t\t\t ___________________________________________________________"<<endl;		  
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl;  
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl;
 cout<<"\t\t\t\t\t|******************--------------------*********************|"<<endl;
 cout<<"\t\t\t\t\t|*****************|   TEACHER PORTAL  |*********************|"<<endl;
 cout<<"\t\t\t\t\t|******************--------------------*********************|"<<endl;
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl;  
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl; 
 cout<<"\t\t\t\t\t ___________________________________________________________"<<endl; 
 cout<<endl<<endl;
	cout<<"PRESS 1 TO ENTER DATA OF CLASS CE 112L BET 2B "<<endl;
	cout<<"PRESS 2 TO ENTER DATA OF CLASS CE 112L BET 2A "<<endl;
	cout<<"PRESS 3 TO ENTER DATA OF CLASS CE 112L BEEP 2A"<<endl;
	cout<<"PRESS 4 TO ENTER DATA OF CLASS CE 112L BEEE 2A"<<endl;
	cout<<"PRESS KEY : "; 
	cin>>check;
	if (check==1)
    cout<<"YOU SELECT CE 112L BET 2B"<<endl;
    else if (check==2)
    cout<<"YOU SELECT CE 112L BET 2A"<<endl;
    else if (check==3)
    cout<<"YOU SELECT CE 112L BEEP 2A"<<endl;
    else if (check==4)
    cout<<"YOU SELECT CE 112L BEEE 2A"<<endl;
    else
    {
    do{
    	cout<<"YOU ENTER INVALID KEY "<<endl;
    	cout<<"PRESS 5 TO RAPEAT ";
    	cin>>check;
    	system("CLS");
	  }while(check!=5);
    	system("CLS");
	}
    }while(check==5);
    cout<<"ENTER THE NUMBER OF STUDENT IN CLASS : ";
    cin>>st_num;
    Air[ch_num].input(st_num);
    Air[ch_num].result(st_num);
    cout<<"PRESS 1 TO CALCULATE GPA : ";
    cin>>check;
    if(check==1)
    Air[ch_num].GPA(st_num);
    check=0;
    cout<<"PRESS 1 IF YOU WANT TO MAKE FILE OF RESULT : ";
    cin>>check;
    if(check==1)
    Air[ch_num].file(st_num);
    cout<<"PRESS 1 TO ENTER DATA OF ANOTHER CLASS";
    cout<<" OR ANY OTHER KEY TO EXIT : ";
    cin>>check;
    ch_num++;
    if(ch_num>3)
    {
    	cout<<"\t\t_______FOUR CLASSES COMPLETED________ "<<endl;
    	break;
	}
}while(check==1);
check=0;
}
if(check==2)
{
 cout<<"\t\t\t\t\t ___________________________________________________________"<<endl;		  
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl;  
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl;
 cout<<"\t\t\t\t\t|***************** ------------------- *********************|"<<endl;
 cout<<"\t\t\t\t\t|*****************|  UNIVERSITY CAFE  |*********************|"<<endl;
 cout<<"\t\t\t\t\t|***************** ------------------- *********************|"<<endl;
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl;  
 cout<<"\t\t\t\t\t|***********************************************************|"<<endl; 
 cout<<"\t\t\t\t\t ___________________________________________________________"<<endl; 
  cout<<endl<<endl; 
    uni.menu();
	uni.printbill();	

check=0;}
if(check==3)
{
	tictac t;
	int row,col;
	while(t.check()=='-'){
        t.display();
        cout<<"Player: "<<t.getplayer()<<": Enter desired row and column: ";
        cin>>row>>col;
        if(!t.play(row,col)){
            cout<<"That spot is already taken,try again"<<endl;
        }
    }
	t.display();
	char result = t.check();
    if (result == 'X') {
        cout << "Player X is the winner!" << endl;
    }
    else if (result == 'O') {
        cout << "Player O is the winner!" << endl;
    }
    else if (result == 'D') {
        cout << "It's a draw!" << endl;
    }
	check=0;
}
cout<<"PRESS 1 IF YOU WANT TO REPEAT WHOLE PROGRAM : ";
cin>>check;
}while(check==1);
	return 0;
}

