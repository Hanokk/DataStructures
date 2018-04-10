#include <stdio.h>
#incldue <malloc.h>

int a[100000],index;

int parent(int index){
    return (index-1)/2;
}

int leftchild(int index){
    return 2*index+1;
}

int rightchild(int index){
    return 2*index+2;
}

void percolateup(int index){
    if(index <= 0){
        return;
    }
    if(a[parent(index)] > a[index]){
        swap(parent(index),index);
        percolateup(parent(index));
    }
    return;
}

void percolatedown(int index){
    l = leftchild(index);
    r = rightchild(index);
    if(a[l] < a[index] || a[r] < a[index]){
        if(a[l] < a[r]){
            swap(l,index);
            percolate(l);
        }
        else{
            swap(r,index);
            percolate(r);
        }
    }
}

void Insert(int value){
    a[index] = value;
    index++;
    percolateup(index-1);
}

void Delete(int value){
    int i;
    while(i < index){
        
    }
}

int deleteMin(){
    
}

int main()
{
    int option,value,Min;
    printf("Heap 1. Insert \n2. Delete\n3. Get minimum");
    switch(option) {
        case 1:
            Insert(value);
            break;
        case 2:
            scanf("%d",&value);
            Delete(value);
            break;
        case 3:
            printf("Min is %d", a[0]);
            break;
        default:
            break;
    }
}