# cat and grep utilities

## Обзор проекта

Учебный вариант реализация базовых утилит Bash (cat и grep) написанных на языке C.

## Оглавление

0. [Обзор проекта](#Обзор-проекта)
1. [cat](#cat)
2. [grep](#grep)
3. [Тестирование](#Тестирование)

## cat

Формат подачи аргументов:

`cat [OPTION] [FILES]...`

Ниже перечисленны реализуемые опции:

| № | Опции | Описание |
| ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | нумерует только непустые строки |
| 2 | -e предполагает и -v (GNU only: -E то же самое, но без применения -v) | также отображает символы конца строки как $  |
| 3 | -n (GNU: --number) | нумерует все выходные строки |
| 4 | -s (GNU: --squeeze-blank) | сжимает несколько смежных пустых строк |
| 5 | -t предполагает и -v (GNU: -T то же самое, но без применения -v) | также отображает табы как ^I |

## grep

Формат подачи аргументов:

`grep [option] template [file_names]`

Ниже перечисленны реализуемые опции:

| № | Опции | Описание |
| ------ | ------ | ------ |
| 1 | -e | Шаблон |
| 2 | -i | Игнорирует различия регистра.  |
| 3 | -v | Инвертирует смысл поиска соответствий. |
| 4 | -c | Выводит только количество совпадающих строк. |
| 5 | -l | Выводит только совпадающие файлы.  |
| 6 | -n | Предваряет каждую строку вывода номером строки из файла ввода. |
| 7 | -h | Выводит совпадающие строки, не предваряя их именами файлов. |
| 8 | -s | Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах. |
| 9 | -f file | Получает регулярные выражения из файла. |
| 10 | -o | Печатает только совпадающие (непустые) части совпавшей строки. |

## Тестирование

Проверка результатов реализована путем сравнения работы разрабатываемых утилит с оригинальными. Вызвать тестирование можно при помощи Makefile целью testing в каждой из папок. Результаты работы записываются во временные текстовые файлы и сравниваются при помощи команды diff. Далее эти файлы удаляются. Паттерны расположены в папках grep/tests и cat/tests соответственно.
