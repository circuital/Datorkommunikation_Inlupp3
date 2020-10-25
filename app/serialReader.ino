void initSerial()
{
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    Serial.println("Serial successfully inited.");
}

bool readFromSerial(char * prompt, char * buf, int maxLen, int timeout)
{
    int timer = 0, delayTime = 1000;
    String input = "";
    if(maxLen <= 0)
    {
        return false;
    }

    Serial.println(prompt);
    while(1)
    {
        input = Serial.readString();
        int len = input.length();
        if(len > maxLen)
        {
            Serial.printf("Your input should less than %d character(s), now you input %d characters.\r\n", maxLen, len);
        }
        else if (len > 0)
        {
            sprintf(buf, "%s", input.c_str());
            return true;
        }

        timer += delayTime;
        if(timeout > 0 && timer >= timeout)
        {
            Serial.println("You input nothing, skip...");
            return false;
        }
        delay(delayTime);
    }
}
