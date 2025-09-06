# Write your MySQL query statement below
SELECT id
FROM Weather w
WHERE temperature > 
(
    SELECT temperature
    FROM Weather k 
    WHERE k.recordDate = DATE_SUB(w.recordDate, INTERVAL 1 DAY)
);