#include "Student.h"
#include <cstring>

bool Student::setName(char* s){
    if(strlen(s)>50)
        return false;
    strcpy(this->name,s);
    return true;
}
char* Student::getName(){
    return this->name;
}

bool Student::setmathGrade(float val) {
    if(val<1 || val>10)
        return false;
    this->mathGrade=val;
}
float Student::getmathGrade(){
    return this->mathGrade;
}

bool Student::setenglishGrade(float val) {
    if(val<1 || val>10)
        return false;
    this->englishGrade=val;
}
float Student::getenglishGrade(){
    return this->englishGrade;
}

bool Student::sethistoryGrade(float val) {
    if(val<1 || val>10)
        return false;
    this->historyGrade=val;
}
float Student::gethistoryGrade(){
    return this->historyGrade;
}

float Student::getaverageGrade(){
    return (this->mathGrade+this->englishGrade+this->historyGrade)/3;
}