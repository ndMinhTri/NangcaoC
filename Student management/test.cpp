#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef enum
{
    ADD = 1,
    DELETE = 2,
    EDIT = 3,
    SEARCH = 4,
    SORTSCORE = 5,
    SORTNAME = 6,
    SHOW = 7,
    EXIT = 8
} MENU;

typedef enum
{
    MALE = 1,
    FEMALE = 2
} TYPE_GENDER;

class Student
{
private:
    int ID;
    string NAME;
    int OLD;
    TYPE_GENDER GENDER;
    double MATH_SCORES;
    double ENGLISH_SCORES;
    double LITERATURE_SCORES;

public:
    Student(string name, int old, TYPE_GENDER gender, double math_scores, double english_scores, double literature_scores);
    void set_name(string name);
    void set_old(int old);
    void set_gender(TYPE_GENDER gender);
    void set_math(double math_scores);
    void set_english(double english_scores);
    void set_literature(double literature_scores);
    int get_id() ;
    string get_name() ;
    int get_old() ;
    TYPE_GENDER get_gender() ;
    double get_math() ;
    double get_english() ;
    double get_literature() ;
};

Student::Student(string name, int old, TYPE_GENDER gender, double math_scores, double english_scores, double literature_scores)
{
    static int id = 1000;
    this->ID = id;
    id++;
    this->NAME = name;
    this->OLD = old;
    this->GENDER = gender;
    this->MATH_SCORES = math_scores;
    this->ENGLISH_SCORES = english_scores;
    this->LITERATURE_SCORES = literature_scores;
}

void Student::set_name(string name)
{
    NAME = name;
}

void Student::set_old(int old)
{
    OLD = old;
}

void Student::set_gender(TYPE_GENDER gender)
{
    GENDER = gender;
}

void Student::set_math(double math_scores)
{
    MATH_SCORES = math_scores;
}

void Student::set_english(double english_scores)
{
    ENGLISH_SCORES = english_scores;
}

void Student::set_literature(double literature_scores)
{
    LITERATURE_SCORES = literature_scores;
}

int Student::get_id() 
{
    return ID;
}

string Student::get_name() 
{
    return NAME;
}

int Student::get_old() 
{
    return OLD;
}

TYPE_GENDER Student::get_gender() 
{
    return GENDER;
}

double Student::get_math() 
{
    return MATH_SCORES;
}

double Student::get_english() 
{
    return ENGLISH_SCORES;
}

double Student::get_literature() 
{
    return LITERATURE_SCORES;
}

void add_student(vector<Student> &database_student)
{
    string name_sv;
    int old_sv;
    int gender_sv;
    double math_sv;
    double english_sv;
    double literature_sv;
Continuee:
    cin.ignore();
    cout << "Ten sinh vien : ";
    getline(cin, name_sv);
    cout << "Tuoi sinh vien : ";
    cin >> old_sv;
    do
    {
        cout << "Gioi tinh (1.Nam--2.Nu) :";
        cin >> gender_sv;
    } while (gender_sv != 1 && gender_sv != 2);
    do
    {
        cout << "Diem toan : ";
        cin >> math_sv;
    } while (math_sv < 0 || math_sv > 10);
    do
    {
        cout << "Diem anh van : ";
        cin >> english_sv;
    } while (english_sv < 0 || english_sv > 10);
    do
    {
        cout << "Diem ngu van : ";
        cin >> literature_sv;
    } while (literature_sv <= 0 || literature_sv >= 10);

    Student new_student(name_sv, old_sv, static_cast<TYPE_GENDER>(gender_sv), math_sv, english_sv, literature_sv);

    database_student.push_back(new_student);

    int n;
    do
    {
        cout << "Tiep tuc them sinh vien : " << endl;
        cout << "Nhap : 1.Co     2.Khong" << endl;
        cin >> n;
        if (n == 1)
        {
            goto Continuee;
        }
        else if (n == 2)
        {
            return;
        }

    } while (n != 1 || n != 2);
}

