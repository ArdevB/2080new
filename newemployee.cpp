#include<iostream>
#include<fstream>
using namespace std;
struct Employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    ofstream fout;
    Employee e[100];
    int n;
    int i=0;
    int j,k;

    fout.open("employee.txt");

    cout<<"Enter the number of employees: ";
    cin>>n;

    for (i=0; i<n; i++) {
        cout<<"Enter name: ";
        cin>>e[i].name;
        cout<<"Enter ID: ";
        cin>>e[i].id;
        cout<<"Enter salary: ";
        cin>>e[i].salary;

        fout<<e[i].name<<" "<<e[i].id<<" "<<e[i].salary<<endl;
    }

    fout.close();

    ifstream fin;
    fin.open("employee.txt");

    i = 0;
    while(fin>>e[i].name>>e[i].id>>e[i].salary) {
        i++;
    }

    fin.close();

    for(j=0; j<i-1;j++) {
        for(k=j+1;k<i;k++) {
            if(e[j].salary > e[k].salary) {
                Employee temp=e[j];
                e[j]=e[k];
                e[k]=temp;
            };
        }
    }

    cout<<"\nEmployees sorted by salary:\n";
    for (j=0; j<i; j++) {
        cout<<"Name: "<<e[j].name<<", ID: "<<e[j].id<<", Salary: "<<e[j].salary<<endl;
    }
}