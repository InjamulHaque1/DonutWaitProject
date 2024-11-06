/*
We have mentioned all the function prototypes below.
You will find the specific work done in that function prototype commented out next to it.
We have called all the arguments by reference.
There will be 2 text files that will be generated with user information

                            1.daily_userInfo.txt
                            2.total_userInfo.txt
Manager ID = 123
Manager PASS = 123

Make sure to change the font of NOTEPAD to "consolas Regular" to view the text file in correct format.

*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// Structure Section------
struct userInfo
{
    char uname[50];
    int regid;
    char pass[10], cPass[10];

} m[300], n[300];

struct scoreCard
{
    struct userInfo uinfo[50];
    int score;
} sc[50];

struct category
{
    char cname[100];
    char f1[50];
    char f2[50];
    char f3[50];
    char f4[50];
    char f5[50];

    int p1, p2, p3, p4, p5;

} o[500];

// Global Variable Section------
char ch;
int i, j, k;
int customerOrManager, choice;
int Manager_id = 123, Manager_pass = 123;
int tot = 0, ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0, ct5 = 0, ct = 1;
int height = 20, width = 40, gameOver = 0;
int x, y, fruitX, fruitY, score = 0, flag, tailX[100], tailY[100];
int countTail = 0;

// Function Prototype Section------
void signup();   //Information taken from user and stored in text file.
void login();    //Uses signup information to login.
void Manager();  //Admin panel interface.
void category(); //Shows food cuisine and menus.
void bill(int *a, int *b, int *c, int *d, int *e, int *tot, int *ch); //calculate and prints total bill from chosen food items and stores them in a text file.
void snake(); //main function of the snake game.
void Print(); //game instruction.
void gotoxy(int x, int y); //used for positioning loading screen items.
void load();  //loading screen animation.
void setup(); //Generates random fruit position by using rand funtion;
void draw();  //Used to build the border,snake body, snake head, fruit.
void input(); //Used to define keyboard keys to move around in the game using kbhit funtion.
void makeLogic(); //Main login of the snake game.
void freeDrink(int *a); //uses game score to allocate a free drink to the user.
void dataTransfer();    //uses file copying method to transfer data from 1 file to another.
void dailyUserInfo();   //Used to store daily user info in daily_userInfo.txt.
void totalUserInfo();   //Used to store total user info in total_userInfo.txt.
void clearFile(); //Clears daily_userInfo.txt file after copying all the data to total_userInfo.txt.

// Main Function---------
int main()
{
    int tot = 0, ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0, ct5 = 0,score=0;
    system("cls");
    system("color 0F");

    char c[50] = "\t\t\t\t\tWaiting is not boring anymore... ";
    int n, l;
    l = strlen(c);
    printf("\n\n\n\n\n\n\n");
    printf("\n\t\t\t  \033[0;37m --------------------------------------------------------\n");
    printf("\n\t\t\t  \033[0;36m                        Donut Wait                       \n");
    printf("\n\t\t\t  \033[0;37m --------------------------------------------------------\n");
    printf("\n\n");

    for (i = 0; i < l; i++)
    {

        printf("\033[0;36m%c", c[i]);
        for (j = 1; j <= 50000000; j++)
        {
            //first animation
        }
    }

    system("cls");

    printf("\n\n\n\n\n");
    system("color 7");
    printf("\n\t\t\t  \033[0;36m*----------------------            -----------------------*\n");
    printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =               \033[0;37m1. User Signup     \033[0;36m         =");
    printf("\n\t\t\t        =               \033[0;37m2. User Login         \033[0;36m      =");
    printf("\n\t\t\t        =               \033[0;37m3. Admin Login        \033[0;36m      =");
    printf("\n\t\t\t        =               \033[0;37m4. Exit                \033[0;36m     =");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\t\t\t \033[0;36m*----------------------            -----------------------*\n");
    printf("\n\n\t\t\t\t\t\033[0;37mEnter any key to continue.....      ");

    getch();
    printf("\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    if (n == 1)
    {
        signup();
    }
    else if (n == 2)
    {
        login();
    }
    else if (n == 3)
    {
        Manager();
    }
    else if (n == 4)
    {
        exit(0);
    }
    else
    {
        printf("\n\tInput Wrong Id or Password Press enter and try again.\n\n");
        getch();
        main();
    }
}

void signup()
{
    char pass[20], cpass[20];
    time_t t;
    time(&t);

    system("cls");
    printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =               \033[0;37mWelcome to signup           \033[0;36m=");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        \033[0;37m1. Name                : ");
    fflush(stdin);
    gets(m[0].uname);

    printf("\n\t\t\t        2. User ID             : ");
    scanf("%d", &m[0].regid);

    printf("\n\t\t\t        3. Password            : ");
    scanf("%s",pass);

    printf("\n\t\t\t        4. Confirm Password    : ");
    scanf("%s",cpass);

    FILE *file;
    file = fopen("daily_userInfo.txt", "a");

    printf("\n--------------------------------------------------------------------------\n");
    while (1)
    {
        if (strcmp(pass, cpass) != 0)
        {
            printf("\n\tPress enter and try again....");
            getch();
            signup();
            break;
        }
        else
        {
            strcpy(m[0].pass, pass);
            fprintf(file, "\n\nUser number: %d\n", ct++);

            fprintf(file, "\n--------------------------------------------------\n");
            fprintf(file, "Login time>> %s", ctime(&t));
            fprintf(file, "--------------------------------------------------\n\n");

            fprintf(file, "Name      : %s\nUser. ID  : %d\nPassword  : %s\n", m[0].uname, m[0].regid, m[0].pass);
            fclose(file);
            login();
            break;
        }
    }
}
void login()
{
    int lc;

    system("cls");
    printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =              \033[0;37mPlease Login here            \033[0;36m=");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        ----O-----------------O------------------O---");

    printf("\n\t\t\t        \033[0;37m1. Enter your User ID : ");
    scanf("%d", &n[0].regid);
    printf("\n\t\t\t        2. Enter your password: ");
    scanf("%s", &n[0].pass);

    while (1)
    {
        if ((m[0].regid != n[0].regid) || strcmp(m[0].pass, n[0].pass) != 0)
        {
lg:
            printf("\n\tTry again or want to sign up?\n\n\tPress 1 to signup and 2 to login: ");
            scanf("%d", &lc);
            if (lc == 1)
            {
                signup();
                break;
            }
            else if (lc == 2)
            {
                login();
                break;
            }
            else
            {
                printf("\n\tPress enter and try again....\n");
                getch();
                goto lg;
            }
        }
        else
        {
            category();
            break;
        }
    }
}

void Manager()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t\t1. Enter Manager Id               : ");
    scanf("%d", &Manager_id);
    printf("\n\t\t\t\t\t2. Enter Manager Password         : ");
    scanf("%d", &Manager_pass);
    if (Manager_id == 123 && Manager_pass == 123)
    {
x1:
        system("cls");
        printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=--=-=-\033[0;37mAdmin Panel\033[0;36m-=-=-=-=-=--=-=-=-=-=");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =                                                     =");
        printf("\n\t\t\t        =             \033[0;37m1.Today's bill history            \033[0;36m      =");
        printf("\n\t\t\t        =             \033[0;37m2.Entire bill history          \033[0;36m         =");
        printf("\n\t\t\t        =             \033[0;37m3.Save today's bill history and exit   \033[0;36m =");
        printf("\n\t\t\t        =             \033[0;37m4.Return to main menu       \033[0;36m            =");
        printf("\n\t\t\t        =                                                     =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\n\t\t\t   \033[0;37m      Please enter your choice: ");

        scanf("%d", &choice);
        system("cls");

        if (choice == 1)
        {

        int x;
            dailyUserInfo();
            printf("\n\t\t\t\tPress enter to clear screen");
            getch();
            system("cls");
            x2:
            printf("\n\t\t\t\tPress 1 to go back ");
            printf("\n\t\t\t\tPress 2 to exit ");
            printf("\n\n\t\t\t\tEnter your choice : ");
            scanf("%d",&x);
            if(x==1)
            {
                goto x1;
            }
            else if(x==2)
            {
                exit(0);
            }
            else
            {
                printf("\n\t\t\t\tEnter a valid choice!");
                goto x2;
            }


        }
        if(choice == 2)
        {

                    int y;
            totalUserInfo();
            printf("\n\t\t\t\tPress enter to clear screen");
            getch();
            system("cls");
            y2:
            printf("\n\t\t\t\tPress 1 to go back ");
            printf("\n\t\t\t\tPress 2 to exit ");
            printf("\n\n\t\t\t\tEnter your choice : ");
            scanf("%d",&y);
            if(y==1)
            {
                goto x1;
            }
            else if(y==2)
            {
                exit(0);
            }
            else
            {
                printf("\n\t\t\t\tEnter a valid choice!");
                goto y2;
            }
        }
        if (choice == 3)
        {
            dataTransfer();
            gotoxy(52, 11);
            system("color B");
            printf("Saving data...\n");
            gotoxy(49, 13);

            for (int r = 1; r <= 20; r++)
            {
                for (int q = 0; q <= 100000000; q++)
                {
                }
                printf("%c", 178);
            }
            gotoxy(48, 15);
            printf("Data transfer complete\n\n\t\t\t\t\t\tPress any key to exit...");
            getch();

            clearFile();
            exit(0);
        }
        else if(choice==4)
        {
            main();

        }
        else if(choice < 1 || choice > 4)
        {
            printf("\n\n\t\t\t\t\tWrong Key Pressed try again : ");
            getch();
            Manager();
        }
    }
    if (Manager_id != 123 || Manager_pass != 123)
    {
        printf("\n");

        printf("\n\t\t\t\t\t[Pressed Wrong id or Password]");
        printf("\n\t\t\t\t\tPress enter to return front page...\n\n");
        getch();
        main();
    }
}

void category()
{
    int tot = 0, ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0, ct5 = 0,score=0;

    system("cls");


    char sn;
    int choice, s, qua;
    strcpy(o[0].cname, "Fast Food");
    strcpy(o[0].f1, "Burger");
    strcpy(o[0].f2, "Patties");
    strcpy(o[0].f3, "Sandwitch");
    strcpy(o[0].f4, "Fried Chicken");
    strcpy(o[0].f5, "Donut");

    o[0].p1 = 100;
    o[0].p2 = 50;
    o[0].p3 = 80;
    o[0].p4 = 250;
    o[0].p5 = 70;

    strcpy(o[1].cname, "Chinese");
    strcpy(o[1].f1, "Fried Rice");
    strcpy(o[1].f2, "Soup");
    strcpy(o[1].f3, "Stir Fry");
    strcpy(o[1].f4, "Dim Sum");
    strcpy(o[1].f5, "Red Bean Bun");

    o[1].p1 = 300;
    o[1].p2 = 150;
    o[1].p3 = 400;
    o[1].p4 = 250;
    o[1].p5 = 100;

    strcpy(o[2].cname, "Bengali");
    strcpy(o[2].f1, "Kacchi");
    strcpy(o[2].f2, "Tehari");
    strcpy(o[2].f3, "Morog Polao");
    strcpy(o[2].f4, "Shorshe Ilish");
    strcpy(o[2].f5, "Shondesh");

    o[2].p1 = 300;
    o[2].p2 = 250;
    o[2].p3 = 200;
    o[2].p4 = 250;
    o[2].p5 = 150;

    strcpy(o[3].cname, "Italian");
    strcpy(o[3].f1, "Pasta Carbonara");
    strcpy(o[3].f2, "Pizza");
    strcpy(o[3].f3, "Polenta");
    strcpy(o[3].f5, "Mushroom Risotto");
    strcpy(o[3].f4, "Panna Cotta");

    o[3].p1 = 300;
    o[3].p2 = 350;
    o[3].p3 = 400;
    o[3].p4 = 250;
    o[3].p5 = 550;

    strcpy(o[4].cname, "Turkish");
    strcpy(o[4].f1, "Saksuka");
    strcpy(o[4].f2, "Kisir");
    strcpy(o[4].f3, "Dolma");
    strcpy(o[4].f4, "Kofta");
    strcpy(o[4].f5, "Baklava");

    o[4].p1 = 600;
    o[4].p2 = 450;
    o[4].p3 = 400;
    o[4].p4 = 250;
    o[4].p5 = 550;
ct:

    system("cls");
    printf("\n\t\t\t     \033[0;36m   =-=-=-=-=-=-=-\033[0;37mPlease choose cuisine\033[0;36m-=-=-=-=-=");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =      \033[0;37m        1.%s          \033[0;36m        =", o[0].cname);
    printf("\n\t\t\t        =      \033[0;37m        2.%s            \033[0;36m        =", o[1].cname);
    printf("\n\t\t\t        =       \033[0;37m       3.%s            \033[0;36m        =", o[2].cname);
    printf("\n\t\t\t        =        \033[0;37m      4.%s            \033[0;36m        =", o[3].cname);
    printf("\n\t\t\t        =        \033[0;37m      5.%s         \033[0;36m           =", o[4].cname);
    printf("\n\t\t\t        =         \033[0;37m     6.Return to main menu  \033[0;36m      =");
    printf("\n\t\t\t        =         \033[0;37m     7.EXIT       \033[0;36m                =");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\t\t\t     \033[0;37m   Please enter your choice: ");

    scanf("%d", &choice);

    system("cls");

    if (choice == 7)
    {
        dataTransfer();
        exit(0);
    }
    if(choice==6)
    {
        main();
    }
    if (choice < 1 || choice > 7)
    {
        printf("\n\tPress enter and try again\n");
        getch();
        system("cls");
        goto ct;
    }

cc:
    if (choice == 1)
    {
        printf("\n\t\t\t                   \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t                      \033[0;37m%s Menu                    ", o[choice - 1].cname);
        printf("\n\t\t\t                   \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        \033[0;37m1.%s              : %d Taka", o[choice - 1].f1, o[0].p1);
        printf("\n\t\t\t        2.%s             : %d Taka", o[choice - 1].f2, o[0].p2);
        printf("\n\t\t\t        3.%s           : %d Taka", o[choice - 1].f3, o[0].p3);
        printf("\n\t\t\t        4.%s       : %d Taka", o[choice - 1].f4, o[0].p4);
        printf("\n\t\t\t        5.%s               : %d Taka", o[choice - 1].f5, o[0].p5);
        printf("\n");
        printf("\n\t\t\t\t6.Change cuisine and cancel current order");
        printf("\n");
        printf("\n\t\t\t\t7.Done");
        printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

        printf("\n");
        while (1)
        {

            printf("\n\t\t\t        \033[0;36m-------------------------------------------");
            printf("\n");
            printf("\n\t\t\t\t\033[0;37mChoice                : ");
            scanf("%d", &s);
            if(s==6)
            {
                tot = 0, ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0, ct5 = 0;
                goto ct;
            }
            if (s == 7)
            {
                system("cls");
                printf("\n\t\tPress Y to play a game to win a free drink\n\t\tPress N to issue your bill\n");
                printf("\n\t\tEnter your choice : ");
l:
                scanf("%c", &sn);
                if (sn == 'Y')
                {
                    snake();
                    getch();
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();
                    system("cls");
                    return main();
                }
                else if (sn == 'N')
                {
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();
                    return main();
                }
                else
                    goto l;
            }
            if (s < 1 || s > 6)
            {
                printf("\n\t*Press enter and try again*\n");
                getch();
                system("cls");
                goto cc;
            }

            printf("\n\t\t\t\tQuantity              : ");

            scanf("%d", &qua);
            printf("\n\t\t\t        \033[0;36m-------------------------------------------");

            if (s == 1)
            {
                ct1 += qua;
                tot += o[0].p1 * qua;
            }
            if (s == 2)
            {
                ct2 += qua;
                tot += o[0].p2 * qua;
            }
            if (s == 3)
            {
                ct3 += qua;
                tot += o[0].p3 * qua;
            }
            if (s == 4)
            {
                ct4 += qua;
                tot += o[0].p4 * qua;
            }
            if (s == 5)
            {
                ct5 += qua;
                tot += o[0].p5 * qua;
            }
            printf("\n\t\t\t\t\033[0;37mPayable amount so far : %d", tot);
        }
    }
    if (choice == 2)
    {
        printf("\n\t\t\t                  \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t                      \033[0;37m%s Menu                    ", o[choice - 1].cname);
        printf("\n\t\t\t                  \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        \033[0;37m1.%s          : %d Taka", o[choice - 1].f1, o[1].p1);
        printf("\n\t\t\t        2.%s                : %d Taka", o[choice - 1].f2, o[1].p2);
        printf("\n\t\t\t        3.%s            : %d Taka", o[choice - 1].f3, o[1].p3);
        printf("\n\t\t\t        4.%s             : %d Taka", o[choice - 1].f4, o[1].p4);
        printf("\n\t\t\t        5.%s        : %d Taka", o[choice - 1].f5, o[1].p5);
        printf("\n");
        printf("\n\t\t\t\t6.Change cuisine and cancel current order");
        printf("\n\t\t\t\t7.Done");
        printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

        printf("\n");
        while (1)
        {

            printf("\n\t\t\t        \033[0;36m-------------------------------------------");
            printf("\n");
            printf("\n\t\t\t\t\033[0;37mChoice                : ");
            scanf("%d", &s);
            if(s==6)
            {
                tot = 0, ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0, ct5 = 0;
                goto ct;
            }
            if (s == 7)
            {
                system("cls");
                printf("\n\t\tPress Y to play a game to win a free drink\n\t\tPress N to issue your bill\n");
                printf("\n\t\tEnter your choice : ");
j:
                scanf("%c", &sn);
                if (sn == 'Y')
                {
                    snake();
                    getch();
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();
                    system("cls");

                    return main();
                }
                else if (sn == 'N')
                {
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();

                    return main();
                }
                else
                    goto j;
            }
            if (s < 1 || s > 7)
            {
                printf("\n\t*Press enter and try again*\n");
                getch();
                system("cls");
                goto cc;
            }

            printf("\n\t\t\t\tQuantity              : ");

            scanf("%d", &qua);
            printf("\n\t\t\t        \033[0;36m-------------------------------------------");

            if (s == 1)
            {
                ct1 += qua;
                tot += o[1].p1 * qua;
            }
            if (s == 2)
            {
                ct2 += qua;
                tot += o[1].p2 * qua;
            }
            if (s == 3)
            {
                ct3 += qua;
                tot += o[1].p3 * qua;
            }
            if (s == 4)
            {
                ct4 += qua;
                tot += o[1].p4 * qua;
            }
            if (s == 5)
            {
                ct5 += qua;
                tot += o[1].p5 * qua;
            }
            printf("\n\t\t\t\t\033[0;37mPayable amount so far : %d", tot);
        }
    }
    if (choice == 3)
    {
        printf("\n\t\t\t                  \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t                      \033[0;37m%s Menu                    ", o[choice - 1].cname);
        printf("\n\t\t\t                  \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        \033[0;37m1.%s              : %d Taka", o[choice - 1].f1, o[2].p1);
        printf("\n\t\t\t        2.%s              : %d Taka", o[choice - 1].f2, o[2].p2);
        printf("\n\t\t\t        3.%s         : %d Taka", o[choice - 1].f3, o[2].p3);
        printf("\n\t\t\t        4.%s       : %d Taka", o[choice - 1].f4, o[2].p4);
        printf("\n\t\t\t        5.%s            : %d Taka", o[choice - 1].f5, o[2].p5);
        printf("\n");
        printf("\n\t\t\t\t6.Change cuisine and cancel current order");
        printf("\n\t\t\t\t7.Done");
        printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

        printf("\n");
        while (1)
        {

            printf("\n\t\t\t        \033[0;36m-------------------------------------------");
            printf("\n");
            printf("\n\t\t\t\t\033[0;37mChoice                : ");
            scanf("%d", &s);
            if(s==6)
            {
                tot = 0, ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0, ct5 = 0;
                goto ct;
            }
            if (s == 7)
            {
                system("cls");
                printf("\n\t\tPress Y to play a game to win a free drink\n\t\tPress N to issue your bill\n");
                printf("\n\t\tEnter your choice : ");
k:
                scanf("%c", &sn);
                if (sn == 'Y')
                {
                    snake();
                    getch();
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();
                    system("cls");

                    return main();
                }
                else if (sn == 'N')
                {
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();

                    return main();
                }
                else
                    goto k;
            }
            if (s < 1 || s > 7)
            {
                printf("\n\t*Press enter and try again*\n");
                getch();
                system("cls");
                goto cc;
            }

            printf("\n\t\t\t\tQuantity              : ");

            scanf("%d", &qua);
            printf("\n\t\t\t        \033[0;36m-------------------------------------------");

            if (s == 1)
            {
                ct1 += qua;
                tot += o[2].p1 * qua;
            }
            if (s == 2)
            {
                ct2 += qua;
                tot += o[2].p2 * qua;
            }
            if (s == 3)
            {
                ct3 += qua;
                tot += o[2].p3 * qua;
            }
            if (s == 4)
            {
                ct4 += qua;
                tot += o[2].p4 * qua;
            }
            if (s == 5)
            {
                ct5 += qua;
                tot += o[2].p5 * qua;
            }
            printf("\n\t\t\t\t\033[0;37mPayable amount so far : %d", tot);
        }
    }
    if (choice == 4)
    {
        printf("\n\t\t\t                  \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t                     \033[0;37m%s Menu                    ", o[choice - 1].cname);
        printf("\n\t\t\t                  \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        \033[0;37m1.%s        : %d Taka", o[choice - 1].f1, o[3].p1);
        printf("\n\t\t\t        2.%s                  : %d Taka", o[choice - 1].f2, o[3].p2);
        printf("\n\t\t\t        3.%s                : %d Taka", o[choice - 1].f3, o[3].p3);
        printf("\n\t\t\t        4.%s            : %d Taka", o[choice - 1].f4, o[3].p4);
        printf("\n\t\t\t        5.%s       : %d Taka", o[choice - 1].f5, o[3].p5);
        printf("\n");
        printf("\n\t\t\t\t6.Change cuisine and cancel current order");
        printf("\n\t\t\t\t7.Done");
        printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

        printf("\n");
        while (1)
        {

            printf("\n\t\t\t        \033[0;36m-------------------------------------------");
            printf("\n");
            printf("\n\t\t\t\t\033[0;37mChoice                   : ");
            scanf("%d", &s);
            if(s==6)
            {
                tot = 0, ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0, ct5 = 0;
                goto ct;
            }
            if (s == 7)
            {
                system("cls");
                printf("\n\t\tPress Y to play a game to win a free drink\n\t\tPress N to issue your bill\n");
                printf("\n\t\tEnter your choice : ");
r:
                scanf("%c", &sn);
                if (sn == 'Y')
                {
                    snake();
                    getch();
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();
                    system("cls");

                    return main();
                }
                else if (sn == 'N')
                {
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();

                    return main();
                }
                else
                    goto r;
            }
            if (s < 1 || s > 7)
            {
                printf("\n\t*Press enter and try again*\n");
                getch();
                system("cls");
                goto cc;
            }

            printf("\n\t\t\t\tQuantity                 : ");

            scanf("%d", &qua);
            printf("\n\t\t\t        \033[0;36m-------------------------------------------");

            if (s == 1)
            {
                ct1 += qua;
                tot += o[3].p1 * qua;
            }
            if (s == 2)
            {
                ct2 += qua;
                tot += o[3].p2 * qua;
            }
            if (s == 3)
            {
                ct3 += qua;
                tot += o[3].p3 * qua;
            }
            if (s == 4)
            {
                ct4 += qua;
                tot += o[3].p4 * qua;
            }
            if (s == 5)
            {
                ct5 += qua;
                tot += o[3].p5 * qua;
            }
            printf("\n\t\t\t\t\033[0;37mPayable amount so far    : %d", tot);
        }
    }
    if (choice == 5)
    {
        printf("\n\t\t\t                  \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t                     \033[0;37m%s Menu                    ", o[choice - 1].cname);
        printf("\n\t\t\t                  \033[0;36m~~~||******||~~~~");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        \033[0;37m1.%s             : %d Taka", o[choice - 1].f1, o[4].p1);
        printf("\n\t\t\t        2.%s               : %d Taka", o[choice - 1].f2, o[4].p2);
        printf("\n\t\t\t        3.%s               : %d Taka", o[choice - 1].f3, o[4].p3);
        printf("\n\t\t\t        4.%s               : %d Taka", o[choice - 1].f4, o[4].p4);
        printf("\n\t\t\t        5.%s             : %d Taka", o[choice - 1].f5, o[4].p5);
        printf("\n");
        printf("\n\t\t\t\t6.Change cuisine and cancel current order");
        printf("\n\t\t\t\t7.Done");
        printf("\n\t\t\t        \033[0;36m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

        printf("\n");
        while (1)
        {

            printf("\n\t\t\t        \033[0;36m-------------------------------------------");
            printf("\n");
            printf("\n\t\t\t\t\033[0;37mChoice                : ");
            scanf("%d", &s);
            if(s==6)
            {
                tot = 0, ct1 = 0, ct2 = 0, ct3 = 0, ct4 = 0, ct5 = 0;
                goto ct;
            }
            if (s == 7)
            {
                system("cls");
                printf("\n\t\tPress Y to play a game to win a free drink\n\t\tPress N to issue your bill\n");
                printf("\n\t\tEnter your choice : ");
t:
                scanf("%c", &sn);
                if (sn == 'Y')
                {
                    snake();
                    getch();
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();
                    system("cls");

                    return main();
                }
                else if (sn == 'N')
                {
                    bill(&ct1, &ct2, &ct3, &ct4, &ct5, &tot, &choice);
                    getch();

                    return main();
                }
                else
                    goto t;
            }
            if (s < 1 || s > 7)
            {
                printf("\n\t*Press enter and try again*\n");
                getch();
                system("cls");
                goto cc;
            }
            else
            {

                printf("\n\t\t\t\tQuantity              : ");

                scanf("%d", &qua);
                printf("\n\t\t\t        \033[0;36m-------------------------------------------");

                if (s == 1)
                {
                    ct1 += qua;
                    tot += o[4].p1 * qua;
                }
                if (s == 2)
                {
                    ct2 += qua;
                    tot += o[4].p2 * qua;
                }
                if (s == 3)
                {
                    ct3 += qua;
                    tot += o[4].p3 * qua;
                }
                if (s == 4)
                {
                    ct4 += qua;
                    tot += o[4].p4 * qua;
                }
                if (s == 5)
                {
                    ct5 += qua;
                    tot += o[4].p5 * qua;
                }
                printf("\n\t\t\t\t\033[0;37mPayable amount so far : %d", tot);
            }
        }
    }
}

void bill(int *a, int *b, int *c, int *d, int *e, int *tot, int *ch)
{
    system("cls");

    char ab[1], sn;
    time_t t;
    time(&t);
    FILE *file;
    file = fopen("daily_userInfo.txt", "a");
    system("color F0");
    printf("\n\n");
    printf("\t\t\t\tDonut Wait\n\n\n");
    fprintf(file, "\t\t\t\tDonut Wait\n\n\n");

    printf("Invoice To : %s\n", m[0].uname);
    fprintf(file, "Invoice To : %s\n", m[0].uname);
    printf("Bill time: %s", ctime(&t));
    fprintf(file, "Bill time: %s", ctime(&t));
    printf("\n---------------------------------------------------------------------------\n");
    fprintf(file, "\n---------------------------------------------------------------------------\n");

    if ((*a) <= 0 && (*b) <= 0 && (*c) <= 0 && (*d) <= 0 && (*e) <= 0)
    {
        printf("\n\tYou have not ordered anything\n");
        fprintf(file, "No orders\n");
    }
    else
    {
        printf("Item\t\t\t\tQty.\tRate\t\t: Total\n");
        fprintf(file, "Item\t\t\t\tQty.\tRate\t\t: Total\n");
        printf("---------------------------------------------------------------------------\n");
        fprintf(file, "---------------------------------------------------------------------------\n");

        if ((*ch) == 1)
        {
            if ((*a) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
            }

            if ((*b) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
            }

            if ((*c) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
            }
            if ((*d) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
            }

            if ((*e) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
            }
            printf("---------------------------------------------------------------------------\n");
        }
        if ((*ch) == 2)
        {
            if ((*a) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
            }

            if ((*b) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
            }

            if ((*c) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
            }
            if ((*d) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
            }

            if ((*e) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
            }
            printf("---------------------------------------------------------------------------\n");
        }
        if ((*ch) == 3)
        {
            if ((*a) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
            }

            if ((*b) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
            }

            if ((*c) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
            }
            if ((*d) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t|\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
            }

            if ((*e) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
            }
            printf("---------------------------------------------------------------------------\n");
        }
        if ((*ch) == 4)
        {
            if ((*a) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
            }

            if ((*b) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
            }

            if ((*c) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
            }
            if ((*d) > 0)
            {
                printf("%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
                fprintf(file, "%s\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
            }

            if ((*e) > 0)
            {
                printf("%s\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
                fprintf(file, "%s\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
            }
            printf("---------------------------------------------------------------------------\n");
        }
        if ((*ch) == 5)
        {
            if ((*a) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f1, (*a), o[(*ch) - 1].p1, (*a) * o[(*ch) - 1].p1);
            }

            if ((*b) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f2, (*b), o[(*ch) - 1].p2, (*b) * o[(*ch) - 1].p2);
            }

            if ((*c) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f3, (*c), o[(*ch) - 1].p3, (*c) * o[(*ch) - 1].p3);
            }
            if ((*d) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f4, (*d), o[(*ch) - 1].p4, (*d) * o[(*ch) - 1].p4);
            }

            if ((*e) > 0)
            {
                printf("%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
                fprintf(file, "%s\t\t\t\t%d\tBDT %d\t\t: BDT %d\n", o[(*ch) - 1].f5, (*e), o[(*ch) - 1].p5, (*e) * o[(*ch) - 1].p5);
            }
            printf("---------------------------------------------------------------------------\n");
        }

        if (sc[0].score < 100)
        {
            printf("\n\n\t\tYou didn't win a free drink.Better luck next time\n");
            fprintf(file, "\n\n\t\tYou didn't win a free drink.Better luck next time\n");
        }
      else if (sc[0].score >= 100 && sc[0].score < 200)
        {
            printf("\n\n\t\tCongratulations!!!You won a Zesty Lemonade\n");
            fprintf(file, "\n\n\t\tCongratulations!!!You won a Zesty Lemonade\n");
        }
       else if (sc[0].score >= 200 && sc[0].score < 300)
        {
            printf("\n\n\t\tCongratulations!!!You won a Chilled Lacchi\n");
            fprintf(file, "\n\n\t\tCongratulations!!!You won a Chilled Lacchi\n");
        }
        else if(sc[0].score >= 300 && sc[0].score < 400)
        {
            printf("\n\n\t\tCongratulations!!!You won a Velvety Milkshake\n");
            fprintf(file, "\n\n\t\tCongratulations!!!You won a Velvety Milkshake\n");
        }
        else if (sc[0].score >= 400)
        {
            printf("\n\n\t\tCongratulations!!!You won a Donut Wait special Cappuccino\n");
            fprintf(file, "\n\n\t\tCongratulations!!!You won a Donut Wait special Cappuccino\n");
        }
    }

    printf("\n---------------------------------------------------------------------------\n");
    fprintf(file, "\n---------------------------------------------------------------------------\n");
    printf("Sub total\t\t\t\t\t\t:BDT %d\n\n", (*tot));
    fprintf(file, "Sub total\t\t\t\t\t\t:BDT %d\n\n", (*tot));

    printf("Adding 10%% VAT\t\t\t\t\t\t:BDT %.4f", (*tot) * 10 / 100.0);
    fprintf(file, "Adding 10%% VAT\t\t\t\t\t\t:BDT %.4f", (*tot) * 10 / 100.0);
    printf("\n---------------------------------------------------------------------------\n");
    fprintf(file, "\n---------------------------------------------------------------------------\n");
    printf("Grand Total\t\t\t\t\t\t:BDT %0.4f\n\n", (*tot) + ((*tot) * 10 / 100.0));
    fprintf(file, "Grand Total\t\t\t\t\t\t:BDT %0.4f\n\n", (*tot) + ((*tot) * 10 / 100.0));

    printf("\n\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t= Thank you for visiting us =");
    printf("\n\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    fprintf(file, "\n\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    fprintf(file, "\n\t\t= Thank you for visiting us =");
    fprintf(file, "\n\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

    fclose(file);
}

void snake()
{
    int m, n;
    countTail = 0;

    Print();
    load();
    setup();
    while (gameOver != 0)
    {
        draw();
        input();
        makeLogic();
        for (m = 0; m < 1500; m++)
        {
            for (n = 0; n < 18000; n++)
            {
                //snake speed
            }
        }
    }
}

void Print()
{
    system("cls");

    printf("\n\n\tWelcome to the mini Snake game.(press any key to continue)\n");
    getch();

    system("cls");

    printf("\n---------------------------------------------------------------------------\n");
    printf("\t\t\t\tGame instructions");
    printf("\n---------------------------------------------------------------------------\n\n");
    printf("\n->Make sure you do not have Caps Lock turned on\n\n");
    printf("\n->Use W,A,S,D keys to move the snake.\n\n");
    printf("-> You will be provided foods at the several positions within boundary of the screen which you have to eat to gain points.\n\n");
    printf("\t*For 100-199 points you will get a Zesty Lemonade.\n\n");
    printf("\t*For 200-299 points you will get a Chilled Lacchi.\n\n");
    printf("\t*For 300-399 points you will get a Velvety Milkshake.\n\n");
    printf("\t*For 400 and above you will get a Donut Wait special Cappuccino.\n\n");
    printf("-> Here you are provided with three lives. Your life will decrease as you hit the wall or you hit the snake body.\n\n");
    printf("-> You can exit the game in its middle by pressing X.\n\n");
    printf("-> If you want to exit to the main menu press esc button. \n\n");
    printf("Press any key to play game...");

    if (getch() == 27)
    {
        return main();
    }
}

void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void load()
{

    system("cls");

    int row, col, r, c, q;

    gotoxy(52, 12);
    printf("\033[0;36mloading...");

    gotoxy(46, 13);

    for (r = 1; r <= 20; r++)
    {
        for (q = 0; q <= 70000000; q++)
        {
            //loading speed
        }
        printf("\033[0;36m%c", 177);
    }
    gotoxy(46, 15);
    printf("Press any key to enter");
    getch();
}

void setup()
{
    gameOver = 3;
    x = width / 2;
    y = height / 2;

level1:
    fruitX = rand() % 40;
    if (fruitX == 0)
    {
        goto level1;
    }

level2:
    fruitY = rand() % 20;
    if (fruitY == 0)
    {
        goto level2;
    }
    score = 0;
}

void draw()
{

    int i, j;
    system("cls");
    system("color 0F");
    printf("\033[0;36m\nScore: %d\t\tLives: %d\n\033[0;37m", sc[0].score, gameOver);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {

            if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
            {

                printf("\033[0;37m%c", 219); // border
            }
            else
            {
                if (i == y && j == x)
                {
                    printf("\033[0;33m%c", 233); // head
                }
                else if (i == fruitY && j == fruitX)
                {

                    printf("\033[0;31m%c", 232); // fruit
                }
                else
                {
                    int p = 0, k;
                    for (k = 0; k < countTail; k++)
                    {

                        if (i == tailY[k] && j == tailX[k])
                        {
                            printf("\033[0;32m%c", 254); // body
                            p = 1;
                        }
                    }
                    if (p == 0)
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}
void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a' :
            flag = 1;
            break;
        case 'd':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 's':
            flag = 4;
            break;
        case 'x':
            gameOver = 0;
            break;
        }
    }
}

void makeLogic()
{
    int prevX = tailX[0], prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = x;
    tailY[0] = y;

    for (i = 1; i < countTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (flag)
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }
    if (x < 1 || x > width - 1 || y < 1 || y > height - 1)
    {
        gameOver--;
        x = width / 2;
        y = height / 2;
    }
    for (i = 0; i < countTail; i++)
    {
        if (x == tailX[i] && y == tailY[i])
            gameOver--;
    }
    if (x == fruitX && y == fruitY)
    {
level3:
        fruitX = rand() % 20;
        if (fruitX == 0)
        {
            goto level3;
        }
level4:
        fruitY = rand() % 20;
        if (fruitY == 0)
        {
            goto level4;
        }
        score += 20;
        countTail++;
    }
    sc[0].score = score;
    freeDrink(&score);
}

void freeDrink(int *a)
{
    if (*a < 100)
    {
        printf("\033[0;36m\n\tKeep playing!\n");
    }
    if (*a >= 100 && *a < 200)
    {
        printf("\033[0;36m\n\tYou won a Zesty Lemonade\n");
    }
    if (*a >= 200 && *a < 300)
    {
        printf("\033[0;36m\n\tYou won a Chilled Lacchi\n");
    }
    if (*a >= 300 && *a < 400)
    {
        printf("\033[0;36m\n\tYou won a Velvety Milkshake\n");
    }
    if (*a >= 400)
    {
        printf("\033[0;36m\n\tYou won a Donut Wait special Cappuccino\n");
    }
}


void dataTransfer()
{

    FILE *fptr1, *fptr2;
    char c;

    fptr1 = fopen("Daily_userInfo.txt", "r");
    fptr2 = fopen("total_userInfo.txt", "a");

    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    fclose(fptr1);
    fclose(fptr2);
}



void dailyUserInfo()
{
    FILE *fptr1;
    fptr1 = fopen("daily_userInfo.txt", "r");

    if(fptr1 == NULL)
    {
        printf("There is no user information in the file");
    }

    char ch = fgetc(fptr1);
    while (!feof(fptr1))
    {
        ch = getc(fptr1);

        printf("\033[0;37m%c", ch);
    }
    fclose(fptr1);
}


void totalUserInfo()
{
    FILE *fptr1;
    fptr1 = fopen("total_userInfo.txt", "r");

    if(fptr1 == NULL)
    {
        printf("\nDo some business first!!\n");
    }

    char ch = fgetc(fptr1);
    while (!feof(fptr1))
    {
        ch = getc(fptr1);

        printf("\033[0;37m%c", ch);
    }
    fclose(fptr1);
}

void clearFile()
{

    FILE *cf;

    cf = fopen("daily_userInfo.txt", "w");
    fclose(cf);
}

