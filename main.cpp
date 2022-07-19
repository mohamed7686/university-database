#include <iostream>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

class students {
   private:
     char name , department, year ;
     int code ;
   public:


   /******************************** function to add a student  ************************/

     void add(){
     char name[50]  , department[50] , year[50] ;
     int i,code ;

     ofstream student("student.txt",ios::app);

     do{
        cout<<"enter name"<< endl;
        cin.ignore();
        cin.getline(name ,50);
        cout<<"enter department one of these"<<endl<<"1-structure"<<endl<<"2-irrigation and hydraulics"<<endl<<"3-public works"<<endl<<
        "4-architecture"<<endl<<"5-urban design and planning"<<endl<<"6-power and electrical machines"<<endl<<"7-electronics and electrical communication"
        <<endl<<"8-computer and systems"<<endl<<"9-mechatronics"<<endl<<"10-mechanical power"<<endl<<"11-automotive"<<endl<<"12-design and production"<<endl;
        cin.getline(department,100);
        cout << " enter year "<<endl<<"freshmen"<<endl<<"sophomore"<<endl<<"junior"<<endl<<"senior i"<<endl<<"senior ii"<<endl;
        cin.getline(year,50);


        student<<codegenerator(code,name,department,year)<<"\t"<<name<<"|\t"<<department<<"|\t"<<year<<endl;
        cout<<codegenerator(code,name,department,year)<<"\t"<<name<<"|\t"<<department<<"|\t"<<year<<endl;

        cout<<"1 to continue 0 to exit"<<endl;
        cin>>i;}
     while(i==1);
     student.close();
    }


    /******************************** function to search a student by code ************************/

