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
    int GetPrice() ;
    int GetId() ;
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

int Dish::GetId()  {
    return ID;
}

int Dish::GetPrice()  {
    return PRICE;
}

string Dish::GetName()  {
    return NAME;
}

class DishOnTable : public Dish {
private:
    int QUANTITY;

public:
    DishOnTable(int quantity);
    void SetQuantity(int quantity);
    int GetQuantity() ;
};

DishOnTable::DishOnTable(int quantity) {
    this->QUANTITY = quantity;
}

void DishOnTable::SetQuantity(int quantity) {
    QUANTITY = quantity;
}

int DishOnTable::GetQuantity()  {
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
    int getNumberOfTable() ;
    bool GetStatus() ;
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

int Table::getNumberOfTable()  {
    return this->NUMBEROFTABLE;
}

bool Table::GetStatus()  {
    return this->STATUS;
}

vector<DishOnTable>& Table::getdatabaseDishOnTable() {
    return this->databaseDishOnTable;
}


// Function to display the menu
void DishList(vector<Dish>& databaseDishOnMenu) {
    cout << "ID\t\tNAME\t\tPRICE" << endl;
    for (int i = 0; i < databaseDishOnMenu.size(); i++) {
        cout << databaseDishOnMenu[i].GetId() << "\t\t";
        cout << databaseDishOnMenu[i].GetName() << "\t";
        cout << databaseDishOnMenu[i].GetPrice() << "\t" << endl;
    }
}

// Function to set the number of tables
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
                Table x(i + 1);
                databaseTable.push_back(x);
            }
            break;
        case 2:
            return;
        default:
            cout << "Phim khong hop le" << endl;
            break;
    }
}

// Function to add a dish to the menu
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
    cin >> price;
    cout << "Enter the ID of the dish: ";
    cin >> id;
    Dish DishOnMenu(id, name, price);
    databaseDishOnMenu.push_back(DishOnMenu);
    int n;
    do {
        cout << "1.Tiep tuc them mon :" << endl;
        cout << "2.Quay lai :" << endl;
        cin >> n;
        if (n == 1) {
            goto continuee;
        }
        else if (n == 2) return;
    } while (n != 1 || n != 2);
}

// Function to edit a dish in the menu
void EditDish(vector<Dish>& databaseDishOnMenu) {
    cout << "\t Manager \t" << endl;
    for (int i = 0; i < databaseDishOnMenu.size(); i++) {
        cout << databaseDishOnMenu[i].GetId() << "\t";
        cout << databaseDishOnMenu[i].GetName() << "\t";
        cout << databaseDishOnMenu[i].GetPrice() << "\t" << endl;
    }
    int id;
    string newname;
    int newprice;
    cout << "Nhap ID mon an can sua :" << endl;
    cin >> id;

    bool found = false; // Flag to track whether the ID was found

    for (int i = 0; i < databaseDishOnMenu.size(); i++) {
        if (databaseDishOnMenu[i].GetId() == id) {
            cout << "Ten mon an :" << endl;
            cin.ignore();
            getline(cin, newname);
            cout << "Gia :" << endl;
            cin >> newprice;
            databaseDishOnMenu[i].SetName(newname);
            databaseDishOnMenu[i].SetPrice(newprice);
            found = true; // ID was found
            break; // Exit the loop once the item is edited
        }
    }

    if (found) {
        cout << "Mon an da duoc sua" << endl;
    }
    else {
        cout << "Khong tim thay ID" << endl;
    }
}

// Function to delete a dish from the menu
void DeleteDish(vector<Dish>& databaseDishOnMenu) {
    int ID;
    cout << "\tDELETE DISH\t" << endl;
    cout << "Nhap ID muon xoa : " << endl;
    cin >> ID;

    bool found = false; // Flag to track whether the ID was found

    for (int i = 0; i < databaseDishOnMenu.size(); i++) {
        if (databaseDishOnMenu[i].GetId() == ID) {
            databaseDishOnMenu.erase(databaseDishOnMenu.begin() + i);
            found = true; // ID was found
            break; // Exit the loop once the item is deleted
        }
    }

    if (found) {
        cout << "Mon an da duoc xoa" << endl;
    }
    else {
        cout << "Khong tim thay ID" << endl;
    }
}

// Function to set the manager role
void SetManager(vector<Dish>& databaseDishOnMenu, vector<Table>& databaseTable) {
    vector<DishOnTable> order;
    Dish DishOnMenu(1, "ga nuong", 250);
    Dish DishOnMenu2(2, "Tom hap\t", 170);
    Dish DishOnMenu3(3, "De rung\t", 270);
    Dish DishOnMenu4(4, "Bo Kobe\t", 400);
    Dish DishOnMenu5(5, "Muc chien", 200);
    Dish DishOnMenu6(6, "Chim cuc", 40);
    Dish DishOnMenu7(7, "Heo rung", 340);
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
    while (1) {
        cout << "\tManager\t" << endl;
        cout << "1.Set so ban" << endl;
        cout << "2.Them mon vao menu" << endl;
        cout << "3.Sua mon" << endl;
        cout << "4.Xoa mon" << endl;
        cout << "5.Danh sach mon" << endl;
        cout << "6.Quay lai" << endl;
        int n;
        cin >> n;
        switch (n) {
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
                DeleteDish(databaseDishOnMenu);
                break;
            case 5:
                DishList(databaseDishOnMenu);
                break;
            case 6:
                return;
            default:
                cout << "Lua chon khong hop le" << endl;
                break;
        }
    }
}

