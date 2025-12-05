#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


int __search__(int *index ,data *list , data target ,int opt , int size){

    if (*index >= size){
        return 0;
    }
    int fount = -1;
    if (list[*index].type == target.type){
        switch (target.type)
        {
        case t_int:
            if (list[*index].value._int == target.value._int){
                fount = 1;
            }
            break;
        case t_float:
            if (list[*index].value._float == target.value._float){
               fount = 1;
            }
            break;
        default:
            if (strcmp(list[*index].value._string,target.value._string)==0){
                fount = 1;
            }
        }
    }

    if ((opt == 1) && (fount == 1)){
        return fount;
    }
    (*index)++;
    int res = __search__(index,list,target,opt,size);
    return fount + res;
}

int _in(pyclist *list,data values){
    int index = 0;
    return __search__(&index,list->data,values,1,list->init_size);
}

int _len(pyclist *list ){
    return list->init_size;
}

int _isempty(pyclist *list){
    if (list->init_size == 0){
        return 1;
    }
    return 0;
}
int  _getindex(pyclist *list,data value){
    int index = 0;
    int res = __search__(&index,list->data,value,1,list->init_size);
    if (res == -1){
        return -1;
    }
    return index;


}   
int _count(pyclist *list, data values){
    int index = 0;
    return __search__(&index,list->data,values,0,list->init_size-1);
   
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
    list->getindex = _getindex;
    list->len = _len;
    list->isempty = _isempty;
}