   void searching_by_code(){
        int i,code,g;
        char name[50],department[50],year[50];
        bool q=true;
        while(q){
           cout<<"enter student code"<<endl;
           cin>>i;
           ifstream student;
           student.open("student.txt");
           bool k=false;
           while(!student.eof()){
                student>>code;
                student.getline(name,50,'|');
                student.getline(department,50,'|');
                student.getline(year,50);
                if(i==code){
                    k=true;
                    cout<<code<<"\t"<<name<<"\t"<<department<<"\t"<<year<<endl;
                }


         }
         if(k)
            cout<<"done"<<endl;
         else{cout<<"not found"<<endl;}
         cout<< "enter 1 to search again\n";
         cin>>g;
        if (g==1){
            q=true;}
        else {q=false;}
       }

    }


/******************************** function to generate  a student code ************************/

int codegenerator(int code,char name[],char department[],char year[]){
int a,b,d;
static int c=0;
c++;
if(department[0]=='s')
    a=1;
else if(department[0]=='i')
    a=2;
else if(department[0]=='p')
    a=3;
else if (department[0]=='a')
    a=4;
else if (department[0]=='u')
    a=5;
else if (department[0]=='e')
    a=6;
else if (department[0]=='c')
    a=7;
else if (department[0]=='m')
    a=8;
else if (department[0]=='d')
    a=9;
if (year[0]=='f')
    b=1;
else if(year[0]=='s')
    b=2;
else if(year[0]=='j')
    b=3;
    d=a*100+b*10+c;
    return d;
}


/******************************** function to modify a student information ************************/
void modify(){
fstream student;
fstream update ;
student.open("student.txt",ios::in);
update.open("up.txt",ios::out);
char name[50],department[50],year[50];
int i,code,g;
bool q=true;
while(q){
//cin.ignore();
cout<<"enter the code"<<endl;
cin>>i;
bool b=false,k=true;
while(!student.eof()){
    student>>code;
    student.getline(name,50,'|');
    student.getline(department,50,'|');
    student.getline(year,50);
    if(i==code&&k){
            b=true;
            k=false;
        cout<<"enter new data "<<endl;
        cout<<"name   ";
        cin.ignore();
        cin.getline(name,25);
        cout <<"department   ";
         cin.getline(department,25);
         cout<<"year   ";
          cin.getline(year,25);
       update<<code<<"\t"<<name<<"|\t"<<department<<"|\t"<<year<<endl;
    }
    else{ update<<code<<name<<"|"<<department<<"|"<<year<<endl;
    }}
    if(b){
        cout<<"done"<<endl;}
    else{cout<<"wrong code"<<endl;}
    student.close();
    update.close();

    student.open("student.txt",ios::out);
update.open("up.txt",ios::in);
while(!update.eof()){
    update>>code;
    update.getline(name,50,'|');
    update.getline(department,50,'|');
    update.getline(year,50);
    student<<code<<name<<"|\t"<<department<<"|\t"<<year<<endl;
}
student.close();
update.close();
remove("up.txt");
cout<< "enter 1 to modify again\n";
cin>>g;
if (g==1)
    q=true;
else{q=false;}}
}



/******************************** function to delete a student  ************************/

void del(){
fstream student;
fstream update ;
student.open("student.txt",ios::in);
update.open("up.txt",ios::out);
char name[50],department[50],year[50];
int i,code,g;
bool q=true;
while(q){
//cin.ignore();
cout<<"enter the code"<<endl;
cin>>i;
bool b=false,k=true;
while(!student.eof()){
    student>>code;
    student.getline(name,50,'|');
    student.getline(department,50,'|');
    student.getline(year,50);
    if(i==code&&k){
            b=true;
           continue;
    }
    else{ update<<code<<name<<"|"<<department<<"|"<<year<<endl;
    }}
    if(b){
        cout<<"done"<<endl;}
    else{cout<<"wrong code"<<endl;}
    student.close();
    update.close();

    student.open("student.txt",ios::out);
update.open("up.txt",ios::in);
while(!update.eof()){
    update>>code;
    update.getline(name,50,'|');
    update.getline(department,50,'|');
    update.getline(year,50);
    student<<code<<name<<"|\t"<<department<<"|\t"<<year<<endl;
}
student.close();
update.close();
remove("up.txt");
cout<< "enter 1 to modify again\n";
cin>>g;
if (g==1)
    q=true;
else{q=false;}}
}




/******************************** function to search a student by name ************************/


void searching_by_name(){
int code,n=0,g;
char i[50];
char name[50],department[50],year[50],s[50],d[50];
char z[50],x[50],v[50],l[50];
bool q=true;
while(q){
cout<<"enter student name"<<endl;
cin.ignore();
cin.getline(i,50);
ifstream student;
student.open("student.txt");
bool k=false;
while(!student.eof()){
        for (int j=0;j<50;j++)
                if(i[j]==' ')
                n++;

  if(n==0){
    student>>code;
    student>>s;
    student.getline(name,50,'|');
        student.getline(department,50,'|');
        student.getline(year,50);
    if(strcmp(s,i)==0){
            k=true;
        cout<<code<<"\t"<<s<<name<<"\t"<<department<<"\t"<<year<<endl;
    }


  }
  else if(n==1){
    student>>code;
    student>>s;
    student>>d;
    student.getline(name,50,'|');
        student.getline(department,50,'|');
        student.getline(year,50);
        int e=0;
      for (int j=0;j<50;j++){

        if(i[j]!=' '){
            z[j]=i[j];
            e++;}
            else {j=50;}
      }
      for(int j=0;j<50;j++)
            x[j]=i[j+e+1];

    if(strcmp(s,z)==0&& strcmp(d,x)==0){
            k=true;
        cout<<code<<"\t"<<s<<" "<<d<<name<<"\t"<<department<<"\t"<<year<<endl;
    }


  }
  else{ student>>code;
  student>>s;
    student.getline(name,50,'|');
        student.getline(department,50,'|');
        student.getline(year,50);

        int r=0;
        for(int j=0;j<50;j++){
            if(i[j]!=' '){
                v[j]=i[j];
                r++;}
                else{j=50;}
        }
        for(int j=0;j<50;j++){
                l[j]=i[j+r];}
        cout<<name<<endl<<s<<endl<<v<<endl<<l<<endl;
    if(strcmp(s,v)==0&& strcmp(name,l)==0){
            k=true;
        cout<<code<<"\t"<<s<<name<<"\t"<<department<<"\t"<<year<<endl;
    }
}
  }

  if(k)
    cout<<"done"<<endl;
  else{cout<<"not found"<<endl;}
  cout<<"enter 1 to search again\n";
  cin>>g;
  if (g==1){
    q=true;
  }
  else{q=false;}
}}
};







