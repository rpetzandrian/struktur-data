#include <iostream>
#include "schedule.h"

using namespace std;

void createScheduleList(ScheduleList &S)
{
    first(S) = NULL;
}

ScheduleAdr createScheduleElm(ScheduleInfo s)
{
    ScheduleAdr P = new ScheduleElement;
    info(P) = s;
    next(P) = NULL;
    doctor(P) = NULL;
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
    return P;
}

void showSchedule(ScheduleList S)
{
    ScheduleAdr P = first(S);
    while (P != NULL)
    {
        cout << "ID: " << info(P).id << endl;
        cout << "Day: " << info(P).day << endl;
        cout << "Start: " << info(P).start << endl;
        cout << "End: " << info(P).end << endl;
        P = next(P);
    }
}

void insertDoctorToSchedule(ScheduleList &S, ScheduleAdr P, DoctorAdr D)
{
    doctor(P) = D;
}