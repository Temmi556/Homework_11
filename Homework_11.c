#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");  // устанавливаем локаль системы
    
    wint_t c;
    int letters = 0;
    int words = 0;
    int in_word = 0;

    wprintf(L"Введите строку:\n");

    while ((c = getwchar()) != L'\n') {
        if (c != L' ' && c != L'\t') {
            letters++;
            if (!in_word) {
                words++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }

    if (words > 0)
        wprintf(L"Средняя длина слова = %.2f\n", (float)letters / words);
    else
        wprintf(L"Слова отсутствуют\n");

    return 0;
}