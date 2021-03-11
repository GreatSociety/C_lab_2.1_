//
// Created by Great_Society on 10.03.2021.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int cost;
    char* title;

    struct {
        char data[16];
        int days;
    }Intro;

}Info;


void clearInputBuf(void);
void baseSearch(Info** list, int number, unsigned int size);
void Remove(Info** list, const char* name, unsigned int size);

int main() {

    unsigned int sizeOfGroup = 1;

    printf("How many tours are planned?\n");
    scanf("%d", &sizeOfGroup);
    clearInputBuf();

    Info **listOfTours = calloc(sizeOfGroup+1, sizeof(Info));

    printf("%llu", sizeof(listOfTours));

    for(int i = 0; i < sizeOfGroup; i++){

        listOfTours[i] = malloc(sizeof(Info));
        char* titleName = malloc(256);

        printf("Please, write Tour name:\n");
        fgets(titleName,240,stdin);
        listOfTours[i]->title = titleName;

        printf("Please, write cost:\n");
        scanf("%d", &listOfTours[i]->cost);
        clearInputBuf();

        printf("Please, write date of start:\n");
        fgets(listOfTours[i]->Intro.data, 16,stdin);

        printf("Please, write value days:\n");
        scanf("%d", &listOfTours[i]->Intro.days);
        clearInputBuf();

        //free(titleName);
    }

    int userIFlag = 1;
    do{
        int userChoice;

        printf("\nWhat you wanna do?\n"
               "1. Search by cost.\n"
               "2. Remove by name.\n"
               "3. Exit.\n");

        scanf("%d", &userChoice);
        clearInputBuf();


        if (userChoice == 1){

            int* number = (int*) malloc(sizeof(int));
            printf("Write a cost for search");
            scanf("%d", number);

            baseSearch(listOfTours, *number, sizeOfGroup);

            free(number);
        }
        else if (userChoice == 2){

            char* name = malloc(256);
            printf("Write a title to remove");
            fgets(name,256,stdin);

            Remove(listOfTours, name, sizeOfGroup);

            free(name);
        }
        else if(userChoice == 3){
            userIFlag = 0;
        }
        else{
            printf("Incorrect input", stdin);
        }

    } while (userIFlag);

    free(listOfTours);

    return 0;
}

void baseSearch(Info** list, int number, unsigned int size){

    int flag = 0;

    for(int i = 0; i < size; i++){

        if (list[i]->cost < number){
            printf("\nTitle: %s",list[i]->title);
            printf("Cost: %d",list[i]->cost);
            printf("\nStart Day: %s", list[i]->Intro.data);
            printf("Days: %d\n", list[i]->Intro.days);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("\nNot found");
    }
}

void Remove(Info** list, const char* name, unsigned int size){

    for(int i = 0; i < size; i++){
        if(*list[i]->title == *name){
            free(list[i]);
        }
    }
}

void clearInputBuf()
{
    int garbageCollector;
    while ((garbageCollector = getchar()) != '\n' && garbageCollector != EOF);
}
