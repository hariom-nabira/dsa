# Write your MySQL query statement below
SELECT u.user_id, ROUND(AVG(IF(c.action="confirmed", 1, 0)), 2) AS confirmation_rate
FROM Signups u
    LEFT JOIN Confirmations c
        ON u.user_id = c.user_id
GROUP BY u.user_id;