#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>
#include <cstdint>

using namespace std;

typedef struct {
    uint8_t hour;
    uint8_t minute;
} Times;

typedef struct {
    uint8_t date;
    uint8_t month;
    uint8_t year;
} Dates;

typedef enum {
    IN,
    OUT
} Status;

typedef struct {
    Times time_Book;
    Dates date_Book;
    bool statusClient;
} BookingHistory;

class Room {
private:
    int roomNumber;
    bool isbooked;

public:
    Room(uint8_t number) {
        roomNumber = number;
        isbooked = false;
    }

    int getRoomNumber() {
        return roomNumber;
    }

    bool isAvailable() {
        return !isbooked;
    }

    void bookRoom() {
        isbooked = true;
    }

    void checkOut() {
        isbooked = false;
    }
};

class Customer {
private:
    int roomId;
    string name;
    string phoneNumber;
    string address;
    vector<BookingHistory> bookingHistory;

public:
    Customer(string customerName, string customerPhone, string customerAddress, uint8_t customerIdroom);
    void setIdroom(uint8_t customerIdroom);
    void setPhoneNumber(string customerPhone);
    void setName(string customerName);
    void setAddress(string customerAddress);
    int getIdroom();
    string getPhoneNumber();
    string getName();
    string getAddress();
};

Customer::Customer(string customerName, string customerPhone, string customerAddress, uint8_t customerIdroom) {
    this->name = customerName;
    this->phoneNumber = customerPhone;
    this->address = customerAddress;
    this->roomId = customerIdroom;
}

string Customer::getName() {
    return name;
}

string Customer::getAddress() {
    return address;
}

string Customer::getPhoneNumber() {
    return phoneNumber;
}

int Customer::getIdroom() {
    return roomId;
}

void Customer::setName(string customerName) {
    this->name = customerName;
}

void Customer::setAddress(string customerAdress) {
    this->address = customerAdress;
}

void Customer::setPhoneNumber(string customerPhone) {
    this->phoneNumber = customerPhone;
}

void Customer::setIdroom(uint8_t customerIdroom) {
    this->roomId = customerIdroom;
}

class CustomerManager {
private:
    vector<Customer> databaseCustomer;

public:
    vector<Customer>& getdatabaseCustomer() {
        return databaseCustomer;
    }
};


typedef struct {
    Times timein;
    Times timeout;
    Dates date;
    Status status;
} Schedule;

struct EmployeeInfo {
    int ID;
    string name;
    string phoneNumber;
    string position;
    Schedule schedule;
};

class Employee {
private:
    EmployeeInfo employeeInfo;

public:
    Employee(int ID , string nameEmployee, string phoneNumberEmployee, string positionEmployee, Schedule scheduleEmployee);
    
    // Accessor and mutator methods for EmployeeInfo
    int getIdEmployee();
    string getNameEmployee();
    string getPhoneEmployee();
    string getPositionEmployee();
    Schedule getScheduleEmployee();
    void setNameEmployee(string nameEmployee);
    void setPhoneEmployee(string phoneNumberEmployee);
    void setPositionEmployee(string positionEmployee);
    void setScheduleEmployee(Schedule scheduleEmployee);
};

Employee::Employee(int ID , string nameEmployee, string phoneNumberEmployee, string positionEmployee, Schedule scheduleEmployee) {
    this->employeeInfo.ID = ID ;
    this->employeeInfo.name = nameEmployee;
    this->employeeInfo.phoneNumber = phoneNumberEmployee;
    this->employeeInfo.position = positionEmployee;
    this->employeeInfo.schedule = scheduleEmployee;
}

int Employee::getIdEmployee(){
    return employeeInfo.ID;
}

string Employee::getNameEmployee() {
    return employeeInfo.name;
}

string Employee::getPhoneEmployee() {
    return employeeInfo.phoneNumber;
}

string Employee::getPositionEmployee() {
    return employeeInfo.position;
}

Schedule Employee::getScheduleEmployee() {
    return employeeInfo.schedule;
}

void Employee::setNameEmployee(string nameEmployee) {
    employeeInfo.name = nameEmployee;
}

void Employee::setPhoneEmployee(string phoneNumberEmployee) {
    employeeInfo.phoneNumber = phoneNumberEmployee;
}

void Employee::setPositionEmployee(string positionEmployee) {
    employeeInfo.position = positionEmployee;
}

void Employee::setScheduleEmployee(Schedule scheduleEmployee) {
    employeeInfo.schedule = scheduleEmployee;
}

