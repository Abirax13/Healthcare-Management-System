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

void addpatient();
void allpatients();
void searchpatient();
void updatepatient();
void deletepatient();
void assigndoctor();
// void alldoctors();
// void doctorasignp();
void menu();


void menu(){
    int select;
    while(1){
        printf("\n====== Healthcare Management System ======\n");
        printf("1. Add New Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient by ID\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Assign Doctor\n");
        printf("7. View All Doctors\n");
        printf("8. Doctors Asign Patient\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
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
            printf("invalid selection");
         }
    }
}


void addpatient() {

    FILE *fp = fopen("hdata.txt", "ab");

    struct Patient p;
    printf("\n--- Enter New Patient Data ---\n");
    printf("Patient ID: ");
    scanf("%d", &p.pid);
    getchar();

    printf("Patient Name: ");
    fgets(p.pname, sizeof(p.pname), stdin);
    strtok(p.pname, "\n");

    printf("Patient Age: ");
    scanf("%d", &p.page);
    getchar();

    printf("Patient Gender: ");
    fgets(p.pgender, sizeof(p.pgender), stdin);
    strtok(p.pgender, "\n");

    printf("Patient Contact: ");
    fgets(p.pphone, sizeof(p.pphone), stdin);
    strtok(p.pphone, "\n");

    printf("Patient Address: ");
    fgets(p.paddress, sizeof(p.paddress), stdin);
    strtok(p.paddress, "\n");

    printf("Patient Blood Group: ");
    fgets(p.pbloodgroup, sizeof(p.pbloodgroup), stdin);
    strtok(p.pbloodgroup, "\n");

    printf("Patient Disease: ");
    fgets(p.pdisease, sizeof(p.pdisease), stdin);
    strtok(p.pdisease, "\n");

    printf("Patient Medical History: ");
    fgets(p.phistory, sizeof(p.phistory), stdin);
    strtok(p.phistory, "\n");

    printf("Patient Admission Date (DD/MM/YYYY): ");
    fgets(p.padmitdate, sizeof(p.padmitdate), stdin);
    strtok(p.padmitdate, "\n");

    strcpy(p.pdischaredate, "N/A");
    strcpy(p.pdoctor, "Unassigned");

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    printf("Patient added successfully.\n");

    position++;
}  



void allpatients() {
    FILE *fp = fopen("hdata.txt", "rb");
    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    struct Patient p;
    int count = 0;

    printf("\n====== All Patient Records ======\n");

    while (fread(&p, sizeof(struct Patient), 1, fp)) {
        printf("\n--- Patient %d ---\n", ++count);
        printf("ID             : %d\n", p.pid);
        printf("Name           : %s\n", p.pname);
        printf("Age            : %d\n", p.page);
        printf("Gender         : %s\n", p.pgender);
        printf("Phone          : %s\n", p.pphone);
        printf("Address        : %s\n", p.paddress);
        printf("Blood Group    : %s\n", p.pbloodgroup);
        printf("Disease        : %s\n", p.pdisease);
        printf("Medical History: %s\n", p.phistory);
        printf("Doctor         : %s\n", p.pdoctor);
        printf("Admit Date     : %s\n", p.padmitdate);
        printf("Discharge Date : %s\n", p.pdischaredate);
    }

    if (count == 0)
        printf("No patient records found.\n");

    fclose(fp);
}


void searchpatient(){
    int id, found=0;

    printf("Enter Patient ID to Search: ");
    scanf("%d", &id);

    FILE *fp = fopen("hdata.txt", "rb");
    if(!fp){
        printf("File error.\n");
        return;
    }


    struct Patient p;

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.pid == id) {
            found = 1;
            printf("\n--- Patient Found ---\n");
            printf("Name: %s\nAge: %d\nGender: %s\n", p.pname, p.page, p.pgender);
            break;
        }
    }

    if (!found) printf("Patient not found.\n");

    fclose(fp);
}


void updatepatient() {
    FILE *fp = fopen("hdata.txt", "rb+"); 

    struct Patient p;
    int id, found = 0;

    printf("Enter Patient ID to update: ");
    scanf("%d", &id);
    getchar();

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.pid == id) {
            printf("\n--- Enter New Patient Data ---\n");

            printf("Patient New Name: ");
            fgets(p.pname, sizeof(p.pname), stdin);
            strtok(p.pname, "\n");

            printf("Patient New Age: ");
            scanf("%d", &p.page);
            getchar();

            printf("Patient New Gender: ");
            fgets(p.pgender, sizeof(p.pgender), stdin);
            strtok(p.pgender, "\n");

            printf("Patient New Contact: ");
            fgets(p.pphone, sizeof(p.pphone), stdin);
            strtok(p.pphone, "\n");

            printf("Patient New Address: ");
            fgets(p.paddress, sizeof(p.paddress), stdin);
            strtok(p.paddress, "\n");

            printf("Patient New Blood Group: ");
            fgets(p.pbloodgroup, sizeof(p.pbloodgroup), stdin);
            strtok(p.pbloodgroup, "\n");

            printf("Patient New Disease: ");
            fgets(p.pdisease, sizeof(p.pdisease), stdin);
            strtok(p.pdisease, "\n");

            printf("Patient New Medical History: ");
            fgets(p.phistory, sizeof(p.phistory), stdin);
            strtok(p.phistory, "\n"); 

            fseek(fp, -sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found){
        printf("Record updated successfully.\n");
    }else{
        printf("Patient not found.\n");
    }
}




void deletepatient(){
    FILE *fp = fopen("hdata.txt", "rb");

    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("File error.\n");
        return;
    }

    struct Patient p;
    int id, found = 0;


    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.pid != id) {
            fwrite(&p, sizeof(p), 1, temp);
        } else {
            found = 1;
        }
    }

    if (found) {
        fclose(fp);
        fclose(temp);

        remove("hdata.txt");
        rename("temp.dat", "hdata.txt");

    } else {
        fclose(fp);
        fclose(temp);

        remove("temp.dat");
    }


    if(found){
        printf("Record deleted successfully.\n");
    }else{
        printf("Patient not found.\n");
    }
}


void assigndoctor() {
    FILE *fp = fopen("hdata.txt", "rb+");

    struct Patient p;
    int id, found = 0;

    if (!fp) {
        printf("Unable to open file.\n");
        return;
    }

    printf("Enter Patient ID to assign doctor: ");
    scanf("%d", &id);
    getchar();

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.pid == id) {
            found = 1;

            printf("Enter Doctor's Name to assign: ");
            fgets(p.pdoctor, sizeof(p.pdoctor), stdin);
            strtok(p.pdoctor, "\n");

            printf("Enter Discharge Date (DD/MM/YYYY): ");
            fgets(p.pdischaredate, sizeof(p.pdischaredate), stdin);
            strtok(p.pdischaredate, "\n");

            fseek(fp, -sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);

            printf("Doctor assigned successfully to patient ID %d.\n", id);
            break;
        }
    }

    if (found){
        printf("Doctor assigned successfully.\n");
    }else{
        printf("Patient not found.\n", id);
    }

    fclose(fp);
}



int main(){
    menu();
    return 0;
}