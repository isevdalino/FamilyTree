#include "FamilyTreeNode.h"

FamilyTreeNode::FamilyTreeNode(const Person& person):person(person),leftParent(nullptr),rightParent(nullptr){}

FamilyTreeNode::FamilyTreeNode(const Person& person,FamilyTreeNode *leftParent,FamilyTreeNode *rightParent):
                                            person(person),leftParent(leftParent),rightParent(rightParent){}
