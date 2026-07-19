 #include"employee.h"
 #include"fileutil.h"
 #include"department.h"
 #include<stdio.h>

 int employeeExists(int id){
    FILE *fp;
    Emp e1;
    fp=fopen(path,"rb");
    while(fread(&e1,sizeof(e1),1,fp)){
        if(e1.empId==id){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
 }

 int deptExists(int id){
    FILE *fp;
    Dept d1;
    fp=fopen(dept_path,"rb");
    while(fread(&d1,sizeof(d1),1,fp)){
        if(d1.deptId==id){
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
 }