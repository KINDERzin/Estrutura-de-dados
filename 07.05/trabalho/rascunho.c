typedef struct person{
    int id;
    char name[20];
    int age;
    struct person *next;
} person;

typedef struct list{
    struct person *first;
    struct person *last;
} list;

void create_list(list *list_fl) {
    list_fl->first = NULL;
    list_fl->last = NULL;
}

int is_empty(list *list_fl) {
    return list_fl->first == NULL;
}

void register_user(list *list_fl) {
    struct person *user = (person*) malloc(sizeof(person));

    printf("Name: ");
    scanf("%s", user->name);
    printf("Age: ");
    scanf("%d", user->age);
    printf("Id: ");
    scanf("%d", user->age);

    if(is_empty(list_fl)) {
        list_fl->first = user;
        list_fl->last = user;
    }
    else {
        list_fl->last->next = user;
        list_fl->last = user;
        user->next = NULL;
    }
}

int count_users(list *list_fl) {
    int counter = 0;

    struct person *current_user;
    current_user = list_fl->first;

    // Count users
    while(current_user->next != NULL) {
        counter++;
        current_user = current_user->next;
    }
}

void show_list(list *list_fl) {
    struct person *current_user;
    current_user = list_fl->first;

    if(is_empty(list_fl)) {
        printf("List is EMPTY!");
        return;
    }

    // Show the list
    while(current_user->next != NULL) {
        printf("Name: %s", current_user->name);
        printf("Age: %d", current_user->age);

        current_user = current_user->next;
    }
}

int main() {
    struct person people;
    struct list list_fl;


}