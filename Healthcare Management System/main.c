#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int position=0;

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
    char pdoctor[100];
    char padmitdate[20];
    char pdischaredate[20];
};

void login();
void addpatient();
void allpatients();
void searchpatient();
void updatepatient();
void deletepatient();
void assigndoctor();
void alldoctors();
// void doctorasignp();
void menu();


void menu(){
    int select;
    while(1){
        printf("\n\t====== Healthcare Management System ======\n\n");
        printf("\t1. Add New Patient\n");
        printf("\t2. View All Patients\n");
        printf("\t3. Search Patient by ID\n");
        printf("\t4. Update Patient\n");
        printf("\t5. Delete Patient\n");
        printf("\t6. Assign Doctor\n");
        printf("\t7. View All Doctors\n");
        printf("\t8. Doctors Asign Patient\n");
        printf("\t0. Exit\n");
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
            // case 7:
            //     alldoctors();
            //     break;
            // case 8:
            //     doctorasignp();
            //     break;
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

    fprintf(fileforpatient, "%d|%s|%d|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
            p.pid, p.pname, p.page, p.pgender, p.pphone, p.paddress,
            p.pbloodgroup, p.pdisease, p.phistory, p.pdoctor, p.padmitdate, p.pdischaredate);

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

        fprintf(temp, "%d|%s|%d|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", p.pid, p.pname, p.page, p.pgender, p.pphone, p.paddress, p.pbloodgroup, p.pdisease, p.phistory, p.pdoctor, p.padmitdate, p.pdischaredate);
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

            fprintf(temp, "%d|%s|%d|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", p.pid, p.pname, p.page, p.pgender, p.pphone, p.paddress, p.pbloodgroup, p.pdisease, p.phistory, p.pdoctor, p.padmitdate, p.pdischaredate);
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
            printf("\tEnter Doctor's Name to assign: ");
            fgets(p.pdoctor, sizeof(p.pdoctor), stdin);
            strtok(p.pdoctor, "\n");

            printf("\tEnter Discharge Date (DD/MM/YYYY): ");
            fgets(p.pdischaredate, sizeof(p.pdischaredate), stdin);
            strtok(p.pdischaredate, "\n");

        }

        fprintf(temp, "%d|%s|%d|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", p.pid, p.pname, p.page, p.pgender, p.pphone, p.paddress, p.pbloodgroup, p.pdisease, p.phistory, p.pdoctor, p.padmitdate, p.pdischaredate);

    }

    fclose(fileforpatient);
    fclose(temp);

    remove("hdata.txt");
    rename("temp.txt", "hdata.txt");

    if (found) {
        printf("\tDoctor successfully assigned.\n");
    }else{
        printf("\tPatient ID not found.\n");
    }
   
}





void alldoctors(){
    FILE *filefordoctor;
    filefordoctor= fopen("ddata.txt", "w");

    if(filefordoctor == NULL){
        printf("Error Opening file.\n");
        exit(1);
    }
    
}


int main(){
    menu();
    return 0;
}
