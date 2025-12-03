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

}