/**********************************  staff class *******************/

class staffs {
private:
    char name , department, title ;
public:

void add(){
char name[50]  , department[50] , title[50] ;
int i;
ofstream staff("staff.txt",ios::app);
do{
  cout<<"enter name"<< endl;
  cin.ignore();
  cin.getline(name ,50);
cout<<"enter department one of these"<<endl<<"1-structure"<<endl<<"2-irrigation and hydraulics"<<endl<<"3-public works"<<endl<<
"4-architecture"<<endl<<"5-urban design and planning"<<endl<<"6-power and electrical machines"<<endl<<"7-electronics and electrical communication"
<<endl<<"8-computer and systems"<<endl<<"9-mechatronics"<<endl<<"10-mechanical power"<<endl<<"11-automotive"<<endl<<"12-design and production"<<endl;
cin.getline(department,50);

cout << " enter title "<<endl<<"demonstrator"<<endl<<"teaching assistant"<<endl<<"teacher"<<endl<<"assistant professor"<<endl<<"professor"<<endl;
cin.getline(title,50);

staff<<name<<"|\t"<<department<<"|\t"<<title<<endl;
cout<<name<<"|\t"<<department<<"|\t"<<title<<endl;



cout<<"1 to continue 0 to exit"<<endl;
cin>>i;}
while(i==1);
staff.close();
}





void modify(){
fstream staff;
fstream update ;
staff.open("staff.txt",ios::in);
update.open("up.txt",ios::out);
char name[50],department[50],title[50],i[50];
int g;
bool q=true;
while(q){
cin.ignore();
cout<<"enter the name"<<endl;
cin.getline(i,50);
bool b=false,k=true;
while(!staff.eof()){
    staff.getline(name,50,'|');
    staff.getline(department,50,'|');
    staff.getline(title,50);
    if(strcmp(name,i)==0&&k){
            b=true;
            k=false;
        cout<<"enter new data "<<endl;
        cin.ignore();
        cout <<"department   ";
         cin.getline(department,50);
         cout<<"title   ";
          cin.getline(title,50);
       update<<name<<"|\t"<<department<<"|\t"<<title<<endl;
    }
    else{ update<<name<<"|"<<department<<"|"<<title<<endl;
    }}
    if(b){
        cout<<"done"<<endl;}
    else{cout<<"wrong name"<<endl;}
    staff.close();
    update.close();

    staff.open("staff.txt",ios::out);
update.open("up.txt",ios::in);
while(!update.eof()){
    update.getline(name,50,'|');
    update.getline(department,50,'|');
    update.getline(title,50);
    staff<<name<<"|\t"<<department<<"|\t"<<title<<endl;
}
staff.close();
update.close();
remove("up.txt");
cout<< "enter 1 to modify again\n";
cin>>g;
if (g==1)
    q=true;
else{q=false;}}
}




void del(){
fstream staff;
fstream update ;
staff.open("staff.txt",ios::in);
update.open("up.txt",ios::out);
char name[50],department[50],title[50],i[50];
int g;
bool q=true;
while(q){
cin.ignore();
cout<<"enter the name"<<endl;
cin.getline(i,50);
bool b=false,k=true;
while(!staff.eof()){
    staff.getline(name,50,'|');
    staff.getline(department,50,'|');
    staff.getline(title,50);
    if(strcmp(name,i)==0&&k){
            b=true;
           continue;
    }
    else{ update<<name<<"|"<<department<<"|"<<title<<endl;
    }}
    if(b){
        cout<<"done"<<endl;}
    else{cout<<"wrong name"<<endl;}
    staff.close();
    update.close();

    staff.open("staff.txt",ios::out);
update.open("up.txt",ios::in);
while(!update.eof()){
    update.getline(name,50,'|');
    update.getline(department,50,'|');
    update.getline(title,50);
    staff<<name<<"|\t"<<department<<"|\t"<<title<<endl;
}
staff.close();
update.close();
remove("up.txt");
cout<< "enter 1 to modify again\n";
cin>>g;
if (g==1)
    q=true;
else{q=false;}}
}



void searching_by_name(){
int n=0,g;
char i[50];
char name[50],department[50],title[50],s[50],d[50];
char z[50],x[50],v[50],l[50];
bool q=true;
while(q){
cout<<"enter staff member name"<<endl;
cin.ignore();
cin.getline(i,50);
ifstream staff;
staff.open("staff.txt");
bool k=false;
while(!staff.eof()){
        for (int j=0;j<50;j++)
                if(i[j]==' ')
                n++;

  if(n==0){
    staff>>s;
    staff.getline(name,50,'|');
        staff.getline(department,50,'|');
        staff.getline(title,50);
    if(strcmp(s,i)==0){
            k=true;
        cout<<s<<name<<"\t"<<department<<"\t"<<title<<endl;
    }


  }
  else if(n==1){
    staff>>s;
    staff>>d;
    staff.getline(name,50,'|');
        staff.getline(department,50,'|');
        staff.getline(title,50);
        int e=0;
      for (int j=0;j<50;j++){

        if(i[j]!=' '){
            z[j]=i[j];
            e++;}
            else {j=50;}
      }
      for(int j=0;j<50;j++)
            x[j]=i[j+e+1];

    if(strcmp(s,z)==0&& strcmp(d,x)==0){
            k=true;
        cout<<s<<" "<<d<<name<<"\t"<<department<<"\t"<<title<<endl;
    }


  }
  else{
  staff>>s;
    staff.getline(name,50,'|');
        staff.getline(department,50,'|');
        staff.getline(title,50);

        int r=0;
        for(int j=0;j<50;j++){
            if(i[j]!=' '){
                v[j]=i[j];
                r++;}
                else{j=50;}
        }
        for(int j=0;j<50;j++){
                l[j]=i[j+r];}
    if(strcmp(s,v)==0&& strcmp(name,l)==0){
            k=true;
        cout<<s<<name<<"\t"<<department<<"\t"<<title<<endl;
    }
}
  }

  if(k)
    cout<<"done"<<endl;
  else{cout<<"not found"<<endl;}
  cout<<"enter 1 to search again\n";
  cin>>g;
  if (g==1){
    q=true;
  }
  else{q=false;}
}}
};




