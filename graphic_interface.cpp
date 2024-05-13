//
// Created by mazastya on 4/8/23.
//

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
//#include <ftxui/dom/elements.hpp>
//#include <ftxui/screen/screen.hpp>


using json = nlohmann::json;
void print(json time, json weathercode, json temperature_min, json temperature_max,
           json sunrise, json sunset, json windspeed) {
//    std::string name_city;
//    name_city = "St Peteburg";
//    std::string name_country;
//    name_country = "Russia";
//    std::cout << "\nWeather report: " << name_city << ", " << name_country << '\n';

    std::string sun_;
    std::string sun;
    std::string cloud;
    std::string cloud_with_rain;
    std::string cloud_with_snow;
    std::string cloud_with_snow_rain;
    std::string fog;


    std::cout << sun;

    sun_ = "___________________________________ \n"
           "|      \\   /     " + to_string(time) + "     | \n"
           "|       .-.       " + to_string(windspeed) + "              | \n"
           "|    ― (   ) ―    " + to_string(temperature_min) + "-" + to_string(temperature_max) + "       | \n"
           "|       `-’       " + to_string(windspeed) + "              | \n"
           "|      /   \\     " + "                 | \n"
           "|_________________________________| \n";



    sun =  "                 \n"
           "      \\   /      " + to_string(time).substr(1, to_string(time).size() - 2) + "\n"
           "       .-.       " + to_string(sunrise).substr(12, to_string(sunrise).size() - 2) +
                                " - " + to_string(sunset).substr(12, to_string(sunset).size() - 2) + "\n"
           "    ― (   ) ―    " + to_string(temperature_min) + "°C" + " - " + to_string(temperature_max) + "°C" + "\n"
           "       `-’       " + to_string(windspeed) +  " km/h " + "\n"
           "      /   \\     " + "\n"
           "                 " + "\n";                                                                                                                                                                                      "|_________________________________| \n";


    cloud = "                \n"
            "                " + to_string(time).substr(1, to_string(time).size() - 2) + "\n"
            "      .--.      " + to_string(sunrise).substr(12, to_string(sunrise).size() - 2) +
                          " - " + to_string(sunset).substr(12, to_string(sunset).size() - 2) + "\n"
            "   .-(    ).    " + to_string(temperature_min) + "°C" + " - " + to_string(temperature_max) + "°C" + "\n"
            "   (___.__)__)  " + to_string(windspeed) +  " km/h " + "\n"
            "                " + " \n"
            "                " + " \n";


    cloud_with_rain = "                \n"
                      "                " + to_string(time).substr(1, to_string(time).size() - 2) + "\n"
                      "      .--.      " + to_string(sunrise).substr(12, to_string(sunrise).size() - 2) +
                                        " - " + to_string(sunset).substr(12, to_string(sunset).size() - 2) + "\n"
                      "   .-(    ).    " + to_string(temperature_min) + "°C" + " - " + to_string(temperature_max) + "°C" + "\n"
                      "   (___.__)__)  " + to_string(windspeed) +  " km/h " + "\n"
                      "   , , , , , ,  " + "\n"
                      "                " + "\n";


    cloud_with_snow = "                \n"
                      "                " + to_string(time).substr(1, to_string(time).size() - 2) + "\n"
                      "      .--.      " + to_string(sunrise).substr(12, to_string(sunrise).size() - 2) +
                                        " - " + to_string(sunset).substr(12, to_string(sunset).size() - 2) + "\n"
                      "   .-(    ).    " + to_string(temperature_min) + "°C" + " - " + to_string(temperature_max) + "°C" + "\n"
                      "   (___.__)__)  " + to_string(windspeed) +  " km/h " + "\n"
                      "   * * * * * *  " + "\n"
                      "                " + "\n";

    cloud_with_snow_rain = "                \n"
                           "                " + to_string(time).substr(1, to_string(time).size() - 2) + "\n"
                           "      .--.      " + to_string(sunrise).substr(12, to_string(sunrise).size() - 2) +
                                                " - " + to_string(sunset).substr(12, to_string(sunset).size() - 2) + "\n"
                           "   .-(    ).    " + to_string(temperature_min) + "°C" + " - " + to_string(temperature_max) + "°C" + "\n"
                           "   (___.__)__)  " + to_string(windspeed) +  " km/h " + "\n"
                           "   , * , * , *  " + "\n"
                           "   * , * , * ,  " + "\n"
                           "                " + "\n";

    fog  = "                \n"
           "                " + to_string(time).substr(1, to_string(time).size() - 2) + "\n"
           "   _  -   _     " + to_string(sunrise).substr(12, to_string(sunrise).size() - 2) +
                            " - " + to_string(sunset).substr(12, to_string(sunset).size() - 2)+ "\n"
           "     _  -   _   " + to_string(temperature_min) + "°C" + " - " + to_string(temperature_max) + "°C" + "\n"
           "  _ _  -   _    " + to_string(windspeed) +  " km/h " + "\n"
           "   _  -  -  _   " + "\n"
           "                " + "\n";



    if (weathercode == 1 or weathercode == 2 or weathercode == 3) {
        std::cout << cloud;
    } else if (weathercode == 45 or weathercode == 48) {
        std::cout << fog;
    } else if (weathercode == 63 or weathercode == 61 or weathercode == 65) {
        std::cout << cloud_with_rain;
    } else if (weathercode == 51 or weathercode == 53 or weathercode == 55) {
        std::cout << fog;
    } else if (weathercode == 56 or weathercode == 57) {
        std::cout << fog;
    } else if (weathercode == 66 or weathercode == 67) {
        std::cout << cloud_with_rain;
    } else if (weathercode == 71 or weathercode == 73 or weathercode == 75 or weathercode == 77) {
        std::cout << cloud_with_snow;
    } else if (weathercode == 81 or weathercode == 82 or weathercode == 80) {
        std::cout << cloud_with_snow_rain;
    } else if (weathercode == 85 or weathercode == 86) {
        std::cout << cloud_with_snow;
    } else if (weathercode == 81 or weathercode == 82 or weathercode == 80) {
        std::cout << cloud_with_snow_rain;
    } else {
        std::cout << sun;
    }








}
