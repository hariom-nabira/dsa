# Write your MySQL query statement below
WITH firstOrders as(
    SELECT customer_id, MIN(order_date) AS first_order
    FROM Delivery
    GROUP BY customer_id
)
SELECT ROUND(SUM(IF(first_order=customer_pref_delivery_date, 1, 0))*100/COUNT(*), 2) AS immediate_percentage
FROM firstOrders fo
    JOIN Delivery d
    ON fo.customer_id = d.customer_id
    AND order_date = first_order;