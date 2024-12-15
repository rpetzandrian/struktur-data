#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "hospital.h"
#include "schedule.h"
#include "doctor.h"

using namespace std;

/**
    a. Insert element parent : 5
    b. Insert element child : 5
    c. Insert element relation : 5
    d. Delete element parent : 5
    e. Delete element child : 5
    f. Delete element relation : 5
    g. Find element Parent : 5
    h. Find element child : 5
    i. Find element relation : 5
    j. Show all data di List Parent : 5
    k. Show all data di List Child : 5
    l. Show data child dari parent tertentu : 5
    m. Show setiap data parent beserta data child yang berelasi dengannya : 5
    n. Show data child beserta data parent yang masing-masing child miliki : 10
    o. Show data parent yang berelasi dengan child tertentu : 5
    p. Count relation dari setiap element parent : 5
    q. Count relation yang dimiliki oleh child tertentu : 5
    r. Count element child yang tidak memiliki relasi : 5
    s. Edit relasi /mengganti child dari parent tertentu : 5
 */

void showMenu();
void handleChoice(HospitalList &H, DoctorList &D);
void handleExit();
void clearScreen();
void createHospital(HospitalList &H);
void createDoctor(DoctorList &D);
void createSchedule(HospitalList &H, DoctorList &D);
void deleteHospitals(HospitalList &H);
void deleteDoctors(DoctorList &D);
void deleteSchedules(HospitalList &H);
void searchHospital(HospitalList &H);
void searchDoctor(DoctorList &D);
void searchSchedule();
void showHospitalList(HospitalList &H);
void showDoctorList(DoctorList &D);
void showDoctorFromHospital(HospitalList H);
void showHospitalWithDetail(HospitalList &H);
void doctorWithDetail();
void countScheduleInHospital(HospitalList &H);
void countScheduleInDoctor(HospitalList &H, DoctorList &D);
void countDoctorWithoutSchedule(HospitalList &H, DoctorList &D);
void editDoctorScheduleInHospital(HospitalList &H, DoctorList &D);

#endif