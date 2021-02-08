#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

string GenerateKey(string str, string keyword);
string CipheredText(string str, string key);
string DecryptedText(string &str,string key);

int main ()
{
    setlocale(LC_ALL,"");
    string str; // переменная для ввода текста
    string keyword; // переменная для ввода ключа
    string answer;  // переменная для выбора способа работы с методом Гронсфельда
    printf("Введите способ работы с методом Гронсфельда: файл(file) или клавиатура(kv):\n");
    cin >> answer;
    
    if (answer == "kv")
    {
        cout << "Введите текст: " << str;
        cin >> str;
        cout << "Введите числовой ключ: " << keyword;
        cin >> keyword;
        
        // цикл на наличие ключа шифрования
        while(keyword.empty())
        {
            cout << "Не введен ключ,введите для шифрования: ";
            cin >> keyword;
            cout << "\nВведите ключ: " << keyword << endl << endl;
        }
        // Проверка длины ключа
        if(keyword.size() > str.size())
        {
            cout << "Длина ключа не может быть больше длины текста.\n";
            return 0;
        }
        // проверка на корректные символы в тексте
        for(int i = 0; i < str.size(); i++)
        {
            if(!isalpha(str[i]))
            {
                cout << "Некорректный ввод текста!Пожалуйста проверьте не содержит ли он кириллицу.\n";
                return 0;
            }
        }
        // проверка на корректные символы в пароле
        for(int i = 0; i < keyword.size(); i++)
        {
            if(!isdigit(keyword[i]))
            {
                cout << "Некорректный ввод пароля!.Пожалуйса проверьте не содержит ли он спецсимволы или латинские буквы.\n";
                return 0;
            }
        }
        // перевод текста из нижнего в верхний регистр
        for(int i = 0; i < str.size(); i++)
        {
            if(islower(str[i]))
                str[i] = toupper(str[i]);
        }
        
        string key = GenerateKey(str, keyword); //реализация метода создания ключа шифрования
        string cipherStr = CipheredText(str, key); // реализация метода Шифрования
        string decrypted = DecryptedText(cipherStr,key); // реализация метода Дешифрования
        
        cout << "Реализация шифрования методом \"GRONSFELD\": " << cipherStr << endl;
        cout << "Расшифрованный текст ,зашифрованный методом \"GRONSFELD\": " << decrypted << endl;
        
    }
    else if (answer == "file")
    {
        ifstream file("/Users/vyacheslav/Desktop/GRONSFELD/coding/GRONSFELDU.txt");
        string str; // переменная для ввода текста
        string keyword; // переменная для ввода ключа
        getline(file,str); // считывание первой строки в файле
        getline(file,keyword); // считывание второй строки в файле
        
        // цикл на наличие ключа шифрования
        while(keyword.empty())
        {
            cout << "Не введен ключ,введите для шифрования";
            cin >> keyword;
            cout << "\nВведите ключ: " << keyword << endl << endl;
        }
        
        // проверка длины ключа
        if(keyword.size() > str.size())
        {
            cout << "Длина ключа не может быть больше длины текста.\n";
            return 0;
        }
        // проверка на корректные символы в тексте
        for(int i = 0; i < str.size(); i++)
        {
            if(!isalpha(str[i]))
            {
                cout << "Некорректный ввод текста!Пожалуйста проверьте не содержит ли он кириллицу.\n";
                return 0;
            }
        }
             // проверка на корректные символы в пароле
        for(int i = 0; i < keyword.size(); i++)
        {
            if(!isdigit(keyword[i]))
            {
                cout << "Некорректный ввод пароля!.Пожалуйса проверьте не содержит ли он спецсимволы или латинские буквы.\n";
                return 0;
            }
        }
        string key = GenerateKey(str, keyword); //реализация метода создания ключа шифрования
        string cipherStr = CipheredText(str, key); // реализация метода Шиврования
        string decrypted = DecryptedText(cipherStr,key); // реализация метода Дешифрования
        
        cout << "Реализация шифрования методом \"GRONSFELD\": " << cipherStr << endl;
        cout << "Расшифрованный текст, зашифрованный методом \"GRONSFELD\": " << decrypted << endl;
    }
    else
    {
        printf("Не выбран способ работы с методом Гронсфельда:\n");
    }
    
    
}

// реализация метода по созданию ключа Шифрования
string GenerateKey(string str, string keyword)
{
    int sizeOfText = str.size();
    string key = "\0";
    
    if(str.size() == keyword.size())
        key = keyword;
    else
    {
        int index = 0, count = 0;
        while(count < sizeOfText)
        {
            key += keyword[index];
            if(index == (keyword.size() -1))
            {
                index = -1;
            }
            
            index++;
            count++;
            
        }
    }
    return key;
}

// реализация метода шифрования текста
string CipheredText(string str, string keyword)
{
    string cipherStr = "\0";
    
    for(int i = 0; i < str.size(); i++)
    {
        int num = keyword[i] - '0';
        int x = str[i] + num;
        if(x > 90)
            x -= 26;
        cipherStr += (char)x;
    }
    
    return cipherStr;
}

// реализация метода по Дешифрованию текста
string DecryptedText(string &str,string keyword)
{
    string decrypted = "\0";
    for(int i = 0; i<str.size(); i++)
    {
        int num = keyword[i] - '0';
        int x = str[i] - num;
        if (x < 65)
            x += 'Z' - 64;
        decrypted += (char)x;
    }
    return decrypted;
}