int main()
{
    int choice;
    cout<<" 1 to deal with a student any other key to deal with a stuff member\n";
    cin>> choice;
    if (choice==1){
   students s;
   int c,g,n;
   bool q=true;
   bool w=true;
   while(w){
   while(q){
        cout<<"enter \n 1 for add student \n 2 to search a student \n 3 to modify a student data \n 4 to delete a student data\n";
   cin >>c;
   switch(c){
   case 1 :
       s.add();
       q=false;
       break;
   case 2:
       cout<<"1 to search by name 0 to search by code\n";
       cin>>n;
       if(n==1)
        s.searching_by_name();
       else
       s.searching_by_code();
       q=false;
       break;
   case 3:
       s.modify();
       q=false;
       break;
   case 4 :
       s.del();
       q=false;
       break;
   default:
       q=true;
       cout<<"wrong entry\n";
       break;
   }cout<<"enter 1 to choose again\n 0  to exit\n";}

   cin>> g;
   if (g==1){
    w=true;
    q=true;}
   else{w=false;}
   }}
   else{
   staffs st;
   int c,g,n;
   bool q=true;
   bool w=true;
   while(w){
   while(q){
        cout<<"enter \n 1 for add staff member \n 2 to search a staff member \n 3 to modify a staff member data \n 4 to delete a staff member data\n";
   cin >>c;
   switch(c){
   case 1 :
       st.add();
       q=false;
       break;
   case 2:
        st.searching_by_name();
       q=false;
       break;
   case 3:
       st.modify();
       q=false;
       break;
   case 4 :
       st.del();
       q=false;
       break;
   default:
       q=true;
       cout<<"wrong entry\n";
       break;
   }cout<<"enter 1 to choose again\n 0  to exit\n";}

   cin>> g;
   if (g==1){
    w=true;
    q=true;}
   else{w=false;}
   }}

    return 0;
}







