#include <iostream>
#include "Student.h"
#include "Global.h"
int main(){
    Student s1,s2;

    char s[51];
    std::cout<<"Introdu nume student 1: ";
    std::cin>>s;
    s1.setName(s);

    std::cout<<"Introdu nume student 2: ";
    std::cin>>s;
    s2.setName(s);

    float a,b,c;
    std::cout<<"Introdu note student 1(mate engleza istorie): ";
    std::cin>>a>>b>>c;
    s1.setmathGrade(a);
    s1.setenglishGrade(b);
    s1.sethistoryGrade(c);

    std::cout<<"Introdu note student 2(mate engleza istorie): ";
    std::cin>>a>>b>>c;
    s2.setmathGrade(a);
    s2.setenglishGrade(b);
    s2.sethistoryGrade(c);

    int comp = comparemathGrade(s1, s2);
    if (comp == -1)
        std::cout << "Studentul 1 are nota mai mica la mate decat Studentul 2\n";
    else if(comp==1)
        std::cout << "Studentul 1 are nota mai mare la mate decat Studentul 2\n";
    else
        std::cout << "Studentul 1 are aceeasi nota la mate ca Studentul 2\n";

    comp = compareenglishGrade(s1, s2);
    if (comp == -1)
        std::cout << "Studentul 1 are nota mai mica la engleza decat Studentul 2\n";
    else if (comp == 1)
        std::cout << "Studentul 1 are nota mai mare la engleza decat Studentul 2\n";
    else
        std::cout << "Studentul 1 are aceeasi nota la engleza ca Studentul 2\n";

    comp = comparehistoryGrade(s1, s2);
    if (comp == -1)
        std::cout << "Studentul 1 are nota mai mica la istorie decat Studentul 2\n";
    else if (comp == 1)
        std::cout << "Studentul 1 are nota mai mare la istorie decat Studentul 2\n";
    else
        std::cout << "Studentul 1 are aceeasi nota la istorie ca Studentul 2\n";

    comp = compareAverage(s1, s2);
    if (comp == -1)
        std::cout << "Studentul 1 are media mai mica decat Studentul 2\n";
    else if (comp == 1)
        std::cout << "Studentul 1 are media mai mare decat Studentul 2\n";
    else
        std::cout << "Studentul 1 are aceeasi medie ca Studentul 2\n";

    comp = compareName(s1, s2);
    if (comp == -1)
        std::cout << "Studentul 1 este inaintea Studentului 2 in ordinea lexicografica\n";
    else if (comp == 1)
        std::cout << "Studentul 2 este inaintea Studentului 1 in ordinea lexicografica\n";
    else
        std::cout << "Studentul 1 si Studentul 2 au acelasi nume!\n";

    
    
}