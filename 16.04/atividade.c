#include <stdbool.h>

typedef struct Usuario {
    int id;
    int age;
    char name[20];
    struct usuario *nextUser;
} usuario;

typedef struct list_fl {
    struct usuario *first;
    struct usuario *last;
}

void create_list(list_fl *list) {
    list->first = NULL;
    list->last = NULL;
}

int isEmpty(list_fl *list) {
    return list->first == NULL;
}

void insert_user(usuario *u, list_lf *list) {
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
    usuario *currentUser = (usuario*) malloc(sizeof(usuario));
    *currentUser = list->first;

    while(currentUser != NULL) {
        printf("\nID user: %d\n", currentUser->id);
        printf("Name: %d\n", currentUser->name);
        printf("Age: %.2d\n", currentUser->age);
        
        currentUser = currentUser->nextUser;
    }
}

void create_user(usuario *user) {
    printf("\n=== REGISTER ===\n");
    printf("Name: ");
    scanf("%s", user->name);
    printf("Age: ");
    scanf("%d", user->age);
}

void search_user(usuario *user) {
    usuario *currentUser = (usuario*) malloc(sizeof(usuario));
    *currentUser = user;
    
    while(currentUser != NULL) {
        if(currentUser->id == user->id) {
            printf("\nID user: %d\n", currentUser->id);
            printf("Name: %d\n", currentUser->name);
            printf("Age: %.2d\n", currentUser->age);
            break;
        }
        currentUser = currentUser->nextUser;
    }
}

void delete_user(usuario *user, list_fl *list) {  
    usuario *currentUser = (usuario*) malloc(sizeof(usuario));
    *currentUser = user;
    
    int code;
    bool isFound;
    
    printf("Type the user's id: ");
    scanf("%d", &code)

    if(list->first == user)
        list->first = user->next;

    
    while(currentUser != NULL) {
        if(list->last == currentUser)
            list->last == user
        currentUser = currentUser->nextUser;
    }

    if(!isFound)
        printf("User not found!");
}

int main() {
    usuario User;
    list_fl list;

    create_list(&list);
    create_user(&user);



}