#include <iostream>
#include "FamilyTree.h"
using namespace std;

int main()
{
    Person me("9701237523","Ivan Ivanov",1997,-1,MALE);
    Person mom("6612171695","Nina Stoineva",1966,-1,FEMALE);
    Person dad("5908284265","Sevdalin Stoinev",1959,-1,MALE);
    Person grandma("4012174235","Stanoika Qneva",1940,-1,FEMALE);
    Person grandpa("3612177164","Ivan Qnev",1936,2000,MALE);
    Person grandgrandma("0612176297","Trendafila Todorova",1906,1990,FEMALE);
    Person grandgrandpa("0012171295","Stoine Todorov",1900,1985,MALE);
    FamilyTree myTree(me);
    myTree.recordParents("9701237523",mom,dad);
    myTree.recordParents("5908284265",grandma,grandpa);
    myTree.recordParents("3612177164",grandgrandma,grandgrandpa);
    cout<<"Oldest alive relative:"<<myTree.oldestRelative().getName()<<" born in "<<myTree.oldestRelative().getDateOfBirth()<<endl;
    cout<<"The most common name in my family tree is "<<myTree.mostCommonName()<<",of course"<<endl;
    map<string,int> namesMap=myTree.commonNames();
    cout<<"A map that counts the first names in my family tree:"<<endl;
    for(map<string,int>::iterator it=namesMap.begin();it!=namesMap.end();++it){
      cout<<it->first;
      cout<<":"<<it->second<<endl;
    }
    cout<<"My female relatives are:"<<endl;
    for(vector<Person>::iterator it=myTree.femalePredecessors().begin();it!=myTree.femalePredecessors().end();++it){
      cout<<it->getName()<<endl;
    }
    cout<<"Trendafila Todorova is my "<<myTree.relationship(grandgrandma)<<endl;
    return 0;
}
