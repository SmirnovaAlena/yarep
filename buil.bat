@echo off
chcp 65001 >nul
echo ==========================================
echo Компиляция трехуровневого меню "Обучайка"...
echo ==========================================

g++ main.cpp menu_items.cpp menu_functions.cpp -o obuchayka.exe -finput-charset=UTF-8 -fexec-charset=UTF-8

if %errorlevel% neq 0 (
    echo.
    echo [ОШИБКА] Компиляция не удалась! Проверь ошибки в коде выше.
    pause
    exit /b
)

echo.
echo Компиляция прошла успешно! Запускаем программу...
echo.
obuchayka.exe

echo.
echo Программа завершена.
pause