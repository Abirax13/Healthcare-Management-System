#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int position=0;

struct Doctor{
    int did;
    char dname[150];
    char dgender[10];
    char dspesalized[100];
    char droom[10];
    char dtimetable[50];
    char dcontact[15];
    char daddress[200];
};

struct Patient{
    int pid;
    char pname[150];
    int page;
    char pgender[10];
    char pphone[15];
    char paddress[100];
    char pbloodgroup[5];
    char pdisease[150]; 
    char phistory[200];
    int docid;
    char pdoctor[100];
    char padmitdate[20];
    char pdischaredate[20];
};

struct addminlogin{
    char usertype[15];
    char userid[15];
    char passid[30];
};

struct TestResult{
    int patientId;
    char testName[100];
    char testResult[200];
};

struct dapoint{
    int did;
    int pid;
    char name[50];
    int age;
    char gender[20];
    char adress[100];
    int apointnum;
};

struct medicine{
    char medi[20];
    char morning[15];
    char noon[15];
    char night[15];
};

struct prescription{
    int pid;
    int count;
    struct medicine num[20];
};

void login();
void Authentication(int a);

void Receptionist();
void Administrator();
void doctorlogin();

void addlogin();
void deletelogin();

void addpatient();
void allpatients();
void searchpatient();
void updatepatient();
void deletepatient();
void assigndoctor();
void adddoctors();
void alldoctors();
void deletedoctor();
void doctorasignp();

void addpatienttest();
void viewpatienttests();
void doctorsappointment();
void appointmentprescription();
void viewprescription();
void deleteappointment();
void deleteprescription(int id);


void login(){
    while(1){
        system("cls");
        printf("\n\t====== Healthcare Management System ======\n\n");
        printf("\n\t=============== Login Page ===============\n\n");
        printf("\t1. Login as Administrator\n");
        printf("\t2. Login as Doctor\n");
        printf("\t3. Login as Receptionist\n");
        printf("\t0. Exit Program\n");
        
        printf("\t Enter a number to Login as : ");
        int a;
        scanf("%d", &a);
        getchar();

        if(a > 0 && a < 4){
            Authentication(a);
        }else if(a==0){
            system("cls");
            printf("\n\t==========----------Thank You for using Healthcare Management System----------==========\n\n");
            return;
        }else{
            printf("\tThe number you Entered is Invalid!\n\tPlease enter a valid number.\n");
        }
    }
}


void Authentication(int a) {
    int attempts = 0;
    FILE *userlogin = fopen("login.txt", "r");
    if (userlogin == NULL) {
        printf("\tThere is an error!\n\tPlease try again another time.\n");
        exit(1);
    }

    while (attempts < 3) {
        char userid[15];
        char userpass[30];

        printf("\n\tLogin Page\n\n");

        printf("\tUser Name : ");
        fgets(userid, sizeof(userid), stdin);
        strtok(userid, "\n");

        while (1) {
            printf("\tPassword  : ");
            fgets(userpass, sizeof(userpass), stdin);
            strtok(userpass, "\n");

            if (strlen(userpass) >= 8) break;
            printf("\tPassword must be 8 characters or more.\n");
        }

        struct addminlogin user;
        char line[1024];
        int found = 0;

        rewind(userlogin); // Reset file pointer to top before scanning again

        while (fgets(line, sizeof(line), userlogin)) {
            char *udata = strtok(line, "|");
            if (!udata) continue;
            strcpy(user.usertype, udata);

            udata = strtok(NULL, "|");
            if (!udata) continue;
            strcpy(user.userid, udata);

            udata = strtok(NULL, "\n");
            if (!udata) continue;
            strcpy(user.passid, udata);

            if (strcmp(userid, user.userid) == 0 && strcmp(userpass, user.passid) == 0) {
                found = 1;
                if (a == 1 && strcmp(user.usertype, "Administrator") == 0) {
                    system("cls");
                    printf("\tLogin Successful (Administrator)\n");
                    fclose(userlogin);
                    Administrator();
                    return;
                } else if (a == 2 && strcmp(user.usertype, "Doctor") == 0) {
                    system("cls");
                    printf("\tLogin Successful (Doctor)\n");
                    fclose(userlogin);
                    doctorlogin();
                    return;
                } else if (a == 3 && strcmp(user.usertype, "Receptionist") == 0) {
                    system("cls");
                    printf("\tLogin Successful (Receptionist)\n");
                    fclose(userlogin);
                    Receptionist();
                    return;
                } else {
                    printf("\tAccess denied for this user type.\n");
                    found = 2;
                    break;
                }
            }
        }

        if (found == 0) {
            printf("\tWrong User Name or Password!\n");
            attempts++;
        } else if (found == 2) {
            attempts++;
        }

        if (attempts == 3) {
            printf("\n\tToo many failed attempts. Exiting.\n");
            fclose(userlogin);
            return;
        }
    }
}




