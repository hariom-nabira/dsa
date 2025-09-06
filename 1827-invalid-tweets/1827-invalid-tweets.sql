# Write your MySQL query statement below
SELECT tweet_id
FROM tweets
WHERE length(content) > 15;