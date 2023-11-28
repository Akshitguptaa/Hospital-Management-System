#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max_p 100
#define max_a 10
#define max_d 100
#define MAX_ATTEMPTS 5
#define MAX_LENGTH 10

// structure for patient

typedef struct patient
{
    int id;
    char name[50];
    int age;
    char address[100];
    char contact_number[15];
} p;

// structure for appointment

typedef struct appointment
{
    int id;
    int patient_id;
    char date_time[50];
    char department[50];
} a;

// structure for doctor

typedef struct doctor
{
    int id;
    char name[50];
    char address[50];
    char specialize[50];
    char date[12];
} d;

// function to enter password

int enterpass(const char *pass)
{
    int attempt = 0;
    char inputpass[MAX_LENGTH];
    int flag = 0;

    do
    {
        printf("Enter the password to continue-->  ");
        fgets(inputpass, MAX_LENGTH, stdin);

        inputpass[strcspn(inputpass, "\n")] = '\0';

        if (strncmp(inputpass, pass, MAX_LENGTH) == 0)
        {
            printf("Access granted!\n");
            flag = 1;
            break;
        }
        else
        {
            printf("Access denied,Press any key to Try again..\n");
            attempt++;
        }
        while (getchar() != '\n')
            ;

    } while (attempt < MAX_ATTEMPTS);

    if (!flag)
    {
        printf("Maximum attempt reached.\n");
    }

    return flag;
}

void new_p();

void display_patients();

void update_patient();

void delete_patient();

void new_a();

void display_a();

void update_a();

void delete_a();

void new_d();

void display_d();

void update_d();

void delete_d();

void search_p();

void search_d();

void search_a();

void search_a_name();

void search_d_name();

void search_p_name();

int main()
{
    const char pass[] = "JIIT123";
    p patients[max_p];
    a appointments[max_a];
    a doctors[max_d];
    int a_count = 0;
    int p_count = 0;
    int d_count = 0;
    printf("Welcome to Hospital management system!!\n\n");

    if (!enterpass(pass))
    {
        printf("Exiting..\n");
    }
    else
    {
        printf("Continue--->  \n\n");
        while (1)
        {
            int choice;

            printf("######## Welcome to the Hospital Management System! ########\n\n");
            printf("Enter the digit from 0-6 for selecting the operation you want to perform-->  \n");
            printf("1. Add Patient\n");
            printf("2. Display Patient\n");
            printf("3. Update Patient\n");
            printf("4. Delete from Patient\n");
            printf("5. Add Appointment\n");
            printf("6. Display Appointment list\n");
            printf("7. Update Appointment data\n");
            printf("8. Delete from Appointment\n");
            printf("9. Add Doctor\n");
            printf("10. Display Doctor list\n");
            printf("11. Update Doctor list\n");
            printf("12. Delete from Doctor data\n");
            printf("13. Search Patient by Patient id\n");
            printf("14. Search Doctor by Doctor id\n");
            printf("15. Search Appointments by Patient id\n");
            printf("0. Exit\n");
            scanf("%d", &choice);

            switch (choice)
            {

            case 1:
                if (p_count < max_p)
                {
                    new_p(patients, &p_count);
                }
                else
                {
                    printf("Patient Database is Full.\n");
                }
                break;

            case 2:
                display_patients(patients, p_count);
                break;

            case 3:
                update_patient(patients, p_count);
                break;


            case 4:
                delete_patient(patients, &p_count);
                break;


            case 5:
                if (a_count < max_a)
                {
                    new_a(appointments, &a_count);
                }
                else
                {
                    printf("Apointments full.\n");
                }
                break;

            case 6:
                display_a(appointments, a_count);
                break;

            case 7:
                update_a(appointments, a_count);
                break;

            case 8:
                delete_a(appointments, &a_count);
                break;

            case 9:
                if (d_count < max_d) 
                {
                    new_d(doctors, &d_count);
                } 
                else 
                {
                    printf("Doctors database is full.\n");
                }
                break;

            case 10:
                display_d(doctors, d_count);
                break;

            case 11:
                update_d(doctors, d_count);
                break;
            
            case 12:
                delete_d(doctors, &d_count);
                break;

            case 13:
                search_p(patients, p_count);
                break;
                
            case 14:
                search_d(doctors, d_count);
                break;

            case 15: 
                search_a(appointments, a_count);
                break;
            
            case 16:
                search_p_name(patients, p_count);
                break; 

            case 17:
                search_d_name(doctors, d_count);
                break;

            case 18:
                search_a_name(appointments, a_count, patients, p_count);
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
            }
            char buffer[2];
            printf("\nEnter any key to continue...");
            fgets(buffer, 2, stdin);
        }
    }

    return 0;
}

