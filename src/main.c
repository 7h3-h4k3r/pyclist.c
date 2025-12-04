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
    va.type = t_int;
    va.value._int = 109;
    list.append(&list,va);
    va.type = t_int;
    va.value._int = 109;
    list.append(&list,va);
    va.type = t_string;
    va.value._string = "kobdfam ";
    list.append(&list,va);
    // va.type = t_string;
    // va.value._string = "kobham";
    // list.append(&list,va);
    // va.type = t_string;
    // va.value._string = "kobham";
    // list.append(&list,va);
    va.type = t_string;
    va.value._string = "kobham";
    
    printf("count of %d\n",list.count(&list,va));
    printf("if i in list %d",list.in(&list,va));

}