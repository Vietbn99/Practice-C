/*
    Chương trình C để hiển thị danh sách liên kết theo chiều đảo ngược
    Tìm kích cỡ của danh sách liên kết trong C
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
} * Node;
// tạo node
Node CreateNode(int value)
{
    Node temp;
    temp = (Node)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// them node vào cuối
Node AddTail(Node head, int value)
{
    Node temp = CreateNode(value);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

// trả về giá trị thứ i
int GET(Node head, int index)
{
    int position = 0;
    Node p = head;
    while (p->next != NULL && position != index)
    {
        ++position;
        p = p->next;
    }
    return p->data;
}

// hàm nhâp
Node Input(int n)
{
    Node head = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("pt %d = ", i + 1);
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}

// hàm xuất ngược
void OutputReverse(Node head, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%5d", GET(head, i));
    }
}

// kích cỡ của danh sách
int LengthList(Node head)
{
    Node p = head;
    int position = 0;
    while (p != NULL)
    {
        p = p->next;
        ++position;
    }
    return position;
}
int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    Node head = Input(n);
    OutputReverse(head, n);
    head = AddTail(head, 5);
    printf("\n%d\n", LengthList(head));
    return 0;
}