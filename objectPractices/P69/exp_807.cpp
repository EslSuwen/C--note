#include "Process.h"

int main()
{
    process *p;
    person person("Tom","male",18);
    student student("Emily","female",16,"CQJTU","Computer Science","294817");
    p = &person;
    p->print();
    p = &student;
    p->print();
    return 0;
}