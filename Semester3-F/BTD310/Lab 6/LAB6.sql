--We, MAHNOOR, KHAI, HAO DID EVERYTHING TOGETHER (mention your names), declare that the attached assignment is our own work in accordance with the Seneca Academic Policy.  No part of this assignment has been copied manually or electronically from any other source (including web sites) or distributed to other students.
--QUESTION #1

DECLARE
  v_max_sal NUMBER(8,2);
BEGIN
  
  SELECT MAX(salary)
  INTO v_max_sal
  FROM employees
  WHERE department_id = 10;


  DBMS_OUTPUT.PUT_LINE('Maximum salary in department 10 is ' || v_max_sal );
END;
/

--QUESTION #2
DECLARE
  v_max_sal NUMBER(8,2);
  v_last employees.last_name%TYPE;
  --v_department_id NUMBER(4,0);
BEGIN
  
  SELECT MAX(salary)
  INTO v_max_sal
  FROM employees
  WHERE department_id = &v_department_id;


  DBMS_OUTPUT.PUT_LINE('The highest salary in department ' || &v_department_id || ' is ' || v_max_sal );
  --UNDEFINE (v_department_id);

  Select last_name
  into v_last
  from employees
  where salary = v_max_sal;
  

  DBMS_OUTPUT.PUT_LINE('earn by '||v_last);
END;
/ 

--QUESTION #3
VARIABLE b_id NUMBER
BEGIN	
	SELECT LOCATION_ID
	INTO :b_id
	FROM LOCATIONS
	WHERE CITY LIKE 'Seattle';
END;
/
PRINT b_id;
SELECT DEPARTMENT_NAME FROM DEPARTMENTS
WHERE LOCATION_ID = :b_id;

