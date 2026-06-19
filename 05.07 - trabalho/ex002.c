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

struct list* copy_list(list *list_fl) {
    list *newList;
    struct person *current_user;
    current_user = list_fl->first;
    if(is_empty(list_fl)) 
        newList->first = NULL;
        newList->last = NULL;

    while(current_user != NULL)
        newList->first = current_user;
        current_user = current_user->next;
    }

    return &newList;

int main() {
    struct person people;
    struct list list_fl;
    struct list second_list;

    create_list(&list_fl);
    create_list(&second_list);

    initalize(&list_fl);
    sum_ids(&list_fl);
}