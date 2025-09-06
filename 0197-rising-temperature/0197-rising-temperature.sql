# Write your MySQL query statement below
SELECT id
FROM Weather w
WHERE temperature > 
(
    SELECT temperature
    FROM Weather k 
    WHERE DATEDIFF(k.recordDate, w.recordDate) = -1
);