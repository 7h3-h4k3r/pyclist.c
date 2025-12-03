#ifndef PYCLIST_H
#define PYCLIST_H


typedef union 
{
    int _int;
    float _float;
    char *_string;
}t_datavalue;

typedef enum{
    t_int,
    t_float,
    t_string
}t_datatype;

typedef struct data{
    t_datatype type;
    t_datavalue value;
}data;



typedef struct pyclist
{   
    data *data;
    int init_size;
    int capacity_size;
    void (*append)(struct pyclist * ,data value);
    
   
}pyclist;

void __init__(pyclist *list);
void append(pyclist *list);
#endif