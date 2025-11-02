# Лабораторна робота 13 — Робота з рядками

У цій лабораторній роботі ви попрацюєте з C-стилем рядків (`char*`), бібліотекою `<cstring>`, а також класом `std::string`.
---

## Завдання 1 — Довжина рядка
Реалізуйте функцію `size_t StringLength(const char* str);`, яка обчислює довжину C-стилю рядка без використання `strlen`.

Приклад вводу:
```
Hello, World!
```
Приклад виводу:
```
Довжина: 13
```

---

## Завдання 2 — Реверс рядка
Напишіть функцію `void ReverseString(char* str);`, яка перевертає рядок на місці.

Приклад вводу:
```
Programming
```
Приклад виводу:
```
gnimmargorP
```

---

## Завдання 3 — Підрахунок голосних
Створіть функцію `size_t CountVowels(const char* str);`, яка підраховує кількість голосних літер (a, e, i, o, u) без урахування регістру.

Приклад вводу:
```
Education is important
```
Приклад виводу:
```
Голосних: 10
```

---

## Завдання 4 — Паліндром
Реалізуйте `bool IsPalindrome(const char* str);`, яка перевіряє, чи є рядок паліндромом (ігноруючи пробіли і регістр).

Приклад вводу:
```
A man a plan a canal Panama
```
Приклад виводу:
```
Це паліндром
```

---

## Завдання 5 — Конкатенація рядків
Напишіть функцію `char* ConcatenateStrings(const char* str1, const char* str2);`, яка створює новий рядок, що є результатом об'єднання двох вхідних рядків. Використовуйте `new[]`.

Приклад вводу:
```
Hello
World
```
Приклад виводу:
```
HelloWorld
```

---

## Завдання 6 — Підрядок
Реалізуйте `char* Substring(const char* str, size_t start, size_t length);`, яка повертає новий рядок з `length` символів, починаючи з позиції `start`.

Приклад вводу:
```
String: "Programming is fun"
Start: 12, Length: 2
```
Приклад виводу:
```
is
```

---

## Завдання 7 — Заміна підрядка
Створіть функцію `std::string ReplaceAll(const std::string& source, const std::string& from, const std::string& to);`, яка замінює всі входження підрядка `from` на `to`.

Приклад вводу:
```
Source: "I love cats and cats are great"
From: "cats"
To: "dogs"
```
Приклад виводу:
```
I love dogs and dogs are great
```

---

## Завдання 8 — Розбиття рядка на слова
Напишіть функцію `std::vector<std::string> SplitString(const std::string& str, char delimiter);`, яка розбиває рядок на вектор слів за роздільником.

Приклад вводу:
```
String: "apple,banana,cherry,date"
Delimiter: ','
```
Приклад виводу:
```
[apple, banana, cherry, date]
```

---

## Завдання 9 — Видалення пробілів
Реалізуйте `std::string Trim(const std::string& str);`, яка видаляє пробільні символи на початку і в кінці рядка.

Приклад вводу:
```
"   Hello World   "
```
Приклад виводу:
```
"Hello World"
```

---

## Завдання 10 — Частота слів
Створіть функцію `std::map<std::string, int> WordFrequency(const std::string& text);`, яка підраховує частоту появи кожного слова в тексті (без урахування регістру і розділових знаків).

Приклад вводу:
```
"The quick brown fox jumps over the lazy dog. The dog was very lazy."
```
Приклад виводу:
```
the: 3
quick: 1
brown: 1
fox: 1
jumps: 1
over: 1
lazy: 2
dog: 2
was: 1
very: 1
```

---

## Примітки
- Для завдань 1-6 працюйте з C-стилем рядків (`char*`)
- Для завдань 7-10 використовуйте `std::string` та STL контейнери
- Пам'ятайте про звільнення пам'яті після `new[]` за допомогою `delete[]`
- Перевіряйте коректність вхідних даних (nullptr для C-рядків)
- Використовуйте функції з `<cctype>` для роботи з символами (`tolower`, `isspace`, тощо)
- Для завдання 10 використовуйте `<map>` та розгляньте використання регулярних виразів або ручний парсинг
