#include <iostream>
#include <vector>
#include "table.h"
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
    cout << "13. Tampilkan Data Rumah Sakit dari list Dokter" << endl;
    cout << "14. Tampilkan Data list rumah sakit dari Dokter" << endl;
    cout << "15. Tampilkan Data Rumah Sakit dengan Detail" << endl;
    cout << "16. Hitung Jumlah Jadwal di Rumah Sakit" << endl;
    cout << "17. Hitung Jumlah Jadwal Dokter" << endl;
    cout << "18. Hitung Jumlah Dokter tanpa Jadwal" << endl;
    cout << "19. Edit Jadwal Dokter di Rumah Sakit" << endl;
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
            // 1. Membuat data Rumah Sakit
            createHospital(H);
            handleExit();
            break;
        case 2:
            // 2. Membuat data Dokter
            createDoctor(D);
            handleExit();
            break;
        case 3:
            // 3. Membuat Penjadwalan Dokter
            createSchedule(H, D);
            handleExit();
            break;
        case 4:
            // 4. Hapus Data Rumah Sakit
            deleteHospitals(H);
            handleExit();
            break;
        case 5:
            // 5. Hapus Data Dokter
            deleteDoctors(D, H);
            handleExit();
            break;
        case 6:
            // 6. Hapus Penjadwalan Dokter
            deleteSchedules(H);
            handleExit();
            break;
        case 7:
            // 7. Cari Data Rumah Sakit
            searchHospital(H);
            handleExit();
            break;
        case 8:
            // 8. Cari Data Dokter
            searchDoctor(D);
            handleExit();
            break;
        case 9:
            // 9. Cari Data Jadwal
            searchSchedule(H);
            handleExit();
            break;
        case 10:
            // 10. Tampilkan Data Rumah Sakit
            showHospitalList(H);
            handleExit();
            break;
        case 11:
            // 11. Tampilkan Data Dokter
            showDoctorList(D);
            handleExit();
            break;
        case 12:
            // 12. Tampilkan Data Dokter dari Rumah Sakit
            showDoctorFromHospitals(H);
            handleExit();
            break;
        case 13:
            // 13. Tampilkan Data Rumah Sakit dari list Dokter
            showHospitalListFromDoctorList(D, H);
            handleExit();
            break;
        case 14:
            // 14. Tampilkan Data list rumah sakit dari Dokter
            doctorWithDetail(D, H);
            handleExit();
            break;
        case 15:
            // 15. Tampilkan Data Rumah Sakit dengan Detail
            showHospitalWithDetail(H);
            handleExit();
            break;
        case 16:
            // 16. Hitung Jumlah Jadwal di Rumah Sakit
            countScheduleInHospital(H);
            handleExit();
            break;
        case 17:
            // 17. Hitung Jumlah Jadwal Dokter
            countScheduleInDoctor(H, D);
            handleExit();
            break;
        case 18:
            // 18. Hitung Jumlah Dokter tanpa Jadwal
            countDoctorWithoutSchedule(H, D);
            handleExit();
            break;
        case 19:
            // 19. Edit Jadwal Dokter di Rumah Sakit
            editDoctorScheduleInHospital(H, D);
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
    cin.ignore();

    if (findHospital(H, hospitalInfo.id) != NULL)
    {
        cout << "ID Rumah Sakit sudah ada" << endl;
        return;
    }

    cout << "Masukkan Nama Rumah Sakit: ";
    std::getline(cin, hospitalInfo.name);

    cout << "Masukkan Alamat Rumah Sakit: ";
    std::getline(cin, hospitalInfo.hospital_address);

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

    if (findDoctor(D, doctorInfo.id) != NULL)
    {
        cout << "ID Dokter sudah ada" << endl;
        return;
    }

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

    if (searchDoctorInSchedule(schedule(h), doctorID) != NULL)
    {
        cout << "Dokter " << doctorID << " sudah jadwal di rumah sakit ini" << endl;
        return;
    }

    ScheduleInfo scheduleInfo;
    cout << "Masukkan ID Jadwal: ";
    cin >> scheduleInfo.id;

    if (findSchedule(h->schedule, scheduleInfo.id) != NULL)
    {
        cout << "ID Jadwal sudah ada" << endl;
        return;
    }

    cout << "Masukkan Hari: ";
    cin >> scheduleInfo.day;
    cout << "Masukkan Jam Mulai: ";
    cin >> scheduleInfo.start;
    cout << "Masukkan Jam Selesai: ";
    cin >> scheduleInfo.end;

    ScheduleAdr schedule = createScheduleElm(scheduleInfo, d);
    insertSchedule(schedule(h), schedule);
}

