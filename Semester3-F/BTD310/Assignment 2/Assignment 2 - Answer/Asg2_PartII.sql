--Question 5
CREATE VIEW AVAIL_TOOLS AS
(SELECT tool.tool_name, 
       toolinstance.ti_num,
       retailer.retailer_name,
       toolinstance.ti_status,
       decode(toolinstance.ti_status, 'Available', 'Now'
                                    , 'Rented') Avalibility
FROM tool,toolinstance,retailer
WHERE tool.tool_num = toolinstance.tool_num 
and tool.retailer_num = retailer.retailer_num
and toolinstance.ti_status <> 'Destroyed'
and toolinstance.ti_status = 'Available')
UNION
(SELECT tool.tool_name, 
       toolinstance.ti_num,
       retailer.retailer_name,
       toolinstance.ti_status,
       to_char(NVL(detailrental.detail_returndate,detailrental.detail_duedate),'dd-mm-yyyy') Avalibility
FROM tool,toolinstance,retailer
,detailrental
WHERE tool.tool_num = toolinstance.tool_num 
and tool.retailer_num = retailer.retailer_num
and detailrental.ti_num = toolinstance.ti_num
and detailrental.detail_duedate>=sysdate
and toolinstance.ti_status <> 'Destroyed'
and toolinstance.ti_status = 'Rented');

SELECT * FROM AVAIL_TOOLS ;


--Question 6
SELECT * FROM toolinstance WHERE toolinstance.TI_NUM not in 
(SELECT ti_num FROM detailrental WHERE detailrental.DETAIL_RETURNDATE is null ) 
and toolinstance.TI_STATUS <> 'Destroyed'
and toolinstance.TI_STATUS <> 'Available';


--Question 7
UPDATE TOOLINSTANCE
SET TI_STATUS = 'Available'
WHERE TI_NUM IN(17,20);


--Question 8
CCREATE VIEW OVERDUE_TOOLS AS
  SELECT C.CONTRACTOR_NAME, C.CONTRACTOR_PHONE_NUM, T.TOOL_NAME,
         TI.TI_NUM, R.RENT_DATE, D.DETAIL_DUEDATE
  FROM CONTRACTOR C JOIN RENTAL R ON C.CONTRACTOR_NUM = R.CONTRACTOR_NUM
                    JOIN DETAILRENTAL D ON R.RENT_NUM = D.RENT_NUM
                    JOIN TOOLINSTANCE TI ON D.TI_NUM = TI.TI_NUM
                    JOIN TOOL T ON TI.TOOL_NUM = T.TOOL_NUM
  WHERE  D.DETAIL_RETURNDATE = NULL AND D.DETAIL_DUEDATE > SYSDATE;
 

--Question 9
SELECT toolinstance.ti_num,
NVL2(sum(NVL2(detailrental.detail_returndate,detailrental.detail_returndate,sysdate) - rental.rent_date),
round(sum(NVL2(detailrental.detail_returndate,detailrental.detail_returndate,sysdate) - rental.rent_date),-1),0) "#days rented out",
round(max(sysdate-toolinstance.ti_purchasedate),-1) "#days since purchase" 
FROM toolinstance 
left join detailrental ON (detailrental.TI_NUM = toolinstance.ti_num)
left join rental ON (rental.rent_num = detailrental.RENT_NUM)
GROUP BY toolinstance.ti_num
ORDER BY toolinstance.ti_num;
