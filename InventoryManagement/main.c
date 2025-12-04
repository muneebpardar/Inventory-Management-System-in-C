#include <stdio.h>                 /*Group Members: Ali Asar Khowaja (2012285), Zeyaan Muhummad (2012325), Aleem Maknojia (2012284)*/
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

/*username: codecamp101
password: acmthebest*/
void takeString(char *str, int size) {
    fgets(str, size, stdin);

    // remove trailing newline correctly
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

//global structs
struct CUSTOMER{
	char name[30];
	int age;
	char phone[20];
};
struct ITEM{
	char productname[40],productcomp[40];
	int price;
	int Qnt;
};
int billgenerator();
//record funcs
int Addrecord();
int Viewrecord();
int Modifyrecord();
int Deleterecord();
int Searchrecord();
//item funcs
int Additem();
int Viewitem();
int Modifyitem();
int Deleteitem();
int Searchitem();
//Design funcs
void login();
void gotoxy(int x,int y);
void loading();
int mainmenu();
int recordMenu();
int stockMenu();
int recordsScreen();
int stockScreen();
void quit();

int main(){
	int i;

	system("COLOR 79");
	login();
	time_t t;    //showing system time
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	gotoxy(15,8);
	for(i=0;i<30;i++)
    	printf("%c",219);
    gotoxy(15,9);
    printf("%c%cInventory Managemet System%c%c",219,219,219,219);
    gotoxy(15,10);
	for(i=0;i<30;i++)
    	printf("%c",219);
    loading();
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
	mainmenu();
	return 0;
}
int mainmenu(){
	system("cls");
	int option;
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	int i;
	gotoxy(15,3);
	for(i=0;i<15;i++)
    	printf("%c",219);
    gotoxy(15,4);
    printf("%c%c Main Menu %c%c",219,219,219,219);
    gotoxy(15,5);
	for(i=0;i<15;i++)
    	printf("%c",219);
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	printf("%c",219);
    gotoxy(9,8);
    printf("%c 1 : Customer Records    %c",219,219);
    gotoxy(9,9);
    printf("%c 2 : Stock Management    %c",219,219);
    gotoxy(9,10);
    printf("%c 3 : Bill Generator      %c",219,219);
    gotoxy(9,11);
    printf("%c 4 : Quit                %c",219,219);
    gotoxy(9,12);
    printf("%c     Choose an option:   %c",219,219);
    gotoxy(9,14);
	for(i=0;i<27;i++)
    	printf("%c",219);
	gotoxy(9,13);
	printf("%c                         %c",219,219);
	gotoxy(19,13);
	scanf("%d",&option);
	switch(option)
	{
		case 1:
		{
		system("cls");
		recordsScreen();
		puts("\n\nPress any key to go back.");
		getch();
		mainmenu();
		break;
		}
	case 2:
		{
		system("cls");
		stockScreen();
		puts("\n\nPress any key to go back.");
		getch();
		mainmenu();
		break;
		}
	case 3:
		{
		system("cls");
		billgenerator();
		puts("\n\nPress any key to go back.");
		getch();
		mainmenu();
		break;
		}
	case 4:
		{
		system("cls");
		quit();
		break;
		}
		default:
		{
		printf("\nInvalid Input. Try again!");
		printf("\nPress any key to return to main menu.");
    	getch();
		mainmenu();
		return 0;
		}
	}
	return 0;

}
int recordsScreen(){
	int i;
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	gotoxy(20,8);
	for(i=0;i<20;i++)
    	printf("%c",219);
    gotoxy(20,9);
    printf("%c%cCustomer Records%c%c",219,219,219,219);
    gotoxy(20,10);
	for(i=0;i<20;i++)
    	printf("%c",219);
    loading(10000000);
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
	recordMenu();
	return 0;
}
int recordMenu(){
	system("cls");
	int option;
    time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	int i;
	gotoxy(13,3);
	for(i=0;i<20;i++)
    	printf("%c",219);
    gotoxy(13,4);
    printf("%c%cCustomer Records%c%c",219,219,219,219);
    gotoxy(13,5);
	for(i=0;i<20;i++)
    	printf("%c",219);
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	printf("%c",219);

	gotoxy(9,8);
    printf("%c 1 : Add Record.         %c",219,219);
    gotoxy(9,9);
    printf("%c 2 : View Record.        %c",219,219);
    gotoxy(9,10);
    printf("%c 3 : Search Record.      %c",219,219);
    gotoxy(9,11);
    printf("%c 4 : Modify Record.      %c",219,219);
    gotoxy(9,12);
    printf("%c 5 : Delete Record.      %c",219,219);
    gotoxy(9,13);
    printf("%c 6 : Return to main menu %c",219,219);
    gotoxy(9,14);
	printf("%c Choose an option:       %c",219,219);

	gotoxy(9,16);
	for(i=0;i<27;i++)
    	printf("%c",219);
	gotoxy(9,15);
	printf("%c                         %c",219,219);
	gotoxy(19,15);

	scanf("%d",&option);

	switch(option){
	case 1:
		{
		system("cls");
		Addrecord();
		recordMenu();
		break;
		}
	case 2:
		{
		system("cls");
		Viewrecord();
		puts("\n\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	case 3:
		{
		system("cls");
		Searchrecord();
		puts("\n\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	case 4:
		{
		system("cls");
		Modifyrecord();
		puts("\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	case 5:
		{
		system("cls");
		Deleterecord();
		puts("\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	case 6:
		{
		break;
		}
	default:
		{
		puts("\nPress any key to Exit.");
		getch();
		return 0;
		}
	}
	return 0;
}
int Addrecord(){
	int flag=0;
	struct CUSTOMER c1,temp;
    FILE *fptr,*ft;
    fptr=fopen("Customers.txt","a+");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    while (1)
    {
    	system("cls");
    	clearInput();
        printf("\nEnter Name: ");
        fflush(stdin);
        gets(c1.name);
        c1.name[0]=toupper(c1.name[0]);

        ft=fopen("Customers.txt","r");
        if(ft==NULL){
        	printf("File could not be opened!");
        	exit(1);
    	}
    	while(fread(&temp,sizeof(temp),1,ft)==1){
    		if(strcmp(c1.name,temp.name)==0){
				flag=1;
			}
		}
		fclose(ft);
		if(flag==1){
			printf("\nThis Name already exists can't add again!\nPress any key to go back");
			getch();
			break;
		}

        printf("\nEnter age: ");
        scanf("%d",&c1.age);
        clearInput();
        printf("\nEnter Phone Number: ");
        fflush(stdin);
        gets(c1.phone);
        fwrite(&c1,sizeof(c1),1,fptr);
        break;
    }
    fclose(fptr);
    return 0;
}
int Viewrecord(){
	struct CUSTOMER c1;
    FILE *fptr;
    fptr=fopen("Customers.txt","r");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    while (fread(&c1,sizeof(c1),1,fptr)==1)
    {
		printf("\n\nName: %s",c1.name);
		printf("\nAge: %d",c1.age);
		printf("\nPhone Number: %s",c1.phone);
    }
    fclose(fptr);
    return 0;
}
int Modifyrecord(){
	struct CUSTOMER c1;
	char nameMOD[20];
	int flag=0;
    FILE *fptr,*temp;
    fptr=fopen("Customers.txt","r+");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    temp=fopen("temp.txt","w+");
    if(temp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    //ask name for record modification
    clearInput();
    printf("Which record do u want to modify?\nEnter the name of the customer:");
    fflush(stdin);
    gets(nameMOD);
	nameMOD[0]=toupper(nameMOD[0]);
    while (fread(&c1,sizeof(c1),1,fptr)==1)
    {
		if(strcmp(nameMOD,c1.name)!=0){
			fwrite(&c1,sizeof(c1),1,temp);
		}
    	if(strcmp(nameMOD,c1.name)==0){
			flag=1;
			//start modification
			printf("\nEnter Name: ");
	        fflush(stdin);
	        gets(c1.name);
	        printf("\nEnter age: ");
	        scanf("%d",&c1.age);
	        clearInput();
	        printf("\nEnter Phone Number: ");
	        fflush(stdin);
	        gets(c1.phone);
	        c1.name[0]=toupper(c1.name[0]);
	        fwrite(&c1,sizeof(c1),1,temp);
			//end modification
		}
    }
    //close files before renaming and deleting
    fclose(fptr);
	fclose(temp);
    if(flag==1){
		remove("Customers.txt");
	    rename("temp.txt","Customers.txt");
	    printf("\nRecord Modified Succefully!");
    }
    else{
    	remove("temp.txt");
    	printf("\nThere is no customer with that name!");
	}
	return 0;
}
int Deleterecord(){
	struct CUSTOMER c1;
	char nameDLT[20];
	int flag=0;
    FILE *fptr,*temp;
    fptr=fopen("Customers.txt","r+");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    temp=fopen("temp.txt","w+");
    if(temp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    //ask name for record removal
    clearInput();
    printf("Which record do u want to delete?\nEnter the name of the customer:");
    fflush(stdin);
    gets(nameDLT);
	nameDLT[0]=toupper(nameDLT[0]);
    while (fread(&c1,sizeof(c1),1,fptr)==1)
    {
    	if(strcmp(nameDLT,c1.name)==0)
			flag=1;
		if(strcmp(nameDLT,c1.name)!=0){
			fwrite(&c1,sizeof(c1),1,temp);
		}
    }
    //close files before renaming and deleting
    fclose(fptr);
	fclose(temp);
    if(flag==1){
		remove("Customers.txt");
	    rename("temp.txt","Customers.txt");
	    printf("\nRecord Deleted Succefully!");
    }
    else{
    	remove("temp.txt");
    	printf("\nThere is no customer with that name!");
	}
	return 0;
}
int Searchrecord(){
	struct CUSTOMER c1;
	char nameSRCH[20];
	int flag=0;
    FILE *fptr;
    fptr=fopen("Customers.txt","r");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    clearInput();
    printf("Which record do u want to search for?\nEnter the name of the customer:");
    fflush(stdin);
    gets(nameSRCH);
	nameSRCH[0]=toupper(nameSRCH[0]);
    while (fread(&c1,sizeof(c1),1,fptr)==1)
    {
    	if(strcmp(nameSRCH,c1.name)==0){
			printf("\nName: %s",c1.name);
			printf("\nAge: %d",c1.age);
			printf("\nPhone Number: %s",c1.phone);
			flag=1;
    	}
	}
    fclose(fptr);
    if(flag==0)
	    printf("\nThere is no customer with that name!");
    return 0;
}
int stockScreen(){
	int i;
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	gotoxy(20,8);
	for(i=0;i<20;i++)
    	printf("%c",219);
    gotoxy(20,9);
    printf("%c%cStock Management%c%c",219,219,219,219);
    gotoxy(20,10);
	for(i=0;i<20;i++)
    	printf("%c",219);
    loading(10000000);
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
	stockMenu();
	return 0;
}
int stockMenu(){
	system("cls");
	int option;

	int i;
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	gotoxy(12,3);
	for(i=0;i<20;i++)
    	printf("%c",219);
    gotoxy(12,4);
    printf("%c%cStock Management%c%c",219,219,219,219);
    gotoxy(12,5);
	for(i=0;i<20;i++)
    	printf("%c",219);
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	printf("%c",219);

	gotoxy(9,8);
    printf("%c 1 : Add Products.       %c",219,219);
    gotoxy(9,9);
    printf("%c 2 : View Products.      %c",219,219);
    gotoxy(9,10);
    printf("%c 3 : Search Products.    %c",219,219);
    gotoxy(9,11);
    printf("%c 4 : Modify Products.    %c",219,219);
    gotoxy(9,12);
    printf("%c 5 : Delete Products.    %c",219,219);
    gotoxy(9,13);
    printf("%c 6 : Return to main menu %c",219,219);
    gotoxy(9,14);
	printf("%c Choose an option:       %c",219,219);

	gotoxy(9,16);
	for(i=0;i<27;i++)
    	printf("%c",219);
	gotoxy(9,15);
	printf("%c                         %c",219,219);
	gotoxy(19,15);


	scanf("%d",&option);

	switch(option){
	case 1:
		{
		system("cls");
		Additem();
		stockMenu();
		break;
		}
	case 2:
		{
		system("cls");
		Viewitem();
		puts("\n\nPress any key to go back.");
		getch();
		stockMenu();
		break;
		}
	case 3:
		{
		system("cls");
		Searchitem();
		puts("\n\nPress any key to go back.");
		getch();
		stockMenu();
		break;
		}
	case 4:
		{
		system("cls");
		Modifyitem();
		puts("\nPress any key to go back.");
		getch();
		stockMenu();
		break;
		}
	case 5:
		{
		system("cls");
		Deleteitem();
		puts("\nPress any key to go back.");
		getch();
		stockMenu();
		break;
		}
	case 6:
		{
		break;
		}
	default:
		{
		puts("\nPress any key to Exit.");
		getch();
		return 0;
		}
	}
	return 0;
}
int Additem(){
	int flag=0;
	struct ITEM it,temp;
    FILE *fp,*ft;
    fp=fopen("Items.txt","a+");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    while (1)
    {
    	system("cls");
    	clearInput();
    	printf("\nEnter Product Name: ");
        fflush(stdin);
        gets(it.productname);
        it.productname[0]=toupper(it.productname[0]);

        ft=fopen("Items.txt","r");
        if(ft==NULL){
        	printf("File could not be opened!");
        	exit(1);
    	}
    	while(fread(&temp,sizeof(temp),1,ft)==1){
    		if(strcmp(it.productname,temp.productname)==0){
				flag=1;
			}
		}
		fclose(ft);
		if(flag==1){
			printf("\nThis Product already exists can't add again!\nPress any key to go back");
			getch();
			break;
		}

        printf("\nEnter Product Company: ");
        gets(it.productcomp);
        it.productcomp[0]=toupper(it.productcomp[0]);
        printf("\nEnter Product Price: ");
        scanf("%d",&it.price);
        clearInput();
        printf("\nEnter Product Quantity: ");
        scanf("%d",&it.Qnt);
        fwrite(&it,sizeof(it),1,fp);
        break;
    }
    fclose(fp);
    return 0;
}
int Viewitem(){
	struct ITEM it;
    FILE *fp;
    fp=fopen("Items.txt","r");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    while (fread(&it,sizeof(it),1,fp)==1)
    {
		printf("\n\nProduct Name: %s", it.productname);
		printf("\nCompany Name: %s", it.productcomp);
		printf("\nProduct Price: %d", it.price);
		printf("\nProduct Quantity: %d", it.Qnt);
    }
    fclose(fp);
    return 0;
}
int Modifyitem(){
	struct ITEM it;
	char nameMOD[20];
	int flag=0;
    FILE *fp,*temp;
    fp=fopen("Items.txt","r+");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    temp=fopen("temp.txt","w+");
    if(temp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    //ask name for record modification
    clearInput();
    printf("Which record do u want to modify?\nEnter the Product Name:");
    fflush(stdin);
    gets(nameMOD);
	nameMOD[0]=toupper(nameMOD[0]);
    while (fread(&it,sizeof(it),1,fp)==1)
    {
		if(strcmp(nameMOD,it.productname)!=0){
			fwrite(&it,sizeof(it),1,temp);
		}
		if(strcmp(nameMOD,it.productname)==0){
			flag=1;
			//start modification
			printf("\nProduct Name: %s", it.productname);
			printf("\nCompany Name: %s", it.productcomp);
			printf("\nProduct Price: %d", it.price);
			printf("\nProduct Quantity: %d\n", it.Qnt);
			printf("\nEnter Product Name: ");
	        fflush(stdin);
	        gets(it.productname);
	        printf("\nEnter Company Name: ");
	        fflush(stdin);
	        gets(it.productcomp);
	        printf("\nEnter Price: ");
	        scanf("%d",&it.price);
	        printf("\nEnter Quantity: ");
	        scanf("%d",&it.Qnt);
	        it.productname[0]=toupper(it.productname[0]);
            it.productcomp[0]=toupper(it.productcomp[0]);
	        fwrite(&it,sizeof(it),1,temp);
			//end modification
		}
    }
    //close files before renaming and deleting
    fclose(fp);
	fclose(temp);
    if(flag==1){
		remove("Items.txt");
	    rename("temp.txt","Items.txt");
	    printf("\nRecord Modified Succefully!");
    }
    else{
    	remove("temp.txt");
    	printf("\nThere is no Product with that Name!");
	}
	return 0;
}
int Deleteitem(){
	struct ITEM it;
	char nameDLT[20];
	int flag=0;
    FILE *fp,*temp;
    fp=fopen("Items.txt","r+");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    temp=fopen("temp.txt","w+");
    if(temp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    //ask name for record removal
    clearInput();
    printf("Which record do u want to delete?\nEnter the Product Name:");
    fflush(stdin);
    gets(nameDLT);
	nameDLT[0]=toupper(nameDLT[0]);
    while (fread(&it,sizeof(it),1,fp)==1)
    {
    	if(strcmp(nameDLT,it.productname)==0)
			flag=1;
		if(strcmp(nameDLT,it.productname)!=0){
			fwrite(&it,sizeof(it),1,temp);
		}
    }
    //close files before renaming and deleting
    fclose(fp);
	fclose(temp);
    if(flag==1){
		remove("Items.txt");
	    rename("temp.txt","Items.txt");
	    printf("\nRecord Deleted Succefully!");
    }
    else{
    	remove("temp.txt");
    	printf("\nThere is no product with that Name!");
	}
	return 0;
}
int Searchitem(){
	struct ITEM it;
	char nameSRCH[20];
	int flag=0;
    FILE *fp;
    fp=fopen("Items.txt","r");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    clearInput();
    printf("Which record do u want to search for?\nEnter the Product Name:");
    fflush(stdin);
    gets(nameSRCH);
	nameSRCH[0]=toupper(nameSRCH[0]);
    while (fread(&it,sizeof(it),1,fp)==1)
    {
    	if(strcmp(nameSRCH,it.productname)==0){
			printf("\nProduct Name: %s", it.productname);
			printf("\nCompany Name: %s", it.productcomp);
			printf("\nProduct Price: %d", it.price);
			printf("\nProduct Quantity: %d\n", it.Qnt);
			flag=1;
    	}
	}
    fclose(fp);
    if(flag==0)
	    printf("\nThere is no Item with that name!");
    return 0;
}
int billgenerator() {
    int quantity;
    float sum = 0;
    time_t t;
    time(&t);
    printf("\n\t\t\t\t\t\t%s", ctime(&t));

    struct CUSTOMER c1;
    struct ITEM it;

    char customer[30], searchName[40];
    char option;
    int isMember = 0;

    FILE *fc = fopen("Customers.txt", "rb");
    if (!fc) {
        printf("Customers.txt could not be opened!");
        return 0;
    }

    clearInput();
    printf("Enter Customer Name: ");
    takeString(customer, 30);
    customer[0] = toupper(customer[0]);

    while (fread(&c1, sizeof(c1), 1, fc) == 1) {
        if (strcmp(customer, c1.name) == 0)
            isMember = 1;
    }
    fclose(fc);

    while (1) {

        int found = 0;      // RESET flag every loop

        FILE *fp = fopen("Items.txt", "rb");
        FILE *temp = fopen("temp.txt", "wb");

        if (!fp || !temp) {
            printf("Error opening files!\n");
            return 0;
        }

        printf("\nEnter Product Name: ");
        takeString(searchName, 40);
        searchName[0] = toupper(searchName[0]);

        while (fread(&it, sizeof(it), 1, fp) == 1) {

            if (strcmp(searchName, it.productname) == 0) {
                found = 1;

                // Quantity input loop
                while (1) {
                    printf("Enter Quantity: ");
                    scanf("%d", &quantity);
                    clearInput();

                    if (it.Qnt == 0) {
                        printf("This item is out of stock.\n");
                        break;
                    }
                    if (quantity > it.Qnt) {
                        printf("Only %d left. Try again.\n", it.Qnt);
                        continue;
                    }
                    break;
                }

                if (it.Qnt > 0) {
                    printf("\nProduct: %s  Price: PKR %d  Qty: %d\n",
                           it.productname, it.price, quantity);

                    sum += (it.price * quantity);
                    it.Qnt -= quantity;
                }

                fwrite(&it, sizeof(it), 1, temp);
            }
            else {
                fwrite(&it, sizeof(it), 1, temp);
            }
        }

        fclose(fp);
        fclose(temp);

        if (!found) {
            printf("\nProduct not found!\n");
            remove("temp.txt");
        } else {
            remove("Items.txt");
            rename("temp.txt", "Items.txt");
        }

        printf("\nAdd another item? (Y/N): ");
        scanf(" %c", &option);   // NOTICE THE SPACE BEFORE %c
        clearInput();

        if (option != 'y' && option != 'Y')
            break;
    }

    if (isMember) {
        printf("\nMembership discount 15%% applied!\n");
        sum -= sum * 0.15;
    }

    printf("\nGross Total: PKR %.2f\n", sum);
    return 0;
}

void gotoxy(int x,int y){ //function to print anything at desired position...
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void loading(){ //function for loading screen
	int i,j;
	gotoxy(25,12);
	printf("Loading....");
	gotoxy(15,14);
	for (i=0;i<30;i++)
	{
		Sleep(20);
		printf("%c",219);
	}
}

void quit(){ //function for the message to be displayed when quit

	gotoxy(25,5);
	printf("================\n");
	gotoxy(25,6);
	printf(" SYSTEM CLOSED!\n");
	gotoxy(25,7);
	printf("================\n");
}

void login(){ //function for login to the system

	char id[20];
	char p[20];
	gotoxy(40,8);
	printf("Username:");
	gotoxy(40,9);
	scanf("%s", &id);
	gotoxy(40,11);
	printf("Password:");
	gotoxy(40,12);
	char c;
	int i=0;
	while((c=getch())!='\n')
	{
		p[i]=c;
		if(c==13) break;
		else
		printf("*");
		i++;
	}
	p[i]='\0';
		if(strcmp(id,"codecamp101")==0)
		{
        	if(strcmp(p,"acmthebest")==0)
			{
				gotoxy(40,14);
				printf("Welcome Login Successful!");
				gotoxy(40,16);
				printf("Press any key to continue.");
				gotoxy(40,17);
   				getch();
				system("cls");
			}
			else
			{
				gotoxy(40,14);
				printf("Wrong password");
				Sleep(600);
				system("cls");
				login();
			}
    	}
		else
		{
			gotoxy(40,14);
			printf("User doesn't exist");
			Sleep(600);
			system("cls");
			login();
		}
}
