-- Solve 2025-01-02

SELECT
    CASE
        WHEN EXISTS (
            SELECT 1
            FROM SKILLCODES S
            WHERE S.CATEGORY = 'Front End'
            AND S.CODE & D.SKILL_CODE != 0
        )
        AND EXISTS (
            SELECT 1
            FROM SKILLCODES S
            WHERE S.NAME = 'Python'
            AND S.CODE & D.SKILL_CODE != 0
        )
        THEN 'A'
        WHEN EXISTS (
            SELECT 1
            FROM SKILLCODES S
            WHERE S.NAME = 'C#'
            AND S.CODE & D.SKILL_CODE != 0
        )
        THEN 'B'
        WHEN EXISTS (
            SELECT 1
            FROM SKILLCODES S
            WHERE S.CATEGORY = 'Front End'
            AND S.CODE & D.SKILL_CODE != 0
        )
        THEN 'C'
        ELSE NULL
    END AS GRADE,
    D.ID,
    D.EMAIL
FROM DEVELOPERS D
HAVING GRADE IS NOT NULL
ORDER BY GRADE ASC, D.ID ASC;
