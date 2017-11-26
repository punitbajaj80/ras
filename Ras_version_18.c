#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<Windows.h>
#include<windows.h>
#include<time.h>
#include<math.h>
#define ANS 15
#define ACS 10

 COORD coord={0,0}; 
                   
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//Structure Declaration
//Product Sturucture
typedef struct{
char name[ANS],code[ACS];
float purchase_price;
float gst;
float sell_price;
int quantity;
int initial_quantity;
float break_even_value;
float break_even_quantity;
float profit;
int sold;
float total_profit;
}rec;
rec item,p1,p2;
//Bill Structure
typedef struct{
char cust_name[ANS],cust_code[ACS];
char mob[ANS];
char billno[ANS];
int age;
float total;
}gbill;
gbill b1;
//Retailer Structure
typedef struct{
char name[ANS],state[ANS],code[ACS],pass[ANS];
char mob[ANS];
char bus_name[170];
char gstin[ANS];
}Retailer;
Retailer ret;
/*
//gst Structure
typedef struct{
float totaligst,totalcgst,totalsgst;
float gstsum;
}gst;
gst g1;
*/
//Customer Structure
typedef struct{
char name[ANS],code[ACS],state[ANS];
char mob[ANS];
int age;
}customer;
customer cust;

//Functions are defined here
/*declaration of checking functions*/
void c_code(char[]);
int check(char[]);
void cust_code(char[]);
int check_cust(char[]);
void check_admin();

// time function
void showtime();

//function related to mainmenu
/*declaration of display functions*/
void mainmenu();
void admin();
void cust_record();
void prod_record();
 void ras();
//Retailer Function
void add_retailer();
void ret_code();
void display_retailer();
void dis_ret();
void display_ret();
void d_mainmenu();
void display(rec *,int,int); 			
void check_retailer();

//Product Function
/* menu functions for product*/
void edit();
void add();
void del();
void exit();
void dis_con();
void d_search();				// search -by- funtion for products
/*Product Search functions*/
void d_code();
void d_rate();
void d_quan();
void d_all();

// Customer record functions
//Customer Function
void dc_search(); 			
void dis_cust();		
void add_customer();
void edit_customer();
void display_customer();
void delete_customer();
void display_cust(customer *,int,int); 
//Customer display type functions
void dc_code();
void dc_mob();
void profit();
//bill function
void bill() ;
void dbill();
void display_all_bill();
// graphics function
void highlight(int,int);
void border();
void curser(int);
void window(int,int,int,int);
void display_gst();
//  product Analysis Function
void compare();
void break_even_calc();
void display_break_even(rec *,int,int);
void dispaly_menu_break_even(); 			
// function for profit anallyzer
void product_profit();
int display_product();
void display_menu_product();

// main function
int main()
{
	border();
	mainmenu();
 return 0;
}

void ras()
{
 int i=0,s=0;
    char c[7]={'W','E','L','C','O','M','E'};

  while(c[i] != '\0')
        {
			 s = i;
            while(s--)
        	printf(" ");
        	//to make R of welcome
            gotoxy(53+i,28+i); printf("%c",c[i]);//gives diagonal
            gotoxy(52+i,21); printf("%c",c[i+1]);
			gotoxy(59,21+i); printf("%c",c[i]); //right upper line of R
            gotoxy(54+i,28); printf("%c",c[i+1]); 
		    gotoxy(51,21+i); printf("%c",c[i]);
		    gotoxy(51,28+i); printf("%c",c[i]);
		    // to make A of welcome
		    gotoxy(69-i,21+i); printf("%c",c[i]);
		    gotoxy(70+i,22+i); printf("%c",c[i+1]);
		    gotoxy(63,28+i); printf("%c",c[i]);
		    gotoxy(66+i,28); printf("%c",c[i]);
		    gotoxy(75,28+i); printf("%c",c[i]);
		    // to make S of welcome
		    gotoxy(78+i,21); printf("%c",c[i]);
		    gotoxy(78,22+i); printf("%c",c[i+1]);
		    gotoxy(78+i,28); printf("%c",c[i]);
		    gotoxy(85,28+i); printf("%c",c[i]);
		    gotoxy(78+i,34); printf("%c\n\n\n",c[i-1]);
		i++;             
        }
}

void exitout()
{
	int i;
	system("cls");
	border();
	ras();
	gotoxy(8,34);printf("Exiting ");
	for(i=1;i<5;i++)
	{
		sleep(1);		printf(".");
	}
	gotoxy(8,38);
	exit(0);
}

void mainmenu()
{
 char ch;
 int i,j;
    const char *menu[]={"   Retailer","   Administrator","   Exit "};
 system("cls");
	border();	
 window(25,50,20,32);
 for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(42,18);printf("MAIN MENU");
 for (i=0;i<=2;i++){
 gotoxy(10,22+i+1);printf("%s\n\n\n",menu[i]);}
 for(i = 19; i<=35; i++)
 {
 	gotoxy(46,i); printf("%c",176);
}
ras();
 curser(20);
}

void d_mainmenu()
{
 int i;
 char ch;
 const char *menu[]={"   Calculate Bill","   Customer Records","   Product Records","   Profit Analyzer","   Display Bills","   Go to Home","   Exit"};
 system("cls");
	border();	
 window(25,50,20,32);
  for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(39,18);printf("RETAILER's MENU");
 for(i = 32; i<=66; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,31); printf("%c",176);
 }
for(i = 22; i<=30; i++)
 {
 	gotoxy(32,i); printf("%c",176);
 	gotoxy(66,i); printf("%c",176);
 }
 for (i=0;i<=6;i++){
  gotoxy(37,22+i+1);printf("%s\n\n\n",menu[i]);}
  curser(7);
 }
void cust_record()
{
 int i;
 char ch;
 const char *menu[]={"   Add Customer","   Edit Customer","  Display customer","   Delete customer ","   Search", "  Back","Exit"};
 system("cls");
 border();	
 window(25,50,20,32);
 for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(36,18);printf("CUSTOMER RECORD MENU");
 for(i = 32; i<=66; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,31); printf("%c",176);
 }
for(i = 22; i<=30; i++)
 {
 	gotoxy(32,i); printf("%c",176);
 	gotoxy(66,i); printf("%c",176);
 }
 for (i=0;i<=6;i++){
  gotoxy(37,22+i+1);printf("%s\n\n\n",menu[i]);}
  curser(8);
 }
 void prod_record()
{
 int i;
 char ch;
 const char *menu[]={"   add product","   edit Product","  display Product","   delete Product ","   Search", "  Back","Exit"};
 system("cls");
 border();	
 window(25,50,20,32);
  for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(36,18);printf("PRODUCT RECORD MENU");
  for(i = 32; i<=66; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,31); printf("%c",176);
 }
for(i = 22; i<=30; i++)
 {
 	gotoxy(32,i); printf("%c",176);
 	gotoxy(66,i); printf("%c",176);
 }
 for (i=0;i<=6;i++){
  gotoxy(37,22+i+1);printf("%s\n\n\n",menu[i]);}
  curser(9);
 }
  void profit()
{
 int i;
 char ch;
 const char *menu[]={"   Compare two Product","    Product Details","    Break Even Point", "  Go to Main Menu","Exit"};
 system("cls");
 border();	
 window(25,50,20,32);
 for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(42,18);printf("PROFIT ANALYZER");
 for(i = 32; i<=66; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,31); printf("%c",176);
 }
for(i = 22; i<=30; i++)
 {
 	gotoxy(32,i); printf("%c",176);
 	gotoxy(66,i); printf("%c",176);
 }
 for (i=0;i<=4;i++){
  gotoxy(37,22+i+1);printf("%s\n\n\n",menu[i]);}
  curser(15);
 }
   void admin()
{
 int i;
 char ch;
 const char *menu[]={"   Add Retailer","    Display Retailer","  Back","Exit"};
 system("cls");
 border();	
 window(25,50,20,32);
 for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(41,18);printf("ADMINISTRATOR");
 for(i = 32; i<=66; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,31); printf("%c",176);
 }
for(i = 22; i<=30; i++)
 {
 	gotoxy(32,i); printf("%c",176);
 	gotoxy(66,i); printf("%c",176);
 }
 for (i=0;i<=3;i++){
  gotoxy(37,22+i+1);printf("%s\n\n\n",menu[i]);}
  curser(16);
 }
void bill_dis()
{
 int i;
 char ch;
 const char *menu[]={"   Display all Bill","    Search Bill","   Go to Main Menu","Exit"};
 system("cls");
 border();	
 window(25,50,20,32);
  for(i=7;i<=88;i++)
 {
 	gotoxy(i,17);printf("%c",176);
 	gotoxy(i,19);printf("%c",176);
 }
 gotoxy(36,18);printf("DISPLAY BILL MENU");
  for(i=28;i<=70;i++)
 {
 	gotoxy(i,21);printf("%c",176);
 	gotoxy(i,30);printf("%c",176);
 }
   for(i=22;i<30;i++)
 {
 	gotoxy(28,i);printf("%c",176);
 	gotoxy(70,i);printf("%c",176);
 }
 for (i=0;i<4;i++){
  gotoxy(32,22+i+1);printf("%s\n\n\n",menu[i]);}
  curser(22);
 }
