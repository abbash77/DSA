# Write your MySQL query statement below
# select * from mynumbers order by (select * from mynumbers group by num having count(*)=1) desc;
SELECT MAX(num) as num
FROM (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
) as a;


