struct node
{
  int data;
  struct node *link;
};
typedef struct node node;

node *push(node *start,int data);
int pop(node **start);
int peep(node *start);
void display(node *start);
node *createnode(int data);
