#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

int main() {
    // Get the current time
    std::time_t currentTime = std::time(nullptr);

    // Convert the current time to a tm structure
    std::tm* localTime = std::localtime(&currentTime);

    // Format the time as a string
    std::stringstream ss;
    ss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    std::string timeString = ss.str();

    // Print the formatted time string
    std::cout << "Formatted time: " << timeString << std::endl;
    system("pause");
    return 0;
}