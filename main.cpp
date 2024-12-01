
#include <iostream>
#include "hospital.h"
#include "schedule.h"
#include "doctor.h"

using namespace std;

int main()
{
    // Create Doctor List
    DoctorList D;
    createDoctorList(D);
    // create 5 doctor element
    DoctorAdr D1 = createDoctorElm({"D001", "123456789", "Dr. A", "General", 30});
    DoctorAdr D2 = createDoctorElm({"D002", "123456789", "Dr. B", "General", 30});
    DoctorAdr D3 = createDoctorElm({"D003", "123456789", "Dr. C", "General", 30});
    DoctorAdr D4 = createDoctorElm({"D004", "123456789", "Dr. D", "General", 30});
    DoctorAdr D5 = createDoctorElm({"D005", "123456789", "Dr. E", "General", 30});

    // insert doctor element to doctor list
    insertDoctor(D, D1);
    insertDoctor(D, D2);
    insertDoctor(D, D3);
    insertDoctor(D, D4);
    insertDoctor(D, D5);

    // Create 3 Schedule List
    ScheduleList S1, S2, S3;
    createScheduleList(S1);
    createScheduleList(S2);
    createScheduleList(S3);

    // create 3 schedule per list
    ScheduleAdr S1_1 = createScheduleElm({"S001", "Monday", "08.00", "12.00"});
    ScheduleAdr S1_2 = createScheduleElm({"S002", "Tuesday", "08.00", "12.00"});
    ScheduleAdr S1_3 = createScheduleElm({"S003", "Wednesday", "08.00", "12.00"});

    ScheduleAdr S2_1 = createScheduleElm({"S004", "Monday", "08.00", "12.00"});
    ScheduleAdr S2_2 = createScheduleElm({"S005", "Tuesday", "08.00", "12.00"});
    ScheduleAdr S2_3 = createScheduleElm({"S006", "Wednesday", "08.00", "12.00"});

    ScheduleAdr S3_1 = createScheduleElm({"S007", "Monday", "08.00", "12.00"});
    ScheduleAdr S3_2 = createScheduleElm({"S008", "Tuesday", "08.00", "12.00"});
    ScheduleAdr S3_3 = createScheduleElm({"S009", "Wednesday", "08.00", "12.00"});

    // insert schedule element to schedule list
    insertSchedule(S1, S1_1);
    insertSchedule(S1, S1_2);
    insertSchedule(S1, S1_3);

    insertSchedule(S2, S2_1);
    insertSchedule(S2, S2_2);
    insertSchedule(S2, S2_3);

    insertSchedule(S3, S3_1);
    insertSchedule(S3, S3_2);
    insertSchedule(S3, S3_3);

    // insert doctor to schedule
    insertDoctorToSchedule(S1, S1_1, D1);
    insertDoctorToSchedule(S1, S1_2, D2);
    insertDoctorToSchedule(S1, S1_3, D3);

    insertDoctorToSchedule(S2, S2_1, D2);
    insertDoctorToSchedule(S2, S2_2, D3);
    insertDoctorToSchedule(S2, S2_3, D4);

    insertDoctorToSchedule(S3, S3_1, D3);
    insertDoctorToSchedule(S3, S3_2, D4);
    insertDoctorToSchedule(S3, S3_3, D5);

    // create Hospital List
    HospitalList H;
    createHospitalList(H);

    // create 4 hospital element
    hospitalAdr H1 = createHospitalElm({"H001", "Hospital A", "Jl. A"});
    hospitalAdr H2 = createHospitalElm({"H002", "Hospital B", "Jl. B"});
    hospitalAdr H3 = createHospitalElm({"H003", "Hospital C", "Jl. C"});
    hospitalAdr H4 = createHospitalElm({"H004", "Hospital D", "Jl. D"});

    // insert hospital element to hospital list
    insertHospital(H, H1);
    insertHospital(H, H2);
    insertHospital(H, H3);
    insertHospital(H, H4);

    // insert schedule to hospital
    insertHospitalSchedule(H, H1, first(S1));
    insertHospitalSchedule(H, H2, first(S2));
    insertHospitalSchedule(H, H3, first(S3));

    // show hospital list
    showHospital(H);

    return 0;
}
