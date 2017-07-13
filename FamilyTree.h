#ifndef FAMILYTREE_H
#define FAMILYTREE_H
#include "FamilyTreeNode.h"
#include "Person.h"
#include<string>
#include<vector>
#include<map>
class FamilyTree
{
    public:
    FamilyTree(Person& root);
    ~FamilyTree();
    FamilyTree(const FamilyTree& other);
    FamilyTree& operator=(const FamilyTree& other);
    void recordParents(std::string egn, const Person& mother, const Person& father);
    Person oldestRelative()const;
    std::string mostCommonName()const;
    std::map<std::string,int> commonNames()const;
    std::vector<Person> femalePredecessors()const;
    std::string relationship(const Person& relative)const;
    FamilyTreeNode* familyTreeRoot;
    void deleteNode(FamilyTreeNode* subRoot);
    FamilyTreeNode* getRoot()const;
    private:

    FamilyTreeNode* copyTree(FamilyTreeNode* subRoot)const;
    FamilyTreeNode* findPerson(FamilyTreeNode* subRoot,std::string egn)const;
    void oldestRelative(FamilyTreeNode* subRoot,Person*& current)const;
    void generateNamesMap(FamilyTreeNode* subRoot,std::map<std::string,int>& namesHash)const;
    void femalePredecessors(FamilyTreeNode* subRoot,std::vector<Person>& femalePredecessors,bool rootPassed)const;
    void relationship(FamilyTreeNode* subRoot,const Person& relative,int& depth,std::string& relation)const;
};

#endif // FAMILYTREE_H
