#include "DLL.h"

/*  ��� ���� */
Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    if (NewNode != NULL) {
        NewNode->Data = NewData;  /*  �����͸� �����Ѵ�. */
        NewNode->NextNode = NULL; /*  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. */
        NewNode->PrevNode = NULL;
        NewNode->count = 0;
    }

    return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

/*  ��� �Ҹ� */
void DLL_DestroyNode(Node* Node) { free(Node); }

/*  ��� �߰� */
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  ��� ��尡 NULL�̶�� ���ο� ��尡 Head */
    if ((*Head) == NULL) { *Head = NewNode; }
    else
    {
        /*  ������ ã�� NewNode�� �����Ѵ�. */
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

/*  ��� ���� */
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}

void DLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ((*Head) == NULL)
    {
        (*Head) = NewHead;
    }
    else
    {
        NewHead->NextNode = (*Head); 
        NewHead->PrevNode = NULL;

        (*Head)->PrevNode = NewHead;
        (*Head) = NewHead;
    }
}

/*  ��� ���� */
void DLL_RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove) { *Head = Remove->NextNode; }
    else
    {
        Node* Current = *Head;
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }

        if (Current != NULL)
        {
            Current->NextNode = Remove->NextNode;
            Remove->NextNode->PrevNode = Current;
        }

    }
}

/*  ��� Ž�� */
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  ��� �� ���� */
int DLL_GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}