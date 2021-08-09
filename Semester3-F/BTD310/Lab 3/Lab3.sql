SELECT FIRST_NAME ||' earns ' || '$' || SALARY 
|| ' monthly and ' 
|| NVL2(COMMISSION_PCT, '%'||COMMISSION_PCT*100,' no ')
|| ' commission to afford spending ' ||TO_CHAR(ROUND((SALARY/3),2), 'fm$99,999.00') 
|| ' on housing ' as "Housing Expenses"
from EMPLOYEES;


SELECT LAST_NAME, TO_CHAR(HIRE_DATE, 'DAY, DD/mon/YY') as "Hire Date", 
TO_CHAR(NEXT_DAY(ADD_MONTHS(HIRE_DATE, 240),'FRIDAY'), 'fmDAY, DD/Mon/YYYY') as "20 years celebration"
FROM EMPLOYEES;


SELECT TO_CHAR(HIRE_DATE, 'fmDAY, "the" DdSpth "of" Month, YYYY') as "Day of Hire"
FROM EMPLOYEES
ORDER BY (NEXT_DAY(HIRE_DATE,'MONDAY') - HIRE_DATE) DESC;


SELECT LAST_NAME, PHONE_NUMBER,
  DECODE(SUBSTR(PHONE_NUMBER,1,3),
                      '515', 'A',
                      '590', 'B',
                      '603', 'C',
                      '650', 'D', 
                      'E') AS REGION
FROM EMPLOYEES
ORDER BY REGION, PHONE_NUMBER;


SELECT LAST_NAME, PHONE_NUMBER,
  CASE SUBSTR(PHONE_NUMBER,1,3)
                      WHEN '515' THEN 'A'
                      WHEN '590' THEN 'B'
                      WHEN '603' THEN 'C'
                      WHEN '650' THEN 'D' 
                      ELSE 'E' END AS REGION
FROM EMPLOYEES
ORDER BY REGION, PHONE_NUMBER;


SELECT HIRE_DATE,
  CASE TO_CHAR(HIRE_DATE, 'YY') 
                      WHEN '95' THEN '1'
                      ELSE '0' END AS "1995"
FROM EMPLOYEES;