void show_infor( vector<Student> &database_student) 
{
    cout << "\tStudent list\t" << endl;
    cout << "STT\tID\tNAME\tOLD\tGENDER\tMATH\tENGLISH\tLITERATURE" << endl;
    for (int i = 0; i < database_student.size(); i++)
    {
        cout << "" << i + 1;
        cout << "\t" << database_student[i].get_id();
        cout << "\t" << database_student[i].get_name();
        cout << "\t" << database_student[i].get_old();
        if (database_student[i].get_gender() == MALE)
            cout << "\tNam";
        else if (database_student[i].get_gender() == FEMALE)
            cout << "\tNu";
        cout << "\t" << database_student[i].get_math();
        cout << "\t" << database_student[i].get_english();
        cout << "\t" << database_student[i].get_literature();
        cout << "\n";
    }
    int n;
    do
    {
        cout << "\nnhan phim 0 de thoat : ";
        cin >> n;
    } while (n != 0);
}

void Delete_student(vector<Student> &database_student)
{
continuee:
    cout << "\tDELETE STUDENT\t" << endl;
    int ID_temp;
    do
    {
        cout << "Nhap ID muon xoa (1000->" << 1000 + database_student.size() - 1 << ")" << endl;
        cin >> ID_temp;
    } while ((ID_temp < 1000) || (ID_temp > 1000 + database_student.size() - 1));

    database_student.erase(database_student.begin() + (ID_temp - 1000));

    int n;
enter:
    cout << "Nhan phim 1 de tiep tuc xoa sinh vien" << endl;
    cout << "Nhan phim 0 de thoat: " << endl;
    cin >> n;
    switch (n)
    {
    case 0:
        break;
    case 1:
        goto continuee;
        break;
    default:
        goto enter;
        break;
    }
}

void edit_student(vector<Student> &database_student)
{
    int ID_temp;
Continuee:
    cout << "Nhap ID sinh vien can sua thong tin: ";
    cin >> ID_temp;

    for (int i = 0; i < database_student.size(); i++)
    {
        if (ID_temp == database_student[i].get_id())
        {
            cout << "\tStudent Information\t" << endl;
            cout << "ID: " << database_student[i].get_id() << endl;

            // Display the current information
            cout << "Current Name: " << database_student[i].get_name() << endl;
            cout << "Current Age: " << database_student[i].get_old() << endl;
            cout << "Current Gender: " << (database_student[i].get_gender() == MALE ? "Nam" : "Nu") << endl;
            cout << "Current Math Score: " << database_student[i].get_math() << endl;
            cout << "Current English Score: " << database_student[i].get_english() << endl;
            cout << "Current Literature Score: " << database_student[i].get_literature() << endl;

            // Prompt for updated information
            string new_name;
            int new_age;
            int new_gender;
            double new_math;
            double new_english;
            double new_literature;

            cout << "Nhap thong tin moi:" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, new_name);
            cout << "Age: ";
            cin >> new_age;
            do
            {
                cout << "Gender (1.Nam--2.Nu): ";
                cin >> new_gender;
            } while (new_gender != 1 && new_gender != 2);
            do
            {
                cout << "Math Score: ";
                cin >> new_math;
            } while (new_math < 0 || new_math > 10);
            do
            {
                cout << "English Score: ";
                cin >> new_english;
            } while (new_english < 0 || new_english > 10);
            do
            {
                cout << "Literature Score: ";
                cin >> new_literature;
            } while (new_literature <= 0 || new_literature >= 10);

            // Update the student's information
            database_student[i].set_name(new_name);
            database_student[i].set_old(new_age);
            database_student[i].set_gender(static_cast<TYPE_GENDER>(new_gender));
            database_student[i].set_math(new_math);
            database_student[i].set_english(new_english);
            database_student[i].set_literature(new_literature);

            cout << "Thong tin sinh vien da duoc cap nhat." << endl;
            break;
        }
        if (ID_temp != database_student[i].get_id()){
              cout << "Khong tim thay sinh vien co ID " << ID_temp << endl;
            }
    }

    
    int n;
    do
    {
        cout << "Tiep tuc cap nhap sinh vien : " << endl;
        cout << "Nhap : 1.Co     2.Khong" << endl;
        cin >> n;
        if (n == 1)
        {
            goto Continuee;
        }
        else if (n == 2)
        {
            return;
        }

    } while (n != 1 || n != 2);
}

