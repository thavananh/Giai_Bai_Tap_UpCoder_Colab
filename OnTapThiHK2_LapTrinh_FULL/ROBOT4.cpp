#include <iostream>
using namespace std;

class Robot
{
    string name, username;
    int energyLevel, locationX, locationY;

public:
    Robot(string _name, string _username, int _locationX, int _locationY, int _energyLevel = 100)
    {
        name = _name;
        username = _username;
        energyLevel = _energyLevel;
        locationX = _locationX;
        locationY = _locationY;
    }

    Robot(string _name, string _username, int _energyLevel = 100)
    {
        name = _name;
        username = _username;
        energyLevel = _energyLevel;
        locationX = 0;
        locationY = 0;
    }

    Robot(int _energyLevel = 100)
    {
        name = "Robot";
        username = "NoName";
        energyLevel = _energyLevel;
        locationX = 0;
        locationY = 0;
    }

    Robot(const Robot &rb)
    {
        name = rb.name;
        username = rb.username;
        energyLevel = rb.energyLevel;
        locationX = rb.locationX;
        locationY = rb.locationY;
    }

    virtual ~Robot() {}

    int getLocationX()
    {
        return locationX;
    }

    int getLocationY()
    {
        return locationY;
    }

    int getEnergyLevel()
    {
        return energyLevel;
    }

    void setEnergyLevel(int _energyLevel)
    {
        energyLevel = _energyLevel;
    }

    void setLocationX(int _locationX)
    {
        locationX = _locationX;
    }

    void setLocationY(int _locationY)
    {
        locationY = _locationY;
    }

    void setAll(int _locationX, int _locationY)
    {
        locationX = _locationX;
        locationY = _locationY;
    }

    void Charge()
    {
        energyLevel += 10;
    }

    virtual bool Move(int direction) = 0;

    void Display()
    {
        cout << "{" << this->name << "}" << ":" << "{" << this->username << "}" << '\n';
        cout << "(" << this->locationX << "," << this->locationY << ")" << '\n';
        cout << this->energyLevel;
    }
};

class RobotThuong : public Robot
{
public:
    RobotThuong(string _name, string _username, int _locationX, int _locationY, int _energyLevel = 100) : Robot(_name, _username, _locationX, _locationY, _energyLevel)
    {
    }

    RobotThuong(string _name, string _username, int _energyLevel = 100) : Robot(_name, _username, _energyLevel)
    {
    }

    RobotThuong(int _energyLevel = 100) : Robot(_energyLevel)
    {
    }

    RobotThuong(const Robot &rb) : Robot(rb)
    {
    }

    ~RobotThuong() {}

    bool Move(int direction)
    {
        if (getEnergyLevel() <= 0)
        {
            return false;
        }
        else if (direction != 0 && direction != 1 && direction != 2 && direction != 3)
        {
            return false;
        }

        if (direction == 0)
        {
            int k = getLocationX();
            setLocationX(k - 1);
            int nangLuong = getEnergyLevel();
            setEnergyLevel(nangLuong - 5);
            return true;
        }
        else if (direction == 1)
        {
            int k = getLocationX();
            setLocationX(k + 1);
            int nangLuong = getEnergyLevel();
            setEnergyLevel(nangLuong - 5);
        }
        else if (direction == 2)
        {
            int k = getLocationY();
            setLocationY(k + 1);
            int nangLuong = getEnergyLevel();
            setEnergyLevel(nangLuong - 5);
            return true;
        }
        else if (direction == 3)
        {
            int k = getLocationY();
            setLocationY(k - 1);
            int nangLuong = getEnergyLevel();
            setEnergyLevel(nangLuong - 5);
            return true;
        }

        return false;
    }
};

class AdaptiveRobot : public Robot
{
public:
    AdaptiveRobot(string _name = "AdaptiveRobot", string _username = "NoName", int _locationX = 0, int _locationY = 0, int _energyLevel = 100) : Robot(_name, _username, _locationX, _locationY, _energyLevel)
    {
    }

