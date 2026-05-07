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

void register_user(list *list_fl, person u) {
    person *newGuy = (person*) malloc(sizeof(person));
    // Não lembro porque colocar ponteiro novamente
    *newGuy = u;
    newGuy->next = NULL;

    if(isEmpty(list_fl)) {
        list_fl->first = newGuy;
        list_fl->last = newGuy;
    }
    else {
        list_fl->last->next = newGuy;
        list_fl->last = newGuy;
    }
}

int count_users(list *list_fl) {
    int counter = 0;

    if(is_empty(list_fl))
        return 0;

    struct person *current_user;
    current_user = list_fl->first;

    // Count users
    while(current_user != NULL) {
        counter++;
        current_user = current_user->next;
    } 

    return counter;
}

void initialize(list *list_fl) {
    person addUser;
   
    addUser.id = 1;
    strcpy(addUser.name, "Josimar");
    addUser.age = 37;
    insert_user(addUser, list_fl);
   
    addUser.id = 2;
    strcpy(addUser.name, "Ademar");
    addUser.age = 64;
    insert_user(addUser, list_fl);
   
    addUser.id = 3;
    strcpy(addUser.name, "Jose");
    addUser.age = 67;
    insert_user(addUser, list_fl);
}

int main() {
    struct list list_fl;

    create_list(&list_fl);
    initialize(&list_fl);
    count_users(&list_fl);

    printf("%d usuarios cadastrados.", count_users(&list_fl));
}