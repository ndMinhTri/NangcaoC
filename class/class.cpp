#include<iostream>
#include<string>

using namespace std;

class Doituong{
    public:
    void SetThongTin(string ten , string gioi_tinh , int tuoi);
    void Hienthi();
    protected :
    int TUOI;
    string GIOI_TINH;
    string TEN;
    
};

void Doituong::SetThongTin(string ten , string gioi_tinh , int tuoi){
    TEN = ten;
    GIOI_TINH = gioi_tinh;
    TUOI = tuoi ;
}

void Doituong::Hienthi(){
    cout<<"Ten : "<<TEN<<endl;
    cout<<"TUOI : "<<TUOI<<endl;
    cout<<"Gioi Tinh : "<<GIOI_TINH<<endl;
}

class Sinhvien : public Doituong{
    public :
    void SetThongTin(string ten , string gioi_tinh , int tuoi, int mssv);
    void Hienthi();
    private :
     int MSSV;
};

void Sinhvien::SetThongTin(string ten , string gioi_tinh , int tuoi, int mssv){
    TEN = ten;
    GIOI_TINH = gioi_tinh;
    TUOI = tuoi ;
    MSSV = mssv;
}

void Sinhvien::Hienthi(){
    cout<<"Ten : "<<TEN<<endl;
    cout<<"TUOI : "<<TUOI<<endl;
    cout<<"Gioi Tinh : "<<GIOI_TINH<<endl;
    cout<<"MSSV : "<<MSSV<<endl;
}
int main(){
    Doituong dt;
    Sinhvien sv;
    sv.SetThongTin("vy","nu",19,1002);
    sv.Hienthi();
}