
#include <iostream>
#include "hospital.h"
#include "doctor.h"
#include "menu.h"
//#include "table.h"

using namespace std;

// void addDoctor(DoctorList &D, DoctorAdr newDoctor) {
//     if (newDoctor == NULL) return;

//     if (D.first == NULL) {
//         // List is empty, newDoctor becomes the first and last element
//         D.first = newDoctor;
//         D.last = newDoctor;
//     } else {
//         // Add newDoctor to the end of the list
//         newDoctor->prev = D.last;
//         D.last->next = newDoctor;
//         D.last = newDoctor;
//     }
// }

int main()
{
    HospitalList H;
    createHospitalList(H);

    DoctorList D;
    createDoctorList(D);
    // DoctorInfo doctor1 = {"1", "SIP123", "Dr. John", "Cardiologist", 45};
    // addDoctor(D, createDoctorElm(doctor1));

    handleChoice(H, D);

    return 0;
}
