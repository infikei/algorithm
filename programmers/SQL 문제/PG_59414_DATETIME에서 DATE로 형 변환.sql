-- Solve 2024-12-25

SELECT ANIMAL_ID, NAME, DATE_FORMAT(DATETIME, '%Y-%m-%d') 날짜
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;
