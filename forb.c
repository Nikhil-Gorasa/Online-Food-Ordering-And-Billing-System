#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int number,size,opt,noitems,cart=0,catopt,flag=0,qty,fopt,cc=0;//cc = Cart Count
float grandTotal,total=0; 
char str[50],tempstr[100],personame[50];
char option;
const char* filenames[] = {"appetizers.txt","soups&salads.txt","main_courses.txt","Pasta&Rice.txt","breads.txt","desserts.txt","beverages.txt"};

const int numfiles = sizeof(filenames) / sizeof(filenames[0]);
char catn[10][100]= {"APPETIZERS","SOUPS AND SALADS","MAIN COURSES","PASTA AND RICE DISHES","BREADS","DESSERTS","BEVERAGES"};
//color codes
void red() {printf("\033[1;31m");};
void green() {printf("\033[0;32m");};
void blue() {printf("\033[0;34m");};
void yellow() {printf("\033[1;33m");};
void purple() {printf("\033[1;35m");};
void cyan() {printf("\033[1;36m");};
void reset() {printf("\033[0m");};
//functions
void openmenu(int num);
void explore();
void order();
void start();
void checkout();
void scanoption();
//bill functions
void generateBillHeader(char a[50]);
void generateBillBody(char item[30],int qty, float price);
void generateBillFooter(float total);

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct{
    char name[50];
    int qty,fopt;
    float price;
} CART;

MenuItem menu[100];
CART c[100];
FILE *menufile;
FILE *receipt;

void main(){
    purple();
if(flag==0){flag=1;start();}

while(1)
    {if(cart>0){strcpy(str,"ORDER MORE");}
        else {strcpy(str,"ORDER NOW");}
    purple();
    printf("\n1. EXPLORE MENU\n2. %s\n3. OPEN CART & CHECKOUT\n4. EXIT PORTAL\nYOUR CHOICE : ",str);
    scanf("%d",&opt);
    switch(opt){
        case 1:explore();break;
        case 2:if(flag==2){order();break;}
                else red();printf("Please check out our MENU before ordering \n");
                main();
        case 3:checkout();break;        
        case 4:green();printf("THANKYOU FOR VISITING THINNAVARA ONLINE PORTAL ");reset();exit(1);
        default:red();printf("Invalid option ! Try Again\n");reset();

                }
    }

}

void checkout(){
    system("cls");
if(cart>0){ 
green();    
    generateBillHeader(personame);
        for(int i=0;i<cart;i++){
            generateBillBody(c[i].name,c[i].qty,c[i].price);
        }
    generateBillFooter(total);
red();
printf("Enter 'y' to confirm your order or Enter any key to order more items!\n");
fgetc(stdin);
scanf("%c",&option);
if(option=='y'||option=='Y'){
    yellow();
    printf("Pay %.2f/- for %d items from THINNAVARA RESTAURANT ?\n",grandTotal,cart);
    printf("Press any key to complete the payment \n");
    getch();
    printf("Processing payment ... \n");Sleep(2000);
    red();printf("Thankyou for ordering from THINNAVARA RESTAURANT \nHAVE A NICE DAY !\n");reset();exit(1);
}
else{system("cls");reset();main();}
}
else{red();printf("THERE ARE CURRENTLY NO ITEMS IN YOUR CART !\n");}
}


void openmenu(int num){
    int k=1;k++;
    if(k%2==1){yellow();}
    else{blue();}
    flag=2;
    menufile = fopen(filenames[num], "r");

    char line[100];
    int i = 0;
    size=0;
    while (fgets(line, sizeof(line), menufile) != NULL) {
        char *name = strtok(line, ",");
        char *priceStr = strtok(NULL, ",");
        float price = atof(priceStr);
        strcpy(menu[i].name, name);
        menu[i].price = price;
        i++;size++;
    }
    fclose(menufile);
    for (int i = 0; i < size; i++) {
        printf("%2d. %-20s - Rs. %6.2f\n", i + 1, menu[i].name, menu[i].price);

    }
    printf("\n");
}

