#pragma once
#include "Global.h"
#include <cstring>
int comparemathGrade(Student& a,Student& b){
    float f1=a.getmathGrade(),f2=b.getmathGrade();
    if(f1<f2)
        return -1;
    else if(f1>f2)
        return 1;
    else
        return 0;
}
int compareenglishGrade(Student& a,Student& b){
    float f1=a.getenglishGrade(),f2=b.getenglishGrade();
    if(f1<f2)
        return -1;
    else if(f1>f2)
        return 1;
    else
        return 0;
}
int comparehistoryGrade(Student& a,Student& b){
    float f1=a.gethistoryGrade(),f2=b.gethistoryGrade();
    if(f1<f2)
        return -1;
    else if(f1>f2)
        return 1;
    else
        return 0;
}
int compareName(Student& a,Student& b){
    char* s1=a.getName(),*s2=b.getName();
    int len1=strlen(s1),len2=strlen(s2);
    if(len1<len2)
        return -1;
    else if(len1>len2)
        return 1;
    else{
        for(int i=0;i<len1;i++){
            if(s1[i]<s2[i])
                return -1;
            else if(s1[i]>s2[i])
                return 1;
        }
        return 0;
    }
}
int compareAverage(Student& a,Student& b){
    float f1=a.getaverageGrade(),f2=b.getaverageGrade();
    if(f1<f2)
        return -1;
    else if(f1>f2)
        return 1;
    else
        return 0;
}