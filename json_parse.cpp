//
// Created by mazastya on 4/21/23.
//
#define CURL_STATICLIB
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

using json = nlohmann::json;

[[maybe_unused]] json json_parse(std::string name_city) {
    CURL *curl;
    CURLcode res;

    std::string print_;

//    std::string name_city;
//    name_city = "Moscow";

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

        std::cout << ninja_api << std::endl;
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
              "&daily=weathercode,temperature_2m_max,temperature_2m_min,windspeed_10m_max,winddirection_10m_dominant"
              "&current_weather=true&forecast_days=" + amount_days + "&timezone=Europe%2FLondon";
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

    json weather = json::parse(weather_api);
//    std::cout << weather << '\n';

    json current_weather = json(weather["daily"]);
    json temperature_2m_max = current_weather["temperature_2m_max"];
    json temperature_2m_min = current_weather["temperature_2m_min"];
    json time = current_weather["time"];
    json weathercode = current_weather["weathercode"];
    json windspeed_10m_max = current_weather["windspeed_10m_max"];

//    std::cout << time;

}
