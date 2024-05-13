#define CURL_STATICLIB

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
//#include <fstream>
//#include <iomanip>
//#include <ftxui/dom/elements.hpp>
//#include <ftxui/screen/screen.hpp>

#include "graphic_interface.h"
//#include "json_parse.h"




static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

using json = nlohmann::json;

const int amount_city = 5;
std::string array_name_city[amount_city] = {"Moscow", "Novgorod", "Makhachkala", "Magadan", "California"};
int i = 0;

json get_parse_string(std::string name_city) {
    CURL *curl;
    CURLcode res;

    std::string print_;

    name_city = array_name_city[i];

    std::string URL_city_str;
    URL_city_str = "https://api.api-ninjas.com/v1/city?name=" + name_city + "";
//    std::cout << URL_city_str;

    char *URL_city;
    URL_city = const_cast<char *>(URL_city_str.c_str());
//    std::cout << URL_city;

    std::string ninja_api;

    curl = curl_easy_init();
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "X-Api-Key: p4oUS0X7t965vpD8mVdOwg==zW5okO0gl0HkUdHj");
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL_city);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ninja_api);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

//        std::cout << ninja_api << std::endl;
    }

    json api_parse = json::parse(ninja_api.substr(1, ninja_api.size() - 2));
    json api_latitude = api_parse["latitude"];
    json api_longitude = api_parse["longitude"];
    std::string api_latitude_str = to_string(api_latitude);
    std::string api_longitude_str = to_string(api_longitude);

    std::string amount_days = "14";

    std::string URL_str;
    URL_str = "https://api.open-meteo.com/v1/forecast?latitude="
              "" + api_latitude_str + "&longitude=" + api_longitude_str +
              "&daily=weathercode,temperature_2m_max,temperature_2m_min,windspeed_10m_max,sunrise,sunset,"
              "precipitation_probability_max&forecast_days=" + amount_days + "&timezone=Europe%2FLondon";
//    precipitation_probability_max
//    std::cout << URL_str;

    char *URL;
    URL = const_cast<char *>(URL_str.c_str());

    std::string weather_api;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &weather_api);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

//        std::cout << weather_api << std::endl;
    }
//
//    curl = curl_easy_init();
//    curl_easy_cleanup(curl);

    json weather = json::parse(weather_api);
    curl = curl_easy_init();
    curl_easy_cleanup(curl);
    return weather;
}

//json weather = get_parse_string(array_name_city[i]);

//json get_daily_current_weather() {
//    json weather = get_parse_string(array_name_city[i]);
//    json current_weather = json(weather["daily"]);
//    return current_weather;
//}
//
//json get_weathercode() {
//    json current_weather = get_daily_current_weather();
//    json weathercode = current_weather["weathercode"];
//    return weathercode;
//}
//
//json get_temperature_2m_max() {
//    json current_weather = get_daily_current_weather();
//    json temperature_2m_max = current_weather["temperature_2m_max"];
//    return temperature_2m_max;
//}
//
//json get_temperature_2m_min() {
//    json current_weather = get_daily_current_weather();
//    json temperature_2m_min = current_weather["temperature_2m_min"];
//    return temperature_2m_min;
//}
//
//json get_time() {
//    json current_weather = get_daily_current_weather();
//    json time = current_weather["time"];
//    return time;
//}
//
//json get_windspeed_10m_max() {
//    json current_weather = get_daily_current_weather();
//    json windspeed_10m_max = current_weather["windspeed_10m_max"];
//    return windspeed_10m_max;
//}
//
//json get_sunrise() {
//    json current_weather = get_daily_current_weather();
//    json sunrise = current_weather["sunrise"];
//    return sunrise;
//}
//
//json get_sunset() {
//    json current_weather = get_daily_current_weather();
//    json sunset = current_weather["sunset"];
//    return sunset;
//}
//
//json get_precipitation_probability_max() {  //вероятность осадков
//    json current_weather = get_daily_current_weather();
//    json precipitation_probability_max = current_weather["precipitation_probability_max"];
//    return precipitation_probability_max;
//}


