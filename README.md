# Простой скрипт проверки быстродействия PHP

Работает со всеми версиями ПХП: от 4.4 до 7.1

## ChangeLog

@ 2017-04-21, v1.0.12

 * Правильная конвертация значений в единицы SI.
 * Считаем операции в секунду на МГц.
 * Обновил вывод - добавил заголовок столбцам

@ 2017-04-20, v1.0.11

 * Нагружаем процессор, чтобы определить MHz только если разница между
   значениями 'cpu MHz' и 'bogomips/2' большая.

@ 2017-04-20, v1.0.10

 * Тесты массивов теперь всегда включены, они больше не съедают много памяти
 * Добавлено определение CPU на Linux-системах, добавлен вывод операций на МГц
 * В выводе uname осталена только необходимая для сравнения информация
 * Обновлен README

@ 2017-04-06, v1.0.9

 * Поправлен подсчет операций в секунду для теста массивов

@ 2017-04-06, v1.0.8

 * Тесты, которых нет в php-4.4 вынесены в отдельный подключаемый файл

@ 2017-04-06, v1.0.7

 * Изменены названия функций-тестов для сортировки перед запуском
 * Обновлено форматирование вывода результатов тестов
 * Добавлены и обновлены тесты:
   - образение к определенныи и неопределенным переменным/ключам массива
   - исключения (exceptions)
   - к хешированию добавлен тест crypt
   - тест массивов разбит на три уровня - время выполнения то же, памяти занимает меньше

@ 2015-07-16, v1.0.6

 * Добавлены тесты: preg & serialize

@ 2015-07-02, v1.0.5

 * Добавлен тест простейшего копирования строк

@ 2015-07-02, v1.0.4

 * Добавлено увеличение лимита по памяти и времени выполнения

@ 2015-07-02, v1.0.3

 * Исправлено определение доступных функций, сделан пропуск тестов для них

@ 2015-07-02, v1.0.2

 * Добавлено еще больше функций, теперь требуется наличие mbstring и json модулей
 * Потребление памяти увеличено из-за тестирования массивов - нужно более 1Гб

@ 2015-07-01, v1.0.1

 * Добавлен вывод потребления памяти
 * Добавлены новые функции, увеличен размер проверочной строки

## Пример вывода скрпита

```
<pre>
------------------------------------------------------------------------------
|                            PHP BENCHMARK SCRIPT                            |
------------------------------------------------------------------------------
Start:             : 2017-04-20 20:56:47
Server:            : Linux/4.4.0-73-generic x86_64
CPU:               :
             model : Intel(R) Core(TM) i5-6600K CPU @ 3.50GHz
             cores : 4
               MHz : 3758.535MHz
PHP version:       : 7.0.14-Ubuntu/16.04-SergeyD/9.3.1
Benchmark version: : 1.0.10
Platform:          : Linux
------------------------------------------------------------------------------
01_math                          :   3.112 sec | 449.91 kOp/s | 372.49  Op/Mhz
02_string_concat                 :   0.417 sec |  33.53 MOp/s |   3.72 kOp/Mhz
03_string_simple_functions       :   1.734 sec | 749.74 kOp/s | 345.88  Op/Mhz
04_string_multibyte              :   3.912 sec |  33.23 kOp/s |  34.59  Op/Mhz
05_string_manipulation           :   2.355 sec | 551.93 kOp/s | 345.88  Op/Mhz
06_regex                         :   1.889 sec | 688.21 kOp/s | 345.88  Op/Mhz
07_1_hashing                     :   2.025 sec | 641.83 kOp/s | 345.88  Op/Mhz
07_2_crypt                       :   5.792 sec |   1.73 kOp/s |   2.66  Op/Mhz
08_json_encode                   :   1.447 sec | 898.25 kOp/s | 345.88  Op/Mhz
09_json_decode                   :   1.692 sec | 768.44 kOp/s | 345.88  Op/Mhz
10_serialize                     :   1.027 sec |   1.27 MOp/s | 345.88  Op/Mhz
11_unserialize                   :   1.192 sec |   1.09 MOp/s | 345.88  Op/Mhz
12_array_fill                    :   0.529 sec |  51.00 MOp/s |   7.18 kOp/Mhz
13_array_unset                   :   0.743 sec |  36.34 MOp/s |   7.18 kOp/Mhz
14_loops                         :   1.800 sec | 211.06 MOp/s | 101.10 kOp/Mhz
15_loop_ifelse                   :   1.297 sec |  69.41 MOp/s |  23.95 kOp/Mhz
16_loop_ternary                  :   3.105 sec |  28.99 MOp/s |  23.95 kOp/Mhz
17_1_loop_defined_access         :   0.667 sec |  29.98 MOp/s |   5.32 kOp/Mhz
17_2_loop_undefined_access       :   3.761 sec |   5.32 MOp/s |   5.32 kOp/Mhz
18_loop_exceptiontrycatch        :   2.111 sec |   1.89 MOp/s |   1.06 kOp/Mhz
------------------------------------------------------------------------------
Total time:                      : 40.609 sec.
Current memory usage:            : 474.19 kb.
Peak memory usage:               : 227.44 Mb.
</pre>
```