void Administrator(){
    int select;
    while(1){
        printf("\n\t====== Healthcare Management System ======\n\n");
        printf("\t1.  Add New Patient\n");
        printf("\t2.  View All Patients\n");
        printf("\t3.  Search Patient by ID\n");
        printf("\t4.  Update Patient\n");
        printf("\t5.  Delete Patient\n");
        printf("\t6.  Assign Doctor\n");
        printf("\t7.  Add New Doctor\n");
        printf("\t8.  View All Doctor\n");
        printf("\t9.  Delete Doctor\n");
        printf("\t10. View All Patient Under a Doctor\n");
        printf("\t11. Input New User.\n");
        printf("\t12. Delete User.\n");
        printf("\t13. Add Apointment.\n");
        printf("\t14. Pescribe a Patient.\n");
        printf("\t15. View Prescription.\n");
        printf("\t16. Delete Appointment.\n");
        printf("\t17. Add Patient Test.\n");
        printf("\t0. Log Out\n");
        printf("\tEnter your choice: ");
        scanf("%d", &select);
        getchar();


        if(select==1){
            addpatient();
        }else if(select==2){
            allpatients();
        }else if(select==3){
            searchpatient();
        }else if(select==4){
            updatepatient();
        }else if(select==5){
            deletepatient();
        }else if(select==6){
            assigndoctor();
        }else if(select==7){
            adddoctors();
        }else if(select==8){
            alldoctors();
        }else if(select==9){
            deletedoctor();
        }else if(select==10){
            doctorasignp();
        }else if(select==11){
            addlogin();
        }else if(select==12){
            deletelogin();
        }else if(select==13){
            doctorsappointment();
        }else if(select==14){
            appointmentprescription();
        }else if(select==15){
            viewprescription();
        }else if(select==16){
            deleteappointment();
        }else if(select==17){
            addpatienttest();
            break;
        }else if(select==0){
            return;
        }else{
            printf("\tinvalid selection");
        }
    }
}

void doctorlogin(){
    int select;
    while(1){
        printf("\n\t====== Healthcare Management System ======\n\n");
        printf("\t1.  View All Patients\n");
        printf("\t2.  Search Patient by ID\n");
        printf("\t3.  Update Patient\n");
        printf("\t4.  View apointment Patient details.\n");
        printf("\t5.  Pescribe a Patient.\n");
        printf("\t0. Log Out\n");
        printf("\tEnter your choice: ");
        scanf("%d", &select);
        getchar();

        switch(select){
            case 1:
                doctorasignp();
                break;
            case 2:
                searchpatient();
                break;
            case 3:
                updatepatient();
                break;
            case 4:
                viewprescription();
                break;
            case 5:
                appointmentprescription();
                break;
            case 0:
                return;
            default:
            printf("\tinvalid selection");
         }
    }
}


void Receptionist(){
    int select;
    while(1){
        printf("\n\t====== Healthcare Management System ======\n\n");
        printf("\t1. Add New Patient\n");
        printf("\t2. View All Patients\n");
        printf("\t3. Search Patient by ID\n");
        printf("\t4. Update Patient\n");
        printf("\t5. Delete Patient\n");
        printf("\t6. Assign Doctor\n");
        printf("\t7. Add Apointment.\n");
        printf("\t8. View Prescription.\n");
        printf("\t9. Delete Appointment.\n");
        printf("\t0. Log Out\n");
        printf("\tEnter your choice: ");
        scanf("%d", &select);
        getchar();

        switch(select){
            case 1:
                addpatient();
                break;
            case 2:
                allpatients();
                break;
            case 3:
                searchpatient();
                break;
            case 4:
                updatepatient();
                break;
            case 5:
                deletepatient();
                break;
            case 6:
                assigndoctor();
                break;
            case 7:
                doctorsappointment();
                break;
            case 8:
                viewprescription();
                break;
            case 9:
                deleteappointment();
                break;
            case 0:
                return;
            default:
            printf("\tinvalid selection");
         }
    }
}



void addpatient() {
    system("cls");

    FILE *fileforpatient = fopen("hdata.txt", "a");


    struct Patient p;
    printf("\n\t--- Enter New Patient Data ---\n\n");
    printf("\tPatient ID: ");
    scanf("%d", &p.pid);
    getchar();

    printf("\tPatient Name: ");
    fgets(p.pname, sizeof(p.pname), stdin);
    strtok(p.pname, "\n");

    printf("\tPatient Age: ");
    scanf("%d", &p.page);
    getchar();

    printf("\tPatient Gender: ");
    fgets(p.pgender, sizeof(p.pgender), stdin);
    strtok(p.pgender, "\n");

    printf("\tPatient Contact: ");
    fgets(p.pphone, sizeof(p.pphone), stdin);
    strtok(p.pphone, "\n");

    printf("\tPatient Address: ");
    fgets(p.paddress, sizeof(p.paddress), stdin);
    strtok(p.paddress, "\n");

    printf("\tPatient Blood Group: ");
    fgets(p.pbloodgroup, sizeof(p.pbloodgroup), stdin);
    strtok(p.pbloodgroup, "\n");

    printf("\tPatient Disease: ");
    fgets(p.pdisease, sizeof(p.pdisease), stdin);
    strtok(p.pdisease, "\n");

    printf("\tPatient Medical History: ");
    fgets(p.phistory, sizeof(p.phistory), stdin);
    strtok(p.phistory, "\n");

    printf("\tPatient Admission Date (DD/MM/YYYY): ");
    fgets(p.padmitdate, sizeof(p.padmitdate), stdin);
    strtok(p.padmitdate, "\n");

    strcpy(p.pdischaredate, "N/A");
    strcpy(p.pdoctor, "Unassigned");
    p.docid=000000;

    fprintf(fileforpatient, "%d|%s|%d|%s|%s|%s|%s|%s|%s|%d|%s|%s|%s\n", p.pid, p.pname, p.page, p.pgender, p.pphone, p.paddress, p.pbloodgroup, p.pdisease, p.phistory, p.docid, p.pdoctor, p.padmitdate, p.pdischaredate);

    fclose(fileforpatient);
    printf("\tPatient added successfully.\n");
}




