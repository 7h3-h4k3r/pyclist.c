#include <stdio.h>
#include <stdlib.h>
#include "../header/include.h"

void customErr(const char *func , char *msg , const int line , const char *file){
    fprintf(stderr,"[*] Err : %s() throw  a Exception '%s'\n{File: %s -> Function: %s -> Line : %d}",func,msg,file,func,line);
    
    exit(-1);
}
void _append(pyclist *list , data values){
    if (list->capacity_size == list->init_size){
        void *temp = realloc(list->data,list->capacity_size * 2 * sizeof(data));
        if (temp == NULL){
            customErr(__func__,"Reallocation Failed",__LINE__,__FILE__);
        }
        list->capacity_size *=2;
        list->data = temp;
    }
    list->data[list->init_size++] = values;
    
}

int _clear(pyclist *list){

    __init__(list);
}


int __search__(int *index ,data *list , data target , int count , int opt , int size){
    if (list->type == target.type){
        switch (target.type)
        {
        case t_int:
            if (list->value._int == target.value._int){
                count = count + 1;
            }
            break;
        case t_float:
            if (list->value._float == target.value._float){
                count = count + 1;
            }
            break;
        default:
            if (list->value._string == target.value._string){
                count = count + 1;
            }
        }
    }

    if ((opt || *index == size) && (count != 0 || *index == size)){
        return count;
    }
    else{
       count = count +  __search__(index,&list[(*index)++],target,count,opt,size);
    }
    return count;
}
int _in(pyclist *list,data values){
    int *index;
    return __search__(index,list->data,values,0,1,list->init_size);
}
int _count(pyclist *list, data values){
    int *index;
    return __search__(index,list->data,values,0,0,list->init_size-1); 
}
void __init__(pyclist *list){
    list->data = malloc(sizeof(data));
    if (list->data == NULL){
        customErr(__func__,"Memory allocation Failed line",__LINE__,__FILE__);
    }
    list->capacity_size = 1;
    list->init_size = 0;
    list->append = _append;
    list->clear = _clear;
    list->count = _count;
    list->in = _in;
}
