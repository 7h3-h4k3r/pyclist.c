#include <stdio.h>
#include "../header/include.h"
int main(){
    pyclist list;
    __init__(&list);
    data va ={.type= t_int ,.value._int = 10};
    list.append(&list,va);
    va.type = t_float;
    va.value._float = 32.5;
    list.append(&list,va);
    list.clear(&list);
    //=================================================================
    va.type = t_int;
    va.value._int = 109;
    list.append(&list,va);
    va.type = t_int;
    va.value._int = 109;
    list.append(&list,va);
    data target = {.type=t_string,.value._string="kobdfam"};
     va.type = t_string;
    va.value._string = "kobham";
    list.append(&list,va);  va.type = t_string;
    va.value._string = "kobham";
    list.append(&list,va);
    list.append(&list,target);
    va.type = t_string;
    va.value._string = "kobham";
    list.append(&list,va);
    // printf("index of KObdfam %d",list.getindex(&list,n));
    printf("count of %d\n",list.count(&list,va));
    printf("if i in list %d \n",list.in(&list,va));
    printf("index of KObdfam %d\n",list.getindex(&list,target));
    printf("Len of List %d \n",list.len(&list));
    printf("is empty of List %d \n",list.isempty(&list));
}