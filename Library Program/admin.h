#include <stdio.h>
#include <string.h>
char adminUser[] = "admin", adminPass[] = "1234";
int sumMember, sumTitle, sumFine, z;

struct VisitorList{ //struct untuk profile visitor
    char visitorFullName[40];
    char visitorUser[15], visitorPass[15];
} member[100];

struct BookList{ //struct untuk daftar buku
    int bookId;
    char bookName[100];
	int bookYear;
	char bookAuthor[100];
    char bookStatus[15];
} title[30];

struct FineList{
    int day, year;
    char monthName[15];
    char visitorName[40];
    int fine;
} fine[100];

void visitorList() //menampilkan daftar visitor
{FILE *fr; int a, b; char temp[40];

    fr = fopen("Visitor List.txt", "r");
    sumMember = 0;
    printf("\n=========================================\n");
	printf("||             VISITOR LIST            ||\n");
	printf("=========================================\n");
    while (fscanf(fr, " %[^#]#%[^#]#%s", member[sumMember].visitorFullName, member[sumMember].visitorUser, member[sumMember].visitorPass) != EOF){
        sumMember++;
    }

    for (a = 0; a < sumMember-1; a++){
        for (b = 0; b < sumMember-a-1; b++){
            if (strcmp(member[b].visitorFullName, member[b+1].visitorFullName) > 0){
                strcpy(temp, member[b].visitorFullName);
                strcpy(member[b].visitorFullName, member[b+1].visitorFullName);
                strcpy(member[b+1].visitorFullName, temp);
            }
        }
    }

    for (a = 0; a < sumMember; a++){
        printf("%d. %s\n", a+1, member[a].visitorFullName);
    }
    fclose(fr);
}

void sort1()
{int a, b;
    for (a = 0; a < sumTitle-1; a++){
        for (b = 0; b < sumTitle-a-1; b++){
            if (title[b].bookId > title[b+1].bookId){
                struct BookList temp = title[b];
                title[b] = title[b+1];
                title[b+1] = temp;
            }
        }
    }

    printf("\n=========================================\n");
	printf("||              BOOK LIST              ||\n");
    printf("=========================================\n");

    for (a = 0; a < sumTitle; a++){
        printf("%d. #%03d-%s in %d by %s (%s)\n", a+1, title[a].bookId, title[a].bookName, title[a].bookYear, title[a].bookAuthor, title[a].bookStatus);
    }
}

void sort2()
{int a, b;
    for (a = 0; a < sumTitle-1; a++){
        for (b = 0; b < sumTitle-a-1; b++){
            if (strcmp(title[b].bookName, title[b+1].bookName) > 0){
                struct BookList temp = title[b];
                title[b] = title[b+1];
                title[b+1] = temp;
            }
        }
    }

    printf("\n=========================================\n");
	printf("||              BOOK LIST              ||\n");
    printf("=========================================\n");

    for (a = 0; a < sumTitle; a++){
        printf("%d. #%03d-%s in %d by %s (%s)\n", a+1, title[a].bookId, title[a].bookName, title[a].bookYear, title[a].bookAuthor, title[a].bookStatus);
    }
}

void sort3()
{int a, b;
    for (a = 0; a < sumTitle-1; a++){
        for (b = 0; b < sumTitle-a-1; b++){
            if (title[b].bookYear > title[b+1].bookYear){
                struct BookList temp = title[b];
                title[b] = title[b+1];
                title[b+1] = temp;
            }
        }
    }

    printf("\n=========================================\n");
	printf("||              BOOK LIST              ||\n");
    printf("=========================================\n");

    for (a = 0; a < sumTitle; a++){
        printf("%d. #%03d-%s in %d by %s (%s)\n", a+1, title[a].bookId, title[a].bookName, title[a].bookYear, title[a].bookAuthor, title[a].bookStatus);
    }
}

void sort4()
{int a, b;
    for (a = 0; a < sumTitle-1; a++){
        for (b = 0; b < sumTitle-a-1; b++){
            if (strcmp(title[b].bookAuthor, title[b+1].bookAuthor) > 0){
                struct BookList temp = title[b];
                title[b] = title[b+1];
                title[b+1] = temp;
            }
        }
    }

    printf("\n=========================================\n");
	printf("||              BOOK LIST              ||\n");
    printf("=========================================\n");

    for (a = 0; a < sumTitle; a++){
        printf("%d. #%03d-%s in %d by %s (%s)\n", a+1, title[a].bookId, title[a].bookName, title[a].bookYear, title[a].bookAuthor, title[a].bookStatus);
    }
}