// Function to search for a student by ID
void search_student( vector<Student> &database_student) // Marked as const
{
    int ID_temp;
Continuee:
    cout << "Nhap ID sinh vien can tim: ";
    cin >> ID_temp;

    for (int i = 0; i < database_student.size(); i++)
    {
        if (ID_temp == database_student[i].get_id())
        {
            cout << "\tStudent Information\t" << endl;
            cout << "ID: " << database_student[i].get_id() << endl;
            cout << "Name: " << database_student[i].get_name() << endl;
            cout << "Age: " << database_student[i].get_old() << endl;
            cout << "Gender: " << (database_student[i].get_gender() == MALE ? "Nam" : "Nu") << endl;
            cout << "Math Score: " << database_student[i].get_math() << endl;
            cout << "English Score: " << database_student[i].get_english() << endl;
            cout << "Literature Score: " << database_student[i].get_literature() << endl;
            break;
        }
         if (ID_temp != database_student[i].get_id()){
            cout << "Khong tim thay sinh vien co ID " << ID_temp << endl;
        }
    }
    int n;
    do
    {
        cout << "Tiep tuc tim sinh vien : " << endl;
        cout << "Nhap : 1.Co     2.Khong" << endl;
        cin >> n;
        if (n == 1)
        {
            goto Continuee;
        }
        else if (n == 2)
        {
            return;
        }

    } while (n != 1 || n != 2);
}


// Function to calculate the average score of a student
double calculate_average_score( Student &student) // Marked as const
{
    return (student.get_math() + student.get_english() + student.get_literature()) / 3.0;
}

// Function to sort students by their average scores
void sorted_student(vector<Student> &database_student)
{
    sort(database_student.begin(), database_student.end(), []( Student &a, Student &b) {
        return calculate_average_score(a) > calculate_average_score(b);
    });
    show_infor(database_student);
}

// Function to sort students by their names
void sort_student_by_name(vector<Student> &database_student)
{
    sort(database_student.begin(), database_student.end(), [](Student &a, Student &b) {
        return a.get_name() < b.get_name();
    });
    show_infor(database_student);
}

int main()
{
    vector<Student> database_student;
    int n;
    while (1)
    {
        cout << "\tMENU\t" << endl;
        cout << "1.Them sinh vien" << endl;
        cout << "2.Xoa sinh vien bang id" << endl;
        cout << "3.Chinh sua thong tin sinh vien" << endl;
        cout << "4.Tim kiem sinh vien bang id" << endl;
        cout << "5.Sap xep sinh vien theo diem trung binh" << endl;
        cout << "6.Sap xep sinh vien theo ten" << endl;
        cout << "7.Hien thi thong tin sinh vien" << endl;
        cout << "8.Thoat" << endl;
    menu:
        cout << "Chon : ";
        cin >> n;
        switch(n)
        {
        case ADD:
            add_student(database_student);
            break;
        case DELETE:
            Delete_student(database_student);
            break;
        case EDIT:
            edit_student(database_student);
            break;
        case SEARCH:
            search_student(database_student);
            break;
        case SORTSCORE:
            sorted_student(database_student);
            break;
        case SORTNAME:
            sort_student_by_name(database_student);
            break;
        case SHOW:
            show_infor(database_student);
            break;
        case EXIT:
            return 0;
        default:
            cout << "Invalid choice. Please select a valid option from the menu." << endl;
            break;
        }
    }
    return 0;
}