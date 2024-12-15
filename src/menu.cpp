#include <iostream>
#include "menu.h"
#include "hospital.h"
#include "schedule.h"
#include "doctor.h"

using namespace std;

void showMenu()
{
    cout << "=== Menu Aplikasi ===" << endl;
    cout << "1. Membuat data Rumah Sakit" << endl;
    cout << "2. Membuat data Dokter" << endl;
    cout << "3. Membuat Penjadwalan Dokter" << endl;
    cout << "4. Hapus Data Rumah Sakit" << endl;
    cout << "5. Hapus Data Dokter" << endl;
    cout << "6. Hapus Penjadwalan Dokter" << endl;
    cout << "7. Cari Data Rumah Sakit" << endl;
    cout << "8. Cari Data Dokter" << endl;
    cout << "9. Cari Data Jadwal" << endl;
    cout << "10. Tampilkan Data Rumah Sakit" << endl;
    cout << "11. Tampilkan Data Dokter" << endl;
    cout << "12. Tampilkan Data Dokter dari Rumah Sakit" << endl;
    cout << "13. Tampilkan Data Rumah Sakit dengan Detail" << endl;
    cout << "14. Tampilkan Data Dokter dengan Detail" << endl;
    cout << "15. Hitung Jumlah Jadwal di Rumah Sakit" << endl;
    cout << "16. Hitung Jumlah Jadwal Dokter" << endl;
    cout << "17. Hitung Jumlah Dokter tanpa Jadwal" << endl;
    cout << "18. Edit Jadwal Dokter di Rumah Sakit" << endl;
    cout << "0. Keluar" << endl;
    cout << "=====================" << endl;
    cout << "Pilih opsi: ";
}

void handleExit()
{
    int choice;
    do
    {
        cout << "Klik 0 to exit." << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            clearScreen();
            break;
        default:
            cout << "Opsi tidak valid" << endl;
            break;
        }
    } while (choice != 0);
}

void handleChoice(HospitalList &H, DoctorList &D)
{
    int choice;
    do
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            createHospital(H);
            handleExit();
            break;
        case 2:
            createDoctor(D);
            handleExit();
            break;
        case 3:
            createSchedule(H, D);
            handleExit();
            break;
        case 4:
            deleteHospital();
            handleExit();
            break;
        case 5:
            deleteDoctor(D);
            handleExit();
            break;
        case 6:
            deleteSchedule();
            handleExit();
            break;
        case 7:
            searchHospital(H);
            handleExit();
            break;
        case 8:
            searchDoctor(D);
            handleExit();
            break;
        case 9:
            searchSchedule();
            handleExit();
            break;
        case 10:
            showHospitalList(H);
            handleExit();
            break;
        case 11:
            showDoctorList(D);
            handleExit();
            break;
        case 12:
            showDoctorFromHospital();
            handleExit();
            break;
        case 13:
            showHospitalWithDetail(H);
            handleExit();
            break;
        case 14:
            doctorWithDetail();
            handleExit();
            break;
        case 15:
            countScheduleInHospital();
            handleExit();
            break;
        case 16:
            countScheduleInDoctor();
            handleExit();
            break;
        case 17:
            countDoctorWithoutSchedule();
            handleExit();
            break;
        case 18:
            editDoctorScheduleInHospital();
            handleExit();
            break;
        case 0:
            cout << "Keluar dari aplikasi" << endl;
            break;
        default:
            cout << "Opsi tidak valid" << endl;
            break;
        }
    } while (choice != 0);
}

void clearScreen()
{
    system("cls||clear");
}

void createHospital(HospitalList &H)
{
    HospitalInfo hospitalInfo;
    cout << "Masukkan ID Rumah Sakit: ";
    cin >> hospitalInfo.id;
    cout << "Masukkan Nama Rumah Sakit: ";
    cin >> hospitalInfo.name;
    cout << "Masukkan Alamat Rumah Sakit: ";
    cin >> hospitalInfo.hospital_address;

    ScheduleList S;
    createScheduleList(S);

    hospitalAdr hospital = createHospitalElm(hospitalInfo, S);
    insertHospital(H, hospital);
}

