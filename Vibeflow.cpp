// ---------------IMPORTS------------------------- //
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <thread>
#include <chrono>
#include <fstream>
#include <regex>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <curl/curl.h> // For HTTP requests

using namespace std;
namespace fs = std::filesystem;

// ---------------FUNCTIONS------------------------- //
char get_input() {
    char pressed = '\0';
    while (true) {
        if (_kbhit()) {
            pressed = _getch();
            if (pressed >= '1' && pressed <= '5') {
                return pressed;
            } else if (pressed == '\r') {
                continue;
            }
        }
    }
}

std::string sanitize_filename(const std::string& filename) {
    return std::regex_replace(filename, std::regex(R"([\\/*?:"<>|])"), "");
}

char get_only_1_letter_input() {
    char pressed = '\0';
    while (true) {
        if (_kbhit()) {
            pressed = _getch();
            if (pressed == 's') {
                return pressed;
            } else if (pressed == '\r') {
                continue;
            }
        }
    }
}

std::string load_api_key(const std::string& config_file) {
    std::ifstream file(config_file);
    if (!file) {
        cout << "Error: Configuration file '" << config_file << "' not found." << endl;
        return "";
    }

    std::string api_key;
    file >> api_key;
    return api_key;
}

int get_audio_length(const std::string& file_path) {
    // Placeholder function to return audio length
    // Implement audio file parsing logic based on file extension (e.g. .mp3, .wav)
    return 0; // Return actual audio length here
}

std::string select_file() {
    // Function to select file using a OpenFileDialog equivalent, not directly possible in C++
    std::cout << "Function select_file() not implemented. Returning empty." << std::endl;
    return "";
}

void play_music(const std::string& file_path) {
    // Placeholder for playing music
    // This would normally require a library for audio playback
    cout << "Playing: " << file_path << endl;
}

void show_status(const std::string& file_path) {
    int length = get_audio_length(file_path);
    // Placeholder for getting the current position, assuming a function/music library is available
    int current_pos = 0;

    cout << "Music path: " << file_path << endl;
    cout << "Length: " << length << " sec" << endl;
    cout << "Played: " << current_pos << " sec" << endl;
    cout << "Not played: " << (length - current_pos) << " sec" << endl;
    if (current_pos == length) {
        cout << "Music has ended" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // Call main_menu() here
    }
}

void main_menu(); // Forward declaration

// ---------------FUNCTIONS-ends------------------------- //

//----------------Modes------------------------- //
void choosen_music() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("cls");
    std::string file_path = "";
    cout << "S. Choose music to play:" << endl;
    if (get_only_1_letter_input() == 's') {
        file_path = select_file();
        if (!file_path.empty()) {
            cout << "Playing started " << file_path << "." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            play_music(file_path);

            while (true) {
                show_status(file_path);
                std::this_thread::sleep_for(std::chrono::seconds(1));
                system("cls");
            }
        }
    }
}

// Implement other modes like guide_mode(), download_with_youtube(), vibeflow_folder(), etc.

// Main menu implementation
void main_menu() {
    system("cls");
    string Vibeflow = "✮⋆˙VibeFlow✮⋆˙";
    cout << "Welcome to " << Vibeflow << " - A tiny music player" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "1. Play Choosen Music" << endl;
    cout << "2. Open Vibeflow music folder" << endl;
    cout << "3. Download Music from Vibeflow-site" << endl;
    cout << "4. Exit" << endl;
    cout << "---------------------------------------------" << endl;

    char choice = get_input();
    switch (choice) {
        case '1':
            system("cls");
            cout << "You chose 'Play Choosen Music'" << endl;
            choosen_music();
            break;
        case '2':
            system("cls");
            // Call vibeflow_folder() here
            break;
        case '3':
            system("cls");
            // Call download_with_youtube() here
            break;
        case '4':
            system("cls");
            cout << "You chose 'Exit'" << endl;
            exit(0);
            break;
        default:
            break;
    }
}

// ----------------Main------------------------- //
int main() {
    system("cls");
    string Vibeflow = "✮⋆˙VibeFlow✮⋆˙";
    cout << "Welcome to " << Vibeflow << " - A tiny music player" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    main_menu();
    return 0;
}
//----------------Main-end------------------------- //