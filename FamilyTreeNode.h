#ifndef FAMILYTREENODE_H
#define FAMILYTREENODE_H
#include "Person.h"

class FamilyTreeNode
{
    public:
    FamilyTreeNode *leftParent, *rightParent;
	Person person;
	FamilyTreeNode(const Person& person);
    FamilyTreeNode(const Person& person,FamilyTreeNode *leftParent,FamilyTreeNode *rightParent);
};

#endif
