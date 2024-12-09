#include <iostream>
#include "hospital.h"

using namespace std;

void createHospitalList(HospitalList &H)
{
    first(H) = NULL;
}

hospitalAdr createHospitalElm(HospitalInfo h, ScheduleList &S)
{
    hospitalAdr P = new HospitalElement;
    info(P) = h;
    next(P) = NULL;
    schedule(P) = S;
    return P;
}

void insertHospital(HospitalList &H, hospitalAdr P)
{
    if (first(H) == NULL)
    {
        first(H) = P;
    }
    else
    {
        hospitalAdr Q = first(H);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

hospitalAdr deleteHospital(HospitalList &H, string id)
{
    hospitalAdr P = findHospital(H, id);
    if (P != NULL)
    {
        if (P == first(H))
        {
            first(H) = next(P);
            next(P) = NULL;
        }
        else
        {
            hospitalAdr Q = first(H);
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

hospitalAdr findHospital(HospitalList H, string id)
{
    hospitalAdr P = first(H);
    while (P != NULL && info(P).id != id)
    {
        P = next(P);
    }
    return P;
}

void showHospital(HospitalList H)
{
    hospitalAdr P = first(H);
    while (P != NULL)
    {
        cout << "Hospital ID: " << info(P).id << endl;
        cout << "Hospital Name: " << info(P).name << endl;
        cout << "Hospital Address: " << info(P).hospital_address << endl;

        ScheduleList SL = schedule(P);
        ScheduleAdr S = first(SL);
        while (S != NULL)
        {
            cout << "===================================" << endl;
            cout << "Schedule ID: " << info(S).id << endl;
            cout << "Day: " << info(S).day << endl;
            cout << "Start: " << info(S).start << endl;
            cout << "End: " << info(S).end << endl;
            if (doctor(S) != NULL)
            {
                cout << "Doctor Name: " << info(doctor(S)).name << endl;
            }
            S = next(S);
            cout << "===================================" << endl;
        }

        cout << "+-----------------------------------+" << endl;
        P = next(P);
    }
}

void countEveryHospitalSchedule(HospitalList H)
{
    hospitalAdr P = first(H);
    while (P != NULL)
    {
        int count = 0;
        ScheduleList SL = schedule(P);
        ScheduleAdr S = first(SL);
        while (S != NULL)
        {
            count++;
            S = next(S);
        }

        cout << "Hospital ID: " << info(P).id << endl;
        cout << "Total Schedule: " << count << endl;

        P = next(P);
    }
}