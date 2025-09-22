# Write your MySQL query statement below
SELECT activity_date AS day, COUNT(DISTINCT(user_id)) AS active_users
FROM Activity
WHERE DATEDIFF(activity_date,'2019-07-27') BETWEEN -29 AND 0
GROUP BY activity_date
HAVING active_users > 0