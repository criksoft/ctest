long write(int, void *, unsigned long);

void itoa(int value, char *str)
{
    char *p;
    char *start;
    char *end;
    char tmp; 
    int n;
    p = str;
    n = value;
check_negative:
    if (n >= 0)
        goto make_negative;
    *p = '-';
    p = p + 1;
make_negative:
    if (n <= 0)
        goto convert_start;
    n = -n;
convert_start:
    start = p;
convert_loop:
    *p = '0' - (n % 10);
    p = p + 1;
    n = n / 10;
    if (n < 0)
        goto convert_loop;
    *p = '\0';
    end = p - 1;
reverse_check:
    if (start >= end)
        goto done;
    tmp = *start;
    *start = *end;
    *end = tmp;
    start = start + 1;
    end = end - 1;
    goto reverse_check;
done:
    return;
}

int main(void)
{
    int i;
    int j;
    int num;
    char buff[20];
    int len;
    i = 0;
    j = 0;
    num = 2;
    len = 0;
zero_the_buff:
    if (j >= 20)
        goto print_the_nums;
    buff[j] = 0;
    j = j + 1;
    goto zero_the_buff;
print_the_nums:
    if (i >= 5)
        goto end;
    itoa(num, buff);
    len = 0;
calc_length:
    if (buff[len] == '\0')
        goto add_new_line;
    len = len + 1;
    goto calc_length;
add_new_line:
    buff[len] = '\n';
    len = len + 1;
write_num:
    write(1, buff, len);
    num = num * num;
    i = i + 1;
    j = 0;
    goto zero_the_buff;
end:
    return 0;
}
