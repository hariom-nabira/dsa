/* Write your PL/SQL query statement below */
select 
    tweet_id from Tweets 
where length(content) > 15;