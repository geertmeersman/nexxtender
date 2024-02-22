uint32_t getInt(String x, int i) {
    return (uint32_t(x[i+3]) << 24) | (uint32_t(x[i+2]) << 16) | (uint32_t(x[i+1]) << 8) | uint32_t(x[i]);
}

int16_t getShort(String x, int i) {
    return (int16_t(x[i+1]) << 8) | int16_t(x[i]);
}