void allpatients() {
    system("cls");

    FILE *fileforpatient = fopen("hdata.txt", "r");
    if (fileforpatient == NULL) {
        printf("\tNo patient records found.\n");
        exit(1);
    }

    struct Patient point;
    int count = 0;
    char line[1024];

    printf("\n\t====== All Patient Records ======\n");

    while (fgets(line, sizeof(line), fileforpatient)) {
        char *pdata = strtok(line, "|");
        if (pdata == NULL){
            continue;
        }
        point.pid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pname, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        point.page = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pgender, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pphone, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.paddress, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pbloodgroup, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pdisease, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.phistory, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        point.docid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pdoctor, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.padmitdate, pdata);

        pdata = strtok(NULL, "\n");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pdischaredate, pdata);

        printf("\n\t--- Patient %d ---\n", ++count);
        printf("\tID             : %d\n", point.pid);
        printf("\tName           : %s\n", point.pname);
        printf("\tAge            : %d\n", point.page);
        printf("\tGender         : %s\n", point.pgender);
        printf("\tPhone          : %s\n", point.pphone);
        printf("\tAddress        : %s\n", point.paddress);
        printf("\tBlood Group    : %s\n", point.pbloodgroup);
        printf("\tDisease        : %s\n", point.pdisease);
        printf("\tMedical History: %s\n", point.phistory);
        printf("\tDoctor         : %s\n", point.pdoctor);
        printf("\tAdmit Date     : %s\n", point.padmitdate);
        printf("\tDischarge Date : %s\n", point.pdischaredate);
    }

    fclose(fileforpatient);
}


void searchpatient() {
    system("cls");

    int id, found = 1;

    printf("\tEnter Patient ID to Search: ");
    scanf("%d", &id);

    FILE *fileforpatient = fopen("hdata.txt", "r");
    if (fileforpatient == NULL) {
        printf("\tFile error.\n");
        exit(1);
    }

    struct Patient point;
    char line[1024];

    while (fgets(line, sizeof(line), fileforpatient)) {
        char *pdata = strtok(line, "|");
        if (pdata == NULL){
            continue;
        }
        point.pid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pname, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        point.page = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pgender, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pphone, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.paddress, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pbloodgroup, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pdisease, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.phistory, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        point.docid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pdoctor, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.padmitdate, pdata);

        pdata = strtok(NULL, "\n");
        if (pdata == NULL){
            continue;
        }
        strcpy(point.pdischaredate, pdata);

        if (point.pid == id) {
            found = 0;
            printf("\n\t--- Patient Found ---\n");
            printf("\tID             : %d\n", point.pid);
            printf("\tName           : %s\n", point.pname);
            printf("\tAge            : %d\n", point.page);
            printf("\tGender         : %s\n", point.pgender);
            printf("\tPhone          : %s\n", point.pphone);
            printf("\tAddress        : %s\n", point.paddress);
            printf("\tBlood Group    : %s\n", point.pbloodgroup);
            printf("\tDisease        : %s\n", point.pdisease);
            printf("\tMedical History: %s\n", point.phistory);
            printf("\tDoctor         : %s\n", point.pdoctor);
            printf("\tAdmit Date     : %s\n", point.padmitdate);
            printf("\tDischarge Date : %s\n", point.pdischaredate);
            break;
        }
    }

    if (found) {
        printf("\tPatient not found.\n");
    }

    fclose(fileforpatient);
}





void updatepatient() {
    system("cls");

    FILE *fileforpatient = fopen("hdata.txt", "r");
    if (fileforpatient == NULL) {
        printf("\tError opening file.\n");
        exit(1);
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("\tError creating temporary file.\n");
        fclose(fileforpatient);
        exit(1);
    }

    struct Patient p;
    char line[1024];
    int id, found = 0;

    printf("\tEnter Patient ID to update: ");
    scanf("%d", &id);
    getchar();

    while (fgets(line, sizeof(line), fileforpatient)) {

        char *pdata = strtok(line, "|");
        if (pdata == NULL) continue;
        p.pid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pname, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        p.page = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pgender, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pphone, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.paddress, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pbloodgroup, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pdisease, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.phistory, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        p.docid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pdoctor, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.padmitdate, pdata);

        pdata = strtok(NULL, "\n");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pdischaredate, pdata);


        if (p.pid == id) {
            found = 1;
            printf("\n\t--- Enter New Patient Data ---\n");

            printf("\tPatient New Name: ");
            fgets(p.pname, sizeof(p.pname), stdin);
            strtok(p.pname, "\n");

            printf("\tPatient New Age: ");
            scanf("%d", &p.page);
            getchar();

            printf("\tPatient New Gender: ");
            fgets(p.pgender, sizeof(p.pgender), stdin);
            strtok(p.pgender, "\n");

            printf("\tPatient New Contact: ");
            fgets(p.pphone, sizeof(p.pphone), stdin);
            strtok(p.pphone, "\n");

            printf("\tPatient New Address: ");
            fgets(p.paddress, sizeof(p.paddress), stdin);
            strtok(p.paddress, "\n");

            printf("\tPatient New Blood Group: ");
            fgets(p.pbloodgroup, sizeof(p.pbloodgroup), stdin);
            strtok(p.pbloodgroup, "\n");

            printf("\tPatient New Disease: ");
            fgets(p.pdisease, sizeof(p.pdisease), stdin);
            strtok(p.pdisease, "\n");

            printf("\tPatient New Medical History: ");
            fgets(p.phistory, sizeof(p.phistory), stdin);
            strtok(p.phistory, "\n");
        }

        fprintf(temp, "%d|%s|%d|%s|%s|%s|%s|%s|%s|%d|%s|%s|%s\n", p.pid, p.pname, p.page, p.pgender, p.pphone, p.paddress, p.pbloodgroup, p.pdisease, p.phistory, p.docid, p.pdoctor, p.padmitdate, p.pdischaredate);
    }

    fclose(fileforpatient);
    fclose(temp);

    remove("hdata.txt");
    rename("temp.txt", "hdata.txt");

    if (found) {
        printf("\tRecord updated successfully.\n");
    } else {
        printf("\tPatient not found.\n");
    }
}



