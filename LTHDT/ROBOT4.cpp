#include <bits/stdc++.h>

using namespace std;

class Robot{
    protected:
        string name;
        string username;
        int EnergyLevel;
        int LocationX;
        int LocationY;
    public:
        Robot(string _name, string _username, int x, int y){
            name = _name;
            username = _username;
            LocationX = x;
            LocationY = y;
        }
        
        Robot(string _name, string _username){
            name = _name;
            username = _username;
        }
        
        Robot(){
            name = "";
            username = "";
            LocationX = 0;
            LocationY = 0;
            EnergyLevel = 100;
        }
        
        Robot(const Robot &rb){
            name = rb.name;
            username = rb.username;
            LocationX = rb.LocationX;
            LocationY = rb.LocationY;
            EnergyLevel = rb.EnergyLevel;
        }
        
        void Charge(){
            EnergyLevel += 10;
        }
        
        bool Move(int direction){
            if(EnergyLevel==0) return false;
            if(direction < 0 || direction > 3) return false;
            if(direction==0)      LocationX--;
            else if(direction==1) LocationX++;
            else if(direction==2) LocationY++;
            else if(direction==3) LocationY--;
            EnergyLevel-=5;
            return true;
        }
        
        //{ABC}:{Nguyễn Văn A}
        
        void Display(){
            cout << "{" << name << "}:{" << username << "}\n";
        }
        
        friend istream &operator >> (istream &input, Robot &rb){
            input >> rb.EnergyLevel >> rb.LocationX >> rb.LocationY;
            return input;
        }
        
        friend ostream &operator << (ostream &output, Robot rb){
            rb.Display();
            output << "(" << rb.LocationX << "," << rb.LocationY << ")\n";
            output << rb.EnergyLevel << endl;
            return output;
        }
};

class AdaptiveRobot : public Robot{
    int buocdi;
    public:
        AdaptiveRobot(string _name, string _username, int x, int y) : Robot(_name, _username, x, y) {};
        AdaptiveRobot(string _name, string _username) : Robot(_name, _username) {};
        AdaptiveRobot() : Robot() {buocdi = 0;};
        AdaptiveRobot(const AdaptiveRobot &rb) : Robot(rb) {};

        bool Move(int direction){
            if(EnergyLevel==0) return false;
            if(direction < 0 || direction > 3) return false;
            
            
            buocdi++;
            
            if(direction==0)      LocationX--;
            else if(direction==1) LocationX++;
            else if(direction==2) LocationY++;
            else if(direction==3) LocationY--;
            
            if(EnergyLevel > 50){
                if(buocdi==3){
                    EnergyLevel -= 12;
                    buocdi = 0;   
                }
            }
            else if(EnergyLevel > 20){
                if(buocdi==2){
                    EnergyLevel -= 9;
                    buocdi = 0;   
                }
            }
            else if(buocdi==1){
                EnergyLevel -= 6;
                buocdi = 0;
            }
            return true;
        }
        
        
        friend istream &operator >> (istream &input, AdaptiveRobot &rb){
            input >> rb.EnergyLevel >> rb.LocationX >> rb.LocationY;
            return input;
        }
        
        
        friend ostream &operator << (ostream &output, AdaptiveRobot rb){
            rb.Display();
            output << "(" << rb.LocationX << "," << rb.LocationY << ")\n";
            output << rb.EnergyLevel << endl;
            return output;
        }
};

int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin.ignore();
        string name, username;
        getline(cin, name);
        getline(cin, username);
        if(name[0]=='A'){
            AdaptiveRobot robot(name, username);
            cin >> robot;
            int direction;
            while(cin >> direction){
                if(direction >= 0 && direction <= 3) robot.Move(direction);
                else if(direction==4) robot.Charge();
                else if(direction==-1) break;
            }
            cout << robot;
        }
        else{
            Robot robot(name, username);
            cin >> robot;
            int direction;
            while(cin >> direction){
                if(direction >= 0 && direction <= 3) robot.Move(direction);
                else if(direction==4) robot.Charge();
                else if(direction==-1) break;
            }
            cout << robot;
        }
    }
}