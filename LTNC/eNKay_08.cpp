#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers; // Khai báo một vector để lưu trữ các số nhập vào
    int num;
    while (cin >> num) { // Vòng lặp để nhập các số từ người dùng
        numbers.push_back(num); // Thêm số vào vector numbers
    }
    bool foundNegative = false; // Biến kiểm tra xem có tìm thấy số âm không
    vector<int> negativeNumbers; // Vector lưu trữ các số âm không trùng lặp
    for (int i = 0; i < numbers.size(); i++) { // Duyệt qua các số trong vector numbers
        if (numbers[i] < 0 && find(negativeNumbers.begin(), negativeNumbers.end(), numbers[i]) == negativeNumbers.end()) {
            // Nếu số âm và chưa tồn tại trong negativeNumbers
            negativeNumbers.push_back(numbers[i]); // Thêm số âm vào negativeNumbers
            foundNegative = true; // Đánh dấu đã tìm thấy số âm
        }
    }
    if (foundNegative) { // Nếu tìm thấy số âm
        for (int i = 0; i < negativeNumbers.size(); i++) { // In ra các số âm
            cout << negativeNumbers[i] << " ";
        }
    } else {
        cout << "NOTFOUND"; // Nếu không tìm thấy số âm
    }
    return 0;
}
