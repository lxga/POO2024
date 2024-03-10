#define _CRT_SECURE_NO_WARNINGS
#pragma once
class Student {
    char name[51];
    float mathGrade;
    float historyGrade;
    float englishGrade;
public:
    bool setName(char* s);
    char* getName();

    bool setmathGrade(float val);
    float getmathGrade();

    bool sethistoryGrade(float val);
    float gethistoryGrade();

    bool setenglishGrade(float val);
    float getenglishGrade();

    float getaverageGrade();
};