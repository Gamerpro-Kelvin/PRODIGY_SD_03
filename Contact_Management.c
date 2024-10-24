#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    Contact newContact;

    printf("\nEnter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number: ");
    scanf("%s", newContact.phone);

    printf("Enter email address: ");
    scanf("%s", newContact.email);

    contacts[numContacts] = newContact;
    numContacts++;

    printf("Contact added successfully.\n");
}

void viewContacts() {
    if (numContacts == 0) {
        printf("\nContact list is empty.\n");
        return;
    }

    printf("\nContact List:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n\n", contacts[i].email);
    }
}

void editContact() {
    if (numContacts == 0) {
        printf("\nContact list is empty.\n");
        return;
    }

    int index;
    printf("\nEnter the index of the contact to edit: ");
    scanf("%d", &index);

    if (index < 0 || index >= numContacts) {
        printf("Invalid index.\n");
        return;
    }

    printf("\nEnter the new name: ");
    scanf("%s", contacts[index].name);

    printf("Enter the new phone number: ");
    scanf("%s", contacts[index].phone);

    printf("Enter the new email address: ");
    scanf("%s", contacts[index].email);

    printf("Contact edited successfully.\n");
}

void deleteContact() {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    int index;
    do {
        printf("\nEnter the index of the contact to delete: ");
        scanf("%d", &index);

        if (index < 0 || index >= numContacts) {
            printf("Invalid index. Please enter a valid index.\n");
        }
    } while (index < 0 || index >= numContacts);

    for (int i = index; i < numContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    numContacts--;

    printf("Contact deleted successfully.\n");
}

void saveContactsToFile() {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < numContacts; i++) {
        fprintf(file, "%s %s %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(file);
    printf("Contacts saved to file.\n");
}

void loadContactsFromFile() {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%s %s %s", contacts[numContacts].name, contacts[numContacts].phone, contacts[numContacts].email) != EOF) {
        numContacts++;
    }

    fclose(file);
    printf("Contacts loaded from file.\n");
}

int main() {
    int choice;

    loadContactsFromFile();

    while (1) {
        printf("\n\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts to File\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                saveContactsToFile();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