void d_search()
{
 char ch;
 int i;
    const char *menu[]={"   By Product Code","   By Sell Price","   By Quantity","   Back to main menu"};
 system("cls");
	border();	
 window(25,50,20,32);
  for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(39,18);printf("PRODUCT SEARCH MENU");
 for(i = 32; i<=66; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,31); printf("%c",176);
 }
for(i = 22; i<=30; i++)
 {
 	gotoxy(32,i); printf("%c",176);
 	gotoxy(66,i); printf("%c",176);
 }
 for (i=0;i<=3;i++){
 gotoxy(37,22+i+1);printf("%s\n\n\n",menu[i]);}
 curser(4);
}

void dc_search()
{
 char ch;
 int i;
    const char *menu[]={"   By Customer Code","   By Mobile Number","   Back to main menu","Exit "};
 system("cls");
	border();	
 window(25,50,20,32);
  for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(39,18);printf("CUSTOMER SEARCH MENU");
 for(i = 32; i<=66; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,31); printf("%c",176);
 }
for(i = 22; i<=30; i++)
 {
 	gotoxy(32,i); printf("%c",176);
 	gotoxy(66,i); printf("%c",176);
 }
 for (i=0;i<=3;i++){
 gotoxy(37,22+i+1);printf("%s\n\n\n",menu[i]);}
 curser(12);
}

/*function for cursor movement*/
void curser(int no)
{
    int count=1;
    char ch='0';
    gotoxy(30,23);
 while(1){
  switch(ch){
   case 80:   // why 80
    count++;
    if (count==no+1) count=1;
    break;
   case 72:   // why 72
    count--;
    if(count==0) count=no;
    break;
  }
  highlight(no,count);
  ch=getch();
  if(ch=='\r'){
   if(no==7){
    if (count==1) bill() ;
    else if(count==2) cust_record();
    else if (count==3) prod_record();
    else if (count==4) profit();
    else if (count==5) bill_dis();
    else if (count==6) mainmenu();
    else   exit(0);
   }
    if(no==22){
    if (count==1) display_all_bill() ;
    else if(count==2) display_bill();
   // else if(count==3) display_gst();    
    else if(count==3) d_mainmenu();
    else   exit(0);
   }
   if(no==8){
    if (count==1) add_customer() ;
    else if(count==2) edit_customer();
    else if (count==3) display_customer();
    else if (count==4) dc_search();
    else if (count==5) delete_customer();
    else if (count==6) d_mainmenu();
    else   exit(0);
   }
   if(no==9){
    if (count==1) add() ;
    else if(count==2) edit();
    else if(count==3) d_all();
    else if (count==4) d_search();
    else if (count==5) del();
    else if (count==6) d_mainmenu();
    else   exit(0);
   }
   if(no==15){
    if (count==1) compare() ;
    else if(count==2) product_profit();
    else if(count==3) break_even_calc();
    else if(count==4) d_mainmenu();
    else   exit(0);
   }
    if(no==16){
    if (count==1) add_retailer() ;
    else if(count==2) display_retailer();
    else if(count==3) mainmenu();
    else   exit(0);
   }
   if(no==4){
    if (count==1) d_code();
    else if (count==2)d_rate();
    else if (count==3) d_quan();
    else d_mainmenu();
   }
   if(no==12){
    if (count==1) dc_code();
    else if (count==2)dc_mob();
    else if (count==3)d_mainmenu();
    else exit(0);
  }
    if(no==20){
    if (count==1) check_retailer();
    else if (count==2)check_admin();
    else if(count ==3) exitout();
    else exit(0);
  }
 }
}
}
void highlight(int no,int count)
{
 if (no==12){
  //textbackground(11);
  //textcolor(0);
  gotoxy(37,23);printf("   By Customer Code      ");
  gotoxy(37,24);printf("   By Mobile Number      ");
  gotoxy(37,25);printf("   Back to Main Menu     ");
  gotoxy(37,26);printf("   Exit                  ");
  //textcolor(0);
  //textbackground(2);
  switch (count)
  {
   case 1:
    gotoxy(37,23);
    printf(" - By Customer Code   ");
    break;
   case 2:
    gotoxy(37,24);
    printf(" - By Mobile Number   ");
    break;
   case 3:
    gotoxy(37,25);
    printf(" - Back to Main Menu  ");
    break;
   case 4:
    gotoxy(37,26);
    printf(" - Exit               ");
    break;
	}
 }
	if (no==4){
  gotoxy(37,23);printf("   By Code              ");
  gotoxy(37,24);printf("   By Sell Price        ");
  gotoxy(37,25);printf("   By Quantity          ");
  gotoxy(37,26);printf("   Back to main menu    ");

  switch (count)
  {
   case 1:
    gotoxy(37,23);
    printf(" - By Code                ");
    break;
   case 2:
    gotoxy(37,24);
    printf(" - By Sell Price          ");
    break;
   case 3:
    gotoxy(37,25);
    printf(" - By Quantity            ");
    break;
   case 4:
    gotoxy(37,26);
    printf(" - Back to main menu      ");
    break;
  }
 }
   if (no==20){
  gotoxy(10,23);printf("   RETAILER             ");
  gotoxy(10,24);printf("   ADMINISTRATOR        ");
  gotoxy(10,25);printf("   Exit                 ");

  switch (count)
  {
   case 1:
    gotoxy(10,23);
    printf(" - RETAILER               ");
    break;
   case 2:
    gotoxy(10,24);
    printf(" - ADMINISTRATOR          ");
    break;
   case 3:
    gotoxy(10,25);
    printf(" - Exit                   ");
    break;
  }
 }


 if(no==7)
 {

  gotoxy (37,23);printf("   Calculate Bill         ");
  gotoxy (37,24);printf("   Customer Records       ");
  gotoxy (37,25);printf("   Product Records       ");
  gotoxy (37,26);printf("   Profit Analyzer       ");
  gotoxy (37,27);printf("   Display Bills          ");
  gotoxy (37,28);printf("   Go to Home             ");
  gotoxy (37,29);printf("   Exit                   ");

  switch(count){
   case 1:
    gotoxy (37,23);
    printf(" - Calculate Bill     ");
    break;
   case 2:
    gotoxy (37,24);
    printf(" - Customer Records   ");
    break;
   case 3:
    gotoxy (37,25);
    printf(" - Product Records   ");
    break;
    case 4:
    gotoxy (37,26);
    printf(" - Profit Analyzer    ");
    break;
   case 5:
    gotoxy (37,27);
    printf(" - Display Bills      ");
    break;
   case 6:
    gotoxy (37,28);
    printf(" - Go to Home         ");
    break;
   case 7:
    gotoxy (37,29);
    printf(" - Exit               ");
    break;
  }
 }
 if (no==22){
  gotoxy(30,23);printf("   Display All Bill          ");
  gotoxy(30,24);printf("   Search Bill        ");
 // gotoxy(30,25);printf("   Display GST        ");
  gotoxy(30,25);printf("   Go To Main Menu      ");
  gotoxy(30,26);printf("   Exit   ");

  switch (count)
  {
   case 1:
    gotoxy(30,23);
    printf(" - Display All Bill          ");
    break;
   case 2:
    gotoxy(30,24);
    printf(" - Search Bill          ");
    break;
 /*  case 3:
    gotoxy(30,25);
    printf(" - Display GST      ");
    break;	*/
       case 3:
    gotoxy(30,25);
    printf(" - Go To Main Menu      ");
    break;
   case 4:
    gotoxy(30,26);
    printf(" - Exit     ");
    break;
  }
 }
if(no==8)
 {

  gotoxy (37,23);printf("   Add Customer      ");
  gotoxy (37,24);printf("   Edit Customer     ");
  gotoxy (37,25);printf("   Display Customer  ");
  gotoxy (37,26);printf("   Search            ");
  gotoxy (37,27);printf("   Delete            ");
  gotoxy (37,28);printf("   Back              ");
  gotoxy (37,29);printf("   Exit              ");

  switch(count){
   case 1:
    gotoxy (37,23);
    printf(" - Add Customer          ");
    break;
   case 2:
    gotoxy (37,24);
    printf(" - Edit Customer         ");
    break;
   case 3:
    gotoxy (37,25);
    printf(" - Display Customer      ");
    break;
   case 4:
    gotoxy (37,26);
    printf(" - Search                ");
    break;
   case 5:
    gotoxy (37,27);
    printf(" - Delete                ");
    break;
   case 6:
    gotoxy (37,28);
    printf(" - Back                  ");
    break;
   case 7:
    gotoxy (37,29);
    printf(" - Exit                  ");
    break;
  }
 }

 if(no==9){

  gotoxy (37,23);printf("   Add Product        ");
  gotoxy (37,24);printf("   Edit Product       ");
  gotoxy (37,25);printf("   Display Product    ");
  gotoxy (37,26);printf("   Search             ");
  gotoxy (37,27);printf("   Delete             ");
  gotoxy (37,28);printf("   Back               ");
  gotoxy (37,29);printf("   Exit               ");
  //textcolor(0);
  //textbackground(2);
  switch(count){
   case 1:
    gotoxy (37,23);
    printf(" - Add Product         ");
    break;
   case 2:
    gotoxy (37,24);
    printf(" - Edit Product        ");
    break;
   case 3:
    gotoxy (37,25);
    printf(" - Display Product     ");
    break;
   case 4:
    gotoxy (37,26);
    printf(" - Search              ");
    break;
   case 5:
    gotoxy (37,27);
    printf(" - Delete              ");
    break;
   case 6:
    gotoxy (37,28);
    printf(" - Back                ");
    break;
   case 7:
    gotoxy (37,29);
    printf(" - Exit                ");
    break; 
  }
 }
if(no==15){

  gotoxy (37,23);printf("   Compare two Product   ");
  gotoxy (37,24);printf("   Product Detail        ");
  gotoxy (37,25);printf("   Break Even Calculation");  
  gotoxy (37,26);printf("   Go to Main Menu       ");
  gotoxy (37,27);printf("   Exit                   ");
  switch(count){
   case 1:
    gotoxy (37,23);
    printf(" - Compare two Product      ");
    break;
   case 2:
    gotoxy (37,24);
    printf(" - Product Detail           ");
    break;
     case 3:
    gotoxy (37,25);
    printf(" - Break Even Calculation   ");
    break;
   case 4:
    gotoxy (37,26);
    printf(" - Go to Main Menu          ");
    break;
   case 5:
    gotoxy (37,27);
    printf(" - Exit                     ");
    break; 
  }
 }
if(no==16){

  gotoxy (37,23);printf("   Add Retailer           ");
  gotoxy (37,24);printf("   Display Retailer       ");
  gotoxy (37,25);printf("   Back                   ");
  gotoxy (37,26);printf("   Exit                   ");
  switch(count){
   case 1:
    gotoxy (37,23);
    printf(" - Add Retailer       ");
    break;
   case 2:
    gotoxy (37,24);
    printf(" - Display Retailer   ");
    break;
   case 3:
    gotoxy (37,25);
  	printf(" - Back         ");
    break;
   case 4:
    gotoxy (37,26);
    printf(" - Exit               ");
    break; 
  }
 }
}