void explore(){
    cyan();
    system("cls");
    printf("WE HAVE %d CATEGORIES AVAILABLE\n",numfiles);
    printf("1. APPETIZERS\n2. SOUPS AND SALADS\n3. MAIN COURSE\n4. PASTA AND RICE DISHES\n5. BREADS\n6. DESSERTS\n7. BEVERAGES\n8. BACK\nYOUR CHOICE : ");
    scanf("%d",&catopt);
    switch(catopt){
        case 1: printf("--------------%s-------------\n",catn[0]);openmenu(0);
        break;
        case 2: printf("-----------%s----------\n",catn[1]);openmenu(1);
        break;
        case 3: printf("-------------%s------------\n",catn[2]);openmenu(2);
        break;
        case 4: printf("--------%s--------\n",catn[3]);openmenu(3);
        break;
        case 5: printf("-----------------%s--------------\n",catn[4]);openmenu(4);
        break;
        case 6: printf("---------------%s--------------\n",catn[5]);openmenu(5);
        break;
        case 7: printf("--------------%s--------------\n",catn[6]);openmenu(6);
        break;
        case 8: system("cls");main();
        break;
        default: red();printf("INVALID CHOICE");explore();reset();
    }
    reset();
}

void start(){
    red();
    printf("WELCOME TO THINNAVARA RESTAURANT ONLINE PORTAL\n");
    printf("Press any key to light up the kitchen !\n");
    if(getch()=='@'){yellow();printf("WELCOME ADMIN ! \n");
    printf("Press any key to Check out all the receipts ! \n");
    getch();
    
    if(receipt==NULL){printf("NO RECEIPTS FOUND !\n");}
    else{
          receipt=fopen("receipt.txt","r");
        printf("\n---------------RECEIPTS----------------\n");
        while (fgets(tempstr, sizeof(tempstr), receipt)) { // read file line by line
        printf("%s", tempstr); // print the line to the console
         }
         fclose(receipt);
    }
    exit(1);}red();
    printf("Please Enter Your Name : ");gets(personame);
    system("cls");
    printf("Welcome %s !\n",personame);
    reset();
}

void order(){
    purple();
    int j;
printf("How many Items are you ordering ?\n");
scanf("%d",&noitems);
cart+=noitems;
    for(int i=0;i<noitems && cc<cart;i++,cc++){
        purple();
    scanoption();
        j = (fopt-1);
        printf("Enter quantity : ");
        scanf("%d",&qty);
            //ADDING THE ITEMS TO THE CART//
            c[cc].fopt=fopt;
            strcpy(c[cc].name,menu[j].name);
            c[cc].qty=qty;
            c[cc].price=menu[j].price;
            //COMPLETED ADDING INTO THE CART
        green();printf("\"%s\" of QTY:%d with ID:%d has been added to your cart!\n",c[cc].name,c[cc].qty,c[cc].fopt);
        total+=(c[cc].price*c[cc].qty); //calculating total cost
        cyan();printf("NUMBER OF ITEMS IN YOUR CART : %d\tCART VALUE : %f\n",cc+1,total);
    }
    reset();
}

void scanoption(){
            printf("Enter item ID : ");
            scanf("%d",&fopt);
    if(fopt<=0 || fopt>size){
        red();printf("INVALID OPTION\n");scanoption();
    }purple();
}
//functions to generate biils
void generateBillHeader(char personame[50]) {
    time_t t = time(NULL);
    printf("\n\n");
    printf("       THINNAVARA Restaurant");
    printf("\n\t -----------------");
    printf("\nDate: %s", ctime(&t));
    printf("Name: %s", personame);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items[%d]",cart);
    printf("%-11s %-6s %-8s\n","", "Qty", "  Total");
    printf("---------------------------------------\n");
}

void generateBillBody(char item[30], int qty, float price) {
    printf("%-20s %-6d Rs. %.2f\n", item, qty, qty * price);
}

void generateBillFooter(float total) {
    printf("\n");
    float dis = 0.2 * total;
    float netTotal = total - dis;
    float cgst = 0.07 * netTotal;
    float sgst = 0.05 * netTotal;
    grandTotal = netTotal + cgst + sgst;

    printf("---------------------------------------\n");
    printf("%-26s  Rs. %.2f\n", "Sub Total", total);
    printf("%-26s  Rs. %.2f\n", "Discount @20%", dis);
    printf("\t\t\t    ----------\n");
    printf("%-26s  Rs. %.2f\n", "Net Total", netTotal);
    printf("%-26s  Rs. %.2f\n", "CGST @7%", cgst);
    printf("%-26s  Rs. %.2f\n", "SGST @5%", sgst);
    printf("---------------------------------------\n");
    printf("%-26s  Rs. %.2f\n", "Grand Total", grandTotal);
    printf("---------------------------------------\n");
}