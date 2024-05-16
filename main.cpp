#include<bits/stdc++.h>
using namespace std;

struct employee{
    int id;
    string name;
    int salary;
    string start_date;
};

class linked_list{
private:
    class intnode {
    public:
        employee item;
        intnode* next;
        intnode(employee e, intnode* n) {
            item = e;
            next = n;
        }
    };
    int size;
    intnode* sentinel;
    intnode* last;
public:
    linked_list(){
        sentinel = new intnode(employee(), nullptr);
        last = NULL;
        size=0;
    }
    linked_list(employee e1){
        intnode* t = new intnode(e1, nullptr);
        sentinel = new intnode(employee(), t);
        last = t;
        size++;
    }
    void add_employee(employee e1){
        if (last == nullptr) {
            last = new intnode(e1, nullptr);
            sentinel->next = last;
        } else {
            intnode* newNode = new intnode(e1, nullptr);
            last->next = newNode;
            last = newNode;
        }
        size++;
    }
    void report_of_specific(int position){
        employee e;
        if(position-1 == 0) e=sentinel->next->item;
        else if(position-1 < size){
            intnode* t = sentinel->next;
            for(int i=1; i <= position-1; i++){
                t=t->next;
            }
            e= t->item;
        }else return;
        cout<<"Employee position num "<<position<<" is : "<<endl;
        cout<<"ID is : "<<e.id<<endl;
        cout<<"Name is : "<<e.name<<endl;
        cout<<"Date of joining is : "<<e.start_date<<endl;
        cout<<"Salary is : "<<e.salary<<endl;
    }
    void report_of_employees(){
        intnode* t=sentinel->next;
        for(int i=1;i<=size;i++){
            if(t== nullptr)return;
            employee e=t->item;
            cout<<"---------------------------------------------\n";
            cout<<"Employee position num "<<i<<" is : "<<endl;
            cout<<"ID is : "<<e.id<<endl;
            cout<<"Name is : "<<e.name<<endl;
            cout<<"Date of joining is : "<<e.start_date<<endl;
            cout<<"Salary is : "<<e.salary<<endl;
            t=t->next;
        }
        cout<<"---------------------------------------------\n";
    }
    void search_with_name(string n){
        intnode * t=sentinel->next;
        for(int i=1;i<=size;i++){
            if(t==nullptr) { cout << "This employee not exist.\n";return; }
            employee e=t->item;
            if(e.name == n){
                cout<<"Employee position num "<<i<<" is : "<<endl;
                cout<<"ID is : "<<e.id<<endl;
                cout<<"Name is : "<<e.name<<endl;
                cout<<"Date of joining is : "<<e.start_date<<endl;
                cout<<"Salary is : "<<e.salary<<endl;
                return;
            }
            t=t->next;
        }
    }
    void search_with_id(int idd){
        intnode * t=sentinel->next;
        for(int i=1;i<=size;i++){
            if(t==nullptr) { cout << "This employee not exist.\n";return; }
            employee e=t->item;
            if(e.id==idd){
                cout<<"Employee position num "<<i<<" is : "<<endl;
                cout<<"ID is : "<<e.id<<endl;
                cout<<"Name is : "<<e.name<<endl;
                cout<<"Date of joining is : "<<e.start_date<<endl;
                cout<<"Salary is : "<<e.salary<<endl;
                return;
            }
            t=t->next;
        }
    }
    void get_employees_with_rang_salary(int l,int r){
        int left =min(l,r);
        int right =max(l,r);
        bool exist= false;
        intnode * t=sentinel->next;
        for(int i=1;i<=size;i++){
            if(t==nullptr) { cout << "This salary rang not exist.\n";return; }
            employee e=t->item;
            if( e.salary >= left && e.salary <= right){
                exist=true;
                cout<<"Employee position num "<<i<<" is : "<<endl;
                cout<<"ID is : "<<e.id<<endl;
                cout<<"Name is : "<<e.name<<endl;
                cout<<"Date of joining is : "<<e.start_date<<endl;
                cout<<"Salary is : "<<e.salary<<endl;
                cout<<"---------------------------------------------\n";
            }
            t=t->next;
        }
        if(!exist){
            cout<<"We don't have employees with this rang of salary.\n";
        }
    }
    void update_with_id(int idd){
        intnode * t=sentinel->next;
        for(int i=1;i<=size;i++){
            if(t==nullptr) { cout << "This employee not exist.\n";return; }
            if(t->item.id==idd){
                cout<<"enter employee name : \n";
                cin>>t->item.name;
                cout<<"enter employee salary : \n";
                cin>>t->item.salary;
                cout<<"enter employee joining date : \n";
                cin>>t->item.start_date;
                cout<<"successfully update. \n";
                search_with_id(idd);
                return;
            }
            t=t->next;
        }
    }
    void delete_with_id(int idd){
        intnode* current = sentinel->next;
        intnode* previous = nullptr;

        for(int i=1;i<=size;i++){
            if(current==nullptr) { cout << "This employee not exist.\n";return; }
            if(current->item.id==idd)break;
            previous = current;
            current = current->next;
        }

        if (previous != nullptr) {
            previous->next = current->next;
        } else {
            sentinel->next = current->next;
        }


        if (current == last) {
            last = previous;
        }


        delete current;
        size--;
        cout<<"successful deleted.\n";
    }
    void bubbleSort() {
        if (size <= 1) return;
        bool swapped;
        intnode* ptr1;
        intnode* lptr = nullptr;
        do {
            swapped = false;
            ptr1 = sentinel->next;
            while (ptr1->next != lptr) {
                if (ptr1->item.id > ptr1->next->item.id) {
                    // Swap data
                    employee temp = ptr1->item;
                    ptr1->item = ptr1->next->item;
                    ptr1->next->item = temp;
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        }while (swapped);
    }
};

int menu(){
    int mode;
    cout<<"choose mode : \n1- administrator mode.\n2- guest mode.\n0- Exit.\n";
    cin>>mode;
    if(mode<0 || mode>2){
        cout<<"not available input, try again.\n";
        menu();
    }else{
        return mode;
    }
}
int mode_1(){
    int fun;
    cout<<"choose functionality you want : \n"
          "1-Add a new employee's details.\n"
          "2-Update the details of an existing employee.\n"
          "3-Delete (fired from the company) the details of a specific employee from the database.\n"
          "4-search for the details of an employee based on name\n"
          "5-search for the details of an employee based on name ID \n"
          "6-Display the list of all employees either in the working or nonworking category.\n";
    cin>>fun;
    if(fun<1||fun>6){
        cout<<"not available input, try again.\n";
        mode_1();
    }else return fun;
}
int mode_2(){
    int fun;
    cout<<" Choose functionality you want : \n"
          "1- search for the details of an employee based on name\n"
          "2- search for the details of an employee based on name ID \n"
          "3- Display the list of all employees\n"
          "4- generating the report in a sorted manner based on ID.\n"
          "5- get employees with rang salary. \n";
    cin>>fun;
    if(fun<1||fun>5){
        mode_2();
    }else return fun;
}
int main() {

    linked_list l;

    /*if you need to test project with initial values remove the comment :)

    employee test1,test2,test3;
    test1.id=50;test1.name="ta";test1.salary=10;test1.start_date="1";
    test2.id=10;test2.name="re";test2.salary=20;test2.start_date="2";
    test3.id=40;test3.name="k";test3.salary=30;test3.start_date="3" ;
    l.add_employee(test1);
    l.add_employee(test2);
    l.add_employee(test3);
     */

    int mode=menu();
    while(mode!=0){
        if(mode==1){
            int fun=mode_1();
            if(fun==1){
                employee e;
                cout<<"enter employee name : \n";
                cin>>e.name;
                cout<<"enter employee id : \n";
                cin>>e.id;
                cout<<"enter employee salary : \n";
                cin>>e.salary;
                cout<<"enter employee joining date : \n";
                cin>>e.start_date;
                l.add_employee(e);
            }
            else if(fun==2){
                cout<<"enter employee id : ";
                int idd;cin>>idd;
                l.update_with_id(idd);
            }
            else if(fun==3){
                cout<<"enter employee id : ";
                int idd;cin>>idd;
                l.delete_with_id(idd);
            }
            else if(fun==4){
                cout<<"enter employee name for report : ";
                string n;cin>>n;
                l.search_with_name(n);
            }
            else if(fun==5){
                cout<<"enter employee ID for report : ";
                int idd;cin>>idd;
                l.search_with_id(idd);
            }
            else if(fun==6){
                l.report_of_employees();
            }
        }
        else if(mode==2){
            int fun=mode_2();
            if(fun==1){
                cout<<"enter employee name for report : ";
                string n;cin>>n;
                l.search_with_name(n);
            }
            else if(fun==2){
                cout<<"enter employee ID for report : ";
                int idd;cin>>idd;
                l.search_with_id(idd);
            }
            else if(fun==3){
                l.report_of_employees();
            }
            else if(fun==4){
                cout<<"here is employees after sort based on IDs : \n";
                l.bubbleSort();
                l.report_of_employees();
            }
            else if(fun==5){
                cout<<"Enter the range  to search ex:{S1,S2} : \n";
                int s1,s2;
                cin>>s1>>s2;
                l.get_employees_with_rang_salary(s1,s2);
            }
        }
        mode=menu();
    }
}
