#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dish {
private:
    int ID;
    string NAME;
    int PRICE;

public:
    Dish(int id = 0, string name = "", int price = 0);
    void SetName(string name);
    void SetPrice(int price);
    void SetId(int id);
    string GetName();
    int GetPrice();
    int GetId();
};

Dish::Dish(int id, string name, int price) {
    this->ID = id;
    this->NAME = name;
    this->PRICE = price;
}

void Dish::SetName(string name) {
    NAME = name;
}

void Dish::SetPrice(int price) {
    PRICE = price;
}

void Dish::SetId(int id) {
    ID = id;
}

int Dish::GetId() {
    return ID;
}

int Dish::GetPrice() {
    return PRICE;
}

string Dish::GetName() {
    return NAME;
}

class DishOnTable : public Dish {
private:
    int QUANTITY;

public:
    DishOnTable(int quantity);
    void SetQuantity(int quantity);
    int GetQuantity();
};

DishOnTable::DishOnTable(int quantity) {
    this->QUANTITY = quantity;
}

void DishOnTable::SetQuantity(int quantity) {
    QUANTITY = quantity;
}

int DishOnTable::GetQuantity() {
    return QUANTITY;
}

class Table {
private:
    vector<DishOnTable> databaseDishOnTable;
    int NUMBEROFTABLE;
    bool STATUS;

public:
    Table(int NumberOfTable);
    void SetStatus(bool status);
    void SetNumberOfTable(int NumberOfTable);
    int getNumberOfTable();
    bool GetStatus();
    vector<DishOnTable>& getdatabaseDishOnTable();
};

Table::Table(int NumberOfTable) {
    this->NUMBEROFTABLE = NumberOfTable;
}

void Table::SetStatus(bool status) {
    STATUS = status;
}

void Table::SetNumberOfTable(int NumberOfTable) {
    NUMBEROFTABLE = NumberOfTable;
}

int Table::getNumberOfTable() {
    return NUMBEROFTABLE;
}

bool Table::GetStatus() {
    return STATUS;
}

vector<DishOnTable>& Table::getdatabaseDishOnTable() {
    return databaseDishOnTable;
}

// SETTING MANAGER

void DishList(vector<Dish>& databaseDishOnMenu) {
    cout << "ID\t\tNAME\t\tPRICE" << endl;
    for (int i = 0; i < databaseDishOnMenu.size(); i++) {
        cout << databaseDishOnMenu[i].GetId() << "\t\t";
        cout << databaseDishOnMenu[i].GetName() << "\t";
        cout << databaseDishOnMenu[i].GetPrice() << "\t" << endl;
    }
}

void SetTable(vector<Table>& databaseTable) {
    cout << "Manager" << endl;
    int n;
    cout << "1.Nhap so luong ban " << endl;
    cout << "2.Quay lai " << endl;
    cin >> n;
    switch (n) {
    case 1:
        int table;
        cout << "Nhap so luong : " << endl;
        cin >> table;
        for (int i = 0; i < table; i++) {
            Table x ( i + 1);
            databaseTable.push_back(x);
        }
        break;
    case 2:
        return;
        break;
    default:
        cout << "Phim khong hop le" << endl;
        break;
    }
}

void AddDish(vector<Dish>& databaseDishOnMenu) {
    cout << "\tManager\t" << endl;
    string name;
    int price;
    int id;
    continuee:
    cout << "Enter the name of the dish: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);
    cout << "Enter the price of the dish: ";
    cin.ignore();
    cin>>price;
    cout << "Enter the ID of the dish: ";
    cin>>id;
    Dish DishOnMenu (id,name,price);
    databaseDishOnMenu.push_back(DishOnMenu);
    int n;
    do{
        cout<<"1.Tiep tuc them mon :"<<endl;
        cout<<"2.Quay lai :"<<endl;
        cin>>n;
        if(n==1){
            goto continuee;
        }
        else if(n==2) return;
    }while(n!=1||n!=2);
}

void EditDish(vector<Dish> &databaseDishOnMenu){
    cout<<"\t Manager \t"<<endl;  
    for(int i=0;i<databaseDishOnMenu.size();i++){
        cout<<databaseDishOnMenu[i].GetId()<<"\t"<<endl;
        cout<<databaseDishOnMenu[i].GetName()<<"\t"<<endl;
        cout<<databaseDishOnMenu[i].GetPrice()<<"\t"<<endl;
    }
    int id;
    string newname;
    int newprice;
    continuee:
    cout<<"Nhap ID mon an can sua :"<<endl;
    cin>>id;
    for(int i=0;i<databaseDishOnMenu.size();i++){
        if(databaseDishOnMenu[i].GetId()==id){
            cout<<"Ten mon an :"<<endl;
            cin.ignore();
            getline(cin,newname);
            cout<<"Gia :"<<endl;
            cin>>newprice;
            databaseDishOnMenu[i].SetName(newname);
            databaseDishOnMenu[i].SetPrice(newprice);
        }
        else if(databaseDishOnMenu[i].GetId()!=id){
            cout<<"Khong tim thay id"<<endl;
            return;
        }
    }
    int n;
    do{
        cout<<"1.Tiep tuc sua mon :"<<endl;
        cout<<"2.Quay lai :"<<endl;
        cin>>n;
        if(n==1){
            goto continuee;
        }
        else if(n==2) return;
    }while(n!=1||n!=2);
    
}

