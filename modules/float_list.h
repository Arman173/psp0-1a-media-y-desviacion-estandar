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
    unsigned int length;
    Node *root;
    Node *last;

public:
    float_list(/* args */);
    ~float_list();
    unsigned int size();
    bool push(float);
    void clear();
    float &operator[](int);
};

float_list::float_list(/* args */)
{
    this->length = 0;
    this->root = NULL;
    this->last = NULL;
}

float_list::~float_list()
{
    this->clear();
}

#endif