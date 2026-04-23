/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct usuario {
    int id;
    int age;
    char name[20];
    struct usuario *nextUser;
} usuario;

typedef struct list_fl {
    struct usuario *first;
    struct usuario *last;
} list_fl;

void create_list(list_fl *list) {
    list->first = NULL;
    list->last = NULL;
}

int isEmpty(list_fl *list) {
    return list->first == NULL;
}

void insert_user(usuario u, list_fl *list) {
    usuario *newGuy = (usuario*) malloc(sizeof(usuario));
    // Não lembro porque colocar ponteiro novamente
    *newGuy = u;
    newGuy->nextUser = NULL;

    if(isEmpty(list)) {
        list->first = newGuy;
        list->last = newGuy;
    }
    else {
        list->last->nextUser = newGuy;
        list->last = newGuy;
    }
}

void show_list(list_fl *list) {
    usuario *currentUser = list->first;

    if(list->first == NULL) {
        printf("Empty list.");
        return;
    }
    
    printf("=== USERS LIST ===");
    while(currentUser != NULL) {
        printf("\nID user: %d\n", currentUser->id);
        printf("Name: %s\n", currentUser->name);
        printf("Age: %d\n", currentUser->age);
        
        currentUser = currentUser->nextUser;
    }
}

void create_user(list_fl *list) {
    usuario newGuy;
    
    printf("\n=== REGISTER ===\n");
    printf("Name: ");
    scanf("%s", &newGuy.name);
    printf("Age: ");
    scanf("%d", &newGuy.age);
    
    insert_user(newGuy, list);
}

void search_user(usuario *user, list_fl *list) {
    usuario *currentUser = (usuario*) malloc(sizeof(usuario));
    currentUser = list->first;
    
    while(currentUser != NULL) {
        if(currentUser->id == user->id) {
            printf("\nID user: %d\n", currentUser->id);
            printf("Name: %d\n", currentUser->name);
            printf("Age: %.2d\n", currentUser->age);
            break;
        }
        currentUser = currentUser->nextUser;
    }
    
    printf("User not found!");
}

void delete_user(list_fl *list) {  
    usuario *currentUser = (usuario*) malloc(sizeof(usuario));
    currentUser = list->first;
    
    int code;
    bool isFound;
    
    do {
    printf("\nType the user's id: ");
    scanf("%d", &code);
    
    // If the user was the first, the second will be the first
    if(list->first->id == code) {
        list->first = list->first->nextUser;
        free(list->first);
        printf("User deleted");
        return;
    }
    
    while(currentUser != NULL) {
        
        // Last position
        if(currentUser->nextUser->id == code && currentUser->nextUser->id == list->last->id) {
            list->last = currentUser;
            currentUser->nextUser == NULL;
            free(currentUser->nextUser);
            printf("User deleted!");
            return;
        }    
        //Middle position
        if(currentUser->nextUser->id == code) {
            currentUser->nextUser = currentUser->nextUser->nextUser;
            printf("User deleted!");
            return;
        }
        currentUser = currentUser->nextUser;
        
    }
    
    if(!isFound)
        printf("User not found!");
    } 
    while(!isFound);
}

void initialize(list_fl *list) {
    usuario addUser;
    
    
    addUser.id = 1;
    strcpy(addUser.name, "Josimar");
    addUser.age = 37;
    insert_user(addUser, list);
    
    addUser.id = 2;
    strcpy(addUser.name, "Ademar");
    addUser.age = 64;
    insert_user(addUser, list);
    
    addUser.id = 3;
    strcpy(addUser.name, "Jose");
    addUser.age = 67;
    insert_user(addUser, list);
}

int main() {
    usuario user;
    list_fl list;

    create_list(&list);
    initialize(&list);
    
    show_list(&list);
    delete_user(&list);
}
