-- Solve 2024-12-23

SELECT ANIMAL_TYPE, IFNULL(NAME, 'No name') NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;