// Function to display the dishes ordered on a table
void PrintDishOnTable(vector<Table>& databaseTable, int TableNumber) {
    if (TableNumber < 1 || TableNumber > databaseTable.size()) {
        cout << "Invalid table number." << endl;
        return;
    }
    vector<DishOnTable>& DishOnTable = databaseTable[TableNumber - 1].getdatabaseDishOnTable();

    cout << "BAN " << TableNumber << endl;
    cout << " \t\tDanh sach mon an\t\t" << endl;
    cout << "STT\t\t";
    cout << "ID\t\t";
    cout << "Ten\t\t";
    cout << "Gia\t\t";
    cout << "So luong\t\t";
    cout << endl;

    for (int i = 0; i < DishOnTable.size(); i++) {
        cout << i + 1 << "\t";
        cout<<"\t";
        cout << DishOnTable[i].GetId() << "\t\t";
        cout << DishOnTable[i].GetName() << "\t";
        cout << DishOnTable[i].GetPrice() << "\t\t";
        cout << DishOnTable[i].GetQuantity() << "\t";
        cout << endl;
    }
}

// Function to add a dish to a table's order
void AddDishOnTable(vector<Table>& databaseTable, int TableNumber, vector<Dish>& databaseDishOnMenu) {
    if (TableNumber < 1 || TableNumber > databaseTable.size()) {
        cout << "Invalid table number." << endl;
        return;
    }

    Table& table = databaseTable[TableNumber - 1];  // Get the reference to the selected table

    // Check if the table is available (status is false)
    // if (table.GetStatus()) {
    //     cout << "Table " << TableNumber << " is already occupied." << endl;
    //     return;
    // }

    // Print the menu for the staff to choose a dish
    cout << "Menu:\n";
    for (int i = 0; i < databaseDishOnMenu.size(); i++) {
        cout << i + 1 << ". " << databaseDishOnMenu[i].GetName() << " - $" << databaseDishOnMenu[i].GetPrice() << endl;
    }

    int choice;
    cout << "Enter the number of the dish to add: ";
    cin >> choice;

    if (choice < 1 || choice > databaseDishOnMenu.size()) {
        cout << "Invalid choice." << endl;
        return;
    }

    int quantity;
    cout << "Enter the quantity: ";
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Invalid quantity." << endl;
        return;
    }
    
    // Create a DishOnTable object and set its properties
    DishOnTable dishOnTable(quantity);
    dishOnTable.SetId(databaseDishOnMenu[choice - 1].GetId());
    dishOnTable.SetName(databaseDishOnMenu[choice - 1].GetName());
    dishOnTable.SetPrice(databaseDishOnMenu[choice - 1].GetPrice());

    // Add the dish to the table's order list
    table.getdatabaseDishOnTable().push_back(dishOnTable);

    // Update the table's status to indicate it's occupied
    table.SetStatus(false);

    cout << "Dish added to Table " << TableNumber << " successfully." << endl;
}

// Function to edit a dish in a table's order
void EditDishOnTable(vector<Table>& databaseTable, int TableNumber) {
    if (TableNumber < 1 || TableNumber > databaseTable.size()) {
        cout << "Invalid table number." << endl;
        return;
    }

    Table& table = databaseTable[TableNumber - 1];  // Get the reference to the selected table

    
    // Display the dishes on the table's order
    PrintDishOnTable(databaseTable, TableNumber);

    int choice;
    cout << "Enter the number of the dish to edit: ";
    cin >> choice;

    vector<DishOnTable>& DishOnTable = table.getdatabaseDishOnTable();

    if (choice < 1 || choice > DishOnTable.size()) {
        cout << "Invalid choice." << endl;
        return;
    }

    int newQuantity;
    cout << "Enter the new quantity: ";
    cin >> newQuantity;

    if (newQuantity <= 0) {
        cout << "Invalid quantity." << endl;
        return;
    }

    // Update the quantity of the selected dish
    DishOnTable[choice - 1].SetQuantity(newQuantity);

    cout << "Dish quantity updated successfully." << endl;
}

