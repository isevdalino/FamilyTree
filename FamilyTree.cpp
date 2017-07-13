#include "FamilyTree.h"
#include <iostream>

FamilyTree::FamilyTree(Person& familyTreeRoot)
{
  this->familyTreeRoot=new FamilyTreeNode(familyTreeRoot);
}

FamilyTree::FamilyTree(const FamilyTree& other)
{
  this->familyTreeRoot=copyTree(other.getRoot());
}

FamilyTree& FamilyTree::operator=(const FamilyTree& other){
  if(this!=&other){
    deleteNode(familyTreeRoot);
    this->familyTreeRoot=copyTree(other.getRoot());
  }
  return *this;
}

FamilyTree::~FamilyTree()
{
  deleteNode(familyTreeRoot);
}

FamilyTreeNode* FamilyTree::getRoot()const{
  return familyTreeRoot;
}

FamilyTreeNode* FamilyTree::copyTree(FamilyTreeNode* subRoot)const{
  if(subRoot==nullptr){
    return nullptr;
  }
  return new FamilyTreeNode(subRoot->person,copyTree(subRoot->leftParent),copyTree(subRoot->rightParent));
}

void FamilyTree::deleteNode(FamilyTreeNode* subRoot){
  if(subRoot==nullptr){
    return;
  }
  deleteNode(subRoot->leftParent);
  deleteNode(subRoot->rightParent);
  delete subRoot;
}

 FamilyTreeNode* FamilyTree::findPerson(FamilyTreeNode* subRoot,std::string egn)const{
  if(subRoot==nullptr){
    return nullptr;
  }
  if(subRoot->person.getEgn()==egn){
    return subRoot;
  }
  FamilyTreeNode* result1=findPerson(subRoot->leftParent,egn);
  FamilyTreeNode* result2=findPerson(subRoot->rightParent,egn);
  if(result1!=nullptr){
    return result1;
  }else{
    return result2;
  }
}

void FamilyTree::recordParents(std::string egn, const Person& mother, const Person& father){
  FamilyTreeNode*  personSought=findPerson(familyTreeRoot,egn);
  if(personSought->leftParent!=nullptr||personSought->rightParent!=nullptr){
    std::cout<<"A given person can only has one set of parents...and he doesn't get to choose them,sorry"<<std::endl;
  }
  personSought->leftParent=new FamilyTreeNode(mother);
  personSought->rightParent=new FamilyTreeNode(father);
}

Person FamilyTree::oldestRelative()const{
  if((familyTreeRoot->leftParent==nullptr||familyTreeRoot->rightParent==nullptr)&&familyTreeRoot->person.getDateOfDeath()==(-1)){
    return familyTreeRoot->person;
  }else if(familyTreeRoot->person.getDateOfDeath()!=-1){
    return Person();
  }else{
    Person* current=&familyTreeRoot->person;
    oldestRelative(familyTreeRoot,current);
    return *current;
  }
}

void FamilyTree::oldestRelative(FamilyTreeNode* subRoot,Person*& current)const{
  if(subRoot==nullptr){
    return;
  }
  if((subRoot->person.getDateOfDeath()==-1)&&(subRoot->person.getDateOfBirth()<current->getDateOfBirth())){
    current=&subRoot->person;
  }
  oldestRelative(subRoot->leftParent,current);
  oldestRelative(subRoot->rightParent,current);
}

void FamilyTree::generateNamesMap(FamilyTreeNode* subRoot,std::map<std::string,int>& namesMap)const{
  if(subRoot==nullptr){
    return;
  }
  namesMap[subRoot->person.getFirstName()]=namesMap[subRoot->person.getFirstName()]+1;
  generateNamesMap(subRoot->leftParent,namesMap);
  generateNamesMap(subRoot->rightParent,namesMap);
}

std::string FamilyTree::mostCommonName()const{
  std::map<std::string,int> namesMap;
  generateNamesMap(familyTreeRoot,namesMap);
  int maxCount=0;
  std::string mostCommonName="";
  for(std::map<std::string,int>::iterator it=namesMap.begin();it!=namesMap.end();++it){
    if(it->second>maxCount){
      maxCount=it->second;
      mostCommonName=it->first;
    }
  }
  return mostCommonName;
}

std::map<std::string,int> FamilyTree::commonNames()const{
  std::map<std::string,int> namesMap;
  generateNamesMap(familyTreeRoot,namesMap);
  return namesMap;
}

void FamilyTree::femalePredecessors(FamilyTreeNode* subRoot,std::vector<Person>& femalePredecessorsVec,bool rootPassed)const{
  if(subRoot==nullptr){
    return;
  }
  if(rootPassed&&subRoot->person.getSex()==FEMALE){
    femalePredecessorsVec.push_back(subRoot->person);
  }
  femalePredecessors(subRoot->leftParent,femalePredecessorsVec,true);
  femalePredecessors(subRoot->rightParent,femalePredecessorsVec,true);
}

std::vector<Person> FamilyTree::femalePredecessors()const{
  std::vector<Person> femalePredecessorsVec;
  femalePredecessors(familyTreeRoot,femalePredecessorsVec,false);
  return femalePredecessorsVec;
}

std::string FamilyTree::relationship(const Person& relative)const{
   int depth=0;
   std::string relation="Not a relative";
   relationship(familyTreeRoot,relative,depth,relation);
   return relation;
}

void FamilyTree::relationship(FamilyTreeNode* subRoot,const Person& relative,int& depth,std::string& relation)const{
  if(subRoot==nullptr){
    return;
  }
  if(subRoot->person==relative){
    if(depth==0){
      relation="Thats not a relative,thats the person itself!";
      return;
    }
    relation="";
    if(depth>1){
    for(int i=0;i<depth-1;i++){
      relation.append("grand-");
    }
    }
    if(relative.getSex()==FEMALE){
      relation.append("mother");
    }else{
      relation.append("father");
    }
    return;
  }
  depth++;
  relationship(subRoot->leftParent,relative,depth,relation);
  relationship(subRoot->rightParent,relative,depth,relation);
  depth--;
}

