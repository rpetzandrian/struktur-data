
#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

struct DoctorInfo
{
    string id;
    string sip_number;
    string name;
    string speciality;
    int age;
};

typedef struct DoctorElement *DoctorAdr;

struct DoctorElement
{
    DoctorInfo info;
    DoctorAdr next;
    DoctorAdr prev;
};

struct DoctorList
{
    DoctorAdr first;
    DoctorAdr last;
};

void createDoctorList(DoctorList &D);
DoctorAdr createDoctorElm(DoctorInfo d);
void insertDoctor(DoctorList &D, DoctorAdr P);
DoctorAdr deleteDoctor(DoctorList &D, string id);
DoctorAdr findDoctor(DoctorList D, string id);
void showDoctor(DoctorList D);

#endif
