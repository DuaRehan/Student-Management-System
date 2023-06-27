/* Write program to perform Student Management Tasks similar to CUOnline
It should have related concepts implementation such as Constructors, Destructors, Inheritance  etc */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include<iomanip>
#include<string>

using namespace std;

class Admin
{
    public:
        string username;
        string password;
    
    public:
        Admin()
        {
            username = "admin";
            password = "admin";
        }
        void create_student();
        void update_password();
        void delete_data();
        void view_data();
};

class Student
{
    public:
        string name;
        string reg_no;
        string password;
        int semester;
        float gpa;
        string subjects[5];

    public:
        Student()
        {
            name = "";
            reg_no = "";
            password = "";
            semester = 0;
            gpa = 0.0;
            for(int i=0; i<5; i++)
            {
                subjects[i] = "";
            }
        }
};

void Admin::create_student()
{
    Student s;
    cout<<"\n\n\t\t\t\t\tCREATE NEW STUDENT\n\n";
    cout<<"\n\t\tEnter the name: ";
    cin.ignore();
    getline(cin, s.name);
    cout<<"\t\tEnter the registration number: ";
    cin>>s.reg_no;
    cout<<"\t\tEnter the password: ";
    cin>>s.password;
    cout<<"\t\tEnter the semester: ";
    cin>>s.semester;
    cout<<"\t\tEnter the gpa: ";
    cin>>s.gpa;
    cout<<"\t\tEnter the subjects: ";
    for(int i=0; i<5; i++)
    {
        cin>>s.subjects[i];
    }

    ofstream f1("student.txt",ios::app);
    f1<<s.name<<"\t\t"<<s.reg_no<<setw(15)<<s.password<<setw(15)<<s.semester<<setw(15)<<s.gpa<<setw(20)<<s.subjects[0]<<setw(10)<<s.subjects[1]<<setw(10)<<s.subjects[2]<<setw(10)<<s.subjects[3]<<setw(10)<<s.subjects[4];

    f1<<endl;
    f1.close();
}

void Admin::update_password()
{
    cout<<"\n\n\t\t\t\t\tUPDATE PASSWORD\n\n";
    string reg_no;
    cout<<"\n\t\tEnter the registration number: ";
    cin>>reg_no;
    ifstream f1("student.txt");
    if (f1.is_open()){
        string line;
        while ( getline (f1,line) ){
            if(line.find(reg_no) != string::npos)
            {
                cout<<"\n\t\tEnter the new password: ";
                cin>>password;
                ofstream f2("temp.txt",ios::app);
                f2<<line<<endl;
                f2.close();
                remove("student.txt");
                rename("temp.txt","student.txt");
                cout<<"\n\t\tPassword updated successfully!";
            }
            else{
                cout<<"\n\t\tRegistration number not found!";
            }
        }
    }
    else{
        cout<<"\n\t\tFile not found!";
    }
}

void Admin::view_data(){
    string line;
            ifstream f1 ("student.txt");
            if (f1.is_open()){    
                cout<<"\n\n\t\t\t\t\t\t\t\tALL Students DATA\n\n";
                cout<<"\t\t==================================================================================================================================================\n";
                cout<<"\t\t     Name                 Reg #               PASSWORD        SEMESTER        GPA                      SUBJECTS  \n";
                cout<<"\t\t==================================================================================================================================================\n";
                while ( getline (f1,line) ){
                    cout <<"\t\t"<< line << '\n';	}
                f1.close();}
            else{
                cout << "Error!!!!! Unable to open file"; } 

}

void Admin::delete_data()
{
    int choice2;
    cout<<"\n\n\t\t\t\t\tDELETE DATA\n\n";
    cout<<"\t\t1. Delete all data\n";
    cout<<"\t\t2. Delete data at specific line number\n";
    cout<<"\t\tEnter your choice: ";
    cin>>choice2;

    cout<<endl;

    if(choice2 == 1)
    {
        ofstream f1("student.txt",ios::trunc);
        cout<<"\n\t\tData deleted successfully!";
        f1.close();
    }
    else if(choice2 == 2)
    {
        int line_no;
        cout<<"\t\tEnter the line number: ";
        cin>>line_no;
        ifstream f1("student.txt");
        ofstream f2("temp.txt");
        int i=0;
        while(f1)
        {
            string line;
            getline(f1,line);
            if(i==line_no-1)
            {
                continue;
            }
            f2<<line<<endl;
            i++;
        }
        cout<<"\n\t\tData deleted successfully!";
        f1.close();
        f2.close();
        remove("student.txt");
        rename("temp.txt","student.txt");
    }
    else
    {
        cout<<"\t\tInvalid choice\n";
    }
}

