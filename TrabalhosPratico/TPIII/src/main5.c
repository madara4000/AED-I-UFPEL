
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 10
#define PHONE_SIZE 20

void add_person(void *pBuffer, int *count) {
    char *name = (char *)pBuffer + (*count) * (NAME_SIZE + PHONE_SIZE + sizeof(int));
    char *phone = name + NAME_SIZE;
    int *age = (int *)(phone + PHONE_SIZE);

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone: ");
    scanf("%s", phone);
    printf("Enter age: ");
    scanf("%d", age);

    (*count)++;
}

void remove_person(void *pBuffer, int *count) {
    char *name = (char *)pBuffer + (*count) * (NAME_SIZE + PHONE_SIZE + sizeof(int));
    printf("Enter name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        char *person_name = (char *)pBuffer + i * (NAME_SIZE + PHONE_SIZE + sizeof(int));
        if (strcmp(person_name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                char *current = (char *)pBuffer + j * (NAME_SIZE + PHONE_SIZE + sizeof(int));
                char *next = (char *)pBuffer + (j + 1) * (NAME_SIZE + PHONE_SIZE + sizeof(int));
                memcpy(current, next, NAME_SIZE + PHONE_SIZE + sizeof(int));
            }
            (*count)--;
            printf("Person removed.\n");
            return;
        }
    }
    printf("Person not found.\n");
}

void search_person(void *pBuffer, int count) {
    char *name = (char *)pBuffer + count * (NAME_SIZE + PHONE_SIZE + sizeof(int));
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        char *person_name = (char *)pBuffer + i * (NAME_SIZE + PHONE_SIZE + sizeof(int));
        if (strcmp(person_name, name) == 0) {
            char *phone = person_name + NAME_SIZE;
            int *age = (int *)(phone + PHONE_SIZE);
            printf("Name: %s\n", person_name);
            printf("Phone: %s\n", phone);
            printf("Age: %d\n", *age);
            return;
        }
    }
    printf("Person not found.\n");
}

void print_agenda(void *pBuffer, int count) {
    for (int i = 0; i < count; i++) {
        char *name = (char *)pBuffer + i * (NAME_SIZE + PHONE_SIZE + sizeof(int));
        char *phone = name + NAME_SIZE;
        int *age = (int *)(phone + PHONE_SIZE);
        printf("Name: %s\n", name);
        printf("Phone: %s\n", phone);
        printf("Age: %d\n", *age);
    }
}

int main() {
    void *pBuffer = malloc(11 * (NAME_SIZE + PHONE_SIZE + sizeof(int)));
    int count = 0;

    int option;
    do {
        printf("1 - Add person\n");
        printf("2 - Remove person\n");
        printf("3 - Search person\n");
        printf("4 - Print agenda\n");
        printf("0 - Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_person(pBuffer, &count);
                break;
            case 2:
                remove_person(pBuffer, &count);
                break;
            case 3:
                search_person(pBuffer, count);
                break;
            case 4:
                print_agenda(pBuffer, count);
                break;
            case 0:
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 0);

    free(pBuffer);

    return 0;
}