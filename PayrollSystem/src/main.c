#include<stdio.h>
#include"employee.h"
#include"department.h"

int main(){
    printf("===============================\n");
    printf("        PAYROLL SYSTEM\n");
    printf("===============================");
    int check = 1, choice;
    while(check==1){
        printf("\n-----------------\n");
        printf("    Main Menu\n");
        printf("-----------------\n");
        printf("1. Department Management\n");
        printf("2. Employee Management\n");
        printf("3. Payroll\n");
        printf("0. To Quit Program\n");
        printf("Enter Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Quitting....");
                check=0;
                break;
            case 1: //Dept Menu
                int x=0;
                printf("\n-----------------\n");
                printf("1. Add Department\n"
                       "2. Display Department\n"
                       "3. Search Department\n"
                       "4. Update Department\n"
                       "5. Delete Department\n"
                       "6. Back\n"
                       "Enter Choice:");
                scanf("%d",&x);
                switch(x){
                    case 1: //Add Department UnderDev
                        printf("Adding Deprartment");
                        break;
                    case 2://Display Department UnderDev
                        printf("Display Department");
                        break;
                    case 3://Search Department UnderDev
                        printf("Search Deprartment");
                        break;
                    case 4://Update Department UnderDev
                        printf("Update Deprartment");
                        break;
                    case 5://Delete Department UnderDev
                        printf("Delete Deprartment");
                        break;
                    case 6:
                        //No message for backing, intentional
                        break;
                    default:
                        printf("Enter Valid Choice");
                        break;
                }
            break;
            case 2://Employee Menu
                x=0;
                int a=0;
                printf("\n-----------------\n");
                printf("1. Add Employee\n"
                       "2. Display Employee\n"
                       "3. Search Employee\n"
                       "4. Update Employee\n"
                       "5. Delete Employee\n"
                       "6. Back\n"
                       "Enter Choice:");
                scanf("%d",&x);
                switch(x){
                    case 1: //Add Employee UnderDev
                        printf("Adding Employee");
                        printf("\nEnter the number of records to add:");
                        scanf("%d",&a);
                        for(int i=0;i<a;i++){
                            addEmployee();
                        }
                        break;
                    case 2://Display Employee UnderDev
                        printf("Display Employee");
                        displayAllEmployees();
                        break;
                    case 3://Search Employee UnderDev
                        printf("Search Employee");
                        printf("Enter number of searches to perform:");
                        scanf("%d",&a);
                        for(int i=0;i<a;i++){
                            searchEmployee();
                        }
                        break;
                    case 4://Update Employee UnderDev
                        printf("Update Employee");
                        printf("Enter number of modifications to be done:");
                        scanf("%d",&a);
                        for(int i=0;i<a;i++){
                            updateEmployee();
                        }
                        break;
                    case 5://Delete Employee UnderDev
                        printf("Delete Employee");
                        printf("Enter number of records to delete:");
                        scanf("%d",&a);
                        for(int i=0;i<a;i++){
                            deleteEmployee();
                        }
                        break;
                    case 6:
                        //No message for backing, intentional
                        break;
                    default:
                        printf("Enter Valid Choice");
                        break;
                }
            break;
            case 3: //Payroll Menu
                x=0;
                printf("\n-----------------\n");
                printf("1. Generate Payroll\n"
                       "2. View Payroll\n"
                       "3. Search Payroll\n"
                       "4. Summary\n"
                       "5. Back\n"
                       "Enter Choice:");
                scanf("%d",&x);
                switch(x){
                    case 1: //Generate Payroll
                        printf("Generate Payroll");
                        break;
                    case 2://View Payroll
                        printf("View Payroll");
                        break;
                    case 3://Search Payroll
                        printf("Search Payroll");
                        break;
                    case 4://Summary
                        printf("Summary");
                        break;
                    case 5://Back
                        //No message for backing, intentional
                        break;
                    default:
                        printf("Enter Valid Choice");
                        break;
                }
            break;
            default:
                printf("Please Enter a Valid choice\n");
                break;
            
        }
    }
    return 0;
}