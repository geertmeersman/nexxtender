#ifndef NEXXTENDER_UTILS_H
#define NEXXTENDER_UTILS_H

uint32_t getInt(String x, int i) {
    return (uint32_t(x[i+3]) << 24) | (uint32_t(x[i+2]) << 16) | (uint32_t(x[i+1]) << 8) | uint32_t(x[i]);
}

int16_t getByte(String x, int i) {
    return x[i] & 0xFF;
}

int16_t getShort(String x, int i) {
    return (int16_t(x[i+1]) << 8) | int16_t(x[i]);
}

String getTimeString(int minutes) {
    char time_string[20];
    minutes += 60; // add 1 hour due to timezone
    int hours = minutes / 60;
    int remaining_minutes = minutes % 60;
    sprintf(time_string, "%dh%02d", hours, remaining_minutes);
    return time_string;
}

void logd_x(const char* device_name, String x) {
    auto hex_data = format_hex_pretty((uint8_t *) x.c_str(), x.size());
    ESP_LOGD(device_name, "%s", hex_data.c_str());
}

void logd_s(const char* device_name, String x) {
    ESP_LOGD(device_name, "%s", x.c_str());
}

#endif