class EmployeeManagement {
private:
    vector<Employee> databaseEmployee;

public:
    vector<Employee>& getdatabaseEmployee() {
        return databaseEmployee;
    }
};

void SettingRoom(vector<Room>& databaseRoom) {
    cout << "Manager" << endl;
    int n;
    cout << "1.Nhap so luong phong " << endl;
    cout << "2.Quay lai " << endl;
    cin >> n;
    switch (n) {
    case 1:
        int room;
        cout << "Nhap so luong : " << endl;
        cin >> room;
        for (int i = 0; i < room; i++) {
            Room x(i + 1);
            databaseRoom.push_back(x);
        }
        break;
    case 2:
        return;
    default:
        cout << "Phim khong hop le" << endl;
        break;
    }
}

void BookingRoomProcess(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer) {
    string name;
    string phoneNumber;
    string address;
    uint8_t roomId;
    cout << "\tProceed\t" << endl;
    cout << "\t Danh sach phong \t" << endl;
    if (databaseRoom.empty()) {
        cout << "Chua nhap so phong" << endl;
        return;
    }
    for (int i = 0; i < databaseRoom.size(); i++) {
        cout << "Phong " << databaseRoom[i].getRoomNumber();
        cout << "\t\tTrang thai " << (databaseRoom[i].isAvailable() ? "trong" : "da dat") << endl;
    }
continuee:
    int choice;
    cout << "Nhap so phong :" << endl;
    cin >> choice;
    if (choice < 1 || choice > databaseRoom.size()) {
        cout << "Invalid choice." << endl;
        return;
    }
    cout << "Enter name :" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter phone number :" << endl;
    cin >> phoneNumber;
    cout << "Enter address :" << endl;
    cin.ignore();
    getline(cin, address);
    Customer customer(name, phoneNumber, address, choice);
    databaseCustomer.push_back(customer);

    databaseRoom[choice - 1].bookRoom();

    int n;
    do {
        cout << "1.Continue to booking room :" << endl;
        cout << "2.Back :" << endl;
        cin >> n;
        if (n == 1) {
            goto continuee;
        } else if (n == 2)
            return;
    } while (n != 1 || n != 2);
}

void BookingRoom(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer) {
    cout << "      BOOKING ROOM        " << endl;
    cout << "1.Setting Room " << endl;
    cout << "2.Booking Room Process " << endl;
    cout << "3.Back" << endl;
    int n;
    cin >> n;
    switch (n) {
    case 1:
        SettingRoom(databaseRoom);
        break;
    case 2:
        BookingRoomProcess(databaseRoom, databaseCustomer);
        break;
    default:
        break;
    }
}

void printCustomer(vector<Customer> databaseCustomer) {
    for (int i = 0; i < databaseCustomer.size(); i++) {
        cout << "      INFOR OF CUSTOMER" << endl;
        cout << "NAME :" << databaseCustomer[i].getName() << endl;
        cout << "PHONE NUMBER :" << databaseCustomer[i].getPhoneNumber() << endl;
        cout << "ADDRESS :" << databaseCustomer[i].getAddress() << endl;
        cout << "ID ROOM :" << databaseCustomer[i].getIdroom() << endl;
    }
}

