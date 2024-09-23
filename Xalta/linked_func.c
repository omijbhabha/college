// insert at end
// insert at beginning
// insert at nth position
// delete at nth position
// concatenate
// doubly
sturct node *insertatbegin(int n)
{
    struct node *temp = (struct node *)malloc(sizzeof(struct node));
    temp->data = n;
    temp->next = head;
    head = temp;
    return head;
}
void insertatnthposi(int x, int n)
{
    struct node *temp = (struct node *)malloc(sizzeof(struct node));
    temp->data = x;
    temp->next = null;
    if (n == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    struct node *temp1 = head;
    for (i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}
void deleteatnthposi(int n)
{
    struct Node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }
    strut node *temp2 = temp1->next;
    temp1->next = temp2->next;
}

void insertatend(int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = null;
    if (head == null)
    {
        head = temp;
    }
    struct node *temp1 = head;
    while (temp1->next != null)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp
}
void insertatend(int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = null;
    if (head == null)
    {
        head = temp;
        return;
    }
    struct node *temp1 = head;
    while (temp1->next != null)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}
void concatenate(struct node **list1, struct node *list2)
{
    if (*list1 == null)
    {
        *list1 = list2;
    }
    else
        struct node *temp = *list1;
    while (temp->next != null)
    {
        temp = temp_ > next;
    }
    temp->next = list2;
}
concatenate(&head1, head2);
void concatenate(struct node **list1, struct node *list2)
{
    if (*list1 == null)
    {
        *list1 = list2;
    }
    struct node *temp = *list1;
    while (temp->next != null)
    {
        temp = temp->next;
    }
    temp->next = list2;
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp->next != null)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
void Reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    head = prev; // Update head to the new front of the list
}