void bill()
{
	float price;
	float gstamount=0;
	float igstprice=0;
	float cgstprice=0;
	float sgstprice=0;
	char cust_name[ANS],cust_code[ACS],state[ANS];
	char mob[ANS];
	char state2[ANS];
	int age;
  char x[ACS]={0};
  char p[ACS]={0};
  char t[ACS]={0};
  char s[ANS];
  int flag=1,flag1=1,flag2=1;
  int j=29,q=0,size=0,i=1;
  float total=0,gtotal=0;
  float igst=0,cgst=0,sgst=0;
  system("cls");
  dbill();
   FILE *file3;
  file3=fopen("Retailer.txt","r+b");
  rewind(file3);
  //gotoxy(8,11);printf("enter  \"end\" to finish input");
    for(i = 7; i<=88; i++)
 {
 	gotoxy(i,11); printf("%c",176);
 }
 i=1;
  gotoxy(9,13);printf("Enter Retailer Code:");
  scanf("%s",p);
  gotoxy(9,13); printf("                                                                    ");
  
  if(strcmp(p,"end")==0)
  {
  	d_mainmenu();
   } 
  rewind(file3);
  while(fread(&ret,sizeof(ret),1,file3)){
   if((strcmp(ret.code,p)==0) && (strlen(p)<=5)){
   	gotoxy(9,21);printf("Retailer : ");
    gotoxy(21,21);printf("%9s",ret.code);
    printf("%13s",ret.name);
    printf("%14s",ret.mob);
 	printf("%13s",ret.state);
 	strcpy(state2,ret.state);
 	printf("%13s",ret.gstin);
   flag=0;
   }
    }
    if (flag!=0)
    {
 		system ("cls");
 		border();
 		gotoxy(45,17); printf("WARNING !  ");
for(i = 40; i<=56;)
 {	
 	gotoxy(i,19); printf("*+");		i+=2;
 }
    	gotoxy(41,28);printf("Enter Valid Code");
    	gotoxy(39,29);printf("Contact Administrator");
    	getche();
			d_mainmenu();
		}
	
   FILE *file1;
  file1=fopen("Customer_Records.txt","r+b");
  rewind(file1);
  gotoxy(9,13);printf("Enter Customer Code / Mobile Number : ");
  scanf("%s",t);
  gotoxy(9,13); printf("                                                                    ");
  if(strcmp(t,"end")==0)
  {
  	d_mainmenu();
   } 
  rewind(file1);
  while(fread(&cust,sizeof(cust),1,file1)){
   if((strcmp(cust.code,t)==0) || (strcmp(cust.mob,t)==0)){
   	gotoxy(9,22);printf("Customer : ");
    gotoxy(21,22);printf("%9s",cust.code);
    printf("%13s",cust.name);
    printf("%14s",cust.mob);
 	printf("%14d",cust.age);
 	printf("%13s",cust.state);
	strcpy(cust_name,cust.name);
  	strcpy(cust_code,cust.code);
  	strcpy(mob,cust.mob);
  	age=cust.age;
  	strcpy(state,cust.state);
 	flag1=0;
 	}
	}
    if (flag1!=0)
    {
    	system ("cls");
 		border();
 		gotoxy(45,17); printf("WARNING !  ");
for(i = 40; i<=56;)
 {	
 	gotoxy(i,19); printf("*+");		i+=2;
 }
    	gotoxy(41,30);printf("Enter Valid Code");
       	gotoxy(32,28);printf("No Customer is available with this Code");
       	gotoxy(48,31);printf("OR");
    	gotoxy(38,32);printf("Add a new Customer(Y/N)");
    	gotoxy(48,33);
    	if(toupper(getche())=='Y')
    	{
    		sleep(3);
    		add_customer();
		}
		else
		{			sleep(3);
					d_mainmenu();
		}
	}
  FILE *file;
  
  file=fopen("record.txt","r+b");
  rewind(file);
  while(1){

  gotoxy(9,13);printf("Enter Item Name / Code :              ");
  scanf("%s",x);
  gotoxy(9,13); printf("                                                                    ");
  if(strcmp(x,"end")==0)
   break;
  gotoxy(9,13);printf("Enter Quantity :                      ");
  scanf("%d",&q);
  rewind(file);
  while(fread(&item,sizeof(item),1,file))
  { 
   if((strcmp(item.code,x)==0) || (strcmp(item.name,x)==0))
   {
   	flag2=0;
    total=item.sell_price*q;
    price=item.sell_price-(item.sell_price*item.gst/(100+item.gst));
	gstamount=item.gst*price/100;
	if(strcmp(state,state2)==0)
 	{
  	cgst=item.gst/2;
  	sgst=item.gst/2;
  	cgstprice=gstamount/2;
  	sgstprice=gstamount/2;
	}
	else
	{
		
		igstprice=gstamount;	
		igst=item.gst;
	}	
    if(item.quantity<=0 || item.quantity<q)
    {
    	gotoxy(9,34);printf("There are only %d %s item(s) left in the stock",item.quantity,item.name);
	}
	else
	{
	gotoxy(8,j);printf("%2d",i);
	printf("%9s",item.name);
    printf("%12.2f",price);
 	printf("%8.2f[%.f%%]",igstprice,igst);   
    printf("%4.2f[%.f%%]",cgstprice,cgst);
    printf("%4.2f[%.f%%]",sgstprice,sgst);
    printf("%12.2f",item.sell_price);
    printf("%6d",q);
	printf("%10.2f",total);
    gtotal=gtotal+total;
    size=sizeof(item);
    item.quantity=item.quantity-q;
	item.sold=item.sold+q;
	item.break_even_value=item.sell_price*item.sold-item.purchase_price*item.initial_quantity;
	item.break_even_quantity=floor(item.break_even_value/item.sell_price);
	item.total_profit=item.total_profit+item.profit*q;
    j+=2; i++;
    fseek(file,-size,SEEK_CUR);fwrite(&item,sizeof(item),1,file);
	/*FILE *file8;
  	file8=fopen("gst_record.txt","ab");
  	rewind(file8);
    size=sizeof(g1);
  	g1.totaligst=g1.totaligst+igstprice;
  	g1.totalcgst=g1.totalcgst+cgstprice;
  	g1.totalsgst=g1.totalsgst+sgstprice;
  	fseek(file8,-size,SEEK_CUR);fwrite(&g1,sizeof(g1),1,file8);
  	fclose(file8);*/
    break;
   }
     }
    
    }
	
 }
 fclose(file);
 if(gtotal!=0){
 	 system("cls");
 	 border();
 	  gotoxy(20,10);
 for (i=1;i<=10;i++)
  printf("*");
 printf(" Retail Automation System ");
 for (i=1;i<=10;i++)
        printf("*");
 printf("\n\n");
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	sprintf(s,"B%d/%d/%d/%s",str_t.wYear,str_t.wMonth,str_t.wDay,cust_code);
	gotoxy(30,16);printf("Bill Number : %s",s);
  gotoxy(22,20);printf("Name 	: %s",cust_name); 
  gotoxy(44,20);printf("Mobile	: %s",mob);
  gotoxy(22,24);printf("Age 	: %d",age);
  gotoxy(44,24);printf("State  	: %s",state);
  gotoxy(32,27);showtime();
  gotoxy(30,29);
  printf("TOTAL AMOUNT = MRs. %6.2f",gtotal);
  
   FILE *file;
  file=fopen("bill_record.txt","ab");
  b1.total=gtotal;
	sprintf(b1.billno,"B%d/%d/%d/%s",str_t.wYear,str_t.wMonth,str_t.wDay,cust_code);
  strcpy(b1.cust_name,cust_name);
  strcpy(b1.cust_code,cust_code);
  strcpy(b1.mob,mob);
  b1.age=age;
  fseek(file,0,SEEK_END);fwrite(&b1,sizeof(b1),1,file);
  fclose(file);
  fclose(file1);
  fclose(file3);
 }
 
 getch();
 d_mainmenu();
}
 /*function to display bill window*/
