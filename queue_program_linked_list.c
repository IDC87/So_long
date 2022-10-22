/* typedef struct node
{
    int value;
    struct node *next;
    
}   node;

typedef struct queue
{
    node *head;
    node *tail;
}   queue;

typedef struct coords
{
    queue row;
    queue col;
    
} t_coords; */



/* void init_queue(t_tudo *tudo)
{
    tudo->coords.row.head = NULL;
    tudo->coords.row.tail = NULL;
}

int enqueue1(t_tudo *tudo, int value)
{
    node * newnode;
    
    newnode = malloc(sizeof(node));
    if (newnode == NULL)
        return -1;
    newnode->value = value;
    newnode->next = NULL;
    if (tudo->coords.row.tail != NULL)
        tudo->coords.row.tail->next = newnode;
    tudo->coords.row.tail = newnode;
    if(tudo->coords.row.head == NULL)
        tudo->coords.row.head = newnode;
    return 1;
}

int dequeue1(t_tudo *tudo)
{
    int result;
    node *tmp;
    
    if (tudo->coords.row.head == NULL)
        return -1;
    tmp = tudo->coords.row.head;
    result = tmp->value;
    tudo->coords.row.head = tudo->coords.row.head->next;
    if (tudo->coords.row.head == NULL)
        tudo->coords.row.tail = NULL;

    free(tmp);
    //free(tudo->coords.row.head);
    return result;
}

void check_valid_path(t_tudo *tudo)
{
    
    init_queue(tudo);
    
    enqueue1(tudo, 50);    
   enqueue1(tudo, 25);
    enqueue1(tudo, 500);
    enqueue1(tudo, 100);
    
    int i = 0;
    while(i < 8)
    {
     printf("%d\n\n", tudo->coords.row); 
     i++;   
    }
} */

/* typedef struct s_queue
{
    int move_count;
    int nodes_left_in_layer;
    int nodes_in_next_layer;
    //int dr[4];
    //int dc[4];
    int count;
    int size_of_queue;
    int *rq;
    int *cq;    
    
}   t_queue; */ 