void deleteDish(vector<Dish>& databaseDishOnMenu){
    continuee:
    cout << "\tDELETE DISH\t" << endl;
    int ID;
    do
    {
        cout << "Nhap ID muon xoa : " <<  endl;
        cin >> ID;
    } while (ID < 0 );
    for(int i=0;databaseDishOnMenu.size()-1;i++){
        if(databaseDishOnMenu[i].GetId()==ID){
            databaseDishOnMenu.erase(databaseDishOnMenu.begin()+i);
            break;
        }
        else if(databaseDishOnMenu[i].GetId()!=ID){
            cout<<"Khong tim thay ID"<<endl;
        }
    }
    int n;
    do{
        cout<<"1.Tiep tuc xoa mon :"<<endl;
        cout<<"2.Quay lai :"<<endl;
        cin>>n;
        if(n==1){
            goto continuee;
        }
        else if(n==2) return;
    }while(n!=1||n!=2);

}


void SetManager(vector<Dish>& databaseDishOnMenu, vector<Table>& databaseTable) {
    vector<DishOnTable> order;
    Dish DishOnMenu  (1,"ga nuong",250);
    Dish DishOnMenu2 (2,"Tom hap\t",170);
    Dish DishOnMenu3 (3,"De rung\t",270);
    Dish DishOnMenu4 (4,"Bo Kobe\t",400);
    Dish DishOnMenu5 (5,"Muc chien",200);
    Dish DishOnMenu6 (6,"Chim cuc",40);
    Dish DishOnMenu7 (7,"Heo rung",340);
    databaseDishOnMenu.push_back(DishOnMenu);
    databaseDishOnMenu.push_back(DishOnMenu2);
    databaseDishOnMenu.push_back(DishOnMenu3);
    databaseDishOnMenu.push_back(DishOnMenu4);
    databaseDishOnMenu.push_back(DishOnMenu5);
    databaseDishOnMenu.push_back(DishOnMenu6);
    databaseDishOnMenu.push_back(DishOnMenu7);
    cout << "ID\t\tNAME\t\tPRICE" << endl;
    for (int i = 0; i < databaseDishOnMenu.size(); i++) {
        cout << databaseDishOnMenu[i].GetId() << "\t\t";
        cout << databaseDishOnMenu[i].GetName() << "\t";
        cout << databaseDishOnMenu[i].GetPrice() << "\t" << endl;
    }
    while(1){
    cout << "\tManager\t" << endl;
    cout << "1.Set so ban" << endl;
    cout << "2.Them mon vao menu" << endl;
    cout << "3.Sua mon" << endl;
    cout << "4.Xoa mon" << endl;
    cout << "5.Danh sach mon" << endl;
    cout << "6.Quay lai" << endl;
    int n;
    cin >> n;
    switch (n){
    case 1:
        SetTable(databaseTable);
        break;
    case 2:
        AddDish(databaseDishOnMenu);
        break;
    case 3:
        EditDish(databaseDishOnMenu);
        break;
    case 4:
        deleteDish(databaseDishOnMenu);
        break;
    case 5:
        DishList(databaseDishOnMenu);
        break;
    case 6:
        break;
    }
}
}

//SETTING STAFF
// void Staff(vector<Table> &databaseTable){
//     cout<<"\t Danh sach ban \t"<<endl;
//     for(int i=0;i<databaseTable.size()-1;i++){
//         cout<<"Ban"<<databaseTable[i].getNumberOfTable();
//         cout<<"\t\tTrang thai"<<databaseTable[i].GetStatus()<<endl;
//     }
//     int tableNumber
//     cout<<"nhap so ban :"<<endl;
//     cin>>tableNumber;
    
// }


int main() {
    vector<Dish> databaseDishOnMenu;
    vector<Table> databaseTable;
    int n;
    do {
        cout << "1.Manager\n2.Staff" << endl;
        cout << "Lua chon :" << endl;
        cin >> n;
        if (n == 1) {
            SetManager(databaseDishOnMenu, databaseTable);
        }
        else if (n == 2) {

        }
    } while (n != 1 && n != 2);

    return 0;
}