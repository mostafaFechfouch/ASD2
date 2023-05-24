#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char matricule[20];
    char nom[50];
    char prenom[50];
    float moyenne;
    struct Student* next;
    struct Grade* grades;
};
struct Grade {
    float note;
    int coefficient;
    struct Grade* next;
};

void addGrade(struct Grade** head, float note, int coefficient) {
    struct Grade* newGrade = (struct Grade*) malloc(sizeof(struct Grade));
    newGrade->note = note;
    newGrade->coefficient = coefficient;
    newGrade->next = NULL;

    if (*head == NULL) {
        *head = newGrade;
    } else {
        struct Grade* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newGrade;
    }
}

void addStudent(struct Student** head, char matricule[], char nom[], char prenom[], float moyenne, struct Grade* grades) {
    struct Student* newStudent = (struct Student*) malloc(sizeof(struct Student));
    strcpy(newStudent->matricule, matricule);
    strcpy(newStudent->nom, nom);
    strcpy(newStudent->prenom, prenom);
    newStudent->moyenne = moyenne;
    newStudent->next = NULL;
    newStudent->grades = grades;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

void printGrades(struct Grade* head) {
    printf("Notes obtenues:\n");
    struct Grade* current = head;
    while (current != NULL) {
        printf("- %.2f (coefficient %d)\n", current->note, current->coefficient);
        current = current->next;
    }
}

void printStudents(struct Student* head) {
    printf("Liste des étudiants:\n");
    struct Student* current = head;
    while (current != NULL) {
        printf("%s %s (%s), moyenne %.2f\n", current->prenom, current->nom, current->matricule, current->moyenne);
        printGrades(current->grades);
        printf("\n");
        current = current->next;
    }
}

void calculateAverage(struct Student *head) {
    struct Student *currentStudent = head;
    float totalAverage = 0.0;
    int numStudents = 0;

    while (currentStudent != NULL) {
        totalAverage += currentStudent->moyenne;
        numStudents++;
        currentStudent = currentStudent->next;
    }

    float average = totalAverage / numStudents;
    printf("La moyenne de l'ensemble des etudiants est : %.2f\n", average);
}

int main() {
    struct Student* head = NULL;

    // Ajout de quelques étudiants
    struct Grade* grades1 = NULL;
    addGrade(&grades1, 16.5, 3);
    addGrade(&grades1, 13.0, 4);
    addGrade(&grades1, 18.0, 2);
    addStudent(&head, "A123", "Dupont", "Jean", 15.0, grades1);

    struct Grade* grades2 = NULL;
    addGrade(&grades2, 12.0, 2);
    addGrade(&grades2, 14.0, 3);
    addGrade(&grades2, 11.5, 4);
    addStudent(&head, "B456", "Martin", "Marie", 12.5, grades2);

    struct Grade* grades3 = NULL;
    addGrade(&grades3, 19.0, 3);
    addGrade(&grades3, 17.5, 4);
    addGrade(&grades3, 16.0, 2);
    addStudent(&head, "C789", "Durand", "Paul", 17.0, grades3);

    // Affichage de la liste des étudiants
    printStudents(head);

    // Calcul de la moyenne de l'ensemble des étudiants
    calculateAverage(head);

    return 0;
}