void admin_menu()
{
    Admin a;
    int choice;
    cout<<"\n\n\t\t\t\t\tADMIN MENU\n\n";
    cout<<"\t\t1. Create student\n";
    cout<<"\t\t2. Update password\n";
    cout<<"\t\t3. View data\n";
    cout<<"\t\t4. Delete data\n";
    cout<<"\t\t5. Exit\n";
    cout<<"\t\tEnter your choice: ";
    cin>>choice;
    cout<<endl;

    system("cls");
    if(choice == 1)
    {
        a.create_student();
        system("cls");
        admin_menu();
    }
    else if(choice == 2)
    {
        a.update_password();
        system("cls");
        admin_menu();
    }
    else if(choice == 3)
    {
        a.view_data();
        admin_menu();
    }
    else if(choice == 4)
    {
        a.delete_data();
        admin_menu();
    }
    else if(choice == 5)
    {
        cout<<"\t\tLogout Successful! Thank you for using our program :)";
        exit(0);
    }
    else
    {
        cout<<"\t\tInvalid choice\n";
    }
}

int main(){
    Admin a;
    Student s;

    cout<<"\n\n\t\t\t\t\tWelcome to Student Console\n\n";
    int choice, choice1;
    cout<<"\t\t1. Admin Login\n";
    cout<<"\t\t2. Student Login\n";
    cout<<"\n\t\tEnter your choice: ";
    cin>>choice;
    
    system("cls");

    if(choice == 1){
        cout<<"\n\n\t\t\t\t\tADMIN MENU\n\n";
        cout<<"\t\tEnter username: ";
        cin>>a.username;
        cout<<"\t\tEnter password: ";
        cin>>a.password;

        if(a.username == "admin" && a.password == "admin")
        {
            system("cls");
            admin_menu();
         }
        else{
            cout<<"\t\tInvalid username or password\n";
        }
    }

    else if(choice == 2){
        cout<<"\n\n\t\t\t\t\tSTUDENT LOGIN\n\n";
        cout<<"\t\tEnter registration number: ";
        cin>>s.reg_no;
        cout<<"\t\tEnter password: ";
        cin>>s.password;

        ifstream f1("student.txt");
        if (f1.is_open()){
            string line;
            while ( getline (f1,line) ){
                if(line.find(s.reg_no) != string::npos && line.find(s.password) != string::npos)
                {
                    system("cls");
                    Student s;
                    int choice;
                    cout<<"\n\n\t\t\t\t\tSTUDENT MENU\n\n";
                    cout<<"\t\t1. View dashboard\n";
                    cout<<"\t\t2. Logout\n";
                    cout<<"\t\tEnter your choice: ";
                    cin>>choice;
                    cout<<endl;

                    system("cls");
                    if(choice == 1)
                    {
                        cout<<"\n\n\t\t\t\t\tSTUDENT DASHBOARD\n\n";
                        ifstream f1("student.txt");
                        if (f1.is_open()){
                            string line;
                            while ( getline (f1,line) ){
                                if(line.find(s.reg_no) != string::npos)
                                {
                                    cout<<"\t\t==================================================================================================================================================\n";
                                    cout<<"\t\t     Name                 Reg #               PASSWORD        SEMESTER        GPA                      SUBJECTS  \n";
                                    cout<<"\t\t==================================================================================================================================================\n";
                                    cout<<"\t\t"<<line<<'\n';
                                }
                            }
                            f1.close();

                        }
                        else{
                            cout << "Error!!!!! Unable to open file"; }
                       
                    }

                    else if(choice == 2)
                    {
                        cout<<"\t\tLogout Successful! Thank you for using our program :)";
                        exit(0);
                    }
                    else
                    {
                        cout<<"\t\tInvalid choice\n";
                    }
                }
                        else{
                        cout<<"\n\t\tInvalid registration number or password!\n";
                                }
            }
                        }
                        else{
                            cout<<"\n\t\tFile not found!\n";
                        }
    }

    else{
        cout<<"Invalid choice";
    }

    return 0;
}
