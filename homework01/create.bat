@echo off
mkdir %1
mkdir %1\\Algem
mkdir %1\\MathAnalys
mkdir %1\\BasicsOfProg
mkdir %1\\DiscreteMath
echo Лекции: Погожев Сергей Владимирович. > %1\\Algem\\readme.txt
echo Практика: Балыкина Юлия Ефимовна >> %1\\Algem\\readme.txt 
echo Начало занятий: %date% >> %1\\Algem\\readme.txt
echo Лекции: Платонов Алексей Викторович. > %1\\MathAnalys\\readme.txt 
echo Практика: Мышков Станислав Константинович >> %1\\MathAnalys\\readme.txt
echo Начало занятий: %date% >> %1\\MathAnalys\\readme.txt
echo Лекции: Погожев Сергей Владимирович. > %1\\BasicsOfProg\\readme.txt
echo Практика: Севостьянов Руслан Андреевич. >> %1\\BasicsOfProg\\readme.txt 
echo Начало занятий: %date% >> %1\\BasicsOfProg\\readme.txt
echo Лекции: Погожев Сергей Владимирович. > %1\\DiscreteMath\\readme.txt 
echo Практика: Воронкова Ева Боруховна >> %1\\DiscreteMath\\readme.txt
echo Начало занятий: %date% >> %1\\DiscreteMath\\readme.txt
copy op.bat %1\\BasicsOfProg
copy algem.bat %1\\Algem