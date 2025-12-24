#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_white(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int main(void)
{
    int hour12, hour24, min;
    char c[100];
    printf("Enter a time in 12-hour clock: ");
    scanf("%d:%d %2s", &hour12, &min, c);

    // check validity (DIY)

    // 0, 11 AM =>
    // 12 AM => 0
    // 12 PM => 12
    // PM 1~11 => +12 => 13 ~ 23

    hour24 = hour12 % 12;
    if (strcmp(c, "PM") == 0)
    {
        hour24 = (hour12 % 12) + 12;
    }

    printf("%02d:%02d\n", hour24, min);
}

int main_(int argc, char *argv[])
{
    FILE *fp;
    char c;
    int word_cnt = 0, char_cnt = 0;
    bool white = true;

    fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        while ((c = fgetc(fp)) != EOF)
        {
            // count word if non-white to white.
            if (is_white(c))
            {
                if (!white)
                {
                    word_cnt++;
                    white = true;
                }
            }
            else
            {
                char_cnt++;
                white = false;
            }
        }

        if (!white)
        {
            word_cnt++;
        }
    }
    fclose(fp);
    printf("%d, %d\n", char_cnt, word_cnt);
    return 0;
}