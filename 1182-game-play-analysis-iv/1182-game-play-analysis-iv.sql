# Write your MySQL query statement below
SELECT ROUND(SUM(IF((player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) in (
                    SELECT player_id, MIN(event_date)
                    FROM Activity
                    GROUP BY player_id),
                1,0))
            / COUNT(DISTINCT player_id), 2) AS fraction
FROM Activity