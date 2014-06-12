#ifndef VISITORCURSUS_H
#define VISITORCURSUS_H

class VisitorCursus
{
public:
    VisitorCursus();
    virtual void visit(class Primitive *, class Component*) = 0;
    virtual void visit(class Composite *, Component*) = 0;
};

#endif // VISITORCURSUS_H
