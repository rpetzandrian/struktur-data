
#include <iostream>
#include "hospital.h"
#include "doctor.h"
#include "menu.h"

using namespace std;

int main()
{
    HospitalList H;
    createHospitalList(H);

    DoctorList D;
    createDoctorList(D);

    handleChoice(H, D);

    return 0;
}