void dbill()
{
 int i;
 border();
 gotoxy(20,10);
 for (i=1;i<=10;i++)
  printf("*");
 printf(" Retail Automation System ");
 for (i=1;i<=10;i++)
        printf("*");
 printf("\n\n");
  for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(39,18);printf("CUSTOMER'S BILL") ;
 for(i = 7; i<=88; i++)
 {
 	gotoxy(i,24); printf("%c",176);
 }
 gotoxy(8,26);printf("SN.   Item     Price   		GST(included)      	Price   Quant.    Total");
 gotoxy(1,27);printf("				    IGST    CGST     SGST          ");

}
/*function to add item records*/
void add ()
{
 FILE *file;
 char y[ACS],x[12];
 system("cls");
 border();
 gotoxy(29,25);printf("Enter new Product(Y/N)?");
 while(toupper(getche())=='Y'){
  system("cls");
  border();
  file=fopen("record.txt","ab");
  c_code(y);
  strcpy(item.code,y);
  gotoxy(29,26);printf("Enter name of the item:");
  scanf("%s",item.name);
  gotoxy(29,27);printf("Enter Purchase Price of the item:");
  scanf("%f",&item.purchase_price);
  gotoxy(29,28);printf("Enter GST of the item:");
  scanf("%f",&item.gst);
  gotoxy(29,29);printf("Enter Selling Price of the item:");
  scanf("%f",&item.sell_price);
  gotoxy(29,30);printf("Enter quantity of the item:");
  scanf("%d",&item.quantity);
  item.initial_quantity=item.quantity;
  item.profit=item.sell_price-item.purchase_price;
  item.sold=0;
  item.total_profit=0;
  	item.break_even_value=item.sell_price*item.sold-item.purchase_price*item.initial_quantity;
  	item.break_even_quantity=floor(item.break_even_value/item.sell_price);
  fseek(file,0,SEEK_END);fwrite(&item,sizeof(item),1,file);
  fclose(file);
  gotoxy(29,32);printf("Enter new Product(Y/N)?");
   }
   d_mainmenu();
}

 /*function to check availability of code*/
void c_code(char y[])
{
 int flag,i;
 FILE *file;
 file=fopen("record.txt","rb");
 while(1){
  system("cls");
  border();
  window(20,58,23,36);
    for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
  gotoxy(42,18);printf(" ADD PRODUCT ")  ;
  flag=1;
  rewind(file);
   for(i = 26; i<=70; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,34); printf("%c",176);
 }
for(i = 22; i<=34; i++)
 {
 	gotoxy(26,i); printf("%c",176);
 	gotoxy(70,i); printf("%c",176);
 }
  gotoxy(29,23);printf("Enter new code of the Product:");
  scanf(" %[^\n]",y);
  while(fread(&item,sizeof(item),1,file)==1){
  	border();
   if (strcmp(y,item.code)==0){
    flag=0;
    gotoxy(29,25);printf("Code already exists");
    gotoxy(29,26);printf("enter again");
	gotoxy(29,27);printf("Enter Y to Update any Record ");
	gotoxy(40,28);printf("OR ");
	gotoxy(29,29);printf("ADd new Record");
 	if(toupper(getche())=='Y')
    {
    	edit();
	}
	else
	{
		add();
	}
	
	break;
   }
  }
  if (flag==1)
  break;
 }
}
// function to add customer 
void add_customer()
{
 
 FILE *file1;
 char y[ACS],x[12];
 system("cls");
 int i;
 border();
 gotoxy(32,22);printf("Enter new Customer(Y/N)?  ");
 sleep(2);
 while(toupper(getche())=='Y'){
  system("cls");
  border();
  file1=fopen("Customer_Records.txt","ab");
  cust_code(y);
  strcpy(cust.code,y);
  gotoxy(29,28);printf("Enter Customer's Name:  ");
  scanf("%s",cust.name);
  gotoxy(29,29);printf("Enter mobile number     ");
  scanf("%s",cust.mob);
  gotoxy(29,30);printf("Enter Customer's Age:   ");
  scanf("%d",&cust.age);
  gotoxy(29,31);printf("Enter Customer's state: ");
  scanf("%s",cust.state);
  fseek(file1,0,SEEK_END);fwrite(&cust,sizeof(cust),1,file1);
  fclose(file1);
  gotoxy(29,32);printf("Enter new record(Y/N)?  ");

   }
   d_mainmenu();
}
 /*function to check availability of code*/
void cust_code(char y[])
{
 int flag;
 int i;
 FILE *file1;
 file1=fopen("Customer_records.txt","rb");
 while(1){
  system("cls");
  border();	
  window(20,58,23,36);
  for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
  gotoxy(42,18);printf(" ADD CUSTOMER ")  ;
  flag=1;
  rewind(file1);
    for(i = 26; i<=70; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,34); printf("%c",176);
 }
for(i = 22; i<=34; i++)
 {
 	gotoxy(26,i); printf("%c",176);
 	gotoxy(70,i); printf("%c",176);
 }
  
  gotoxy(29,26);printf("Enter Customer ID:  ");
  scanf(" %[^\n]",y);
  while(fread(&cust,sizeof(cust),1,file1)==1){
   if (strcmp(y,cust.code)==0){
    flag=0;
    gotoxy(29,30);printf("Customer ID already exists");
    gotoxy(29,32);printf("enter again  ");getch();
    break;
   }
  }
  if (flag==1)
  break;
 }
}

/*function for editing product records*/
void edit()
{
 int flag=0,choice;
 char x[ACS],y[ACS];
 FILE *file;
 int size,i;
 system("cls");
 border();
 window(20,63,20,46);
   for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(37,18);printf("EDIT PRODUCT RECORDS");
 for(i = 26; i<=70; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,34); printf("%c",176);
 }
for(i = 22; i<=34; i++)
 {
 	gotoxy(26,i); printf("%c",176);
 	gotoxy(70,i); printf("%c",176);
 }
 gotoxy(29,23);printf("enter item code: ");
 scanf("%s",x);
 flag=check(x);
 if(flag==0){
  file=fopen("record.txt","r+b");
  rewind(file);
  while (fread(&item,sizeof (item),1,file)){
   if(strcmp(item.code,x)==0){
   	border();
    gotoxy(29,24);printf("name       = %s",item.name);
    gotoxy(29,25);printf("code       = %s",item.code);
    gotoxy(29,26);printf("Purchase Price       = %g",item.purchase_price);
    gotoxy(29,27);printf("Gst %       = %g",item.gst);
    gotoxy(29,28);printf("Sell Price      = %g",item.sell_price);
    gotoxy(29,29);printf("quantity   = %d",item.quantity);
    gotoxy(29,32); printf("Edit this record(y/n):");
    fflush(file);
    if(toupper(getche())=='Y'){
     border();
     gotoxy(29,24); printf("1- edit name ");
     gotoxy(29,25); printf("2- edit code ");
     gotoxy(29,26); printf("3- edit Purchase Price ");
     gotoxy(29,27); printf("4- edit GST ");
     gotoxy(29,28); printf("5- edit Sell Price ");
     gotoxy(29,29); printf("6- edit quantity ");
     gotoxy(29,32);printf(" enter your choice(1, 2, 3, 4, 5, 6) ");
     scanf("%d",&choice);
     if(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6)
     {
     	switch(choice){
      case 1:
       system("cls");
       border();
       window(23,48,20,40);
       gotoxy(37,18);printf("Edit Product Details");
       gotoxy(9,24); printf(" enter new name: ");
       scanf("%s",item.name);
       size=sizeof(item);
       fseek(file,-size,SEEK_CUR);fwrite(&item,sizeof(item),1,file);
       break;
      case 2:
       system("cls");
       border();
       window(23,65,20,40);
       gotoxy(37,18);printf("Edit Product Detail");
       gotoxy(9,24);printf("Edit code ");
       c_code(y);                                                      //////// might be a cause of an error
       strcpy(item.code,y);
       size=sizeof(item);
       fseek(file,-size,SEEK_CUR);fwrite(&item,sizeof(item),1,file);
       break;
      case 3:
       system("cls");
       border();
       window(23,65,20,40);
       gotoxy(37,18);printf("Edit Product Details");
       gotoxy(9,24);
       printf(" enter new Purchase Price: ");
       scanf("%f",&item.purchase_price);
       size=sizeof(item);
       fseek(file,-size,SEEK_CUR);fwrite(&item,sizeof(item),1,file);
       break;
    
       case 4:
       system("cls");
       border();
       window(23,65,20,40);
       gotoxy(37,18);printf("Edit Product Detail");
       gotoxy(9,24);
       printf(" enter new Gst %: ");
       scanf("%f",&item.gst);
       size=sizeof(item);
       fseek(file,-size,SEEK_CUR);fwrite(&item,sizeof(item),1,file);
       break;
	   case 5:
       system("cls");
       border();
       window(23,65,20,40);
       gotoxy(37,18);printf("Edit Product Detail");
       gotoxy(9,24);
       printf(" enter new Sell Price: ");
       scanf("%f",&item.sell_price);
       size=sizeof(item);
       fseek(file,-size,SEEK_CUR);fwrite(&item,sizeof(item),1,file);
       break;
    	case 6:
       system("cls");
       border();
       window(23,65,20,40);
       gotoxy(37,18);printf("EDIT Product Detail");
       gotoxy(9,24);
       printf(" enter new quantity: ");
       scanf("%d",&item.quantity);
       size=sizeof(item);
       fseek(file,-size,SEEK_CUR);fwrite(&item,sizeof(item),1,file);
       break;   
	 }
	 }

	else
	 {
	 	gotoxy(27,33);printf("Enter valid choice ");
	 	edit();
	  }
     border();
     gotoxy(40,30);printf("--- item edited---");
     break;
    }
   }
  }
 }
 if (flag==1){
 	border();
  gotoxy(32,26);printf("item does not exist");
  gotoxy(36,27);printf("TRY AGAIN(Y/N)");
  scanf("%c",y);
  if(toupper(getche())=='Y')
  {
  	edit();
  }
  else
  {
  	prod_record();
   } 
   }
 getch();
 fclose(file);
 d_mainmenu();
}

