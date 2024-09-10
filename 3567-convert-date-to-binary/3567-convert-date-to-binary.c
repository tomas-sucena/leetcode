char *toBinary(char *date, unsigned short number) {
    unsigned short mask = 0x1000;

    // ignore leading zeros
    for (; (number & mask) == 0; mask >>= 1);

    // write each bit
    for (; mask; mask >>= 1) {
        // NOTE: The double negation simply converts a number to a boolean.
        *date++ = !!(number & mask) + '0';
    }
    
    return date;
}

char* convertDateToBinary(char* date) {
    // get the year, month and day represented in the date
    unsigned short year, month, day;
    sscanf(date, "%hu-%hu-%hu", &year, &month, &day);

    // convert them to binary
    date = malloc(30 * sizeof(char));

    char *temp = toBinary(date, year);
    *temp++ = '-';
    temp = toBinary(temp, month);
    *temp++ = '-';
    temp = toBinary(temp, day);
    *temp = '\0';

    return date;
}