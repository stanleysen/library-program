#include <stdio.h>
#include <string.h>
#include <time.h>
int sumVisitor, sumBook, sumBorrowBook, i, j, k, x;

struct visitorList{ //struct untuk profile visitor
    char visitorFirstName[15], visitorLastName[25];
    char visitorUser[15], visitorPass[15];
} profile[100];

char thisvisitorFirstName[15], thisvisitorLastName[25];

struct bookList{ //struct untuk daftar buku
    int bookId;
    char bookName[100];
	int bookYear;
	char bookAuthor[100];
    char bookStatus[15];
} book[30];

struct bookBorrowedList{
    char visitorFirstName[15];
    char visitorLastName[25];
    char bookName[100];
    int day, year;
    char monthName[15];
    int deadlineDay, deadlineYear;
    char deadlineMonth[15];
} bookBorrowed[30];

struct tm *local;
int day, month, year;
int deadlineDay, deadlineYear;
char monthName[15], deadlineMonth[15];

void timeNow()
{
    time_t t = time(NULL);
    local = localtime(&t);
    day = local->tm_mday;
    month = local->tm_mon;
    year = local->tm_year + 1900;
    if (month == 0){
        strcpy(monthName, "January");
    } else if (month == 1){
        strcpy(monthName, "Ferbuary");
    } else if (month == 2){
        strcpy(monthName, "March");
    } else if (month == 3){
        strcpy(monthName, "April");
    } else if (month == 4){
        strcpy(monthName, "May");
    } else if (month == 5){
        strcpy(monthName, "June");
    } else if (month == 6){
        strcpy(monthName, "July");
    } else if (month == 7){
        strcpy(monthName, "August");
    } else if (month == 8){
        strcpy(monthName, "September");
    } else if (month == 9){
        strcpy(monthName, "October");
    } else if (month == 10){
        strcpy(monthName, "November");
    } else if (month == 11){
        strcpy(monthName, "December");
    }
}

void deadline()
{
    if (strcmp(monthName, "January") == 0 && day + 7 >= 31){
        strcpy(deadlineMonth, "Febuary");
        deadlineDay = day - 31 + 7;
        deadlineYear = year;
    } else if (strcmp(monthName, "Febuary") == 0 && day + 7 >= 28 && year % 4 != 0){
        strcpy(deadlineMonth, "March");
        deadlineDay = day - 28 + 7;
        deadlineYear = year;
    } else if (strcmp(monthName, "Febuary") == 0 && day + 7 >= 29 && year % 4 == 0){
        strcpy(deadlineMonth, "March");
        deadlineDay = day - 29 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "March") == 0 && day + 7 >= 31){
        strcpy(deadlineMonth, "April");
        deadlineDay = day - 31 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "April") == 0 && day + 7 >= 30){
        strcpy(deadlineMonth, "May");
        deadlineDay = day - 30 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "May") == 0 && day + 7 >= 31){
        strcpy(deadlineMonth, "June");
        deadlineDay = day - 31 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "June") == 0 && day + 7 >= 30){
        strcpy(deadlineMonth, "July");
        deadlineDay = day - 30 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "July") == 0 && day + 7 >= 31){
        strcpy(deadlineMonth, "August");
        deadlineDay = day - 31 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "August") == 0 && day + 7 >= 31){
        strcpy(deadlineMonth, "September");
        deadlineDay = day - 31 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "September") == 0 && day + 7 >= 30){
        strcpy(deadlineMonth, "October");
        deadlineDay = day - 30 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "October") == 0 && day + 7 >= 31){
        strcpy(deadlineMonth, "November");
        deadlineDay = day - 31 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "November") == 0 && day + 7 >= 30){
        strcpy(deadlineMonth, "December");
        deadlineDay = day - 30 + 7;
        deadlineYear = year;
    } else if(strcmp(monthName, "December") == 0 && day + 7 >= 31){
        strcpy(deadlineMonth, "January");
        deadlineDay = day - 31 + 7;
        deadlineYear++;
    } else {
        deadlineDay = day + 7;
        strcpy(deadlineMonth, monthName);
        deadlineYear = year;
    }
}