    AdaptiveRobot(string _name = "AdaptiveRobot", string _username = "NoName", int _energyLevel = 100) : Robot(_name, _username, _energyLevel)
    {
    }

    AdaptiveRobot(int _energyLevel = 100) : Robot(_energyLevel)
    {
    }

    AdaptiveRobot(const Robot &rb) : Robot(rb)
    {
    }

    ~AdaptiveRobot() {}

    bool Move(int direction)
    {
        int x = getEnergyLevel();
        if (x <= 0)
        {
            return false;
        }
        else if (direction != 0 && direction != 1 && direction != 2 && direction != 3)
        {
            return false;
        }

        if (direction == 0)
        {
            int k = getLocationX();
            x = getEnergyLevel();
            if (x > 50)
            {
                setLocationX(k-1);
                setEnergyLevel(x - 12);
            }
            else if (x <= 50)
            {
                if (x <= 20)
                {
                    setLocationX(k-1);
                    setEnergyLevel(x-6);
                }
                else
                {
                    setLocationX(k-1);
                    setEnergyLevel(x-9);
                }
            }
            return true;
        }
        else if (direction == 1)
        {
            int k = getLocationX();
            x = getEnergyLevel();
            if (x > 50)
            {
                setLocationX(k+1);
                setEnergyLevel(x - 12);
            }
            else if (x <= 50)
            {
                if (x <= 20)
                {
                    setLocationX(k+1);
                    setEnergyLevel(x-6);
                }
                else
                {
                    setLocationX(k+1);
                    setEnergyLevel(x-9);
                }
            }
            return true;
        }
        else if (direction == 2)
        {
            int k = getLocationY();
            x = getEnergyLevel();
            if (x > 50)
            {
                setLocationY(k+1);
                setEnergyLevel(x - 12);
            }
            else if (x <= 50)
            {
                if (x <= 20)
                {
                    setLocationY(k+1);
                    setEnergyLevel(x-6);
                }
                else
                {
                    setLocationY(k+1);
                    setEnergyLevel(x-9);
                }
            }
            return true;
        }
        else if (direction == 3)
        {
            int k = getLocationY();
            x = getEnergyLevel();
            if (x > 50)
            {
                setLocationY(k-1);
                setEnergyLevel(x - 12);
            }
            else if (x <= 50)
            {
                if (x <= 20)
                {
                    setLocationY(k-1);
                    setEnergyLevel(x-6);
                }
                else
                {
                    setLocationY(k-1);
                    setEnergyLevel(x-9);
                }
            }
            return true;
        }
        return false;
    }
};

int main()
{
    Robot *p[1000];
    int n;
    cin >> n;
    cin.ignore();
    for (size_t i = 0; i < n; i++)
    {
        string name, username;
        int nangluong, hoanhdoX, tungdoY;
        getline(cin, name);
        if (name[0] == 'A')
        {
            getline(cin, username);
            cin >> nangluong >>hoanhdoX >> tungdoY;
            cin.ignore();
            AdaptiveRobot arb(name, username, hoanhdoX, tungdoY, nangluong);
            int k;
            while (cin >> k)
            {
                if (k == -1)
                {
                    break;
                }
                else if (k == 4)
                {
                    arb.Charge();
                }
                else
                {
                    arb.Move(k);
                }
            }
            cin.ignore();
            p[i] = &arb;
            p[i]->Display(); cout << '\n';
        }
        else
        {
            getline(cin, username);
            cin >> nangluong >>hoanhdoX >> tungdoY;
            cin.ignore();
            RobotThuong rbt(name, username, hoanhdoX, tungdoY, nangluong);
            int k;
            while (cin >> k)
            {
                if (k == -1)
                {
                    break;
                }
                else if (k == 4)
                {
                    rbt.Charge();
                }
                else
                {
                    rbt.Move(k);
                }
            }
            cin.ignore();
            p[i] = &rbt;
            p[i]->Display(); cout << '\n';
        }
    }
}