// function to input a new patient

void new_p(p patients[], int *p_count)
{
    printf("\n Enter patient details---->>>\n");
    printf("Enter patient ID-->  ");
    scanf("%d", &patients[*p_count].id);
    getchar();
    printf("Enter patient name-->  ");
    fgets(patients[*p_count].name, 50, stdin);
    printf("Enter patient age-->  ");
    scanf("%d", &patients[*p_count].age);
    getchar();
    printf("Enter patient address-->  ");
    fgets(patients[*p_count].address, 100, stdin);
    printf("Enter patient contact number-->  ");
    fgets(patients[*p_count].contact_number, 15, stdin);
    *p_count += 1;
}

// function for displaying patients data

void display_patients(p patients[], int p_count) 
{
    if (p_count == 0) 
    {
        printf("No patients found.\n");
        return;
    }

    printf("\n--- Patient Database ---\n");
    for (int i = 0; i < p_count; i++) 
    {
        printf("\nPatient ID-->  %d\n", patients[i].id);
        printf("Name-->  %s", patients[i].name);
        printf("Age-->  %d\n", patients[i].age);
        printf("Address-->  %s", patients[i].address);
        printf("Contact Number-->  %s\n", patients[i].contact_number);
    }
}

// function for updating patient data

void update_patient(p patients[], int p_count) 
{
    int patientID;
    printf("Enter the patient ID to update-->  ");
    scanf("%d", &patientID);
    getchar(); 

    int found = 0;
    for (int i = 0; i < p_count; i++) 
    {
        if (patients[i].id == patientID) 
        {
            printf("Enter updated patient name-->  ");
            fgets(patients[i].name, 50, stdin);
            printf("Enter updated patient age-->  ");
            scanf("%d", &patients[i].age);
            getchar(); 
            printf("Enter updated patient address-->  ");
            fgets(patients[i].address, 100, stdin);
            printf("Enter updated patient contact number-->  ");
            fgets(patients[i].contact_number, 15, stdin);
            printf("Patient details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found with ID-->  %d\n", patientID);
    }
}

// function for deleting patient data

void delete_patient(p patients[], int *p_count) 
{
    int patientID;
    printf("Enter the patient ID to delete-->  ");
    scanf("%d", &patientID);
    getchar(); 

    int found = 0;
    for (int i = 0; i < *p_count; i++) 
    {
        if (patients[i].id == patientID) 
        {
            // Replace the matched patient with the last patient in the array
        
            patients[i] = patients[(*p_count) - 1];
            (*p_count)--;
            printf("Patient deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Patient not found with ID-->  %d\n", patientID);
    }
}

//function for taking new appoinntment

void new_a(a appointments[], int *a_count)
{
    printf("\nEnter appointment details ---->>>\n");
    printf("Enter appointment ID-->  ");
    scanf("%d", &appointments[*a_count].id);
    getchar();
    printf("Enter patient ID-->  ");
    scanf("%d", &appointments[*a_count].patient_id);
    getchar();
    printf("Enter date and time-->  ");
    fgets(appointments[*a_count].date_time, 50, stdin);
    printf("Enter department-->  ");
    fgets(appointments[*a_count].department, 50, stdin);
    *a_count += 1;
}

// function to display appointment list

void display_a(a appointments[], int a_count) 
{
    if (a_count == 0) 
    {
        printf("No appointments found.\n");
        return;
    }

    printf("\n--- Appointment Database ---\n");
    for (int i = 0; i < a_count; i++) 
    {
        printf("\nAppointment ID: %d\n", appointments[i].id);
        printf("Patient ID: %d\n", appointments[i].patient_id);
        printf("Date & Time: %s", appointments[i].date_time);
        printf("Department: %s", appointments[i].department);
    }
}

// function to update appointment list

void update_a(a appointments[], int a_count) 
{
    int appointmentID;
    printf("Enter the appointment ID to update: ");
    scanf("%d", &appointmentID);
    getchar();

    int found = 0;
    for (int i = 0; i < a_count; i++) 
    {
        if (appointments[i].id == appointmentID) 
        {
            printf("Enter updated date and time: ");
            fgets(appointments[i].date_time, 50, stdin);
            printf("Enter updated department: ");
            fgets(appointments[i].department, 50, stdin);
            printf("Appointment details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Appointment not found with ID: %d\n", appointmentID);
    }
}

// function to delete appointment

void delete_a(a appointments[], int *a_count) 
{
    int appointmentID;
    printf("Enter the appointment ID to delete: ");
    scanf("%d", &appointmentID);
    getchar();

    int found = 0;
    for (int i = 0; i < *a_count; i++) 
    {
        if (appointments[i].id == appointmentID) 
        {
            appointments[i] = appointments[(*a_count) - 1];
            (*a_count)--;
            printf("Appointment deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Appointment not found with ID: %d\n", appointmentID);
    }
}

// function for adding new doctor

void new_d(d doctors[], int *d_count) 
{
    if (*d_count >= max_d) 
    {
        printf("Doctor's database is full.\n");
        return;
    }

    printf("\nEnter doctor details--> \n");
    printf("Enter doctor ID-->  ");
    scanf("%d", &doctors[*d_count].id);
    getchar(); 
    printf("Enter doctor name-->  ");
    fgets(doctors[*d_count].name, 50, stdin);
    printf("Enter doctor address-->  ");
    fgets(doctors[*d_count].address, 50, stdin);
    printf("Enter doctor specialization-->  ");
    fgets(doctors[*d_count].specialize, 50, stdin);
    printf("Enter doctor joining date-->  ");
    fgets(doctors[*d_count].date, 12, stdin);

    (*d_count)++;
    printf("Doctor added successfully!\n");
}

// function for displaying doctor database

void display_d(d doctors[], int d_count) 
{
    if (d_count == 0) 
    {
        printf("No doctors found.\n");
        return;
    }

    printf("\n--- Doctors Database ---\n");
    for (int i = 0; i < d_count; i++) 
    {
        printf("\nDoctor ID-->  %d\n", doctors[i].id);
        printf("Name-->  %s", doctors[i].name);
        printf("Address-->  %s", doctors[i].address);
        printf("Specialization-->  %s", doctors[i].specialize);
        printf("Joining Date-->  %s\n", doctors[i].date);
    }
}

// function to update doctor list

void update_d(d doctors[], int d_count) 
{
    int doctorID;
    printf("Enter the doctor ID to update: ");
    scanf("%d", &doctorID);
    getchar(); 

    int found = 0;
    for (int i = 0; i < d_count; i++) 
    {
        if (doctors[i].id == doctorID) 
        {
            printf("Enter updated doctor name: ");
            fgets(doctors[i].name, 50, stdin);
            printf("Enter updated doctor address: ");
            fgets(doctors[i].address, 50, stdin);
            printf("Enter updated doctor specialization: ");
            fgets(doctors[i].specialize, 50, stdin);
            printf("Enter updated doctor joining date: ");
            fgets(doctors[i].date, 12, stdin);
            printf("Doctor details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Doctor not found with ID: %d\n", doctorID);
    }
}

// function for deleting doctor data

void delete_d(d doctors[], int *d_count) 
{
    int doctorID;
    printf("Enter the doctor ID to delete-->  ");
    scanf("%d", &doctorID);
    getchar(); 

    int found = 0;
    for (int i = 0; i < *d_count; i++) 
    {
        if (doctors[i].id == doctorID) 
        {
            // Replace the matched doctor with the last doctor in the array

            doctors[i] = doctors[(*d_count) - 1];
            (*d_count)--;
            printf("Doctor deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Doctor not found with ID-->  %d\n", doctorID);
    }
}

// function to search for a specific patient by ID

void search_p(p patients[], int p_count) 
{
    int patientID;
    printf("Enter the patient ID to search-->  ");
    scanf("%d", &patientID);
    getchar(); 

    int found = 0;
    for (int i = 0; i < p_count; i++) 
    {
        if (patients[i].id == patientID) 
        {
            printf("\n--- Patient Found ---\n");
            printf("Patient ID-->  %d\n", patients[i].id);
            printf("Name-->  %s", patients[i].name);
            printf("Age-->  %d\n", patients[i].age);
            printf("Address-->  %s", patients[i].address);
            printf("Contact Number-->  %s\n", patients[i].contact_number);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Patient not found with ID-->  %d\n", patientID);
    }
}

// function to search for a specific doctor by ID

void search_d(d doctors[], int d_count) 
{
    int doctorID;
    printf("Enter the doctor ID-->  ");
    scanf("%d", &doctorID);
    getchar(); 

    int found = 0;
    for (int i = 0; i < d_count; i++) 
    {
        if (doctors[i].id == doctorID) 
        {
            printf("\n--- Doctor Found ---\n");
            printf("Doctor ID-->  %d\n", doctors[i].id);
            printf("Name-->  %s", doctors[i].name);
            printf("Address-->  %s", doctors[i].address);
            printf("Specialization-->  %s", doctors[i].specialize);
            printf("Joining Date-->  %s\n", doctors[i].date);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Doctor not found with ID-->  %d\n", doctorID);
    }
}

// function to search appointment by appointment id

void search_a(a appointments[], int a_count) 
{
    int patientID;
    printf("Enter the patient ID to search appointments-->  ");
    scanf("%d", &patientID);
    getchar(); 

    int found = 0;
    printf("\n--- Appointments for Patient ID %d ---\n", patientID);
    for (int i = 0; i < a_count; i++) 
    {
        if (appointments[i].patient_id == patientID) 
        {
            printf("\nAppointment ID-->  %d\n", appointments[i].id);
            printf("Date & Time-->  %s", appointments[i].date_time);
            printf("Department-->  %s", appointments[i].department);
            found = 1;
        }
    }

    if (!found) 
    {
        printf("No appointments found for Patient ID %d\n", patientID);
    }
}

// function to search for a patient by name
void search_p_name(p patients[], int p_count) 
{
    char searchName[50];
    printf("Enter the patient name to search-->  ");
    fgets(searchName, 50, stdin);
    int found = 0;

    printf("\n--- Patients with Name \"%s\" ---\n", searchName);
    for (int i = 0; i < p_count; i++) 
    {
        if (strstr(patients[i].name, searchName) != NULL) 
        {
            printf("\nPatient ID-->  %d\n", patients[i].id);
            printf("Name-->  %s", patients[i].name);
            printf("Age-->  %d\n", patients[i].age);
            printf("Address-->  %s", patients[i].address);
            printf("Contact Number-->  %s\n", patients[i].contact_number);
            found = 1;
        }
    }

    if (!found) 
    {
        printf("No patients found with the name \"%s\"\n", searchName);
    }
}

// function to search for a doctor by name

void search_d_name(d doctors[], int d_count) 
{
    char searchName[50];
    printf("Enter the doctor name to search: ");
    fgets(searchName, 50, stdin);
    int found = 0;

    printf("\n--- Doctors with Name \"%s\" ---\n", searchName);
    for (int i = 0; i < d_count; i++) 
    {
        if (strstr(doctors[i].name, searchName) != NULL) 
        {
            printf("\nDoctor ID-->  %d\n", doctors[i].id);
            printf("Name-->  %s", doctors[i].name);
            printf("Address-->  %s", doctors[i].address);
            printf("Specialization-->  %s", doctors[i].specialize);
            printf("Joining Date-->  %s\n", doctors[i].date);
            found = 1;
        }
    }

    if (!found) 
    {
        printf("No doctors found with the name \"%s\"\n", searchName);
    }
}

// function to search appointments by patient name

void search_a_name(a appointments[], int a_count, p patients[], int p_count) 
{
    char searchName[50];
    printf("Enter the patient name to search appointments-->  ");
    fgets(searchName, 50, stdin);
    int found = 0;

    printf("\n--- Appointments for Patient \"%s\" ---\n", searchName);
    for (int i = 0; i < a_count; i++) 
    {
        for (int j = 0; j < p_count; j++) 
        {
            if (appointments[i].patient_id == patients[j].id && strstr(patients[j].name, searchName) != NULL) 
            {
                printf("\nAppointment ID-->  %d\n", appointments[i].id);
                printf("Date & Time-->  %s", appointments[i].date_time);
                printf("Department-->  %s", appointments[i].department);
                found = 1;
            }
        }
    }

    if (!found) 
    {
        printf("No appointments found for Patient \"%s\"\n", searchName);
    }
}