void deletepatient() {
    system("cls");

    FILE *fileforpatient = fopen("hdata.txt", "r");
    if (fileforpatient == NULL) {
        printf("\tError opening file.\n");
        exit(1);
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("\tError creating temporary file.\n");
        fclose(fileforpatient);
        exit(1);
    }

    struct Patient p;
    char line[1024];
    int id, found = 0;

    printf("\tEnter Patient ID to delete: ");
    scanf("%d", &id);
    getchar();

    while (fgets(line, sizeof(line), fileforpatient)) {

        char *pdata = strtok(line, "|");
        if (pdata == NULL) continue;
        p.pid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pname, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        p.page = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pgender, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pphone, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.paddress, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pbloodgroup, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pdisease, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.phistory, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        p.docid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pdoctor, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.padmitdate, pdata);

        pdata = strtok(NULL, "\n");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pdischaredate, pdata);

        if(p.pid == id){
            found=1;
        }

        if (p.pid != id) {

            fprintf(temp, "%d|%s|%d|%s|%s|%s|%s|%s|%s|%d|%s|%s|%s\n", p.pid, p.pname, p.page, p.pgender, p.pphone, p.paddress, p.pbloodgroup, p.pdisease, p.phistory, p.docid, p.pdoctor, p.padmitdate, p.pdischaredate);
        }

        
    }

    fclose(fileforpatient);
    fclose(temp);

    remove("hdata.txt");
    rename("temp.txt", "hdata.txt");

    if (found) {
        printf("\tPatient deleted successfully.\n");
    }else{
        printf("\tPatient ID not found.\n");
    }
}





void assigndoctor() {
    system("cls");

    FILE *fileforpatient = fopen("hdata.txt", "r");
    if (fileforpatient == NULL) {
        printf("\tError opening file.\n");
        exit(1);
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("\tError creating temporary file.\n");
        fclose(fileforpatient);
        exit(1);
    }

    FILE *filefordoctor = fopen("ddata.txt", "r");
    if(filefordoctor == NULL){
        printf("\tError Reading File.");
        exit(1);
    }
    struct Doctor point;
    struct Patient p;
    char line[1024];
    int id, found = 0;
    int did;

    printf("\tEnter Patient ID to Assign Doctor: ");
    scanf("%d", &id);
    getchar();

    while (fgets(line, sizeof(line), fileforpatient)) {

        char *pdata = strtok(line, "|");
        if (pdata == NULL) continue;
        p.pid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pname, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        p.page = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pgender, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pphone, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.paddress, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pbloodgroup, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pdisease, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.phistory, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        p.docid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if(pdata == NULL){
            continue;
        }
        strcpy(p.pdoctor, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.padmitdate, pdata);

        pdata = strtok(NULL, "\n");
        if (pdata == NULL){
            continue;
        }
        strcpy(p.pdischaredate, pdata);

        if(p.pid == id){
            found=1;
            printf("\n\tEnter Doctor Id:  ");
            scanf("%d", &did);
            getchar();

            while (fgets(line, sizeof(line), filefordoctor)) {

                char *ddata = strtok(line, "|");
                if (ddata == NULL){
                    continue;
                }
                point.did = atoi(ddata);

                ddata = strtok(NULL, "|");
                if (ddata == NULL){
                    continue;
                }
                strcpy(point.dname, ddata);

                ddata = strtok(NULL, "|");
                if (ddata == NULL){
                    continue;
                }
                strcpy(point.dgender, ddata);

                ddata = strtok(NULL, "|");
                if (ddata == NULL){
                    continue;
                }
                strcpy(point.dspesalized, ddata);

                ddata = strtok(NULL, "|");
                if (ddata == NULL){
                    continue;
                }
                strcpy(point.droom, ddata);

                ddata = strtok(NULL, "|");
                if (ddata == NULL){
                    continue;
                }
                strcpy(point.dtimetable, ddata);

                ddata = strtok(NULL, "|");
                if (ddata == NULL){
                    continue;
                }
                strcpy(point.dcontact, ddata);

                ddata = strtok(NULL, "|");
                if (ddata == NULL){
                    continue;
                }
                strcpy(point.daddress, ddata);

                if(point.did == did){
                    p.docid = point.did;
                    strcpy(p.pdoctor, point.dname);
                    strtok(p.pdoctor, "\n");
                }
                
                printf("\n\tEnter discharge date: ");
                fgets(p.pdischaredate, sizeof(p.pdischaredate), stdin);
                strtok(p.pdischaredate, "\n");
            

            }
        }
        
        fprintf(temp, "%d|%s|%d|%s|%s|%s|%s|%s|%s|%d|%s|%s|%s\n", p.pid, p.pname, p.page, p.pgender, p.pphone, p.paddress, p.pbloodgroup, p.pdisease, p.phistory, p.docid, p.pdoctor, p.padmitdate, p.pdischaredate);
        
    }

    fclose(fileforpatient);
    fclose(temp);
    fclose(filefordoctor);

    remove("hdata.txt");
    rename("temp.txt", "hdata.txt");

    if (found) {
        printf("\tDoctor successfully assigned.\n");
    }else{
        printf("\tPatient ID not found.\n");
    }
   
}