/* function to edit customer records */
void edit_customer()
{
	 int flag=0,choice,i;
 char x[ACS],y[ACS];
 FILE *file1;
 int size;
 system("cls");
 border();
 window(20,63,20,46);
  for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(37,18);printf("EDIT CUSTOMER RECORDS");
for(i = 26; i<=70; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,34); printf("%c",176);
 }
for(i = 22; i<=34; i++)
 {
 	gotoxy(26,i); printf("%c",176);
 	gotoxy(70,i); printf("%c",176);
 } 
 gotoxy(29,23);printf("Enter Customer Code:   ");
 scanf("%s",x);
 flag=check_cust(x);
 if(flag==0){
  file1=fopen("Customer_Records.txt","r+b");
  rewind(file1);
  while (fread(&cust,sizeof (cust),1,file1)){
   if(strcmp(cust.code,x)==0){
   	border();   
    gotoxy(29,24);printf("name       = %s",cust.name);
    gotoxy(29,25);printf("code       = %s",cust.code);
    gotoxy(29,26);printf("mobile     = %s",cust.mob);
    gotoxy(29,27);printf("age        = %d",cust.age);
    gotoxy(29,30); printf("Edit this Customer Record(Y/n):  ");
    fflush(file1);
    if(toupper(getche())=='Y'){
		system("cls");
     border();
     for(i = 26; i<=70; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,34); printf("%c",176);
 }
for(i = 22; i<=34; i++)
 {
 	gotoxy(26,i); printf("%c",176);
 	gotoxy(70,i); printf("%c",176);
 }
     gotoxy(29,24); printf("1- edit name ");
     gotoxy(29,25); printf("2- edit code ");
     gotoxy(29,26); printf("3- edit mob ");
     gotoxy(29,27); printf("4- edit age ");
     gotoxy(29,30);printf(" enter your choice (1, 2, 3, 4)  ");
     scanf("%d",&choice);
     switch(choice){
      case 1:
       system("cls");
       border();
       window(23,48,20,40);
       gotoxy(39,18);printf("Edit Customer Detail");
       gotoxy(9,24); printf("enter new name: ");
       scanf("%s",cust.name);
       size=sizeof(cust);
       fseek(file1,-size,SEEK_CUR);fwrite(&cust,sizeof(cust),1,file1);
       break;
      case 2:
       system("cls");
       border();
       window(23,65,20,40);
       gotoxy(39,18);printf("Edit Customer Detail");
       gotoxy(9,24);printf("enter new cust_code:  ");
       strcpy(cust.code,y);
       size=sizeof(cust);
       fseek(file1,-size,SEEK_CUR);fwrite(&cust,sizeof(cust),1,file1);
       break;
      case 3:
       system("cls");
       border();
       window(23,65,20,40);
       gotoxy(39,18);printf("Edit Customer Detail");
       gotoxy(9,24);
       printf("enter new mobile no:  ");
       scanf("%s",cust.mob);
       size=sizeof(cust);
       fseek(file1,-size,SEEK_CUR);fwrite(&cust,sizeof(cust),1,file1);
       break;
      case 4:
       system("cls");
       border();
       window(23,65,20,40);
       gotoxy(39,18);printf("Edit Customer Detail");
       gotoxy(9,24);
       printf("enter new age: ");
       scanf("%d",&cust.age);
       size=sizeof(cust);
       fseek(file1,-size,SEEK_CUR);fwrite(&cust,sizeof(cust),1,file1);
       break;
     }
     border();
     gotoxy(9,30);printf("--- Customer record edited---");
     break;
    }
   }
  }
 }
 if (flag==1){
 	border();
  gotoxy(32,30);printf("Customer not found !! ");
  gotoxy(36,32);printf("Press Y to TRY AGAIN");
  gotoxy(36,33);printf(".....");
  scanf("%c",y);
  if(toupper(getche())=='Y')
  {
  	edit_customer();
  }
  else{
  	
  	cust_record();
  }
 }
 getch();
 fclose(file1);
 d_mainmenu();

}

// function to display all customer records
void display_customer()
{
 int i,j=1;
 FILE *file1;
 dis_cust();
 file1=fopen("Customer_Records.txt","rb");
 rewind(file1);
 i=26;
 fflush(file1);
 while(fread(&cust,sizeof(cust),1,file1)){
  display_cust(&cust,i,j);
  i++;
  j++;
  if ((j%11)==0){
  	border();
         gotoxy(9,34);printf("press any key to see more ....");
         getch();
         system("cls");
         dis_cust();
         i=26;
         continue;
  }
  }
  getch();
  if (i==26) {
  	border();
  gotoxy(9,33); printf("-- no data found --");
 }
 getch();
 fclose(file1);
 d_mainmenu();
}

/*function to display all product records*/
void d_all()
{
 int i,j=1;
 FILE *file;
 dis_con();
 file=fopen("record.txt","rb");
 rewind(file);
 i=26;
 fflush(file);
 while(fread(&item,sizeof(item),1,file)){
  display(&item,i,j);
  i++;
  j++;
  if ((j%11)==0){
  	border();
         gotoxy(9,34);printf("press any key to see more ....");
         getch();
         system("cls");
         dis_con();
         i=26;
         continue;
  }
  }
  getch();
  if (i==26) {
  	border();
  	gotoxy(9,34);printf("                                                     ");
  gotoxy(9,34); printf("-- Products Not found --");
 }
 getch();
 fclose(file);
 d_mainmenu();
}

/*function to display by quantity*/
void d_quan()
{
  int i,j=1;
  int a,b;
  FILE *file;
  dis_con();
  file=fopen("record.txt","rb");
  rewind(file);
  i=26;
  border();
  gotoxy(9,12);;printf("enter lower range: ");
  scanf("%d",&a);
  gotoxy(9,13);printf("enter upper range:");
  scanf("%d",&b);
  fflush(file);
  while(fread(&item,sizeof(item),1,file)){
  if((item.quantity>=a)&&(item.quantity<=b)){
   display(&item,i,j);
   i++;
   j++;
   if ((j%11)==0){
   	border();
   	gotoxy(9,34);printf("                                                                    ");
    gotoxy(9,34);printf("press any key to see more...........");
    getch();
    system("cls");
    dis_con();
    i=26;
    continue;
   }
     }
  }
  border();
  getch();
  if (i==26){
  	border();
  gotoxy(28,30); printf(" no item found ");
 }
 getch();
 d_search();
 fclose(file);
}

// function to display customer by customer id
void dc_code()
{
  int i,j=1;
  char x[4]={0};
  FILE *file1;
  dis_cust();
  file1=fopen("Customer_Records.txt","rb");
  rewind(file1);
  i=26;
  border();
  gotoxy(16,20);;printf("enter Customer code: ");
  scanf("%s",x);
  fflush(file1);
  while(fread(&cust,sizeof(cust),1,file1)){
  if((strcmp(cust.code,x)==0)){
   display_cust(&cust,i,j);
   i++;
   j++;
   break;
  }
  }
  if (i==26){
  	border();
  gotoxy(28,30); printf("no data found !!");
  }
  getch();
  fclose(file1);
  dc_search();
}

