#include<stdio.h>
#include<string.h>
#include"employee.h"

int addEmployee(){
    FILE *fp;
    Emp e1;
    fp=fopen(path,"ab");
    if (fp == NULL) {
    printf("Cannot open file.\n");
    return 1;
    }
    int ID, deptID;
    char name[40];
    float sal;
    printf("\nEnter employee ID:");
    scanf("%d", &ID);
    getchar();
    printf("Enter Employee Name:");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter department ID:");
    scanf("%d", &deptID);
    printf("Enter basic salary:");
    scanf("%f", &sal);
    e1.empId=ID;
    strcpy(e1.name,name);
    e1.deptId=deptID;
    e1.basicSalary=sal;
    fwrite(&e1, sizeof(e1),1,fp);
    fclose(fp);
    printf("Record added successfully");
    return 0;
}

int displayAllEmployees(){
    FILE *fp;
    fp=fopen(path,"rb");
    Emp e1;
    if (fp == NULL) {
    printf("Cannot open file.\n");
    return 1;
    }
    printf("--------------------------------------------------------\n");
    printf("%-8s %-20s %-10s %-12s\n","ID","Name","Dept. ID","Basic Salary");
    printf("--------------------------------------------------------\n");
    while(fread(&e1,sizeof(e1),1,fp)){
    printf("%-8d %-20s %-10d %-12f\n", e1.empId,e1.name,e1.deptId,e1.basicSalary);
    }
    fclose(fp);
    return 0;
}

int searchEmployee(){
    int sc, found=0;
    FILE *fp;
    fp=fopen(path,"rb");
    Emp e1;
    if (fp == NULL) {
    printf("Cannot open file.\n");
    return 1;
    }
    printf("\n1. Search by employee ID\n2. Search by Department ID\n3. Search by Salary Range\nEnter Choice:");
    scanf("%d",&sc);
    switch(sc){
        case 1:
            int id=0;
            printf("\nEnter employee ID to search:");
            scanf("%d",&id);
            printf("--------------------------------------------------------\n");
            printf("%-8s %-20s %-10s %-12s\n","ID","Name","Dept. ID","Basic Salary");
            printf("--------------------------------------------------------\n");
            while(fread(&e1,sizeof(e1),1,fp)){
                if(e1.empId==id){
                    printf("%-8d %-20s %-10d %-12f\n", e1.empId,e1.name,e1.deptId,e1.basicSalary);
                    found =1;
                    break;
                }
            }
            break;
        case 2:
            int did=0;
            printf("\nEnter Department ID to search:");
            scanf("%d",&id);
            printf("--------------------------------------------------------\n");
            printf("%-8s %-20s %-10s %-12s\n","ID","Name","Dept. ID","Basic Salary");
            printf("--------------------------------------------------------\n");
            while(fread(&e1,sizeof(e1),1,fp)){
                if(e1.deptId==did){
                    found=1;
                    printf("%-8d %-20s %-10d %-12f\n", e1.empId,e1.name,e1.deptId,e1.basicSalary);
                }
            }
            break;
        case 3:
            float min=0.0, max=0.0;
            printf("\nEnter Lower Value of Salary Search Range:");
            scanf("%f",&min);
            printf("\nEnter Higher Value of Salary Search Range:");
            scanf("%f",&max);
            printf("--------------------------------------------------------\n");
            printf("%-8s %-20s %-10s %-12s\n","ID","Name","Dept. ID","Basic Salary");
            printf("--------------------------------------------------------\n");
            while(fread(&e1,sizeof(e1),1,fp)){
                if((e1.basicSalary>=min)&&(e1.basicSalary<=max)){
                    found=1;
                    printf("%-8d %-20s %-10d %-12f\n", e1.empId,e1.name,e1.deptId,e1.basicSalary);
                }
            }
            break;
        default: 
            found=1;
            printf("\nPlease Enter a valid choice");
            break;
    }
    if(found!=1){printf("No record found\n");}
    return 0;
}

int updateEmployee(){
    Emp e1;
    int eid=0;
    FILE *fpr;
    FILE *fpw;
    fpr=fopen(path,"rb");
    fpw=fopen("../data/temp.dat","ab");
    printf("\nEnter employee ID to modify:");
    scanf("%d",&eid);
    while(fread(&e1,sizeof(e1),1,fpr)){
        if(e1.empId==eid){
            int c=0;
            printf("\n1. Modify Department ID\n2. Modify Basic Salary\nEnter Choice:");
            scanf("%d",&c);
            switch(c){
                case 1:
                    int did=0;
                    printf("\nEnter new dept ID:");
                    scanf("%d",&did);
                    e1.deptId=did;
                    break;
                case 2:
                    float sal=0.0;
                    printf("\nEnter new Salary:");
                    scanf("%f",&sal);
                    e1.basicSalary=sal;
                    break;
                default:
                    printf("\nEnter valid choice");
                    break;
            }
        }
        fwrite(&e1,sizeof(e1),1,fpw);
    }
    fclose(fpw);
    fclose(fpr);
    remove(path);                
    rename("../data/temp.dat", path); 
    return 0;
}

int deleteEmployee(){
    Emp e1;
    int eid=0;
    FILE *fpr;
    FILE *fpw;
    fpr=fopen(path,"rb");
    fpw=fopen("../data/temp.dat","ab");
    printf("\nEnter employee ID to delete:");
    scanf("%d",&eid);
    while(fread(&e1,sizeof(e1),1,fpr)){
        if(e1.empId!=eid){
            fwrite(&e1,sizeof(e1),1,fpw);
        }
    }
    fclose(fpw);
    fclose(fpr);
    remove(path);                
    rename("../data/temp.dat", path); 
    return 0;
}

int main(){
    //addEmployee(path);
    displayAllEmployees();
    //searchEmployee(path);
    //updateEmployee(path);
    return 0;
}
