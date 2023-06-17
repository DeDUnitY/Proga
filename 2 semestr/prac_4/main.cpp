#include <iostream>
#include <string>
#include <fstream>

class Appliance
{
private:
    std::string i_name;
public:
    explicit Appliance(std::string& name) : i_name(name) {}

    void Poll()
    {
        std::cout << i_name << std::endl;
    }
};

class Electric_energy_meters : public Appliance
{
public:
    explicit Electric_energy_meters(std::string& name) : Appliance(name) {}
};

class Input_descrete_signal : public Appliance
{
public:
    explicit Input_descrete_signal(std::string& name) : Appliance(name) {}
};

class Heating_control : public Appliance
{
public:
    explicit Heating_control(std::string& name) : Appliance(name) {}
};

std::string electricity_meter[] = { "Mercury 230", "Neva MT314", "Energomera CE308" };

std::string input_descrete_signal[] = { "Reallab NL-16HV", "Priboreltctro PRE - 16", "Energoservis EHMB-1-24" };

std::string heating_control[] = { "Ouman S203", "Oven TPM232" };

struct configuration
{
    Electric_energy_meters* meter = nullptr;
    Input_descrete_signal* device = nullptr;
    Heating_control* heat = nullptr;
};

int main()
{
    configuration config;
    std::ifstream file("../appliance.txt");
    std::string tmp;
    while (getline(file, tmp))
    {
        int n = sizeof(electricity_meter) / sizeof(std::string);
        for (int i = 0; i < n; ++i)
        {
            if (electricity_meter[i] == tmp)
            {
                config.meter = new Electric_energy_meters(tmp);
                break;
            }
        }

        n = sizeof(input_descrete_signal) / sizeof(std::string);
        for (int i = 0; i < n; ++i)
        {
            if (input_descrete_signal[i] == tmp)
            {
                config.device = new Input_descrete_signal(tmp);
                break;
            }
        }

        n = sizeof(heating_control) / sizeof(std::string);
        for (int i = 0; i < n; ++i)
        {
            if (heating_control[i] == tmp)
            {
                config.heat = new Heating_control(tmp);
                break;
            }
        }
    }
    config.device->Poll();
    config.heat->Poll();
    config.meter->Poll();
}