/*function to display by rate*/
void d_rate(){
  int i,j=1;
  float a,b;
  FILE *file;
  dis_con();
  file=fopen("record.txt","rb");
  rewind(file);
  i=26;
  border();
  gotoxy(9,12);;printf("enter lower range: ");
  scanf("%f",&a);
  gotoxy(9,13);printf("enter upper range: ");
  scanf("%f",&b);
  fflush(file);
  while(fread(&item,sizeof(item),1,file)){
  if((item.sell_price>=a)&&(item.sell_price<=b)){
   display(&item,i,j);
   i++;
   j++;
   if ((j%11)==0){
   	border();
   	gotoxy(9,34);printf("                                                      ");
    gotoxy(9,34);printf("press any key to see more...........");
    getch();
    system("cls");
    dis_con();
    i=26;
    continue;
   }
  }
  }
  border();
 getch();
 if (i==26){
 	border();
  gotoxy(28,30); printf(" no item found ");
 }
 getch();
 fclose(file);
 d_search();
}



//function to display custoer by mobile no
void dc_mob()
{
  int i,j=1;
  char a[ANS];
  int b;
  FILE *file1;
  dis_cust();
  file1=fopen("Customer_Records.txt","rb");
  rewind(file1);
  i=26;
  border();
  gotoxy(16,20);;printf("enter mobile no :  ");
  scanf("%s",a);
  fflush(file1);
  while(fread(&cust,sizeof(cust),1,file1)){
  if((strcmp(cust.mob,a)==0))
  {
   display_cust(&cust,i,j);
   i++;
   j++;
   if ((j%11)==0){
   	border();
    gotoxy(27,47);printf("press any key to see more...........");
    getch();
    system("cls");
    dis_cust();
    i=26;
    continue;
   }
  }
  }
  border();
 getch();
 if (i==26){
 	border();
  gotoxy(28,30); printf(" no data found !!");
 }
 getch();
 fclose(file1);
 dc_search();
}
/*function to display by code*/
void d_code()
{
  int i,j=1;
  char x[4]={0};
  FILE *file;
  dis_con();
  file=fopen("record.txt","rb");
  rewind(file);
  i=26;
  border();
  gotoxy(16,20);;printf("enter item code: ");
  scanf("%s",x);
  fflush(file);
  while(fread(&item,sizeof(item),1,file)){
  if((strcmp(item.code,x)==0)){
   display(&item,i,j);
   i++;
   j++;
   break;
  }
  }
  if (i==26){
  	border();
  gotoxy(28,30); printf("no item found");
  }
  getch();
  fclose(file);
  d_search();
}

/*function to display window for item display*/
void dis_con()
{
 int i;
 system("cls");
 border();
 gotoxy(32,10);
 ;
 for (i=1;i<=10;i++)
  printf("*");
 printf(" * Products * ");
 for (i=1;i<=10;i++)
        printf("*");
 printf("\n\n");
 for(i=7; i<=88;i++)
  {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,23); printf("%c",176);
 }
 gotoxy(42,18);printf("RECORDS") ;
gotoxy(8,22);printf ("SN   Item Name   Item Code     Purchase Price	GST    	Sell Price	Quantity");
}
//fumction to display window for customer
void dis_cust()
{
 int i;
 system("cls");
 border();
 gotoxy(30,13);
 for (i=1;i<=10;i++)
  printf("*");
 printf(" * Customer * ");
 for (i=1;i<=10;i++)
        printf("*");
 printf("\n\n");
   for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(42,18);printf("Customer Data") ;
    for(i = 7; i<=88; i++)
 {
 	gotoxy(i,22); printf("%c",176);
 	gotoxy(i,24); printf("%c",176);
 } 
 gotoxy(18,23);printf ("SN   Customer Name   Customer Id     Mobile     Age		State");
}
/*function to display in screen*/
void display(rec *item,int i,int j)
{
 gotoxy(7,i);//textcolor(13);
 printf("%3d",j);
 printf("%9s",item->name);
 printf("%12s",item->code);
 printf("%14.2f",item->purchase_price);
 printf("%14.2f",item->gst);
 printf("%14.2f",item->sell_price);
 printf("%14d",item->quantity);
}
/*function to display in screen*/
void display_cust(customer *cust,int i,int j)
{
	border();
 gotoxy(16,i);
 printf("%4d",j);
 printf("%9s",cust->name);
 printf("%12s",cust->code);
 printf("%20s",cust->mob);
 printf("%11d",cust->age);
 printf("%9s",cust->state);
}

/*function to delete records*/
void del()
{
 int flag,i;
 char x[ANS],y;
 FILE *file,*file2;
 system("cls");
 border();
 window(23,51,25,34);
     for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(42,18);printf("DELETE PRODUCT");
  for(i = 25; i<=70; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,34); printf("%c",176);
 }
for(i = 22; i<=34; i++)
 {
 	gotoxy(25,i); printf("%c",176);
 	gotoxy(70,i); printf("%c",176);
 }
 gotoxy(27,27);printf("enter item code: ");
 scanf("%s",x);
 flag=check(x);
 if(flag==0){
  file2=fopen("record1.txt","ab");
  file=fopen("record.txt","rb");
  rewind(file);
  while (fread(&item,sizeof (item),1,file)){
   if(strcmp(item.code,x)!=0)
    fwrite(&item,sizeof(item),1,file2);
  }
  gotoxy(27,29);printf("---item deleted---");
  remove("record.txt");
  rename("record1.txt","record.txt");
 }
 if (flag==1){
  gotoxy(27,30);printf("---item does not exist---");
  gotoxy(27,31);printf("TRY AGAIN (Y/n) ");
  scanf("%c",&y);
  if(toupper(getche())=='Y')
  {
  	del();
	}  else prod_record();
 }
 fclose(file2);
 fclose(file);
 getch();
 d_mainmenu();
}

// function to delete customer records
void delete_customer()
{
 int flag,i;
 char x[ANS],y;
 FILE *file1,*file3;
 system("cls");
 border();
 window(23,51,25,34);
    for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
 gotoxy(42,18);printf("DELETE CUSTOMER");
 for(i = 25; i<=70; i++)
 {
 	gotoxy(i,21); printf("%c",176);
 	gotoxy(i,34); printf("%c",176);
 }
for(i = 22; i<=34; i++)
 {
 	gotoxy(25,i); printf("%c",176);
 	gotoxy(70,i); printf("%c",176);
 }
 gotoxy(27,27);printf("enter customer code: ");
 scanf("%s",x);
 flag=check(x);
 if(flag==0){
  file3=fopen("Customer_Records1.txt","ab");
  file1=fopen("Customer_Records.txt","rb");
  rewind(file1);
  while (fread(&cust,sizeof (cust),1,file1)){
   if(strcmp(cust.code,x)!=0)
    fwrite(&cust,sizeof(cust),1,file3);
  }
  gotoxy(27,29);printf("---customer deleted---");
  remove("Customer_Records.txt");
  rename("Customer_Records1.txt","Customer_records.txt");
 }
 if (flag==1){
  gotoxy(27,30);printf("---Customer does not exist---");
  gotoxy(27,31);printf("TRY AGAIN (Y/n)  ");
  scanf("%c",&y);
  if(toupper(getche())=='Y')
  {
  	delete_customer();
	}  else cust_record();
 }
 fclose(file1);
 fclose(file3);
 getch();
 d_mainmenu();
}

/*function to check validity of code while editing and deleting*/
int check(char x[ANS])
{
 FILE *file;
 int flag=1;
 file=fopen("record.txt","rb");
 rewind(file);
 while (fread(&item,sizeof (item),1,file)){
  if(strcmp(item.code,x)==0){
   flag=0;
   break;
  }
 }
 fclose(file);
 return flag;
 }
 
 /*function to check validity of code while editing and deleting Customer Record*/
int check_cust(char x[ANS])
{
 FILE *file1;
 int flag=1;
 file1=fopen("Customer_records.txt","rb");
 rewind(file1);
 while (fread(&cust,sizeof(cust),1,file1)){
  if(strcmp(cust.code,x)==0){
   flag=0;
   break;
  }
 }
 fclose(file1);
 return flag;
 }
