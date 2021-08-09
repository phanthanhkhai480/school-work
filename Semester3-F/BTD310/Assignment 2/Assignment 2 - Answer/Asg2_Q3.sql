CREATE SEQUENCE CONTRACTORS_NUM_SEQ
START WITH 101
NOCACHE;

CREATE SEQUENCE RETAILERS_NUM_SEQ
START WITH 1
NOCACHE;

CREATE SEQUENCE RENTS_NUM_SEQ
START WITH 100001
MAXVALUE 999999
NOCACHE
CYCLE;

CREATE SEQUENCE TOOLS_NUM_SEQ
START WITH 9999
MAXVALUE 10000
INCREMENT BY -2
NOCACHE;
