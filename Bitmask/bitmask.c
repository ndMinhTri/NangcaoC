#include <stdio.h>
#include <stdint.h>

uint8_t GIO_HANG = 0;

typedef enum{
    AO = 1 << 0,
    QUAN = 1 << 1,
    VAY = 1 << 2,
    DAM = 1 << 3,
    NHAN = 1 << 4,
    VONG_TAY = 1 << 5,
    GIAY = 1 << 6,
    TUI = 1 << 7,
}Do_dung_ca_nhan;

void Add_gio_hang(uint8_t *GIO_HANG, Do_dung_ca_nhan item){
    *GIO_HANG |= item;
}

void ShowItem(uint8_t GIO_HANG){
    printf("\nTrong gio hang co: ");
    if((GIO_HANG&AO)==0X01) printf("\n ao");
    if((GIO_HANG&QUAN)==0X02) printf("\n quan");
    if((GIO_HANG&VAY)==0X04) printf("\n vay");
    if((GIO_HANG&DAM)==0X08) printf("\n dam");
    if((GIO_HANG&NHAN)==0X10) printf("\n nhan");
    if((GIO_HANG&VONG_TAY)==0X20) printf("\n vong tay");
    if((GIO_HANG&GIAY)==0X40) printf("\n giay");
    if((GIO_HANG&TUI)==0X80) printf("\n tui");
}

void Delete_Item(uint8_t *GIO_HANG){
uint8_t DeleteItem;  
        printf("\n0.A0 1.QUAN 2.VAY 3.DAM 4.NHAN 5.VONG TAY 6.GIAY 7.TUI");
        printf("\nEnter the ID of item you want to delete: ");
        scanf("%d",&DeleteItem);
        switch (DeleteItem)
        {
        case 0:
            *GIO_HANG&=(~AO);
            break;
        case 1:
            *GIO_HANG&=(~QUAN);
            break;
        case 2:
            *GIO_HANG&=(~VAY);
            break;
        case 3:
            *GIO_HANG&=(~DAM);
            break;
        case 4:
            *GIO_HANG&=(~NHAN);
            break;
        case 5:
            *GIO_HANG&=(~VONG_TAY);
            break;
        case 6:
            *GIO_HANG&=(~GIAY);
            break;
        case 7:
            *GIO_HANG&=(~TUI);
            break;
        default:
            break;
        }

}

void Check_item(uint8_t GIO_HANG){ 
    uint8_t CheckItem;  
        printf("\n0.A0 1.QUAN 2.VAY 3.DAM 4.NHAN 5.VONG TAY 6.GIAY 7.TUI");
        printf("\nEnter the ID of item you want to check: ");
        scanf("%d",&CheckItem);
        switch (CheckItem)
        {
        case 0:
            if ((GIO_HANG&AO)==0X01) printf("\nAO: CO");
            else printf("\nAO: KHONG CO");
            break;
        case 1:
            if ((GIO_HANG&QUAN)==0X02) printf("\nQUAN: CO");
            else printf("\nQUAN: KHONG CO");
            break;
        case 2:
            if ((GIO_HANG&VAY)==0X04)  printf("\nVAY: CO");
            else printf("\nVAY: KHONG CO");
            break;
        case 3:
            if ((GIO_HANG&DAM)==0X08) printf("\nDAM: CO");
            else printf("\nDAM: KHONG CO");
            break;
        case 4:
            if ((GIO_HANG&NHAN)==0X10) printf("\nNHAN: CO");
            else printf("\nNHAN: KHONG CO");
            break;
        case 5:
            if ((GIO_HANG&VONG_TAY)==0X20) printf("\nVONG TAY: CO");
            else printf("\nVONG TAY: KHONG CO");
            break;
        case 6:
            if ((GIO_HANG&GIAY)==0X40) printf("\nGIAY: CO");
            else printf("\nGIAY: KHONG CO");
            break;
        case 7:
            if ((GIO_HANG&TUI)==0X80) printf("\nTUI: CO");
            else printf("\nTUI: KHONG CO");
            break;
        default:
            break;
        }
}


int main(int argc, char const *argv[])
{  
    Add_gio_hang(&GIO_HANG,AO|VONG_TAY|VAY);
    Check_item(GIO_HANG);
    Delete_Item(&GIO_HANG);
    ShowItem(GIO_HANG);
    return 0;
}