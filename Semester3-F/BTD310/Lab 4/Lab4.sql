
-- Question 1
-- A
SELECT last_name
FROM employees
WHERE last_name LIKE '%Z%';

-- B
 SELECT COUNT(DISTINCT LOCATION_ID)AS "Number of Locations"
FROM DEPARTMENTS; 
-- Question 2

select substr(phone_number,1,3) AREA_CODE, count(*) Count from employees
group by substr(phone_number,1,3)
order by AREA_CODE; 

-- Question 3

SELECT count(NVL(TO_CHAR(SUBSTR(postal_code, 1, 1)),'A')) "Others"
FROM locations
WHERE NVL(TO_CHAR(SUBSTR(postal_code, 1, 1)),'A') BETWEEN 'A' AND 'Z';

-- Question 4

SELECT department_id, 0.5*(MAX(salary) - MIN(salary)) + MIN(salary) AS "Mid salary"
FROM employees
GROUP BY department_id
HAVING MIN(salary) > 5000 AND department_id IS NOT NULL
ORDER BY department_id;

-- Question 5

SELECT department_id,SUM(
       NVL2(commission_pct,500,1000)) AS "Total bonuses"
FROM employees
WHERE department_id IS NOT NULL
GROUP BY department_id;

-- Question 6
SELECT d.department_name, l.street_address || ', ' || l.city || ', ' || l.state_province AS address  
FROM departments d NATURAL JOIN locations l
WHERE l.city != 'Seattle'
ORDER BY d.department_name;

-- Question 7
SELECT DISTINCT n.last_name, n.employee_id 
FROM employees n JOIN employees i
ON (n.employee_id < 201 AND n.last_name > 'Hartstein')
ORDER BY n.last_name;

-- Question 8
SELECT last_name, employee_id 
FROM (SELECT last_name, employee_id FROM employees WHERE employee_id < 201)
WHERE last_name >  'Hartstein'
ORDER BY last_name;

-- Question 9
SELECT substr(phone_number,1,3) AS "Area code",
       100 * COUNT(substr(phone_number,1,3)) / 
       (SELECT COUNT(phone_number) FROM employees) 
       AS "Percentage"
FROM employees
GROUP BY substr(phone_number,1,3)
ORDER BY COUNT(substr(phone_number,1,3));

-- Question 10
SELECT location_id, 0.5*(MAX(salary) - MIN(salary)) + MIN(salary) AS "Mid salary"
FROM employees e Join departments using(department_id) join locations using(location_id)
WHERE department_id IS NOT NULL
GROUP BY location_id
ORDER BY location_id;