void signinMember()
{char user[15], pass[15], confirm;
    
    awalSignin:
    x = 0;
	printf("\n-----Sign In Visitor-----\n"); //masuk fitur sign in visitor
    printf("Username: ");
    scanf(" %s", user); //input username
    printf("Password: ");
    scanf(" %s", pass); //input password
	
    //membandingkan dengan data visitor yang telah disimpan
    for(i = 0; i < sumVisitor; i++){
        if (strcmp(profile[i].visitorUser, user) == 0 && strcmp(profile[i].visitorPass, pass) == 0){
            strcpy(thisvisitorFirstName, profile[i].visitorFirstName);
            strcpy(thisvisitorLastName, profile[i].visitorLastName);
            x++;
            break;
        } else if (i == (sumVisitor - 1)){
            printf("Incorrect Username Or Password.\n");
            do {
                printf("\nDo You Want To Go Back? (Y/N)\n");
                printf("Input: ");
                scanf(" %c", &confirm);
                if (confirm == 'Y' || confirm == 'y'){
                    ;
                } else if (confirm == 'N' || confirm == 'n'){
                    goto awalSignin;
                } else {
                    printf("Wrong Input. Please Try Again\n\n");
                }
            } while (confirm != 'Y' && confirm != 'y' && confirm && 'N' && confirm != 'n');
        }
    }
}

void signupMember()
{FILE *fa; char firstName[15], lastName[25], user[15], pass[15], conPass[15];
    awalSignup:
    printf("\n-----Sign Up Visitor-----\n"); //masuk fitur sign up visitor
    printf("First Name: ");
    scanf(" %s", firstName);
    printf("Last Name : ");
    scanf(" %[^\n]", lastName);
    printf("Username  : ");
    scanf(" %s", user);
    printf("Password  : ");
    scanf(" %s", pass);
    printf("Confirm Password: ");
    scanf(" %s", conPass);
    
    //mengecek apakah password dan confirm password sama atau tidak
    if (strcmp(pass, conPass) == 0){
        //jika belum ada akun yang disimpan, data yang diinput masuk ke dalam data program
        for(j = 0; j < sumVisitor; j++){
            //jika sama, harus mengganti username kembali
            if (strcmp(profile[j].visitorUser, user) == 0){
                printf("This Username Is Already Taken. Please Use Another Username\n\n");
                goto awalSignup; //pergi ke fitur sign up awal
                break;
            } else if (j == (sumVisitor - 1)){ //jika sudah sampai data terakhir, data yang diinput akan dimasukkan ke dalam data program
                fa = fopen("Visitor List.txt", "a");
                fprintf(fa, "%s %s#%s#%s\n", firstName, lastName, user, pass);
                fclose(fa);
                printf("Your Account Has Been Created. Please Sign In\n");
            }
        }   
    } else { //jika pasword dan confirm password tidak cocok, kembali ke fitur sign up awal
        printf("Password Doesn't Match. Please Try Again\n\n");
        goto awalSignup;
    }
}

