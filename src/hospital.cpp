#include <iostream>
#include <vector>
#include "hospital.h"
#include "doctor.h"
#include "table.h"

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

    if (P == NULL || info(P).id != id)
    {
        cout << "Data rumah sakit tidak ditemukan" << endl;
        return NULL;
    }

    return P;
}

void showHospital(HospitalList H, bool withDetail)
{
    hospitalAdr P = first(H);
    while (P != NULL)
    {
        cout << "ID: " << info(P).id << endl;
        cout << "Nama Rumah Sakit: " << info(P).name << endl;
        cout << "Alamat: " << info(P).hospital_address << endl;

        ScheduleList SL = schedule(P);
        ScheduleAdr S = first(SL);
        while (S != NULL && withDetail)
        {
            cout << "===================================" << endl;
            cout << "Id Jadwal: " << info(S).id << endl;
            cout << "Hari: " << info(S).day << endl;
            cout << "Mulai: " << info(S).start << endl;
            cout << "Berakhir: " << info(S).end << endl;
            if (doctor(S) != NULL)
            {
                cout << "Dokter saat ini: " << info(doctor(S)).name << endl;
            }
            else
            {
                cout << "Dokter saat ini : -" << endl;
            }
            S = next(S);
            cout << "===================================" << endl;
        }

        cout << "+-----------------------------------+" << endl;
        P = next(P);
    }
}

void showDoctorFromHospitals(HospitalList H)
{
    hospitalAdr P = first(H);
    while (P != NULL)
    {
        vector<vector<string>> data;

        ScheduleList SL = schedule(P);
        ScheduleAdr S = first(SL);
        while (S != NULL)
        {
            if (doctor(S) != NULL)
            {
                data.push_back(vector<string>{info(doctor(S)).name, info(doctor(S)).speciality});
            }
            S = next(S);
        }
        string title = info(P).name + "\n#ID" + info(P).id + "\n" + info(P).hospital_address;
        try
        {
            printTable(2, 20, title, data);
        }
        catch (const exception &e)
        {
            cerr << "error : " << e.what() << endl;
        }
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

        cout << "ID: " << info(P).id << endl;
        cout << "Total Jadwal: " << count << endl;

        P = next(P);
    }
}

int countDoctorInHospital(HospitalList H, string doctorId)
{
    int count = 0;
    hospitalAdr h = first(H);
    while (h != NULL)
    {
        DoctorAdr d = searchDoctorInSchedule(schedule(h), doctorId);

        if (d != NULL)
        {
            count++;
        }

        h = next(h);
    }

    return count;
}

void deleteDoctorInHospital(HospitalList H, string doctorId)
{
    hospitalAdr h = first(H);
    while (h != NULL)
    {
        deleteDoctorInSchedule(schedule(h), doctorId);
        h = next(h);
    }

    return;
}