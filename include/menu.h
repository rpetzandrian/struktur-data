#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "hospital.h"
#include "schedule.h"
#include "doctor.h"

using namespace std;

void showMenu();
void handleChoice(HospitalList &H, DoctorList &D);
void handleExit();
void clearScreen();
void createHospital(HospitalList &H);
void createDoctor(DoctorList &D);
void createSchedule(HospitalList &H, DoctorList &D);
void deleteHospital();
void deleteDoctor();
void deleteSchedule();
void searchHospital();
void searchDoctor();
void searchSchedule();
void showHospitalList(HospitalList &H);
void showDoctorList(DoctorList &D);
void showDoctorFromHospital();
void showHospitalWithDetail();
void doctorWithDetail();
void countScheduleInHospital();
void countScheduleInDoctor();
void countDoctorWithoutSchedule();
void editDoctorScheduleInHospital();

#endif