void adddoctors(){
    system("cls");
    FILE *filefordoctor;
    filefordoctor= fopen("ddata.txt", "a");
    
    struct Doctor d;
    if(filefordoctor == NULL){
        printf("Error Opening file.\n");
        exit(1);
    }


    printf("\n\t--- Enter New Doctor Data ---\n\n");
    printf("\tDoctor ID: ");
    scanf("%d", &d.did);
    getchar();

    printf("\tDoctor Name: ");
    fgets(d.dname, sizeof(d.dname), stdin);
    strtok(d.dname, "\n");


    printf("\tDoctor Gender: ");
    fgets(d.dgender, sizeof(d.dgender), stdin);
    strtok(d.dgender, "\n");

    printf("\tDoctor Specialize: ");
    fgets(d.dspesalized, sizeof(d.dspesalized), stdin);
    strtok(d.dspesalized, "\n");

    printf("\tDoctor Designated Room: ");
    fgets(d.droom, sizeof(d.droom), stdin);
    strtok(d.droom, "\n");

    printf("\tDoctor Time Schedule: ");
    fgets(d.dtimetable, sizeof(d.dtimetable), stdin);
    strtok(d.dtimetable, "\n");

    printf("\tDoctor Contact: ");
    fgets(d.dcontact, sizeof(d.dcontact), stdin);
    strtok(d.dcontact, "\n");

    printf("\tDoctor Address: ");
    fgets(d.daddress, sizeof(d.daddress), stdin);
    strtok(d.daddress, "\n");

    fprintf(filefordoctor, "%d|%s|%s|%s|%s|%s|%s|%s\n",d.did, d.dname, d.dgender, d.dspesalized, d.droom, d.dtimetable, d.dcontact, d.daddress);

    fclose(filefordoctor);
    printf("\tDoctor data has successfully Uploaded to the server.\n");
}


void alldoctors(){
    system("cls");

    FILE *filefordoctor = fopen("ddata.txt", "r");
    if (filefordoctor == NULL) {
        printf("\tNo Doctor records found.\n");
        exit(1);
    }

    struct Doctor point;
    int count = 0;
    char line[1024];

    printf("\n\t====== All Doctors Records ======\n");

    while (fgets(line, sizeof(line), filefordoctor)) {
        char *ddata = strtok(line, "|");
        if (ddata == NULL){
            continue;
        }
        point.did = atoi(ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dname, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dgender, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dspesalized, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.droom, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dtimetable, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dcontact, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.daddress, ddata);


        printf("\n\t--- Doctor %d ---\n", ++count);
        printf("\tID                : %d\n", point.did);
        printf("\tName              : %s\n", point.dname);
        printf("\tGender            : %s\n", point.dgender);
        printf("\tSpecialize        : %s\n", point.dspesalized);
        printf("\tRoom No           : %s\n", point.droom);
        printf("\tTime Schedule     : %s\n", point.dtimetable);
        printf("\tContact           : %s\n", point.dcontact);
        printf("\tAddress           : %s\n", point.daddress);
    }

    fclose(filefordoctor);
}

void deletedoctor(){
    system("cls");

    FILE *filefordoctor = fopen("ddata.txt", "r");
    if (filefordoctor == NULL) {
        printf("\tNo Doctor records found.\n");
        exit(1);
    }


    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("\tError creating temporary file.\n");
        fclose(filefordoctor);
        exit(1);
    }

    struct Doctor point;
    char line[1024];
    int id, found = 0;

    printf("\tEnter Doctor ID to delete: ");
    scanf("%d", &id);
    getchar();

    while (fgets(line, sizeof(line), filefordoctor)) {

        char *ddata = strtok(line, "|");
        if (ddata == NULL){
            continue;
        }
        point.did = atoi(ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dname, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dgender, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dspesalized, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.droom, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dtimetable, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.dcontact, ddata);

        ddata = strtok(NULL, "|");
        if (ddata == NULL){
            continue;
        }
        strcpy(point.daddress, ddata);

        if(point.did == id){
            found=1;
        }

        if (point.did != id) {

            fprintf(temp, "%d|%s|%s|%s|%s|%s|%s|%s\n",point.did, point.dname, point.dgender, point.dspesalized, point.droom, point.dtimetable, point.dcontact, point.daddress);
        }

        
    }

    fclose(filefordoctor);
    fclose(temp);

    remove("ddata.txt");
    rename("temp.txt", "ddata.txt");

    if (found) {
        printf("\tDoctor deleted successfully.\n");
    }else{
        printf("\tDoctor ID not found.\n");
    }

}

