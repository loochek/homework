// свой strcmp для соответствия ТЗ
// Следите за тем, чтобы был windows-1251, на двухбайтной кодировке не работает
// если rev = 1, то компаратор идет в обратную сторону, принимая указатели на последние символы строк
// (однако перед первым символом должен быть нуль-терминатор)
int custom_strcmp(const char *a, const char *b, int rev);