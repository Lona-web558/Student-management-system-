#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

char adminf[20]="Trip.txt";
char userf[20]="Reservation.txt";

struct tour{
 	char ad_id[20],ad_email[20],ad_studentno[20],ad_number[20];
 	char us_phone[20],us_id[20],us_people[20],us_date[20],us_status[20],us_sno[20];
};

class Tourist{
             public:
                void ad_pack(tour r);
	            tour ad_unpack(char a[]);
	            void ad_writedata();
	            void ad_display();
	            void ad_modify();
	            void us_pack(tour r);
	            tour us_unpack(char a[]);
	            void us_writedata();
	            void us_display();
	            void us_search();
	            void us_modify();
};

// ADMIN PANEL
void Tourist ::ad_pack(tour r){
     fstream fp;
     fp.open(adminf,ios::out|ios::app);
     if(!fp){
		cout<<"\nCannot open file";
		exit(0);
     }
     char buff[45];
     strcpy(buff,r.ad_id);
     strcat(buff,"|");
     strcat(buff,r.ad_email);
     strcat(buff,"|");
     //strcat(buff,r.ad_country);
     //strcat(buff,"|");
     strcat(buff,r.ad_studentno);
     strcat(buff,"|");
     strcat(buff,r.ad_number);
     strcat(buff,"|");
     for(int i=0;i<45-strlen(buff);i++)
            strcat(buff,"|");
     fp<<buff<<endl;
     fp.close();
}