int main() {
    bool flag = true;
    char command;
    int count_window = 0;
    int amount_day = 0;


    while (flag) {
        json weather = get_parse_string(array_name_city[i]);
        json current_weather = json(weather["daily"]);
        json weathercode = current_weather["weathercode"];
        json time = current_weather["time"];
        json temperature_2m_min = current_weather["temperature_2m_min"];
        json temperature_2m_max = current_weather["temperature_2m_max"];
        json windspeed_10m_max = current_weather["windspeed_10m_max"];
        json sunrise = current_weather["sunrise"];
        json sunset = current_weather["sunset"];
        json precipitation_probability_max = current_weather["precipitation_probability_max"];

        std::cin >> command;
        system("clear");
        if (command == 'n') {
            i++;
            if (i >= 4) {
                i = 0;
            }
            json weather = get_parse_string(array_name_city[i]);
            json current_weather = json(weather["daily"]);
            json weathercode = current_weather["weathercode"];
            json time = current_weather["time"];
            json temperature_2m_min = current_weather["temperature_2m_min"];
            json temperature_2m_max = current_weather["temperature_2m_max"];
            json windspeed_10m_max = current_weather["windspeed_10m_max"];
            json sunrise = current_weather["sunrise"];
            json sunset = current_weather["sunset"];
            json precipitation_probability_max = current_weather["precipitation_probability_max"];

            system("clear");

            std::cout << "City:" <<  array_name_city[i] << "\n";
            std::cout << "<-" << array_name_city[i-1] << "|" << array_name_city[i+2] << "->" << "\nz" ;
            for (int amount_enter = 0; amount_enter < count_window; amount_enter++) {
                print(time[amount_enter], weathercode[amount_enter], temperature_2m_min[amount_enter],
                      temperature_2m_max[amount_enter], sunrise[amount_enter],
                      sunset[amount_enter], weathercode[amount_enter]);
            }

        } else if (command == 'p') {
            i--;
            if (i <= 0) {
                i = 0;
            }
            json weather = get_parse_string(array_name_city[i]);
            json current_weather = json(weather["daily"]);
            json weathercode = current_weather["weathercode"];
            json time = current_weather["time"];
            json temperature_2m_min = current_weather["temperature_2m_min"];
            json temperature_2m_max = current_weather["temperature_2m_max"];
            json windspeed_10m_max = current_weather["windspeed_10m_max"];
            json sunrise = current_weather["sunrise"];
            json sunset = current_weather["sunset"];
            json precipitation_probability_max = current_weather["precipitation_probability_max"];

            system("clear");

            std::cout << "City:" <<  array_name_city[i] << "<-" << array_name_city[i+1] << "->" << array_name_city[i+2] ;
            for (int amount_enter = 0; amount_enter < count_window; amount_enter++) {
                print(time[amount_enter], weathercode[amount_enter], temperature_2m_min[amount_enter],
                      temperature_2m_max[amount_enter], sunrise[amount_enter],
                      sunset[amount_enter], windspeed_10m_max[amount_enter]);
            }

        } else if (command == '=' or command == '+') {
            system("clear");
            count_window++;
            if (count_window > 14) {
//                system("clear");
                std::cout << "ERROR! \n"
                             "You can't show the weather for more than 14 days! \n"
                             "The program is terminated(( \n";
                break;
            }
            std::cout << "City:" << array_name_city[i];
            for (int amount_enter = 0; amount_enter < count_window; amount_enter++) {
                print(time[amount_enter], weathercode[amount_enter], temperature_2m_min[amount_enter],
                      temperature_2m_max[amount_enter], sunrise[amount_enter],
                      sunset[amount_enter], weathercode[amount_enter]);
            }
        } else if (command == '-') {
//            system("clear");
            count_window--;
            if (count_window <= 0) {
                count_window = 0;
            }
            std::cout << "City:" << array_name_city[i];
            for (int amount_enter = 0; amount_enter < count_window; amount_enter++) {
                print(time[amount_enter], weathercode[amount_enter], temperature_2m_min[amount_enter],
                      temperature_2m_max[amount_enter], sunrise[amount_enter],
                      sunset[amount_enter], weathercode[amount_enter]);
            }
        } else if (command == '0' or command == 'x') {
            flag = false;
        }
        else{
            std::cout << "ERROR! \n"
                         "I can't recognize this command! \n"
                         "The program is terminated(( \n";
            break;
        }

    }

}


//    bool flag = true;
//    char command;
//    int count_window = 0;
//    system("clear");
//
//    while (flag) {
//        std::cin >> command;
//        if (command == '=') {
//            count_window++;
//            system("clear");
//            if (count_window > 14) {
//                system("clear");
//                std::cout << "ERROR! "
//                             "You can't show the weather for more than 14 days!"
//                             "The program is terminated((";
//                break;
//            }
//            for (int i = 0; i < count_window; i++) {
//                print(get_time()[i], get_windspeed_10m_max()[i], get_temperature_2m_max()[i],
//                      get_time()[i]);
//            }
//        } else if (command == '-') {
//            system("clear");
//            count_window--;
//            if (count_window < 0) {
//                std::cout << "ERROR! "
//                             "It is impossible to show a negative number of days"
//                             "The program is terminated((";
////                command = '0';
//                break;
//            }
////            for (int i = 0; i < count_window; i++) {
////                print(to_string(time[i]), to_string(windspeed_10m_max[i]), to_string(temperature_2m_max[i]),
////                      to_string(time[i]));
////            }
//        }
//
//        else if (command == '0') {
//            flag = false;
//        }
//    }
//
//
//    return 0;
//}
