-- Solve 2024-06-08

SELECT ROUND(AVG(DAILY_FEE)) AVERAGE_FEE
FROM CAR_RENTAL_COMPANY_CAR
WHERE CAR_TYPE = 'SUV';
