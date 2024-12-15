#include <iostream>
#include "doctor.h"

using namespace std;

void createDoctorList(DoctorList &D)
{
    first(D) = NULL;
    last(D) = NULL;
}

DoctorAdr createDoctorElm(DoctorInfo d)
{
    DoctorAdr P = new DoctorElement;
    info(P) = d;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertDoctor(DoctorList &D, DoctorAdr P)
{
    if (first(D) == NULL)
    {
        first(D) = P;
        last(D) = P;
    }
    else
    {
        next(last(D)) = P;
        prev(P) = last(D);
        last(D) = P;
    }
}

DoctorAdr deleteDoctor(DoctorList &D, string id)
{
    DoctorAdr P = findDoctor(D, id);
    if (P != NULL)
    {
        if (P == first(D))
        {
            first(D) = next(P);
            prev(first(D)) = NULL;
            next(P) = NULL;
        }
        else if (P == last(D))
        {
            last(D) = prev(P);
            next(last(D)) = NULL;
            prev(P) = NULL;
        }
        else
        {
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
    return P;
}

DoctorAdr findDoctor(DoctorList D, string id)
{
    DoctorAdr P = first(D);
    while (P != NULL && info(P).id != id)
    {
        P = next(P);
    }

    if (info(P).id != id)
    {
        cout << "Data dokter tidak ditemukan" << endl;
        return NULL;
    }

    return P;
}

void showDoctor(DoctorList D)
{
    DoctorAdr P = first(D);
    while (P != NULL)
    {
        cout << "ID: " << info(P).id << endl;
        cout << "SIP Number: " << info(P).sip_number << endl;
        cout << "Name: " << info(P).name << endl;
        cout << "Speciality: " << info(P).speciality << endl;
        cout << "Age: " << info(P).age << endl;
        cout << endl;
        P = next(P);
    }
}