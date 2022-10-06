#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Score.h"

typedef Score ElementType;

typedef struct tagNode
{
	ElementType Data;	// 데이타 
    struct tagNode* NextNode;	// 다음 노드의 주소값을 저장
	struct tagNode* PrevNode;
	int count;	//계수법전용 카운트
} Node;

/* 함수 원형 선언 */
Node* DLL_CreateNode(ElementType NewData);
void  DLL_DestroyNode(Node* Node);
void  DLL_AppendNode(Node** Head, Node* NewNode);
void  DLL_InsertAfter(Node* Current, Node* NewNode);
void  DLL_InsertNewHead(Node** Head, Node* NewHead);
void  DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int   DLL_GetNodeCount(Node* Head);