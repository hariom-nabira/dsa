# Write your MySQL query statement below
SELECT u.user_id, ROUND((SELECT count(*) FROM confirmations where user_id = u.user_id AND action="confirmed")/count(*), 2) AS confirmation_rate
FROM Signups u
    LEFT JOIN Confirmations c
        ON u.user_id = c.user_id
GROUP BY u.user_id;