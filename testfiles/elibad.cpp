// Copyright (c) 2015 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.
#include <noeliheader.h>

int myglobal=20;;

int main()
{
    Person* p = new Person();
    p->val = myglobal;

    return 0;
}
