#include <iostream>
#include <iomanip>
using namespace std;

double get_seconds(string time) {
    size_t firstColonPos = time.find(':');
    size_t secondColonPos = time.find(':', firstColonPos + 1);

    int hours = 0, minutes = 0;
    double seconds = 0;

    if (secondColonPos != string::npos) {
        // Convert the part before the colon to an integer
        hours = stoi(time.substr(0, firstColonPos));

        // Convert the part before the colon to an integer
        minutes = stoi(time.substr(firstColonPos + 1, secondColonPos - firstColonPos - 1));

        // Convert the part after the colon to an integer
        seconds = stoi(time.substr(secondColonPos + 1));

        return (((hours * 60) + minutes) * 60) + seconds;
    } else if (firstColonPos != string::npos){
        // Convert the part before the colon to an integer
        minutes = stoi(time.substr(0, firstColonPos));

        // Convert the part after the colon to an integer
        seconds = stoi(time.substr(firstColonPos + 1));

        return minutes * 60 + seconds;
    } else {
        return stod(time);
}

}


string mile_split(double time, double laps) {
    double secs = (time / laps) * 4;
    int mins = 0;

    do {
        mins += 1;
        secs -= 60;
    } while (secs >= 60);

    if (mins > 0) {
        if (secs < 10) {
            return to_string(mins) + ":0" + to_string(secs);
        } else {
            return to_string(mins) + ":" + to_string(secs);
        }
    } else {
        return to_string(secs);
    }
}

string lap_split(double time, double laps) {
    double secs = time / laps;
    int mins = 0;

    if (secs > 100) {
        do {
            mins += 1;
            secs -= 60;
        } while (secs >= 60);

        if (secs < 10) {
            return to_string(mins) + ":0" + to_string(secs);
        } else {
            return to_string(mins) + ":" + to_string(secs);
        }
    } else {
        return to_string(secs);
    }
}

int main() {

    string time;
    double distance;
    char choice;


    do {
        // Prompt the user for the time and distance
        cout << "Race Distance (meters): ";
        cin >> distance;

        cout << "\nTime: ";
        cin >> time;
        double seconds = get_seconds(time);

        // Check for division by zero
        if (seconds <= 0 || distance <= 0) {
            cout << "\n\nError: Time or distance is invalid." << endl;
        } else {
            // Perform the splits
            double laps = distance / 400;
            string mile_time = mile_split(seconds, laps);
            string lap_time = lap_split(seconds, laps);

            cout << "\n\n\nAverage Mile Time -> " << fixed << setprecision(2) << mile_time.erase(mile_time.length() - 4) << endl;
            cout << "\nAverage 400m Time -> " << fixed << setprecision(2) << lap_time.erase(lap_time.length() - 4) << endl;
        }

        // Ask the user if they want to perform another operation
        cout << "\n\n\n\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;

        cout << "\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";

    } while (choice == 'y' || choice == 'Y');

    cout << "\n\n\n\n\n\n\n\n\n";

    return 0;
}
