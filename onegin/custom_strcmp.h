// свой strcmp для соответствия ТЗ
// Следите за тем, чтобы был windows-1251, на двухбайтной кодировке не работает
// (потратил прилично времени, чтобы это понять)
// unsigned чтоб русские буквы сравнивались корректно
int custom_strcmp(const unsigned char *a, const unsigned char *b);

// перевернутый custom_strcmp
int custom_strcmp_rev(const unsigned char *a, const unsigned char *b);