// function to check profitable product
void compare()
{
	 border();
 window(20,63,20,46);//eNTeries for p1
	gotoxy(12,20);  printf("Enter name of the product:");
	gotoxy(12,21);  scanf("%s",p1.name);
	gotoxy(12,22);  printf("Enter Purchase Price of Product:");
	gotoxy(12,23);  scanf("%f",&p1.purchase_price);
 	gotoxy(12,24);  printf("Enter GST Rate of Product:");
 	gotoxy(12,25);  scanf("%f",&p1.gst);
	gotoxy(12,26);  printf("Enter Selling Price of Product:");
 	gotoxy(12,27); scanf("%f",&p1.sell_price);
	gotoxy(12,28);  printf("Enter quantity sold of Product:");
	gotoxy(12,29);  scanf("%d",&p1.quantity);
p1.profit=(p1.sell_price-p1.purchase_price)*p1.quantity;
	gotoxy(12,30); 	printf("profit in p1 is %f",p1.profit);
	// ENTRIES FOR p2
	
	
	gotoxy(50,20);  printf("Enter name of Product:");
	gotoxy(50,21);  scanf("%s",p2.name);
	gotoxy(50,22);  printf("Enter Purchase Price of Product:");
	gotoxy(50,23);  scanf("%f",&p2.purchase_price);
	gotoxy(50,24);  printf("Enter GST Rate of Product:");
	gotoxy(50,25);  scanf("%f",&p2.gst);
	gotoxy(50,26);  printf("Enter Selling Price of Product:");
	gotoxy(50,27);  scanf("%f",&p2.sell_price);
 	gotoxy(50,28); printf("Enter quantity of Product:");
	gotoxy(50,29);  scanf("%d",&p2.quantity);
	p2.profit=p2.quantity*(p2.sell_price-p2.purchase_price);
	gotoxy(50,30);	printf("profit in p2 is %f",p2.profit);
	if(p1.profit>p2.profit)
	{	
		gotoxy(18,35);	printf("Product(%s) is Profitable with %f amount",p1.name,p1.profit-p2.profit);
	}
	else
	{
		gotoxy(18,35);	printf("Product(%s) is Profitable with %f amount",p2.name,p2.profit-p1.profit);
	}
	getch();
	d_mainmenu();
}

/*function to display all product records*/
void product_profit()
{
 int i,j=1;
 FILE *file;
 
 display_menu_product();
 file=fopen("record.txt","rb");
 rewind(file);
 i=26;
 fflush(file);
 while(fread(&item,sizeof(item),1,file)){
  display_product(&item,i,j);
  i++;
  j++;
  if ((j%10)==0){
  	window(23,51,25,34);
	border();
	gotoxy(9,34);/*textcolor(0)*/;printf("                                                                                ");
         gotoxy(9,34);/*textcolor(0)*/;printf("press any key to see more...........");
         getch();
         system("cls");
         display_menu_product();
         i=26;
         continue;
  }
  }
  getch();
  if (i==26) {
  	border();
  gotoxy(24,30); printf("-- Products Not found --");
 }
 getch();
 fclose(file);
 d_mainmenu();
}

void display_menu_product()
{

 int i;
 system("cls");
// window(23,51,25,34);
for (i=1;i<=10;i++)
  printf("*");
 printf(" Retail Automation System ");
 for (i=1;i<=10;i++)
    printf("*");
	border();
 gotoxy(20,10);
 gotoxy(40,17);printf("PRODUCT PROFIT");
 for(i=7;i<=88;i++)
 {
 	gotoxy(i,21);printf("%c",176);
 	gotoxy(i,25);printf("%c",176);
 }
 gotoxy(8,23);printf ("SN   Item Name   Item Code     	ProfitPerItem	ItemSold	Total Profit");
}


/*function to display in screen*/
int display_product(rec *item,int i,int j)
{
 gotoxy(7,i);
 printf("%3d",j);
 printf("%9s",item->name);
 printf("%12s",item->code);
 printf("%14.2f",item->profit);
 printf("%14d",item->sold);
 printf("%20.2f",item->total_profit);
}
void window(int a,int b,int c,int d)
{
 int i;
 int x;
	gotoxy(70,10); showtime();
 system("cls");
 gotoxy(25,9);
 for (i=1;i<=10;i++)
  printf("*");
 printf(" Retail Automation System ");
 for (i=1;i<=10;i++)
    printf("*");
 printf("\n\n");
 gotoxy(22,11);printf("Developed By : ");
 gotoxy(22,12);printf("  \tPrashant Malik");
 gotoxy(22,13);printf("  \tPunit Bajaj");
 gotoxy(22,14);printf("  \tSuchit K Garg");
 gotoxy(22,15);printf("  \tRajat Kumar");
 border();
}

void showtime()
{
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    printf("%s", c_time_string);
    
}
void border()
{
	int i;
	 for(i = 5; i<=90; i++)
 {
 	gotoxy(i,8); printf("%c",176);
 	gotoxy(i,36); printf("%c",176);
 }
 for(i = 8; i<=35; i++)
 {
 	gotoxy(5,i); printf("%c",176);
 	gotoxy(6,i); printf("%c",176);
 	gotoxy(89,i); printf("%c",176);
 	gotoxy(90,i); printf("%c",176);
 }
}

/*function to display all product records*/
int display_bill()
{
 int i,j=1;
 char a[ANS];
 FILE *file;
 display_menu_bill();
 file=fopen("bill_record.txt","rb");
 rewind(file);
 i=25;
 fflush(file);
 gotoxy(10,14);;printf("Enter mobile no/billno/code:  ");
  scanf("%s",a);
  fflush(file);
  while(fread(&b1,sizeof(b1),1,file)){
  if((strcmp(b1.mob,a)==0) || (strcmp(b1.billno,a)==0) || (strcmp(b1.cust_code,a)==0))
  {
   display_bill_item(&b1,i,j);
   i++;
   j++;
   if ((j%10)==0){
   	border();
   	gotoxy(9,34);printf("                                                   ");
    gotoxy(9,34);printf("press any key to see more ....");
    getch();
    system("cls");
    display_menu_bill();
    i=26;
    continue;
   }
  }
  }
  border();
 getch();
 if (i==26){
 	border();
 	gotoxy(9,34);printf("                                                      ");
    gotoxy(9,34); printf(" no data found !!");
 }
 getch();
 d_mainmenu();

}
int display_menu_bill()
{

 int i;
 system("cls");
// window(23,51,25,34);
	border();
 gotoxy(30,10);
 ;
 for (i=1;i<=10;i++)
  printf("*");
 printf(" * Bills * ");
 for (i=1;i<=10;i++)
        printf("*");
 printf("\n\n");
  for(i=7;i<=88;i++)
 {
 	gotoxy(i,21);printf("%c",176);
 	gotoxy(i,25);printf("%c",176);
 }
  gotoxy(9,23);printf ("SN   Billno	 	CustName	Code  	Mob		Age 	 total	");
}


int display_bill_item(gbill *b1,int i,int j)
{
 gotoxy(7,i);
 printf("%3d",j);
 printf("%15s",b1->billno);
 printf("%16s",b1->cust_name);
 printf("%8s",b1->cust_code);
 printf("%16s",b1->mob);
 printf("%8d",b1->age);
 printf("%14.2f",b1->total);
}
void add_retailer()
{
 
 FILE *file1;
 char y[ACS],x[12];
 system("cls");
 
 border();
 gotoxy(25,20);
  system("cls");
   border();
  system("cls");
  border();
  file1=fopen("Retailer.txt","ab");
  ret_code(y);
  strcpy(ret.code,y);
  gotoxy(34,27);printf("Enter GSTIN No:     ");
  scanf("%s",ret.gstin);
  gotoxy(34,28);printf("Enter Retailer Name:");
  scanf("%s",ret.name);
  gotoxy(34,29);printf("Create Password:    ");
  scanf("%s",ret.pass);
  gotoxy(34,30);printf("Enter mobile number:");
  scanf("%s",ret.mob);
   gotoxy(34,31);printf("Enter state:       ");
  scanf("%s",ret.state);
  fseek(file1,0,SEEK_END);fwrite(&ret,sizeof(ret),1,file1);
  fclose(file1);
  gotoxy(34,32);printf("Retailer Added      ");
  sleep(3);
  admin();
}
 /*function to check availability of code*/
void ret_code(char y[])
{
 int flag;
 FILE *file1;
 int i,j;
 file1=fopen("Retailer.txt","rb");
 while(1){
  system("cls");
  border();	
  window(20,58,23,36);
  for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
  gotoxy(38,18);printf(" ADD RETAILER PAGE ") ;
  flag=1;
  rewind(file1);
  gotoxy(13,21);printf("*+*+*+*+*+*+*+*+  Welcome to Retail Automation System  +*+*+*+*+*+*+*+*");
   for(i = 30; i<=66; i++)
 {
 	gotoxy(i,23); printf("%c",176);
 	gotoxy(i,34); printf("%c",176);
 }
 for(j=23;j<=34;j++)
 {
 	gotoxy(30,j); printf("%c",176);
 	gotoxy(66,j); printf("%c",176);
 }
  gotoxy(34,25);printf("Enter Retailer ID :  ");
  scanf("%s",y);
  	if(strlen(y)>5)
   {
   	    gotoxy(34,28);printf(" Invalid Entry ");
   	    gotoxy(34,30);printf(" Only 5 Characters are allowed");
   	    gotoxy(34,32);printf(" Going Back ");
   	    sleep(1);   	    gotoxy(48,32);printf(".");
   	    sleep(1);			gotoxy(49,32);printf(".");
    	sleep(1);   	    gotoxy(50,32);printf(".");
   	    sleep(1);			gotoxy(51,32);printf(".");
   	    sleep(1);
    admin();
   }
//  ******************************************************** to hide password while typing *********************
 // scanf(" %[^\n]",y);

  while(fread(&ret,sizeof(ret),1,file1)==1){
   if (strcmp(y,ret.code)==0){
    flag=0;
    system("cls");
    printf(" ");
    border();	
  window(20,58,23,36);
    gotoxy(34,28);printf(" Retalier Already exists");
    gotoxy(34,29);printf(" Use new Id");
    getch();
	mainmenu();
	break;
   }
  }
  if (flag==1)
  break;
 }
}
// function to display all Retailer records
void display_retailer()
{
 int i,j=1;
 FILE *file1;
 dis_ret();
 file1=fopen("Retailer.txt","rb");
 rewind(file1);
 i=26;
 fflush(file1);
 while(fread(&ret,sizeof(ret),1,file1)){
  display_ret(&ret,i,j);
  i++;
  j++;
  if ((j%11)==0){
  	border();
         gotoxy(9,21);printf("Press any key to see more !");
         getch();
         system("cls");
         dis_ret();
         i=26;
         continue;
  }
  }
  gotoxy(9,21);printf("Press any key to go back !");
  getch();
  if (i==26) {
  	border();
  //gotoxy(65,21); printf("-- no more data found --");
 }
 getch();
 fclose(file1);
 admin();
}
//fumction to display window for customer
void dis_ret()
{
 int i;
 system("cls");
 
 border();
   for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 } 
 gotoxy(37,18);printf("RETAILER DETAILS") ;
    for(i = 7; i<=88; i++)
 {
 	gotoxy(i,22); printf("%c",176);
 	gotoxy(i,24); printf("%c",176);
 } 
 gotoxy(12,23);printf ("SN    Ret. ID   	RetailerName  	  GSTIN       	Mobile           State");
}
void display_ret(Retailer *ret,int i,int j)
{
	border();
 gotoxy(9,i);
 printf("%4d",j);
 printf("%8s",ret->code);
 printf("%18s",ret->name);
 printf("%18s",ret->gstin);
 printf("%14s",ret->mob);
 printf("%13s",ret->state);
}


