-- Solve 2024-12-29

SET @hour = -1;

SELECT (@hour := @hour + 1) AS HOUR,
    (SELECT COUNT(ANIMAL_ID)
    FROM ANIMAL_OUTS
    WHERE HOUR(DATETIME) = @hour
    ) AS COUNT
FROM ANIMAL_OUTS
WHERE @hour < 23;
