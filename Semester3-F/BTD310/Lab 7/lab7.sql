--Q1
CREATE TABLE CPY_DEPT
AS
(SELECT * 
FROM DEPARTMENTS); 

SELECT * FROM CPY_DEPT;

--Q2
DECLARE
  dept_id CPY_DEPT.DEPARTMENT_ID%TYPE :=10;
  location_info CPY_DEPT.LOCATION_ID%TYPE := 1700;
  v_rows_delete VARCHAR2(30);
  v_rows_update VARCHAR2(30);
BEGIN
  DELETE
  FROM CPY_DEPT
  WHERE DEPARTMENT_ID = dept_id;
  v_rows_delete := (SQL%ROWCOUNT || ' rows deleted.');
  DBMS_OUTPUT.PUT_LINE(v_rows_delete);
  
  UPDATE CPY_DEPT
  SET MANAGER_ID = 100
  WHERE LOCATION_ID = location_info;
  v_rows_update := (SQL%ROWCOUNT || ' rows updated.');
  DBMS_OUTPUT.PUT_LINE(v_rows_update);
END;
/

--Q3
BEGIN
MERGE INTO CPY_DEPT C
    USING DEPARTMENTS D
    ON (D.DEPARTMENT_ID = C.DEPARTMENT_ID)
  WHEN MATCHED THEN
    UPDATE SET
  
      C.DEPARTMENT_NAME = D.DEPARTMENT_NAME,
      C.MANAGER_ID = D.MANAGER_ID,
      C.LOCATION_ID = D.LOCATION_ID
  WHEN NOT MATCHED THEN
    INSERT VALUES(D.DEPARTMENT_ID,
    D.DEPARTMENT_NAME,
    D.MANAGER_ID, D.LOCATION_ID);
END;
/
SELECT * FROM CPY_DEPT;

--Q4
DECLARE
  v_max_sal NUMBER(8,2);
BEGIN
  
  SELECT MAX(salary)
  INTO v_max_sal
  FROM employees
  WHERE department_id = &&v_department_id;


  DBMS_OUTPUT.PUT_LINE('The highest salary in department ' || &v_department_id || ' is ' || v_max_sal );
  if v_max_sal > 5000
  then DBMS_OUTPUT.PUT_LINE('which is higher than 5000');
  else 
  DBMS_OUTPUT.PUT_LINE('which is lower than 5000');
  end if;
END;

--Q5
CREATE TABLE regStars
(
  loaction_id NUMBER(4,0),
  region_id NUMBER(4,0),
  stars VARCHAR2(10)
);

DECLARE 
    V_counter Number(10):= 1000;
    V_Country_id VarChar(10);
    V_region_id NUmber(10);
    V_location_id NUmber(10);
    V_stars VarChar(10);
    V_temp VarChar(10):='';
BEGIN
    <<outer_loop>>
    LOOP 
        select locations.country_id into V_country_id from locations where locations.location_id = V_counter; 
        
        select locations.location_id, countries.region_id into V_location_id, V_region_id from locations
        join countries on (countries.country_id = V_country_id and locations.location_id = V_counter);
        
        for i in 1..V_region_id
         loop
            V_stars:=(V_stars || '*');
         end loop;
            insert into regstars
            values(V_location_id,V_region_id,V_stars);
        V_stars:='';
        V_Counter := V_Counter+100;
        exit when V_counter > 3200;
    END LOOP;
END;

select * from regstars;
