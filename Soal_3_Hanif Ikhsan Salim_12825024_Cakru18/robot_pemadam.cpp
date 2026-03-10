// File: robot_pemadam.cpp
#include <iostream>
#include <string>

class RobotPemadam {
private:
    int jarak;          
    std::string status; 

public:
    RobotPemadam() : jarak(0), status("Standby") {}

    void inputSensor(int nilai) {
        jarak = nilai;
    }

    void prosesLogika() {
        if (jarak > 20) {
            status = "Maju Mencari Api";
        } else if (jarak <= 20 && jarak > 5) {
            status = "UDAH DEKET NIH BRAY";
        } else { 
            status = "Posisi Tepat! gas semprot kali ya!";
        }
    }

    void cetakStatus() const {
        std::cout << "[Sensor: " << jarak << " cm] -> Action: [" << status << "]\n";
    }
};

int main() {
    RobotPemadam robot;
    int input;

    std::cout << "Program simulasi Robot Pemadam (masukkan 67 untuk keluar)\n";

    while (true) {
        std::cout << "Masukkan jarak sensor (cm): ";
        if (!(std::cin >> input)) {
            std::cerr << "Input tidak valid. Program dihentikan.\n";
            break;
        }

        if (input == 67) {
            std::cout << "Perintah keluar diterima. Program berhenti.\n";
            break;
        }

        robot.inputSensor(input);
        robot.prosesLogika();
        robot.cetakStatus();
    }

    return 0;
}