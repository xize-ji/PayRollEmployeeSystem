#include<iostream>
#include<iomanip>
using namespace std;
class EmployeePayrollSystem{
    private:
        int id;
        string name, pos;
        int rate;
        float totalSalary;
        int hoursWorked;
    public:
        void createData(){
            cout<<"Enter Employee ID: ";cin>>id;
            cout<<"Enter Employee Name: ";cin>>name;
            cout<<"Employee Position: ";cin>>pos;
            cout<<"Employee work in hours: ";cin>>hoursWorked;
            cout<<"Salary work in hours: ";cin>>rate;

            totalSalary = hoursWorked * rate;
            cout<<endl;
        }

        void outPutData(){
            cout<<left<<setw(21)<<id
                        <<setw(24)<<name
                        <<setw(18)<<pos
                        <<setw(19)<<hoursWorked
                        <<setw(14)<<rate
                        <<setw(22)<<totalSalary<<endl;
        }
        int getID(){
            return id;
        }
        float getTotalSalary(){
            return totalSalary;
        }



};
void Header(){
    cout<<left<<setw(21)<<"Employee ID"
                <<setw(24)<<"Name Employee"
                <<setw(18)<<"Position"
                <<setw(19)<<"Work Time"
                <<setw(14)<<"Rate"
                <<setw(22)<<"Total Salary"<<endl;

}
void Manu(){
    cout<<"\033[35m========================================="<<endl;
            cout<<"|                  MENU                  |"<<endl;
            cout<<"========================================="<<endl;
            cout<<"| 1. Create List Employee               |"<<endl;
            cout<<"| 2. Show List Employee                 |"<<endl;
            cout<<"| 3. Search ID Employee                 |"<<endl;
            cout<<"| 4. Delete Employee                    |"<<endl;
            cout<<"| 5. Update Employee                    |"<<endl;
            cout<<"| 6. Delete All Data                    |"<<endl;
            cout<<"| 7. Add Employee                       |"<<endl;
            cout<<"| 8. Sort Salary                        |"<<endl;
            cout<<"| 9. Exit                               |"<<endl;
            cout<<"=========================================\033[0m"<<endl<<endl;
}  


int main(){
    EmployeePayrollSystem persons[150];
    int op, n;
    do{
        Manu();
        cout<<"Choose Option ";cin>>op;
        cout<<endl;
        switch (op){
            case 1:{
                int empE;
                cout << "How many Employee: "; cin >> n;
                
                for(int i=0; i<n; i++){
                    bool idExists;
                    do {
                        idExists = false;
                        persons[i].createData();  
                        empE = persons[i].getID();
                        
                        for(int j=0; j<i; j++){
                            if(persons[j].getID() == empE){
                                cout << "\033[31mThis ID already exists! Please enter a different ID.\033[0m" << endl;
                                idExists = true;
                                break;
                            }
                        }
                    } while(idExists);
                    
                    cout << endl;
                }
            }break;

            
            case 2:{
                Header();
                for(int i=0; i<n; i++){
                    persons[i].outPutData();
                }

            }break;
            case 3:{
                bool checking = false;
                int search;
                cout<<"Enter ID to search for employee: ";cin>>search;
                for(int i=0; i<n; i++){
                    if(persons[i].getID() == search){
                        Header();
                        persons[i].outPutData();
                        cout<<"Search Found"<<endl;
                        checking = true;
                        
                    }
                }
               if (!checking){
                    cout<<"Sorry :( We can not finding this ID "<<endl;
                }
                
            }break;

            case 4:{
                int Delete;
                cout<<"Enter Employee ID to deleted: "; cin>> Delete;
                for(int i=0; i<n; i++){
                    if(Delete==persons[i].getID()){
                        for(int j=i; j<n; j++){
                            persons[j]=persons[j+1];
                        
                        }n--;

                    }

                }   
            }break;

            case 5:{
                int empUpdate;
                bool checkingUpDate = false;
                cout<<"Enter ID to updata employee imformation: ";cin>>empUpdate;
                for(int i=0; i<n; i++){
                    
                    if(empUpdate == persons[i].getID()){
                       
                        persons[i].createData();
                        checkingUpDate = true;
                    }
                }      
                if (!checkingUpDate){
                    cout<<"This ID not exist :("<<endl;
                
                }


            }break;
            case 6:{
                string ansker;
                cout<<"Are you sure to deleted all Data? y/n "; cin>>ansker;
                if(ansker =="yes" || ansker=="y"){
                    n=0;
                    cout<<"All data has been deleted"<<endl;
                }
                else if(ansker=="no" || ansker=="n"){
                    n=0;
                    cout<<"All data has been deleted"<<endl;
                } 
                
            
            }break;  
            case 7:{
                int addEmp;
                int existID;
                cout<<"How many employee do you want to add more: ";cin>>addEmp;
                
                for (int i=n; i< addEmp + n; i++){
                    bool checkingID;
                    do{
                        persons[i].createData();
                        checkingID = true;
                        existID = persons[i].getID();
                        for(int j; j<i ;j++){
                            if(existID == persons[j].getID()){
                                cout << "\033[31mThis ID already exists! Please enter a different ID.\033[0m" << endl;
                                cout<<endl;
                                existID = false;
                                break;
                            }
                        }
                    }while(!checkingID);
                    

                }

                cout<<endl;
                n+=addEmp;
                        
            }break;
            case 8:{
                EmployeePayrollSystem shortsalary;
                for(int i=0; i<n ; i++){
                    for(int j = i+1; j<n ;j++){
                        if(persons[i].getTotalSalary() < persons[j].getTotalSalary()){
                            shortsalary = persons[i];
                            persons[i]= persons[j];
                            persons[j]= shortsalary;
                        }
                    }
                };
            }break;
            case 9:{
                
                op = 0;
            }break;

		}


        
    }while(op!=0);
}