void doctorasignp() {
    system("cls");
    int doctor_id;
    int found = 0;

    printf("\tEnter Doctor's ID to view assigned patients: ");
    scanf("%d", &doctor_id);
    getchar();

    FILE *fileforpatient = fopen("hdata.txt", "r");
    if (fileforpatient == NULL) {
        printf("\tNo patient records found.\n");
        return;
    }

    struct Patient point;
    char line[1024];
    int count = 0;

    printf("\n\t====== Patients Assigned to Doctor ID: %d ======\n", doctor_id);

    while (fgets(line, sizeof(line), fileforpatient)) {
        char *pdata = strtok(line, "|");
        if (pdata == NULL) continue;
        point.pid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(point.pname, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        point.page = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(point.pgender, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(point.pphone, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(point.paddress, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(point.pbloodgroup, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(point.pdisease, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(point.phistory, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        point.docid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(point.pdoctor, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(point.padmitdate, pdata);

        pdata = strtok(NULL, "\n");
        if (pdata == NULL) continue;
        strcpy(point.pdischaredate, pdata);


        if (point.docid == doctor_id) {
            found = 1;
            printf("\n\t--- Patient %d ---\n", ++count);
            printf("\tID             : %d\n", point.pid);
            printf("\tName           : %s\n", point.pname);
            printf("\tAge            : %d\n", point.page);
            printf("\tGender         : %s\n", point.pgender);
            printf("\tPhone          : %s\n", point.pphone);
            printf("\tAddress        : %s\n", point.paddress);
            printf("\tBlood Group    : %s\n", point.pbloodgroup);
            printf("\tDisease        : %s\n", point.pdisease);
            printf("\tMedical History: %s\n", point.phistory);
            printf("\tDoctor Name    : %s\n", point.pdoctor);
            printf("\tAdmit Date     : %s\n", point.padmitdate);
            printf("\tDischarge Date : %s\n", point.pdischaredate);
        }
    }

    fclose(fileforpatient);

    if (!found) {
        printf("\n\tNo patients found for doctor ID: %d\n", doctor_id);
    }
}

// void addpatienttest() {
//     system("cls");

    
//     char patientName[150];
//     int patientId = -1; 
    
//     printf("\n\t--- Add New Patient Test Result ---\n\n");
//     printf("\tEnter Patient Name to find: ");
//     fgets(patientName, sizeof(patientName), stdin);
//     strtok(patientName, "\n");

//     FILE *patientFile = fopen("hdata.txt", "r");
//     if (patientFile == NULL) {
//         printf("Error: Patient records not found. Cannot add test results.\n");
        
//         exit(1);
//     }

//     struct Patient p;
//     char line[1024];

    
//     while (fgets(line, sizeof(line), patientFile)) {
//         char *pdata = strtok(line, "|");
//         if (pdata == NULL) continue;
//         p.pid = atoi(pdata);
        
//         pdata = strtok(NULL, "|");
//         if (pdata == NULL) continue;
//         strcpy(p.pname, pdata);

        
//         if (strcmp(p.pname, patientName) == 0) {
//             patientId = p.pid;
//             break; 
//         }
//     }
//     fclose(patientFile);

    
//     if (patientId != 0) {
//         printf("\n\tPatient not found with that name. Cannot add test results.\n");
//         exit(1);
//     }

    
//     FILE *testFile = fopen("tdata.txt", "a");
//     if(testFile == NULL){
//         printf("Error: Could not open test data file for writing.\n");
//         exit(1);
//     }
    
//     struct TestResult test;
//     test.patientId = patientId; 
    
//     printf("\tTest Name: ");
//     fgets(test.testName, sizeof(test.testName), stdin);
//     strtok(test.testName, "\n");
    
    
//     strcpy(test.testResult, "N/A");
    
//     fprintf(testFile, "%d|%s|%s\n", test.patientId, test.testName, test.testResult);
//     printf("\tTest result added successfully for patient %s (ID: %d).\n", patientName, test.patientId);
    
//     fclose(testFile);
// }



    
// void viewpatienttests(){
     
//      system("cls");

    
//     char patientName[150];
//     int patientId = -1; 

//     printf("\tEnter Patient Name to view test results: ");
//     fgets(patientName, sizeof(patientName), stdin);
//     strtok(patientName, "\n");

    
//     FILE *patientFile = fopen("hdata.txt", "r");
//     if (patientFile == NULL) {
//         printf("\tPatient records not found.\n");
//         return;
//     }

//     struct Patient p;
//     char line[1024];

    
//     while (fgets(line, sizeof(line), patientFile)) {
//         char *pdata = strtok(line, "|");
//         if (pdata == NULL) continue;
//         p.pid = atoi(pdata);
        
//         pdata = strtok(NULL, "|");
//         if (pdata == NULL) continue;
//         strcpy(p.pname, pdata);

       
//         if (strcmp(p.pname, patientName) == 0) {
//             patientId = p.pid;
//             break; 
//         }
//     }
//     fclose(patientFile);

//     if (patientId != 0) {
//         printf("\n\tPatient not found with that name.\n");
//         exit(1);
//     }

    
//     FILE *testFile = fopen("tdata.txt", "r");
//     if (testFile == NULL) {
//         printf("\tNo patient test records found.\n");
//         exit(1);
//     }

//     int found_tests = 0;
//     struct TestResult test;
//     int count = 0;

//     printf("\n\t====== Test Results for Patient: %s ======\n", patientName);

    
//     while (fgets(line, sizeof(line), testFile)) {
//         char *tdata = strtok(line, "|");
//         if (tdata == NULL) continue;
//         test.patientId = atoi(tdata);
        
//         tdata = strtok(NULL, "|");
//         if (tdata == NULL) continue;
//         strcpy(test.testName, tdata);
        
//         tdata = strtok(NULL, "\n");
//         if (tdata == NULL) continue;
//         strcpy(test.testResult, tdata);

//         if (test.patientId == patientId) {
//             found_tests = 1;
//             printf("\n\t--- Test %d ---\n", ++count);
//             printf("\tTest Name:   %s\n", test.testName);
//             printf("\tTest Result: %s\n", test.testResult);
//         }
//     }

//     fclose(testFile);

//     if (found_tests == 0) {
//         printf("\n\tNo test results found for patient: %s.\n", patientName);
//     }
// }



void doctorsappointment(){
    system("cls");

    FILE *apoint = fopen("adata.txt","a");
    if(apoint == NULL){
        printf("\tError opening file.\n");
        exit(1);
    }

    struct dapoint a;
    printf("\n\t--- Enter New Appointment ---\n\n");
    printf("\tDoctors ID: ");
    scanf("%d", &a.did);
    getchar();

    printf("\tPatient ID: ");
    scanf("%d", &a.pid);
    getchar();

    printf("\tPatient Name: ");
    fgets(a.name, sizeof(a.name), stdin);
    strtok(a.name, "\n");

    printf("\tPatient Age: ");
    scanf("%d", &a.age);
    getchar();

    printf("\tPatient Gender: ");
    fgets(a.gender, sizeof(a.gender), stdin);
    strtok(a.gender, "\n");

    printf("\tPatient Address: ");
    fgets(a.adress, sizeof(a.adress), stdin);
    strtok(a.adress, "\n");

    a.apointnum = position++;

    fprintf(apoint,"%d|%d|%s|%d|%s|%s|%d\n",a.did ,a.pid ,a.name ,a.age ,a.gender ,a.adress,a.apointnum);

    fclose(apoint);

    printf("\tApoint is successfully added.\n");
    
}


void appointmentprescription(){
    system("cls");

    FILE *prescription = fopen("presdata.txt", "a");
    if (prescription == NULL){
        printf("\tError opening file presdata.txt\n");
        exit(1);
    }

    struct prescription pres;
    int count = 0;

    printf("\n\t--- Add Prescription ---\n\n");
    printf("\tEnter Patient ID: ");
    scanf("%d", &pres.pid);
    getchar();

    printf("\tNow enter medicines (max 20). To finish enter 0 as medicine name.\n");

    for (int i = 0; i < 20; ++i) {
        printf("\n\tMedicine %d name (or 0 to finish): ", i + 1);
        fgets(pres.num[i].medi, sizeof(pres.num[i].medi), stdin);
        strtok(pres.num[i].medi, "\n");

        if (strcmp(pres.num[i].medi, "0") == 0) {
            break;
        }

        printf("\t  Morning dose/notes: ");
        fgets(pres.num[i].morning, sizeof(pres.num[i].morning), stdin);
        strtok(pres.num[i].morning, "\n");

        printf("\t  Noon dose/notes   : ");
        fgets(pres.num[i].noon, sizeof(pres.num[i].noon), stdin);
        strtok(pres.num[i].noon, "\n");

        printf("\t  Night dose/notes  : ");
        fgets(pres.num[i].night, sizeof(pres.num[i].night), stdin);
        strtok(pres.num[i].night, "\n");

        count++;
    }

    pres.count = count;

    fprintf(prescription, "%d|%d", pres.pid, pres.count);
    for (int j = 0; j < count; ++j) {
        fprintf(prescription, "|%s-%s-%s-%s", pres.num[j].medi, pres.num[j].morning, pres.num[j].noon, pres.num[j].night);
    }
    fprintf(prescription, "\n");

    fclose(prescription);

    printf("\n\tPrescription saved for patient ID %d with %d medicine(s).\n", pres.pid, count);
}


void viewprescription(){
    system("cls");
    int id;
    printf("\n\tEnter Patient ID to view prescription: ");
    scanf("%d", &id);
    getchar();


    FILE *patientFile = fopen("adata.txt", "r");
    if (patientFile == NULL) {
        printf("\tError opening file.\n");
        exit(1);
    }
    struct dapoint a;
    char line[1000];
    int foundPatient = 1;

    while (fgets(line, sizeof(line), patientFile)) {
        char *pdata = strtok(line, "|");
        if (pdata == NULL) continue;
        a.did = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        a.pid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;

        char *nl = strchr(pdata, '\n');
        if (nl) *nl = '\0';
        strcpy(a.name, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        a.age = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        nl = strchr(pdata, '\n');
        if (nl) *nl = '\0';
        strcpy(a.gender, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        nl = strchr(pdata, '\n');
        if (nl) *nl = '\0';
        strcpy(a.adress, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        a.apointnum = atoi(pdata);

        if(a.pid == id){
            printf("\n\t--- Patient Details ---\n");
            printf("\tPatitnt ID : %d \t \tDoctor ID  : %d\t \tApointment NO: %d\n", a.pid, a.did, a.apointnum);
            printf("\tName           : %s\n", a.name);
            printf("\tAge            : %d\n", a.age);
            printf("\tGender         : %s\n", a.gender);
            printf("\tAddress        : %s\n", a.adress);
            foundPatient = 0;
            break;
        }

    }
  
    fclose(patientFile);

    if (foundPatient==1) {
        printf("\tPatient not found.\n");
        return;
    }

    FILE *presFile = fopen("presdata.txt", "r");
    if (presFile == NULL) {
        printf("\n\tNo prescription data found.\n");
        fclose(presFile);
        return;
    }
    struct prescription pp;
    int foundPres = 0;
  
    while (fgets(line, sizeof(line), presFile)){
        char *pressdata = strtok(line, "|");
        if (pressdata == NULL) continue;
        pp.pid = atoi(pressdata);
      
        pressdata = strtok(NULL,"|");
        if(pressdata == NULL) continue;
        pp.count = atoi(pressdata);

        for(int i=0; i<pp.count; i++){
            char *medblock = strtok(NULL, "|");
            if (medblock == NULL) {
                pp.count = i;
                break;
            }


            char *nl = strchr(medblock, '\n');
            if (nl) *nl = '\0';


            char temp[512];
            strncpy(temp, medblock, sizeof(temp)-1);
            temp[sizeof(temp)-1] = '\0';

            char *tptr = strtok(temp, "-");
            if (tptr) strcpy(pp.num[i].medi, tptr); else pp.num[i].medi[0] = '\0';

            tptr = strtok(NULL, "-");
            if (tptr) strcpy(pp.num[i].morning, tptr); else pp.num[i].morning[0] = '\0';

            tptr = strtok(NULL, "-");
            if (tptr) strcpy(pp.num[i].noon, tptr); else pp.num[i].noon[0] = '\0';

            tptr = strtok(NULL, "-");
            if (tptr) strcpy(pp.num[i].night, tptr); else pp.num[i].night[0] = '\0';
        }

        if(pp.pid == id){
            foundPres=1;
            printf("\t \t ---------------Medication---------------            \n");
            printf("\tMedicine  -  Morning  -  Noon -  Night\n");
            for (int j = 0; j < pp.count; ++j) {
                printf("\t%d %s - %s - %s - %s\n",j, pp.num[j].medi, pp.num[j].morning, pp.num[j].noon, pp.num[j].night);
            }

        }
    }

    if(foundPres==0){
        printf("\tPrescription in not available.\n");
    }

    fclose(presFile);
}

void deleteappointment(){
    system("cls");

    FILE *fileforpatient = fopen("adata.txt", "r");
    if (fileforpatient == NULL) {
        printf("\tNo patient appointment records found.\n");
        exit(1);
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("\tError creating temporary file.\n");
        fclose(fileforpatient);
        exit(1);
    }

    struct dapoint a;
    char line[1000];
    int id, found = 0;

    printf("\tEnter Patient ID to delete appointment: ");
    scanf("%d", &id);
    getchar();

    while (fgets(line, sizeof(line), fileforpatient)) {
        char *pdata = strtok(line, "|");
        if (pdata == NULL) continue;
        a.did = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        a.pid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(a.name, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        a.age = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(a.gender, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        strcpy(a.adress, pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        a.apointnum = atoi(pdata);

        if (a.pid == id) {
            found = 1;
        } else {
            fprintf(temp, "%d|%d|%s|%d|%s|%s|%d\n",
                    a.did, a.pid, a.name, a.age, a.gender, a.adress, a.apointnum);
        }
    }

    

    fclose(fileforpatient);
    fclose(temp);

    remove("adata.txt");
    rename("temp.txt", "adata.txt");

    deleteprescription(id);

    if (found) {
        printf("\tAppointment deleted successfully.\n");
    } else {
        printf("\tPatient ID not found.\n");
    }
}


void deleteprescription(int id){
    system("cls");

    FILE *fileforpres = fopen("presdata.txt", "r");
    if (fileforpres == NULL) {
        printf("\tNo prescription records found.\n");
        exit(1);
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("\tError creating temporary file.\n");
        fclose(fileforpres);
        exit(1);
    }

    struct prescription p;
    char line[1000];
    int found = 0;


    while (fgets(line, sizeof(line), fileforpres)) {
        char *pdata = strtok(line, "|");
        if (pdata == NULL) continue;
        p.pid = atoi(pdata);

        pdata = strtok(NULL, "|");
        if (pdata == NULL) continue;
        p.count = atoi(pdata);

        if (p.pid == id) {
            found = 1;
        } else {
            fprintf(temp, "%d|%d", p.pid, p.count);

            for (int i = 0; i < p.count; i++) {
                pdata = strtok(NULL, "-");
                if (pdata == NULL) break;
                strcpy(p.num[i].medi, pdata);

                pdata = strtok(NULL, "-");
                if (pdata == NULL) break;
                strcpy(p.num[i].morning, pdata);

                pdata = strtok(NULL, "-");
                if (pdata == NULL) break;
                strcpy(p.num[i].noon, pdata);

                pdata = strtok(NULL, "|");
                if (pdata == NULL) break;
                strcpy(p.num[i].night, pdata);

                fprintf(temp, "|%s-%s-%s-%s",
                        p.num[i].medi, p.num[i].morning, p.num[i].noon, p.num[i].night);
            }
            fprintf(temp, "\n");
        }
    }

    fclose(fileforpres);
    fclose(temp);

    remove("presdata.txt");
    rename("temp.txt", "presdata.txt");

    if (found) {
        printf("\tPrescription deleted successfully.\n");
    } else {
        printf("\tPatient ID not found in prescription records.\n");
    }
}



int main(){
    login();
    return 0;
}


void addlogin(){
    system("cls");
    FILE *userlogin = fopen("login.txt", "a");

    if(userlogin ==  NULL){
        printf("\tError Opening the file.\n");
        exit(1);
    }

    struct addminlogin pass;

    printf("\n\t--- Enter New User to Login data ---\n\n");
    printf("\tUser Type       :  ");
    fgets(pass.usertype, sizeof(pass.usertype), stdin);
    strtok(pass.usertype, "\n");

    printf("\tUser ID         :  ");
    fgets(pass.userid, sizeof(pass.userid), stdin);
    strtok(pass.userid, "\n");

    printf("\tUser Password   :  ");
    while(1){
        fgets(pass.passid, sizeof(pass.passid), stdin);
        strtok(pass.passid, "\n");

        int n= strlen(pass.passid);
        if(n>=8){
            break;
        }

    }

    fprintf(userlogin, "%s|%s|%s\n",pass.usertype, pass.userid, pass.passid);

    printf("\tUser Account created sucessfully.\n");

    fclose(userlogin);
}


void deletelogin(){
    system("cls");
    
    FILE *userlogin = fopen("login.txt", "r");
    
    if(userlogin == NULL){
        printf("\tError Opeing File\n");
        exit(1);
    }

    FILE *temp = fopen("temp.txt", "w");
    
    if(temp == NULL){
        printf("\tError Opeing File\n");
        exit(1);
    }

    struct addminlogin pass;
    char line[1024];
    int  found = 0;
    char id[15];

    printf("\tEnter User ID to Delete User: ");
    fgets(id, sizeof(id), stdin);
    strtok(id, "\n");

    while (fgets(line, sizeof(line), userlogin)) {

        char *udata = strtok(line, "|");
        if (udata == NULL){
            continue;
        }
        strcpy(pass.usertype, udata);

        udata = strtok(NULL, "|");
        if (udata == NULL){
            continue;
        }
        strcpy(pass.userid, udata);

        udata = strtok(NULL, "|");
        if (udata == NULL){
            continue;
        }
        strcpy(pass.passid, udata);

        if(id == pass.userid){
            found=1;
        }else{
            fprintf(temp, "%s|%s|%s\n",pass.usertype, pass.userid, pass.passid);
        }
    }

    fclose(userlogin);
    fclose(temp);

    remove("login.txt");
    rename("temp.txt", "login.txt");

    if (found) {
        printf("\tUser deleted successfully.\n");
    }else{
        printf("\tDoctor ID not found.\n");
    }
    
}