void createDoctor(DoctorList &D)
{
    DoctorInfo doctorInfo;
    cout << "Masukkan ID Dokter: ";
    cin >> doctorInfo.id;
    cout << "Masukkan Nama Dokter: ";
    cin >> doctorInfo.name;
    cout << "Masukkan Nomor SIP: ";
    cin >> doctorInfo.sip_number;
    cout << "Masukkan Umur: ";
    cin >> doctorInfo.age;
    cout << "Masukkan Spesialisasi Dokter: ";
    cin >> doctorInfo.speciality;

    DoctorAdr doctor = createDoctorElm(doctorInfo);
    insertDoctor(D, doctor);
}

void createSchedule(HospitalList &H, DoctorList &D)
{
    string hospitalID;
    cout << "Masukkan ID Rumah Sakit: ";
    cin >> hospitalID;
    hospitalAdr h = findHospital(H, hospitalID);

    string doctorID;
    cout << "Masukkan ID Dokter: ";
    cin >> doctorID;
    DoctorAdr d = findDoctor(D, doctorID);

    ScheduleInfo scheduleInfo;
    cout << "Masukkan ID Jadwal: ";
    cin >> scheduleInfo.id;
    cout << "Masukkan Hari: ";
    cin >> scheduleInfo.day;
    cout << "Masukkan Jam Mulai: ";
    cin >> scheduleInfo.start;
    cout << "Masukkan Jam Selesai: ";
    cin >> scheduleInfo.end;

    ScheduleAdr schedule = createScheduleElm(scheduleInfo);
    insertSchedule(schedule(h), schedule);
}

void deleteHospital()
{
    cout << "Not Implemented" << endl;
}

void deleteDoctor(DoctorList &D)
{
    // find doctor by id
    string id;
    cout << "Masukkan ID Dokter: ";
    cin >> id;
    DoctorAdr d = findDoctor(D, id);

    if (d != NULL)
    {
        deleteDoctor(D, id);
        cout << "Dokter berhasil dihapus" << endl;
    }
    else
    {
        cout << "Dokter tidak ditemukan" << endl;
    }
}

void deleteSchedule()
{
    cout << "Not Implemented" << endl;
}

void searchHospital(HospitalList &H)
{
    string id;
    cout << "Masukkan ID Rumah Sakit: ";
    cin >> id;
    hospitalAdr h = findHospital(H, id);

    if (h != NULL)
    {
        cout << "ID: " << info(h).id << endl;
        cout << "Nama: " << info(h).name << endl;
        cout << "Alamat: " << info(h).hospital_address << endl;
    }
    else
    {
        cout << "Rumah Sakit tidak ditemukan" << endl;
    }
}

void searchDoctor(DoctorList &D)
{
    // find doctor by id
    string id;
    cout << "Masukkan ID Dokter: ";
    cin >> id;
    DoctorAdr d = findDoctor(D, id);

    if (d != NULL)
    {
        cout << "ID: " << info(d).id << endl;
        cout << "Nama: " << info(d).name << endl;
        cout << "Nomor SIP: " << info(d).sip_number << endl;
        cout << "Umur: " << info(d).age << endl;
        cout << "Spesialisasi: " << info(d).speciality << endl;
    }
    else
    {
        cout << "Dokter tidak ditemukan" << endl;
    }
}

void searchSchedule()
{
    cout << "Not Implemented" << endl;
}

void showHospitalList(HospitalList &H)
{
    showHospital(H);
}

void showDoctorList(DoctorList &D)
{
    showDoctor(D);
}

void showDoctorFromHospital()
{
    cout << "Not Implemented" << endl;
}

void showHospitalWithDetail(HospitalList &H)
{
    showHospital(H, true);
}

void doctorWithDetail()
{
    cout << "Not Implemented" << endl;
}

void countScheduleInHospital()
{
    cout << "Not Implemented" << endl;
}

void countScheduleInDoctor()
{
    cout << "Not Implemented" << endl;
}

void countDoctorWithoutSchedule()
{
    cout << "Not Implemented" << endl;
}

void editDoctorScheduleInHospital()
{
    cout << "Not Implemented" << endl;
}