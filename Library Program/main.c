#include "admin.h"
#include "visitor.h"
#include <stdio.h>
int main()
{int login;
    
    //masuk sebagai admin atau visitor (pengunjung)
    do{
    	printf("==================================================\n");
	    printf("::          WELCOME TO BINUSIAN LIBRARY         ::\n");
        printf("==================================================\n");
		printf("LOGIN AS: \n");
		printf("1. Admin\n");
		printf("2. Visitor\n");
        printf("0. Exit\n");
		printf("Input: ");
		scanf(" %d", &login);
		switch (login){
			case 1:
				admin(); //menuju fungsi admin di file admin.h
				break;
			case 2:
				visitor(); //menuju fungsi admin di file visitor.h
				break;
            case 0:
                break;
			default:
				printf("Wrong Input. Please Try Again\n\n");
				break;
		}
	} while (login != 0);
	
    printf("\n==================================================\n");
	printf("::   Remember Always To Take Care Your Health   ::\n");
    printf("::  Thanks For Visiting Us. Have A Nice Day :)  ::\n");
    printf("==================================================\n");

	return 0;
}