void break_even_calc()
{
 int i,j=1;
 FILE *file;
 
 display_menu_break_even();
 file=fopen("record.txt","rb");
 rewind(file);
 i=26;
 fflush(file);
 while(fread(&item,sizeof(item),1,file)){
  display_break_even(&item,i,j);
  i++;
  j++;
  if ((j%11)==0){
  	
	border();
	gotoxy(9,34);printf("                                                                 ");
         gotoxy(9,34);printf("press any key to see more...........");
         getch();
         system("cls");
         display_menu_break_even();
         i=26;
         continue;
  }
  }
  getch();
  if (i==26) {
  	border();
  	gotoxy(9,34);printf("                                                                ");
  gotoxy(9,34); printf("-- Products Not found --");
 }
 getch();
 fclose(file);
 d_mainmenu();
}
int display_menu_break_even()
{

 int i;
 system("cls");
 window(23,51,25,34);
	border();
 gotoxy(20,10);
 ;
 for (i=1;i<=10;i++)
  printf("*");
 printf(" * Products Break Even Calculation* ");
 for (i=1;i<=10;i++)
        printf("*");
 printf("\n\n");
  for(i=7;i<=88;i++)
 {
 	gotoxy(i,21);printf("%c",176);
 	gotoxy(i,25);printf("%c",176);
 }
  gotoxy(8,23);printf ("SN   Item Name   Item Code 	Intitial    ItemSold    BEQuantity 	BEPrice");
}


/*function to display in screen*/
void display_break_even(rec *item,int i,int j)
{
 gotoxy(7,i);
 printf("%3d",j);
 printf("%9s",item->name);
 printf("%14s",item->code);
 printf("%12d",item->initial_quantity);
 printf("%12d",item->sold);
 if(item->break_even_quantity>=0)
 {
 printf("        Reached ");
 }
 else
 {
 printf("%14.lf",item->break_even_quantity);
 }
 printf("%15.2f",item->break_even_value);
}

void check_retailer()
{
 char y[ANS];
 int i,j;
 char z[ANS];
 int flag;
 FILE *file1;
 file1=fopen("Retailer.txt","rb");
 while(1){
  system("cls");
  border();	
  window(20,58,23,36);
  for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
  gotoxy(39,18);printf(" RETAILER LOGIN ")  ;
  flag=1;

  rewind(file1);
  gotoxy(13,21);printf("*+*+*+*+*+*+*+*+  Welcome to Retail Automation System  +*+*+*+*+*+*+*+*");
   for(i = 30; i<=66; i++)
 {
 	gotoxy(i,23); printf("%c",176);
 	gotoxy(i,33); printf("%c",176);
 }
 for(j=23;j<=32;j++)
 {
 	gotoxy(30,j); printf("%c",176);
 	gotoxy(66,j); printf("%c",176);
 }
  gotoxy(34,25);printf("Enter Retailer ID :  ");
  scanf("%s",y);
//  ******************************************************** to hide password while typing *********************
   HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    //*******************************************************************
  gotoxy(34,26);printf("Enter Password :     ");
  scanf(" %s",z);
  while(fread(&ret,sizeof(ret),1,file1)==1){
   if ((strcmp(y,ret.code)==0)&& (strcmp(z,ret.pass)==0)){
    
    system("cls");
    printf(" ");
    border();	
  window(20,58,23,36);
   for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,20); printf("%c",176);
 }
    gotoxy(42,18);printf(" WELCOME ");
    gotoxy(25,19);printf("+*+*+*+* You've Successfully logged in *+*+*+*+");
    gotoxy(31,25);printf("Hello   %s",ret.name);
    gotoxy(31,28);printf("Please Press ENTER to proceed : ");
    getch();
	d_mainmenu();
	flag=0;
}
}
    if (flag!=0)
    {
    	gotoxy(34,28);printf("==========  OOPs!  ==========");
    	gotoxy(34,30);printf("ID OR Password is Wrong");
    	gotoxy(34,31);printf("Contact Administrater ;( ");
    	getch();
    	mainmenu();
	
   }
 }
}
/*
void display_gst()
{
	 int i;
 system("cls");
 window(23,51,25,34);
	border();
 gotoxy(20,10);
 ;
 for (i=1;i<=10;i++)
  printf("*");
 printf(" * Total Gst* ");
 for (i=1;i<=10;i++)
        printf("*");
 printf("\n\n");
  gotoxy(20,23);printf (" total igst");
  gotoxy(20,25);printf (" total igst");
  gotoxy(20,27);printf (" total igst");
	gotoxy(20,29);printf (" total SUM ");	
	FILE *file5;
	file5=fopen("gst_record.txt","rb");
    rewind(file5);
    gotoxy(40,23);printf("%f",g1.totaligst);
    gotoxy(40,25);printf("%f",g1.totalcgst);
	gotoxy(40,27);printf("%f",g1.totalsgst);
	g1.gstsum=g1.totalcgst+g1.totaligst+g1.totalsgst;
	gotoxy(40,29);printf("%f",g1.gstsum);	
	fclose(file5);
	 getch();
 admin();
}
*/

void display_all_bill()
{
 int i,j=1;
 char a[ANS];
 FILE *file;
 display_menu_bill();
 file=fopen("bill_record.txt","rb");
 rewind(file);
 i=25;
 fflush(file);
 while(fread(&b1,sizeof(b1),1,file)){
 	
  display_bill_item(&b1,i,j);
  i++;
  j++;
  if ((j%11)==0){
  	getch();
	  window(23,51,25,34);
	border();
		 gotoxy(9,34);printf("                                                                   ");	
         gotoxy(9,34);printf("press any key to see more...........");
         getch();
         system("cls");
         display_menu_bill();
         i=26;
         continue;
  }

  }
  getch();
  if (i==26) {
  	border();
  	gotoxy(9,34);printf("                                                                    ");
  gotoxy(9,34); printf("-- Products Not found --");
 }
 getch();
 fclose(file);
 d_mainmenu();
}
void check_admin()
{
 char y[ANS];
 char z[ANS];
 int i,flag,j;
  system("cls");
  border();	
  window(20,58,23,36);
   for(i = 7; i<=88; i++)
 {
 	gotoxy(i,17); printf("%c",176);
 	gotoxy(i,19); printf("%c",176);
 }
  gotoxy(39,18);printf(" ADMIN LOGIN ")  ;
  flag=1;
  gotoxy(13,21);printf("*+*+*+*+*+*+*+*+  Welcome to Retail Automation System  +*+*+*+*+*+*+*+*");
   for(i = 30; i<=66; i++)
 {
 	gotoxy(i,23); printf("%c",176);
 	gotoxy(i,33); printf("%c",176);
 }
 for(j=23;j<=32;j++)
 {
 	gotoxy(30,j); printf("%c",176);
 	gotoxy(66,j); printf("%c",176);
 }
  gotoxy(34,25);printf("Enter Admin id :  ");
  scanf("%s",y);
  //  ******************************************************** to hide password while typing *********************
   HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    //*******************************************************************
  gotoxy(34,26);printf("Enter Password :  ");
  scanf(" %s",z);
   if ((strcmp(y,"k")==0)&& (strcmp(z,"k")==0)){
    
	admin();
	}
	else
    {
        	gotoxy(34,28);printf("==========  OOPs!  ==========");
    	gotoxy(34,30);printf("ID OR Password is Wrong");
    	gotoxy(34,31);printf(" ");
    	getch();
    	mainmenu();
	   }
 }
 


