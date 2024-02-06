#ifndef _HPP_FLOAT_LIST
#define _HPP_FLOAT_LIST

#include <cstdio>
#include <iostream>

struct Node
{
    Node *prev;
    Node *next;
    float data;
};

class float_list
{
private:
    /* data */
    int length;
    Node *root;
    Node *last;

public:
    float_list(/* args */);
    ~float_list();
    int size();
    bool push(float);
    void clear();
    float element(int);
};

#endif