void idSort()
{
    for (i = 0; i < sumBook-1; i++){
        for (j = 0; j < sumBook-i-1; j++){
            if (book[j].bookId > book[j+1].bookId){
                struct bookList temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    printf("\n=========================================\n");
	printf("||              BOOK LIST              ||\n");
    printf("=========================================\n");

    for (i = 0; i < sumBook; i++){
        printf("%d. #%03d-%s in %d by %s (%s)\n", i+1, book[i].bookId, book[i].bookName, book[i].bookYear, book[i].bookAuthor, book[i].bookStatus);
    }
}

void titleSort()
{
    for (i = 0; i < sumBook-1; i++){
        for (j = 0; j < sumBook-i-1; j++){
            if (strcmp(book[j].bookName, book[j+1].bookName) > 0){
                struct bookList temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    printf("\n=========================================\n");
	printf("||              BOOK LIST              ||\n");
    printf("=========================================\n");

    for (i = 0; i < sumBook; i++){
        printf("%d. #%03d-%s in %d by %s (%s)\n", i+1, book[i].bookId, book[i].bookName, book[i].bookYear, book[i].bookAuthor, book[i].bookStatus);
    }
}

void yearSort()
{
    for (i = 0; i < sumBook-1; i++){
        for (j = 0; j < sumBook-i-1; j++){
            if (book[j].bookYear > book[j+1].bookYear){
                struct bookList temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    printf("\n=========================================\n");
	printf("||              BOOK LIST              ||\n");
    printf("=========================================\n");

    for (i = 0; i < sumBook; i++){
        printf("%d. #%03d-%s in %d by %s (%s)\n", i+1, book[i].bookId, book[i].bookName, book[i].bookYear, book[i].bookAuthor, book[i].bookStatus);
    }
}

void authorSort()
{
    for (i = 0; i < sumBook-1; i++){
        for (j = 0; j < sumBook-i-1; j++){
            if (strcmp(book[j].bookAuthor, book[j+1].bookAuthor) > 0){
                struct bookList temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }

    printf("\n=========================================\n");
	printf("||              BOOK LIST              ||\n");
    printf("=========================================\n");

    for (i = 0; i < sumBook; i++){
        printf("%d. #%03d-%s in %d by %s (%s)\n", i+1, book[i].bookId, book[i].bookName, book[i].bookYear, book[i].bookAuthor, book[i].bookStatus);
    }
}

void borrowBook()
{FILE *fbl, *fbbl; int input, z;
    do{
        z = 0;
        printf("\nInput The Book Number You Want To Borrow\n");
        printf("(Input 0 To Back)\n");
        printf("Input: ");
        scanf(" %d", &input);
        if (input > 0 && input <= sumBook){
            if (strcmp(book[input-1].bookStatus, "Available") == 0){
                strcpy(book[input-1].bookStatus, "Unavailable");
                
                fbl = fopen("Book List.txt", "w");
                for (i = 0; i < sumBook; i++){
                    fprintf(fbl, "%d#%s#%d#%s#%s\n", book[i].bookId, book[i].bookName, book[i].bookYear, book[i].bookAuthor, book[i].bookStatus);
                }
                fclose(fbl);
                
                timeNow();
                deadline();

                fbbl = fopen("Borrow Book List.txt", "a");
                fprintf(fbbl, "%s %s#%s#%d %s %d#%d %s %d\n", thisvisitorFirstName, thisvisitorLastName, book[input-1].bookName, day, monthName, year, deadlineDay, deadlineMonth, deadlineYear);
                fclose(fbbl);

                printf("%s Is Successfully Borrowed\n", book[input-1].bookName);
            } else if (strcmp(book[input-1].bookStatus, "Unavailable") == 0) {
                printf("Sorry, The Book Is Already Borrowed By Others\n");
            }
        } else if (input == 0){
            ;
        } else {
            printf("Wrong Input. Please Try Again\n");
        }
    } while (input < 0 || input > sumBook);
}

void bookList()
{int input;
    
    do{
        printf("\n-----Book Sorting-----\n");
        printf("Sort By:\n");
        printf("1. Book ID\n"); 
        printf("2. Book Title\n");
        printf("3. Publication Year\n");
        printf("4. Author Name\n");
        printf("0. Back\n");
        printf("Input: ");
        scanf(" %d", &input);
        
        switch (input){
            case 1:
                idSort();
                borrowBook();
                break;
            case 2:
                titleSort();
                borrowBook();
                break;
            case 3:
                yearSort();
                borrowBook();
                break;
            case 4:
                authorSort();
                borrowBook();
                break;
            case 0:
                break;
            default:
                printf("Wrong Input. Please Try Again\n\n");
                break;
        }
    } while (input != 0);
}

void foundBook(int z)
{FILE *fbl, *fbbl; char input;
    
    printf("Book Has Been Found!!!\n");
    printf("\nBook ID: %03d\n", book[z].bookId);
    printf("Book Title: %s\n", book[z].bookName);
    printf("Year Publication: %d\n", book[z].bookYear);
    printf("Author: %s\n", book[z].bookAuthor);
    printf("Status: %s\n", book[z].bookStatus);
            
    if (strcmp(book[z].bookStatus, "Available") == 0){
        do {
            printf("Do You Want To Borrow The Book? (Y/N)\n");
            printf("Input: ");
            scanf(" %c", &input);
            if (input == 'Y' || input == 'y'){
                strcpy(book[z].bookStatus, "Unavailable");
                
                fbl = fopen("Book List.txt", "w");
                for (j = 0; j < sumBook; j++){
                    fprintf(fbl, "%d#%s#%d#%s#%s\n", book[j].bookId, book[j].bookName, book[j].bookYear, book[j].bookAuthor, book[j].bookStatus);
                }
                fclose(fbl);

                timeNow();
                deadline();

                fbbl = fopen("Borrow Book List.txt", "a");
                fprintf(fbbl, "%s %s#%s#%d %s %d#%d %s %d\n", thisvisitorFirstName, thisvisitorLastName, book[z].bookName, day, monthName, year, deadlineDay, deadlineMonth, deadlineYear);
                fclose(fbbl);

                printf("%s Is Successfully Borrowed\n", book[z].bookName);
            } else if (input == 'N' || input == 'n'){
                ;
            } else {
                printf("Wrong Input. Please Try Again\n");
            }
        } while (input != 'Y' && input != 'y' && input != 'N' && input != 'n');
                
    } else if (strcmp(book[z].bookStatus, "Unavailable") == 0){
        printf("Sorry, The Book Is Already Borrowed By Others\n");
    }
}

void idSearch()
{int idBook;
    printf("\nInput Book ID: ");
    scanf(" %d", &idBook);
    for (i = 0; i < sumBook; i++){
        if (idBook == book[i].bookId){            
            foundBook(i);
            break;
        } else if (i == sumBook-1){
            printf("The Book You Are Looking For Couldn't Be Found\n");
        }
    }
}

void titleSearch()
{char titleBook[100];
    printf("\nInput Book Title: ");
    scanf(" %[^\n]", titleBook);
    for (i = 0; i < sumBook; i++){
        if (strcmp(titleBook, book[i].bookName) == 0){            
            foundBook(i);
            break;
        } else if (i == sumBook-1){
            printf("The Book You Are Looking For Couldn't Be Found\n");
        }
    }
}

void authorSearch()
{char authorName[100];
    printf("\nInput Author Name: ");
    scanf(" %s", authorName);
    for (i = 0; i < sumBook; i++){
        if (strcmp(authorName, book[i].bookAuthor) == 0){            
            foundBook(i);
            break;
        } else if (i == sumBook-1){
            printf("The Book You Are Looking For Couldn't Be Found\n");
        }
    }
}

void searchBook()
{int input;
    do {
        printf("\n-----Search Book-----\n");
        printf("Search Book By:\n");
        printf("1. Book ID\n");
        printf("2. Book Title\n");
        printf("3. Author Name\n");
        printf("0. Back\n");
        printf("Input: ");
        scanf(" %d", &input);

        switch (input){
            case 1:
                idSearch();
                break;
            case 2:
                titleSearch();
                break;
            case 3:
                authorSearch();
                break;
            case 0:
                break;
            default:
                printf("Wrong Input. Please Try Again\n\n");
                break;
        }
    } while (input != 0);
}

void choiceBook()
{int choice;
    do{
        printf("\n-----Borrow A Book-----\n");
        printf("1. Searching Book\n");
        printf("2. Book List\n");
        printf("0. Back\n");
        printf("Input: ");
        scanf(" %d", &choice);
        switch (choice){
            case 1:
                searchBook();
                break;
            case 2:
                bookList();
                break;
            case 0:
                break;
            default:
                printf("Wrong Input. Please Try Again\n\n");
                break;
        }
    } while (choice != 0);
}

int monthDeadline(int monthDate, int dayDL)
{int num, sumDayFined;
    for (num = monthDate; num < month; num++){
        if (num == monthDate){
            if (monthDate == 0){
                sumDayFined = 31 - dayDL;
            } else if (monthDate == 1 && year % 4 == 0){
                sumDayFined = 29 - dayDL;
            } else if (monthDate == 1 && year % 4 != 0){
                sumDayFined = 28 - dayDL;
            } else if (monthDate == 2){
                sumDayFined = 31 - dayDL;
            } else if (monthDate == 3){
                sumDayFined = 30 - dayDL;
            } else if (monthDate == 4){
                sumDayFined = 31 - dayDL;
            } else if (monthDate == 5){
                sumDayFined = 30 - dayDL;
            } else if (monthDate == 6){
                sumDayFined = 31 - dayDL;
            } else if (monthDate == 7){
                sumDayFined = 31 - dayDL;
            } else if (monthDate == 8){
                sumDayFined = 30 - dayDL;
            } else if (monthDate == 9){
                sumDayFined = 31 - dayDL;
            } else if (monthDate == 10){
                sumDayFined = 30 - dayDL;
            } else if (monthDate == 11){
                sumDayFined = 31 - dayDL;
            }
        } else if (num == month-1){
            sumDayFined += day;
        } else if (num == 1 && year % 4 == 0){
            sumDayFined += 29;
        } else if (num == 1 && year % 4 != 0){
            sumDayFined += 28;
        } else if (num == 2){
            sumDayFined += 31;
        } else if (num == 3){
            sumDayFined += 30;
        } else if (num == 4){
            sumDayFined += 31;
        } else if (num == 5){
            sumDayFined += 30;
        } else if (num == 6){
            sumDayFined += 31;
        } else if (num == 7){
            sumDayFined += 31;
        } else if (num == 8){
            sumDayFined += 30;
        } else if (num == 9){
            sumDayFined += 31;
        } else if (num == 10){
            sumDayFined += 30;
        } else if (num == 11){
            sumDayFined += 31;
        } 
    }
    return sumDayFined;
}

void getFined(int dayDL, char monthDL[15], int yearDL)
{FILE *fa; int dayFined, yearFined, sumFined; char monthFined[15];

    timeNow();
    fa = fopen("Fine List.txt", "a");
    if (yearDL == year){
        if (strcmp(monthDL, monthName) == 0){
            if (dayDL > day){
                printf("You Have Returned The Book On Time!!!\n");
            } else {
                dayFined = day - dayDL;
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
                fprintf(fa, "%d %s %d#%s %s#%d\n", day, monthName, year, thisvisitorFirstName, thisvisitorLastName, sumFined);
            }
        } else {
            if (strcmp(monthDL, "January")){
                dayFined = monthDeadline(0, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "February")){
                dayFined = monthDeadline(1, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "March")){
                dayFined = monthDeadline(2, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "April")){
                dayFined = monthDeadline(3, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "May")){
                dayFined = monthDeadline(4, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "June")){
                dayFined = monthDeadline(5, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "July")){
                dayFined = monthDeadline(6, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "August")){
                dayFined = monthDeadline(7, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "September")){
                dayFined = monthDeadline(8, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "October")){
                dayFined = monthDeadline(9, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            } else if (strcmp(monthDL, "November")){
                dayFined = monthDeadline(10, dayDL);
                sumFined = dayFined * 1000;
                printf("Fine: Rp%d,-\n", sumFined);
            }
            fprintf(fa, "%d %s %d#%s %s#%d\n", day, monthName, year, thisvisitorFirstName, thisvisitorLastName, sumFined);
        }
    } else {
        ; //ini buat yang beda tahun tapi ngga ada waktu buat bikin codingnya
    }
    fclose(fa);
}

void returnBook()
{FILE *fbbl, *fbl, *fr; int num = 0, input; char bookName[30][100];
    
    fbbl = fopen("Borrow Book List.txt", "r");
    do {
        for (i = 0; i < sumBorrowBook; i++){
    		if (strcmp(bookBorrowed[i].visitorFirstName, thisvisitorFirstName) == 0 && strcmp(bookBorrowed[i].visitorLastName, thisvisitorLastName) == 0){
                if (num == 0){
                    printf("\nWhich Book Would You Like To Return?\n");
                }
                strcpy(bookName[num], bookBorrowed[i].bookName);
                printf("%d. %s\n", num+1, bookName[num]);
                num++;
            }
        }
        if (num == 0){
            printf("No Borrowed Books Can Be Returned\n");
            fclose(fbbl);
            goto akhirReturnBook;
        }
        
        fclose(fbbl);

        printf("0. Back\n");
        printf("Input: ");
        scanf(" %d", &input);
    
        if (input > 0 && input <= num){
            fbl = fopen("Book List.txt", "w");
            fbbl = fopen("Borrow Book List.txt", "w");
            for (i = 0; i < sumBorrowBook; i++){
                if (strcmp(bookBorrowed[i].bookName, bookName[input-1]) == 0){
                    for (j = 0; j < sumBook; j++){
                        if (strcmp(book[j].bookName, bookName[input-1]) == 0){
                            strcpy(book[j].bookStatus, "Available");
                            break;
                        }
                    }
                    for (j = 0; j < sumBook; j++){
                        fprintf(fbl, "%d#%s#%d#%s#%s\n", book[j].bookId, book[j].bookName, book[j].bookYear, book[j].bookAuthor, book[j].bookStatus);
                    }
                    printf("The Book Has Been Returned\n");

                    getFined(bookBorrowed[i].deadlineDay, bookBorrowed[i].deadlineMonth, bookBorrowed[i].deadlineYear);

                } else if (strcmp(bookBorrowed[i].bookName, bookName[input-1]) != 0){
                    fprintf(fbbl, "%s %s#%s#%d %s %d#%d %s %d\n", bookBorrowed[i].visitorFirstName, bookBorrowed[i].visitorLastName, bookBorrowed[i].bookName, bookBorrowed[i].day, bookBorrowed[i].monthName, bookBorrowed[i].year, bookBorrowed[i].deadlineDay, bookBorrowed[i].deadlineMonth, bookBorrowed[i].deadlineYear);
                }
            }
        } else if (input == 0){
            ;
        } else {
            printf("Wrong Input. Please Try Again\n");
        }
    } while (input < 0 || input > num);
    
    fclose(fbl);
    fclose(fbbl);
    akhirReturnBook:
    ;
}

void menuMember()
{FILE *fr, *fa; int visitor;
    
    do{
        fr = fopen("Book List.txt", "r");
        sumBook = 0;
        while (fscanf(fr, " %d#%[^#]#%d#%[^#]#%s", &book[sumBook].bookId, book[sumBook].bookName, &book[sumBook].bookYear, book[sumBook].bookAuthor, book[sumBook].bookStatus) != EOF){
            sumBook++;
        }
        fclose(fr);

        fa = fopen("Borrow Book List.txt", "r");
        sumBorrowBook = 0;
        while (fscanf(fa, " %s %[^#]#%[^#]#%d %s %d#%d %s %d", bookBorrowed[sumBorrowBook].visitorFirstName, bookBorrowed[sumBorrowBook].visitorLastName, bookBorrowed[sumBorrowBook].bookName, &bookBorrowed[sumBorrowBook].day, bookBorrowed[sumBorrowBook].monthName, &bookBorrowed[sumBorrowBook].year, &bookBorrowed[sumBorrowBook].deadlineDay, bookBorrowed[sumBorrowBook].deadlineMonth, &bookBorrowed[sumBorrowBook].deadlineYear) != EOF){
            sumBorrowBook++;
        }
        fclose(fa);
        
        printf("\nWelcome, %s %s!!!\n", thisvisitorFirstName, thisvisitorLastName);
    	printf("\nList of Activity: \n");
    	printf("1. Borrow A Book\n");
    	printf("2. Return A Book\n");
        printf("0. Exit\n");
		printf("Input: ");
		scanf(" %d", &visitor);
		switch (visitor){
			case 1:
				choiceBook();
				break;
			case 2:
				returnBook();
				break;
            case 0:
                break;
			default:
				printf("Wrong Input. Please Try Again\n\n");
				break;
		}
	} while (visitor != 0);
}

void visitor()
{FILE *fr; int member;
	
    do{
        fr = fopen("Visitor List.txt", "r");
        sumVisitor = 0;
        while (fscanf(fr, " %s %[^#]#%[^#]#%s", profile[sumVisitor].visitorFirstName, profile[sumVisitor].visitorLastName, profile[sumVisitor].visitorUser, profile[sumVisitor].visitorPass) != EOF){
            sumVisitor++;
        }
        fclose(fr);

        printf("\n==================================================\n");
	    printf("::           HI!! WELCOME BINUSIAN :)           ::\n");
        printf("==================================================\n");
        
        printf("1. Sign In\n");
		printf("2. Sign Up\n");
        printf("0. Back\n");
        printf("Input: ");
        scanf(" %d", &member);
        switch (member){
			case 1: //jika ingin masuk ke akun yang sudah terdaftar, masuk ke function signinMember
				signinMember();
                if (x == 1){
                    menuMember();
                }
				break;
			case 2: //jika ingin mendaftar, masuk ke function signupMember
				signupMember();
				break;
            case 0: //jika ingin kembali ke fitur menu utama
                break;
			default: //jika input salah
				printf("Wrong Input. Please Try Again\n\n");
				break;
		}
    } while (member != 0);
    
    printf("\n");
}