void titleList()
{FILE *fr; int sort, a, b;

    fr = fopen("Book List.txt", "r");
    sumTitle = 0;
    while (fscanf(fr, " %d#%[^#]#%d#%[^#]#%s", &title[sumTitle].bookId, title[sumTitle].bookName, &title[sumTitle].bookYear, title[sumTitle].bookAuthor, title[sumTitle].bookStatus) != EOF){
        sumTitle++;
    }
    
    do{
        printf("\n-----Book Sorting-----\n");
        printf("Sort By:\n");
        printf("1. Book ID\n");
        printf("2. Book Title\n");
        printf("3. Publication Year\n");
        printf("4. Author Name\n");
        printf("0. Back\n");
        printf("Input: ");
        scanf(" %d", &sort);
        
        switch (sort){
            case 1:
                sort1();
            case 2:
                sort2();
                break;
            case 3:
                sort3();
                break;
            case 4:
                sort4();
                break;
            case 0:
                break;
            default:
                printf("Wrong Input. Please Try Again\n\n");
                break;
        }
    } while (sort != 0);
    fclose(fr);
}

void addBook()
{FILE *fa; char titleBook[100], authorName[100], confirm; int yearBook;

    fa = fopen("Book List.txt", "a");
    awalAddBook:

    do {
        printf("\n-----Add Book-----\n");
        printf("Title Book: ");
        scanf(" %[^\n]", titleBook);
        printf("Tear Publication: ");
        scanf(" %d", &yearBook);
        printf("Author Name: ");
        scanf(" %[^\n]", authorName);
        
        printf("Do You Want To Add This Book? (Y/N)");
        printf("Input: ");
        scanf(" %c", &confirm);

        if (confirm == 'Y' || confirm == 'y'){
            title[sumTitle].bookId = sumTitle;
            strcpy(title[sumTitle].bookName, titleBook);
            title[sumTitle].bookYear = yearBook;
            strcpy(title[sumTitle].bookAuthor, authorName);
            strcpy(title[sumTitle].bookStatus, "Available");
            fprintf(fa, "%d#%s#%d#%s#%s\n", title[sumTitle].bookId, title[sumTitle].bookName, title[sumTitle].bookYear, title[sumTitle].bookAuthor, title[sumTitle].bookStatus);
            sumTitle++;
            printf("\n");
        } else if (confirm == 'N' || confirm == 'n'){
            goto awalAddBook;
        } else {
            printf("Wrong Input. Please Try Again\n\n");
        }

    } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');

}

void fineList()
{FILE *fr; int totalFine = 0;
    
    printf("\n-----Fine List-----\n");
    fr = fopen("Fine List.txt", "r");
    sumFine = 0;
    while (fscanf(fr, "%d %s %d#%[^#]#%d", &fine[sumFine].day, fine[sumFine].monthName, &fine[sumFine].year, fine[sumFine].visitorName, &fine[sumFine].fine) != EOF){
        printf("%d %s %d - %s Rp.%d,-\n", fine[sumFine].day, fine[sumFine].monthName, fine[sumFine].year, fine[sumFine].visitorName, fine[sumFine].fine);
        totalFine += fine[sumFine].fine;
        sumFine++;
    }
    printf("Total Fine: Rp%d,-\n\n", totalFine);
    fclose(fr);
}

void signinAdmin()
{char user[15], pass[15], confirm;

	signinAdmin:
	z = 0;
	printf("\n==================================================\n");
	printf("::               WELCOME ADMIN :)               ::\n");
    printf("==================================================\n");
    printf("Username: "); //username = admin
    scanf(" %s", user);
    printf("Password: "); // password = 1234
    scanf(" %s", pass);
	
    if (strcmp(adminUser, user) == 0 && strcmp(adminPass, pass) == 0){
        printf("\n");
        z++;
    } else {
        printf("Incorrect Username Or Password.\n");
        do {
            printf("\nDo You Want To Go Back? (Y/N)\n");
            printf("Input: ");
            scanf(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y'){
                printf("\n");
            } else if (confirm == 'N' || confirm == 'n'){
                goto signinAdmin;
            } else {
                printf("Wrong Input. Please Try Again\n\n");
            }
        } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');
    }
}

void admin()
{int admin;
	
	awalAdmin:
	signinAdmin();
	if (z == 0){
		goto akhirAdmin;
	}
	
    do{
		printf("List of Activity: \n");
		printf("1. Visitor List\n");
		printf("2. Book List\n");
		printf("3. Add Book\n");
        printf("4. Fine List\n");
        printf("0. Logout\n");
		printf("Input: ");
		scanf(" %d", &admin);
		switch (admin){
			case 1:
				visitorList();
                printf("\n");
				break;
			case 2:
                titleList();
                printf("\n");
				break;
			case 3:
                addBook();
				break;
            case 4:
                fineList();
                break;
            case 0:
                break;
			default:
				printf("Wrong Input. Please Try Again\n\n");
				break;
		}
	} while (admin != 0);
    
    printf("\n");
    akhirAdmin:;
}
