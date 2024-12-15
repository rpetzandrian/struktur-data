#include <iostream>
#include "schedule.h"

using namespace std;

void createScheduleList(ScheduleList &S)
{
    first(S) = NULL;
}

ScheduleAdr createScheduleElm(ScheduleInfo s, DoctorAdr d)
{
    ScheduleAdr P = new ScheduleElement;
    info(P) = s;
    next(P) = NULL;
    P->doctor = d;
    return P;
}

void insertSchedule(ScheduleList &S, ScheduleAdr P)
{
    if (first(S) == NULL)
    {
        first(S) = P;
    }
    else
    {
        ScheduleAdr Q = first(S);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

ScheduleAdr deleteSchedule(ScheduleList &S, string id)
{
    ScheduleAdr P = findSchedule(S, id);
    if (P != NULL)
    {
        if (P == first(S))
        {
            first(S) = next(P);
            next(P) = NULL;
        }
        else
        {
            ScheduleAdr Q = first(S);
            while (next(Q) != P)
            {
                Q = next(Q);
            }
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
    return P;
}

ScheduleAdr findSchedule(ScheduleList S, string id)
{
    ScheduleAdr P = first(S);
    while (P != NULL && info(P).id != id)
    {
        P = next(P);
    }

    if (P == NULL || info(P).id != id)
    {
        cout << "Data jadwal tidak ditemukan" << endl;
        return NULL;
    }

    return P;
}

void showSchedule(ScheduleList S)
{
    ScheduleAdr P = first(S);
    cout << "LIST JADWAL" << endl;

    while (P != NULL)
    {
        cout << "+---------------------------------------+" << endl;
        cout << "ID: " << info(P).id << endl;
        cout << "Day: " << info(P).day << endl;
        cout << "Start: " << info(P).start << endl;
        cout << "End: " << info(P).end << endl;
        if (doctor(P) != NULL)
        {
            cout << "Dokter saat ini: " << info(doctor(P)).name << endl;
        }
        else
        {
            cout << "Dokter saat ini: -" << endl;
        }
        cout << "+---------------------------------------+" << endl;

        P = next(P);
    }
}

void insertDoctorToSchedule(ScheduleAdr P, DoctorAdr D)
{
    doctor(P) = D;
}

int countSchedule(ScheduleList S)
{
    // count total schedule
    int count = 0;
    ScheduleAdr P = first(S);
    while (P != NULL)
    {
        count++;
        P = next(P);
    }

    return count;
}

DoctorAdr searchDoctorInSchedule(ScheduleList S, string doctorId)
{
    ScheduleAdr P = first(S);
    while (P != NULL)
    {
        if (info(doctor(P)).id == doctorId)
        {
            return doctor(P);
        }

        P = next(P);
    }

    return NULL;
}