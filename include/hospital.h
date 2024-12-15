
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <iostream>
#include "schedule.h"
#include "doctor.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define schedule(P) P->schedule

using namespace std;

struct HospitalInfo
{
    string id;
    string name;
    string hospital_address;
};

typedef struct HospitalElement *hospitalAdr;

struct HospitalElement
{
    HospitalInfo info;
    ScheduleList schedule;
    hospitalAdr next;
};

struct HospitalList
{
    hospitalAdr first;
};

void createHospitalList(HospitalList &H);
hospitalAdr createHospitalElm(HospitalInfo h, ScheduleList &S);
void insertHospital(HospitalList &H, hospitalAdr P);
hospitalAdr deleteHospital(HospitalList &H, string id);
hospitalAdr findHospital(HospitalList H, string id);
void showHospital(HospitalList H, bool withDetail);
void showDoctorFromHospitals(HospitalList H);
void countEveryHospitalSchedule(HospitalList H);
int countDoctorInHospital(HospitalList H, string doctorId);

#endif