static char result[9]; // "HH:MM:SS" + null terminator
int hour;
char period[3];

// Extract hour and AM/PM
sscanf(s, "%2d:%*2d:%*2d%2s", &hour, period);

// Convert AM/PM to uppercase just in case
period[0] = toupper(period[0]);
period[1] = toupper(period[1]);

// Apply conversion rules
if (strcmp(period, "AM") == 0)
{
    if (hour == 12)
        hour = 0; // Midnight case
}
else
{ // PM case
    if (hour != 12)
        hour += 12;
}

// Format into result without AM/PM
sprintf(result, "%02d:%c%c:%c%c", hour, s[3], s[4], s[6], s[7]);

return result;