// Function to delete a dish from a table's order
void DeleteDishFromTable(vector<Table>& databaseTable, int TableNumber) {
    if (TableNumber < 1 || TableNumber > databaseTable.size()) {
        cout << "Invalid table number." << endl;
        return;
    }

    Table& table = databaseTable[TableNumber - 1];  // Get the reference to the selected table

    if (table.GetStatus()) {
        cout << "Table " << TableNumber << " is not occupied." << endl;
        return;
    }

    // Display the dishes on the table's order
    PrintDishOnTable(databaseTable, TableNumber);

    int choice;
    cout << "Enter the number of the dish to delete: ";
    cin >> choice;

    vector<DishOnTable>& DishOnTable = table.getdatabaseDishOnTable();

    if (choice < 1 || choice > DishOnTable.size()) {
        cout << "Invalid choice." << endl;
        return;
    }

    // Remove the selected dish from the table's order
    DishOnTable.erase(DishOnTable.begin() + choice - 1);

    cout << "Dish deleted from the table's order successfully." << endl;
}

// Function to process payment for a table's order
void ProcessPayment(vector<Table>& databaseTable, int TableNumber) {
    if (TableNumber < 1 || TableNumber > databaseTable.size()) {
        cout << "Invalid table number." << endl;
        return;
    }

    Table& table = databaseTable[TableNumber - 1];  // Get the reference to the selected table

    if (table.GetStatus()) {
        cout << "Table " << TableNumber << " is not occupied." << endl;
        return;
    }
    vector<DishOnTable>& dishesOnTable = table.getdatabaseDishOnTable();
    if (dishesOnTable.empty()) {
        cout << "No dishes ordered on Table " << TableNumber << "." << endl;
        return;
    }

    // Calculate the total bill for the table
    int totalBill = 0;
    for ( DishOnTable& dish : dishesOnTable) {
        totalBill += dish.GetPrice() * dish.GetQuantity();
    }

    // Display the bill and process payment
    cout << "Hoa don cho BAN " << TableNumber << endl;
    cout << "STT\t\t";
    cout << "ID\t\t";
    cout << "Ten\t\t";
    cout << "Gia\t\t";
    cout << "So luong\t\t";
    cout << endl;

    for (int i = 0; i < dishesOnTable.size(); i++) {
        cout << i + 1 << "\t";
        cout<<"\t";
        cout << dishesOnTable[i].GetId() << "\t\t";
        cout << dishesOnTable[i].GetName() << "\t";
        cout << dishesOnTable[i].GetPrice() << "\t\t";
        cout << dishesOnTable[i].GetQuantity() << "\t";
        cout << endl;
    }

    cout << "Tong hoa don: $" << totalBill << endl;

    // Clear the table's order and update the table's status
    dishesOnTable.clear();
    table.SetStatus(true);

    cout << "Thanh toan hoa don thanh cong." << endl;
}

// Function to handle the staff role
void Staff(vector<Table>& databaseTable, vector<Dish>& databaseDishOnMenu) {
    cout << "\t Danh sach ban \t" << endl;
    if (databaseTable.empty()) {
        cout << "Chua nhap so ban" << endl;
        return;
    }

    for (int i = 0; i < databaseTable.size(); i++) {
        cout << "Ban " << databaseTable[i].getNumberOfTable();
        cout << "\t\tTrang thai " << (databaseTable[i].GetStatus() ? "trong" : "da dat") << endl;
    }

    int TableNumber;
    cout << "Nhap so ban: ";
    cin >> TableNumber;

    if (TableNumber < 1 || TableNumber > databaseTable.size()) {
        cout << "Invalid table number." << endl;
        return;
    }

    int choice;
    cout << "1. Them mon an" << endl;
    cout << "2. Sua mon an" << endl;
    cout << "3. Xoa mon an" << endl;
    cout << "4. Danh sach mon an tren ban" << endl;
    cout << "5. Thanh toan" << endl;
    cout << "6. Quay lai" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;

    switch (choice) {
        case 1:
            AddDishOnTable(databaseTable, TableNumber, databaseDishOnMenu);
            break;
        case 2:
            EditDishOnTable(databaseTable, TableNumber);
            break;
        case 3:
            DeleteDishFromTable(databaseTable, TableNumber);
            break;
        case 4:
            PrintDishOnTable(databaseTable, TableNumber);
            break;
        case 5:
            ProcessPayment(databaseTable, TableNumber);
            break;
        case 6:
            return;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
    }
}

int main() {
    vector<Dish> databaseDishOnMenu;
    vector<Table> databaseTable;

    int choice;

    while (true) {
        cout << "\n\tCHAO MUNG BAN DEN VOI NHA HANG CUA CHUNG TOI\t" << endl;
        cout << "1. Quan ly" << endl;
        cout << "2. Nhan vien" << endl;
        cout << "3. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                SetManager(databaseDishOnMenu, databaseTable);
                break;
            case 2:
                Staff(databaseTable, databaseDishOnMenu);
                break;
            case 3:
                return 0;
            default:
                cout << "Lua chon khong hop le." << endl;
                break;
        }
    }

    return 0;
}