void deleteHospitals(HospitalList &H)
{
    string id;
    cout << "Masukkan ID Rumah Sakit : ";
    cin >> id;
    hospitalAdr hospital = deleteHospital(H, id);
    if (hospital != NULL)
    {
        cout << "Data Rumah Sakit berhasil terhapus" << endl;
    }
    else
    {
        cout << "Data Rumah Sakit tidak ditemukan" << endl;
    }
}
void deleteDoctors(DoctorList &D, HospitalList &H)
{
    string id;
    cout << "Masukkan ID Dokter : ";
    cin >> id;
    DoctorAdr doctor = deleteDoctor(D, id);
    if (doctor != NULL)
    {
        deleteDoctorInHospital(H, id);
        cout << "Data dokter berhasil terhapus" << endl;
    }
    else
    {
        cout << "Data dokter tidak ditemukan" << endl;
    }
}
void deleteSchedules(HospitalList &H)
{
    string id;
    string id_rs;
    cout << "Masukkan ID Jadwal : ";
    cin >> id;
    cout << "Masukkan ID Rumah Sakit : ";
    cin >> id_rs;
    hospitalAdr hospital = findHospital(H, id_rs);
    ScheduleAdr schedule = deleteSchedule(hospital->schedule, id);
    if (schedule != NULL)
    {
        cout << "Data jadwal berhasil terhapus" << endl;
    }
    else
    {
        cout << "Data jadwal tidak ditemukan" << endl;
    }
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

void searchSchedule(HospitalList &H)
{
    string id;
    string id_rs;
    cout << "Masukkan ID Jadwal : ";
    cin >> id;
    cout << "Masukkan ID Rumah Sakit : ";
    cin >> id_rs;
    hospitalAdr hospital = findHospital(H, id_rs);
    if (hospital != NULL)
    {
        ScheduleAdr schedule = findSchedule(hospital->schedule, id);
        if (schedule != NULL)
        {
            cout << "ID : " << info(schedule).id << endl;
            cout << "Hari : " << info(schedule).day << endl;
            cout << "Mulai : " << info(schedule).start << endl;
            cout << "Berakhir : " << info(schedule).end << endl;
            if (doctor(schedule) != NULL)
            {
                cout << "Dokter saat ini : " << info(doctor(schedule)).name << endl;
            }
            else
            {
                cout << "Dokter saat ini : -" << endl;
            }
        }
        else
        {
            cout << "Jadwal tidak ditemukan" << endl;
        }
    }
    else
    {
        cout << "Rumah Sakit tidak ditemukan" << endl;
    }
}

void showHospitalList(HospitalList &H)
{
    showHospital(H, false);
}

void showDoctorList(DoctorList &D)
{
    showDoctor(D);
}

void showDoctorFromHospital(HospitalList H)
{
    showDoctorFromHospitals(H);
}

void showHospitalWithDetail(HospitalList &H)
{
    showHospital(H, true);
}
void showHospitalListFromDoctorList(DoctorList D, HospitalList H)
{
    DoctorAdr doctor = first(D);
    while (doctor != NULL)
    {
        hospitalAdr hospital = first(H);
        vector<vector<string>> data;
        while (hospital != NULL)
        {
            ScheduleList S = hospital->schedule;
            ScheduleAdr schedule = first(S);
            while (schedule != NULL)
            {
                if (info(schedule->doctor).id == info(doctor).id)
                {
                    string id_rs = "ID RS : " + info(hospital).id;
                    string rs = "RS : " + info(hospital).name;
                    string alamat = "Alamat : " + info(hospital).hospital_address;
                    data.push_back(vector<string>{id_rs, rs, alamat});
                }
                schedule = next(schedule);
            }
            hospital = next(hospital);
        }
        string title = "#ID " + info(doctor).id + "\n" + info(doctor).name + "\n" + info(doctor).sip_number + "\n" + to_string(info(doctor).age) + "\n" + info(doctor).speciality;
        try
        {
            printTable(3, 20, title, data);
        }
        catch (const exception &e)
        {
            cerr << "error : " << e.what() << endl;
        }
        doctor = next(doctor);
    }
}
void doctorWithDetail(DoctorList D, HospitalList H)
{
    string id;
    cout << "Masukkan ID Dokter : ";
    cin >> id;
    DoctorAdr doctor = findDoctor(D, id);
    if (doctor != NULL)
    {
        hospitalAdr hospital = first(H);
        while (hospital != NULL)
        {
            vector<vector<string>> data;
            ScheduleList schedules = hospital->schedule;
            ScheduleAdr schedule = first(schedules);
            while (schedule != NULL)
            {
                if (info(schedule->doctor).id == info(doctor).id)
                {
                    string id = "ID : " + info(schedule).id;
                    string hari = "Hari : " + info(schedule).day;
                    string mulai = "Mulai Jam : " + info(schedule).start;
                    string akhir = "Berakhir Jam : " + info(schedule).end;
                    string id_rs = "ID RS : " + info(hospital).id;
                    string rs = "RS : " + info(hospital).name;
                    string alamat = "Alamat : " + info(hospital).hospital_address;
                    data.push_back(vector<string>{id, hari, mulai, akhir, id_rs, rs, alamat});
                }
                schedule = next(schedule);
            }
            string title = "#ID " + info(doctor).id + "\n" + info(doctor).name + "\n" + info(doctor).sip_number + "\n" + to_string(info(doctor).age) + "\n" + info(doctor).speciality;
            try
            {
                printTable(7, 20, title, data);
            }
            catch (const exception &e)
            {
                cerr << "error : " << e.what() << endl;
            }
            hospital = next(hospital);
        }
    }
    else
    {
        cout << "Dokter tidak ditemukan" << endl;
    }
}

void countScheduleInHospital(HospitalList &H)
{
    // search rumah sakit
    string id;
    cout << "Masukkan ID Rumah Sakit: ";
    cin >> id;
    hospitalAdr h = findHospital(H, id);

    if (h != NULL)
    {
        int count = countSchedule(schedule(h));
        cout << "Terdapat " << count << " jadwal dalam rumah sakit " << info(h).name << endl;
    }
}

void countScheduleInDoctor(HospitalList &H, DoctorList &D)
{
    string idDoc;
    cout << "Masukkan ID Dokter: ";
    cin >> idDoc;
    DoctorAdr d = findDoctor(D, idDoc);

    if (d != NULL)
    {
        int count = countDoctorInHospital(H, idDoc);
        cout << "Dokter dengan nama " << info(d).name << " mempunyai " << count << " jadwal praktek di berbagai rumah sakit." << endl;
    }
}

void countDoctorWithoutSchedule(HospitalList &H, DoctorList &D)
{
    int total = 0;
    DoctorAdr d = first(D);
    while (d != NULL)
    {
        int count = countDoctorInHospital(H, info(d).id);
        if (count == 0)
        {
            total++;
        }

        d = next(d);
    }

    cout << "Terdapat " << total << " Dokter yang tidak memiliki jadwal praktek" << endl;
}

void editDoctorScheduleInHospital(HospitalList &H, DoctorList &D)
{
    // search rumah sakit
    string id;
    cout << "Masukkan ID Rumah Sakit: ";
    cin >> id;
    hospitalAdr h = findHospital(H, id);

    // search dokter
    DoctorAdr d = NULL;
    if (h != NULL)
    {
        string idDoc;
        cout << "Masukkan ID Dokter: ";
        cin >> idDoc;
        d = findDoctor(D, idDoc);
    }

    // search schedule
    if (d != NULL)
    {
        showSchedule(schedule(h));

        string idS;
        cout << "Masukkan ID Jadwal yang ingin di ganti: ";
        cin >> idS;
        ScheduleAdr s = findSchedule(schedule(h), idS);

        if (s != NULL)
        {
            insertDoctorToSchedule(s, d);
            cout << "Jadwal berhasil diubah" << endl;
        }
    }
}