void editInfor(vector<Customer>& databaseCustomer, vector<Room> databaseRoom) {
    int room;
    string newName;
    string newPhone;
    string newAddress;
    cout << "Nhap ID phong can sua thong tin :" << endl;
    cin >> room;
    bool found = false;
    for (int i = 0; i < databaseRoom.size(); i++) {
        if (databaseCustomer[i].getIdroom() == room) {
            cout << "Nhap ten :" << endl;
            cin.ignore();
            getline(cin, newName);
            cout << "Nhap so dien thoai :" << endl;
            cin >> newPhone;
            cout << "Nhap dia chi :" << endl;
            cin.ignore();
            getline(cin, newAddress);
            databaseCustomer[i].setName(newName);
            databaseCustomer[i].setAddress(newAddress);
            databaseCustomer[i].setPhoneNumber(newPhone);
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Thong tin da duoc sua !!" << endl;
    } else {
        cout << "Khong tim thay phong " << endl;
    }
}

void deleteInfor(vector<Customer>& databaseCustomer, vector<Room>& databaseRoom) {
    int room;
    cout << "Nhap ID phong can xoa :" << endl;
    cin >> room;
    bool found = false;
    if (databaseCustomer.empty()) {
        cout << "Khong co thong tin nao !!" << endl;
        return;
    }
    for (int i = 0; i < databaseRoom.size(); i++) {
        if (databaseCustomer[i].getIdroom() == room) {
            databaseCustomer.erase(databaseCustomer.begin() + i);
            found = true;
            databaseRoom[i].checkOut();
            break;
        }
    }
    if (found) {
        cout << "Thong tin da duoc xoa !!" << endl;
    } else {
        cout << "Khong tim thay ID phong can xoa " << endl;
    }
}

////////////////////////////////////////////////////////////

void AddEmployment(vector<Employee>&databaseEmployee){
    cout<<"  ADD EMPLOYMENT"<<endl;
    int ID;
    string name;
    string phone;
    string position;
    Schedule employeeSchedule ; 
    Schedule employeeSchedule2;
continuee:
    cout<<"Enter ID"<<endl;
    cin>>ID;
    cout << "Enter employee name : "<<endl;
    cin.ignore(); 
    getline(cin, name);
    cout << "Enter employee phone : "<<endl;
    getline(cin, phone);
    cout << "Enter employee position : "<<endl;
    getline(cin, position);
    cout << "Enter employee schedule : "<<endl;
    cout << "1.7h-16h\n2.16h-23h";
    employeeSchedule.timein = {7,0};
    employeeSchedule.timeout = {16,0};
    employeeSchedule2.timein = {16,0};
    employeeSchedule2.timeout = {23,0};
    int choice;
    cin >> choice;
    if(choice == 1){
        Employee employee(ID,name,phone,position,employeeSchedule);
        databaseEmployee.push_back(employee);
    }else if(choice == 2){
        Employee employee(ID,name,phone,position,employeeSchedule2);
        databaseEmployee.push_back(employee);
    }else {
        return;
    }
    int n;
    do {
        cout << "1.Tiep tuc them nhan vien :" << endl;
        cout << "2.Quay lai :" << endl;
        cin >> n;
        if (n == 1) {
            goto continuee;
        }
        else if (n == 2) return;
    } while (n != 1 || n != 2);
}    

void EditEmployee(vector<Employee>&databaseEmployee){
    cout<<"  EDIT EMPLOYEE"<<endl;
    int ID;
    string newname;
    string newphone;
    string newposition;
    Schedule employeeSchedule ; 
    Schedule employeeSchedule2;
    employeeSchedule.timein = {7,0};
    employeeSchedule.timeout = {16,0};
    employeeSchedule2.timein = {16,0};
    employeeSchedule2.timeout = {23,0};
    cout<<"Enter name need edit :"<<endl;
    cin>>ID;
    bool found = false ;
    continuee :
    for(int i=0 ; i<databaseEmployee.size(); i++){
        if(databaseEmployee[i].getIdEmployee()==ID){
           cout<<"Enter new name : "<<endl;
           cin>>newname;
           cout<<"Enter new phone : "<<endl;
           cin>>newphone;
           cout<<"Enter new position :"<<endl;
           cin>>newposition;
           int choice;
           cout << "Enter employee schedule : ";
           cout << "1.7h-16h\n2.16h-23h";
           cin>>choice;
           if(choice == 1){
              Employee employee(ID,newname,newphone,newposition,employeeSchedule);
              databaseEmployee.push_back(employee);
            }else if(choice == 2){
              Employee employee(ID,newname,newphone,newposition,employeeSchedule2);
              databaseEmployee.push_back(employee);
            }else {
              return;
           }
            found = true; 
            break; 
        }
        if (found) {
        cout << "Thong tin da duoc sua" << endl;
        }
        else {
        cout << "Khong tim thay ID" << endl;
        }
    }
    int n;
    do {
        cout << "1.Tiep tuc them nhan vien :" << endl;
        cout << "2.Quay lai :" << endl;
        cin >> n;
        if (n == 1) {
            goto continuee;
        }
        else if (n == 2) return;
    } while (n != 1 || n != 2);
}

void DeleteEmployee(vector<Employee>&databaseEmployee){
    cout<<"  DELETE EMPLOYEE"<<endl;
    int ID;
    cout<<"Enter ID employee need delete :"<<endl;
    cin>>ID;
    bool found = false;
    for(int i=0 ; i<databaseEmployee.size() ; i++){
        if(databaseEmployee[i].getIdEmployee()==ID){
           databaseEmployee.erase(databaseEmployee.begin()+i);
           found = true;
           break;
        }
        if(found){
            cout<<"Da xoa nhan vien ";
        }else {
            cout<<"Khong tim thay ID ";
        }
    }
}

void EmployeeList(vector<Employee>&databaseEmployee){
    cout<<"  EMPLOYEE LIST"<<endl;
    cout<<"ID \tNAME \t\t PHONE \t POSITION \t SCHEDULE"<<endl;
    for(int i=0;i<databaseEmployee.size();i++){
        cout<<databaseEmployee[i].getIdEmployee()<<"\t";
        cout<<databaseEmployee[i].getNameEmployee()<<"\t";
        cout<<databaseEmployee[i].getPhoneEmployee()<<"\t";
        cout<<databaseEmployee[i].getPositionEmployee()<<"\t";
        cout<<static_cast<int>(databaseEmployee[i].getScheduleEmployee().timein.hour) << ":" << static_cast<int>(databaseEmployee[i].getScheduleEmployee().timein.minute) << "\t";
        cout<<static_cast<int>(databaseEmployee[i].getScheduleEmployee().timeout.hour) << ":" << static_cast<int>(databaseEmployee[i].getScheduleEmployee().timeout.minute)<<endl ;
}
}
void EmployeeManagement(vector<Employee>&databaseEmployee){
    while(1){
    cout<<"\t STAFF MANAGEMENT"<<endl;  
    cout<<"1.ADD STAFF"<<endl;
    cout<<"2.EDIT STAFF"<<endl;
    cout<<"3.DELETE STAFF"<<endl;
    cout<<"4.STAFF LIST"<<endl;
    cout<<"5.CANCER "<<endl;
    int n;
    cin>>n;
    switch(n){
    case 1:
        AddEmployment(databaseEmployee);
        break;
    case 2:
        EditEmployee(databaseEmployee);
        break;
    case 3:
        DeleteEmployee(databaseEmployee);
        break;
    case 4:
        EmployeeList(databaseEmployee);
    case 5: 
        return;
    default:
        break;
    }
    }
}

int main() {
    vector<Room> databaseRoom;
    vector<Customer> databaseCustomer;
    vector<Employee> databaseEmployee;
    int n;
    cout << "\tHotel Management\t" << endl;
    while (1) {
        cout << " 1. BOOKING ROOM." << endl;
        cout << " 2. CLIENT MANAGEMENT." << endl;
        cout << " 3. STAFF MANAGEMENT." << endl;
        cout << " 4. PURCHASE." << endl;
        cout << " 5. SECURITY AND ACCESS" << endl;
        cout << " 6. STATISTICS AND REPORTS" << endl;
        cout << " 7. FEEDBACK AND EVALUATION" << endl;
        cout << " 8. EXIT." << endl << endl;
        cout << " Enter your choice: ";
        cin >> n;
        switch (n) {
        case 1:
            BookingRoom(databaseRoom, databaseCustomer);
            break;
        case 2:
            printCustomer(databaseCustomer);
            int m;
            cout << "1. EDIT INFO CUSTOMER:" << endl;
            cout << "2. DELETE INFO CUSTOMER:" << endl;
            cin >> m;
            switch (m) {
            case 1:
                editInfor(databaseCustomer, databaseRoom);
                break;
            case 2:
                deleteInfor(databaseCustomer, databaseRoom);
                break;
            }
            break;
        case 3:
            Schedule employeeSchedule ; 
            Schedule employeeSchedule2;
            employeeSchedule.timein = {7,0};
            employeeSchedule.timeout = {16,0};
            employeeSchedule2.timein = {16,0};
            employeeSchedule2.timeout = {23,0};
            Employee employee(1,"Minh Tri","112-234","JANITOR",employeeSchedule);
            Employee employee2(2,"Nhat Nam","123-251","RECEPTIONIST",employeeSchedule);
            Employee employee3(3,"Thu Ha","143-413","LAUNDRY STAFF",employeeSchedule2);
            Employee employee4(4,"Thanh Nha","153-461","LUGGAGE STAFF",employeeSchedule2);
            Employee employee5(5,"Van Toan","143-931","GARDENER",employeeSchedule);
            databaseEmployee.push_back(employee);
            databaseEmployee.push_back(employee2);
            databaseEmployee.push_back(employee3);
            databaseEmployee.push_back(employee4);
            databaseEmployee.push_back(employee5);
            EmployeeManagement(databaseEmployee);
            break; 
    }
    }
      return 0;
}
      