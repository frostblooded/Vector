#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_STARTING_SIZE 5

struct Vector
{
    int *data;
    int size;
    int index;
};

void InitializeVector(struct Vector*);
void DestroyVector(struct Vector*);

void PushVector(struct Vector*, int);
int PopVector(struct Vector*);
int PeekVector(struct Vector);

void IncreaseSizeOfVector(struct Vector*);
void TransferData(int*, int, int*);


void InitializeVector(struct Vector *v)
{
    v->index = 0;
    v->size = VECTOR_STARTING_SIZE;
    v->data = (int*)malloc(sizeof(int) * v->size);
}

void DestroyVector(struct Vector *v)
{
    free(v->data);
}

void PushVector(struct Vector *v, int value)
{
    if(v->size <= v->index)
    {
        IncreaseSizeOfVector(v);
    }

    v->data[v->index] = value;
    v->index++;
}

int PopVector(struct Vector *v)
{
    v->index--;
    return v->data[v->index];
}

int PeekVector(struct Vector v)
{
    return v.data[v.index - 1];
}

void PrintData(struct Vector *v)
{
    int i;
    for(i = 0; i < v->index; ++i)
    {
        printf("%d\n", v->data[i]);
    }
}

void TransferData(int *old_data, int old_data_size, int *new_data)
{
    int i;
    for(i = 0; i < old_data_size; ++i)
    {
        new_data[i] = old_data[i];
    }
}

void IncreaseSizeOfVector(struct Vector *v)
{
    v->size *= 2;
    int *new_data = (int*)malloc(sizeof(int) * v->size);

    TransferData(v->data, v->size, new_data);

    free(v->data);
    v->data = new_data;
}

int main()
{
    struct Vector v;
    InitializeVector(&v);
    srand(time(NULL));

    int i;
    for(i = 0; i < 10; ++i)
    {
        PushVector(&v, rand() % 20 + 1);
    }

    for(i = 0; i < 10; ++i)
    {
        printf("%d\n", PopVector(&v));
    }

    DestroyVector(&v);

    return 0;
}
