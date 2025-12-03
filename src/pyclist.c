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
    }
    list->data[list->init_size++] = values;
}

void __init__(pyclist *list){
    list->data = malloc(sizeof(data));
    if (list->data == NULL){
        customErr(__func__,"Memory allocation Failed line",__LINE__,__FILE__);
    }
    list->capacity_size = 1;
    list->init_size = 0;
    list->append = _append;
}
