#include "Person.h"

Person::Person(std::string egn,std::string name,int dateOfBirth,int dateOfDeath,gender sex)
{
  this->egn=egn;
  this->name=name;
  this->dateOfBirth=dateOfBirth;
  this->dateOfDeath=dateOfDeath;
  this->sex=sex;
}

Person::Person()
{
  this->egn="0000000000";
  this->name="John/Jane Doe";
  this->dateOfBirth=0;
  this->dateOfDeath=0;
  this->sex=UNKNOWN;
}

std::string Person::getFirstName()const{
  int i;
  for(i=0;i<getName().length();i++){
    if(getName().at(i)==' '){
        break;
    }
  }
  return getName().substr(0,i);

}

std::string Person::getEgn()const{
  return egn;
}

std::string Person::getName()const{
  return name;
}

int Person::getDateOfBirth()const{
  return dateOfBirth;
}

int Person::getDateOfDeath()const{
  return dateOfDeath;
}

gender Person::getSex()const{
  return sex;
}

bool Person::operator==(const Person& other)const{
  bool isEgnEquel=egn.compare(other.getEgn())==0;
  bool isNameEquel=name.compare(other.getName())==0;
  bool isDateOfBirthEquel=dateOfBirth==other.getDateOfBirth();
  bool isDateOfDeathEquel=dateOfDeath==other.getDateOfDeath();
  bool isSexSame=sex==other.getSex();
  return isEgnEquel&&isNameEquel&&isDateOfBirthEquel&&isDateOfDeathEquel&&isSexSame;
}

