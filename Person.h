#ifndef PERSON_H
#define PERSON_H
#include<string>

enum gender{
FEMALE ,MALE,UNKNOWN
};

class Person
{
    public:
    Person(std::string egn,std::string name,int dateOfBirth,int dateOfDeath,gender sex);
    Person();
    gender getSex()const;
    std::string getFirstName()const;
    std::string getEgn()const;
    std::string getName()const;
    int getDateOfBirth()const;
    int getDateOfDeath()const;
    bool operator==(const Person& other)const;
    private:
    std::string egn;
    std::string name;
    int dateOfBirth;
    int dateOfDeath;
    gender sex;
};

#endif // PERSON_H