tour Tourist::ad_unpack(char buff[]){
	tour r;
	int i=0,j=0;
	while(buff[j]!='|')
	      r.ad_id[i++]=buff[j++];
	r.ad_id[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_email[i++]=buff[j++];
	r.ad_email[i]='\0';
	i=0;
	j++;
	/**while(buff[j]!='|')
	      r.ad_country[i++]=buff[j++];
	r.ad_country[i]='\0';
	i=0;
	j++;**/
	while(buff[j]!='|')
	      r.ad_studentno[i++]=buff[j++];
	r.ad_studentno[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_number[i++]=buff[j++];
	r.ad_number[i]='\0';
	return(r);
}

void Tourist::ad_writedata(){
    tour s;
    cout<<"Enter the Student's ID number\nD-";
    cin>>s.ad_id;
    cout<<"Enter the Student's email address\n";
    cin>>s.ad_email;
    //cout<<"Enter the Country of the Destination\n";
    //cin>>s.ad_country;
    cout<<"Enter the Student's student number\n";
    cin>>s.ad_studentno;
    cout<<"Enter the Student's number\n";
    cin>>s.ad_number;
    ad_pack(s);
}


void Tourist::ad_display(){
 	fstream fp;
   	char buff[45];
   	tour r;
    fp.open(adminf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"-------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\t\tID NUMBER\tEMAIL\t\STUDENT NO.\t\tNUMBER\n";
    cout<<"-------------------------------------------------------------------------------------------------\n";
    int c=1;
    while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
       		r=ad_unpack(buff);
        cout<<c++<<"\t\t"<<r.ad_id<<"\t\t"<<r.ad_email<<"\t\t" <<r.ad_studentno<<"\t\t"<<r.ad_number<<endl;
    }
    fp.close();
    return;
}


void Tourist ::ad_modify(){
    fstream fp;
    char ad_id[15],buff[45];
    int i,j,ch;
    tour s[100];
    fp.open(adminf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"\nENTER THE STUDENT ID TO BE MODIFIED: ";
    cin>>ad_id;
    i=0;
   	while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
        s[i]=ad_unpack(buff);
        i++;
    }
   	for(j=0;j<i;j++){
       		if(strcmp(s[j].ad_id,ad_id)==0){
                    cout<<"STUDENT DETAILS\n";
                    cout<<"\n Student ID : "<<s[j].ad_id;
                    cout<<"\n Student Email : "<<s[j].ad_email;
                    //cout<<"\nDestination Country: "<<s[j].ad_country;
                    cout<<"\n Student number : "<<s[j].ad_studentno;
                    cout<<"\n Student number : "<<s[j].ad_number;
                    cout<<"\n What do you want to Update: ";
	  		cout<<"\n\n\t\tEnter 1 for changing Email address\n";
	  		cout<<"\t\tEnter 2 for changing Student number\n";
	  		cout<<"\t\tEnter 3 for changing Student number\n";
	  		cout<<"\t\t\t";
	  		cin>>ch;
	  		switch(ch){
                case 1:
                    cout<<"Email address: ";
                    cin>>s[j].ad_email;
                    //cout<<"Student number: ";
                    //cin>>s[j].ad_studentno;
                    break;
                case 2:
                    cout<<"Student number: ";
                    cin>>s[j].ad_studentno;
                    break;
                case 3:
                    cout<<"Student cellphone number : ";
                    cin>>s[j].ad_number;
                    break;
	  		}
                    break;
            }
    }
   	if(j==i){
        cout<<"\n STUDENT DETAILS NOT FOUND";
        return;
    }
    fp.close();
    fstream fd;
    fd.open(adminf,ios::out|ios::trunc);
    if(!fd){
        cout<<"\nFile Not Found";
        exit(0);
    }
   	for(j=0;j<i;j++)
         ad_pack(s[j]);
   	fd.close();
}


// USER PANEL


void Tourist ::us_pack(tour r){
    fstream fp;
    fp.open(userf,ios::out|ios::app);
    if(!fp){
        cout<<"\nFile Not Found";
		exit(0);
    }
    char buff[45];
    strcpy(buff,r.us_id);
    strcat(buff,"|");
    strcat(buff,r.us_phone);
    strcat(buff,"|");
    strcat(buff,r.us_people);
    strcat(buff,"|");
    strcat(buff,r.us_sno);
    strcat(buff,"|");
    strcat(buff,r.us_date);
    strcat(buff,"|");
    strcat(buff,r.us_status);
    strcat(buff,"|");
    for(int i=0;i<45-strlen(buff);i++)
     	strcat(buff,"|");
    fp<<buff<<endl;
    fp.close();
}


tour Tourist::us_unpack(char buff[]){
	tour r;
	int i=0,j=0;
	while(buff[j]!='|')
	      r.us_id[i++]=buff[j++];
	r.us_id[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_phone[i++]=buff[j++];
	r.us_phone[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_people[i++]=buff[j++];
	r.us_people[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_sno[i++]=buff[j++];
	r.us_sno[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_date[i++]=buff[j++];
	r.us_date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_status[i++]=buff[j++];
	r.us_status[i]='\0';
	return(r);
}
void Tourist::us_writedata(){
    tour r;
    cout<<"ENTER YOUR ID number : ";
    cin>>r.us_id;
    cout<<"ENTER YOUR CONTACT NO.: ";
    cin>>r.us_phone;
    cout<<"ENTER NO. OF STUDENTS : ";
    cin>>r.us_people;
    cout<<"ENTER YOUR STUDENT NUMBER: S-";
    cin>>r.us_sno;
    cout<<"ENTER DATE OF STUDYING (DD/MM/YY): ";
    cin>>r.us_date;
    cout<<"\nENTER 'Confirm' TO CONFIRM YOUR DETAILS: ";
    cin>>r.us_status;
    us_pack(r);
}

void Tourist::us_display(){
 	fstream fp;
   	char buff[45];
   	tour r;
    fp.open(userf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\tID number \t\tCONTACT NO\t\tTOTAL STUDENTS\t\tDATE\t\STUDENT NUMBER \t\tSTATUS\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    int c=1;
    while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
       		r=us_unpack(buff);
        cout<<c++<<"\t"<<r.us_id<<"\t\t"<<r.us_phone<<"\t\t"<<r.us_people<<"\t\t\t"<<r.us_date<<"\t\t"<<r.us_sno<<"\t\t"<<r.us_status<<endl;
    }
    fp.close();
    return;
}


void Tourist ::us_modify(){
    fstream fp;
    char us_id[15],buff[45];
    int i,j;
    tour s[100];
    fp.open(userf,ios::in);
    if(!fp){
		cout<<"\nFile not Found";
		exit(0);
    }
    cout<<"\nEnter Your ID number to cancel  your application: ";
    cin>>us_id;
    i=0;
   	while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
        s[i]=us_unpack(buff);
        i++;
    }
   	for(j=0;j<i;j++){
        if(strcmp(s[j].us_id,us_id)==0){
	  		cout<<"\nYour Student Details are:\n";
	  		cout<<"\n ID number : "<<s[j].us_id;
	  		cout<<"\nContact No.: "<<s[j].us_phone;
	  		cout<<"\nNo.of Students: "<<s[j].us_people;
	  		cout<<"\n Student number : "<<s[j].us_sno;
	  		cout<<"\nDate of Studying: "<<s[j].us_date;
	  		cout<<"\nStatus: "<<s[j].us_status;
	  		cout<<"\n\nENTER 'Cancel' TO CANCEL YOUR APPLICATION: \n";
	  		cin>>s[j].us_status;
	  		cout<<"\nYour Application has been Cancelled\n";
	  		cout<<"\n\nID number : "<<s[j].us_id;
	  		cout<<"\nContact No.: "<<s[j].us_phone;
	  		cout<<"\nNo.of People: "<<s[j].us_people;
	  		cout<<"\nStudent number: "<<s[j].us_sno;
	  		cout<<"\nDate of Studying: "<<s[j].us_date;
	  		cout<<"\nStatus: "<<s[j].us_status;
            break;
        }
    }
   	if(j==i){
        cout<<"\nRECORD NOT FOUND";
        return;
    }
    fp.close();
    fstream fd;
    fd.open(userf,ios::out|ios::trunc);
    if(!fd){
        cout<<"\nCannot open file";
        exit(0);
    }
   	for(j=0;j<i;j++)
        us_pack(s[j]);
   	fd.close();
}

void Tourist::us_search(){
 	fstream fp;
 	char us_id[15],buff[45];
 	int i,j;
 	tour s;
    fp.open(userf,ios::in);
    if(!fp){
	 	cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"\nENTER THE STUDENT ID TO BE SEARCHED: ";
    cin>>us_id;
    i=0;
   	while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
        s=us_unpack(buff);
        if(strcmp(s.us_id,us_id)==0){
	  	 	cout<<"\n STUDENT DETAILS \n";
	  		cout<<"\N STUDENT ID: "<<s.us_id;
	  		cout<<"\nCONTACT NO.: "<<s.us_phone;
	  		cout<<"\nNO. OF STUDENTS: "<<s.us_people;
	  		cout<<"\nDATE OF STUDYING: "<<s.us_date;
	  		cout<<"\n STUDENT STATUS: "<<s.us_status;
	  		return;
	 	}
    }
    cout<<"\nAPPLICATION NOT FOUND";
    return;
}

int main(){
    cout<<"                              \t\t WELCOME TO STUDENT MANAGEMENT SYSTEM\n\n\n";
    cout<<"                                   \t    STUDENT MANAGEMENT SOFTWARE\n\n\n";
    cout<<"                                     \t      PRESS ENTER TO CONTINUE....\n\n";
    if(cin.get()=='\n'){
        system("cls");
        int choice,ch1,ch2;
        Tourist obj;
        cout<<"\n Who are You?\n";
        cout<<"1. ADMIN\n";
        cout<<"2. STUDENT\n\n";
        cout<<"Enter any other key for exit\n\n\n";
        cout<<"Enter Your Option\n";
        cin>>choice;
        switch(choice){
            case 1:
                system("cls");
                cout<<"WELCOME ADMIN\n";
                cout<<"Enter your option\n";
                cout<<"1. Student's details \n";
                cout<<"2. View a single student's details \n";
                cout<<"3. View all student's details \n";
                cout<<"4. Update student details \n";
                cout<<"Enter any other key for exit\n\n";
                while(1){
                    cout<<"\nENTER UR CHOICE: ";
                    cin>>ch1;
                    switch(ch1){
                        case 1:
                            obj.ad_writedata();
                            break;
                        case 2:
                            obj.ad_display();
                            break;
                        case 3:
                            obj.us_display();
                            break;
                        case 4:
                            obj.ad_modify();
                            break;
                        default:
                            exit(0);
            }
        }
            case 2:
                system("cls");
                cout<<"WELCOME STUDENT\n";
                cout<<"Enter your option\n";
                cout<<"1. Register\n";
                cout<<"2. Search Application \n";
                cout<<"3. Cancel Application \n";
                cout<<"Enter any other key for exit\n\n\n";
                while(1){
                    cout<<"\nENTER UR CHOICE: ";
                    cin>>ch2;
                    switch(ch2){
                        case 1:
                            cout<<"-----------------------------------";
                            cout<<"\n Enter details \n";
                            cout<<"-----------------------------------\n";
                            obj.ad_display();
                            cout<<"\n";
                            obj.us_writedata();
                            break;
                        case 2:
                            obj.us_search();
                            break;
                        case 3:
                            obj.us_modify();
                            break;
                        default:
                            exit(0);
                    }
                }
            default:
                exit(0);
        }
    }
}
    #include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

char adminf[20]="Trip.txt";
char userf[20]="Reservation.txt";

struct tour{
 	char ad_id[20],ad_email[20],ad_studentno[20],ad_number[20];
 	char us_phone[20],us_id[20],us_people[20],us_date[20],us_status[20],us_sno[20];
};

class Tourist{
             public:
                void ad_pack(tour r);
	            tour ad_unpack(char a[]);
	            void ad_writedata();
	            void ad_display();
	            void ad_modify();
	            void us_pack(tour r);
	            tour us_unpack(char a[]);
	            void us_writedata();
	            void us_display();
	            void us_search();
	            void us_modify();
};

// ADMIN PANEL
void Tourist ::ad_pack(tour r){
     fstream fp;
     fp.open(adminf,ios::out|ios::app);
     if(!fp){
		cout<<"\nCannot open file";
		exit(0);
     }
     char buff[45];
     strcpy(buff,r.ad_id);
     strcat(buff,"|");
     strcat(buff,r.ad_email);
     strcat(buff,"|");
     //strcat(buff,r.ad_country);
     //strcat(buff,"|");
     strcat(buff,r.ad_studentno);
     strcat(buff,"|");
     strcat(buff,r.ad_number);
     strcat(buff,"|");
     for(int i=0;i<45-strlen(buff);i++)
            strcat(buff,"|");
     fp<<buff<<endl;
     fp.close();
}

tour Tourist::ad_unpack(char buff[]){
	tour r;
	int i=0,j=0;
	while(buff[j]!='|')
	      r.ad_id[i++]=buff[j++];
	r.ad_id[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_email[i++]=buff[j++];
	r.ad_email[i]='\0';
	i=0;
	j++;
	/**while(buff[j]!='|')
	      r.ad_country[i++]=buff[j++];
	r.ad_country[i]='\0';
	i=0;
	j++;**/
	while(buff[j]!='|')
	      r.ad_studentno[i++]=buff[j++];
	r.ad_studentno[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.ad_number[i++]=buff[j++];
	r.ad_number[i]='\0';
	return(r);
}

void Tourist::ad_writedata(){
    tour s;
    cout<<"Enter the Student's ID number\nD-";
    cin>>s.ad_id;
    cout<<"Enter the Student's email address\n";
    cin>>s.ad_email;
    //cout<<"Enter the Country of the Destination\n";
    //cin>>s.ad_country;
    cout<<"Enter the Student's student number\n";
    cin>>s.ad_studentno;
    cout<<"Enter the Student's number\n";
    cin>>s.ad_number;
    ad_pack(s);
}


void Tourist::ad_display(){
 	fstream fp;
   	char buff[45];
   	tour r;
    fp.open(adminf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"-------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\t\tID NUMBEr\tEMAIL\t\STUDENT NO.\t\tNUMBER\n";
    cout<<"-------------------------------------------------------------------------------------------------\n";
    int c=1;
    while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
       		r=ad_unpack(buff);
        cout<<c++<<"\t\t"<<r.ad_id<<"\t\t"<<r.ad_email<<"\t\t" <<r.ad_studentno<<"\t\t"<<r.ad_number<<endl;
    }
    fp.close();
    return;
}


void Tourist ::ad_modify(){
    fstream fp;
    char ad_id[15],buff[45];
    int i,j,ch;
    tour s[100];
    fp.open(adminf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"\nENTER THE STUDENT ID TO BE MODIFIED: ";
    cin>>ad_id;
    i=0;
   	while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
        s[i]=ad_unpack(buff);
        i++;
    }
   	for(j=0;j<i;j++){
       		if(strcmp(s[j].ad_id,ad_id)==0){
                    cout<<"STUDENT DETAILS\n";
                    cout<<"\n Student ID : "<<s[j].ad_id;
                    cout<<"\n Student Email : "<<s[j].ad_email;
                    //cout<<"\nDestination Country: "<<s[j].ad_country;
                    cout<<"\n Student number : "<<s[j].ad_studentno;
                    cout<<"\n Student number : "<<s[j].ad_number;
                    cout<<"\n What do you want to Update: ";
	  		cout<<"\n\n\t\tEnter 1 for changing Email address\n";
	  		cout<<"\t\tEnter 2 for changing Student number\n";
	  		cout<<"\t\tEnter 3 for changing Student number\n";
	  		cout<<"\t\t\t";
	  		cin>>ch;
	  		switch(ch){
                case 1:
                    cout<<"Email address: ";
                    cin>>s[j].ad_email;
                    //cout<<"Student number: ";
                    //cin>>s[j].ad_studentno;
                    break;
                case 2:
                    cout<<"Student number: ";
                    cin>>s[j].ad_studentno;
                    break;
                case 3:
                    cout<<"Student cellphone number : ";
                    cin>>s[j].ad_number;
                    break;
	  		}
                    break;
            }
    }
   	if(j==i){
        cout<<"\n STUDENT DETAILS NOT FOUND";
        return;
    }
    fp.close();
    fstream fd;
    fd.open(adminf,ios::out|ios::trunc);
    if(!fd){
        cout<<"\nFile Not Found";
        exit(0);
    }
   	for(j=0;j<i;j++)
         ad_pack(s[j]);
   	fd.close();
}


// USER PANEL


void Tourist ::us_pack(tour r){
    fstream fp;
    fp.open(userf,ios::out|ios::app);
    if(!fp){
        cout<<"\nFile Not Found";
		exit(0);
    }
    char buff[45];
    strcpy(buff,r.us_id);
    strcat(buff,"|");
    strcat(buff,r.us_phone);
    strcat(buff,"|");
    strcat(buff,r.us_people);
    strcat(buff,"|");
    strcat(buff,r.us_sno);
    strcat(buff,"|");
    strcat(buff,r.us_date);
    strcat(buff,"|");
    strcat(buff,r.us_status);
    strcat(buff,"|");
    for(int i=0;i<45-strlen(buff);i++)
     	strcat(buff,"|");
    fp<<buff<<endl;
    fp.close();
}


tour Tourist::us_unpack(char buff[]){
	tour r;
	int i=0,j=0;
	while(buff[j]!='|')
	      r.us_id[i++]=buff[j++];
	r.us_id[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_phone[i++]=buff[j++];
	r.us_phone[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_people[i++]=buff[j++];
	r.us_people[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_sno[i++]=buff[j++];
	r.us_sno[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_date[i++]=buff[j++];
	r.us_date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.us_status[i++]=buff[j++];
	r.us_status[i]='\0';
	return(r);
}
void Tourist::us_writedata(){
    tour r;
    cout<<"ENTER YOUR ID number : ";
    cin>>r.us_id;
    cout<<"ENTER YOUR CONTACT NO.: ";
    cin>>r.us_phone;
    cout<<"ENTER NO. OF STUDENTS : ";
    cin>>r.us_people;
    cout<<"ENTER YOUR STUDENT NUMBER: S-";
    cin>>r.us_sno;
    cout<<"ENTER DATE OF STUDYING (DD/MM/YY): ";
    cin>>r.us_date;
    cout<<"\nENTER 'Confirm' TO CONFIRM YOUR DETAILS: ";
    cin>>r.us_status;
    us_pack(r);
}

void Tourist::us_display(){
 	fstream fp;
   	char buff[45];
   	tour r;
    fp.open(userf,ios::in);
    if(!fp){
		cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Sr No.\tID number \t\tCONTACT NO\t\tTOTAL STUDENTS\t\tDATE\t\STUDENT NUMBER \t\tSTATUS\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    int c=1;
    while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
       		r=us_unpack(buff);
        cout<<c++<<"\t"<<r.us_id<<"\t\t"<<r.us_phone<<"\t\t"<<r.us_people<<"\t\t\t"<<r.us_date<<"\t\t"<<r.us_sno<<"\t\t"<<r.us_status<<endl;
    }
    fp.close();
    return;
}


void Tourist ::us_modify(){
    fstream fp;
    char us_id[15],buff[45];
    int i,j;
    tour s[100];
    fp.open(userf,ios::in);
    if(!fp){
		cout<<"\nFile not Found";
		exit(0);
    }
    cout<<"\nEnter Your ID number to cancel  your application: ";
    cin>>us_id;
    i=0;
   	while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
        s[i]=us_unpack(buff);
        i++;
    }
   	for(j=0;j<i;j++){
        if(strcmp(s[j].us_id,us_id)==0){
	  		cout<<"\nYour Student Details are:\n";
	  		cout<<"\n ID number : "<<s[j].us_id;
	  		cout<<"\nContact No.: "<<s[j].us_phone;
	  		cout<<"\nNo.of Students: "<<s[j].us_people;
	  		cout<<"\n Student number : "<<s[j].us_sno;
	  		cout<<"\nDate of Studying: "<<s[j].us_date;
	  		cout<<"\nStatus: "<<s[j].us_status;
	  		cout<<"\n\nENTER 'Cancel' TO CANCEL YOUR APPLICATION: \n";
	  		cin>>s[j].us_status;
	  		cout<<"\nYour Application has been Cancelled\n";
	  		cout<<"\n\nID number : "<<s[j].us_id;
	  		cout<<"\nContact No.: "<<s[j].us_phone;
	  		cout<<"\nNo.of People: "<<s[j].us_people;
	  		cout<<"\nStudent number: "<<s[j].us_sno;
	  		cout<<"\nDate of Studying: "<<s[j].us_date;
	  		cout<<"\nStatus: "<<s[j].us_status;
            break;
        }
    }
   	if(j==i){
        cout<<"\nRECORD NOT FOUND";
        return;
    }
    fp.close();
    fstream fd;
    fd.open(userf,ios::out|ios::trunc);
    if(!fd){
        cout<<"\nCannot open file";
        exit(0);
    }
   	for(j=0;j<i;j++)
        us_pack(s[j]);
   	fd.close();
}

void Tourist::us_search(){
 	fstream fp;
 	char us_id[15],buff[45];
 	int i,j;
 	tour s;
    fp.open(userf,ios::in);
    if(!fp){
	 	cout<<"\nCannot open file";
		exit(0);
    }
    cout<<"\nENTER THE STUDENT ID TO BE SEARCHED: ";
    cin>>us_id;
    i=0;
   	while(1){
        fp.getline(buff,45);
        if(fp.eof())break;
        s=us_unpack(buff);
        if(strcmp(s.us_id,us_id)==0){
	  	 	cout<<"\n STUDENT DETAILS \n";
	  		cout<<"\N STUDENT ID: "<<s.us_id;
	  		cout<<"\nCONTACT NO.: "<<s.us_phone;
	  		cout<<"\nNO. OF STUDENTS: "<<s.us_people;
	  		cout<<"\nDATE OF STUDYING: "<<s.us_date;
	  		cout<<"\n STUDENT STATUS: "<<s.us_status;
	  		return;
	 	}
    }
    cout<<"\nAPPLICATION NOT FOUND";
    return;
}

int main(){
    cout<<"                              \t\t WELCOME TO STUDENT MANAGEMENT SYSTEM\n\n\n";
    cout<<"                                   \t    STUDENT MANAGEMENT SOFTWARE\n\n\n";
    cout<<"                                     \t      PRESS ENTER TO CONTINUE....\n\n";
    if(cin.get()=='\n'){
        system("cls");
        int choice,ch1,ch2;
        Tourist obj;
        cout<<"\n Who are You?\n";
        cout<<"1. ADMIN\n";
        cout<<"2. STUDENT\n\n";
        cout<<"Enter any other key for exit\n\n\n";
        cout<<"Enter Your Option\n";
        cin>>choice;
        switch(choice){
            case 1:
                system("cls");
                cout<<"WELCOME ADMIN\n";
                cout<<"Enter your option\n";
                cout<<"1. Student's details \n";
                cout<<"2. View a single student's details \n";
                cout<<"3. View all student's details \n";
                cout<<"4. Update student details \n";
                cout<<"Enter any other key for exit\n\n";
                while(1){
                    cout<<"\nENTER UR CHOICE: ";
                    cin>>ch1;
                    switch(ch1){
                        case 1:
                            obj.ad_writedata();
                            break;
                        case 2:
                            obj.ad_display();
                            break;
                        case 3:
                            obj.us_display();
                            break;
                        case 4:
                            obj.ad_modify();
                            break;
                        default:
                            exit(0);
            }
        }
            case 2:
                system("cls");
                cout<<"WELCOME STUDENT\n";
                cout<<"Enter your option\n";
                cout<<"1. Register\n";
                cout<<"2. Search Students \n";
                cout<<"3. Cancel Application \n";
                cout<<"Enter any other key for exit\n\n\n";
                while(1){
                    cout<<"\nENTER UR CHOICE: ";
                    cin>>ch2;
                    switch(ch2){
                        case 1:
                            cout<<"-----------------------------------";
                            cout<<"\n Enter details \n";
                            cout<<"-----------------------------------\n";
                            obj.ad_display();
                            cout<<"\n";
                            obj.us_writedata();
                            break;
                        case 2:
                            obj.us_search();
                            break;
                        case 3:
                            obj.us_modify();
                            break;
                        default:
                            exit(0);
                    }
                }
            default:
                exit(0);
        }
    }
}
