/*
    Danh sách liên kết đơn
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

// KHAI BÁO LINKEDLIST
typedef struct Linkedlist
{
    int data;
    struct Linkedlist *next;
} * Node;

// Hàm kiểm tra danh sách có rỗng hay không
int Empty(Node list1)
{
    if (list1 == NULL)
        return 1;
    else
        return 0;
}

// Hàm duyệt các phần tử danh sách liên kết
void Traverse(Node List1)
{
    for (Node p = List1; p != NULL; p = p->next)
    {
        printf("%5d", p->data);
    }
}

// Tạo 1 node mới
Node CreateNode(int value)
{
    Node temp;
    temp = (Node)malloc(sizeof(Node));
    temp->next = NULL;
    temp->data = value;
    return temp;
}

// Thêm node vào đầu
Node AddHead(Node head, int value)
{
    Node temp = CreateNode(value);
    if (Empty(head))
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

// Thêm node vào cuối
Node AddTail(Node head, int value)
{
    Node temp, p;
    temp = CreateNode(value);
    if (Empty(head))
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

// Thêm node vào vị trí bất kỳ
Node AddAt(Node head, int value, int position)
{
    if (position == 0 || head == NULL)
        head = AddHead(head, value);
    else
    {
        int k = 1;
        Node p = head;
        while (p != NULL && k != position)
        {
            p = p->next;
            ++k;
        }
        if (k != position)
            head = AddTail(head, value);
        else
        {
            Node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}

// Xóa node đầu tiên
Node DelHead(Node head)
{
    if (Empty(head))
    {
        printf("\nCha co gi de xoa het!");
    }
    else
    {
        head = head->next;
    }
    return head;
}

// xóa node cuối
Node DelTail(Node head)
{
    if (head == NULL || head->next == NULL)
    {
        return DelHead(head);
    }
    Node p = head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = p->next->next; // Cho next bằng NULL
    // Hoặc viết p->next = NULL cũng được
    return head;
}

// Xóa node bất kỳ
Node DelAt(Node head, int position)
{
    if (position == 0 || head == NULL || head->next == NULL)
    {
        head = DelHead(head);
    }
    else
    {
        int k = 1;
        Node p = head;
        while (p->next->next != NULL && k != position)
        {
            p = p->next;
            ++k;
        }

        if (k != position)
            head = DelTail(head);
        else
            p->next = p->next->next;
    }
    return head;
}

// Tìm kiếm trong danh sách
int Search(Node head, int value)
{
    int position = 0;
    for (Node p = head; p != NULL; p = p->next)
    {
        if (value == p->data)
        {
            return position;
        }
        else
        {
            ++position;
        }
    }
    return -1;
}

// Lấy giá trị
int Get(Node head, int index)
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

// Hàm nhập danh sách liên kết
Node Input()
{
    Node head = NULL;
    int n, value;
    do
    {
        printf("\nINPUT: n = ");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = 0; i < n; ++i)
    {
        printf("Value[%d] = ", i);
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}

int main()
{
    Node head = NULL;
    //
    printf("INPUT\n");
    head = Input();
    printf("List:\n");
    Traverse(head);
    //
    printf("\nADD HEAD: ");
    int value1;
    scanf("%d", &value1);
    head = AddHead(head, value1);
    Traverse(head);
    //
    printf("\nADD TAIL: ");
    int value2;
    scanf("%d", &value2);
    head = AddTail(head, value2);
    Traverse(head);
    //
    printf("\nADD AT : ");
    int value3, index1;
    scanf("%d", &index1);
    printf("Value = ");
    scanf("%d", &value3);
    head = AddAt(head, value3, index1);
    Traverse(head);
    //
    printf("\nDELETE NODE HEAD\n");
    head = DelHead(head);
    Traverse(head);
    //
    printf("\n DELETE NODE TAIL\n");
    head = DelTail(head);
    Traverse(head);
    //
    printf("\n DELETE NODE AT:");
    int index2;
    scanf("%d", &index2);
    head = DelAt(head, index2 - 1);
    Traverse(head);
    //
    printf("\nVALUE WANT TO SEARCH: ");
    int value4;
    scanf("%d", &value4);
    int index3 = Search(head, value4);
    if (index3 == -1)
    {
        printf("Not value %d on list.\n", value4);
    }
    else
    {
        printf(" Value %d is %d on list\n", value4, index3 + 1);
    }
    //
    printf("GET VALUE AT: ");
    int index4;
    scanf("%d", &index4);
    printf("%d is value, is %d on list.\n", Get(head, index4), index4);
    return 0;
}