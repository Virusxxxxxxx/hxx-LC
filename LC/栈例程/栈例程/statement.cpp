#ifndef _Stack_h
struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif // !_Stack_h
#define EmptyTOS -1
#define MinStackSize 5
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};
