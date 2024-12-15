
#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include "doctor.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define doctor(P) P->doctor

using namespace std;

struct ScheduleInfo
{
    string id;
    string day;
    string start;
    string end;
};

typedef struct ScheduleElement *ScheduleAdr;

struct ScheduleElement
{
    ScheduleInfo info;
    DoctorAdr doctor;
    ScheduleAdr next;
};

struct ScheduleList
{
    ScheduleAdr first;
};

void createScheduleList(ScheduleList &S);
ScheduleAdr createScheduleElm(ScheduleInfo s, DoctorAdr d);
void insertSchedule(ScheduleList &S, ScheduleAdr P);
ScheduleAdr deleteSchedule(ScheduleList &S, string id);
ScheduleAdr findSchedule(ScheduleList S, string id);
void showSchedule(ScheduleList S);
void insertDoctorToSchedule(ScheduleList &S, ScheduleAdr P, DoctorAdr D);
int countSchedule(ScheduleList S);

#endif